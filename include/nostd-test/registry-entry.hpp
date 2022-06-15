#ifndef NOSTD_TEST_REGISTRY_ENTRY_HPP
#define NOSTD_TEST_REGISTRY_ENTRY_HPP

namespace nostd_test {
  struct Empty {};

  struct SourceLocation {
    const char* file{};
    unsigned int line{};
  };

  using CaseFunction = void();

  struct RegistryEntry {
    SourceLocation source{};
    const char* case_name{};
    CaseFunction* case_func{};

    [[nodiscard]] Empty add_to_global_registry() const noexcept;
  };
}

#endif  // NOSTD_TEST_REGISTRY_ENTRY_HPP
