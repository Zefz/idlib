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

/// @file idlib/TextRange.cpp
/// @brief Information on a text range in a text.
/// @author Michael Heilmann

#define IDLIB_PRIVATE 1
#include "idlib/TextRange.hpp"
#undef IDLIB_PRIVATE

namespace Id {

TextRange::TextRange(size_t start, size_t length) noexcept :
	start(start), length(length)
{}

TextRange::TextRange(const TextRange& other) noexcept :
	start(other.start), length(other.length)
{}

TextRange& TextRange::operator=(const TextRange& other) noexcept
{
	start = other.start;
	length = other.length;
	return *this;
}

bool TextRange::isEmpty() const noexcept
{
	return 0 == getLength();	
}

size_t TextRange::getStart() const noexcept
{
	return start;
}

#if defined(ID_TEXTRANGE_MUTABLE) && 1 == ID_TEXTRANGE_MUTABLE
void TextRange::setStart(size_t start) noexcept
{
	this->start = start;
}
#endif

size_t TextRange::getLength() const noexcept
{
	return length;
}

#if defined(ID_TEXTRANGE_MUTABLE) && 1 == ID_TEXTRANGE_MUTABLE
void TextRange::setLength(size_t length) noexcept
{
	this->length = length;
}
#endif

} // namespace Id
