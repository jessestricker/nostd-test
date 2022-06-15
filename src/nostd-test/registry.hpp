#ifndef NOSTD_TEST_REGISTRY_HPP
#define NOSTD_TEST_REGISTRY_HPP

#include <array>
#include <cstddef>
#include <nostd-test/registry-entry.hpp>
#include <span>

namespace nostd_test {
  /// A test case registry contains an array of test case registrations with a
  /// fixed capacity. The array is pre-allocated on construction of the
  /// registry, to allow for registering test cases without exceptions.
  class Registry {
  public:
    /// Returns a reference to the single global registry instance.
    static Registry& global() noexcept;

    /// Appends a copy of the registry entry.
    /// If there is no more space available in the fixed-capacity array,
    /// then the too_many_entries() flag is set to `true`
    /// and the entry is discarded.
    void append(const RegistryEntry& entry) noexcept;

    /// Returns a span of the registry entries.
    [[nodiscard]] std::span<const RegistryEntry> entries() const noexcept;

    /// Returns whether the number of registrations exceeded the capacity of
    /// the pre-allocated array.
    [[nodiscard]] bool too_many_entries() const noexcept;

  private:
    static constexpr std::size_t entries_cap_{1024};
    std::array<RegistryEntry, entries_cap_> entries_{};
    std::size_t entries_len_{};
    bool too_many_entries_{};
  };
}

#endif  // NOSTD_TEST_REGISTRY_HPP
