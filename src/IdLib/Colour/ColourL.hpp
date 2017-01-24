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

/// @file IdLib/Colour/ColourL.hpp
/// @brief Colours in L colour spaces.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `IdLib/IdLib.hpp` instead)
#endif

#include "IdLib/Colour/Colour.hpp"
#include "IdLib/CRTP.hpp"

namespace Id {

/// @brief A colour value in L colour space.
template <typename ColourSpaceTypeArg>
struct Colour<ColourSpaceTypeArg, std::enable_if_t<Internal::IsL<ColourSpaceTypeArg>::value>> :
    public ColourComponents<ColourSpaceTypeArg>,
    public EqualToExpr<Colour<ColourSpaceTypeArg>>
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
        ColourComponents<ColourSpaceType>(ColourSpaceType::min())
    {
        // Intentionally empty.
    }

    /// @brief Construct this colour with the specified component value.
    /// @param l the component value of the luminance component
    /// @throws Id::OutOfBoundsException @a l is not within the range of ColourSpaceType::min() (inclusive) and ColourSpaceType::max() (inclusive)
    Colour(ComponentType l) :
        ColourComponents<ColourSpaceType>(l)
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
    bool equalTo(const MyType& other) const
    {
        return this->getLuminance() == other.getLuminance();
    }

};

} // namespace Id
