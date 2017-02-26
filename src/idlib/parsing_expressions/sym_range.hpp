/// @file idlib/parsing_expressions/sym_range.hpp
/// @brief "range" parsing expression.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/parsing_expressions/include.hpp` instead)
#endif

#include "idlib/Platform.hpp"

namespace id {
namespace parsing_expressions {

/// @internal
/// @brief Parsing expression accepting a range of symbols.
/// @tparam the symbol type
template <typename Sym>
struct sym_range_expr
{
private:
    /// @internal
    /// @brief The first symbol (incl.).
    Sym m_first;

    /// @internal
    /// @brief The last symbol (incl.).
    Sym m_last;

public:
    /// @internal
    /// @brief Construct this parsing expression.
    /// @param first the first symbol (incl.)
    /// @param last the last symbol (incl.)
    sym_range_expr(Sym first, Sym last) :
        m_first(first), m_last(last)
    {}

    template <typename It>
    bool operator()(It& current, It& end) const
    {
        if (current == end) return false;
        if (m_first <= *current && *current <= m_last)
        {
            current++;
            return true;
        }
        return false;
    }
};

/// @brief Create a parsing expression accepting a range of symbols.
/// @tparam Sym the symbol type
/// @param first the first symbol (incl.)
/// @param last the last symbol (incl.)
/// @return the parsing expression
template <typename Sym>
sym_range_expr<Sym> sym_range(Sym first, Sym last)
{
    return sym_range_expr<Sym>(first, last);
}

} // namespace parsing_expressions
} // namespace id
