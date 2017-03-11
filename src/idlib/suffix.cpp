/// @file idlib/suffix.cpp
/// @brief Explicit template instantiations.
/// @author Michael Heilmann

#include "idlib/suffix.hpp"

namespace id {

template bool is_suffix<char>(const std::basic_string<char>& w, const std::basic_string<char>& v);
template bool is_suffix<wchar_t>(const std::basic_string<wchar_t>& w, const std::basic_string<wchar_t>& v);

template bool is_true_suffix<char>(const std::basic_string<char>& w, const std::basic_string<char>& v);
template bool is_true_suffix<wchar_t>(const std::basic_string<wchar_t>& w, const std::basic_string<wchar_t>& v);

} // namespace id
