#include "rpn.h"
#include "pole.c"

int main() {
    int str_size, buf_size, rpn_size;
    char* str = input_string();
    str_size = (int)strlen(str);
    char** buf = parse_string(str, &buf_size);
    char** rpn = convert_to_rpn(buf, buf_size, str_size, &rpn_size);
    rendering(rpn, rpn_size);
    for (int i = 0; i < str_size; i++) {
        free(buf[i]);
    }
    free(buf);
    for (int i = 0; i < buf_size; i++) {
        free(rpn[i]);
    }
    free(rpn);
    free(str);
    return 0;
}
