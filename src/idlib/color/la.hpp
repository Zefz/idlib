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
#error(do not include directly, include `idlib/Idlib.hpp` instead)
#endif

#include "idlib/color/color.hpp"
#include "idlib/crtp.hpp"

namespace Id {

/// @brief A color in LA color space.
template <typename ColourSpaceTypeArg>
struct Colour<ColourSpaceTypeArg, std::enable_if_t<Internal::IsLA<ColourSpaceTypeArg>::value>> :
    public id::equal_to_expr<Colour<ColourSpaceTypeArg>>
{
public:
    using ColourSpaceType = ColourSpaceTypeArg;
    using ComponentType = typename ColourSpaceType::ComponentType;
    using MyType = Colour<ColourSpaceType>;

private:
    /// @brief The luminance component value.
    /// @invariant Within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive).
    ComponentType l;

    /// @brief The alpha component value.
    /// @invariant Within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive).
    ComponentType a;

    void assign(const MyType& other)
    {
        l = other.l;
        a = other.a;
    }

public:
    /// @brief Default construct with component values corresponding to "opaque black".
    Colour() :
        l(ColourSpaceType::min()), a(ColourSpaceType::max())
    {
        // Intentionally empty.
    }

    /// @brief Construct this color with the values of another color.
    /// @param other the other color
    template <typename OtherColourSpaceTypeArg,
              std::enable_if_t<std::is_same<OtherColourSpaceTypeArg, ColourSpaceTypeArg>::value, int *> = 0>
    Colour(const Colour<OtherColourSpaceTypeArg>& other) :
        l(other.getLuminance()), a(other.getAlpha())
    {
        // Intentionally empty.
    }

    /// @brief Construct this color with the specified luminance and alpha component values.
    /// @param l the component value of the luminance component
    /// @param a the component value of the alpha component
    /// @throws OutOfBoundsException @a l or @a a are not within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive)
    Colour(ComponentType l, ComponentType a) :
        l(l), a(a)
    {
        if (l < ColourSpaceType::min() || l > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "luminance component out of bounds");
        }
        if (a < ColourSpaceType::min() || a > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "alpha component out of bounds");
        }
    }

    /// @brief Construct this color from the specified color of the corresponding opaque color space and the specified alpha component value.
    /// @param l the L color
    /// @param a the component value of the blue component
    /// @throws Id::OutOfBoundsException @a a is not within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive)
    Colour(const Colour<Opaque<ColourSpaceType>>& l, ComponentType a)
        : l(l.getLuminance()), a(a)
    {
        /* l is known to be within bounds. */
        if (a < ColourSpaceType::min() || a > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "alpha component out of bounds");
        }
    }

    // If LAf to LAb.
    template <typename OtherColourSpaceTypeArg,
              std::enable_if_t<std::is_same<ColourSpaceTypeArg, LAb>::value &&
              std::is_same<OtherColourSpaceTypeArg, LAf>::value, int *> = 0>
    Colour(const Colour<OtherColourSpaceTypeArg>& other) :
        l(Internal::b2f(other.getLuminance())), a(f2b(other.getAlpha()))
    {
        // Intentionally empty.
    }

    // If LAb to LAf.
    template <typename OtherColourSpaceTypeArg,
              std::enable_if_t<std::is_same<ColourSpaceTypeArg, LAf>::value &&
              std::is_same<OtherColourSpaceTypeArg, LAb>::value, int *> = 0>
    Colour(const Colour<OtherColourSpaceTypeArg>& other) :
        l(Internal::b2f(other.getLuminance())), a(Internal::b2f(other.getAlpha()))
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
    // CRTP
    bool equal_to(const MyType& other) const
    {
        return this->getLuminance() == other.getLuminance()
            && this->getAlpha() == other.getAlpha();
    }

public:
    /// @brief Get the value of the luminance component.
    /// @return the value of the luminance component
    ComponentType getLuminance() const
    {
        return l;
    }

#if defined(ID_COLOR_SHORT_GETTERS) && 1 == ID_COLOR_SHORT_GETTERS
    /// @brief Get the value of the luminance component.
    /// @return the value of the luminance component
    ComponentType getL() const
    {
        return l;
    }
#endif

#if defined(ID_COLOR_SETTERS) && 1 == ID_COLOR_SETTERS
    /// @brief Set the value of the luminance component.
    /// @param l the value of the luminance component
    /// @throws OutOfBoundsException @a l is not within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive)
    void setLuminance(ComponentType l)
    {
        if (l < ColourSpaceType::min() || l > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "luminance component out of bounds");
        }
        this->l = l;
    }
#if defined(ID_COLOR_SHORT_SETTERS) && 1 == ID_COLOR_SHORT_SETTERS
    /// @brief Set the value of the luminance component.
    /// @param l the value of the luminance component
    /// @throws OutOfBoundsException @a l is not within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive)
    void setL(ComponentType l)
    {
        if (l < ColourSpaceType::min() || l > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "luminance component out of bounds");
        }
        this->l = l;
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
