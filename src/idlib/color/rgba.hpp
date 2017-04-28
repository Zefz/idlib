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

/// @file idlib/color/rgba.hpp
/// @brief Colors in RGBA color spaces.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/idlib.hpp` instead)
#endif

#include "idlib/color/color.hpp"
#include "idlib/crtp.hpp"

namespace id {

/// @brief A color in RGBA color space.
template <typename ColorSpace>
struct color<ColorSpace, std::enable_if_t<internal::is_rgba<ColorSpace>::value>> :
    public equal_to_expr<color<ColorSpace>>
{
public:
    using color_space = ColorSpace;
    using component = typename color_space::ComponentType;
    using this_type = color<color_space>;
    static_assert(internal::is_rgba<ColorSpace>::value, "not an RGBA color space type");
    static_assert(color_space::has_rgb() && color_space::has_a() && !color_space::has_l(), "not an RGBA color space type");

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

    /// @brief The blue component value.
    /// @invariant Within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive).
    component a;

    void assign(const this_type& other)
    {
        r = other.r;
        g = other.g;
        b = other.b;
        a = other.a;
    }

public:
    /// @brief The color "red".
    /// @return the color "red"
    /// @see color<RGBb>::red()
    static const this_type& red()
    {
        static const this_type color(color<opaque_t<color_space>>::red(),
                                     color_space::max());
        return color;
    }

    /// @brief The color "green".
    /// @return the color "green"
    /// @see color<RGBb>::green()
    static const this_type& green()
    {
        static const this_type color(color<opaque_t<color_space>>::green(),
                                     color_space::max());
        return color;
    }

    /// @brief The color "blue".
    /// @return the color "blue"
    /// @see color<RGBb>::blue()
    static const this_type blue()
    {
        static const this_type color(color<opaque_t<color_space>>::blue(),
                                     color_space::max());
        return color;
    }

    /// @brief The color "white".
    /// @return the color "white"
    /// @see color<RGBb>::white()
    static const this_type white()
    {
        static const this_type color(color<opaque_t<color_space>>::white(),
                                     color_space::max());
        return color;
    }

    /// @brief The color "black".
    /// @return the color "black"
    /// @see color<RGBb>::black()
    static const this_type black()
    {
        static const this_type color(color<opaque_t<color_space>>::black(),
                                     color_space::max());
        return color;
    }

    /// @brief The color "cyan".
    /// @return the color "cyan"
    /// @see color<RGBb>::cyan()
    static const this_type cyan()
    {
        static const this_type color(color<opaque_t<color_space>>::cyan(),
                                     color_space::max());
        return color;
    }

    /// @brief The color "magenta".
    /// @return the color "magenta"
    /// @see color<RGBb>::magenta()
    static const this_type magenta()
    {
        static const this_type color(color<opaque_t<color_space>>::magenta(),
                                     color_space::max());
        return color;
    }

    /// @brief The color "yellow".
    /// @return the color "yellow"
    /// @see color<RGBb>::yellow()
    static const this_type yellow()
    {
        static const this_type color(color<opaque_t<color_space>>::yellow(),
                                     color_space::max());
        return color;
    }

    /// @brief The color "purple".
    /// @return the color "purple"
    /// @see color<RGBb>::purple()
    static const this_type purple()
    {
        static const this_type color(color<opaque_t<color_space>>::purple(),
                                     color_space::max());
        return color;
    }

    /// @brief The color "grey".
    /// @return the color "grey"
    /// @see color<RGBb>::grey()
    static const this_type grey()
    {
        static const this_type color(color<opaque_t<color_space>>::grey(),
                                     color_space::max());
        return color;
    }

public:
    /// @brief Default construct with component values corresponding to "opaque black".
    color() :
        r(color_space::min()), g(color_space::min()), b(color_space::min()),
        a(color_space::max())
    {
        // Intentionally empty
    }

    /// @brief Construct this color from the component values of a another color.
    /// @param other the other color
    template <typename OtherColorSpace,
        std::enable_if_t<std::is_same<OtherColorSpace, ColorSpace>::value, int *> = nullptr>
    color(const color<OtherColorSpace>& other) :
        r(other.getRed()), g(other.getGreen()), b(other.getBlue()), a(other.getAlpha())
    {
        // Intentionally empty.
    }

    /// @brief Construct this color from the specified color of the corresponding opaque color space and the specified alpha component value.
    /// @param rgb the RGB color
    /// @param a the component value of the blue component
    /// @throws out_of_bounds_exception @a a is not within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive)
    color(const color<opaque_t<color_space>>& rgb, component a) :
        r(rgb.getRed()), g(rgb.getGreen()), b(rgb.getBlue()),
        a(a)
    {
        /* r, g, b are known to be within in bounds. */
        if (a < color_space::min() || a > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "alpha component out of bounds");
        }
    }

    /// @brief Construct this RGBAb color from the component values of an RGBAf color.
    /// @param other the other color
    template <typename OtherColorSpace,
        std::enable_if_t<std::is_same<ColorSpace, RGBAb>::value &&
        std::is_same<OtherColorSpace, RGBAf>::value, int *> = nullptr>
    color(const color<OtherColorSpace>& other) :
        r(internal::f2b(other.getRed())),
        g(internal::f2b(other.getGreen())),
        b(internal::f2b(other.getBlue())),
        a(internal::f2b(other.getAlpha()))
    {
        // Intentionally empty.
    }

