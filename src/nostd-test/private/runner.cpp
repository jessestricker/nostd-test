#include "runner.hpp"

#include <iostream>
#include <sstream>

#include "suite.hpp"

namespace nostd_test {
  AssertionFailure::AssertionFailure(const std::string_view& condition,
                                     const SourceLocation& source) noexcept
      : condition{condition}, source{source} {
  }

  Runner::Runner(const Registry& registry) noexcept : registry_{registry} {
  }

  auto Runner::operator()() const -> int {
    auto& out = std::cout;

    if (registry_.too_many_entries()) {
      out << "# Error\n";
      out << "> Too many test cases were registered!\n";
      out << "> The capacity of registry entries is " << Registry::capacity
          << ".\n";
      return 1;
    }

    out << "# Test Report\n";
    out << "\n";

    const auto suites = suites_from_registry(registry_);
    for (const auto& suite : suites) {
      std::size_t cases_failure = 0;
      auto suite_report = std::ostringstream{};

      for (const auto& case_ : suite.cases) {
        try {
          case_.func();
          continue;
        } catch (const AssertionFailure& failure) {
          // an assertion failed
          suite_report << "\n### Case `" << case_.name << "`\n";
          suite_report << "__Assertion Failure__\\\n";

          suite_report << "__Source:__ `" << failure.source.file << ":"
                       << failure.source.line << "`\\\n";

          suite_report << "__Condition:__\n";
          suite_report << "```\n";
          suite_report << failure.condition << "\n";
          suite_report << "```\n";
        } catch (const std::exception& ex) {
          // an arbitrary exception was thrown
        } catch (...) {
          // an unknown type was thrown
        }
        cases_failure += 1;
      }

      const auto cases_total = suite.cases.size();
      const auto cases_success = cases_total - cases_failure;
      out << "## Suite `" << suite.file_name << "`\n\n";
      out << "__Summary:__ " << cases_success << "/" << cases_total
          << " cases succeeded, " << cases_failure << " cases failed.\n";

      out << suite_report.str() << "\n";
    }
    return 0;
  }
}
