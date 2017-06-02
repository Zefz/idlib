#pragma once

#include "idlib/utility/platform.hpp"

#if defined(ID_WINDOWS)
    #include "idlib/file_system/mapped_file_windows.hpp"
#elif defined(ID_OSX)
    #error("operating system not supported")
#elif defined(ID_LINUX)
#include "idlib/file_system/mapped_file_linux.hpp"
#else
    #error("operating system not supported")	
#endif
