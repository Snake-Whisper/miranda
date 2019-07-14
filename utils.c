#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void parseArguments(int argc, char **argv, UserOpts *opts)
{
    char c;
    while ((c = getopt(argc, argv, ":c:ve:s:w:H:P:")) != -1)
    {
        switch (c)
        {
        case 'c':
            opts->charset = optarg;
            opts->charset_lenght = strlen(optarg); //error if null?
            break;
        case 'e':
            opts->expression = optarg;
            opts->expr_lenght = strlen(optarg) - 1; //dirty -1
            break;
        case 's':
            opts->mode = SERVER;
            //extract host and port
            break;
        case 'w':
            opts->mode = WORKER;
            break;
        case 'H':
            opts->host = optarg;
            break;
        case 'P':
            opts->port = optarg;
            break;
        case ':':
            printf("Option %c needs a value\n", c);
            exit(-1);
        case '?':
            printf("unknown option\n");
            break;
        case 'v':
            usage();
            exit(0);
        default:
            printf("got undefined: %s", optarg);
            break;

        }
    }
}

int isBlank (char *string)
{
    return string == 0 || strlen(string) == 0 || string[0] == '\0';
}

void testArguments(UserOpts *opts)
{
    switch (opts->mode) {
    case SERVER:
        if (isBlank(opts->charset)) {
            printf("Please specify charset with -c\n");
            exit(-1);
        }

        if (isBlank(opts->expression)) {
            printf("Please specify expression with -e\n");
            exit(-1);
        }

        if (isBlank(opts->host)) {
            printf("Please Specific host with -H in server / client mode\n");
            exit(-1);
        }

        if (opts->port == 0) { //wasn't there a random port function in some os with 0?
            printf("Please specific port unequal 0 with -p in server / client mode\n");
            exit(-1);
        }
        break;

    case NORMAL:
        if (isBlank(opts->charset)) {
            printf("Please specify charset with -c\n");
            exit(-1);
        }

        if (isBlank(opts->expression)) {
            printf("Please specify expression with -e\n");
            exit(-1);
        }
        break;

    case WORKER:
        if (isBlank(opts->host)) {
            printf("Please Specific host with -H in server / client mode\n");
            exit(-1);
        }

        if (opts->port == 0) { //wasn't there a random port function in some os with 0?
            printf("Please specific port unequal 0 with -p in server / client mode\n");
            exit(-1);
        }
        break;
    }
}

void usage()
{
    printf("wordgen\n"
           "=======\n\n"
           "wordGen -- Copyright MIT snake-whisper 2019\n"
           "Generate Wordlists in give ranges\n"
           "\t-c\tchars\tlist of chars allowed to use. Don't use seperators like comma or space.\n"
           "\t-s\t\trun wordgen in server Mode. Use -H and -P to specify host and port.\n"
           "\t-w\t\trun wordGen in worker mode. Use -H and -P to specify host and port.\n");
}
