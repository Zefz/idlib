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

EgoTest_TestCase(choice_expression_testing)
{
    using string = std::basic_string<char>;

    EgoTest_Test(test_choice_expression)
    {
        auto p = id::parsing_expressions::choice<char>
            (
                id::parsing_expressions::sequence<char>
                (
                    id::parsing_expressions::sym<char>('x'),
                    id::parsing_expressions::sym<char>('x')
                    ),
                id::parsing_expressions::sequence<char>
                (
                    id::parsing_expressions::sym<char>('y'),
                    id::parsing_expressions::sym<char>('y')
                )
            );
        const std::vector<string> words_to_accept
        {
            "xx",
            "yy"
        };
        const std::vector<string> words_to_reject
        {
            "xy",
            "yx"
        };
        for (const auto& word : words_to_accept)
        {
            auto c = word.cbegin();
            auto e = word.cend();
            EgoTest_Assert(true == p(c, e));
            EgoTest_Assert(c == word.cend());
        }
        for (const auto& word : words_to_reject)
        {
            auto c = word.cbegin();
            auto e = word.cend();
            EgoTest_Assert(false == p(c, e));
            EgoTest_Assert(c == word.cbegin());
        }
    }
};

} // namespace parsing_expression
} // namespace tests
} // namespace id
