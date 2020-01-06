#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_sh.h"

t_buffer        *new_buffer(){

    t_buffer        *buffer = (t_buffer *)malloc(sizeof(t_buffer));

    buffer->size = 0;

    return buffer;
}

void            buffer_push(t_buffer *buffer, char c){

    if (buffer->size > 0){
        char    *temp_str = (char *)malloc(sizeof(char) * (buffer->size + 2));

        for (int i = 0; i < buffer->size; i++){
            temp_str[i] = buffer->str[i];
        }

        temp_str[buffer->size] = c;
        temp_str[buffer->size + 1] = '\0';

        free(buffer->str);

        buffer->str = temp_str;
        buffer->size++;
    } else {
        buffer->str = (char *)malloc(sizeof(char) + 1);
        buffer->str[0] = c;
        buffer->str[1] = '\0';
        buffer->size = 1;
    }
}