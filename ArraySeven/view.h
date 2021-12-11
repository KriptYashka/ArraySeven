#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <assert.h>

int* check_seven(int* arr, int arr_count, int* seven_count) {
    assert(arr_count >= 0);
    if (arr_count < 0) {
        return NULL;
    }
    *seven_count = 0;
    int* res = (int*)malloc(arr_count * sizeof(int));
    for (int i = 0; i < arr_count; ++i) {
        if (abs(arr[i]) % 10 == 7) {
            res[(*seven_count)++] = arr[i];
        }
    }
    return res;
}


void set_seven(int* arr, int arr_count, int* seven) {
    assert(arr_count >= 0);
    if (arr_count < 0) {
        return NULL;
    }
    int index_seven = 0;
    for (int i = 0; i < arr_count; ++i) {
        if (abs(arr[i]) % 10 == 7) {
            arr[i] = seven[index_seven++];
        }
    }
}

void sort(int data[], int n) {
    assert(n >= 0);
    if (n < 0) {
        return NULL;
    }
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