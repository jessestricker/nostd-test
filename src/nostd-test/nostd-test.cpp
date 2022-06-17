#include <nostd-test/nostd-test.hpp>

#include "assertion-failure.hpp"
#include "registry.hpp"

namespace nostd_test {
  auto register_test_case(const RegistryEntry& entry) noexcept -> Empty {
    Registry::global().append(entry);
    return {};
  }

  void fail_assertion(const char* condition, const SourceLocation& source) {
    throw AssertionFailure{condition, source};
  }
}
