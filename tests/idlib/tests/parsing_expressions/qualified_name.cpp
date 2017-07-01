// Copyright Michael Heilmann 2016, 2017.
//
// This file is part of Idlib.
//
// Idlib is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Idlib is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Idlib. If not, see <http://www.gnu.org/licenses/>.

#include "EgoTest/EgoTest.hpp"
#include "idlib/parsing_expressions/include.hpp"

namespace id { namespace tests { namespace parsing_expression {

EgoTest_TestCase(qualified_name_testing)
{
    EgoTest_Test(test_qualified_name_acceptance)
    {
        auto p = id::parsing_expressions::qualified_name<char>();
        const std::vector<std::string> words
            {
                "org.egoboo",
                "org.egoboo.ego",
                "org.egoboo.id"
            };
        for (const auto& word : words)
        {
            auto c = word.cbegin();
            auto e = word.cend();
            EgoTest_Assert(true == p(c, e));
            EgoTest_Assert(c == e);
            EgoTest_Assert(false == p(c, e));
        }
    }

    EgoTest_Test(qualified_name_rejection)
    {
        auto p = id::parsing_expressions::qualified_name<char>();
        const std::vector<std::tuple<std::string, bool, size_t>> words
        {
                { ".egoboo", false, 0 },
                { "org.", true, 3 },
                { "org.egoboo.", true, 10 },
                { "org.#", true, 3 },
                { "org.egoboo.#", true, 10 },
        };
        for (const auto& word : words)
        {
            auto c = std::get<0>(word).cbegin();
            auto e = std::get<0>(word).cend();
            EgoTest_Assert(std::get<1>(word) == p(c, e));
            EgoTest_Assert(c == std::get<0>(word).cbegin() + std::get<2>(word));
        }
    }
};

} } } // namespace id::tests::parsing_expression
