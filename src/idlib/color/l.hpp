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

namespace Id {

/// @brief A color in L color space.
template <typename ColourSpaceTypeArg>
struct Colour<ColourSpaceTypeArg, std::enable_if_t<Internal::IsL<ColourSpaceTypeArg>::value>> :
    public id::equal_to_expr<Colour<ColourSpaceTypeArg>>
{
public:
    using ColourSpaceType = ColourSpaceTypeArg;
    using ComponentType = typename ColourSpaceType::ComponentType;
    using MyType = Colour<ColourSpaceType>;
    static_assert(Id::Internal::IsL<ColourSpaceTypeArg>::value, "not an L color space type");
    static_assert(ColourSpaceTypeArg::hasL() && !ColourSpaceTypeArg::hasRgb() && !ColourSpaceTypeArg::hasA(), "not an L color space type");

private:
    /// @brief The luminance component value.
    /// @invariant Within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive).
    ComponentType l;

    void assign(const MyType& other)
    {
        l = other.l;
    }

public:
    /// @brief Default construct with component values corresponding to "opaque black".
    Colour() :
        l(ColourSpaceType::min())
    {
        // Intentionally empty.
    }

    /// @brief Construct this color with the specified luminance component color.
    /// @param l the component value of the luminance component
    /// @throws OutOfBoundsException @a l is not within the bounds of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive)
    Colour(ComponentType l) :
        l(l)
    {
        if (l < ColourSpaceType::min() || l > ColourSpaceType::max())
        {
            throw OutOfBoundsException(__FILE__, __LINE__, "luminance component out of bounds");
        }
    }

    /// @brief Copy construct this color with the component values of another color.
    /// @param other the other color
    template <typename OtherColourSpaceTypeArg,
              std::enable_if_t<std::is_same<OtherColourSpaceTypeArg, ColourSpaceTypeArg>::value, int *> = nullptr>
    Colour(const Colour<OtherColourSpaceTypeArg>& other) :
        l(other.getLuminance())
    {
        // Intentionally empty.
    }

    /// @brief Construct this Lb color with the component values of an Lf color.
    /// @param other the Lf color
    template <typename OtherColourSpaceTypeArg,
              std::enable_if_t<std::is_same<ColourSpaceTypeArg, RGBb>::value &&
              std::is_same<OtherColourSpaceTypeArg, Lf>::value, int *> = nullptr>
    Colour(const Colour<OtherColourSpaceTypeArg>& other) :
        l(Internal::f2b(other.getLuminance()))
    {
        // Intentionally empty.
    }

    /// @brief Construct this Lf color with the component values of an Lb color.
    /// @param other the Lb color
    template <typename OtherColourSpaceTypeArg,
              std::enable_if_t<std::is_same<ColourSpaceTypeArg, Lf>::value &&
              std::is_same<OtherColourSpaceTypeArg, Lb>::value, int *> = nullptr>
    Colour(const Colour<OtherColourSpaceTypeArg>& other) :
        l(Internal::b2f(other.getLuminance()))
    {
        // Intentionally empty.
    }

public:
    /// @brief Assign this color from another color.
    /// @param other the other color
    /// @return this color
    const MyType& operator=(const MyType& other)
    {
        this->assign(other);
        return *this;
    }

public:
    // CRTP
    bool equal_to(const MyType& other) const
    {
        return this->getLuminance() == other.getLuminance();
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

};

} // namespace Id
