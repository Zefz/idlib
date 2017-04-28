/// @file id/math/interpolate.hpp
/// @brief Functionality to interpolate between floating point values.
/// @author Michael Heilmann

#pragma once

#include "idlib/math/interpolate.hpp"
#include "idlib/math/mu.hpp"
#include "idlib/math/one_zero.hpp"

namespace id {

/// @brief Interpolation functor specialization for floating point types.
template <typename T>
struct interpolation_functor<T, interpolation_method::LINEAR, std::enable_if_t<std::is_floating_point_v<T>>>
{
    /// @brief Interpolate between to floating point values.
    /// @param x, y the values to interpolate between
    /// @param t the parameter. Must be within the bounds of @a 0 (inclusive) and @a 1 (inclusive).
    /// @return the interpolated value
    /// @throw out_of_bounds_exception @a t is not within the bounds of @a 0 (inclusive) and @a 1 (inclusive)
    T operator()(T x, T y, T t) const
    {
        return (*this)(x, y, mu<T>(t));
    }

    /// @brief Interpolate between to floating point values.
    /// @param x, y the values to interpolate between
    /// @param t the parameter
    /// @return the interpolated value
    T operator()(T x, T y, const mu<T>& mu) const
    {
        return x * mu.getOneMinusValue() + y * mu.getValue();
    }

}; // struct interpolation_functor

} // namespace id
