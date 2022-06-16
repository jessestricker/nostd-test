#ifndef NOSTD_TEST_NOSTD_TEST_HPP
#define NOSTD_TEST_NOSTD_TEST_HPP

#include <nostd-test/registry-entry.hpp>

/// The root namespace of the *nostd-test* framework.
namespace nostd_test {
  [[noreturn]] void fail_assertion(const char* condition,
                                   const SourceLocation& source) noexcept;

  template <class ExprLambda>
  void check_assertion(ExprLambda expr_lambda, const char* condition,
                       const SourceLocation& source) noexcept {
    if (expr_lambda()) [[likely]] {
      return;
    }
    fail_assertion(condition, source);
  }
}

/// Define a test case with a given name.
///
/// This macro may only be used directly in the global namespace,
/// as it injects global variable declarations in an anonymous namespace as part
/// of the automatic test case registration mechanism.
#define TEST_CASE(Name)                                     \
  void nostd_test_case_func_##Name();                       \
  namespace {                                               \
    const auto nostd_test_registry_entry_##Name =           \
        nostd_test::RegistryEntry{                          \
            .source = {.file = __FILE__, .line = __LINE__}, \
            .case_name = #Name,                             \
            .case_func = &nostd_test_case_func_##Name}      \
            .add_to_global_registry();                      \
  }                                                         \
  void nostd_test_case_func_##Name()

#define ASSERT_THAT(Cond)                                                \
  ::nostd_test::check_assertion([&]() -> bool { return (Cond); }, #Cond, \
                                {.file = __FILE__, .line = __LINE__})

#endif  // NOSTD_TEST_NOSTD_TEST_HPP
