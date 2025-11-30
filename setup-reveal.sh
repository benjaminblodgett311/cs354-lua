#!/bin/bash

set -e

SRC="reveal.js-5.2.1/dist"
OUT="reveal-local"

mkdir -p "$OUT"

# core JS + CSS
cp "$SRC/reveal.js"      "$OUT/reveal.js"
cp "$SRC/reveal.css"     "$OUT/reveal.css"
cp "$SRC/reset.css"      "$OUT/reset.css"

# theme (choose one)
cp "$SRC/theme/black.css" "$OUT/theme.css"

# fonts
mkdir -p "$OUT/fonts"
cp -r "$SRC/theme/fonts/"* "$OUT/fonts/"

echo "Done. Files copied to: $OUT/"

