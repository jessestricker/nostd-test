#include "nostd-test.hpp"

#include "private/runner.hpp"

namespace nostd_test {
  void fail_assertion(const char* condition, const SourceLocation& source) {
    throw AssertionFailure{condition, source};
  }
}
