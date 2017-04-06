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

namespace Id {

/// @brief A color in RGBA color space.
template <typename ColourSpaceTypeArg>
struct Colour<ColourSpaceTypeArg, std::enable_if_t<Internal::IsRgba<ColourSpaceTypeArg>::value>> :
    public id::equal_to_expr<Colour<ColourSpaceTypeArg>>
{
public:
    using ColourSpaceType = ColourSpaceTypeArg;
    using ComponentType = typename ColourSpaceType::ComponentType;
    using MyType = Colour<ColourSpaceType>;
    static_assert(Id::Internal::IsRgba<ColourSpaceTypeArg>::value, "not an RGBA colour space type");
    static_assert(ColourSpaceTypeArg::hasRgb() && ColourSpaceTypeArg::hasA() && !ColourSpaceTypeArg::hasL(), "not an RGBA colour space type");

private:
    /// @brief The red component value.
    /// @invariant Within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive).
    ComponentType r;

    /// @brief The green component value.
    /// @invariant Within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive).
    ComponentType g;

    /// @brief The blue component value.
    /// @invariant Within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive).
    ComponentType b;

    /// @brief The blue component value.
    /// @invariant Within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive).
    ComponentType a;

    void assign(const MyType& other)
    {
        r = other.r;
        g = other.g;
        b = other.b;
        a = other.a;
    }

public:
    /// @brief The colour "red".
    /// @return the colour "red"
    /// @see Id::Colour<RGBb>::red()
    static const MyType& red()
    {
        static const MyType colour(Colour<Opaque<ColourSpaceType>>::red(),
                                   ColourSpaceType::max());
        return colour;
    }

    /// @brief The colour "green".
    /// @return the colour "green"
    /// @see Id::Colour<RGBb>::green()
    static const MyType& green()
    {
        static const MyType colour(Colour<Opaque<ColourSpaceType>>::green(),
                                   ColourSpaceType::max());
        return colour;
    }

    /// @brief The colour "blue".
    /// @return the colour "blue"
    /// @see Id::Colour<RGBb>::blue()
    static const MyType blue()
    {
        static const MyType colour(Colour<Opaque<ColourSpaceType>>::blue(),
                                   ColourSpaceType::max());
        return colour;
    }

    /// @brief The colour "white".
    /// @return the colour "white"
    /// @see Id::Colour<RGBb>::white()
    static const MyType white()
    {
        static const MyType colour(Colour<Opaque<ColourSpaceType>>::white(),
                                   ColourSpaceType::max());
        return colour;
    }

    /// @brief The colour "black".
    /// @return the colour "black"
    /// @see Id::Colour<RGBb>::black()
    static const MyType black()
    {
        static const MyType colour(Colour<Opaque<ColourSpaceType>>::black(),
                                   ColourSpaceType::max());
        return colour;
    }

    /// @brief The colour "cyan".
    /// @return the colour "cyan"
    /// @see Id::Colour<RGBb>::cyan()
    static const MyType cyan()
    {
        static const MyType colour(Colour<Opaque<ColourSpaceType>>::cyan(),
                                   ColourSpaceType::max());
        return colour;
    }

    /// @brief The colour "magenta".
    /// @return the colour "magenta"
    /// @see Id::Colour<RGBb>::magenta()
    static const MyType magenta()
    {
        static const MyType colour(Colour<Opaque<ColourSpaceType>>::magenta(),
                                   ColourSpaceType::max());
        return colour;
    }

    /// @brief The colour "yellow".
    /// @return the colour "yellow"
    /// @see Id::Colour<RGBb>::yellow()
    static const MyType yellow()
    {
        static const MyType colour(Colour<Opaque<ColourSpaceType>>::yellow(),
                                   ColourSpaceType::max());
        return colour;
    }

    /// @brief The colour "purple".
    /// @return the colour "purple"
    /// @see Id::Colour<RGBb>::purple()
    static const MyType purple()
    {
        static const MyType colour(Colour<Opaque<ColourSpaceType>>::purple(),
                                   ColourSpaceType::max());
        return colour;
    }

    /// @brief The colour "grey".
    /// @return the colour "grey"
    /// @see Id::Colour<RGBb>::grey()
    static const MyType grey()
    {
        static const MyType colour(Colour<Opaque<ColourSpaceType>>::grey(),
                                   ColourSpaceType::max());
        return colour;
    }

public:
    /// @brief Default construct with component values corresponding to "opaque black".
    Colour() :
        r(ColourSpaceType::min()), g(ColourSpaceType::min()), b(ColourSpaceType::min()),
        a(ColourSpaceType::max())
    {
        // Intentionally empty
    }

    /// @brief Construct this color from the component values of a another color.
    /// @param other the other color
    template <typename OtherColourSpaceTypeArg,
              std::enable_if_t<std::is_same<OtherColourSpaceTypeArg, ColourSpaceTypeArg>::value, int *> = nullptr>
    Colour(const Colour<OtherColourSpaceTypeArg>& other) :
        r(other.getRed()), g(other.getGreen()), b(other.getBlue()), a(other.getAlpha())
    {
        // Intentionally empty.
    }

    /// @brief Construct this color from the specified color of the corresponding opaque color space and the specified alpha component value.
    /// @param rgb the RGB color
    /// @param a the component value of the blue component
    /// @throws Id::OutOfBoundsException @a a is not within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive)
    Colour(const Colour<Opaque<ColourSpaceType>>& rgb, ComponentType a) :
        r(rgb.getRed()), g(rgb.getGreen()), b(rgb.getBlue()), 
        a(a)
    {
        /* r, g, b are known to be within in bounds. */
        if (a < ColourSpaceType::min() || a > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "alpha component out of bounds");
        }
    }

