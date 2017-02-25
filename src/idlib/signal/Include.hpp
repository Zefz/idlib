#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/idlib.hpp` instead)
#endif

#include "idlib/signal/Signal.hpp"
#include "idlib/signal/Connection.hpp"
#include "idlib/signal/ScopedConnection.hpp"
