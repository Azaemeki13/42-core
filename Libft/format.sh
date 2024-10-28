#!/bin/bash

# Loop over all .c files in the current directory
for file in *.c; do
    # Check if the file exists to avoid errors if no .c files are present
    if [ -f "$file" ]; then
        # Run c_formatter_42 on the file
        c_formatter_42 "$file" < "$file"
        echo "Formatted $file"
    fi
done
