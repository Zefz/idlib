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
#include "idlib/math/Dimensionality.hpp"
#include "idlib/math/even_odd.hpp"
#include "idlib/math/one_zero.hpp"
#include <limits>

namespace id { namespace tests {

EgoTest_TestCase(dimensionality_testing)
{
    EgoTest_Test(test_dimensionality)
    {
        EgoTest_Assert(false == id::is_dimensionality<0>::value);
        EgoTest_Assert(false == id::is_dimensionality_v<0>);
        EgoTest_Assert(true == id::is_dimensionality<1>::value);
        EgoTest_Assert(true == id::is_dimensionality_v<1>);
        EgoTest_Assert(true == id::is_dimensionality<std::numeric_limits<size_t>::max()>::value);
        EgoTest_Assert(true == id::is_dimensionality_v<std::numeric_limits<size_t>::max()>);
    }
};

EgoTest_TestCase(one_zero_type_checking)
{
    EgoTest_Test(type_check_one_zero)
    {
        static_assert(std::is_same<decltype(id::zero<signed short>()), signed short>::value, "");
        static_assert(std::is_same<decltype(id::zero<unsigned short>()), unsigned short>::value, "");
        static_assert(std::is_same<decltype(id::zero<signed int>()), signed int>::value, "");
        static_assert(std::is_same<decltype(id::zero<unsigned int>()), unsigned int>::value, "");
        static_assert(std::is_same<decltype(id::zero<signed long>()), signed long>::value, "");
        static_assert(std::is_same<decltype(id::zero<unsigned long>()), unsigned long>::value, "");
        static_assert(std::is_same<decltype(id::zero<signed long long>()), signed long long>::value, "");
        static_assert(std::is_same<decltype(id::zero<unsigned long long>()), unsigned long long>::value, "");
        static_assert(std::is_same<decltype(id::zero<float>()), float>::value, "");
        static_assert(std::is_same<decltype(id::zero<double>()), double>::value, "");

        static_assert(std::is_same<decltype(id::one<signed short>()), signed short>::value, "");
        static_assert(std::is_same<decltype(id::one<unsigned short>()), unsigned short>::value, "");
        static_assert(std::is_same<decltype(id::one<signed int>()), signed int>::value, "");
        static_assert(std::is_same<decltype(id::one<unsigned int>()), unsigned int>::value, "");
        static_assert(std::is_same<decltype(id::one<signed long>()), signed long>::value, "");
        static_assert(std::is_same<decltype(id::one<unsigned long>()), unsigned long>::value, "");
        static_assert(std::is_same<decltype(id::one<signed long long>()), signed long long>::value, "");
        static_assert(std::is_same<decltype(id::one<unsigned long long>()), unsigned long long>::value, "");
        static_assert(std::is_same<decltype(id::one<float>()), float>::value, "");
        static_assert(std::is_same<decltype(id::one<double>()), double>::value, "");
    }
};

} // namespace tests
} // namespace id
