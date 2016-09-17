/*  numberChains.c
 *
 *  Copyright 2016 Daniel Moran
 *  All rights reserved.
 *  
 *  This software is licensed under the terms of
 *  the MIT License. See the LICENSE file for details.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "constants.h"

int extractTarget(char * target)
{
    char *c = target;
    int res = 0;

    /* Check for characters, we only want digits */
    while (*c != '\0') {
        if (!(*c >= '0' && *c <= '9')) {
            return -1;
        }
        c++;
    }
    
    /* Convert digits to an integer */
    res = atoi(target);

    return res;
}

int main(int argc, char * argv[])
{
    int target = 0;
    int countAnd = 0;

    if (argc == 1) {
        fputs("Not enough arguments\n", stderr);
        return -1;
    }else if (argc > 3) {
        fputs("Too many arguments\n", stderr);
        return -1;
    }

    target = extractTarget(argv[1]);
    if (target < 0){
        fputs("Error processing target. Negatives and non-digits not allowed", stderr);
        return -1;
    }

    printf("Number: %d, Length: %d\n", target, 1);

    return 0;
}
