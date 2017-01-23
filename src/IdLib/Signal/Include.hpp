#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `IdLib/IdLib.hpp` instead)
#endif

#include "IdLib/Signal/Signal.hpp"
#include "IdLib/Signal/Connection.hpp"
#include "IdLib/Signal/ScopedConnection.hpp"