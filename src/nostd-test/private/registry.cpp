#include "registry.hpp"

namespace {
  nostd_test::Registry global_registry{};
}

namespace nostd_test {
  Registry& Registry::global() noexcept {
    return global_registry;
  }

  void Registry::append(const RegistryEntry& entry) noexcept {
    if (entries_len_ >= entries_cap_) {
      too_many_entries_ = true;
      return;
    }
    entries_[entries_len_] = entry;
    entries_len_ += 1;
  }

  std::span<const RegistryEntry> Registry::entries() const noexcept {
    return {entries_.begin(), entries_len_};
  }

  bool Registry::too_many_entries() const noexcept {
    return too_many_entries_;
  }
}
