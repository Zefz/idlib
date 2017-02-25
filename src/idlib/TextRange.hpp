//********************************************************************************************
//*
//*    This file is part of Egoboo.
//*
//*    Egoboo is free software: you can redistribute it and/or modify it
//*    under the terms of the GNU General Public License as published by
//*    the Free Software Foundation, either version 3 of the License, or
//*    (at your option) any later version.
//*
//*    Egoboo is distributed in the hope that it will be useful, but
//*    WITHOUT ANY WARRANTY; without even the implied warranty of
//*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//*    General Public License for more details.
//*
//*    You should have received a copy of the GNU General Public License
//*    along with Egoboo.  If not, see <http://www.gnu.org/licenses/>.
//*
//********************************************************************************************

/// @file idlib/TextRange.hpp
/// @brief Information on a text range in a text.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/idlib.hpp` instead)
#endif

#include "idlib/Platform.hpp"

/// @brief If defined to @a 1, text ranges are mutable i.e. provide setters.
#define ID_TEXTRANGE_MUTABLE (0)

namespace Id {

/// @brief Information on a text range in a text.
/// @remark A text range (start, length) is empty iff length = 0.
struct TextRange
{
private:
    /// @brief The codepoint at which the text range starts.
    size_t start;

    /// @brief The length of the text range in codepoints.
    size_t length;

public:
    /// @brief Construct this text range with the specified values.
    /// @param start the codepoint at which this text range starts at
    /// @param length the length of this text range in codepoints
    TextRange(size_t start, size_t length) noexcept;

public:
    /// @brief Construct this text range with the values of another text range.
    /// @param other the other text range
    TextRange(const TextRange& other) noexcept;

    /// @brief Assign this text range with the values of another text range.
    /// @param other the other text range
    /// @return this text range
    TextRange& operator=(const TextRange& other) noexcept;

public:
    /// @brief Get if this text range is empty.
    /// @return @a true if this text range is empty, @a false otherwise
    bool isEmpty() const noexcept;

public:
    /// @brief Get the codepoint at which the text range starts.
    /// @return the codepoint at which the text range starts
    size_t getStart() const noexcept;

#if defined(ID_TEXTRANGE_MUTABLE) && 1 == ID_TEXTRANGE_MUTABLE
    /// @brief Set the codepoint at which this text range starts.
    /// @param start the codepoint at which this text range starts
    void setStart(size_t start) noexcept;
#endif

    /// @brief Get the length of this text range in codepoints.
    /// @return the length of this text range in codepoints
    size_t getLength() const noexcept;

#if defined(ID_TEXTRANGE_MUTABLE) && 1 == ID_TEXTRANGE_MUTABLE
    /// @brief Set the length of this text range in codepoints.
    /// @param length the length of this text range in codepoints
    void setLength(size_t length) noexcept;
#endif

};

} // namespace Id
