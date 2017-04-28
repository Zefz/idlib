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

/// @file idlib/idlib.hpp
/// @brief Master include file for idlib.
/// @author Michael Heilmann

#pragma once

#define IDLIB_PRIVATE 1
#include "idlib/target.hpp"
#include "idlib/platform.hpp"
#include "idlib/NonCopyable.hpp"

// Exceptions.
#include "idlib/exception.hpp"
#include "idlib/EnvironmentErrorException.hpp"
#include "idlib/AssertionFailedException.hpp"
#include "idlib/UnhandledSwitchCaseException.hpp"
#include "idlib/RuntimeErrorException.hpp"
#include "idlib/InvalidArgumentException.hpp"
#include "idlib/OutOfBoundsException.hpp"

// Bitmask types.
#include "idlib/BitmaskTypes.hpp"

// CRTP.
#include "idlib/crtp.hpp"

// Text utilities.
#include "idlib/text_range.hpp"

// DSL utilities.
#include "idlib/location.hpp"
#include "idlib/qualified_name.hpp"
#include "idlib/token.hpp"

// DSL exceptions.
#include "idlib/CompilationErrorException.hpp"

// Define __ID_CURRENT_FILE__, __ID_CURRENT_LINE__ and __ID_CURRENT_FUNCTION__.
// Those constants will either be properly defined or not at all.
#include "idlib/CurrentFunction.inline"

// Debug assertions.
#include "idlib/DebugAssert.hpp"

// Signals.
#include "idlib/signal/Include.hpp"

// Colors.
#include "idlib/color/include.hpp"

// Math.
#include "idlib/math/dimensionality.hpp"

#undef IDLIB_PRIVATE