    /// @brief Construct this RGBAb color from the component values of an RGBAf color.
    /// @param other the other color
    template <typename OtherColourSpaceTypeArg,
              std::enable_if_t<std::is_same<ColourSpaceTypeArg, RGBAb>::value &&
              std::is_same<OtherColourSpaceTypeArg, RGBAf>::value, int *> = nullptr>
    Colour(const Colour<OtherColourSpaceTypeArg>& other) :
        r(Internal::f2b(other.getRed())),
        g(Internal::f2b(other.getGreen())),
        b(Internal::f2b(other.getBlue())),
        a(Internal::f2b(other.getAlpha()))
    {
        // Intentionally empty.
    }

    /// @brief Construct this RGBAf color from the component values of an RGBAb color.
    /// @param other the other color
    template <typename OtherColourSpaceTypeArg,
              std::enable_if_t<std::is_same<ColourSpaceTypeArg, RGBAf>::value &&
              std::is_same<OtherColourSpaceTypeArg, RGBAb>::value, int *> = nullptr>
    Colour(const Colour<OtherColourSpaceTypeArg>& other) :
        r(Internal::b2f(other.getRed())),
        g(Internal::b2f(other.getGreen())),
        b(Internal::b2f(other.getBlue())),
        a(Internal::b2f(other.getAlpha()))
    {
        // Intentionally empty.
    }

    /// @brief Construct this RGBAf color from the component values of an LAf color.
    /// @param other the other color
    template <typename OtherColourSpaceTypeArg,
              std::enable_if_t<std::is_same<ColourSpaceTypeArg, RGBAf>::value &&
              std::is_same<OtherColourSpaceTypeArg, LAf>::value, int *> = nullptr>
    Colour(const Colour<OtherColourSpaceTypeArg>& other) :
        r(other.getLuminance()), g(other.getLuminance()), b(other.getLuminance()), a(other.getAlpha())
    {
        // Intentionally empty.
    }

    /// @brief Construct this RGBAb color from the component values of an LAb color.
    /// @param other the other color
    template <typename OtherColourSpaceTypeArg,
              std::enable_if_t<std::is_same<ColourSpaceTypeArg, RGBAb>::value &&
              std::is_same<OtherColourSpaceTypeArg, LAb>::value, int *> = nullptr>
    Colour(const Colour<OtherColourSpaceTypeArg>& other) :
        r(other.getLuminance()), g(other.getLuminance()), b(other.getLuminance()), a(other.getAlpha())
    {
        // Intentionally empty.
    }

