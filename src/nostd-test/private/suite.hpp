#ifndef NOSTD_TEST_SRC_NOSTD_TEST_PRIVATE_SUITE_HPP
#define NOSTD_TEST_SRC_NOSTD_TEST_PRIVATE_SUITE_HPP

#include <string_view>
#include <vector>

#include "registry.hpp"

namespace nostd_test {
  /// A test case is a named function which tests some expected behavior.
  struct Case {
    /// The name given to the test case by the creator.
    std::string_view name{};

    /// The function which asserts the expected behavior.
    CaseFunction* func{};
  };

  /// A test suite is a grouping of related test cases.
  struct Suite {
    /// The name of the file the test cases are defined in.
    std::string_view file_name{};

    /// The test cases belonging to this test suite.
    std::vector<Case> cases{};
  };

  /// Groups the registry entries into cases belonging to suites.
  auto suites_from_registry(const Registry& registry) -> std::vector<Suite>;
}

#endif  // NOSTD_TEST_SRC_NOSTD_TEST_PRIVATE_SUITE_HPP
