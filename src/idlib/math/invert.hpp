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

/// @file id/math/invert.hpp
/// @brief Functionality to invert values.
/// @author Michael Heilmann

#pragma once

namespace id {

/// @brief Functor which inverts values.
/// @tparam T the type of the values
/// @tparam E for SFINAE
template <typename T, typename E = void>
struct inversion_functor;

template <typename T>
decltype(auto) invert(const T& value)
{
	return inversion_functor<T>()(value);
}

} // namespace
