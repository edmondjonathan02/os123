#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
int main()
{
    int fd, sz;
    char *c = (char *)calloc(100, sizeof(char));
    fd = open("text1.txt", O_RDONLY); //create a file called text1 in the directory where your code is
    if (fd < 0)
    {
        perror("r1"), exit(1);
    }
    sz = read(fd, c, 12);
    printf("called read(%d,c,12). returned that"
           " %d bytes were read.\n",
           fd, sz);
    c[sz] = '\0';
    printf("those bytes are as follows: %s\n", c);

    return 0;
}
/*OUTPUT
called read(3,c,12). returned that 12 bytes were read.
those bytes are as follows: hello world */