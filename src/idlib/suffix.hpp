/// @file idlib/suffix.hpp
/// @brief Conversion of characters and strings to lowercase.
/// @detail A word @a v is a suffix of a word @a w if there exists a decomposition such that w = uv.
/// @a v is a true suffix of @a w if @a u is not empty.
/// @author Michael Heilmann

#pragma once

#include <string>

namespace id {

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

} // namespace id
