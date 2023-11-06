#!/bin/bash
for ((i = 0 ; i < 20 ; i++)); do
  echo -n $((1 + $RANDOM % 70)),
done
