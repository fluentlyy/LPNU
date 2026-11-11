
#include <stdio.h>
#include <string.h>

int main() {
    char received[20];
    int code[13], encoded[13], data[9];
    int i, j, p, parity, syndrome = 0;
    int weight = 0, error = 0;

    printf("Enter a 12-bit sequence: ");
    scanf("%19s", received);


    if (strlen(received) != 12) {
        printf("Error: enter exactly 12 bits.\n");
        return 0;
    }

    for (i = 0; i < 12; i++) {
        if (received[i] != '0' && received[i] != '1') {
            printf("Error: only 0 and 1 are allowed.\n");
            return 0;
        }

        code[i + 1] = received[i] - '0';
    }

    printf("\nReceived code: %s\n", received);


    for (p = 1; p <= 8; p *= 2) {
        parity = 0;

        for (i = 1; i <= 12; i++) {
            if ((i & p) != 0) {
                parity = parity ^ code[i];
            }
        }

        if (parity != 0) {
            syndrome = syndrome + p;
        }
    }

    printf("Error syndrome: %d\n", syndrome);

    if (syndrome == 0) {
        printf("No error detected.\n");
    } else if (syndrome <= 12) {
        code[syndrome] = 1 - code[syndrome];
        error = 1;

        printf("Bit at position %d has been corrected.\n", syndrome);
    } else {
        printf("Syndrome is outside the code range.\n");
        printf("Multiple errors may be present.\n");
        return 0;
    }

    printf("Corrected code: ");

    for (i = 1; i <= 12; i++) {
        printf("%d", code[i]);
    }

    printf("\n");


    data[1] = code[3];
    data[2] = code[5];
    data[3] = code[6];
    data[4] = code[7];
    data[5] = code[9];
    data[6] = code[10];
    data[7] = code[11];
    data[8] = code[12];

    printf("Original sequence: ");

    for (i = 1; i <= 8; i++) {
        printf("%d", data[i]);

        if (data[i] == 1) {
            weight++;
        }
    }

    printf("\nSequence weight: %d\n", weight);


    if (weight == 5) {
        printf("Valid weight: equals 5.\n");
    } else {
        printf("Warning: weight is not equal to 5.\n");
        printf("Multiple errors may be present.\n");
        return 0;
    }


    for (i = 1; i <= 12; i++) {
        encoded[i] = 0;
    }

    encoded[3] = data[1];
    encoded[5] = data[2];
    encoded[6] = data[3];
    encoded[7] = data[4];
    encoded[9] = data[5];
    encoded[10] = data[6];
    encoded[11] = data[7];
    encoded[12] = data[8];

    for (p = 1; p <= 8; p *= 2) {
        parity = 0;

        for (i = 1; i <= 12; i++) {
            if (i != p && (i & p) != 0) {
                parity = parity ^ encoded[i];
            }
        }

        encoded[p] = parity;
    }

    printf("Re-encoded sequence: ");

    for (i = 1; i <= 12; i++) {
        printf("%d", encoded[i]);
    }

    printf("\n");

    return 0;
}
