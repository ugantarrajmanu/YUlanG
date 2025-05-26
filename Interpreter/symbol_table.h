#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAX_VARS 100

typedef struct {
    char* name;
    char* type;
    int value;
} symbol;

symbol symbol_table[MAX_VARS];      // symbol table with maximum of 100 variables
int symbol_count = 0;       // number of variables in the symbol table

// Function Declaration
int lookup(char* name);     // for loocking for a variable
void insert(char* name, char* type, int value);     // for inserting a variable
int getValue(char* name);       // for getting the value of a variable
void setValue(char* name, int value);       // for setting the value of a variable

#endif