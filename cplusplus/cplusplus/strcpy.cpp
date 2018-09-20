//
//  strcpy.cpp
//  cplusplus
//
//  Created by junhui cao on 20/09/2018.
//  Copyright © 2018 junhui cao. All rights reserved.
//

#include <stdio.h>
#include <assert.h>

char *strcpy(char *strDest, const char *strScr)
{
    char *address = strDest;
    assert((strDest != NULL) && (strScr != NULL));
    while(*strScr)
    {
        *strDest++ = *strScr++;
    }
    *strDest = '\0';
    return address;
}

int strcmp (const char *str1,const char *str2)
{
    int len = 0;
    assert((str1 != NULL) && (str2 != NULL));
    while(*str1 && *str2 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return *str1-*str2;
}

int main()
{
    char str1[]={"Hello"};
    char str2[]={"World！"};
    
    printf("%d\n",strcmp(str1,str2));
    printf("%s\n",strcpy(str1,str2));
}
