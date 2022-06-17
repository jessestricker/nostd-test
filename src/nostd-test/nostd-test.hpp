#ifndef NOSTD_TEST_SRC_NOSTD_TEST_NOSTD_TEST_HPP
#define NOSTD_TEST_SRC_NOSTD_TEST_NOSTD_TEST_HPP

#include <nostd-test/registry-entry.hpp>

/// The root namespace of the *nostd-test* framework.
namespace nostd_test {
  [[noreturn]] void fail_assertion(const char* condition,
                                   const SourceLocation& source);

  template <class ExprLambda>
  void check_assertion(ExprLambda expr_lambda, const char* condition,
                       const SourceLocation& source) {
    if (expr_lambda()) [[likely]] {
      return;
    }
    fail_assertion(condition, source);
  }
}

/// Define a test case with a given name.
///
/// This macro may only be used directly at global namespace scope.
#define TEST_CASE(Name)                                     \
  namespace nostd_test::cases {                             \
    /* Forward-declare test case function. */               \
    void func_##Name();                                     \
    /* Define registry entry for test case. */              \
    const auto registry_entry_##Name =                      \
        ::nostd_test::RegistryEntry{                        \
            .source = NOSTD_TEST_CURRENT_SOURCE_LOCATION(), \
            .case_name = #Name,                             \
            .case_func = &func_##Name}                      \
            .add_to_global_registry();                      \
  }                                                         \
  /* Define test case function. */                          \
  void nostd_test::cases::func_##Name()

#define ASSERT_THAT(Cond)                                                \
  ::nostd_test::check_assertion([&]() -> bool { return (Cond); }, #Cond, \
                                NOSTD_TEST_CURRENT_SOURCE_LOCATION())

#endif  // NOSTD_TEST_SRC_NOSTD_TEST_NOSTD_TEST_HPP
