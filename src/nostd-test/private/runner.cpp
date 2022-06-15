#include "runner.hpp"

#include <iostream>

namespace nostd_test {
  Runner::Runner(const Registry& registry) noexcept : registry_{registry} {
  }

  int Runner::operator()() const noexcept {
    std::clog << "# Registry Entries:\n";
    std::clog << "\n";
    for (const auto& entry : registry_.entries()) {
      std::clog << "- `" << entry.source.file << ":" << entry.source.line
                << "`: " << entry.case_name << "\n";
    }
    return 0;
  }
}
