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

/// @file idlib/color/ColourLA.hpp
/// @brief Colours in LA colour spaces.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/Idlib.hpp` instead)
#endif

#include "idlib/color/Colour.hpp"
#include "idlib/CRTP.hpp"

namespace Id {

/// @brief A colour value in LA colour space.
template <typename ColourSpaceTypeArg>
struct Colour<ColourSpaceTypeArg, std::enable_if_t<Internal::IsLA<ColourSpaceTypeArg>::value>> :
    public ColourComponents<ColourSpaceTypeArg>,
    public id::equal_to_expr<Colour<ColourSpaceTypeArg>>
{
public:
    using ColourSpaceType = ColourSpaceTypeArg;
    using ComponentType = typename ColourSpaceType::ComponentType;
    using MyType = Colour<ColourSpaceType>;

public:
    /// @brief Construct this colour with the component values of a specified other colour.
    /// @param other the other colour
    template <typename OtherColourSpaceTypeArg>
    Colour(const Colour<OtherColourSpaceTypeArg>& other) :
        ColourComponents<ColourSpaceType>(other)
    {
        // Intentionally empty.
    }

    /// @brief Default construct with component values corresponding to "opaque black".
    Colour() :
        ColourComponents<ColourSpaceType>(ColourSpaceType::min(), ColourSpaceType::max())
    {
        // Intentionally empty.
    }

    /// @brief Construct this colour with the specified component values.
    /// @param l the component value of the luminance component
    /// @param a the component value of the alpha component
    /// @throws Id::OutOfBoundsException @a l or @a a are not within the range of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive)
    Colour(ComponentType l, ComponentType a) :
        ColourComponents<ColourSpaceType>(l, a)
    {
        // Intentionally empty.
    }

public:
    /// @brief Assign this colour from another colour.
    /// @param other the other colour
    /// @return this colour
    const MyType& operator=(const MyType& other)
    {
        this->ColourComponents<ColourSpaceType>::assign(other);
        return *this;
    }

public:
    // CRTP
    bool equal_to(const MyType& other) const
    {
        return this->getLuminance() == other.getLuminance()
            && this->getAlpha() == other.getAlpha();
    }

};

} // namespace Id