    /// @brief Construct this colour from the specified component values.
    /// @param r the component value of the red component
    /// @param g the component value of the green component
    /// @param b the component value of the blue component
    /// @param a the component value of the alpha component
    /// @throws Id::OutOfBoundsException @a a, @a g, @a b or @a a are not within the range of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive)
    Colour(ComponentType r, ComponentType g, ComponentType b, ComponentType a) :
        r(r), g(g), b(b), a(a)
    {
        if (r < ColourSpaceType::min() || r > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "red component out of bounds");
        }
        if (g < ColourSpaceType::min() || g > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "green component out of bounds");
        }
        if (b < ColourSpaceType::min() || b > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "blue component out of bounds");
        }
        if (a < ColourSpaceType::min() || a > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "alpha component out of bounds");
        }
    }

public:
    /// @brief Assign this colour from another colour.
    /// @param other the other colour
    /// @return this colour
    const MyType& operator=(const MyType& other)
    {
        this->assign(other);
        return *this;
    }

    /// @brief Invert this colour value.
    /// @return the inverted colour
    /// @remark
    /// Given a colour  \f$(r,g,b,a)\f$ in real-valued, normalized RGBA space,
    /// then corresponding inverted colour is \f$(1-r,1-g,1-b,a)\f$. Inverting
    /// a colour twice yields the same colour (modula floating-point precision).
    /// @remark
    /// The corresponding inverted colour is also known as the complementary colour.
    MyType invert() const
    {
        return MyType(ColourSpaceType::max() - this->getRed(),
                      ColourSpaceType::max() - this->getGreen(),
                      ColourSpaceType::max() - this->getBlue(),
                      this->getAlpha());
    }

    /**
     * @brief
     *  Make a brighter version of this colour
     * @param brightness
     *  the scalar for brightness increase (0 = normal, 1 = twice as bright)
     * @return
     *  the brighter colour
     * @remark
     *  Given a colour  \f$(r,g,b,a)\f$ in real-valued, normalized RGBA space,
     *  then corresponding inverted colour is \f$(brighness*r,brighness*1,brighness*1,a)\f$. This conversion
     *  is not reverrsible.
     */
    MyType brighter(float brightness) const
    {
        if (brightness <= 0.0f) return *this;
        brightness += 1.0f;
        return MyType(std::min(ColourSpaceType::max(), this->getRed()*brightness),
                      std::min(ColourSpaceType::max(), this->getGreen()*brightness),
                      std::min(ColourSpaceType::max(), this->getBlue()*brightness),
                      this->getAlpha());
    }

public:
    // CRTP
    bool equal_to(const MyType& other) const
    {
        return this->getRed() == other.getRed()
            && this->getGreen() == other.getGreen()
            && this->getBlue() == other.getBlue()
            && this->getAlpha() == other.getAlpha();
    }

public:
    /// @brief Get the value of the red component.
    /// @return the value of the red component
    ComponentType getRed() const
    {
        return r;
    }

#if defined(ID_COLOR_SHORT_GETTERS) && 1 == ID_COLOR_SHORT_GETTERS
    /// @brief Get the value of the red component.
    /// @return the value of the red component
    ComponentType getR() const
    {
        return r;
    }
#endif

#if defined(ID_COLOR_SETTERS) && 1 == ID_COLOR_SETTERS
    /// @brief Set the value of the red component.
    /// @param r the value of the red component
    /// @throws OutOfBoundsException @a r is not within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive)
    void setRed(ComponentType r)
    {
        if (r < ColourSpaceType::min() || r > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "red component out of bounds");
        }
        this->r = r;
    }

