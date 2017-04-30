#define IDLIB_PRIVATE 1
#include "idlib/color/a.hpp"
#include "idlib/color/l.hpp"
#include "idlib/color/la.hpp"
#include "idlib/color/rgb.hpp"
#include "idlib/color/rgba.hpp"
#undef IDLIB_PRIVATE

template struct id::color<id::Ab>;
template struct id::color<id::Af>;

template struct id::color<id::Lb>;
template struct id::color<id::Lf>;

template struct id::color<id::LAb>;
template struct id::color<id::LAf>;

template struct id::color<id::RGBb>;
template struct id::color<id::RGBf>;

template struct id::color<id::RGBAb>;
template struct id::color<id::RGBAf>;
