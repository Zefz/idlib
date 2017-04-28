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

/// @file idlib/color/l.hpp
/// @brief Colors in L color spaces.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/idlib.hpp` instead)
#endif

#include "idlib/color/color.hpp"
#include "idlib/crtp.hpp"

namespace id {

/// @brief A color in L color space.
template <typename ColorSpace>
struct color<ColorSpace, std::enable_if_t<internal::is_l<ColorSpace>::value>> :
    public equal_to_expr<color<ColorSpace>>
{
public:
    using color_space = ColorSpace;
    using component = typename ColorSpace::ComponentType;
    using this_type = color<ColorSpace>;
    static_assert(internal::is_l<color_space>::value, "not an L color space type");
    static_assert(ColorSpace::has_l() && !ColorSpace::has_rgb() && !ColorSpace::has_a(), "not an L color space type");

private:
    /// @brief The luminance component value.
    /// @invariant Within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive).
    component l;

    void assign(const this_type& other)
    {
        l = other.l;
    }

public:
    /// @brief Default construct with component values corresponding to "opaque black".
    color() :
        l(color_space::min())
    {
        // Intentionally empty.
    }

    /// @brief Construct this color with the specified luminance component color.
    /// @param l the component value of the luminance component
    /// @throws out_of_bounds_exception @a l is not within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive)
    color(component l) :
        l(l)
    {
        if (l < color_space::min() || l > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "luminance component out of bounds");
        }
    }

    /// @brief Copy construct this color with the component values of another color.
    /// @param other the other color
    template <typename OtherColorSpace,
        std::enable_if_t<std::is_same<OtherColorSpace, ColorSpace>::value, int *> = nullptr>
        color(const color<OtherColorSpace>& other) :
        l(other.getLuminance())
    {
        // Intentionally empty.
    }

    /// @brief Construct this Lb color with the component values of an Lf color.
    /// @param other the Lf color
    template <typename OtherColorSpace,
        std::enable_if_t<std::is_same<ColorSpace, RGBb>::value &&
        std::is_same<OtherColorSpace, Lf>::value, int *> = nullptr>
        color(const color<OtherColorSpace>& other) :
        l(internal::f2b(other.getLuminance()))
    {
        // Intentionally empty.
    }

    /// @brief Construct this Lf color with the component values of an Lb color.
    /// @param other the Lb color
    template <typename OtherColorSpace,
        std::enable_if_t<std::is_same<ColorSpace, Lf>::value &&
        std::is_same<OtherColorSpace, Lb>::value, int *> = nullptr>
        color(const color<OtherColorSpace>& other) :
        l(internal::b2f(other.getLuminance()))
    {
        // Intentionally empty.
    }

public:
    /// @brief Assign this color from another color.
    /// @param other the other color
    /// @return this color
    const this_type& operator=(const this_type& other)
    {
        this->assign(other);
        return *this;
    }

public:
    // CRTP
    bool equal_to(const this_type& other) const
    {
        return this->getLuminance() == other.getLuminance();
    }

public:
    /// @brief Get the value of the luminance component.
    /// @return the value of the luminance component
    component getLuminance() const
    {
        return l;
    }

#if defined(ID_COLOR_SHORT_GETTERS) && 1 == ID_COLOR_SHORT_GETTERS
    /// @brief Get the value of the luminance component.
    /// @return the value of the luminance component
    component getL() const
    {
        return l;
    }
#endif

#if defined(ID_COLOR_SETTERS) && 1 == ID_COLOR_SETTERS
    /// @brief Set the value of the luminance component.
    /// @param l the value of the luminance component
    /// @throws out_of_bounds_exception @a l is not within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive)
    void setLuminance(component l)
    {
        if (l < color_space::min() || l > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "luminance component out of bounds");
        }
        this->l = l;
    }

#if defined(ID_COLOR_SHORT_SETTERS) && 1 == ID_COLOR_SHORT_SETTERS
    /// @brief Set the value of the luminance component.
    /// @param l the value of the luminance component
    /// @throws out_of_bounds_exception @a l is not within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive)
    void setL(component l)
    {
        if (l < color_space::min() || l > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "luminance component out of bounds");
        }
        this->l = l;
    }
#endif

#endif

}; // struct color

} // namespace id
