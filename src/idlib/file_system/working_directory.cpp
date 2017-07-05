// Copyright Michael Heilmann 2016, 2017.
//
// This file is part of Idlib.
//
// Idlib is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Idlib is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Idlib. If not, see <http://www.gnu.org/licenses/>.

/// @file idlib/file_system/working_directory.cpp
/// @brief Determine the working directory.
/// @author Michael Heilmann

#include "idlib/file_system/working_directory.hpp"

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "idlib/file_system/header.in"

std::string get_working_directory()
{
#if defined(_WIN32)
    auto length = GetCurrentDirectory(0, NULL);
    if (!length)
    {
        throw std::runtime_error("unable to obtain working directory");
    }
    auto buffer = std::make_unique<char[]>(length + 1);
    length = GetCurrentDirectory(length + 1, buffer.get());
    if (!length)
    {
        throw std::runtime_error("unable to obtain working directory");
    }
    return std::string(buffer.get());
#else
	std::unique_ptr<char, decltype(std::free) *> path{get_current_dir_name(), std::free };
	if (!path)
	{
		throw std::runtime_error("unable to obtain working directory");
	}
	return std::string(path.get());
#endif
}

#include "idlib/file_system/footer.in"

