#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include "tree.h"

typedef int reg_index;

reg_index current_register;

FILE *target_file;

reg_index codeGen(tnode *t);
reg_index getReg();
reg_index freeReg();

reg_index codeGen_evaluate_expression(tnode *t);
reg_index codeGen_operation(tnode *t, reg_index left_expression, reg_index right_expression);
reg_index codeGen_add_two_registers(reg_index r1, reg_index r2);
reg_index codeGen_add_two_numbers(reg_index r1, reg_index r2);
reg_index codeGen_subtract_two_registers(reg_index r1, reg_index r2);
reg_index codeGen_multiply_two_registers(reg_index r1, reg_index r2);
reg_index codeGen_divide_two_registers(reg_index r1, reg_index r2);

void generateHeader();
void initializeStack(int addr);
void storeInStack(reg_index reg, int addr);
reg_index readFromStack(int addr);
void printAddress(int addr);
void printRegister(reg_index reg);
void readToAddress(int addr);
void callExit();

#endif