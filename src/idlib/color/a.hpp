//********************************************************************************************
//*
//*    This file is part of idlib.
//*
//*    idlib is free software: you can redistribute it and/or modify it
//*    under the terms of the GNU General Public License as published by
//*    the Free Software Foundation, either version 3 of the License, or
//*    (at your option) any later version.
//*
//*    idlib is distributed in the hope that it will be useful, but
//*    WITHOUT ANY WARRANTY; without even the implied warranty of
//*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//*    General Public License for more details.
//*
//*    You should have received a copy of the GNU General Public License
//*    along with idlib.  If not, see <http://www.gnu.org/licenses/>.
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
#include "idlib/math/interpolate_floating_point.hpp"
#include "idlib/math/invert.hpp"
#include "idlib/utility/is_any_of.hpp"
#include "idlib/color/brighten.hpp"
#include "idlib/color/darken.hpp"
#include "idlib/type.hpp"

namespace id {

/// @brief A color in LA color space.
template <typename ColorSpace>
struct color<ColorSpace, std::enable_if_t<internal::is_a<ColorSpace>::value>> :
    public equal_to_expr<color<ColorSpace>>,
    public plus_expr<color<ColorSpace>>,
    public minus_expr<color<ColorSpace>>
{
public:
    /// @brief The type of color space.
    using color_space = ColorSpace;

    // Assert the color space is an A color space.
    static_assert(internal::is_a<color_space>::value, "not an A color space");

    // Define component types and component members.
    #include "idlib/color/a-header.in.h"

private:
    void assign(const color& other)
    {
        a = other.a;
    }

public:
    /// @brief The color "transparent" (l) = (0).
    /// @return the color "transparent"
    static const color& transparent()
    {
        static const color color(color<Ab>(0));
        return color;
    }

    /// @brief The color "opaque" (l) = (255).
    /// @return the color "opaque".
    static const color& opaque()
    {
        static const color color(color<Ab>(255));
        return color;
    }

public:
    /// @brief Default construct with component values corresponding to "opaque".
    color() :
        a(color_space::a::syntax::range().max())
    {}

    /// @brief Construct this color with the values of another color.
    /// @param other the other color
    template<typename OtherColorSpace,
             std::enable_if_t<std::is_same<OtherColorSpace, ColorSpace>::value, int *> = 0>
    color(const color<OtherColorSpace>& other) :
        a(other.get_a())
    {}

    /// @brief Construct this color with the specified alpha component values.
    /// @param a the component value of the alpha component
    /// @throws out_of_bounds_exception @a a is not within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive)
    color(component_a a) :
        a(a)
    {
        if (color_space::a::syntax::range().outside(a))
        {
            throw out_of_bounds_error(__FILE__, __LINE__, "alpha component out of bounds");
        }
    }

    /// @brief Convert construct this A color from another A color.
    /// @param other the other A color
    template <typename OtherColorSpace,
              std::enable_if_t<!std::is_same<color_space, OtherColorSpace>::value &&
                               is_any_of<OtherColorSpace, Ab, Af>::value, int *> = 0>
    explicit color(const color<OtherColorSpace>& other) :
        a(type::convert<color_space::a::syntax, OtherColorSpace::a::syntax>()(other.get_a()))
    {}

    /// @brief Decompose construct this A color from an LA or RGBA color.
    /// @param other the LA or RGBA color
    template <typename OtherColorSpace,
              std::enable_if_t<std::is_same<color_space, pure_opacity_space_t<OtherColorSpace>>::value,
                               int *> = 0>
    explicit color(const color<OtherColorSpace>& other) :
        a(other.get_a())
    {}

public:
    /// @brief Assign this color from another color.
    /// @param other the other color
    /// @return this color
    const color& operator=(const color& other)
    {
        this->assign(other);
        return *this;
    }

public:
    // CRTP
    bool equal_to(const color& other) const
    {
        return get_a() == other.get_a();
    }

    // CRTP
    void add(const color& other)
    {
        a = type::add<color_space::a::syntax>()(get_a(), other.get_a());
    }

    // CRTP
    void subtract(const color& other)
    {
        a = type::subtract<color_space::a::syntax>()(get_a(), other.get_a());
    }

public:
    #include "idlib/color/a.in.h"

    /// @{
    /// @brief Set the value of the alpha component.
    /// @param a the value of the alpha component
    /// @throws out_of_bounds_exception @a a is not within the bounds of color_space::min() (inclusive) and color_space::max() (inclusive)
#if defined(ID_COLOR_SETTERS) && 1 == ID_COLOR_SETTERS
    void set_alpha(component_a a)
    {
        if (color_space::a::syntax::range().outside(a))
        {
            throw out_of_bounds_error(__FILE__, __LINE__, "alpha component out of bounds");
        }
        this->a = a;
    }
#if defined(ID_COLOR_SHORT_SETTERS) && 1 == ID_COLOR_SHORT_SETTERS
    void set_a(component_a a)
    { set_alpha(a); }
#endif
#endif
    /// @}

}; // struct color

/// @brief Inversion functor for id::color<id::Af> and id::color<id::Ab> values.
/// @remark Given a color \f$(a)\f$ in real-valued, normalized A space,
/// then corresponding inverted color is \f$(1-a)\f$. Inverting a
/// color twice yields the same color (modula floating-point precision).
/// @remark The corresponding inverted color is also known as the complementary color.
template <typename ColorSpace>
struct inversion_functor<color<ColorSpace>,
                         std::enable_if_t<is_any_of<ColorSpace, Ab, Af>::value>>
{
    using color_space = ColorSpace;
    using color = color<color_space>;

    color operator()(const color& x) const
    {
        return color(type::invert<color_space::a::syntax>()(x.get_a()));
    }

}; // struct inversion_functor

/// @brief Interpolation functor for id::color<id::Af> values.
template <typename ColorSpace>
struct interpolation_functor<color<ColorSpace>, interpolation_method::LINEAR,
                             std::enable_if_t<std::is_same<Af, ColorSpace>::value>>
{
    using color_space = ColorSpace;
    using color = color<color_space>;
    using component_functor = interpolation_functor<float, interpolation_method::LINEAR>;

    color operator()(const color& x, const color& y, float t) const
    {
        return (*this)(x, y, mu<float>(t));
    }

    color operator()(const color& x, const color& y, const mu<float>& mu) const
    {
        static const component_functor f{};
        static const auto& range_a = color_space::a::syntax::range();
        return color(range_a.clamp(f(x.get_a(), y.get_a(), mu)));
    }

}; // struct interpolate_functor

} // namespace id
