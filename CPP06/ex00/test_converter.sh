#!/bin/bash
# test_converter.sh

echo "=== TESTS SCALAR CONVERTER ==="

# Tests de caractères
echo "Test char 'a':"
./convert a

echo -e "\nTest char '0':"
./convert 0

# Tests d'entiers
echo -e "\nTest int 42:"
./convert 42

echo -e "\nTest int -42:"
./convert -42

# Tests de flottants
echo -e "\nTest float 42.0f:"
./convert 42.0f

echo -e "\nTest float -42.5f:"
./convert -42.5f

# Tests de doubles
echo -e "\nTest double 42.0:"
./convert 42.0

echo -e "\nTest double -42.5:"
./convert -42.5

# Tests de pseudo-littéraux
echo -e "\nTest nan:"
./convert nan

echo -e "\nTest inf:"
./convert inf

echo -e "\nTest -inf:"
./convert -inf

# Tests d'erreur
echo -e "\nTest invalid 'hello':"
./convert hello

echo -e "\nTest invalid '42.5.3':"
./convert 42.5.3
