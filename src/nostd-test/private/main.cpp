#include "runner.hpp"

/// The program entry point.
int main(int argc, char* argv[]) {
  using namespace nostd_test;

  const auto& registry = Registry::global();
  const auto runner = Runner{registry};
  return runner();
}
