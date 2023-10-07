#ifndef MAIN_H
#define MAIN_H

char *multiply(char *num1, char *num2);
int perform_multiplication(char *num1, char *num2, int *result);
int is_positive_integer(char *str);
#include <stdio.h>
#include <stdlib.h>
int _putchar(char c);
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


#endif/*MAIN_H*/
