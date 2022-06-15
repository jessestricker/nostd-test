#include <nostd-test/registry-entry.hpp>

#include "registry.hpp"

namespace nostd_test {
  Empty RegistryEntry::add_to_global_registry() const noexcept {
    Registry::global().add_entry(*this);
    return {};
  }
}
