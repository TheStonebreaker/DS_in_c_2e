#ifndef _MY_STRING_H
#define _My_STRING_H

#include <string.h>

void strnins(char *des, char *src, int i);
void strnins2(char *des, char *src, int i);
int	nfind(char *string, char *pat);
int pmatch(char *string, char *pat);
void fail(char *pat);

#endif
