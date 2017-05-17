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

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/idlib.hpp` instead)
#endif

#include "idlib/language/location.hpp"

#define ID_TOKEN_WITH_ENDLOCATION (0)

namespace id {

/// @brief Generic token.
/// @tparam Kind the type of the kinds of this token type.
template <typename Kind>
class token	
{
private:
	/// @brief The kind of this token.
	Kind m_kind;

	/// @brief The start location of this token.
	location m_start_location;

#if defined(ID_TOKEN_WITH_END_LOCATION) && 1 == ID_TOKEN_WITH_END_LOCATION
    /// @brief The end location of this token.
    location m_end_location;
#endif

	/// @brief The lexeme of this token.
	std::string m_lexeme;

public:
	/// @brief Construct this token with the specified values.
	/// @param kind the kind of this token
	/// @param start_location the start location of this token
    /// @param end_location the end location of this token
	/// @param lexeme the lexeme of this token. Default is the empty string.
	token(Kind kind, const id::location& start_location,
      #if defined(ID_TOKEN_WITH_END_LOCATION) && 1 == ID_TOKEN_WITH_END_LOCATION  
          const Location& end_location,
      #endif
          const std::string& lexeme = std::string())
		: m_kind(kind),
          m_start_location(start_location),
    #if defined(ID_TOKEN_WITH_END_LOCATION) && 1 == ID_TOKEN_WITH_END_LOCATION  
          m_end_location(end_location),
    #endif
          m_lexeme(lexeme)
	{
		/* Intentionally empty. */
	}
	
	/// @brief Copy-Construct this token from another token.
	/// @param other the other token
	token(const token& other)
		: m_kind(other.get_kind()),
          m_start_location(other.get_start_location()),
    #if defined(ID_TOKEN_WITH_END_LOCATION) && 1 == ID_TOKEN_WITH_END_LOCATION
          m_end_location(other.get_end_location()),
    #endif
          m_lexeme(other.get_lexeme())
	{
		/* Intentionally empty. */
	}

    /// @brief Move-construct this token from another token.
    /// @param other the other token
    token(token&& other)
        : m_kind(std::move(other.get_kind())),
          m_start_location(std::move(other.m_start_location)),
    #if defined(ID_TOKEN_WITH_END_LOCATION) && 1 == ID_TOKEN_WITH_END_LOCATION
          m_end_location(std::move(other.m_end_location)),
    #endif
          m_lexeme(std::move(other.m_lexeme))
    {}

    /// @brief Assign this token from another token.
    /// @param other the other token
    /// @return this token
    token& operator=(token other)
    {
        swap(*this, other);
        return *this;
    }

    friend void swap(token& x, token& y)
    {
        std::swap(x.m_kind, y.m_kind);
        std::swap(x.m_start_location, y.m_start_location);
    #if defined(ID_TOKEN_WITH_END_LOCATION) && 1 == ID_TOKEN_WITH_END_LOCATION
        std::swap(x.m_end_location, y.m_end_locatation);
    #endif
        std::swap(x.m_lexeme, y.m_lexeme);
    }
	
public:
	/// @brief Get the kind of this token.
	/// @return the kind of this token
	const Kind& get_kind() const
	{
		return m_kind;
	}
	
	/// @brief Set the kind of this token.
	/// @param kind the kind of this token
	void set_kind(const Kind& kind)
	{
		m_kind = kind;
	}

#if defined(ID_TOKEN_WITH_END_LOCATION) && 1 == ID_TOKEN_WITH_END_LOCATION
    /// @brief @brief Get the end location of this token.
    /// @return the end location of this token
    /// @see set_end_location
    /// @remark The end location is the location at which the lexeme of this token ends at.
    const location& get_end_location() const
    {
        return m_endLocation;
    }

    /// @brief Set the end location of this token.
    /// @param endLocation the end location of this token
    /// @see get_end_location
    void set_end_location(const location& end_location)
    {
        m_end_location = end_location;
    }
#endif

	/// @brief @brief Get the start location of this token.
	/// @return the start location of this token
    /// @see set_start_location
    /// @remark The start location is the location at which the lexeme of this token starts at.
	const location& get_start_location() const
	{
		return m_start_location;
	}
	
	/// @brief Set the start location of this token.
	/// @param start_location the start location of this token
    /// @see get_start_Location
	void set_start_location(const location& start_location)
	{
		m_start_location = start_location;
	}

	/// @brief Get the lexeme of this token.
	/// @return the lexeme of this token
    /// @see set_lexeme
	const std::string& get_lexeme() const
	{
		return m_lexeme;
	}
	
	/// @brief Set the lexeme of this token.
	/// @param lexeme the lexeme of this token
    /// @see getLexeme
	void set_lexeme(const std::string& lexeme)
	{
		m_lexeme = lexeme;
	}
	
public:
    /// @brief Get if this token is of the given kind.
    /// @param kind the kind
    /// @return @a true if this token is of the given kind @a kind, @a false otherwise
    bool is(const Kind& kind) const
	{
		return kind == get_kind();
	}

    /// @brief Get if this token is of the given kinds.
    /// @param kind1, kind2 the kinds
    /// @return @a true if this token is of the kinds @a kind1 or @a kind2, @a false otherwise
    bool is_one_of(const Kind& kind1, const Kind& kind2) const
	{
		return is(kind1) || is(kind2);
	}

    /// @brief Get if this token is of the given kinds.
    /// @param kind1, kind2, kinds the types
    /// @return @a true if this token is of the given kinds @a kind1, @a kind2, or @a kinds, @a false otherwise
    template <typename ... Kinds>
    bool is_one_of(const Kind& kind1, const Kind& kind2, Kinds ... kinds) const
    {
        return is(kind1) || is_one_of(kind2, kinds ...);
    }

}; // class token

} // namespace id
