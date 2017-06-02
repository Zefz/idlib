#pragma once

#pragma push_macro("IDLIB_PRIVATE")
#define IDLIB_PRIVATE 1
#include "idlib/utility/platform.hpp"

#if defined(ID_WINDOWS)

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include "idlib/file_system/access_mode.hpp"
#include "idlib/file_system/create_mode.hpp"

#include "idlib/file_system/internal/header.hpp"

// A file descriptor.
struct file_descriptor final
{
private:
    HANDLE m_handle;
	access_mode m_access_mode;

public:
    /// @brief Ensure the file descriptor is open.
    /// @param pathname the pathname of the file
    /// @param access_mode the access mode
    /// @param create_mode the create mode
    void open(const std::string& pathname, access_mode access_mode, create_mode create_mode) noexcept;

    /// @brief Get if the file descriptor is open.
    /// @return @a true if the descriptor is open, @a false otherwise
    bool is_open() const noexcept;

    /// @brief Ensure the file descriptor is closed.
    void close() noexcept;

    /// @brief Construct this file descriptor.
    /// @post The file descriptor is closed.
    file_descriptor() noexcept;

    /// @brief Destruct this file descriptor.
    /// @post The file descriptor is closed.
    ~file_descriptor() noexcept;

    /// @brief Get the size, in Bytes, of the file size.
    /// @return the size, in Bytes, of the file
    /// @pre The file is open.
    /// @throw id::file_system::read_write_error the file is not open or the environment fails
    size_t size() const;

    /// Get the internal handle.
    HANDLE& handle() { return m_handle; }

public:
    // Delete copy constructor.
    file_descriptor(const file_descriptor&) = delete;

    // Delete copy assignment operator.
    file_descriptor& operator=(const file_descriptor&) = delete;

}; // struct file_descriptor

#include "idlib/file_system/internal/footer.hpp"

#endif

#undef IDLIB_PRIVATE
#pragma pop_macro("IDLIB_PRIVATE")
