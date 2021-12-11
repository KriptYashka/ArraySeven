#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include "view.h"

#define OK                   0
#define ERR_INVALID_PARAM   -1
#define ERR_NO_DATA         -2

int arrcmp(int* arr1, int count1, int* arr2, int count2) {
    if (count1 != count2) return 0;
    for (int i = 0; i < count1; ++i) {
        if (arr1[i] != arr2[i]) return 0;
    }
    return 1;
}

void main()
{
    int err_cnt = 0;

    // check_seven

    {
        int a[] = { 1, 2, 3 };
        int res[1];
        int count1 = 3;
        int count2 = 0;
        int* seven = check_seven(a, count1, &count2);
        if (0 != count2) {
            err_cnt++;
        }
        free(seven);
    }
    {
        int a[] = { 7, 2, 3 };
        int res[] = { 7 };
        int count_a = 3, count_res = 1;
        int count_seven;
        int* seven = check_seven(a, count_a, &count_seven);
        if (!arrcmp(seven, count_seven, res, count_res)) {
            err_cnt++;
        }
        free(seven);
    }
    {
        int a[] = { -7, -177, -107 };
        int res[] = { -7, -177, -107 };
        int count_a = 3, count_res = 3;
        int count_seven;
        int* seven = check_seven(a, count_a, &count_seven);
        if (!arrcmp(seven, count_seven, res, count_res)) {
            err_cnt++;
        }
        free(seven);
    }
    {
        int a[] = { 1 };
        int count2;
        int* seven = check_seven(a, -1, &count2);
        if (seven != NULL) {
            err_cnt++;
        }
        free(seven);
    }
    // sort
    {
        int a[] = { 1, 2, 3 };
        int res[] = { 1, 2, 3 };
        int count_a = 3, count_res = 3;
        sort(a, count_a);
        if (!arrcmp(a, count_a, res, count_res)) {
            err_cnt++;
        }
    }
    {
        int a[] = { 10, 9, 8, 7, 5 };
        int res[] = { 5, 7, 8, 9, 10 };
        int count_a = 5, count_res = 5;
        sort(a, count_a);
        if (!arrcmp(a, count_a, res, count_res)) {
            err_cnt++;
        }
    }
    {
        int a[] = { 1, 2, 3 };
        int count_a = 3, count_res = 3;
        int count_seven;
        sort(a, count_a);
        if (sort(a, -1) != NULL) {
            err_cnt++;
        }
    }

    printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "OK");
    printf("Have a good day! ^_^");
}