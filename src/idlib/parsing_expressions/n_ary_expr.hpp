#pragma once

#if !defined(IDLIB_PRIVATE) || IDLIB_PRIVATE != 1
#error(do not include directly, include `idlib/parsing_expressions/include.hpp` instead)
#endif

#include "idlib/platform.hpp"

namespace id {
namespace parsing_expressions {

/// @internal
/// @brief An \f$n\f$-ary parsing expression \f$n>0\f$.
/// @param Op the tuple operation
/// @tparam Sym the symbol type
/// @tparam Expr the type of the first expression
/// @tparam Exprs ... the type of the remaining expressions
template <typename Op, typename Sym, typename Expr, typename ... Exprs>
class n_ary_expr
{
protected:
    /// @internal
    /// @brief The parsing expressions.
    std::tuple<Expr, Exprs ...> m_exprs;

public:
    /// @internal
    /// @brief Construct this parsing expression.
    /// @param expr the first expression
    /// @param exprs the remaining expressions
    n_ary_expr(Expr&& expr, Exprs&& ... exprs) :
        m_exprs{std::forward<Expr>(expr), std::forward<Exprs>(exprs) ...}
    {}
};

} // namespace parsing_expressions
} // namespace id
