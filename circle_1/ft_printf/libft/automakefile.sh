#!/bin/bash

# Create a temporary output file for the SRC list
echo "# BEGIN SRC" > temp_src_list.txt
echo "SRC = \\" >> temp_src_list.txt

# List all .c files in the directory and count them
count=0
for file in *.c; do
    echo "    $file \\" >> temp_src_list.txt
    count=$((count + 1))
done

# Remove the trailing backslash from the last line
if [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS
    sed -i '' -e '$ s/ \\$//' temp_src_list.txt
else
    # Linux and others
    sed -i '$ s/ \\$//' temp_src_list.txt
fi

# Add the END SRC block based on the count of .c files
total_lines=$((count + 2))  # 2 lines for BEGIN SRC and SRC line itself
echo "# END SRC (line number: $total_lines)" >> temp_src_list.txt

# Update the Makefile by replacing the lines between "# BEGIN SRC" and "# END SRC"
awk '
    BEGIN {in_block = 0}
    /# BEGIN SRC/ {
        in_block = 1;
        while ((getline line < "temp_src_list.txt") > 0) {
            print line;  # Print lines from the temporary file
        }
        next;  # Skip processing until "# END SRC" is found
    }
    /# END SRC/ {
        if (in_block) { in_block = 0; next; }  # Skip the original "# END SRC" line
    }
    !in_block
' Makefile > Makefile.tmp && mv Makefile.tmp Makefile

# Remove the temporary file
rm temp_src_list.txt
