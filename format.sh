#! /usr/bin/env bash
set -e -u -o pipefail

project_dir=$(dirname "$(realpath "${BASH_SOURCE[0]}")")
cd "$project_dir"

fd -H -E .git -g CMakeLists.txt -x bash -xc 'cmake-format -i {}'            # CMake
fd -H -E .git -e nix -x bash -xc 'alejandra -q {}'                          # Nix
fd -H -E .git -e json -e yml -x bash -xc 'prettier -w --loglevel warn {}'   # JSON, YAML
fd -H -E .git -g .clang-format -x bash -xc 'prettier -w --loglevel warn {}' # YAML: .clang-format
fd -H -E .git -e cpp -e hpp -x bash -xc 'clang-format -i {}'                # C++
fd -H -E .git -e sh -x bash -xc 'shfmt -w {}'                               # Shell
