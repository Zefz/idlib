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

/// @file IdLib/Signal/SignalBase.hpp
/// @brief Non-generic base class of all signals.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `IdLib/IdLib.hpp` instead)
#endif

#include "IdLib/Platform.hpp"

namespace Id {
namespace Internal {

// Forward declarations.
struct ConnectionBase;
struct NodeBase;
struct SignalBase;

/// @internal
/// @ingroup signal
/// @brief Non-generic base class of any signal.
struct SignalBase
{
    friend struct ConnectionBase;
protected:
    NodeBase *head;   ///< @brief The head of the nodes.
    bool running;     ///< @brief @a true if the signal is currently running, @a false otherwise.
    size_t connectedCount; ///< @brief The number of connected nodes.
    size_t disconnectedCount; ///< @brief The number of disconnected nodes.

    /// @brief Remove all dead subscriptions if the number of dead nodes exceeds the number of live nodes.
    /// @precondition The signal is not currently running.
    void maybeSweep() noexcept;

    /// @brief Does the subscriber list need sweeping?
    /// @return @a true if the subscriber list needs sweeping, @a false otherwise
    bool needsSweep() const noexcept;

public:
    SignalBase(const SignalBase&) = delete; // Do not allow copying.
    const SignalBase& operator=(const SignalBase&) = delete; // Do not allow copying.

public:
    /// @brief Default construct this signal base.
    SignalBase() noexcept;

    /// @brief Destruct this signal base.
    /// Disconnects all nodes.
    virtual ~SignalBase() noexcept;

    /// @brief Disconnect all nodes.
    void disconnectAll() noexcept;

private:
    /// @brief Sweep the list of nodes.
    /// Delete any node (from the singly-linked list of nodes) that is not referenced by a connection.
    void sweep() noexcept;

};

} // namespace Internal
} // namespace Id
