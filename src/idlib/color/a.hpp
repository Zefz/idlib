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

/// @file idlib/color/a.hpp
/// @brief Colors in A color spaces.
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
struct color<ColorSpace, std::enable_if_t<internal::IsA<ColorSpace>::value>> :
    public equal_to_expr<color<ColorSpace>>
{
public:
    using color_space = ColorSpace;
    using component = typename ColorSpace::ComponentType;
    using this_type = color<ColorSpace>;

private:
    /// @brief The alpha component value.
    /// @invariant Within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive).
    component a;

    void assign(const this_type& other)
    {
        a = other.a;
    }

public:
    /// @brief Default construct with component values corresponding to "opaque".
    color() :
        a(color_space::max())
    {
        // Intentionally empty.
    }

    /// @brief Construct this color with the values of another color.
    /// @param other the other color
    template<typename OtherColorSpace,
             std::enable_if_t<std::is_same<OtherColorSpace, ColorSpace>::value, int *> = 0>
    color(const color<OtherColorSpace>& other) :
        a(other.getAlpha())
    {
        // Intentionally empty.
    }

    /// @brief Construct this color with the specified alpha component values.
    /// @param a the component value of the alpha component
    /// @throws out_of_bounds_exception @a a is not within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive)
    color(component a) :
        a(a)
    {
        if (a < color_space::min() || a > color_space::max())
        {
            throw out_of_bounds_exception(__FILE__, __LINE__, "alpha component out of bounds");
        }
    }

    // If Af to Ab.
    template <typename OtherColorSpace,
              std::enable_if_t<std::is_same<ColorSpace, Ab>::value &&
              std::is_same<OtherColorSpace, Af>::value, int *> = 0>
    color(const color<OtherColorSpace>& other) :
        a(f2b(other.getAlpha()))
    {
        // Intentionally empty.
    }

    // If Ab to Af.
    template <typename OtherColorSpace,
              std::enable_if_t<std::is_same<ColorSpace, Af>::value &&
              std::is_same<OtherColorSpace, Ab>::value, int *> = 0>
    color(const color<OtherColorSpace>& other) :
        a(internal::b2f(other.getAlpha()))
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
        return this->getAlpha() == other.getAlpha();
    }

public:
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

/// @brief Interpolation functor for id::color<id::Af> values.
template <typename ColorSpace>
struct interpolation_functor<color<ColorSpace>, interpolation_method::LINEAR,
    std::enable_if_t<std::is_same<Af, ColorSpace>::value>>
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
        return the_color(std::clamp(f(x.getAlpha(), y.getAlpha(), mu),
                                    the_color_space::min(),
                                    the_color_space::max()));
    }

}; // struct interpolate_functor

} // namespace id
