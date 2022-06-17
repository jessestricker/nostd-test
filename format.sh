#! /usr/bin/env bash
set -e -u -o pipefail

project_dir=$(dirname "$(realpath "${BASH_SOURCE[0]}")")
cd "$project_dir"

fd -H -E .git -g CMakeLists.txt -x bash -xc 'cmake-format -i {}'                        # CMake
fd -H -E .git -e nix -x bash -xc 'alejandra -q {}'                                      # Nix
fd -H -E .git -e json -e md -e yml -x bash -xc 'prettier -w --loglevel warn {}'         # JSON, Markdown, YAML
fd -H -E .git -g .clang-format .clang-tidy -x bash -xc 'prettier -w --loglevel warn {}' # YAML: .clang-format, .clang-tidy
fd -H -E .git -e cpp -e hpp -x bash -xc 'clang-format -i {}'                            # C++
fd -H -E .git -e sh -x bash -xc 'shfmt -w {}'                                           # Shell
