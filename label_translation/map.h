#ifndef MAP_H
#define MAP_H

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
int map_size;

void put(const char *key, int value);
int get(const char *key);
void print_map();

#endif