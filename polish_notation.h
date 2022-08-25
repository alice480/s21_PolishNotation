#ifndef SRC_RPN_H_
#define SRC_RPN_H_

#include <stdio.h>
#include <string.h>

#include "input.h"
#include "stack.h"

char** convert_to_rpn(char** buf, int buf_size, int str_size, int* rpn_size);
int precedence(char op);

#endif  // SRC_RPN_H_
