#include "registry-entry.hpp"

#include "private/registry.hpp"

namespace nostd_test {
  auto RegistryEntry::add_to_global_registry() const noexcept -> Empty {
    Registry::global().append(*this);
    return {};
  }
}
