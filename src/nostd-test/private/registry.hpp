#ifndef NOSTD_TEST_SRC_NOSTD_TEST_PRIVATE_REGISTRY_HPP
#define NOSTD_TEST_SRC_NOSTD_TEST_PRIVATE_REGISTRY_HPP

#include <array>
#include <cstddef>
#include <span>

#include "../registry-entry.hpp"

namespace nostd_test {
  /// A test case registry contains an array of test case registrations with a
  /// fixed capacity. The array is pre-allocated on construction of the
  /// registry, to allow for registering test cases without exceptions.
  class Registry {
  public:
    /// The capacity of the pre-allocated array of registry entries.
    static constexpr std::size_t capacity{1024};

    /// Returns a reference to the single global registry instance.
    static auto global() noexcept -> Registry&;

    /// Appends a copy of the registry entry.
    /// If there is no more space available in the fixed-capacity array,
    /// then the too_many_entries() flag is set to `true`
    /// and the entry is discarded.
    void append(const RegistryEntry& entry) noexcept;

    /// Returns a span of the registry entries.
    [[nodiscard]] auto entries() const noexcept
        -> std::span<const RegistryEntry>;

    /// Returns whether the number of registrations exceeded the capacity of
    /// the pre-allocated array.
    [[nodiscard]] auto too_many_entries() const noexcept -> bool;

  private:
    std::array<RegistryEntry, capacity> entries_{};
    std::size_t entries_len_{};
    bool too_many_entries_{};
  };
}

#endif  // NOSTD_TEST_SRC_NOSTD_TEST_PRIVATE_REGISTRY_HPP
