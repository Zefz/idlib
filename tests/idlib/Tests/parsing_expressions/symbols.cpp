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

EgoTest_TestCase(id_parsing_expressions_tests_symbols)
{
    using string = std::basic_string<char>;

    EgoTest_Test(period)
    {
        auto p = id::parsing_expressions::sym<char>('.');
        string w;
        string::const_iterator c, e;
        //
        w = string(".");
        c = w.cbegin(); e = w.cend();
        EgoTest_Assert(true == p(c, e));
        EgoTest_Assert(c == e);
        EgoTest_Assert(false == p(c, e));
    }

    EgoTest_Test(whitespace)
    {
        auto p = id::parsing_expressions::whitespace<char>();
        string w;
        string::const_iterator c, e;
        //
        w = string(" ");
        c = w.cbegin(); e = w.cend();
        EgoTest_Assert(true == p(c, e));
        EgoTest_Assert(c == e);
        EgoTest_Assert(false == p(c, e));
        //
        w = string("\t");
        c = w.cbegin(); e = w.cend();
        EgoTest_Assert(true == p(c, e));
        EgoTest_Assert(c == e);
        EgoTest_Assert(false == p(c, e));
    }

    EgoTest_Test(newline)
    {
        auto p = id::parsing_expressions::newline<char>();
        string w;
        string::const_iterator c, e;
        //
        w = string("\n");
        c = w.cbegin(); e = w.cend();
        EgoTest_Assert(true == p(c, e));
        EgoTest_Assert(c == e);
        EgoTest_Assert(false == p(c, e));
        //
        w = string("\r");
        c = w.cbegin(); e = w.cend();
        EgoTest_Assert(true == p(c, e));
        EgoTest_Assert(c == e);
        EgoTest_Assert(false == p(c, e));
    }

    EgoTest_Test(digit)
    {
        auto p = id::parsing_expressions::digit<char>();
        for (char symbol = '0'; symbol <= '9'; ++symbol)
        {
            auto w = string(1, symbol);
            auto c = w.cbegin(), e = w.cend();
            EgoTest_Assert(true == p(c, e));
            EgoTest_Assert(c == e);
            EgoTest_Assert(false == p(c, e));
        }
    }
    
    EgoTest_Test(alpha_lowercase)
    {
        auto p = id::parsing_expressions::alpha_lowercase<char>();
        for (char symbol = 'a'; symbol <= 'z'; ++symbol)
        {
            auto w = string(1, symbol);
            auto c = w.cbegin(), e = w.cend();
            EgoTest_Assert(true == p(c, e));
            EgoTest_Assert(c == e);
            EgoTest_Assert(false == p(c, e));
        }
    }

    EgoTest_Test(alpha_uppercase)
    {
        auto p = id::parsing_expressions::alpha_uppercase<char>();
        for (char symbol = 'A'; symbol <= 'Z'; ++symbol)
        {
            auto w = string(1, symbol);
            auto c = w.cbegin(), e = w.cend();
            EgoTest_Assert(true == p(c, e));
            EgoTest_Assert(c == e);
            EgoTest_Assert(false == p(c, e));
        }
    }

    EgoTest_Test(alpha)
    {
        auto p = id::parsing_expressions::alpha<char>();
        //
        for (char symbol = 'a'; symbol <= 'z'; ++symbol)
        {
            auto w = string(1, symbol);
            auto c = w.cbegin(), e = w.cend();
            EgoTest_Assert(true == p(c, e));
            EgoTest_Assert(c == e);
            EgoTest_Assert(false == p(c, e));
        }
        //
        for (char symbol = 'A'; symbol <= 'Z'; ++symbol)
        {
            auto w = string(1, symbol);
            auto c = w.cbegin(), e = w.cend();
            EgoTest_Assert(true == p(c, e));
            EgoTest_Assert(c == e);
            EgoTest_Assert(false == p(c, e));
        }
    }
};

} // namespace tests
} // namespace parsing_expressions
} // namespace id

