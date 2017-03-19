
/// @file idlib/math/one_zero.hpp
/// @brief Functionality to determine the zero and one values of set of values.
/// @detail Further reading "Why Not Specialize Function Templates?"
/// (http://www.gotw.ca/publications/mill17.htm).
/// @author Michael Heilmann

#pragma once

#include <type_traits>

namespace id {

/// @brief The zero element of a domain of values (e.g. int, float, user-defined types, ...)
/// over which the operations addition and subtraction are defined has the properties
/// - \f$0 + x = x\f$
/// - \f$x + 0 = x\f$
/// - \f$0 \cdot x = 0\f$
/// - \f$x \cdot 0 = 0\f$
/// If in addition the negation operation is defined then in addition the property
/// - \f$-0 = 0\f$
/// holds.
/// @tparam T the type of the values
/// @tparam E SFINAE support
/// @remark Feel free to provide your own implementation.
/// Specialization for all integral types excluding @a bool are provided.
/// Specializations for @a float and @a double are provided.
template <typename T, typename E>
class zero_functor;

/// @internal
template <typename T>
class zero_functor<T, std::enable_if_t<std::is_integral<T>::value && !std::is_same<T, bool>::value>>
{
public:
    constexpr T operator()() noexcept
    {
        return 0;
    }
};

/// @internal
template <>
class zero_functor<float, void>
{
public:
    constexpr float operator()() noexcept
    {
        return 0.0f;
    }
};

/// @internal
template <>
class zero_functor<double, void>
{
public:
    constexpr double operator()() noexcept
    {
        return 0.0;
    }
};

/// @brief The one element of a domain of values (e.g. int, float, user-defined types, ...)
/// over which the operations addition and subtraction are defined has the properties
/// - \f$1 \cdot x = x\f$.
/// @tparam T the type of the values
/// @tparam E SFINAE support
/// @remark Feel free to provide your own implementation.
/// Specialization for all integral types excluding @a bool are provided.
/// Specializations for @a float and @a double are provided.
template <typename T, typename E>
class one_functor;

/// @internal
template <typename T>
class one_functor<T, std::enable_if_t<std::is_integral<T>::value && !std::is_same<T, bool>::value>>
{
public:
    constexpr T operator()() noexcept
    {
        return 1;
    }
};

/// @internal
template <>
class one_functor<float, void>
{
public:
    constexpr float operator()() noexcept
    {
        return 1.0f;
    }
};

/// @internal
template <>
class one_functor<double, void>
{
public:
    constexpr double operator()() noexcept
    {
        return 1.0;
    }
};

/// @brief Get the zero value the type @a T.
/// @tparam T the type
/// @return the zero value of the type @a T
template <typename T>
typename std::result_of<zero_functor<T, void>()>::type zero()
{
	return zero_functor<T, void>()();
}

/// @brief Get the one value of the type @a T.
/// @tparam T the type
/// @return the one value of the type @a T
template <typename T>
typename std::result_of<one_functor<T, void>()>::type one()
{
	return one_functor<T, void>()();
}

} // namespace id
