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

/// @file idlib/math/even_odd.hpp
/// @brief Functionality to determine wether a value is even or odd.
/// @detail Further reading "Why Not Specialize Function Templates?"
/// (http://www.gotw.ca/publications/mill17.htm).
/// @author Michael Heilmann

#pragma once

#include <type_traits>

namespace id {

/// @brief Functor which defines an operator @code{constexpr bool operator()(T x) const noexcept}
/// which determines wether the specified value @a x is even.
/// @tparam T the type of the value
/// @tparam E SFINAE support
/// @remark Feel free to provide your own implementation.
/// Specialization for all integral types excluding @a bool are provided.
/// Implementations for built-in types work regardless of the machine representation and are as fast as any bit hack.
template <typename T, typename E = void>
class is_even_functor;

/// @internal
template <typename T>
class is_even_functor<T,std::enable_if_t<std::is_integral<typename std::remove_reference<T>::type>::value && !std::is_same<typename std::remove_reference<T>::type, bool>::value>>
{
public:
    constexpr bool operator()(T x) const noexcept
    {
        return 0 == (x % 2);
    }
};

/// @brief Get if the specified value is odd.
/// @param x the value
/// @return @a true if @a x is odd, @a false otherwise
/// @remark This is a forwarding function forwarding to id::is_even_functor.
/// To support your custom type, add a specialization of the id::is_even_functor.
template <typename T>
constexpr bool is_even(T&& x) noexcept
{
    return is_even_functor<T>()(std::forward<T>(x));
}

/// @brief Get if the specified value is even.
/// @param x the value
/// @return @a true if @a x is even, @a false otherwise
/// @remark This is a forwarding function forwarding to id::is_even_functor.
/// To support your custom type, add a specialization of the id::is_even_functor.
template <typename T>
constexpr bool is_odd(T&& x) noexcept
{
    return !is_even(std::forward<T>(x));
}

} // namespace id
