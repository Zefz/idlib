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

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/parsing_expressions/include.hpp` instead)
#endif

#include "idlib/parsing_expressions/n_ary_expr.hpp"

namespace id { namespace parsing_expressions {

struct tuple_op_choice
{
private:
    // Terminates the iteration.
    // This is utility code for iterating over an std::tuple.
    template<typename Tuple,
             typename Function,
             typename Iterator>
    std::pair<bool, Iterator>
    for_each
        (
            Tuple&& t,
            Function f,
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
        return std::make_pair(false, at);
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
    std::pair<bool, Iterator>
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
            return result;
        }
        return for_each(std::forward<Tuple>(t), f, at, end, std::integral_constant<size_t, Index + 1>()); // Advance.
    }

public:
    // The iteration.
    // This is utility code for iterating over an std::tuple.
    template<typename Tuple,
             typename Function,
             typename Iterator>
    std::pair<bool, Iterator>
    for_each
        (
            Tuple&& t,
            Function f,
            Iterator at,
            Iterator end
        ) const
    {
        return for_each(std::forward<Tuple>(t), f, at, end, std::integral_constant<size_t, 0>());
    }

    tuple_op_choice()
    {}
};

/// @internal
/// @brief See id::choice for more information.
/// @tparam Expr the type of the first expression
/// @tparam Exprs ... the type of the remaining expressions
template <typename Expr, typename ... Exprs>
class choice_expr : public internal::n_ary_expr<tuple_op_choice, Expr, Exprs ...>
{
public:
    /// @internal
    /// @brief Construct this parsing expression.
    /// @param expr the first expression
    /// @param exprs the remaining expressions
    choice_expr(Expr&& expr, Exprs&& ... exprs) :
        internal::n_ary_expr<tuple_op_choice, Expr, Exprs ...>(std::forward<Expr>(expr), std::forward<Exprs>(exprs) ...)
    {}

    template <typename It>
    std::pair<bool, It> operator()(It at, It end) const
    {
        static const tuple_op_choice op;
        auto result = op.for_each(this->m_exprs,
                                  [](const auto& expr, It at, It end)
                                    {
                                        auto result = expr(at, end);
                                        return result.first ? result : std::make_pair(false, at);
                                    }, 
                                  at, 
                                  end);
        return result;
    }
};

/// @brief Create the choice of one or more parsing expressions.
/// The choice of a one or more parsing expressions accepts if at least one of the parsing expressions accepts.
/// If several of these parsing expressions would accept, the first (in left to right order) accepting parsing expression is considered as accepting.
/// @detail That is, the @a choice of @code{n > 0} parsing expressions @code{e1}, ..., @code{en}
/// is defined as
/// @code{choice(e1, ..., en) = e1 | ...  | en}.
/// @tparam Expr the type of the first expression
/// @tparam Exprs ... the types of the remaining expressions
/// @param expr the first expression
/// @param exprs the remaining expressions
/// @return the parsing expression
template <typename Expr, typename ... Exprs>
choice_expr<Expr, Exprs ...> choice(Expr&& expr, Exprs&& ... exprs)
{
    return choice_expr<Expr, Exprs ...>(std::forward<Expr>(expr), std::forward<Exprs>(exprs) ...);
}

} } // namespace id::parsing_expressions
