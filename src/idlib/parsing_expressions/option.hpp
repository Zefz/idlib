/// @file idlib/parsing_expressions/sym.hpp
/// @brief "symbol" parsing expression.
/// @author Michael Heilmann

#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/parsing_expressions/include.hpp` instead)
#endif

#include "idlib/platform.hpp"

namespace id {
namespace parsing_expressions {

/// @internal
/// @brief See id::option for more information.
/// @tparam Sym the symbol type
/// @tparam Expr the expression type
template <typename Sym, typename Expr>
struct option_expr
{
private:
    /// @internal
    /// @brief The parsing expression.
    Expr m_expr;

public:
    /// @internal
    /// @brief Construct this parsing expression.
    /// @param expr the expression
    option_expr(Expr expr) :
        m_expr(expr)
    {}

    template <typename It>
    bool operator()(It& at, It& end) const
    {
        auto old_at = at;
        if (m_expr(at, end))
        {
            return true;
        }
        at = old_at;
        return false;
    }
};

/// @brief Create an option of a parsing expression.
/// The option of a parsing expression accepts regardless of wether the parsing expression acccepts.
/// @detail That is, the @a option of a parsing expressions @code{e}
/// is defined as
/// @code{repetition(e) = e?}.
/// @tparam Sym the symbol type
/// @tparam Expr the type of the expression
/// @param expr the expression
/// @return the parsing expression
template <typename Sym, typename Expr>
option_expr<Sym, Expr> option(Expr&& expr)
{
    return option_expr<Sym, Expr>(std::forward<Expr>(expr));
}

} // namespace parsing_expressions
} // namespace id
