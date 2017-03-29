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

/// @file idlib/location.hpp
/// @brief Definition of a location in a text.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/idlib.hpp` instead)
#endif

#include "idlib/crtp.hpp"
#include <type_traits>

namespace id {

/// @brief A location is identified by a file name and line number within that file.
class location : public id::equal_to_expr<location>
{
private:
    /// @brief The file name of the file.
    std::string m_file_name;

    /// @brief The line number of a line within the file.
    size_t m_line_number;

public:
    /// @brief Construct this location.
    /// @param file_name the file name of the file
    /// @param line_number the line number of a line within the file
    location(const std::string& file_name, const size_t line_number);

    /// @brief Copy-Construct this lociation from another location.
    /// @param other the other location
    location(const location& other);

    /// @brief Move-construct this location from another location.
    /// @param other the other location
    location(location&& other);

    /// @brief Assign this location from another location.
    /// @param other the other location
    /// @return this location
    location& operator=(location other);

    /// @brief Get the file name of the file of this location.
    /// @return the file name of the file
    const std::string& file_name() const;

    /// @brief Get the line number of a line in the file.
    /// @return the line number of a line in the file
    size_t line_number() const;

    // CRTP
    bool equal_to(const location& other) const;

    /// @brief Swap two locations.
    /// @param x, y the locations
    friend void swap(location& x, location& y)
    {
        using std::swap;
        swap(x.m_file_name, y.m_file_name);
        swap(x.m_line_number, y.m_line_number);
    }

}; // class location

static_assert(std::is_copy_constructible<location>::value, "id::location must be copy constructible");
static_assert(std::is_move_constructible<location>::value, "id::location must be move constructible");
static_assert(std::is_copy_assignable<location>::value, "id::location must be copy assignable");
static_assert(std::is_move_assignable<location>::value, "id::location must be move assignable");

} // namespace id
