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

    /// @brief Get the value of the red component.
    /// @return the value of the red component
    const component_r& get_red() const
    { return r; }
#if defined(ID_COLOR_SHORT_GETTERS) && 1 == ID_COLOR_SHORT_GETTERS
    const component_r& get_r() const noexcept
    { return r; }
#endif
    /// @}

    /// @{
    /// @brief Get the value of the green component.
    /// @return the value of the green component
    const component_g& get_green() const noexcept
    { return g; }
#if defined(ID_COLOR_SHORT_GETTERS) && 1 == ID_COLOR_SHORT_GETTERS
    const component_g& get_g() const
    { return g; }
#endif
    /// @}

    /// @{
    /// @brief Get the value of the blue component.
    /// @return the value of the blue component
    const component_b& get_blue() const noexcept
    { return b; }
#if defined(ID_COLOR_SHORT_GETTERS) && 1 == ID_COLOR_SHORT_GETTERS
    const component_b& get_b() const noexcept
    { return b; }
#endif
    /// @}