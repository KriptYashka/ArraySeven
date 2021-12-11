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

void testû(void)
{
    int err_cnt = 0;

    // check_seven

    {
        int a[] = { 1, 2, 3 };
        int res[1];
        int count1 = 3;
        int count2 = 0;
        int* seven = check_seven(a, count1, &count2);
        if (arrcmp(a, count1, res, count2)) {
            err_cnt++;
        }
        free(seven);
    }
    {
        int a[] = { 7, 2, 3 };
        int res[] = { 7 };
        int count1 = 3;
        int count2 = 0;
        int* seven = check_seven(a, count1, &count2);
        if (arrcmp(a, count1, res, count2)) {
            err_cnt++;
        }
        free(seven);
    }
    {
        int a[] = { -7, -177, -107 };
        int res[] = { -7, -177, -107 };
        int count1 = 3;
        int count2 = 0;
        int* seven = check_seven(a, count1, &count2);
        if (arrcmp(a, count1, res, count2)) {
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


    printf("%s: %s\n", __func__, err_cnt ? "FAILED" : "OK");
}