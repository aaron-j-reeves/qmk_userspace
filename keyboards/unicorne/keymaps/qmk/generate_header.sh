#!/bin/bash

# Check if SECURE_SECRET is set
if [ -z "$SECURE_SECRET" ]; then
    echo "Error: SECURE_SECRET environment variable not set." >&2
    exit 1
fi

# Generate the `secure.h` header file
echo -n "#define SECURE_MACRO \"" > secure.h
echo -n "$SECURE_SECRET" >> secure.h
echo "\"" >> secure.h

echo "secure.h successfully generated."