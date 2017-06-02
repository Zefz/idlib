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

namespace id { namespace tests { namespace file_system {

EgoTest_TestCase(access_mode_test)
{
    EgoTest_Test(test_access_mode)
    {
        using namespace id::file_system;
        // Negation.
        EgoTest_Assert(~access_mode::all == access_mode::none);
        EgoTest_Assert(~access_mode::none == access_mode::all);
        EgoTest_Assert(~access_mode::write == access_mode::read);
        EgoTest_Assert(~access_mode::read == access_mode::write);
        // Equality. 
        EgoTest_Assert(access_mode::none == access_mode::none);
        EgoTest_Assert(access_mode::read == access_mode::read);
        EgoTest_Assert(access_mode::write == access_mode::write);
        EgoTest_Assert(access_mode::all == access_mode::all);
        // Inequality.
        EgoTest_Assert(access_mode::all != access_mode::none);
        EgoTest_Assert(access_mode::read != access_mode::write);
        EgoTest_Assert(access_mode::write != access_mode::read);
        EgoTest_Assert(access_mode::write != access_mode::none);
        // ...
        //
        EgoTest_Assert((access_mode::write | access_mode::read) == access_mode::read_write);
        EgoTest_Assert((access_mode::read | access_mode::write) == access_mode::read_write);
        // Aliases.
        EgoTest_Assert(access_mode::write_read == access_mode::read_write);
        //
        EgoTest_Assert((access_mode::read_write & access_mode::read) == access_mode::read);
        EgoTest_Assert((access_mode::read_write & access_mode::write) == access_mode::write);
        //
        EgoTest_Assert((access_mode::write & access_mode::read) == access_mode::none);
        EgoTest_Assert((access_mode::read & access_mode::write) == access_mode::none);
        //
        EgoTest_Assert((access_mode::read & access_mode::read) == access_mode::read);
        EgoTest_Assert((access_mode::write & access_mode::write) == access_mode::write);
    }
};

} } } // namespace id::tests::file_system
