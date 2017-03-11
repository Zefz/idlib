#include "EgoTest/EgoTest.hpp"
#include "idlib/prefix.hpp"
#include <vector>

namespace id { namespace tests {

EgoTest_TestCase(id_prefix)
{
    EgoTest_Test(prefix)
    {
        static const std::string word = "abcdef";
        static const std::vector<std::string> true_prefixes =
        {
            "",
            "a",
            "ab",
            "abc",
            "abcd",
            "abcde",
        };
        static const std::vector<std::string> false_prefixes =
        {
            "abcdef",
        };
        std::vector<std::string> prefixes;
        prefixes.insert(prefixes.end(), true_prefixes.cbegin(), true_prefixes.cend());
        prefixes.insert(prefixes.end(), false_prefixes.cbegin(), false_prefixes.cend());
        // Assert prefixes are detected as such.
        for (const auto& prefix : prefixes)
        {
            EgoTest_Assert(true == id::is_prefix(word, prefix));
        }
        // Assert true prefixes are detected as such and as prefixes as well.
        for (const auto& prefix : true_prefixes)
        {
            EgoTest_Assert(true == id::is_true_prefix(word, prefix));
            EgoTest_Assert(true == id::is_prefix(word, prefix));
        }
        // Assert false prefixes are not detected as true prefixes.
        for (const auto& prefix : false_prefixes)
        {
            EgoTest_Assert(false == id::is_true_prefix(word, prefix));
        }
    }
};

} } // namespace id::tests
