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

EgoTest_TestCase(id_parsing_expressions_tests_name)
{
    using string = std::basic_string<char>;

    EgoTest_Test(name_0)
    {
        const std::vector<string> words{"org","org_","_1", "_0", "a0"};
        auto p = id::parsing_expressions::name<char>();
		string w;
        string::const_iterator c, e;
		//
        for (const auto& word : words)
        {
            auto c = word.cbegin();
            auto e = word.cend();
            EgoTest_Assert(true == p(c, e));
            EgoTest_Assert(c == e);
            EgoTest_Assert(false == p(c, e));
        }
	}
};

} // namespace tests
} // namespace parsing_expressions
} // namespace id
