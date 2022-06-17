#include "nostd-test.hpp"

#include "private/assertion-failure.hpp"
#include "private/registry.hpp"

namespace nostd_test {
  auto register_test_case(const RegistryEntry& entry) noexcept -> Empty {
    Registry::global().append(entry);
    return {};
  }

  void fail_assertion(const char* condition, const SourceLocation& source) {
    throw AssertionFailure{condition, source};
  }
}
