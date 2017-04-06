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

namespace Id {

/// @brief A color in RGB color space.
template <typename ColourSpaceTypeArg>
struct Colour<ColourSpaceTypeArg, std::enable_if_t<Internal::IsRgb<ColourSpaceTypeArg>::value>> :
    public id::equal_to_expr<Colour<ColourSpaceTypeArg>>
{
public:
    using ColourSpaceType = ColourSpaceTypeArg;
    using ComponentType = typename ColourSpaceType::ComponentType;
    using MyType = Colour<ColourSpaceType>;
    static_assert(Id::Internal::IsRgb<ColourSpaceTypeArg>::value, "not an RGB colour space type");
    static_assert(ColourSpaceTypeArg::hasRgb() && !ColourSpaceTypeArg::hasA() && !ColourSpaceTypeArg::hasL(), "not an RGB colour space type");

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

    void assign(const MyType& other)
    {
        r = other.r;
        g = other.g;
        b = other.b;
    }

public:
    /// @brief The colour "red" (255,0,0).
    /// @return the colour "red"
    static const MyType& red()
    {
        static const MyType colour(Colour<RGBb>(255, 0, 0));
        return colour;
    }

    /// @brief The colour "green" (0,255,0).
    /// @return the colour "green"
    static const MyType& green()
    {
        static const MyType colour(Colour<RGBb>(0, 255, 0));
        return colour;
    }

    /// @brief The colour "blue" (0,0,255).
    /// @return the colour "blue"
    static const MyType& blue()
    {
        static const MyType colour(Colour<RGBb>(0, 0, 255));
        return colour;
    }

    /// @brief The colour "white" (255,255,255).
    /// @return the colour "white"
    static const MyType& white()
    {
        static const MyType colour(Colour<RGBb>(255, 255, 255));
        return colour;
    }

    /// @brief The colour "black" (0,0,0).
    /// @return the colour "black"
    static const MyType& black()
    {
        static const MyType colour(Colour<RGBb>(0, 0, 0));
        return colour;
    }

    /// @brief The colour "cyan" (0,255,255).
    /// @return the colour "cyan"
    /// @remark The colour "cyan" is the complementary colour of the colour "red".
    static const MyType& cyan()
    {
        static const MyType colour(Colour<RGBb>(0, 255, 255));
        return colour;
    }

    /// @brief The colour "magenta" (255,0,255).
    /// @return the colour "magenta"
    /// @remark The colour "magenta" is the complementary colour of the colour "green".
    static const MyType& magenta()
    {
        static const MyType colour(Colour<RGBb>(255, 0, 255));
        return colour;
    }

    /// @brief The colour "yellow" (255,255,0).
    /// @return the colour "yellow"
    /// @remark The colour "yellow" is the complementary colour of the colour "blue".
    static const MyType& yellow()
    {
        static const MyType colour(Colour<RGBb>(255, 255, 0));
        return colour;
    }

    /// @brief The colour "mauve" (224, 176, 255) [Maerz and Paul].
    /// @return the colour "mauve".
    static const MyType& mauve()
    {
        static const MyType colour(Colour<RGBb>(224, 176, 255));
        return colour;
    }

    /// @brief The colour "purple" (128, 0, 128).
    /// @return the colour "purple".
    static const MyType& purple()
    {
        static const MyType colour(Colour<RGBb>(128, 0, 128));
        return colour;
    }

    /// @brief The colour "grey" (75, 75, 75).
    /// @return the colour "grey".
    static const MyType& grey()
    {
        static const MyType colour(Colour<RGBb>(75, 75, 75));
        return colour;
    }

public:
    /// @brief Default construct with component values corresponding to "opaque black".
    Colour() :
        r(ColourSpaceType::min()), g(ColourSpaceType::min()), b(ColourSpaceType::min())
    {
        // Intentionally empty.
    }

    /// @brief Construct this color from the component values of a another color.
    /// @param other the other color
    template <typename OtherColourSpaceTypeArg,
              std::enable_if_t<std::is_same<OtherColourSpaceTypeArg, ColourSpaceTypeArg>::value, int *> = nullptr>
    Colour(const Colour<OtherColourSpaceTypeArg>& other) :
        r(other.getRed()), g(other.getGreen()), b(other.getBlue())
    {
        // Intentionally empty.
    }

    /// @brief Construct this colour from the specified component values
    /// @param r the component value of the red component
    /// @param g the component value of the green component
    /// @param b the component value of the blue component
    /// @throws Id::OutOfBoundsException @a r, @a g, or @a b a are not within the range of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive)
    Colour(ComponentType r, ComponentType g, ComponentType b) :
        r(r), g(g), b(b)
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
    }

