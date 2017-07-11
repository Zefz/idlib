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

namespace id {
    namespace tests {
        namespace parsing_expression {


EgoTest_TestCase(period_expression_testing)
{
    EgoTest_Test(test_period_expression)
    {
        auto p = id::parsing_expressions::sym<char>('.');
        std::string w;
        std::string::const_iterator s, e;
        //
        w = std::string(".");
        s = w.cbegin(); e = w.cend();
        EgoTest_Assert(true == p(s, e).first);
        EgoTest_Assert(p(s,e).second == e);
        EgoTest_Assert(false == p(p(s,e).second, e).first);
    }
};

EgoTest_TestCase(whitespace_expression_testing)
{
    EgoTest_Test(test_whitespace_expression)
    {
        auto p = id::parsing_expressions::whitespace<char>();
        std::string w;
        std::string::const_iterator s, e;
        //
        w = std::string(" ");
        s = w.cbegin(); e = w.cend();
        EgoTest_Assert(true == p(s, e).first);
        EgoTest_Assert(p(s,e).second == e);
        EgoTest_Assert(false == p(p(s,e).second, e).first);
        //
        w = std::string("\t");
        s = w.cbegin(); e = w.cend();
        EgoTest_Assert(true == p(s, e).first);
        EgoTest_Assert(p(s,e).second == e);
        EgoTest_Assert(false == p(p(s,e).second, e).first);
    }
};

EgoTest_TestCase(newline_expression_testing)
{
    EgoTest_Test(test_newline_expression)
    {
        auto p = id::parsing_expressions::newline<char>();
        std::string w;
        std::string::const_iterator s, e;
        //
        w = std::string("\n");
        s = w.cbegin(); e = w.cend();
        EgoTest_Assert(true == p(s, e).first);
        EgoTest_Assert(p(s,e).second == e);
        EgoTest_Assert(false == p(p(s,e).second, e).first);
        //
        w = std::string("\r");
        s = w.cbegin(); e = w.cend();
        EgoTest_Assert(true == p(s, e).first);
        EgoTest_Assert(p(s,e).second == e);
        EgoTest_Assert(false == p(p(s,e).second, e).first);
    }
};

EgoTest_TestCase(digit_symbol_testing)
{
    EgoTest_Test(test_digit_expression)
    {
        auto p = id::parsing_expressions::digit<char>();
        for (char symbol = '0'; symbol <= '9'; ++symbol)
        {
            auto w = std::string(1, symbol);
            auto s = w.cbegin(), e = w.cend();
            EgoTest_Assert(true == p(s, e).first);
            EgoTest_Assert(p(s,e).second == e);
            EgoTest_Assert(false == p(p(s,e).second, e).first);
        }
    }
};
    
EgoTest_TestCase(alpha_lowercase_expression_testing)
{
    EgoTest_Test(test_alpha_lowercase_expression)
    {
        auto p = id::parsing_expressions::alpha_lowercase<char>();
        for (char symbol = 'a'; symbol <= 'z'; ++symbol)
        {
            auto w = std::string(1, symbol);
            auto s = w.cbegin(), e = w.cend();
            EgoTest_Assert(true == p(s, e).first);
            EgoTest_Assert(p(s,e).second == e);
            EgoTest_Assert(false == p(p(s,e).second, e).first);
        }
    }
};

EgoTest_TestCase(alpha_uppercase_expression_testing)
{
    EgoTest_Test(test_alpha_uppercase_expression)
    {
        auto p = id::parsing_expressions::alpha_uppercase<char>();
        for (char symbol = 'A'; symbol <= 'Z'; ++symbol)
        {
            auto w = std::string(1, symbol);
            auto s = w.cbegin(), e = w.cend();
            EgoTest_Assert(true == p(s, e).first);
            EgoTest_Assert(p(s,e).second == e);
            EgoTest_Assert(false == p(p(s,e).second, e).first);
        }
    }
};

EgoTest_TestCase(alpha_expression_testing)
{
    EgoTest_Test(test_single_symbol)
    {
        //
        for (char symbol = 'a'; symbol <= 'z'; ++symbol)
        {
            auto p = id::parsing_expressions::sym(symbol);
            auto w = std::string(1, symbol);
            auto s = w.cbegin(), e = w.cend();
            EgoTest_Assert(true == p(s, e).first);
            EgoTest_Assert(p(s, e).second == e);
            EgoTest_Assert(false == p(p(s,e).second, e).first);
        }
        //
        for (char symbol = 'A'; symbol <= 'Z'; ++symbol)
        {
            auto p = id::parsing_expressions::sym(symbol);
            auto w = std::string(1, symbol);
            auto s = w.cbegin(), e = w.cend();
            EgoTest_Assert(true == p(s, e).first);
            EgoTest_Assert(p(s, e).second == e);
            EgoTest_Assert(false == p(p(s, e).second, e).first);
        }
    }
    EgoTest_Test(test_alpha_expression)
    {
        auto p = id::parsing_expressions::alpha<char>();
        //
        for (char symbol = 'a'; symbol <= 'z'; ++symbol)
        {
            auto w = std::string(1, symbol);
            auto s = w.cbegin(), e = w.cend();
            EgoTest_Assert(true == p(s, e).first);
            EgoTest_Assert(p(s,e).second == e);
            EgoTest_Assert(false == p(p(s,e).second, e).first);
        }
        //
        for (char symbol = 'A'; symbol <= 'Z'; ++symbol)
        {
            auto w = std::string(1, symbol);
            auto s = w.cbegin(), e = w.cend();
            EgoTest_Assert(true == p(s, e).first);
            EgoTest_Assert(p(s,e).second == e);
            EgoTest_Assert(false == p(p(s,e).second, e).first);
        }
    }
};

        }
    }
}
