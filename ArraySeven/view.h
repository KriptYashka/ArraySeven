#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <assert.h>

int* check_seven(int* arr, int arr_count, int* seven_count) {
    *seven_count = 0;
    int* res = (int*)malloc(100 * sizeof(int));
    for (int i = 0; i < arr_count; ++i) {
        if (arr[i] % 10 == 7) {
            res[(*seven_count)++] = arr[i];
        }
    }
    return res;
}


void set_seven(int* arr, int arr_count, int* seven) {
    assert(arr_count >= 0);
    int index_seven = 0;
    for (int i = 0; i < arr_count; ++i) {
        if (arr[i] % 10 == 7) {
            arr[i] = seven[index_seven++];
        }
    }
}

void sort(int data[], int n){
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = (n - 1); j >= (i + 1); j--) {
            if (data[j] < data[j - 1]) {
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;
            }
        }
    }
}