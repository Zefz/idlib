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

#include "gtest/gtest.h"
#include "idlib/parsing_expressions/include.hpp"

#include "idlib/tests/parsing_expressions/header.in"

using symbol = char;
using namespace id::parsing_expressions;
using namespace std;

TEST(any_sym_testing, test_acceptance)
{
    auto p = any_sym<char>();
    const vector<pair<string, bool>> words
    {
        make_pair("", false),
        make_pair("x", true),
        make_pair("y", true),
        make_pair("z", true),
    };
    for (const auto& word : words)
    {
        auto s = word.first.cbegin();
        auto e = word.first.cend();
        ASSERT_EQ(word.second, p(s, e).first);
        if (word.second)
        {
            ASSERT_EQ(p(s, e).second, e);
        }
        else
        {
            ASSERT_EQ(p(s,e).second, s);
        }
        ASSERT_FALSE(p(p(s, e).second, e).first);
    }
}

#include "idlib/tests/parsing_expressions/footer.in"
