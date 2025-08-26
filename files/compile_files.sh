#!/bin/bash

# Check if a directory is provided as an argument
# Assign the directory path to a variable
dir_path="base_files"

# Check if the provided path is a valid directory
if [ ! -d "$dir_path" ]; then
  echo "Error: Directory '$dir_path' not found."
  exit 1
fi

# Define the output file name
output_file="files.bin"

# Initialize an empty string to store the file info
file_info=""

# Initialize the cumulative length counter
cumulative_length=0

# Loop through each item in the specified directory
for item in "$dir_path"/*; do
  # Check if the item is a regular file
  if [ -f "$item" ]; then
    # Get the file name from the full path
    file_name=$(basename "$item")

    # Append the file name and the current cumulative length
    # The format is "file_name=cumulative_length+"
    file_info+="$file_name=$cumulative_length+"

    # Get the length of the current file's content in bytes
    content_length=$(wc -c < "$item" | tr -d '[:space:]')
    
    # Add the current file's length to the cumulative total
    cumulative_length=$((cumulative_length + content_length))
  fi
done

# Remove the trailing '+' character if the file_info string is not empty
if [ ! -z "$file_info" ]; then
  file_info=${file_info%+}
fi

# Create or overwrite the output file with the generated string
echo -n "$file_info|" >> "$output_file"

for item in "$dir_path"/*; do
  # Check if the item is a regular file
  if [ -f "$item" ]; then
    # Get the file name from the full path
    file_name=$(basename "$item")

    cat "$item" >> "$output_file"

  fi
done

