#ifndef NOSTD_TEST_SRC_NOSTD_TEST_PRIVATE_RUNNER_HPP
#define NOSTD_TEST_SRC_NOSTD_TEST_PRIVATE_RUNNER_HPP

#include <exception>
#include <string_view>

#include "registry.hpp"

namespace nostd_test {
  struct AssertionFailure : std::exception {
    std::string_view condition;
    SourceLocation source;

    AssertionFailure(const std::string_view& condition,
                     const SourceLocation& source) noexcept;
  };

  /// A runner runs all or a filtered selection of the test cases from a
  /// registry.
  class Runner {
  public:
    /// Creates a new runner with a given registry.
    explicit Runner(const Registry& registry) noexcept;

    /// Executed the test cases and returns an program exit code.
    ///
    /// The exit code depends on the outcome of the test case executions:
    /// If at least one test case fails, the exit code will indicate failure.
    ///
    /// This method also writes a user-readable report in the Markdown format
    /// to the standard output stream.
    auto operator()() const -> int;

  private:
    const Registry& registry_;
  };
}

#endif  // NOSTD_TEST_SRC_NOSTD_TEST_PRIVATE_RUNNER_HPP
