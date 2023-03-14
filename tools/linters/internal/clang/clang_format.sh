#!/bin/bash

main() {
  # TODO support multiple clang-format versions
  if ! command -v clang-format-15 >/dev/null 2>&1; then
    echo "clang-format-15 is required but not installed"
    exit 1
  fi

  (cd "$BUILD_WORKSPACE_DIRECTORY" && exec_clang_format)
}

exec_clang_format() {
  local file_filter=("*.hpp" "*.cpp")
  local cpp_files
  cpp_files=$(git ls-files "${file_filter[@]}")

  if [[ ${#cpp_files[@]} == 0 ]]; then
    echo "Skipping clang-format since there are no files to check"
    return
  fi

  # shellcheck disable=SC2086
  clang-format-15 -i $cpp_files
}

main
