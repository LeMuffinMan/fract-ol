#!/bin/bash

INCLUDE_FOLDER="include"
HEADER_TO_EDIT=""
CORES=$(nproc)

if [[ ! -d "$INCLUDE_FOLDER" ]]; then
  echo "Include folder not found"
  exit 1
fi

if ! ls "$INCLUDE_FOLDER"/*.h 1> /dev/null 2>&1; then
  echo "No .h files found in $INCLUDE_FOLDER"
  exit 1
fi

for header in "$INCLUDE_FOLDER"/*.h; do
  if grep -q "# *define *THREADS" "$header"; then
    HEADER_TO_EDIT="$header"
    break
  fi
done

if [[ -z $HEADER_TO_EDIT ]]; then
  echo "No header with \"# define THREADS\" found"
  exit 1
fi

sed -i "s|^.*THREADS.*$|# define THREADS $CORES|" "$HEADER_TO_EDIT"

if [[ $? -ne 0 ]]; then
  echo "sed failed to update $HEADER_TO_EDIT to \"# define THREADS $CORES\""
else
  echo "$HEADER_TO_EDIT updated to handle $CORES cores"
fi
