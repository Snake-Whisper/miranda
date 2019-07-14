#include <stdio.h>
#include "genesis.h"
#include "utils.h"
#include "string.h"

void init_genesis()
{
    strcpy(workBuffer, opts.expression);
    int boarder = 0;
    while (workBuffer[boarder] != '?')
    {
        printf("%c", workBuffer[boarder]);
        boarder++;
    }
    printf("start worker at: %i\n", boarder);
    genesis(boarder);
}

void genesis(int index)
{
    if (index == opts.expr_lenght)
    {
       for (int i = 0; i < opts.charset_lenght; i++)
       {
           workBuffer[index] = opts.charset[i];
           printf("%s\n", workBuffer);
       }
    } else
    {
        for (int i = 0; i < opts.charset_lenght; i++)
       {
           workBuffer[index] = opts.charset[i];
           genesis(index+1);
       }
    }
}
