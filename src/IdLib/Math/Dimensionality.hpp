#pragma once

namespace id {

/// @brief Test whether @a N fulfils the <em>dimensionality concept</em>.
/// Provides the member constant value which is equal to @a true, if @a N
/// fulfils the <em>dimensionality concept</em>.
/// Otherwise @a value is equal to @a false.
/// @tparam N the value to test
template <size_t N>
struct is_dimensionality
{
	static constexpr bool value = true;
	
	constexpr operator bool() const
	{
		return value;
	}
};

template <>
struct is_dimensionality<0>
{
	static constexpr bool value = false;
	
	constexpr operator bool() const
	{
		return value;
	}
};

/// @code
/// template<size_t N>
/// constexpr bool is_dimensionality_v = is_dimensionality<N>::value;
/// @endcode
template<size_t N>
constexpr bool is_dimensionality_v = is_dimensionality<N>::value;

} // namespace id