/// @file idlib/prefix.hpp
/// @brief Test if a string is prefix of another string.
/// @detail A word @a v is a prefix of a word @a w if there exists a decomposition such that w = vu.
/// @a v is a true prefix of @a w if @a u is not empty.
/// @author Michael Heilmann

#pragma once

#include <string>

namespace id {

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

} // namespace id
