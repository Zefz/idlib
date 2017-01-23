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

/// @file IdLib/Signal/Connection.hpp
/// @brief A connection.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `IdLib/IdLib.hpp` instead)
#endif

#include "IdLib/Signal/ConnectionBase.hpp"
#include "IdLib/Signal/NodeBase.hpp"
#include "IdLib/Signal/SignalBase.hpp"

namespace Id {

/// @ingroup signal
/// @brief A connection.
struct Connection : Id::Internal::ConnectionBase
{
    Connection()
        : Id::Internal::ConnectionBase(nullptr) {}
    Connection(Internal::NodeBase *node)
        : ConnectionBase(node) {}
    Connection(const Connection& other)
        : Id::Internal::ConnectionBase(other) {}
    const Connection& operator=(const Connection& other)
    {
        Id::Internal::ConnectionBase::operator=(other);
        return *this;
    }
    bool operator==(const Connection& other) const
    {
        return ConnectionBase::operator==(other);
    }
    bool operator!=(const Connection& other) const
    {
        return ConnectionBase::operator!=(other);
    }
}; // struct Connection

} // namespace Id
