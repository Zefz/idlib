#include "EgoTest/EgoTest.hpp"
#include "idlib/to_lower.hpp"

namespace id { namespace tests {

EgoTest_TestCase(id_to_lower)
{
    EgoTest_Test(to_lower)
    {
        std::string x("X");
        id::to_lower_in_situ(x);
        EgoTest_Assert(x == "x");
        // Identity.
        id::to_lower_in_situ(x);
        EgoTest_Assert(x == "x");
    }
};

} } // namespace id::tests
