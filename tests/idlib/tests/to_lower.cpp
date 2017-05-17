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

namespace id { namespace tests {

EgoTest_TestCase(lowercase_conversion)
{
    EgoTest_Test(convert_lowercase)
    {
        std::string x("X");
        id::to_lower_in_situ(x);
        EgoTest_Assert(x == "x");
        // Identity.
        id::to_lower_in_situ(x);
        EgoTest_Assert(x == "x");
    }
};

} } // namespace id::tests