    /// @brief Construct this RGBAf color from the component values of an RGBAb color.
    /// @param other the other color
    template <typename OtherColorSpace,
        std::enable_if_t<std::is_same<ColorSpace, RGBAf>::value &&
        std::is_same<OtherColorSpace, RGBAb>::value, int *> = nullptr>
    color(const color<OtherColorSpace>& other) :
        r(internal::b2f(other.getRed())),
        g(internal::b2f(other.getGreen())),
        b(internal::b2f(other.getBlue())),
        a(internal::b2f(other.getAlpha()))
    {
        // Intentionally empty.
    }

    /// @brief Construct this RGBAf color from the component values of an LAf color.
    /// @param other the other color
    template <typename OtherColorSpace,
        std::enable_if_t<std::is_same<ColorSpace, RGBAf>::value &&
        std::is_same<OtherColorSpace, LAf>::value, int *> = nullptr>
        color(const color<OtherColorSpace>& other) :
        r(other.getLuminance()), g(other.getLuminance()), b(other.getLuminance()), a(other.getAlpha())
    {
        // Intentionally empty.
    }

    /// @brief Construct this RGBAb color from the component values of an LAb color.
    /// @param other the other color
    template <typename OtherColorSpace,
        std::enable_if_t<std::is_same<ColorSpace, RGBAb>::value &&
        std::is_same<OtherColorSpace, LAb>::value, int *> = nullptr>
        color(const color<OtherColorSpace>& other) :
        r(other.getLuminance()), g(other.getLuminance()), b(other.getLuminance()), a(other.getAlpha())
    {
        // Intentionally empty.
    }

    /// @brief Construct this color from the specified component values.
    /// @param r the component value of the red component
    /// @param g the component value of the green component
    /// @param b the component value of the blue component
    /// @param a the component value of the alpha component
    /// @throws out_of_bounds_exception @a a, @a g, @a b or @a a are not within the range of color_space::min() (inclusive) and color_space::max() (inclusive)
    color(component r, component g, component b, component a) :
        r(r), g(g), b(b), a(a)
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
        if (a < color_space::min() || a > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "alpha component out of bounds");
        }
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

    /// @brief Invert this color value.
    /// @return the inverted color
    /// @remark
    /// Given a color  \f$(r,g,b,a)\f$ in real-valued, normalized RGBA space,
    /// then corresponding inverted color is \f$(1-r,1-g,1-b,a)\f$. Inverting
    /// a color twice yields the same color (modula floating-point precision).
    /// @remark
    /// The corresponding inverted color is also known as the complementary color.
    this_type invert() const
    {
        return this_type(color_space::max() - this->getRed(),
                         color_space::max() - this->getGreen(),
                         color_space::max() - this->getBlue(),
                         this->getAlpha());
    }

    /**
     * @brief
     *  Make a brighter version of this color
     * @param brightness
     *  the scalar for brightness increase (0 = normal, 1 = twice as bright)
     * @return
     *  the brighter color
     * @remark
     *  Given a color  \f$(r,g,b,a)\f$ in real-valued, normalized RGBA space,
     *  then corresponding inverted color is \f$(brighness*r,brighness*1,brighness*1,a)\f$. This conversion
     *  is not reverrsible.
     */
    this_type brighter(float brightness) const
    {
        if (brightness <= 0.0f) return *this;
        brightness += 1.0f;
        return this_type(std::min(color_space::max(), this->getRed()*brightness),
                         std::min(color_space::max(), this->getGreen()*brightness),
                         std::min(color_space::max(), this->getBlue()*brightness),
                         this->getAlpha());
    }

public:
    // CRTP
    bool equal_to(const this_type& other) const
    {
        return this->getRed() == other.getRed()
            && this->getGreen() == other.getGreen()
            && this->getBlue() == other.getBlue()
            && this->getAlpha() == other.getAlpha();
    }

public:
    /// @brief Get the value of the red component.
    /// @return the value of the red component
    component getRed() const
    {
        return r;
    }

#if defined(ID_COLOR_SHORT_GETTERS) && 1 == ID_COLOR_SHORT_GETTERS
    /// @brief Get the value of the red component.
    /// @return the value of the red component
    component getR() const
    {
        return r;
    }
#endif

#if defined(ID_COLOR_SETTERS) && 1 == ID_COLOR_SETTERS
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

#if defined(ID_COLOR_SHORT_GETTERS) && 1 == ID_COLOR_SHORT_GETTERS
    /// @brief Get the value of the green component.
    /// @return the value of the green component
    component getG() const
    {
        return g;
    }
#endif

#if defined(ID_COLOR_SETTERS) && 1 == ID_COLOR_SETTERS
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

#if defined(ID_COLOR_SHORT_GETTERS) && 1 == ID_COLOR_SHORT_GETTERS
    /// @brief Get the value of the blue component.
    /// @return the value of the blue component
    component getB() const
    {
        return b;
    }
#endif

#if defined(ID_COLOR_SETTERS) && 1 == ID_COLOR_SETTERS
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

} // namespace id
