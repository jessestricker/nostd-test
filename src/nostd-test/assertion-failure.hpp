#ifndef NOSTD_TEST_SRC_NOSTD_TEST_ASSERTION_FAILURE_HPP
#define NOSTD_TEST_SRC_NOSTD_TEST_ASSERTION_FAILURE_HPP

#include <exception>
#include <string_view>

#include <nostd-test/source-location.hpp>

namespace nostd_test {
  struct AssertionFailure : std::exception {
    std::string_view condition;
    SourceLocation source;

    AssertionFailure(const std::string_view& condition, const SourceLocation& source) noexcept;
  };
}

#endif  // NOSTD_TEST_SRC_NOSTD_TEST_ASSERTION_FAILURE_HPP