    // If RGBf to RGBb.
    template <typename OtherColourSpaceTypeArg,
              std::enable_if_t<std::is_same<ColourSpaceTypeArg, RGBb>::value &&
              std::is_same<OtherColourSpaceTypeArg, RGBf>::value, int *> = nullptr>
    Colour(const Colour<OtherColourSpaceTypeArg>& other) :
        r(Internal::f2b(other.getRed())), g(Internal::f2b(other.getGreen())), b(Internal::f2b(other.getBlue()))
    {
        // Intentionally empty.
    }

    // If RGBb to RGBf.
    template <typename OtherColourSpaceTypeArg,
              std::enable_if_t<std::is_same<ColourSpaceTypeArg, RGBf>::value &&
              std::is_same<OtherColourSpaceTypeArg, RGBb>::value, int *> = nullptr>
    Colour(const Colour<OtherColourSpaceTypeArg>& other) :
        r(Internal::b2f(other.getRed())), g(Internal::b2f(other.getGreen())), b(Internal::b2f(other.getBlue()))
    {
        // Intentionally empty.
    }

    // If Lb to RGBb.
    template <typename OtherColourSpaceTypeArg,
              std::enable_if_t<std::is_same<ColourSpaceTypeArg, RGBb>::value &&
              std::is_same<OtherColourSpaceTypeArg, Lb>::value, int *> = nullptr>
    Colour(const Colour<OtherColourSpaceTypeArg>& other) :
        r(other.getLuminance()), g(other.getLuminance()), b(other.getLuminance())
    {
        // Intentionally empty.
    }

    // If Lf to RGBf.
    template <typename OtherColourSpaceTypeArg,
              std::enable_if_t<std::is_same<ColourSpaceTypeArg, RGBf>::value &&
              std::is_same<OtherColourSpaceTypeArg, Lf>::value, int *> = nullptr>
    Colour(const Colour<OtherColourSpaceTypeArg>& other) :
        r(other.getLuminance()), g(other.getLuminance()), b(other.getLuminance())
    {
        // Intentionally empty.
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

public:
    /// @brief Invert this colour value.
    /// @return the inverted colour
    /// @remark
    /// Given a colour  \f$(r,g,b)\f$ in real-valued, normalized RGB space,
    /// then corresponding inverted colour is \f$(1-r,1-g,1-b)\f$. Inverting
    /// a colour twice yields the same colour (modulo floating-point precision).
    /// @remark
    /// The corresponding inverted colour is also known as the complementary colour.
    MyType invert() const
    {
        return MyType(ColourSpaceType::max() - this->getRed(),
                      ColourSpaceType::max() - this->getGreen(),
                      ColourSpaceType::max() - this->getBlue());
    }

public:
    // CRTP
    bool equal_to(const MyType& other) const
    {
        return this->getRed() == other.getRed()
            && this->getGreen() == other.getGreen()
            && this->getBlue() == other.getBlue();
    }

public:
    /// @brief Get the value of the red component.
    /// @return the value of the red component
    ComponentType getRed() const
    {
        return r;
    }

#if defined(ID_COLORS_SETTERS) && 1 == ID_COLORS_SETTERS
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

#if defined(ID_COLORS_SETTERS) && 1 == ID_COLORS_SETTERS
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

#if defined(ID_COLORS_SETTERS) && 1 == ID_COLORS_SETTERS
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

}; // struct Colour

} // namespace Id
