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

/// @file idlib/text_range.cpp
/// @brief Information on a text range in a text.
/// @author Michael Heilmann

#define IDLIB_PRIVATE 1
#include "idlib/text_range.hpp"
#undef IDLIB_PRIVATE

namespace id {

text_range::text_range(size_t start, size_t length) noexcept :
	start(start), length(length)
{}

text_range::text_range(const text_range& other) noexcept :
	start(other.start), length(other.length)
{}

text_range& text_range::operator=(const text_range& other) noexcept
{
	start = other.start;
	length = other.length;
	return *this;
}

bool text_range::is_empty() const noexcept
{
	return 0 == get_length();	
}

size_t text_range::get_start() const noexcept
{
	return start;
}

#if defined(ID_TEXT_RANGE_MUTABLE) && 1 == ID_TEXT_RANGE_MUTABLE
void text_range::set_start(size_t start) noexcept
{
	this->start = start;
}
#endif

size_t text_range::get_length() const noexcept
{
	return length;
}

#if defined(ID_TEXT_RANGE_MUTABLE) && 1 == ID_TEXT_RANGE_MUTABLE
void text_range::set_length(size_t length) noexcept
{
	this->length = length;
}
#endif

} // namespace id
