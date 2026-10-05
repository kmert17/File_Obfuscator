# Bitwise File Obfuscator

A small C program that demonstrates binary file I/O by applying a bitwise NOT (`~`) to every byte of a file. It first obfuscates an input file, then reverses the operation to recover the original content.

> **⚠️ Disclaimer:** This is **not encryption** and provides **no security**. It is a learning exercise for file handling in C.

## What it does

1. Reads `first_open.txt` in binary mode.
2. Writes the bitwise-NOT of each byte to `second_secret.txt`.
3. Reads `second_secret.txt` and applies the same transform again.
4. Writes the result to `third_open.txt`.

Because `~(~x) == x` for bytes, `third_open.txt` should be identical to `first_open.txt`.
