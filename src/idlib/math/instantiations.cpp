#define IDLIB_PRIVATE 1
#include "idlib/math/dimensionality.hpp"
#include "idlib/math/interpolation_method.hpp"
#include "idlib/math/interpolate.hpp"
#include "idlib/math/interpolate_floating_point.hpp"
#include "idlib/math/mu.hpp"
#include "idlib/math/even_odd.hpp"
#include "idlib/math/one_zero.hpp"
#undef IDLIB_PRIVATE

template class id::mu<float>;
template class id::mu<double>;

template struct id::interpolation_functor<float,id::interpolation_method::LINEAR>;
template struct id::interpolation_functor<double, id::interpolation_method::LINEAR>;

template class id::zero_functor<float>;
template class id::zero_functor<double>;
template class id::zero_functor<short>;
template class id::zero_functor<int>;
template class id::zero_functor<long>;

template class id::one_functor<float>;
template class id::one_functor<double>;
