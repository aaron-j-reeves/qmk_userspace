# rules.mk
SRC += oled.c
SRC += layers.c

# Prebuild step to generate password.h
PRE_BUILD = ./generate_header.sh