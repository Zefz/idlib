/// @file idlib/prefix.cpp
/// @brief Explicit template instantiations.
/// @author Michael Heilmann

#include "idlib/prefix.hpp"

namespace id {

template bool is_prefix<char>(const std::basic_string<char>& w, const std::basic_string<char>& v);
template bool is_prefix<wchar_t>(const std::basic_string<wchar_t>& w, const std::basic_string<wchar_t>& v);

template bool is_true_prefix<char>(const std::basic_string<char>& w, const std::basic_string<char>& v);
template bool is_true_prefix<wchar_t>(const std::basic_string<wchar_t>& w, const std::basic_string<wchar_t>& v);

} // namespace id
