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

#include "idlib/tests/parsing_expressions/header.in"

EgoTest_TestCase(choice_expression_testing)
{
    using string = std::basic_string<char>;

    EgoTest_Test(test_choice_expression_1)
    {
        static const std::string w0 = "x", w1 = "y";
        static const auto p = id::parsing_expressions::ordered_choice
            (
                id::parsing_expressions::sym<char>('x'),
                id::parsing_expressions::sym<char>('y')
                
            );
        /*
        const std::vector<string> words_to_accept
        {
            "x",
            "y"
        };
        const std::vector<string> words_to_reject
        {
            "u",
            "v"
        };
        */
        //for (const auto& word : words_to_accept)
        {
            auto s = w0.cbegin();
            auto e = w0.cend();
            EgoTest_Assert(true == p(s, e).first);
            EgoTest_Assert(p(s, e).second == w0.cend());
        }
        //for (const auto& word : words_to_reject)
        {
            auto s = w1.cbegin();
            auto e = w1.cend();
            EgoTest_Assert(true == p(s, e).first);
            EgoTest_Assert(p(s, e).second == w1.cend());
        }
    }

    EgoTest_Test(test_choice_expression_2)
    {
        auto p = id::parsing_expressions::ordered_choice
            (
                id::parsing_expressions::sequence
                (
                    id::parsing_expressions::sym<char>('x'),
                    id::parsing_expressions::sym<char>('x')
                ),
                id::parsing_expressions::sequence
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
            auto s = word.cbegin();
            auto e = word.cend();
            EgoTest_Assert(true == p(s, e).first);
            EgoTest_Assert(p(s,e).second == word.cend());
        }
        for (const auto& word : words_to_reject)
        {
            auto s = word.cbegin();
            auto e = word.cend();
            EgoTest_Assert(false == p(s, e).first);
            EgoTest_Assert(p(s, e).second == word.cbegin());
        }
    }
};

#include "idlib/tests/parsing_expressions/footer.in"
