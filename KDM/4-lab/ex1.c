
#include <stdio.h>

int main() {
    int f[16] = {0};
    int ones[] = {1, 3, 6, 7, 8, 9, 10, 13, 14, 15};
    int i, j, n, bit;

    // Заповнюємо одиничні значення функції
    for (i = 0; i < 10; i++) {
        f[ones[i]] = 1;
    }

    // Таблиця істинності
    printf("Truth table:\n");
    printf("X1 X2 X3 4 | F\n");

    for (i = 0; i < 16; i++) {
        printf("%d %d %d %d | %d\n",
            (i >> 3) & 1,
            (i >> 2) & 1,
            (i >> 1) & 1,
            i & 1,
            f[i]);
    }

    // Досконала диз'юнктивна нормальна форма
    printf("\nDDNF:\n");
    n = 0;

    for (i = 0; i < 16; i++) {
        if (f[i] == 1) {
            if (n > 0) printf(" + ");
            printf("(");

            for (j = 3; j >= 0; j--) {
                bit = (i >> j) & 1;

                if (j == 3) {
                    if (bit == 0) printf("!X1");
                    else printf("X1");
                } else if (j == 2) {
                    if (bit == 0) printf("!X2");
                    else printf("X2");
                } else if (j == 1) {
                    if (bit == 0) printf("!X3");
                    else printf("X3");
                } else {
                    if (bit == 0) printf("!X4");
                    else printf("X4");
                }

                if (j > 0) printf(" * ");
            }

            printf(")");
            n++;
        }
    }

    // Досконала кон'юнктивна нормальна форма
    printf("\n\nDKNF:\n");
    n = 0;

    for (i = 0; i < 16; i++) {
        if (f[i] == 0) {
            if (n > 0) printf(" * ");
            printf("(");

            for (j = 3; j >= 0; j--) {
                bit = (i >> j) & 1;

                if (j == 3) {
                    if (bit == 1) printf("!X1");
                    else printf("X1");
                } else if (j == 2) {
                    if (bit == 1) printf("!X2");
                    else printf("X2");
                } else if (j == 1) {
                    if (bit == 1) printf("!X3");
                    else printf("X3");
                } else {
                    if (bit == 1) printf("!X4");
                    else printf("X4");
                }

                if (j > 0) printf(" + ");
            }

            printf(")");
            n++;
        }
    }

    printf("\n");
    return 0;
}
