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

/// @file idlib/signal/ConnectionBase.hpp
/// @brief Non-generic base class of all connections.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/idlib.hpp` instead)
#endif

#include "idlib/platform.hpp"

namespace Id {
namespace Internal {

// Forward declarations.
struct NodeBase;
struct SignalBase;

/// @internal
/// @ingroup signal
/// @brief Non-generic base class of all connections.
struct ConnectionBase
{
    /// @brief A pointer to the node.
    NodeBase *node;

    /// @brief Default construct this connection.
    /// @post This connection is not connected.
    ConnectionBase();

    /// @brief Construct this connection with the specified arguments.
    /// @param node a pointer to a node of the signal
    ConnectionBase(NodeBase *node);

    /// Copy construct this connection with the values of another connection.
    /// @param other the other connection
    ConnectionBase(const ConnectionBase& other);

    /// @brief Destruct this connection.
    virtual ~ConnectionBase();

    const ConnectionBase& operator=(const ConnectionBase& other);

    bool operator==(const ConnectionBase& other) const;

    bool operator!=(const ConnectionBase& other) const;


    /// @brief Get if the connection is connected.
    /// @return @a true if this connection is connected, @a false otherwise
    bool isConnected() const;

    /// @brief Disconnect this connection.
    void disconnect();

private:
    void reset();

}; // struct Connection

} // namespace Internal
} // namespace Id
