#ifndef NOSTD_TEST_SRC_NOSTD_TEST_SOURCE_LOCATION_HPP
#define NOSTD_TEST_SRC_NOSTD_TEST_SOURCE_LOCATION_HPP

namespace nostd_test {
  /// A location in a source file.
  struct SourceLocation {
    /// The name or path of the source file.
    const char* file{};

    /// The line number in the source file, starting with 1.
    unsigned int line{};
  };
}

/// Returns the current source location.
#define NOSTD_TEST_CURRENT_SOURCE_LOCATION() \
  ::nostd_test::SourceLocation { .file = __FILE__, .line = __LINE__ }

#endif  // NOSTD_TEST_SRC_NOSTD_TEST_SOURCE_LOCATION_HPP
