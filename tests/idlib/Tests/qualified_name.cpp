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

namespace id { namespace tests {

EgoTest_TestCase(id_qualified_name)
{
    using string = std::basic_string<char>;

    /// Assert selected strings which are not qualified name strings are rejected.
    EgoTest_Test(qualified_name_exception)
    {
        const std::vector<string> words
        {
			"",
			".",
			".egoboo",
			"org.egoboo.",
            "org.",
        };
        for (const auto& word : words)
        {
			try
			{
				id::qualified_name qualified_name(word);
				EgoTest_Assert(false);
			}
			catch (...)
			{
			}
        }
    }
};

} // namespace tests
} // namespace id
