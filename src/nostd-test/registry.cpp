#include "registry.hpp"

namespace {
  nostd_test::Registry global_registry{};
}

namespace nostd_test {
  auto Registry::global() noexcept -> Registry& {
    return global_registry;
  }

  void Registry::append(const RegistryEntry& entry) noexcept {
    if (entries_len_ >= capacity) {
      too_many_entries_ = true;
      return;
    }
    entries_[entries_len_] = entry;
    entries_len_ += 1;
  }

  auto Registry::entries() const noexcept -> std::span<const RegistryEntry> {
    return {entries_.begin(), entries_len_};
  }

  auto Registry::too_many_entries() const noexcept -> bool {
    return too_many_entries_;
  }
}
