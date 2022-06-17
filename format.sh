#! /usr/bin/env bash
set -e -u -o pipefail

script_file=$(realpath "${BASH_SOURCE[0]}")
project_dir=$(dirname "$script_file")
cd "$project_dir"

git ls-files -z 'CMakeLists.txt' | xargs -0 -t -- cmake-format -i
git ls-files -z '*.nix' | xargs -0 -t -- alejandra -q
git ls-files -z '*.json' '*.md' '*.yml' '.clang-format' '.clang-tidy' | xargs -0 -t -- prettier -w --loglevel=warn
git ls-files -z '*.cpp' '*.hpp' | xargs -0 -t -- clang-format -i
git ls-files -z '*.sh' | xargs -0 -t -- shfmt -w -i=2
