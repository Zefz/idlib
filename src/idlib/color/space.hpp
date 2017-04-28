#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/idlib.hpp` instead)
#endif

#include "idlib/platform.hpp"

namespace id {

/// @brief The type of an L colour space with floating-point components each within the range from 0 (inclusive) to 1 (inclusive).
/// A component value of 0 indicates minimal intensity of the component and 1 indicates maximal intensity of the component.
struct Lf
{
    /// @brief The component type.
    using ComponentType = float;

    /// @brief Get if the colour space has RGB components.
    /// @return @a true if the colour space has RGB components, @a false otherwise
    static constexpr bool has_rgb() noexcept { return false; }

    /// @brief Get if the colour space has an A component.
    /// @return @a true if the colour space has an A component, @a false otherwise
    static constexpr bool has_a() noexcept { return false; }

    /// @brief Get if the colour space has a L component.
    /// @return @a true if the colour space has an L component, @a false otherwise
    static constexpr bool has_l() noexcept { return true; }

    /// @brief Get the number of components of a colour in the colour space.
    /// @return the number of components of a colour in the colour space
    static constexpr size_t count() noexcept { return 1; }

    /// @brief Get the minimum component value.
    /// @return the minimum component value
    static constexpr ComponentType min() noexcept { return 0.0f; }

    /// @brief Get the maximum component value.
    /// @return the maximum component value
    static constexpr ComponentType max() noexcept { return 1.0f; }
};

/// @brief The type of an LA colour space with floating-point components each within the range from 0 (inclusive) to 1 (inclusive).
/// A component value of 0 indicates minimal intensity of the component and 1 indicates maximal intensity of the component.
struct LAf
{
    /// @brief The component type.
    using ComponentType = float;

    /// @brief Get if the colour space has RGB components.
    /// @return @a true if the colour space has RGB components, @a false otherwise
    static constexpr bool has_rgb() noexcept { return false; }

    /// @brief Get if the colour space has an A component.
    /// @return @a true if the colour space has an A component, @a false otherwise
    static constexpr bool has_a() noexcept { return true; }

    /// @brief Get if the colour space has a L component.
    /// @return @a true if the colour space has an L component, @a false otherwise
    static constexpr bool has_l() noexcept { return true; }

    /// @brief Get the number of components of a colour in the colour space.
    /// @return the number of components of a colour in the colour space
    static constexpr size_t count() noexcept { return 2; }

    /// @brief Get the minimum component value.
    /// @return the minimum component value
    static constexpr ComponentType min() noexcept { return 0.0f; }

    /// @brief Get the maximum component value.
    /// @return the maximum component value
    static constexpr ComponentType max() noexcept { return 1.0f; }
};

/// @brief The type of an L colour space with unsigned integer components each within the range from 0 (inclusive) to 255 (inclusive).
/// A component value of 0 indicates minimal intensity of the component and 255 indicates maximal intensity of the component.
struct Lb
{
    /// @brief The component type.
    using ComponentType = uint8_t;

    /// @brief Get if the colour space has RGB components.
    /// @return @a true if the colour space has RGB components, @a false otherwise
    static constexpr bool has_rgb() noexcept { return false; }

    /// @brief Get if the colour space has an A component.
    /// @return @a true if the colour space has an A component, @a false otherwise
    static constexpr bool has_a() noexcept { return false; }

    /// @brief Get if the colour space has a L component.
    /// @return @a true if the colour space has an L component, @a false otherwise
    static constexpr bool has_l() noexcept { return true; }

    /// @brief Get the number of components of a colour in the colour space.
    /// @return the number of components of a colour in the colour space
    static constexpr size_t count() noexcept { return 1; }

    /// @brief Get the minimum component value.
    /// @return the minimum component value
    static constexpr ComponentType min() noexcept { return 0; }

    /// @brief Get the maximum component value.
    /// @return the maximum component value
    static constexpr ComponentType max() noexcept { return 255; }
};

/// @brief The type of an LA colour space with unsigned integer components each within the range from 0 (inclusive) to 255 (inclusive).
/// A component value of 0 indicates minimal intensity of the component and 255 indicates maximal intensity of the component.
struct LAb
{
    /// @brief The component type.
    using ComponentType = uint8_t;

    /// @brief Get if the colour space has RGB components.
    /// @return @a true if the colour space has RGB components, @a false otherwise
    static constexpr bool has_rgb() noexcept { return false; }

    /// @brief Get if the colour space has an A component.
    /// @return @a true if the colour space has an A component, @a false otherwise
    static constexpr bool has_a() noexcept { return true; }

    /// @brief Get if the colour space has a L component.
    /// @return @a true if the colour space has an L component, @a false otherwise
    static constexpr bool has_l() noexcept { return true; }

