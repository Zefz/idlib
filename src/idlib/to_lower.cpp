/// @file idlib/to_lower.cpp
/// @brief Explicit template instantiations.
/// @author Michael Heilmann

#include "idlib/to_lower.hpp"

namespace id {

template void to_lower_in_situ<char>(char& x, const std::locale& lc);
template void to_lower_in_situ<wchar_t>(wchar_t& x, const std::locale& lc);

template char to_lower<char>(char x, const std::locale& lc);
template wchar_t to_lower<wchar_t>(wchar_t x, const std::locale& lc);

template void to_lower_in_situ<char>(std::basic_string<char>& w, const std::locale& lc);
template void to_lower_in_situ<wchar_t>(std::basic_string<wchar_t>& w, const std::locale& lc);

template std::basic_string<char> to_lower<char>(std::basic_string<char> w, const std::locale& lc);
template std::basic_string<wchar_t> to_lower<wchar_t>(std::basic_string<wchar_t> w, const std::locale& lc);

} // namespace id
