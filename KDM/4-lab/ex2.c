
#include <stdio.h>
#include <string.h>

int main() {
    int ones[] = {1, 3, 6, 7, 8, 9, 10, 13, 14, 15};

    char current[100][5];
    char next[100][5];
    char primes[100][5];
    int used[100];

    int count = 10, nextCount, primeCount = 0;
    int i, j, k, diff, pos, found, changed;

    // Перетворюємо числа у двійкові набори
    for (i = 0; i < count; i++) {
        for (j = 0; j < 4; j++) {
            current[i][j] =
                ((ones[i] >> (3 - j)) & 1) + '0';
        }
        current[i][4] = '\0';
    }

    printf("Starter sets:\n");
    for (i = 0; i < count; i++) {
        printf("%s\n", current[i]);
    }

    do {
        changed = 0;
        nextCount = 0;

        for (i = 0; i < count; i++) {
            used[i] = 0;
        }

        // Порівнюємо кожну пару наборів
        for (i = 0; i < count; i++) {
            for (j = i + 1; j < count; j++) {
                diff = 0;
                pos = -1;
                found = 1;

                for (k = 0; k < 4; k++) {
                    if (current[i][k] != current[j][k]) {
                        if (current[i][k] == '-' ||
                            current[j][k] == '-') {
                            found = 0;
                            break;
                        }

                        diff++;
                        pos = k;
                    }
                }

                if (found && diff == 1) {
                    char temp[5];

                    strcpy(temp, current[i]);
                    temp[pos] = '-';

                    used[i] = 1;
                    used[j] = 1;
                    changed = 1;

                    // Не додаємо однакові набори двічі
                    found = 0;

                    for (k = 0; k < nextCount; k++) {
                        if (strcmp(next[k], temp) == 0) {
                            found = 1;
                        }
                    }

                    if (found == 0 && nextCount < 100) {
                        strcpy(next[nextCount], temp);
                        nextCount++;
                    }
                }
            }
        }

        // Невикористані набори є простими імплікантами
        for (i = 0; i < count; i++) {
            if (used[i] == 0) {
                found = 0;

                for (j = 0; j < primeCount; j++) {
                    if (strcmp(primes[j], current[i]) == 0) {
                        found = 1;
                    }
                }

                if (found == 0 && primeCount < 100) {
                    strcpy(primes[primeCount], current[i]);
                    primeCount++;
                }
            }
        }

        // Наступний етап склеювання
        count = nextCount;

        for (i = 0; i < count; i++) {
            strcpy(current[i], next[i]);
        }

    } while (changed == 1);

    printf("\nSDNF:\n");

    for (i = 0; i < primeCount; i++) {
        if (i > 0) printf(" + ");

        for (j = 0; j < 4; j++) {
            if (primes[i][j] == '-') continue;

            if (primes[i][j] == '0') printf("!");

            if (j == 0) printf("X1");
            if (j == 1) printf("X2");
            if (j == 2) printf("X3");
            if (j == 3) printf("X4");
        }
    }

    printf("\n");
    return 0;
}
