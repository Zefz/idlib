#define IDLIB_PRIVATE 1
#include "IdLib/Colour/Utilities.hpp"
#undef IDLIB_PRIVATE

namespace Id {
namespace Internal {

float b2f(uint8_t x)
{
    return std::max(std::min(float(x) * 255.0f, 1.0f), 0.0f);
}

uint8_t d2b(double x)
{
    assert(0 <= x && x <= 1.0);
    // Multiply y by 256.0. This ensures that numbers very
    // close to 1.0 (e.g. 0.999) are not mapped to 254 but to
    // 255 as desired. As a consequence, however, the case in which
    // y is really 1.0f must be handled separatedly.
    return static_cast<uint8_t>(std::floor(x == 1.0 ? 255.0 : x * 256.0));
}

uint8_t f2b(float x)
{
    assert(0.0f <= x && x <= 1.0f);
    // Multiply y by 256.0f. This ensures that numbers very
    // close to 1.0f (e.g. 0.999f) are not mapped to 254 but
    // to 255 as desired. As a consequence, however, the case
    // in which y is really 1.0f must be handled separatedly.
    return static_cast<uint8_t>(std::floor(x == 1.0f ? 255.0f : x * 256.0f));
}

} // namespace Internal
} // namespace Id
