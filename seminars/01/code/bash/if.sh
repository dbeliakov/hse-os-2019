#!/bin/sh

if mkdir some_dir/new_subdir
then
    echo "Subdirectory created"
else
    echo "Can't create"
fi
