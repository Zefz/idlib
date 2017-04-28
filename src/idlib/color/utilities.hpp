#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/idlib.hpp` instead)
#endif

#include "idlib/platform.hpp"

namespace id {
namespace internal {

/// @brief Convert an @a uint8_t value within the bounds of \f$0\f$ (incl.)
/// and \f$255\f$ (incl.) to a @a float value within the bounds of \f$0\f$
/// (incl.) and \f$1\f$ (incl.). Conceptually, the output is
/// \f$\frac{x}{255}\f$ for an input \f$x\f$.
float b2f(uint8_t x);

/// @brief Convert a @a double value within the bounds of \f$0\f$ (incl.)
/// and \f$1\f$ (incl.) to an @a uint8_t value within the bounds of \f$0\f$
/// (incl.) and \f$255\f$ (incl.). Conceptually, the output is
/// \f$x \cdot 255\f$ for an input \f$x\f$.
uint8_t d2b(double x);

/// @brief Convert a @a float value within the bounds of \f$0\f$ (incl.)
/// and \f$1\f$ (incl.) to an @a uint8_t value within the bounds of \f$0\f$
/// (incl.) and \f$255\f$ (incl.). Conceptually, the output is
/// \f$x \cdot 255\f$ for an input \f$x\f$.
uint8_t f2b(float x);

} // namespace internal
} // namespace id
