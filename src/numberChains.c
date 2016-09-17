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
#include <string.h>
#include <math.h>

#include "constants.h"

int countLetters(char * string)
{
    int num = 0;
    char * c = string;
    while (*c != '\0')
    {
        if (  (*c >= 'a' && *c <='z')
            ||(*c >= 'A' && *c <='Z')) {
            num++;
        }
        c++;
    }
    return num;
}

void convertToName(long long value, int useAnd, char * buffer) 
{
    char * c = buffer;
    int nDigits, nGroups;
    long long prefix;
    int h, t, u;
    int n = 0;
    
    if (value == 0) {
        strcpy(c, "Zero");
        return;
    }

    nDigits = (int)floor(log10((double)value)) + 1;
    nGroups = (nDigits-1) / 3;
    
    while ( value > 0 ) {
        prefix = value / (long long)pow(10, nGroups*3);

        if (n > 0) *c++ = ' ';

        h = prefix / 100;
        if (h > 0){
            strcpy(c, units[h]);
            c += strlen(units[h]);
            
            strcpy(c, " hundred");
            c += strlen(" hundred");
        }

        t = (prefix % 100) / 10;
        u = prefix % 10;
        printf("%d, %d, h: %d, t: %d, u: %d\n", prefix, nGroups, h, t, u);

        if (useAnd){
            if (h > 0 && ((prefix % 100) > 0)) {
                strcpy(c, " and ");
                c += strlen(" and ");
            }
        } else {
            if (h > 0) *c++ = ' ';
        }
        if (t == 1) {
            /* Teens are special */
            strcpy(c, teens[u]);
            c += strlen(teens[u]);
        } else {
            strcpy(c, tens[t]);
            c += strlen(tens[t]);
            
            if (t > 0) *c++ = ' ';
            
            strcpy(c, units[u]);
            c += strlen(units[u]);
        }

        if (nGroups > 0) *c++ = ' ';

        strcpy(c, groups[nGroups]);
        c += strlen(groups[nGroups]);
        value = value % (long long)pow(10, nGroups*3);
        nGroups--;
        n=1;
    }

}

long long extractTarget(char * target)
{
    char *c = target;
    long long res = 0;

    /* Check for characters, we only want digits */
    while (*c != '\0') {
        if (!(*c >= '0' && *c <= '9')) {
            return -1;
        }
        c++;
    }
    
    /* Convert digits to an integer */
    res = atoll(target);

    return res;
}

int main(int argc, char * argv[])
{
    long long target = 0;
    int countAnd = 0;
    char buffer[1024];
    int len = 0;
     

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

    if ( argc == 3 ){

    } 

    convertToName(target, countAnd, buffer);

    printf("Number: %lld (%s), Length: %d\n", target, buffer, countLetters(buffer));

    return 0;
}
