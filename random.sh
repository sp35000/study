#!/bin/bash
for ((i = 0 ; i < 1000 ; i++)); do
  echo -n $((1 + $RANDOM % 1000)),
done
