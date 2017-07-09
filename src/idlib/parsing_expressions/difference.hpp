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

/// @file idlib/parsing_expressions/any_sym.hpp
/// @brief "any symbol" parsing expression.
/// @author Michael Heilmann

#include "idlib/utility/platform.hpp"

#include "idlib/parsing_expressions/header.in"

/// @internal
/// @brief See id::difference for more information.
/// @tparam Expr1 the expression type of the first expression
/// @tparam Expr2 the expression type of the second expression
template <typename Expr1, typename Expr2>
class difference_expr
{
private:
    /// @brief The first expression.
    Expr1 m_expr1;
    /// @brief The second expression.
    Expr2 m_expr2;
public:
    /// @internal
    /// @brief Construct this parsing expression.
    /// @param expr1 the first expression
    /// @param expr2 the second expression
    difference_expr(Expr1 expr1, Expr2 expr2) :
        m_expr1(expr1), m_expr2(expr2)
    {}

    template <typename It>
    match<std::decay_t<It>> operator()(It at, It end) const
    {
        auto result1 = m_expr1(at, end);
        if (result1.first)
        {
            auto result2 = m_expr2(at, end);
            if (!result2.first)
            {
                return result1;
            }
        }
        return make_match(false, at);
    }

}; // class difference_expr

/// @brief Create a difference of a parsing expression and another parsing expression.
/// The difference of a parsing expression and another parsing expression accepts if
/// the former accepts and the latter does not accept.
/// @tparam Expr the type of the expression
/// @param expr1 the first expression
/// @param expr2 the second expression
/// @return the parsing expression
template <typename Expr1, typename Expr2>
difference_expr<Expr1, Expr2> difference(Expr1 expr1, Expr2 expr2)
{
    return difference_expr<Expr1, Expr2>(expr1, expr2);
}

#include "idlib/parsing_expressions/footer.in"
