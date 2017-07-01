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

/// @file idlib/parsing_expressions/sym_range.hpp
/// @brief "range" parsing expression.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/parsing_expressions/include.hpp` instead)
#endif

#include "idlib/utility/platform.hpp"

namespace id { namespace parsing_expressions {

/// @internal
/// @brief Parsing expression accepting a range of symbols.
/// @tparam the symbol type
template <typename Sym>
struct sym_range_expr
{
private:
    /// @internal
    /// @brief The first symbol (incl.).
    Sym m_first;

    /// @internal
    /// @brief The last symbol (incl.).
    Sym m_last;

public:
    /// @internal
    /// @brief Construct this parsing expression.
    /// @param first the first symbol (incl.)
    /// @param last the last symbol (incl.)
    sym_range_expr(Sym first, Sym last) :
        m_first(first), m_last(last)
    {}

    template <typename It>
    std::pair<bool, It> operator()(It at, It end) const
    {
        if (at != end && (m_first <= *at && *at <= m_last))
        {
            return std::make_pair(true, ++at);
        }
        else
        {
            return std::make_pair(false, at);
        }
    }
};

/// @brief Create a parsing expression accepting a range of symbols.
/// @tparam Sym the symbol type
/// @param first the first symbol (incl.)
/// @param last the last symbol (incl.)
/// @return the parsing expression
template <typename Sym>
sym_range_expr<Sym> sym_range(Sym first, Sym last)
{
    return sym_range_expr<Sym>(first, last);
}

} } // namespace id::parsing_expressions
