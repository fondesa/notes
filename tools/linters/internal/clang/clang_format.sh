#!/bin/bash

__main() {
  # TODO support multiple clang-format versions
  if ! command -v clang-format-15 >/dev/null 2>&1; then
    # TODO
    echo "FAILURE"
    exit 1
  fi
  # TODO
  echo "SUCCESS"
}

__main
