// Copyright Michael Heilmann 2016, 2017.
//
// This file is part of Idlib.
//
// Idlib is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Idlib is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Idlib. If not, see <http://www.gnu.org/licenses/>.

/// @file idlib/parsing_expressions/sequence.hpp
/// @brief "sequence" parsing expression.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/parsing_expressions/include.hpp` instead)
#endif

#include "idlib/parsing_expressions/internal/n_ary_expr.hpp"
#include "idlib/parsing_expressions/match.hpp"

#include "idlib/parsing_expressions/header.in"

struct tuple_op_sequence
{
private:
    // Terminates the iteration.
    // This is utility code for iterating over an std::tuple.
    template<typename Tuple, typename Function, typename Iterator>
    match<std::decay_t<Iterator>>
    for_each
        (
            Tuple&&,
            Function,
            Iterator at,
            Iterator end,
            std::integral_constant
                <
                    size_t,
                    std::tuple_size
                        <
                            std::remove_reference_t<Tuple>
                        >::value
                >
        ) const
    {
        return make_match(true, at);
    }

    // Drives the iteration.
    // This is utility code for iterating over an std::tuple.
    template<std::size_t Index,
             typename Tuple,
             typename Function,
             typename Iterator,
             typename = std::enable_if_t
                            <
                                Index != std::tuple_size
                                            <
                                                std::remove_reference_t<Tuple>
                                            >::value
                            >
            >
    match<std::decay_t<Iterator>>
    for_each
        (
            Tuple&& t,
            Function f,
            Iterator at,
            Iterator end,
            std::integral_constant<size_t, Index>
        ) const
    {
        auto result = f(std::get<Index>(t), at, end);
        if (result.first)
        {
            return for_each(std::forward<Tuple>(t), f, result.second, end, std::integral_constant<size_t, Index + 1>()); // Advance.
        }
        return make_match(false, at);
    }

public:
    // The iteration.
    // This is utility code for iterating over an std::tuple.
    template<typename Tuple,
             typename Function,
             typename It>
    match<std::decay_t<It>>
    for_each
        (
            Tuple&& t,
            Function f,
            It at,
            It end
        ) const
    {
        return for_each(std::forward<Tuple>(t), f, at, end, std::integral_constant<size_t, 0>());
    }

    tuple_op_sequence()
    {}
};

/// @internal
/// @brief See id::sequence for more information.
/// @tparam Expr the type of the first expression
/// @tparam Exprs ... the type of the remaining expressions
template <typename Expr, typename ... Exprs>
struct sequence_expr : public internal::n_ary_expr<tuple_op_sequence, Expr, Exprs ...>
{
public:
    /// @internal
    /// @brief Construct this parsing expression.
    /// @param expr the first expression
    /// @param exprs the remaining expressions
    sequence_expr(internal::constructor_access_token, const Expr& expr, const Exprs& ... exprs) :
        internal::n_ary_expr<tuple_op_sequence, Expr, Exprs ...>(internal::constructor_access_token{}, expr, exprs ...)
    {}

    template <typename It>
    match<std::decay_t<It>> operator()(It at, It end) const
    {
        static const tuple_op_sequence op;
        auto result = op.for_each(this->m_exprs,
                                  [](const auto& expr, It at, It end) 
                                    {
                                        return expr(at, end);
                                    },
                                  at, 
                                  end);
        if (result.first)
        {
            return result;
        }
        return make_match(false, at);
    }
};

/// @brief Create the sequence of a one or more parsing expressions.
/// The sequence of one or more parsing expressions accepts if all parsing expression of one or more parsing expressions accept.
/// @detail That is, the @a sequence of @code{n > 0} parsing expressions @code{e1}, ..., @code{en}
/// is defined as
/// @code{sequence(e1, ..., en) = e1 ...  en}.
/// @tparam Expr the type of the first expression
/// @tparam Exprs ... the types of the remaining expressions
/// @param expr the first expression
/// @param exprs the remaining expressions
/// @return the parsing expression
template <typename Expr, typename ... Exprs>
sequence_expr<std::decay_t<Expr>, std::decay_t<Exprs> ...> sequence(Expr&& expr, Exprs&& ... exprs)
{
    return sequence_expr<std::decay_t<Expr>, std::decay_t<Exprs> ...>(internal::constructor_access_token{}, std::forward<Expr>(expr), std::forward<Exprs>(exprs) ...);
}

#include "idlib/parsing_expressions/footer.in"
