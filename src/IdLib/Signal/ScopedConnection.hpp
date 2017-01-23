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

/// @file IdLib/Signal/ScopedConnection.hpp
/// @brief Scoped connection.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `IdLib/IdLib.hpp` instead)
#endif

#include "IdLib/Signal/Connection.hpp"

namespace Id {

/// @ingroup signal
/// @brief A scoped connection disconnects a signal and a slot of it is destroyed.
/// Scoped connections are neither copy-constructible nor assignable.
struct ScopedConnection {
private:
    Connection connection;

public:
    /// @brief Construct this scoped connection from a connection.
    /// @param connection the connection
    ScopedConnection(const Connection& connection)
        : connection(connection) {
    }

private:
    /// Deleted copy-constructor.
    ScopedConnection(const ScopedConnection& other) = delete;

    /// Deleted assignment operator.
    const ScopedConnection& operator=(const ScopedConnection& other) = delete;

public:
    /// Destruct this scoped connection.
    virtual ~ScopedConnection() {
        connection.disconnect();
    }

    /// @brief Get if the connection is connected.
    /// @return @a true if the connection is connected, @a false otherwise
    bool isConnected() const {
        return connection.isConnected();
    }

    /// @brief Disconnect the connection.
    void disconnect() {
        connection.disconnect();
    }

}; // struct ScopedConnection

} // namespace Id
