#include <stdio.h>

int main() {
    int y[5];
    int isInjective = 1;
    int isSurective = 1;

    for (int x = 0; x < 5; x++) {
        while (1) {
            printf("Enter y for x%d: ", x + 1);
            int scanRes = scanf("%d", y + x);
            if (scanRes != 1) {
                printf("Error! Enter an integer value between 1 and 5.\n");
                while (getchar() != '\n');
            } else if (y[x] < 1 || y[x] > 5) {
                printf("Error! Enter a value between 1 and 5.\n");
            } else {
                break;
            }
        }
    }

    int wrong_x = -1;
    int wrong_y = -1;

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (y[i] == y[j]) {
                isInjective = 0;
                isSurective = 0;
                wrong_x = j + 1;
                wrong_y = y[j];  
                break;
            }
        }
        if (!isInjective) break;
    }

    printf("\n--- RESULT ---\n");

    if (isInjective) {
        printf("Function is injective\n");
    } else {
        printf("Function is NOT injective\n");
    }

    if (isSurective) {
        printf("Function is surjective\n");
    } else {
        printf("Function is NOT surjective\n");
    }

    if (isInjective && isSurective) {
        printf("Function is bijective\n");
    } else {
        printf("Function is NOT bijective\n");
    }

    if (!isInjective) {
        printf("\nWrong pair: (%d, %d)\n", wrong_x, wrong_y);

        int fixed_y = -1;
        for (int val = 1; val <= 5; val++) {
            int used = 0;
            for (int k = 0; k < 5; k++) {
                if (y[k] == val) {
                    used = 1;
                    break;
                }
            }
            if (!used) {
                fixed_y = val;
                break;
            }
        }
        printf("Fixed pair: (%d, %d)\n", wrong_x, fixed_y);
    }

    printf("\nSet B for which the function is surjective: { ");
    for (int val = 1; val <= 5; val++) {
        int present = 0;
        for (int k = 0; k < 5; k++) {
            if (y[k] == val) {
                present = 1;
                break;
            }
        }
        if (present) {
            printf("%d ", val);
        }
    }
    printf("}\n");

    return 0;
}