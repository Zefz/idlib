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

namespace id { namespace tests { namespace color { namespace interpolation {

EgoTest_TestCase(lf_interpolation)
{
    using color = id::color<id::Lf>;
    using functor = id::interpolation_functor<id::color<id::Lf>, id::interpolation_method::LINEAR>;

    static void test(const color& x, const color& y)
    {
        static const functor f{};
        EgoTest_Assert(x == f(x, y, 0.0f));
        EgoTest_Assert(y == f(x, y, 1.0f));
    }

    EgoTest_Test(interpolate_lf)
    {
        test(color::black(), color::black());
        test(color::black(), color::white());
        test(color::white(), color::black());
        test(color::white(), color::white());
    }
};

EgoTest_TestCase(laf_interpolation)
{
    using color = id::color<id::Lf>;
    using functor = id::interpolation_functor<id::color<id::Lf>, id::interpolation_method::LINEAR>;

    static void test(const color& x, const color& y)
    {
        static const functor f{};
        EgoTest_Assert(x == f(x, y, 0.0f));
        EgoTest_Assert(y == f(x, y, 1.0f));
    }

    EgoTest_Test(interpolate_laf)
    {
        test(color::black(), color::black());
        test(color::black(), color::white());
        test(color::white(), color::black());
        test(color::white(), color::white());
    }
};

EgoTest_TestCase(rgbf_interpolation)
{
    using color = id::color<id::RGBf>;
    using functor = id::interpolation_functor<id::color<id::RGBf>, id::interpolation_method::LINEAR>;
    
    static void test(const color& x, const color& y)
    {
        static const functor f{};
        EgoTest_Assert(x == f(x, y, 0.0f));
        EgoTest_Assert(y == f(x, y, 1.0f));
    }

    EgoTest_Test(interpolate_rgbf)
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

EgoTest_TestCase(rgbaf_interpolation)
{
    using color = id::color<id::RGBAf>;
    using functor = id::interpolation_functor<id::color<id::RGBAf>, id::interpolation_method::LINEAR>;

    static void test(const color& x, const color& y)
    {
        static const functor f{};
        EgoTest_Assert(x == f(x, y, 0.0f));
        EgoTest_Assert(y == f(x, y, 1.0f));
    }

    EgoTest_Test(interpolate_rgbaf)
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

} } } } // namespace id::tests::color::interpolation
