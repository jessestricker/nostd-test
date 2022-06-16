#include "runner.hpp"

#include <iostream>

#include "suite.hpp"

namespace nostd_test {
  Runner::Runner(const Registry& registry) noexcept : registry_{registry} {
  }

  int Runner::operator()() const noexcept {
    if (registry_.too_many_entries()) {
      std::clog << "# Error\n";
      std::clog << "> Too many test cases were tried to be registered!\n";
      return 1;
    }

    std::clog << "# Test Report:\n";
    std::clog << "\n";

    const auto suites = suites_from_registry(registry_);
    for (const auto& suite : suites) {
      std::clog << "## Suite: `" << suite.file_name << "`\n";
      std::clog << "\n";

      for (const auto& case_ : suite.cases) {
        std::clog << "### Case: `" << case_.name << "`\n";
      }

      std::clog << "\n";
    }
    return 0;
  }
}
