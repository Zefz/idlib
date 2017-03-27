/// @file idlib/is_any_of.hpp
/// @brief SFINAE utilities: test if a type is in a list of types.
/// @author Michael Heilmann

#pragma once

#include <type_traits>

namespace id {

/// @brief
/// @code
/// id::is_any_of<T,A0,A1,..., An>::value
/// @endcode
/// is equivalent to
/// @code
/// std::is_same<T,A0>::value || std::is_same<T,A1>::value || ... || std::is_same<T,An>
/// @endcode
template<typename T, typename U, typename... Us>
struct is_any_of :
	std::integral_constant<bool,
		std::conditional<std::is_same<T, U>::value,
			std::true_type,
			is_any_of<T, Us...>
		>::type::value>
{};

template<typename T, typename U>
struct is_any_of<T, U> : std::is_same<T, U>::type
{};

} // namespace id
