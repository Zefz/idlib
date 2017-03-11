/// @file idlib/to_upper.hpp
/// @brief Conversion of characters and strings to uppercase.
/// @detail For each function an in-place (aka in-situ) variant and a variant returning a copy are provided.
/// @author Michael Heilmann

#pragma once

#include <locale>
#include <algorithm>

namespace id {

/// @brief In-place (aka in-situ) convert a character to upper case.
/// @param x the character
/// @param lc the locale to use. Default is std::locale().
template <class CharType>
void to_upper_in_situ(CharType& x, const std::locale& lc = std::locale())
{
    x = std::toupper(x, lc);
}

/// @brief Convert a character to upper case.
/// @param x the character
/// @param lc the locale to use. Default is std::locale().
/// @return the upper case character
template <class CharType>
CharType to_upper(CharType x, const std::locale& lc = std::locale())
{
    return std::toupper(x, lc);
}

/// @brief In-place (aka in-situ) convert a string to upper case.
/// @param w the string
/// @param lc the locale to use. Default is std::locale().
template <typename CharType>
void to_upper_in_situ(std::basic_string<CharType>& w, const std::locale& lc = std::locale())
{
    // Capture lc by reference, capture nothing else.
    auto f = [&lc](const CharType chr) -> CharType { return to_upper(chr, lc); };
    std::transform(w.begin(), w.end(), w.begin(), f);
}

/// @brief In-place (aka in-situ) convert a string to upper case.
/// @param w the string
/// @param lc the locale to use. Default is std::locale().
/// @return the upper case string
template <typename CharType>
std::basic_string<CharType> to_upper(std::basic_string<CharType> w, const std::locale& lc = std::locale())
{
    // Capture lc by reference, capture nothing else.
    auto f = [&lc](const CharType chr) -> CharType { return to_upper(chr, lc); };
    std::transform(w.begin(), w.end(), w.begin(), f);
	return w;
}

} // namespace id
