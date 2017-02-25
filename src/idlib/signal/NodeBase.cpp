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

/// @file idlib/signal/NodeBase.cpp
/// @brief Non-generic base class of all nodes.
/// @author Michael Heilmann

#define IDLIB_PRIVATE 1
#include "idlib/signal/NodeBase.hpp"
#undef IDLIB_PRIVATE

namespace Id {
namespace Internal {

NodeBase::NodeBase(int numberOfReferences)
    : state(State::Disconnected), signal(nullptr), numberOfReferences(numberOfReferences), next(nullptr)
{}

NodeBase::~NodeBase() {}

bool NodeBase::hasSignal() const
{
    return nullptr != signal;
}

bool NodeBase::hasReferences() const
{
    return 0 < getNumberOfReferences();
}

int NodeBase::getNumberOfReferences() const
{
    return numberOfReferences;
}

void NodeBase::addReference()
{
    numberOfReferences++;
}

void NodeBase::removeReference()
{
    if (0 == --numberOfReferences)
    {
        /* Nothing to do yet. */
    }
}

} // namespace Internal
} // namespace Id
