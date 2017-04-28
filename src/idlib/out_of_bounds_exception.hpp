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

/// @file idlib/out_of_bounds_exception.hpp
/// @brief Definition of an exception indicating a value is out of bounds.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/idlib.hpp` instead)
#endif

#include "idlib/exception.hpp"

namespace id {

/// @brief Exception indicating a value is out of bounds
class out_of_bounds_exception : public exception
{
public:
    /// @brief Construct this exception.
    /// @param file the C++ source file (as obtained by the __FILE__ macro) associated with this exception
    /// @param line the line within the C++ source file (as obtained by the __LINE__ macro) associated with this exception
    /// @param message optional exception string message
    out_of_bounds_exception(const char *file, int line, const std::string& message = "Value out of bounds") :
        id::exception(file, line), _message(message)
    {}

    /// @brief Construct this exception with the value of another exception.
    /// @param other the other exception
    out_of_bounds_exception(const out_of_bounds_exception& other) :
        id::exception(other), _message(other._message)
    {}

    /// @brief Assign this exception the values of another exception.
    /// @param other the other exception
    /// @return this exception
    out_of_bounds_exception& operator=(const out_of_bounds_exception& other)
    {
        id::exception::operator=(other);
        _message = other._message;
        return *this;
    }

public:
    /// @brief Get the message associated with this exception.
    /// @return the message associated with this exception
    const std::string& getMessage() const
    {
        return _message;
    }

    /// @brief Overloaded cast operator for casting into std::string.
    /// @return a human-readable textual description of the string.
    virtual operator std::string() const override
    {
        std::ostringstream buffer;
        buffer << "(raised in file " << getFile() << ", line " << getLine() << ")"
            << ":" << std::endl;
        buffer << _message;
        return buffer.str();
    }

private:
    std::string _message;
};

} // namespace id
