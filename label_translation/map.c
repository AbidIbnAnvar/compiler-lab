#include "map.h"

int map_size;

void put(const char *key, int value)
{
    for (int i = 0; i < map_size; i++)
    {
        if (strcmp(map[i].key, key) == 0)
        {
            map[i].value = value;
            return;
        }
    }
    strcpy(map[map_size].key, key);
    map[map_size].value = value;
    map_size++;
}

int get(const char *key)
{
    for (int i = 0; i < map_size; i++)
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
    for (int i = 0; i < map_size; i++)
    {
        printf("%s: %d", map[i].key, map[i].value);
        if (i < map_size - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");
}