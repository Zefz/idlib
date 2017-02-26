//********************************************************************************************
//*
//*    This file is part of Egoboo.
//*
//*    Egoboo is free software: you can redistribute it and/or modify it
//*    under the terms of the GNU General Public License as published by
//*    the Free Software Foundation, either version 3 of the License, or
//*    (at your option) any later version.
//*
//*    Egoboo is distributed in the hope that it will be useful, but
//*    WITHOUT ANY WARRANTY; without even the implied warranty of
//*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//*    General Public License for more details.
//*
//*    You should have received a copy of the GNU General Public License
//*    along with Egoboo.  If not, see <http://www.gnu.org/licenses/>.
//*
//********************************************************************************************

#include "EgoTest/EgoTest.hpp"
#include "idlib/parsing_expressions/include.hpp"

namespace id { namespace parsing_expressions { namespace tests {

EgoTest_TestCase(id_parsing_expressions_tests_qualified_name)
{
    using string = std::basic_string<char>;

    EgoTest_Test(qualified_name_accept)
    {
        auto p = id::parsing_expressions::qualified_name<char>();
        const std::vector<string> words
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

    EgoTest_Test(qualified_name_reject)
    {
        auto p = id::parsing_expressions::qualified_name<char>();
        const std::vector<std::tuple<string, bool, size_t>> words
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

} // namespace tests
} // namespace parsing_expressions
} // namespace id
