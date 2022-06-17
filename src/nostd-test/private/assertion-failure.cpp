#include "assertion-failure.hpp"

namespace nostd_test {
  AssertionFailure::AssertionFailure(const std::string_view& condition,
                                     const SourceLocation& source) noexcept
      : condition{condition}, source{source} {
  }
}
