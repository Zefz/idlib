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

/// @file idlib/color/rgb.hpp
/// @brief Colors in RGB color spaces.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/idlib.hpp` instead)
#endif

#include "idlib/color/color.hpp"
#include "idlib/crtp.hpp"
#include "idlib/math/interpolate.hpp"

namespace id {

/// @brief A color in RGB color space.
template <typename ColorSpace>
struct color<ColorSpace, std::enable_if_t<internal::is_rgb<ColorSpace>::value>> :
    public equal_to_expr<color<ColorSpace>>
{
public:
    using color_space = ColorSpace;
    using component = typename ColorSpace::ComponentType;
    using this_type = color<ColorSpace>;
    static_assert(internal::is_rgb<ColorSpace>::value, "not an RGB color space type");
    static_assert(color_space::has_rgb() && !color_space::has_a() && !color_space::has_l(), "not an RGB color space type");

private:
    /// @brief The red component value.
    /// @invariant Within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive).
    component r;

    /// @brief The green component value.
    /// @invariant Within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive).
    component g;

    /// @brief The blue component value.
    /// @invariant Within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive).
    component b;

    void assign(const this_type& other)
    {
        r = other.r;
        g = other.g;
        b = other.b;
    }

public:
    /// @brief The color "red" (255,0,0).
    /// @return the color "red"
    static const this_type& red()
    {
        static const this_type color(color<RGBb>(255, 0, 0));
        return color;
    }

    /// @brief The color "green" (0,255,0).
    /// @return the color "green"
    static const this_type& green()
    {
        static const this_type color(color<RGBb>(0, 255, 0));
        return color;
    }

    /// @brief The color "blue" (0,0,255).
    /// @return the color "blue"
    static const this_type& blue()
    {
        static const this_type color(color<RGBb>(0, 0, 255));
        return color;
    }

    /// @brief The color "white" (255,255,255).
    /// @return the color "white"
    static const this_type& white()
    {
        static const this_type color(color<RGBb>(255, 255, 255));
        return color;
    }

    /// @brief The color "black" (0,0,0).
    /// @return the color "black"
    static const this_type& black()
    {
        static const this_type color(color<RGBb>(0, 0, 0));
        return color;
    }

    /// @brief The color "cyan" (0,255,255).
    /// @return the color "cyan"
    /// @remark The color "cyan" is the complementary color of the color "red".
    static const this_type& cyan()
    {
        static const this_type color(color<RGBb>(0, 255, 255));
        return color;
    }

    /// @brief The color "magenta" (255,0,255).
    /// @return the color "magenta"
    /// @remark The color "magenta" is the complementary color of the color "green".
    static const this_type& magenta()
    {
        static const this_type color(color<RGBb>(255, 0, 255));
        return color;
    }

    /// @brief The color "yellow" (255,255,0).
    /// @return the color "yellow"
    /// @remark The color "yellow" is the complementary color of the color "blue".
    static const this_type& yellow()
    {
        static const this_type color(color<RGBb>(255, 255, 0));
        return color;
    }

    /// @brief The color "mauve" (224, 176, 255) [Maerz and Paul].
    /// @return the color "mauve".
    static const this_type& mauve()
    {
        static const this_type color(color<RGBb>(224, 176, 255));
        return color;
    }

    /// @brief The color "purple" (128, 0, 128).
    /// @return the color "purple".
    static const this_type& purple()
    {
        static const this_type color(color<RGBb>(128, 0, 128));
        return color;
    }

    /// @brief The color "grey" (75, 75, 75).
    /// @return the color "grey".
    static const this_type& grey()
    {
        static const this_type color(color<RGBb>(75, 75, 75));
        return color;
    }

public:
    /// @brief Default construct with component values corresponding to "opaque black".
    color() :
        r(color_space::min()), g(color_space::min()), b(color_space::min())
    {
        // Intentionally empty.
    }

    /// @brief Construct this color from the component values of a another color.
    /// @param other the other color
    template <typename OtherColorSpace,
        std::enable_if_t<std::is_same<OtherColorSpace, ColorSpace>::value, int *> = nullptr>
        color(const color<OtherColorSpace>& other) :
        r(other.getRed()), g(other.getGreen()), b(other.getBlue())
    {
        // Intentionally empty.
    }

    /// @brief Construct this color from the specified component values
    /// @param r the component value of the red component
    /// @param g the component value of the green component
    /// @param b the component value of the blue component
    /// @throws out_of_bounds_exception @a r, @a g, or @a b a are not within the range of color_space::min() (inclusive) and color_space::max() (inclusive)
    color(component r, component g, component b) :
        r(r), g(g), b(b)
    {
        if (r < color_space::min() || r > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "red component out of bounds");
        }
        if (g < color_space::min() || g > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "green component out of bounds");
        }
        if (b < color_space::min() || b > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "blue component out of bounds");
        }
    }

    // If RGBf to RGBb.
    template <typename OtherColorSpace,
        std::enable_if_t<std::is_same<ColorSpace, RGBb>::value &&
        std::is_same<OtherColorSpace, RGBf>::value, int *> = nullptr>
        color(const color<OtherColorSpace>& other) :
        r(internal::f2b(other.getRed())), g(internal::f2b(other.getGreen())), b(internal::f2b(other.getBlue()))
    {
        // Intentionally empty.
    }

    // If RGBb to RGBf.
    template <typename OtherColorSpace,
        std::enable_if_t<std::is_same<ColorSpace, RGBf>::value &&
        std::is_same<OtherColorSpace, RGBb>::value, int *> = nullptr>
        color(const color<OtherColorSpace>& other) :
        r(internal::b2f(other.getRed())), g(internal::b2f(other.getGreen())), b(internal::b2f(other.getBlue()))
    {
        // Intentionally empty.
    }

    // If Lb to RGBb.
    template <typename OtherColorSpace,
        std::enable_if_t<std::is_same<ColorSpace, RGBb>::value &&
        std::is_same<OtherColorSpace, Lb>::value, int *> = nullptr>
        color(const color<OtherColorSpace>& other) :
        r(other.getLuminance()), g(other.getLuminance()), b(other.getLuminance())
    {
        // Intentionally empty.
    }

    // If Lf to RGBf.
    template <typename OtherColorSpace,
        std::enable_if_t<std::is_same<ColorSpace, RGBf>::value &&
        std::is_same<OtherColorSpace, Lf>::value, int *> = nullptr>
        color(const color<OtherColorSpace>& other) :
        r(other.getLuminance()), g(other.getLuminance()), b(other.getLuminance())
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
    /// @brief Invert this color value.
    /// @return the inverted color
    /// @remark
    /// Given a color  \f$(r,g,b)\f$ in real-valued, normalized RGB space,
    /// then corresponding inverted color is \f$(1-r,1-g,1-b)\f$. Inverting
    /// a color twice yields the same color (modulo floating-point precision).
    /// @remark
    /// The corresponding inverted color is also known as the complementary color.
    this_type invert() const
    {
        return this_type(color_space::max() - this->getRed(),
                         color_space::max() - this->getGreen(),
                         color_space::max() - this->getBlue());
    }

