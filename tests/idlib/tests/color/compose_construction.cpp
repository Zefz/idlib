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

namespace id { namespace tests { namespace color {

namespace compose_construction {

EgoTest_TestCase(compose_construction_rgbb_lb)
{
    EgoTest_Test(compose_construct_rgbb_lb)
    {
        using source = id::color<id::Lb>;
        using target = id::color<id::RGBb>;
        EgoTest_Assert(target::white() == target(source::white()));
        EgoTest_Assert(target::black() == target(source::black()));
    }
};

EgoTest_TestCase(compose_construction_rgbf_lf)
{
    EgoTest_Test(compose_construct_rgbf_Lf)
    {
        using source = id::color<id::Lf>;
        using target = id::color<id::RGBf>;
        EgoTest_Assert(target::white() == target(source::white()));
        EgoTest_Assert(target::black() == target(source::black()));
    }
};

EgoTest_TestCase(compose_construction_rgbab_lab)
{
    EgoTest_Test(compose_construct_rgbab_lab)
    {
        using source = id::color<id::LAb>;
        using target = id::color<id::RGBAb>;
        EgoTest_Assert(target::white() == target(source::white()));
        EgoTest_Assert(target::black() == target(source::black()));
    }
};

EgoTest_TestCase(compose_construction_rgbaf_laf)
{
    EgoTest_Test(compose_construct_rgbaf_laf)
    {
        using source = id::color<id::LAf>;
        using target = id::color<id::RGBAf>;
        EgoTest_Assert(target::white() == target(source::white()));
        EgoTest_Assert(target::black() == target(source::black()));
    }
};

} // namespace compose_construction

namespace compose_construction {

EgoTest_TestCase(compose_construction_lab_lb_ab)
{
    EgoTest_Test(compose_construct_lab_lb_ab)
    {
        using color_space = id::LAb;
        using color = id::color<color_space>;

        using pure_color_space = id::pure_color_space_t<color_space>;
        using pure_color = id::color<pure_color_space>;

        using pure_opacity_space = id::pure_opacity_space_t<color_space>;
        using pure_opacity = id::color<pure_opacity_space>;

        EgoTest_Assert(color(pure_color::white(), pure_opacity::opaque()) == color::white());
        EgoTest_Assert(color(pure_color::black(), pure_opacity::opaque()) == color::black());
        EgoTest_Assert(color(pure_color::grey(), pure_opacity::opaque()) == color::grey());
    }

    EgoTest_Test(compose_construct_rgbab_rgbb_ab)
    {
        using color_space = id::RGBAb;
        using color = id::color<color_space>;

        using pure_color_space = id::pure_color_space_t<color_space>;
        using pure_color = id::color<pure_color_space>;

        using pure_opacity_space = id::pure_opacity_space_t<color_space>;
        using pure_opacity = id::color<pure_opacity_space>;

        EgoTest_Assert(color(pure_color::white(), pure_opacity::opaque()) == color::white());
        EgoTest_Assert(color(pure_color::black(), pure_opacity::opaque()) == color::black());
        EgoTest_Assert(color(pure_color::red(), pure_opacity::opaque()) == color::red());
        EgoTest_Assert(color(pure_color::green(), pure_opacity::opaque()) == color::green());
        EgoTest_Assert(color(pure_color::blue(), pure_opacity::opaque()) == color::blue());
        EgoTest_Assert(color(pure_color::cyan(), pure_opacity::opaque()) == color::cyan());
        EgoTest_Assert(color(pure_color::magenta(), pure_opacity::opaque()) == color::magenta());
        EgoTest_Assert(color(pure_color::yellow(), pure_opacity::opaque()) == color::yellow());
    }
};

} // namespace compose_construction

} } } // namespace id::tests::color
