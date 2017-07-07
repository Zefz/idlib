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
/// @see id::any_sym for more information.
/// @tparam Sym the symbol type
template <typename Sym>
class any_sym_expr
{
public:
    /// @internal
    /// @brief Construct this parsing expression.
	any_sym_expr()
	{}

    template <typename It>
    std::pair<bool, It> operator()(It at, It end) const
    {
		if (at == end)
		{
			return std::make_pair(false, at);		
		}
		return std::make_pair(true, ++at);
    }

}; // class any_sym_expr

/// @brief Create an any symbol parsing expression.
/// The any symbol parsing expression accepts any symbol.
/// @return the parsing expression
/// @tparam Sym the symbol type
template <typename Sym>
any_sym_expr<Sym> any_sym()
{
    return any_sym_expr<Sym>();
}

#include "idlib/parsing_expressions/footer.in"
