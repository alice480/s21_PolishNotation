#ifndef SRC_INPUT_H_
#define SRC_INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FUNCTIONS "sin", "cos", "tan", "ctg", "sqrt", "ln"
#define FCOUNT 6

char *input_string();
char** parse_string(char *str, int *buf_size);

#endif  // SRC_INPUT_H_
