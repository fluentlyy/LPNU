#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 100000
/* --------------------------------------------------- */
void randomArray(int *arr){
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++){
        *(arr + i) = rand();
    }
}

void copyIntArr(int *arr1, int *arr2){
    for(int i = 0; i < SIZE; i++){
        *(arr1 + i) = *(arr2 + i);
    }
}

int areEqual(int *arr1, int *arr2){
    for(int i = 0; i < SIZE; i++){
        if(*(arr1 + i) != *(arr2 + i)) return 0;
    }
    return 1;
}
/* --------------------------------------------------- */

void swap(int array[], long pos1, long pos2)
{
    long tmp;
    tmp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = tmp;
}

void qs_sort(int array[], long start, long end)
{
    long head = start, tail = end - 1, tmp;
    long diff = end - start;
    long pe_index;

    // якщо залишилося менше двох елементів
    if (diff < 1) return;
    if (diff == 1) {
        if (array[start] > array[end]) {
            swap(array, start, end);
        }
        return; // кінець рекурсії
    }

    // пошук індексу розділяючого елементу pe_index
    long m = (start + end) / 2;
    if (array[start] <= array[m]) {
        if (array[m] <= array[end]) pe_index = m;
        else if (array[end] <= array[start]) pe_index = start;
        else pe_index = end;
    }
    else {
        if (array[start] <= array[end]) pe_index = start;
        else if (array[end] <= array[m]) pe_index = m;
        else pe_index = end;
    }

    long pe = array[pe_index]; // сам розділяючий елемент
    swap(array, pe_index, end);

    while (1) {
        while (array[head] < pe)
            ++head;
        while (array[tail] > pe && tail > start)
            --tail;
        if (head >= tail) break;
        swap(array, head++, tail--);
    }

    swap(array, head, end);
    long mid = head;
    qs_sort(array, start, mid - 1); // рекурсивний виклик для 1-ої підмножини
    qs_sort(array, mid + 1, end);   // рекурсивний виклик для 2-ої підмножини
}
/* --------------------------------------------------- */
void bubble_sort(int *arr){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE - i - 1; j++){
             if(*(arr + j) > *(arr + (j + 1))){
                swap(arr, j, j + 1);
             }
        }
    }
}

int main(){
    int array1[SIZE];
    int array2[SIZE];

    randomArray(array1);
    copyIntArr(array2, array1);

    if(areEqual(array1, array2)){
        printf("Arrays are equal before sorting\n");
    }

    printf("----------------------------------\n");

    clock_t startQs = clock();
    qs_sort(array1, 0, SIZE - 1);
    clock_t endQs = clock();

    clock_t startBubble = clock();
    bubble_sort(array2);
    clock_t endBubble = clock();

    double resQs = (double)(endQs - startQs) / CLOCKS_PER_SEC;
    double resBubble = (double)(endBubble - startBubble) / CLOCKS_PER_SEC;

    printf("Quick sort worked %f sec.\n", resQs);
    printf("Bubble sort worked %f sec.\n", resBubble);

    printf("----------------------------------\n");

    if(areEqual(array1, array2)){
        printf("Arrays are equal after sorting\n");
    }

    return 0;
}