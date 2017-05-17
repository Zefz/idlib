/// @file id/math/interpolate.hpp
/// @brief Functionality to interpolate between values.
/// @author Michael Heilmann

#pragma once

#include "idlib/math/one_zero.hpp"
#include "idlib/OutOfBoundsException.hpp"

namespace id {

/// @brief Representation of \f$\mu\f$ (mu).
/// @detail The greek letter \f$\mu\f$ (mu) is the name for the interpolation parameter in interpolation.
/// @detail Objects of type @a mu are caches and contracts at the same time:
/// - they are caches as they store two values of which one is one minus the other value (cache)
/// - they guarantee that both values are within the bounds of \f$[0,1]\f$
/// @remark Specializations for @a float and @a double are provided.
template <typename T, typename E = void>
class mu;

template <typename T>
class mu<T, std::enable_if_t<std::is_floating_point_v<T>>>
{
private:
    T m_oneMinusValue;
    T m_value;
public:
    /// @brief Construct this mu.
    /// @param mu the float value this mu represents
    /// @throw id::out_of_bounds_exception @a mu is smaller than @a 0 or greater than @a 1
    mu(T value) :
        m_value(value)
    {
        if (value < zero<T>()) throw Id::OutOfBoundsException(__FILE__, __LINE__);
        else if (value > one<T>()) throw Id::OutOfBoundsException(__FILE__, __LINE__);
        m_oneMinusValue = one<T>() - value;
    }

    /// @brief Copy-construct this mu.
    /// @param mu the other mu
    /// @return this mu
    mu(const mu& other) noexcept :
        m_value(other.m_value),
        m_oneMinusValue(other.m_oneMinusValue)
    {}

    /// @brief Copy-assign this mue from another mu.
    /// @param other the other mu
    /// @return this mu
    mu& operator=(const mu& other) noexcept
    {
        m_value = other.m_value;
        m_oneMinusValue = other.m_oneMinusValue;
        return *this;
    }
    /// @brief Get the value.
    /// @return the value
    const T& getValue() const noexcept
    {
        return m_value;
    }

    /// @brief Get one minus the value.
    /// @return one minus the value
    const T& getOneMinusValue() const noexcept
    {
        return m_oneMinusValue;
    }

}; // class mu

} // namespace id
