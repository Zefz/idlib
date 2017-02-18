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
#include "IdLib/Math/Dimensionality.hpp"
#include <limits>

EgoTest_TestCase(Concepts)
{
    EgoTest_Test(dimensionality)
    {
        EgoTest_Assert(false == id::is_dimensionality<0>::value);
        EgoTest_Assert(false == id::is_dimensionality_v<0>);
        EgoTest_Assert(true == id::is_dimensionality<1>::value);
        EgoTest_Assert(true == id::is_dimensionality_v<1>);
        EgoTest_Assert(true == id::is_dimensionality<std::numeric_limits<size_t>::max()>::value);
        EgoTest_Assert(true == id::is_dimensionality_v<std::numeric_limits<size_t>::max()>);
    }
};
