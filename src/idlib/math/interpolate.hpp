/// @file id/math/interpolate.hpp
/// @brief Functionality to interpolate between values.
/// @author Michael Heilmann

#pragma once

#include "idlib/math/interpolation_method.hpp"
#include "idlib/math/mu.hpp"
#include "idlib/math/one_zero.hpp"

namespace id {

/// @brief Functor which interpolates between values.
/// @tparam T the type of the values to interpolate between.
/// @tparam M the interpolation method
/// @tparam E for SFINAE
template <typename T, interpolation_method M, typename E = void>
struct interpolation_functor;

} // namespace id
