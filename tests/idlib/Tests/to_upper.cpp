#include "EgoTest/EgoTest.hpp"
#include "idlib/to_upper.hpp"

namespace id { namespace tests {

EgoTest_TestCase(id_to_upper)
{
    EgoTest_Test(to_upper)
    {
        std::string x("x");
        id::to_upper_in_situ(x);
        EgoTest_Assert(x == "X");
        // Identity.
        id::to_upper_in_situ(x);
        EgoTest_Assert(x == "X");
    }
};

} } // namespace id::tests
