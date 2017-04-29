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
#include "idlib/idlib.hpp"

namespace id {
namespace tests {

EgoTest_TestCase(color_lf_interpolation_functor)
{
    using color = id::color<id::Lf>;
    using interpolation_functor = id::interpolation_functor<id::color<id::Lf>, id::interpolation_method::LINEAR>;

    static void test(const color& x, const color& y)
    {
        static const interpolation_functor f{};
        EgoTest_Assert(x == f(x, y, 0.0f));
        EgoTest_Assert(y == f(x, y, 1.0f));
    }

    EgoTest_Test(test)
    {
        test(color::black(), color::black());
        test(color::black(), color::white());
        test(color::white(), color::black());
        test(color::white(), color::white());
    }
};

EgoTest_TestCase(color_laf_interpolation_functor)
{
    using color = id::color<id::Lf>;
    using interpolation_functor = id::interpolation_functor<id::color<id::Lf>, id::interpolation_method::LINEAR>;

    static void test(const color& x, const color& y)
    {
        static const interpolation_functor f{};
        EgoTest_Assert(x == f(x, y, 0.0f));
        EgoTest_Assert(y == f(x, y, 1.0f));
    }

    EgoTest_Test(test)
    {
        test(color::black(), color::black());
        test(color::black(), color::white());
        test(color::white(), color::black());
        test(color::white(), color::white());
    }
};

EgoTest_TestCase(color_rgbf_interpolation_functor)
{
    using color = id::color<id::RGBf>;
    using interpolation_functor = id::interpolation_functor<id::color<id::RGBf>, id::interpolation_method::LINEAR>;
    static void test(const color& x, const color& y)
    {
        static const interpolation_functor f{};
        EgoTest_Assert(x == f(x, y, 0.0f));
        EgoTest_Assert(y == f(x, y, 1.0f));
    }

    EgoTest_Test(test)
    {
        test(color::red(), color::red());
        test(color::red(), color::green());
        test(color::red(), color::blue());

        test(color::green(), color::green());
        test(color::green(), color::blue());
        test(color::green(), color::red());

        test(color::blue(), color::blue());
        test(color::blue(), color::green());
        test(color::blue(), color::red());
    }
};

EgoTest_TestCase(color_rgbaf_interpolation_functor)
{
    using color = id::color<id::RGBAf>;
    using interpolation_functor = id::interpolation_functor<id::color<id::RGBAf>, id::interpolation_method::LINEAR>;

    static void test(const color& x, const color& y)
    {
        static const interpolation_functor f{};
        EgoTest_Assert(x == f(x, y, 0.0f));
        EgoTest_Assert(y == f(x, y, 1.0f));
    }

    EgoTest_Test(test)
    {
        test(color::red(), color::red());
        test(color::red(), color::green());
        test(color::red(), color::blue());

        test(color::green(), color::green());
        test(color::green(), color::blue());
        test(color::green(), color::red());

        test(color::blue(), color::blue());
        test(color::blue(), color::green());
        test(color::blue(), color::red());
    }
};

EgoTest_TestCase(color)
{

    EgoTest_Test(Lb_Lb)
    {
        id::color<id::Lb> x;
        auto y = id::color<id::Lb>(x);
        EgoTest_Assert(x == y);
    }

    EgoTest_Test(Lf_Lf)
    {
        id::color<id::Lf> x;
        auto y = id::color<id::Lf>(x);
        EgoTest_Assert(x == y);
    }

    EgoTest_Test(LAb_LAb)
    {
        id::color<id::LAb> x;
        auto y = id::color<id::LAb>(x);
        EgoTest_Assert(x == y);
    }

    EgoTest_Test(LAf_LAf)
    {
        id::color<id::LAf> x;
        auto y = id::color<id::LAf>(x);
        EgoTest_Assert(x == y);
    }

    EgoTest_Test(RGBb_RGBb)
    {
        id::color<id::RGBb> x;
        auto y = id::color<id::RGBb>(x);
        EgoTest_Assert(x == y);
    }

    EgoTest_Test(RGBf_RGBf)
    {
        id::color<id::RGBf> x;
        auto y = id::color<id::RGBf>(x);
        EgoTest_Assert(x == y);
    }

    EgoTest_Test(RGBAb_RGBAb)
    {
        id::color<id::RGBAb> x;
        auto y = id::color<id::RGBAb>(x);
        EgoTest_Assert(x == y);
    }

    EgoTest_Test(RGBAf_RGBAf)
    {
        id::color<id::RGBAf> x;
        auto y = id::color<id::RGBAf>(x);
        EgoTest_Assert(x == y);
    }
};

} // namespace tests
} // namespaces id
