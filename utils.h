#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED


typedef struct {
    char *charset;
    unsigned int charset_lenght;
    char *expression;
    unsigned int *expr_lenght;
    enum Modes {NORMAL = 0, WORKER, SERVER} mode;
    char *host;
    unsigned int port;
} UserOpts;

UserOpts opts;

void usage();
void parseArguments(int, char**, UserOpts*);
void testArguments(UserOpts*);
int isBlank(char*);

#endif // UTILS_H_INCLUDED