public:
    // CRTP
    bool equal_to(const this_type& other) const
    {
        return this->getRed() == other.getRed()
            && this->getGreen() == other.getGreen()
            && this->getBlue() == other.getBlue();
    }

public:
    /// @brief Get the value of the red component.
    /// @return the value of the red component
    component getRed() const
    {
        return r;
    }

#if defined(ID_COLORS_SETTERS) && 1 == ID_COLORS_SETTERS
    /// @brief Set the value of the red component.
    /// @param r the value of the red component
    /// @throws out_of_bounds_exception @a r is not within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive)
    void setRed(component r)
    {
        if (r < color_space::min() || r > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "red component out of bounds");
        }
        this->r = r;
    }

#if defined(ID_COLOR_SHORT_SETTERS) && 1 == ID_COLOR_SHORT_SETTERS
    /// @brief Set the value of the red component.
    /// @param r the value of the red component
    /// @throws out_of_bounds_exception @a r is not within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive)
    void setR(component r)
    {
        if (r < color_space::min() || r > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "red component out of bounds");
        }
        this->r = r;
    }
#endif

#endif

    /// @brief Get the value of the green component.
    /// @return the value of the green component
    component getGreen() const
    {
        return g;
    }

#if defined(ID_COLORS_SETTERS) && 1 == ID_COLORS_SETTERS
    /// @brief Set the value of the green component.
    /// @param g the value of the green component
    /// @throws out_of_bounds_exception @a g is not within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive)
    void setGreen(component g)
    {
        if (g < color_space::min() || g > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "green component out of bounds");
        }
        this->g = g;
    }

#if defined(ID_COLOR_SHORT_SETTERS) && 1 == ID_COLOR_SHORT_SETTERS
    /// @brief Set the value of the green component.
    /// @param g the value of the green component
    /// @throws out_of_bounds_exception @a g is not within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive)
    void setG(component g)
    {
        if (g < color_space::min() || g > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "green component out of bounds");
        }
        this->g = g;
    }
#endif

#endif

    /// @brief Get the value of the blue component.
    /// @return the value of the blue component
    component getBlue() const
    {
        return b;
    }

#if defined(ID_COLORS_SETTERS) && 1 == ID_COLORS_SETTERS
    /// @brief Set the value of the blue component.
    /// @param b the value of the blue component
    /// @throws out_of_bounds_exception @a b is not within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive)
    void setBlue(component b)
    {
        if (b < color_space::min() || b > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "blue component out of bounds");
        }
        this->b = b;
    }

#if defined(ID_COLOR_SHORT_SETTERS) && 1 == ID_COLOR_SHORT_SETTERS
    /// @brief Set the value of the blue component.
    /// @param b the value of the blue component
    /// @throws out_of_bounds_exception @a b is not within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive)
    void setB(component b)
    {
        if (b < color_space::min() || b > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "blue component out of bounds");
        }
        this->b = b;
    }
#endif

#endif

}; // struct color


/// @brief Interpolation functor for id::color<id::RGBf> values.
template <typename ColorSpace>
struct interpolation_functor<color<ColorSpace>, interpolation_method::LINEAR,
    std::enable_if_t<std::is_same<RGBf, ColorSpace>::value>>
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
        return the_color(std::clamp(f(x.getRed(), y.getRed(), mu),
                                    the_color_space::min(),
                                    the_color_space::max()),
                         std::clamp(f(x.getGreen(), y.getGreen(), mu),
                                    the_color_space::min(),
                                    the_color_space::max()),
                         std::clamp(f(x.getBlue(), y.getBlue(), mu),
                                    the_color_space::min(),
                                    the_color_space::max()));
    }

}; // struct interpolate_functor

} // namespace id
