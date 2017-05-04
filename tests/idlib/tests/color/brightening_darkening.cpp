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
#include "idlib/Tests/color/color_generator.hpp"

namespace id::tests::color::brightening_darkening {

template <typename S, typename E = void>
struct basic_test1;

template <typename S>
struct basic_test1<S,std::enable_if_t<id::is_any_of<S, id::Lb, id::Lf, id::LAb, id::LAf, id::RGBb, id::RGBf, id::RGBAb, id::RGBAf>::value>>
{
    void operator()() const
    {
        using C = id::color<S>;
        static const std::vector<C> colors = color_generator<S>()();
        for (const auto& color : colors)
        {
            // darken(c,0) = c (1 - 0) = c
            // brighten(c,0) = c (1 + 0) = c
            EgoTest_Assert(color == id::darken(color, 0.0f));
            EgoTest_Assert(color == id::darken(color, 0.0));
            EgoTest_Assert(color == id::brighten(color, 0.0f));
            EgoTest_Assert(color == id::brighten(color, 0.0));
            // darken(c,-1) = c (1 - (-1)) = 2c
            // brighten(c,+1) = c (1 + (+1)) = 2c
            EgoTest_Assert(id::darken(color, -1.0) == id::brighten(color, +1.0));
            EgoTest_Assert(id::darken(color, -1.0f) == id::brighten(color, +1.0f));
            // darken(c,+2) = c (1 - (+2)) = -1c
            // brighten(c,-2) c (1 + (-2)) = -1c
            EgoTest_Assert(id::darken(color, +1.0) == id::brighten(color, -1.0));
            EgoTest_Assert(id::darken(color, +1.0f) == id::brighten(color, -1.0f));
        }
    }
};

EgoTest_TestCase(brightening_darkening_lf)
{
    EgoTest_Test(brighten_darken_lf)
    {
        basic_test1<id::Lf>()();
    }
};

EgoTest_TestCase(brightening_darkening_lb)
{
    EgoTest_Test(brighten_darken_lb)
    {
        basic_test1<id::Lb>()();
    }
};

EgoTest_TestCase(brightening_darkening_laf)
{
    EgoTest_Test(brighten_darken_laf)
    {
        basic_test1<id::LAf>()();
    }
};

EgoTest_TestCase(brightening_darkening_lab)
{
    EgoTest_Test(brighten_darken_lab)
    {
        basic_test1<id::LAb>()();
    }
};

EgoTest_TestCase(brightening_darkening_rgbf)
{
    EgoTest_Test(brighten_darken_rgbf)
    {
        basic_test1<id::RGBf>()();
    }
};

EgoTest_TestCase(brightening_darkening_rgbb)
{
    EgoTest_Test(brighten_darken_rgbb)
    {
        basic_test1<id::RGBb>()();
    }
};

EgoTest_TestCase(brightening_darkening_rgbaf)
{
    EgoTest_Test(brighten_darken_rgbaf)
    {
        basic_test1<id::RGBAf>()();
    }
};

EgoTest_TestCase(brightening_darkening_rgbab)
{
    EgoTest_Test(brighten_darken_rgbab)
    {
        basic_test1<id::RGBAb>()();
    }
};

} // namespace id::tests::color::brightening_darkening
