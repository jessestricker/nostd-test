#ifndef NOSTD_TEST_REGISTRY_ENTRY_HPP
#define NOSTD_TEST_REGISTRY_ENTRY_HPP

namespace nostd_test {
  /// An empty struct to use in variable declarations where no data needs to be
  /// stored.
  struct Empty {};

  /// A location in a source file.
  struct SourceLocation {
    /// The name or path of the source file.
    const char* file{};

    /// The line number in the source file, starting with 1.
    unsigned int line{};
  };

  /// The type of the test case functions.
  /// They have zero parameters and return void.
  using CaseFunction = void();

  /// An entry in the test case registry.
  struct RegistryEntry {
    /// The source location of the test case.
    SourceLocation source{};

    /// The name of the test case.
    const char* case_name{};

    /// A pointer to the test case function.
    CaseFunction* case_func{};

    /// Registers a this instance at the global registry.
    /// The return value can be used as a global variable to have the
    /// registration happen as a side-effect.
    [[nodiscard]] Empty add_to_global_registry() const noexcept;
  };
}

#endif  // NOSTD_TEST_REGISTRY_ENTRY_HPP
