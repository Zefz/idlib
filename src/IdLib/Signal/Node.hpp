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

/// @file IdLib/Signal/Node.hpp
/// @brief Nodes.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `IdLib/IdLib.hpp` instead)
#endif

#include "IdLib/Signal/NodeBase.hpp"

namespace Id {
namespace Internal {

// Forward declaration.
template <class ReturnType, class ... ParameterTypes>
struct Node;

/// @ingroup signal
/// @brief A generic node.
template <class ReturnType, class ... ParameterTypes>
struct Node<ReturnType(ParameterTypes ...)> : Internal::NodeBase
{
public:
    /// The node type.
    using NodeType = Node<ReturnType(ParameterTypes ...)>;
    /// The function type.
    using FunctionType = std::function<ReturnType(ParameterTypes ...)>;

public:
    /// The function.
    FunctionType function;

public:
    Node(const NodeType&) = delete; // Do not allow copying.
    const NodeType& operator=(const NodeType&) = delete; // Do not allow copying.

public:
    /// @brief Construct this node.
    /// @param numberOfReferences the initial number of references
    /// @param function the function
    explicit Node(int numberOfReferences, const FunctionType& function)
        : Internal::NodeBase(numberOfReferences), function(function) {}

public:
    /// @brief Invoke this node
    /// @param arguments (implied)
    /// @return (implied)
    ReturnType operator()(ParameterTypes&& ... arguments)
    {
        function(std::forward<ParameterTypes>(arguments) ...);
    }
};

} // namespace Internal
} // namespace Id
