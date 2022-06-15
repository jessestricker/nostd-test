#ifndef NOSTD_TEST_REGISTRY_HPP
#define NOSTD_TEST_REGISTRY_HPP

#include <array>
#include <cstddef>
#include <nostd-test/registry-entry.hpp>
#include <span>

namespace nostd_test {
  class Registry {
  public:
    static Registry& global() noexcept;

    void add_entry(const RegistryEntry& entry) noexcept;

    [[nodiscard]] std::span<const RegistryEntry> entries() const noexcept;
    [[nodiscard]] bool too_many_entries() const noexcept;

  private:
    static constexpr std::size_t entries_cap_{1024};
    std::array<RegistryEntry, entries_cap_> entries_{};
    std::size_t entries_len_{};
    bool too_many_entries_{};
  };
}

#endif  // NOSTD_TEST_REGISTRY_HPP
