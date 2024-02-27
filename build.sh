#/usr/bin/env bash

app=${1}

/usr/bin/g++-11 \
  -I ./ \
  -fdiagnostics-color=always \
  -g src/${app}/${app}.cpp \
  -o out/${app}