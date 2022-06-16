#include "suite.hpp"

#include <algorithm>
#include <utility>

namespace nostd_test {
  std::vector<Suite> suites_from_registry(const Registry& registry) {
    auto suites = std::vector<Suite>{};

    for (const auto& entry : registry.entries()) {
      const auto case_ = Case{.name = entry.case_name, .func = entry.case_func};

      auto suite_it =
          std::find_if(suites.begin(), suites.end(), [&](const auto& suite) {
            return suite.file_name == entry.source.file;
          });

      if (suite_it != suites.end()) {
        suite_it->cases.push_back(case_);
      } else {
        suites.push_back(
            Suite{.file_name = entry.source.file, .cases = {case_}});
      }
    }

    // sort suites by file name
    std::ranges::sort(suites, {}, &Suite::file_name);

    return suites;
  }
}
