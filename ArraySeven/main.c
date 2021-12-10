#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

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

void sort(int data[], int n) {
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

#define OK                   0
#define ERR_FILE_EMPTY      -1
#define ERR_NO_FILE         -2
#define ERR_EMPTY_LINE      -3
#define ERR_MORE_LINES      -4
#define ERR_LONG_LINE       -5
#define ERR_INVALID_PARAM   -6

int main() {
    setlocale(LC_ALL, "");
    char path_in[250];
    char path_out[250] = "result.txt";
    gets(path_in);
    //gets(path_out);
    FILE* fin = fopen(path_in, "r");
    FILE* fout = fopen(path_out, "w");
    

    if (fin == NULL) {
        fprintf(fout, "Файл не найден.\n");
        printf("Файл не найден.\n");
        fclose(fout);
        return ERR_NO_FILE;
    }
    else if (feof(fin)) {
        fprintf(fout, "Файл пуст.\n");
        printf("Файл пуст.\n");
        fclose(fout);
        return ERR_FILE_EMPTY;
    }
    int row = 0;
    while (!feof(fin))
    {
        char tmp[51] = "";
        fgets(tmp, sizeof(tmp), fin);
        if (!strlen(tmp)) {
            fprintf(fout, "Некорректные данные.\n");
            printf("Некорректные данные.\n");
            fclose(fout);
            return ERR_EMPTY_LINE;
        }
        if (row++ > 5) {
            fprintf(fout, "Некорректные данные.\n");
            printf("Некорректные данные.\n");
            fclose(fout);
            return ERR_MORE_LINES;
        }
        if (strlen(tmp) > 50) {
            fprintf(fout, "Некорректные данные.\n");
            printf("Некорректные данные.\n");
            fclose(fout);
            return ERR_LONG_LINE;
        }
    }

    fseek(fin, 0, SEEK_SET);
    
    while (!feof(fin)) {
        char buffer[80];
        fgets(buffer, 80, fin);

        int arr_count = 0, seven_count = 0;
        int* arr = (int*)malloc(100 * sizeof(int));

        char s[50];
        int erase = 0;
        int cod = sscanf(buffer, "%d", arr + arr_count++);
        while (cod != EOF) {
            if (cod == 0) {
                fprintf(fout, "Некорректные данные. Символ в файле.\n");
                printf("Некорректные данные. Символ в файле.\n");
                fclose(fout);
                return ERR_INVALID_PARAM;
            }
            sscanf(buffer, "%s", s);
            erase = erase + strlen(s) + 1;
            strnset(buffer, ' ', erase);
            cod = sscanf(buffer, "%d", arr + arr_count++);
        }
        arr_count--;

        int* seven = check_seven(arr, arr_count, &seven_count);
        sort(seven, seven_count);
        set_seven(arr, arr_count, seven);

        for (int i = 0; i < arr_count; ++i) {
            printf("%d ", arr[i]);
            fprintf(fout, "%d ", arr[i]);
        }
        printf("\n");
        fprintf(fout, "\n");
        free(arr);
        free(seven);

    }
    
    

    fclose(fin);
    fclose(fout);
    return 0;
}