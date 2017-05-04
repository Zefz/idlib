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

namespace id::tests::color::addition_subtraction {

EgoTest_TestCase(addition_subtraction_ab)
{
    using color = id::color<id::Ab>;
    EgoTest_Test(add_subtract_ab)
    {
        color::transparent() + color::transparent();
        color::transparent() + color::opaque();
        color::opaque() + color::transparent();
        color::opaque() + color::opaque();
        color::transparent() - color::transparent();
        color::transparent() - color::opaque();
        color::opaque() - color::transparent();
        color::opaque() - color::opaque();
    }
};

EgoTest_TestCase(addition_subtraction_af)
{
    using color = id::color<id::Af>;
    EgoTest_Test(add_subtract_af)
    {
        color::transparent() + color::transparent();
        color::transparent() + color::opaque();
        color::opaque() + color::transparent();
        color::opaque() + color::opaque();
        color::transparent() - color::transparent();
        color::transparent() - color::opaque();
        color::opaque() - color::transparent();
        color::opaque() - color::opaque();
    }
};


EgoTest_TestCase(addition_subtraction_lb)
{
    using color = id::color<id::Lb>;
    EgoTest_Test(add_subtract_lb)
    {
        color::black() + color::black();
        color::black() + color::white();
        color::white() + color::black();
        color::white() + color::white();
        color::black() - color::black();
        color::black() - color::white();
        color::white() - color::black();
        color::white() - color::white();
    }
};

EgoTest_TestCase(addition_subtraction_lf)
{
    using color = id::color<id::Lf>;
    EgoTest_Test(add_subtract_lf)
    {
        color::black() + color::black();
        color::black() + color::white();
        color::white() + color::black();
        color::white() + color::white();
        color::black() - color::black();
        color::black() - color::white();
        color::white() - color::black();
        color::white() - color::white();
    }
};

EgoTest_TestCase(addition_subtraction_lab)
{
    using color = id::color<id::LAb>;
    EgoTest_Test(add_subtract_lab)
    {
        color::black() + color::black();
        color::black() + color::white();
        color::white() + color::black();
        color::white() + color::white();
        color::black() - color::black();
        color::black() - color::white();
        color::white() - color::black();
        color::white() - color::white();
    }
};

EgoTest_TestCase(addition_subtraction_laf)
{
    using color = id::color<id::LAf>;
    EgoTest_Test(add_subtract_laf)
    {
        color::black() + color::black();
        color::black() + color::white();
        color::white() + color::black();
        color::white() + color::white();
        color::black() - color::black();
        color::black() - color::white();
        color::white() - color::black();
        color::white() - color::white();
    }
};

EgoTest_TestCase(addition_subtraction_rgbb)
{
    using color = id::color<id::RGBAf>;
    EgoTest_Test(add_subtract_rgbb)
    {
        color::black() + color::black();
        color::black() + color::white();
        color::white() + color::black();
        color::white() + color::white();
        color::black() - color::black();
        color::black() - color::white();
        color::white() - color::black();
        color::white() - color::white();
    }
};

EgoTest_TestCase(addition_subtraction_rgbf)
{
    using color = id::color<id::RGBf>;
    EgoTest_Test(add_subtract_rgbf)
    {
        color::black() + color::black();
        color::black() + color::white();
        color::white() + color::black();
        color::white() + color::white();
        color::black() - color::black();
        color::black() - color::white();
        color::white() - color::black();
        color::white() - color::white();
    }
};

EgoTest_TestCase(addition_subtraction_rgbab)
{
    using color = id::color<id::RGBAb>;
    EgoTest_Test(add_subtract_rgbab)
    {
        color::black() + color::black();
        color::black() + color::white();
        color::white() + color::black();
        color::white() + color::white();
        color::black() - color::black();
        color::black() - color::white();
        color::white() - color::black();
        color::white() - color::white();
    }
};

EgoTest_TestCase(addition_subtraction_rgbaf)
{
    using color = id::color<id::RGBAf>;
    EgoTest_Test(add_subtract_rgbaf)
    {
        color::black() + color::black();
        color::black() + color::white();
        color::white() + color::black();
        color::white() + color::white();
        color::black() - color::black();
        color::black() - color::white();
        color::white() - color::black();
        color::white() - color::white();
    }
};

} // namespace id::tests::color::addition_subtraction
