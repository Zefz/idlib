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

/// @file idlib/parsing_expressions/repetition.hpp
/// @brief "repetition" parsing expression.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/parsing_expressions/include.hpp` instead)
#endif

#include "idlib/utility/platform.hpp"

namespace id { namespace parsing_expressions {

/// @internal
/// @brief See id::repetition for more information.
/// @tparam Sym the symbol type
/// @tparam Expr the type of the expression
template <typename Sym, typename Expr>
struct repetition_expr
{
private:
    /// @internal
    /// @brief The parsing expression.
    Expr m_expr;

public:
    /// @internal
    /// @brief Construct this parsing expression.
    /// @param expr the expression
    repetition_expr(Expr expr) :
        m_expr(expr)
    {}

    template <typename It>
    bool operator()(It& at, It& end) const
    {
        while (m_expr(at, end))
        {
        }
        return true;
    }
};

/// @brief Create a repetition of a parsing expression.
/// The repetition of a parsing expression accepts if the parsing expression accepts zero or more times.
/// @detail That is, the @a repetition of a parsing expressions @code{e}
/// is defined as
/// @code{repetition(e) = e*}.
/// @tparam Sym the symbol type
/// @tparam Expr the type of the expression
/// @param expr the expression
/// @return the parsing expression
template <typename Sym, typename Expr>
repetition_expr<Sym, Expr> repetition(Expr&& expr)
{
    return repetition_expr<Sym, Expr>(std::forward<Expr>(expr));
}

} } // namespace id::parsing_expressions
