/// @file idlib/parsing_expressions/sym.hpp
/// @brief "symbol" parsing expression.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/parsing_expressions/include.hpp` instead)
#endif

#include "idlib/Platform.hpp"

namespace id {
namespace parsing_expressions {

/// @internal
/// @brief Parsing expression accepting a symbol.
/// @tparam Sym the symbol type
template <typename Sym>
struct sym_expr
{
private:
    /// @internal
    /// @brief The symbol.
    Sym m_x;

public:
    /// @internal
    /// @brief Construct this parsing expression.
    /// @param x the symbol
    sym_expr(Sym x) :
        m_x(x)
    {}

    template <typename It>
    bool operator()(It& at, It& end) const
    {
        if (at == end) return false;
        if (m_x == *at)
        {
            ++at;
            return true;
        }
        return false;
    }
};

/// @brief Create a parsing expression accepting a symbol.
/// @tparam Sym the symbol type
/// @param sym the symbol
/// @return the parsing expression
template <typename Sym>
sym_expr<Sym> sym(Sym sym)
{
    return sym_expr<Sym>(sym);
}

} // namespace parsing_expressions
} // namespace id