    /// @brief Get the number of components of a colour in the colour space.
    /// @return the number of components of a colour in the colour space
    static constexpr size_t count() noexcept { return 2; }

    /// @brief Get the minimum component value.
    /// @return the minimum component value
    static constexpr ComponentType min() noexcept { return 0; }

    /// @brief Get the maximum component value.
    /// @return the maximum component value
    static constexpr ComponentType max() noexcept { return 255; }
};

/// @brief The type of an RGB colour space with floating-point components each within the range from 0 (inclusive) to 1 (inclusive).
/// A component value of 0 indicates minimal intensity of the component and 1 indicates maximal intensity of the component.
struct RGBf
{
    /// @brief The component type.
    using ComponentType = float;

    /// @brief Get if the colour space has RGB components.
    /// @return @a true if the colour space has RGB components, @a false otherwise
    static constexpr bool has_rgb() noexcept { return true; }

    /// @brief Get if the colour space has an A component.
    /// @return @a true if the colour space has an A component, @a false otherwise
    static constexpr bool has_a() noexcept { return false; }

    /// @brief Get if the colour space has a L component.
    /// @return @a true if the colour space has an L component, @a false otherwise
    static constexpr bool has_l() noexcept { return false; }

    /// @brief Get the number of components of a colour in the colour space.
    /// @return the number of components of a colour in the colour space
    static constexpr size_t count() noexcept { return 3; }

    /// @brief Get the minimum component value.
    /// @return the minimum component value
    static constexpr ComponentType min() noexcept { return 0.0f; }

    /// @brief Get the maximum component value.
    /// @return the maximum component value
    static constexpr ComponentType max() noexcept { return 1.0f; }

};

/// @brief The type of an RGBA colour space with floating-point components each within the range from 0 (inclusive) to 1 (inclusive).
/// A component value of 0 indicates minimal intensity of the component and 1 indicates maximal intensity of the component.
struct RGBAf
{
    /// @brief The component type.
    using ComponentType = float;

    /// @brief Get if the colour space has RGB components.
    /// @return @a true if the colour space has RGB components, @a false otherwise
    static constexpr bool has_rgb() noexcept { return true; }

    /// @brief Get if the colour space has an A component.
    /// @return @a true if the colour space has an A component, @a false otherwise
    static constexpr bool has_a() noexcept { return true; }

    /// @brief Get if the colour space has an L component.
    /// @return @a true if the colour space has an L component, @a false otherwise
    static constexpr bool has_l() noexcept { return false; }

    /// @brief Get the number of components of a colour in the colour space.
    /// @return the number of components of a colour in the colour space
    static constexpr size_t count() noexcept { return 4; }

    /// @brief Get the minimum component value.
    /// @return the minimum component value
    static constexpr ComponentType min() noexcept { return 0.0f; }

    /// @brief Get the maximum component value.
    /// @return the maximum component value
    static constexpr ComponentType max() noexcept { return 1.0f; }

};

/// @brief The type of an RGB colour space with unsigned integer components each within the range from 0 (inclusive) to 255 (inclusive).
/// A component value of 0 indicates minimal intensity of the component and 255 indicates maximal intensity of the component.
struct RGBb
{
    /// @brief The component type.
    using ComponentType = uint8_t;

    /// @brief Get if the colour space has RGB components.
    /// @return @a true if the colour space has RGB components, @a false otherwise
    static constexpr bool has_rgb() noexcept { return true; }

    /// @brief Get if the colour space has an A component.
    /// @return @a true if the colour space has an A component, @a false otherwise
    static constexpr bool has_a() noexcept { return false; }

    /// @brief Get if the colour space has an L component.
    /// @return @a true if the colour space has an L component, @a false otherwise
    static constexpr bool has_l() noexcept { return false; }

    /// @brief Get the number of components of a colour in the colour space.
    /// @return the number of components of a colour in the colour space
    static constexpr size_t count() noexcept { return 3; }

    /// @brief Get the minimum component value.
    /// @return the minimum component value
    static constexpr ComponentType min() noexcept { return 0; }

    /// @brief Get the maximum component value.
    /// @return the maximum component value
    static constexpr ComponentType max() noexcept { return 255; }
};

/// @brief The type of an RGBA colour space with unsigned integer components each within the range from 0 (inclusive) to 255 (inclusive).
/// A component value of 0 indicates minimal intensity of the component and 255 indicates maximal intensity of the component.
struct RGBAb
{
    /// @brief The component type.
    using ComponentType = uint8_t;

    /// @brief Get if the colour space has RGB components.
    /// @return @a true if the colour space has RGB components, @a false otherwise
    static constexpr bool has_rgb() noexcept { return true; }

    /// @brief Get if the colour space has an A component.
    /// @return @a true if the colour space has an A component, @a false otherwise
    static constexpr bool has_a() noexcept { return true; }

