#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

char        *input_reader(){

    t_buffer    *buffer = new_buffer();
    char        c;

    while (1){
        c = ft_getchar();
        if (c != '\n' && c != '\t' && c != '\r' && c != '\0' && c != -1){
            buffer_push(buffer, c);
        } else {
            if (buffer->size > 0){
                return buffer->str;
            } else {
                return NULL;
            }
        }
    }
}