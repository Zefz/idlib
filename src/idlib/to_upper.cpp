/// @file idlib/to_upper.cpp
/// @brief Explicit template instantiations.
/// @author Michael Heilmann

#include "idlib/to_upper.hpp"

namespace id {

template void to_upper_in_situ<char>(char& x, const std::locale& lc);
template void to_upper_in_situ<wchar_t>(wchar_t& x, const std::locale& lc);

template char to_upper<char>(char x, const std::locale& lc);
template wchar_t to_upper<wchar_t>(wchar_t x, const std::locale& lc);

template void to_upper_in_situ<char>(std::basic_string<char>& w, const std::locale& lc);
template void to_upper_in_situ<wchar_t>(std::basic_string<wchar_t>& w, const std::locale& lc);

template std::basic_string<char> to_upper<char>(std::basic_string<char> w, const std::locale& lc);
template std::basic_string<wchar_t> to_upper<wchar_t>(std::basic_string<wchar_t> w, const std::locale& lc);

} // namespace id
