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

/// @file idlib/utility/suffix.hpp
/// @brief Conversion of characters and strings to lowercase.
/// @detail A word @a v is a suffix of a word @a w if there exists a decomposition such that w = uv.
/// @a v is a true suffix of @a w if @a u is not empty.
/// @author Michael Heilmann

#pragma once

#include <string>

#include "idlib/utility/header.in"

/// @brief Get if a string is a suffix of another string.
/// @param w the string
/// @param v the string which is tested if it is a suffix of @a w
/// @return @a true if @a v is a suffix of @a w, @a false otherwise
template <typename CharType>
bool is_suffix(const std::basic_string<CharType>& w, const std::basic_string<CharType>& v)
{
    if (v.size() > w.size()) return false;
    return std::equal(v.rbegin(), v.rend(), w.rbegin());
}

/// @brief Get if a string is a true suffix of another string.
/// @param w the string
/// @param v the string which is tested if it is a true suffix of @a w
/// @return @a true if @a v is a true suffix of @a w, @a false otherwise
template <typename CharType>
bool is_true_suffix(const std::basic_string<CharType>& w, const std::basic_string<CharType>& v)
{
    if (v.size() >= w.size()) return false;
    return std::equal(v.rbegin(), v.rend(), w.rbegin());
}

#include "idlib/utility/footer.in"
