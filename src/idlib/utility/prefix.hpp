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

/// @file idlib/utility/prefix.hpp
/// @brief Test if a string is prefix of another string.
/// @detail A word @a v is a prefix of a word @a w if there exists a decomposition such that w = vu.
/// @a v is a true prefix of @a w if @a u is not empty.
/// @author Michael Heilmann

#pragma once

#include <string>

#include "idlib/utility/internal/header.hpp"

/// @brief Get if a string is a prefix of another string.
/// @param w the string
/// @param v the string which is tested if it is a prefix of @a w
/// @return @a true if @a v is a prefix of @a w, @a false otherwise
template <typename CharType>
bool is_prefix(const std::basic_string<CharType>& w, const std::basic_string<CharType>& v)
{
    if (v.size() > w.size()) return false;
    return std::equal(v.begin(), v.end(), w.begin());
}

/// @brief Get if a string is a true prefix of another string.
/// @param w the string
/// @param v the string which is tested if it is a true prefix of @a w
/// @return @a true if @a v is a true prefix of @a w, @a false otherwise
template <typename CharType>
bool is_true_prefix(const std::basic_string<CharType>& w, const std::basic_string<CharType>& v)
{
    if (v.size() >= w.size()) return false;
    return std::equal(v.begin(), v.end(), w.begin());
}

#include "idlib/utility/internal/footer.hpp"
