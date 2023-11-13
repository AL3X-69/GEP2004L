#! /bin/bash
gcc outils.c -Wall -W -std=c99 -I. -c
ar cr liboutils.a outils.o
ranlib liboutils.a
