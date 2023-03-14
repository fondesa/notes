#!/bin/bash

BUILDIFIER_LINK_PATH=@@BUILDIFIER_LINK_PATH@@
ARGS=@@ARGS@@

__main() {
  if [[ -z "${BUILD_WORKSPACE_DIRECTORY+x}" ]]; then
    echo "The env variable BUILD_WORKSPACE_DIRECTORY is not set."
    exit 1
  fi

  BUILDIFIER_EXEC=$(readlink "$BUILDIFIER_LINK_PATH")
  if [[ ! -x "$BUILDIFIER_EXEC" ]]; then
    echo "The buildifier executable does not exist or has not exec permissions"
    exit 1
  fi

  (cd "$BUILD_WORKSPACE_DIRECTORY" && __exec_buildifier)
}

__exec_buildifier() {
  local file_filter=("WORKSPACE" "BUILD" "**/BUILD" "*.bzl")
  local buildifier_files
  buildifier_files=$(git ls-files "${file_filter[@]}")

  if [[ ${#buildifier_files[@]} == 0 ]]; then
    echo "Skipping buildifier since there are no files to check"
    return
  fi

  # shellcheck disable=SC2086
  "$BUILDIFIER_EXEC" "${ARGS[@]}" $buildifier_files
}

__main
