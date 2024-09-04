#include <stdio.h>
#include <stdlib.h>

int inputed(float *a, int size);
int decimal(float a);
int sorted(float *a, int size);
int print(float *a, int size);

int main() {
    float n;
    if (!scanf("%f", &n) || !decimal(n)) {  // ввод числа n
        printf("n/a");
        return 0;
    }

    float * a = NULL;
    a = (float*) malloc(n * sizeof(float));  // инициализация массива

    if (inputed(a, n) * sorted(a, n)) {  // ввод массива
        print(a, n);
    } else {
        printf("n/a");
    }
    free(a);
    return 0;
}

int decimal(float a) {
    if (a != (int)a) {
        return 0;
    } else {
        return 1;
    }
}

int inputed(float *a, int size) {
    for (int i = 0; i < size; i++) {
        if (!scanf("%f", &a[i]) || !decimal(a[i])) {
            return 0;
        }
    }
    return 1;
}

int sorted(float *a, int size) {
    for (int i = 0 ; i < size - 1; i++) {
        for (int p = 0 ; p < size - i - 1 ; p++) {
            if (a[p] > a[p + 1]) {  // сравниваем два соседних элемента.
                int tmp = a[p];     // если они идут в неправильном порядке, то
                a[p] = a[p + 1];   // меняем их местами.
                a[p + 1] = tmp;
            }
        }
    }
    return 1;
}

int print(float *a, int size) {
    int p;
    for (p = 0; p < size; p++) {
        printf("%d", (int)(a[p]));
        if (p != size - 1) {
            printf(" ");
        }
    }
    return 1;
}
