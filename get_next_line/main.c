#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd;

    fd = open("big_line_no_nl", O_RDONLY);
    printf("%s", get_next_line(fd));

}
