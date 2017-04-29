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

/// @file idlib/color/la.hpp
/// @brief Colors in LA color spaces.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/idlib.hpp` instead)
#endif

#include "idlib/color/color.hpp"
#include "idlib/crtp.hpp"
#include "idlib/math/interpolate.hpp"

namespace id {

/// @brief A color in LA color space.
template <typename ColorSpace>
struct color<ColorSpace, std::enable_if_t<internal::IsLA<ColorSpace>::value>> :
    public equal_to_expr<color<ColorSpace>>
{
public:
    using color_space = ColorSpace;
    using component = typename ColorSpace::ComponentType;
    using this_type = color<ColorSpace>;

private:
    /// @brief The luminance component value.
    /// @invariant Within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive).
    component l;

    /// @brief The alpha component value.
    /// @invariant Within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive).
    component a;

    void assign(const this_type& other)
    {
        l = other.l;
        a = other.a;
    }

public:
    /// @brief The color "black" (0,0,0).
    /// @return the color "black"
    static const this_type& black()
    {
        static const this_type color(color<opaque_t<color_space>>(0),
                                     color_space::max());
        return color;
    }

    /// @brief The color "grey" (75,75,75).
    /// @return the color "grey".
    static const this_type& grey()
    {
        static const this_type color(color<opaque_t<color_space>>(75),
                                     color_space::max());
        return color;
    }

    /// @brief The color "white" (255,255,255).
    /// @return the color "white"
    static const this_type& white()
    {
        static const this_type color(color<opaque_t<color_space>>(255),
                                     color_space::max());
        return color;
    }

public:
    /// @brief Default construct with component values corresponding to "opaque black".
    color() :
        l(color_space::min()), a(color_space::max())
    {
        // Intentionally empty.
    }

    /// @brief Construct this color with the values of another color.
    /// @param other the other color
    template <typename OtherColorSpace,
        std::enable_if_t<std::is_same<OtherColorSpace, ColorSpace>::value, int *> = 0>
        color(const color<OtherColorSpace>& other) :
        l(other.getLuminance()), a(other.getAlpha())
    {
        // Intentionally empty.
    }

    /// @brief Construct this color with the specified luminance and alpha component values.
    /// @param l the component value of the luminance component
    /// @param a the component value of the alpha component
    /// @throws out_of_bounds_exception @a l or @a a are not within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive)
    color(component l, component a) :
        l(l), a(a)
    {
        if (l < color_space::min() || l > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "luminance component out of bounds");
        }
        if (a < color_space::min() || a > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "alpha component out of bounds");
        }
    }

    /// @brief Construct this color from the specified color of the corresponding opaque color space and the specified alpha component value.
    /// @param l the L color
    /// @param a the component value of the blue component
    /// @throws out_of_bounds_exception @a a is not within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive)
    color(const color<opaque_t<ColorSpace>>& l, component a)
        : l(l.getLuminance()), a(a)
    {
        /* l is known to be within bounds. */
        if (a < color_space::min() || a > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "alpha component out of bounds");
        }
    }

    // If LAf to LAb.
    template <typename OtherColorSpace,
        std::enable_if_t<std::is_same<ColorSpace, LAb>::value &&
        std::is_same<OtherColorSpace, LAf>::value, int *> = 0>
        color(const color<OtherColorSpace>& other) :
        l(internal::b2f(other.getLuminance())), a(f2b(other.getAlpha()))
    {
        // Intentionally empty.
    }

    // If LAb to LAf.
    template <typename OtherColorSpace,
        std::enable_if_t<std::is_same<ColorSpace, LAf>::value &&
        std::is_same<OtherColorSpace, LAb>::value, int *> = 0>
        color(const color<OtherColorSpace>& other) :
        l(internal::b2f(other.getLuminance())), a(internal::b2f(other.getAlpha()))
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
        return this->getLuminance() == other.getLuminance()
            && this->getAlpha() == other.getAlpha();
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

    /// @brief Get the value of the alpha component.
    /// @return the value of the alpha component
    component getAlpha() const
    {
        return a;
    }

#if defined(ID_COLOR_SHORT_GETTERS) && 1 == ID_COLOR_SHORT_GETTERS
    /// @brief Get the value of the alpha component.
    /// @return the value of the alpha component
    component getA() const
    {
        return a;
    }
#endif

#if defined(ID_COLOR_SETTERS) && 1 == ID_COLOR_SETTERS
    /// @brief Set the value of the alpha component.
    /// @param a the value of the alpha component
    /// @throws out_of_bounds_exception @a a is not within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive)
    void setAlpha(const component a)
    {
        if (a < color_space::min() || a > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "alpha component out of bounds");
        }
        this->a = a;
    }
#if defined(ID_COLOR_SHORT_SETTERS) && 1 == ID_COLOR_SHORT_SETTERS
    /// @brief Set the value of the alpha component.
    /// @param a the value of the alpha component
    /// @throws out_of_bounds_exception @a a is not within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive)
    void setA(const component a)
    {
        if (a < color_space::min() || a > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "alpha component out of bounds");
        }
        this->a = a;
    }
#endif
#endif

}; // struct color

/// @brief Interpolation functor for id::color<id::LAf> values.
template <typename ColorSpace>
struct interpolation_functor<color<ColorSpace>, interpolation_method::LINEAR,
    std::enable_if_t<std::is_same<LAf, ColorSpace>::value>>
{
    using the_color_space = ColorSpace;
    using the_color = color<the_color_space>;
    using the_component_interpolation_functor = interpolation_functor<float, interpolation_method::LINEAR>;

    the_color operator()(const the_color& x, const the_color& y, float t) const
    {
        return (*this)(x, y, mu<float>(t));
    }

    the_color operator()(const the_color& x, const the_color& y, const mu<float>& mu) const
    {
        static const the_component_interpolation_functor f{};
        return the_color(std::clamp(f(x.getLuminance(), y.getLuminance(), mu),
                                    the_color_space::min(),
                                    the_color_space::max()),
                         std::clamp(f(x.getAlpha(), y.getAlpha(), mu),
                                    the_color_space::min(),
                                    the_color_space::max()));
    }

}; // struct interpolate_functor

} // namespace id
