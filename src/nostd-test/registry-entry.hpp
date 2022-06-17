#ifndef NOSTD_TEST_SRC_NOSTD_TEST_REGISTRY_ENTRY_HPP
#define NOSTD_TEST_SRC_NOSTD_TEST_REGISTRY_ENTRY_HPP

#include <nostd-test/source-location.hpp>

namespace nostd_test {
  /// The type of the test case functions.
  /// They have zero parameters and return void.
  using CaseFunction = void();

  /// An entry in the test case registry.
  struct RegistryEntry {
    /// The source location of the test case.
    SourceLocation source;

    /// The name of the test case.
    const char* case_name{};

    /// A pointer to the test case function.
    CaseFunction* case_func{};
  };
}

#endif  // NOSTD_TEST_SRC_NOSTD_TEST_REGISTRY_ENTRY_HPP
