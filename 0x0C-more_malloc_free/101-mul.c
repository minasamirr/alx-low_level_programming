#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int is_digit(const char *str) {
    while (*str) if (*str < '0' || *str > '9') return 0;
    return 1;
}

char *multiply(const char *n1, const char *n2) {
    
	char *s;
	int l1 = strlen(n1), l2 = strlen(n2), l = l1 + l2, i, j;
    int *r = calloc(l, 4);
    if (!r) exit(98);

    for (i = l1; i--;)
        for (j = l2; j--; r[i + j + 1] += (n1[i] - 48) * (n2[j] - 48))
            r[i + j] += r[i + j + 1] / 10, r[i + j + 1] %= 10;

    while (*r == 0) l--, r++;

    s = malloc(l + 1);
    if (!s) exit(98);

    for (i = 0; i < l; i++) s[i] = r[i] + 48;
    s[l] = '\0';

    free(r);
    return s;
}

int main(int ac, char **av) {
    
	char *res;
	if (ac != 3 || !is_digit(av[1]) || !is_digit(av[2])) {
        printf("Error\n");
        return 98;
    }

    res = multiply(av[1], av[2]);
    printf("%s\n", res);
    free(res);
    return 0;
}

