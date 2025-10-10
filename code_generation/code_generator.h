#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include "../tree/tree.h"

typedef unsigned int reg_index;

reg_index current_register;

FILE *target_file;

reg_index codegen(tnode *t, int startLabel, int endLabel);
reg_index get_register();
reg_index free_register();

int last_used_label;
int stack_top;

int get_label();

reg_index codegen_evaluate_expression(tnode *t);
reg_index codegen_operation(tnode *t, reg_index left_expression, reg_index right_expression);
reg_index codegen_add_two_registers(reg_index r1, reg_index r2);
reg_index codegen_add_two_numbers(int num1, int num2);
reg_index codegen_subtract_two_registers(reg_index r1, reg_index r2);
reg_index codegen_multiply_two_registers(reg_index r1, reg_index r2);
reg_index codegen_divide_two_registers(reg_index r1, reg_index r2);
reg_index codegen_mod_two_registers(reg_index r1, reg_index r2);
reg_index codegen_less_than_two_registers(reg_index left_expression, reg_index right_expression);
reg_index codegen_less_than_equal_two_registers(reg_index left_expression, reg_index right_expression);
reg_index codegen_greater_than_two_registers(reg_index left_expression, reg_index right_expression);
reg_index codegen_greater_than_equal_two_registers(reg_index left_expression, reg_index right_expression);
reg_index codegen_not_equal_two_registers(reg_index left_expression, reg_index right_expression);
reg_index codegen_equal_two_registers(reg_index left_expression, reg_index right_expression);
reg_index codegen_or_two_registers(reg_index left_expression, reg_index right_expression);
reg_index codegen_and_two_registers(reg_index left_expression, reg_index right_expression);
void codegen_jump_to_label(int label);
void codegen_jump_to_label_if_zero(reg_index r, int label);
void codegen_jump_to_label_if_not_zero(reg_index r, int label);
void codegen_label_definition(int label);
void codegen_set_int_value_to_register(reg_index r, int value);
void codegen_set_str_value_to_register(reg_index r, char *value);

void codegen_generate_header();
void codegen_add_breakpoint();
void codegen_initialize_stack(int addr);
void codegen_store_in_stack(reg_index reg, int addr);
void codegen_store_in_stack_with_registers(reg_index src, reg_index dest);
reg_index codegen_read_from_stack(int addr);
reg_index codegen_read_from_stack_with_register(reg_index addr);
void codegen_print_address(int addr);
void codegen_print_register(reg_index reg);
void codegen_read_to_address(int addr);
void codegen_read_to_register(reg_index reg);
void codegen_call_exit();

reg_index codegen_array(tnode *t);
reg_index codegen_get_array_offset(dimNode *decl, dimNode *node);

#endif