    /// @brief Get if the colour space has an L component.
    /// @return @a true if the colour space has an L component, @a false otherwise
    static constexpr bool has_l() noexcept { return false; }

    /// @brief Get the number of components in the colour space.
    /// @return the number of components of a colour in the colour space
    static constexpr size_t count() noexcept { return 4; }

    /// @brief Get the minimum component value.
    /// @return the minimum component value
    static constexpr ComponentType min() noexcept { return 0; }

    /// @brief Get the maximum component value.
    /// @return the maximum component value
    static constexpr ComponentType max() noexcept { return 255; }
};

/// @brief The type of an A colour space with floating-point components each within the range from 0 (inclusive) to 1 (inclusive).
/// A component value of 0 indicates minimal intensity of the component and 1 indicates maximal intensity of the component.
struct Af
{
    /// @brief The component type.
    using ComponentType = float;

    /// @brief Get if the colour space has RGB components.
    /// @return @a true if the colour space has RGB components, @a false otherwise
    static constexpr bool has_rgb() noexcept { return false; }

    /// @brief Get if the colour space has an A component.
    /// @return @a true if the colour space has an A component, @a false otherwise
    static constexpr bool has_a() noexcept { return true; }

    /// @brief Get if the colour space has a L component.
    /// @return @a true if the colour space has an L component, @a false otherwise
    static constexpr bool has_l() noexcept { return false; }

    /// @brief Get the number of components of a colour in the colour space.
    /// @return the number of components of a colour in the colour space
    static constexpr size_t count() noexcept { return 1; }

    /// @brief Get the minimum component value.
    /// @return the minimum component value
    static constexpr ComponentType min() noexcept { return 0.0f; }

    /// @brief Get the maximum component value.
    /// @return the maximum component value
    static constexpr ComponentType max() noexcept { return 1.0f; }
};

/// @brief The type of an A colour space with unsigned integer components each within the range from 0 (inclusive) to 255 (inclusive).
/// A component value of 0 indicates minimal intensity of the component and 255 indicates maximal intensity of the component.
struct Ab
{
    /// @brief The component type.
    using ComponentType = uint8_t;

    /// @brief Get if the colour space has RGB components.
    /// @return @a true if the colour space has RGB components, @a false otherwise
    static constexpr bool has_rgb() noexcept { return false; }

    /// @brief Get if the colour space has an A component.
    /// @return @a true if the colour space has an A component, @a false otherwise
    static constexpr bool has_a() noexcept { return true; }

    /// @brief Get if the colour space has a L component.
    /// @return @a true if the colour space has an L component, @a false otherwise
    static constexpr bool has_l() noexcept { return false; }

    /// @brief Get the number of components of a colour in the colour space.
    /// @return the number of components of a colour in the colour space
    static constexpr size_t count() noexcept { return 1; }

    /// @brief Get the minimum component value.
    /// @return the minimum component value
    static constexpr ComponentType min() noexcept { return 0; }

    /// @brief Get the maximum component value.
    /// @return the maximum component value
    static constexpr ComponentType max() noexcept { return 255; }
};

/**
 * @brief Get the type of the opaque color space of a specified color space.
 * @remark The opaque color space consists of all opaque colors of the specified color space.
 */
template <typename ColorSpace>
struct opaque;

template <>
struct opaque<RGBb> { using type = RGBb; };
template <>
struct opaque<RGBf> { using type = RGBf; };
template <>
struct opaque<Lb> { using type = Lb; };
template <>
struct opaque<Lf> { using type = Lf; };

template <>
struct opaque<RGBAb> { using type = RGBb; };
template <>
struct opaque<RGBAf> { using type = RGBf; };
template <>
struct opaque<LAb> { using type = Lb; };
template <>
struct opaque<LAf> { using type = Lf; };

template <typename ColorSpace>
using opaque_t = typename opaque<ColorSpace>::type;

namespace internal {

template <typename ColorSpace>
struct is_rgb
{
    static constexpr bool value = ColorSpace::has_rgb()
        && !ColorSpace::has_l()
        && !ColorSpace::has_a();
};

template <typename ColorSpace>
struct is_rgba
{
    static constexpr bool value = ColorSpace::has_rgb()
        && !ColorSpace::has_l()
        && ColorSpace::has_a();
};

template <typename ColorSpace>
struct is_l
{
    static constexpr bool value = !ColorSpace::has_rgb()
        && ColorSpace::has_l()
        && !ColorSpace::has_a();
};

template <typename ColorSpace>
struct IsLA
{
    static constexpr bool value = !ColorSpace::has_rgb()
        && ColorSpace::has_l()
        && ColorSpace::has_a();
};

template <typename ColorSpace>
struct IsA
{
    static constexpr bool value = !ColorSpace::has_rgb()
        && !ColorSpace::has_l()
        && ColorSpace::has_a();
};


} // namespace internal

} // namespace id
