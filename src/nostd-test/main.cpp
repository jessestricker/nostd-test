#include "runner.hpp"

/// The program entry point.
auto main() -> int {
  const auto& registry = nostd_test::Registry::global();
  const auto runner = nostd_test::Runner{registry};
  return runner();
}
