#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct
{
    char key[50];
    int value;
} MapEntry;

MapEntry map[MAX];
int size = 0;