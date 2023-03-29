#!/bin/bash

mkdir src
mkdir include

cat > src/main.c <<EOL
#include <stdio.h>
#include "my.h"

int main() {
    return 0;
}
EOL

# Créer le fichier my.h dans le dossier include
cat > include/my.h <<EOL
#ifndef MY_H
    # define MY_H

//déclarations fonctions ici

#endif
EOL

# Le remplacer par mon Makefile avec ma lib
cat > Makefile <<EOL
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
SRC = src/main.c
OBJ = \$(SRC:.c=.o)
TARGET = my_program

all: \$(TARGET)

\$(TARGET): \$(OBJ)
	\$(CC) -o \$(TARGET) \$(OBJ) \$(CFLAGS)

%.o: %.c
	\$(CC) -c \$< -o \$@ \$(CFLAGS)

clean:
	rm -f \$(OBJ)

fclean: clean
	rm -f \$(TARGET)

re: fclean all

.PHONY: all clean fclean re
EOL