#include "map.h"

void put(const char *key, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(map[i].key, key) == 0)
        {
            map[i].value = value;
            return;
        }
    }
    strcpy(map[size].key, key);
    map[size].value = value;
    size++;
}

int get(const char *key)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(map[i].key, key) == 0)
        {
            return map[i].value;
        }
    }
    return -1;
}

void print_map()
{
    printf("{");
    for (int i = 0; i < size; i++)
    {
        printf("%s: %d", map[i].key, map[i].value);
        if (i < size - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");
}