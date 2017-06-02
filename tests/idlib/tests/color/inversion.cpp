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
#include "idlib/idlib.hpp"

namespace id { namespace tests { namespace color { namespace inversion {

EgoTest_TestCase(lb_inversion)
{
    using color_space = id::Lb;
    using color = id::color<color_space>;

    EgoTest_Test(invert_lb)
    {
        EgoTest_Assert(color::white() == id::invert(color::black()));
        EgoTest_Assert(color::black() == id::invert(color::white()));
    }
};

EgoTest_TestCase(lab_inversion)
{
    using color_space = id::LAb;
    using color = id::color<color_space>;

    using opaque_color_space = id::pure_color_space_t<color_space>;
    using opaque_color = id::color<opaque_color_space>;

    using alpha_color_space = id::Ab;
    using alpha_color = id::color<alpha_color_space>;

    EgoTest_Test(invert_lab)
    {
        EgoTest_Assert(color(opaque_color::black(), alpha_color::transparent()) == id::invert(color::white()));
        EgoTest_Assert(color(opaque_color::white(), alpha_color::transparent()) == id::invert(color::black()));
    }
};

EgoTest_TestCase(rgbb_inversion)
{
    using color_space = id::RGBb;
    using color = id::color<color_space>;

    EgoTest_Test(invert_rgbb)
    {
        EgoTest_Assert(color::black() == id::invert(color::white()));
        EgoTest_Assert(color::white() == id::invert(color::black()));
        EgoTest_Assert(color::cyan() == id::invert(color::red()));
        EgoTest_Assert(color::magenta() == id::invert(color::green()));
        EgoTest_Assert(color::yellow() == id::invert(color::blue()));
        EgoTest_Assert(color::red() == id::invert(color::cyan()));
        EgoTest_Assert(color::green() == id::invert(color::magenta()));
        EgoTest_Assert(color::blue() == id::invert(color::yellow()));
    }
};

EgoTest_TestCase(rgbab_inversion)
{
    using color_space = id::RGBAb;
    using color = id::color<color_space>;

    using opaque_color_space = id::pure_color_space_t<color_space>;
    using opaque_color = id::color<opaque_color_space>;

    using alpha_color_space = id::Ab;
    using alpha_color = id::color<alpha_color_space>;

    EgoTest_Test(invert_rgbab)
    {
        EgoTest_Assert(color(opaque_color::black(), alpha_color::transparent()) == id::invert(color::white()));
        EgoTest_Assert(color(opaque_color::white(), alpha_color::transparent()) == id::invert(color::black()));
        EgoTest_Assert(color(opaque_color::cyan(), alpha_color::transparent()) == id::invert(color::red()));
        EgoTest_Assert(color(opaque_color::magenta(), alpha_color::transparent()) == id::invert(color::green()));
        EgoTest_Assert(color(opaque_color::yellow(), alpha_color::transparent()) == id::invert(color::blue()));
        EgoTest_Assert(color(opaque_color::red(), alpha_color::transparent()) == id::invert(color::cyan()));
        EgoTest_Assert(color(opaque_color::green(), alpha_color::transparent()) == id::invert(color::magenta()));
        EgoTest_Assert(color(opaque_color::blue(), alpha_color::transparent()) == id::invert(color::yellow()));
    }
};

} } } } // namespace id::tests::color::inversion
