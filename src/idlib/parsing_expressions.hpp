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

/// @file idlib/parsing_expressions.hpp
/// @brief Master include file of the Idlib parsing expressions library.
/// @author Michael Heilmann

#pragma once

#pragma push_macro("IDLIB_PRIVATE")
#undef IDLIB_PRIVATE
#define IDLIB_PRIVATE (1)

#include "idlib/parsing_expressions/any_sym.hpp"
#include "idlib/parsing_expressions/difference.hpp"
#include "idlib/parsing_expressions/sym.hpp"
#include "idlib/parsing_expressions/sym_range.hpp"
#include "idlib/parsing_expressions/ordered_choice.hpp"
#include "idlib/parsing_expressions/option.hpp"
#include "idlib/parsing_expressions/sequence.hpp"
#include "idlib/parsing_expressions/repetition.hpp"
#include "idlib/parsing_expressions/end_of_input.hpp"

#include "idlib/parsing_expressions/action.hpp"

#include "idlib/parsing_expressions/parse.hpp"

#include "idlib/parsing_expressions/predefined.hpp"

#undef IDLIB_PRIVATE
#pragma pop_macro("IDLIB_PRIVATE")
