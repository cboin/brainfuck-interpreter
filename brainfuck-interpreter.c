#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

#define BF_MAX 30000

#define handle_error(e) do { perror(e); exit(EXIT_FAILURE); } while (0)

void interpret(char *buffer, size_t buflen);

static void usage(void)
{
    fprintf(stderr, "brainfuck-interpreter: [-h help] [-f filename]\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    int ch;
    FILE *fd;
    size_t fsize;
    char *buffer;

    while ((ch = getopt(argc, argv, "hf:")) != -1) {
        switch (ch) {
            case 'h':
                usage();
                break;
            case 'f':
                /* open the file to be interpreted. */
                if ((fd = fopen(optarg, "r")) == NULL)
                    handle_error("fopen");

                break;

            case '?':
            default:
                usage();
        }
    }

    /* Get file size. */
    if (fseek(fd, 0L, SEEK_END) != 0)
        handle_error("fseek");

    fsize = ftell(fd);
    if (fsize == -1)
        handle_error("ftell");

    /* back to top. */
    rewind(fd);

    /* allocation the buffer. */
    buffer = (char *) malloc(fsize * sizeof(char));
    if (buffer == NULL)
        handle_error("malloc");

    bzero(buffer, fsize);

    /* fill the buffer. */
    if (!fread(buffer, fsize, 1, fd))
        handle_error("fread");

    interpret(buffer, fsize);

    return (EXIT_SUCCESS);
}

void interpret(char *buffer, size_t buflen)
{

    return;
}

