#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lookup(char *name)
{
    for (int i = 0; i < symbol_count; i++)
    {
        if (strcmp(symbol_table[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

void insert(char *name, char *type, int value)
{
    int index = lookup(name);
    if (index == -1 && symbol_count < MAX_VARS){
        symbol_table[symbol_count].name = name;
        symbol_table[symbol_count].type = type;
        symbol_table[symbol_count].value = value;
        symbol_count++;
    } else if (index != -1) {
        // throw error
        printf("Error: Variable '%s' already exists in the symbol table.\n", name);
        exit(1);
    }
}

int getValue(char* name) {
    int index = lookup(name);
    if (index != -1) {
        return symbol_table[index].value;
    } else {
        // throw error
        printf("Error: Variable '%s' does not exist in the symbol table.\n", name);
        exit(1);
    }
}

void setValue(char* name, int value) {
    int index = lookup(name);
    if (index != -1) {
        symbol_table[index].value = value;
    } else {
        // throw error
        printf("Error: Variable '%s' does not exist in the symbol table.\n", name);
        exit(1);
    }
}

