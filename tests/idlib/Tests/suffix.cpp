#include "EgoTest/EgoTest.hpp"
#include "idlib/suffix.hpp"
#include <vector>

namespace id { namespace tests {

EgoTest_TestCase(id_suffix)
{
    EgoTest_Test(suffix)
    {
        static const std::string word = "abcdef";
        static const std::vector<std::string> true_suffixes =
        {
            "",
            "f",
            "ef",
            "def",
            "cdef",
            "bcdef",
        };
        static const std::vector<std::string> false_suffixes =
        {
            "abcdef",
        };
        std::vector<std::string> suffixes;
        suffixes.insert(suffixes.end(), true_suffixes.cbegin(), true_suffixes.cend());
        suffixes.insert(suffixes.end(), false_suffixes.cbegin(), false_suffixes.cend());
        // Assert prefixes are detected as such.
        for (const auto& suffix : suffixes)
        {
            EgoTest_Assert(true == id::is_suffix(word, suffix));
        }
        // Assert true suffixes are detected as such and as suffixes as well.
        for (const auto& suffix : true_suffixes)
        {
            EgoTest_Assert(true == id::is_true_suffix(word, suffix));
            EgoTest_Assert(true == id::is_suffix(word, suffix));
        }
        // Assert false suffixes are not detected as true suffixes.
        for (const auto& suffix : false_suffixes)
        {
            EgoTest_Assert(false == id::is_true_suffix(word, suffix));
        }
    }
};

} } // namespace id::tests
