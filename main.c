#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "genesis.h"





int main(int argc, char **argv)
{
    memset(&opts, 0, sizeof(UserOpts));
    parseArguments(argc, argv, &opts);
    //testArguments(&opts);
    //init_genesis();
    test();

    return 0;
}

