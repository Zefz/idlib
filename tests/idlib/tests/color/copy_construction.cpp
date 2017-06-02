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

namespace copy_construction {

EgoTest_TestCase(copy_construction_lb_lb)
{
    EgoTest_Test(copy_construct_lb_lb)
    {
        id::color<id::Lb> x;
        auto y = id::color<id::Lb>(x);
        EgoTest_Assert(x == y);
    }
};

EgoTest_TestCase(copy_construction_lf_lf)
{
    EgoTest_Test(copy_construct_lf_lf)
    {
        id::color<id::Lf> x;
        auto y = id::color<id::Lf>(x);
        EgoTest_Assert(x == y);
    }
};

EgoTest_TestCase(copy_construction_lab_lab)
{
    EgoTest_Test(copy_construct_lab_lab)
    {
        id::color<id::LAb> x;
        auto y = id::color<id::LAb>(x);
        EgoTest_Assert(x == y);
    }
};

EgoTest_TestCase(copy_construction_laf_laf)
{
    EgoTest_Test(copy_construct_laf_laf)
    {
        id::color<id::LAf> x;
        auto y = id::color<id::LAf>(x);
        EgoTest_Assert(x == y);
    }
};

EgoTest_TestCase(copy_construction_rgbb_rgbb)
{
    EgoTest_Test(copy_construct_rgbb_rgbb)
    {
        id::color<id::RGBb> x;
        auto y = id::color<id::RGBb>(x);
        EgoTest_Assert(x == y);
    }
};

EgoTest_TestCase(copy_construction_rgbf_rgbf)
{
    EgoTest_Test(copy_construct_rgbf_rgbf)
    {
        id::color<id::RGBf> x;
        auto y = id::color<id::RGBf>(x);
        EgoTest_Assert(x == y);
    }
};

EgoTest_TestCase(copy_construction_rgbab_rgbab)
{
    EgoTest_Test(copy_construct_rgbab_rgbab)
    {
        id::color<id::RGBAb> x;
        auto y = id::color<id::RGBAb>(x);
        EgoTest_Assert(x == y);
    }
};

EgoTest_TestCase(copy_construction_rgbaf_rgbaf)
{
    EgoTest_Test(copy_construct_rgbaf_rgbaf)
    {
        id::color<id::RGBAf> x;
        auto y = id::color<id::RGBAf>(x);
        EgoTest_Assert(x == y);
    }
};

} // namespace copy_construction

} } } // namespace id::tests::color