#if defined(ID_COLOR_SHORT_SETTERS) && 1 == ID_COLOR_SHORT_SETTERS
    /// @brief Set the value of the red component.
    /// @param r the value of the red component
    /// @throws OutOfBoundsException @a r is not within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive)
    void setR(ComponentType r)
    {
        if (r < ColourSpaceType::min() || r > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "red component out of bounds");
        }
        this->r = r;
    }
#endif

#endif

    /// @brief Get the value of the green component.
    /// @return the value of the green component
    ComponentType getGreen() const
    {
        return g;
    }

#if defined(ID_COLOR_SHORT_GETTERS) && 1 == ID_COLOR_SHORT_GETTERS
    /// @brief Get the value of the green component.
    /// @return the value of the green component
    ComponentType getG() const
    {
        return g;
    }
#endif

#if defined(ID_COLOR_SETTERS) && 1 == ID_COLOR_SETTERS
    /// @brief Set the value of the green component.
    /// @param g the value of the green component
    /// @throws OutOfBoundsException @a g is not within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive)
    void setGreen(ComponentType g)
    {
        if (g < ColourSpaceType::min() || g > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "green component out of bounds");
        }
        this->g = g;
    }

#if defined(ID_COLOR_SHORT_SETTERS) && 1 == ID_COLOR_SHORT_SETTERS
    /// @brief Set the value of the green component.
    /// @param g the value of the green component
    /// @throws OutOfBoundsException @a g is not within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive)
    void setG(ComponentType g)
    {
        if (g < ColourSpaceType::min() || g > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "green component out of bounds");
        }
        this->g = g;
    }
#endif

#endif

    /// @brief Get the value of the blue component.
    /// @return the value of the blue component
    ComponentType getBlue() const
    {
        return b;
    }

#if defined(ID_COLOR_SHORT_GETTERS) && 1 == ID_COLOR_SHORT_GETTERS
    /// @brief Get the value of the blue component.
    /// @return the value of the blue component
    ComponentType getB() const
    {
        return b;
    }
#endif

#if defined(ID_COLOR_SETTERS) && 1 == ID_COLOR_SETTERS
    /// @brief Set the value of the blue component.
    /// @param b the value of the blue component
    /// @throws OutOfBoundsException @a b is not within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive)
    void setBlue(ComponentType b)
    {
        if (b < ColourSpaceType::min() || b > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "blue component out of bounds");
        }
        this->b = b;
    }

#if defined(ID_COLOR_SHORT_SETTERS) && 1 == ID_COLOR_SHORT_SETTERS
    /// @brief Set the value of the blue component.
    /// @param b the value of the blue component
    /// @throws OutOfBoundsException @a b is not within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive)
    void setB(ComponentType b)
    {
        if (b < ColourSpaceType::min() || b > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "blue component out of bounds");
        }
        this->b = b;
    }
#endif

#endif

    /// @brief Get the value of the alpha component.
    /// @return the value of the alpha component
    ComponentType getAlpha() const
    {
        return a;
    }

#if defined(ID_COLOR_SHORT_GETTERS) && 1 == ID_COLOR_SHORT_GETTERS
    /// @brief Get the value of the alpha component.
    /// @return the value of the alpha component
    ComponentType getA() const
    {
        return a;
    }
#endif

#if defined(ID_COLOR_SETTERS) && 1 == ID_COLOR_SETTERS
    /// @brief Set the value of the alpha component.
    /// @param a the value of the alpha component
    /// @throws OutOfBoundsException @a a is not within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive)
    void setAlpha(const ComponentType a)
    {
        if (a < ColourSpaceType::min() || a > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "alpha component out of bounds");
        }
        this->a = a;
    }

#if defined(ID_COLOR_SHORT_SETTERS) && 1 == ID_COLOR_SHORT_SETTERS
    /// @brief Set the value of the alpha component.
    /// @param a the value of the alpha component
    /// @throws OutOfBoundsException @a a is not within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive)
    void setA(const ComponentType a)
    {
        if (a < ColourSpaceType::min() || a > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "alpha component out of bounds");
        }
        this->a = a;
    }
#endif

#endif
};

} // namespace Id
