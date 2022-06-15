#ifndef NOSTD_TEST_NOSTD_TEST_HPP
#define NOSTD_TEST_NOSTD_TEST_HPP

#include <nostd-test/registry-entry.hpp>

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

#define ASSERT(Cond)

#endif  // NOSTD_TEST_NOSTD_TEST_HPP
