#!/bin/sh

case $1 in
    --help|-h)
    echo "Usage: $0 --help | --flag1 | --flag2"
    ;;
    --flag1|-f1)
    echo "Flag 1 set"
    ;;
    --flag2|-f2)
    echo "Flag 2 set"
    ;;
    *)
    echo "Unknown argument"
    ;;
esac
