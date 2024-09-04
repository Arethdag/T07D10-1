#include <stdio.h>
#include <stdlib.h>

int inputed(float *a, int size);
int input(int **a, int h, int w);
int output(int **a, int h, int w);
int print(float *a, int size);
int decimal(float a);
int switcher();

int ** alloc_static(int height, int widht);
int ** alloc_D1(int height, int width);
int ** alloc_D2(int height, int width);
int ** alloc_D3(int height, int width);


int main() {
    int mode = switcher();

    float h, w;
    if (!(inputed(&h, 1)) || (!(inputed(&w,1)))) { // ввод размеров
        printf("n/a");
        return 0;
    }

    int ** a = {0};

    switch (mode) {
        case 1: {
            a = alloc_static((int)h, (int)w);
            break;
        }
        case 2: {
            a = alloc_D1((int)h, (int)w);
            break;
        }
        case 3: {
            a = alloc_D2((int)h, (int)w);
            break;
        }
        case 4: {
            a = alloc_D3((int)h, (int)w);
            break;
        } 
        default: {
            printf("n/a");
            return 0;
        }
    }
    
    input(**a, h, w);
    output(**a, h, w);

    return 0;
}

int inputed(float *a, int size) {  // ввод целочисленного одномерного массива в память начиная с указателя а
    for (int i = 0; i < size; i++) {
        if (!(scanf("%f", &a[i])) || !(decimal(a[i]))) {
            return 0;
        }
        a[i] = (int)(a[i]);
    }
    return 1;
}

int input(int **a, int h, int w) {  // вводит двумерный массив
    for (int j = 0; j < h; j++) {
        for (int i = 0; i < w; i++) {
            if (!inputed(a[j][i], 1)) return 0;
        }
    }
    return 1;
}

int output(int **a, int h, int w) {  // выводит двумерный массив
    for (int j = 0; j < h; j++) {
        for (int i = 0; i < w; i++) {
            if (!print(a[j][i], 1)) return 0;
        }
    }
    return 1;
}

int print(float *a, int size) {  // выводит целоцисленный одномерный массив длины size
    int p;
    for (p = 0; p < size; p++) {
        printf("%d", (int)(a[p]));
        if (p != size - 1) {
            printf(" ");
        }
    }
    return 1;
}

int decimal(float a) {
    if (a != (int)a) {
        return 0;
    } else {
        return 1;
    }
}

int switcher() {
    float * mode;
    if (!inputed(mode, 1))
        return (int)mode;
    else 
        return NULL;
}

int ** alloc_static(int height, int widht) {
    int a[100][100];
    return a;
}

int ** alloc_D1(int height, int width) {  // куча массивов
    int *a = (int *) malloc (height * sizeof (int *));
    for (int i = 0; i < width; i++) {
        int *a = (int*) malloc (width * sizeof(int));
    }
    return &a;
}

int ** alloc_D2(int height, int width) {  //один большой массив
    int **a = (int **) malloc (height * sizeof(int *) + height * width * sizeof(int));
    
    // соединяем указатели
    for (int i = 0; i < height; i++) {
        *(a+i) = (&a + height + i * width);  
    }

    return a;
}

int ** alloc_D3(int height, int width) {  //два массива - один с указателями другой со значениями
    int **a = (int **) malloc (height * sizeof(int *));
    int *b = (int *) malloc (width * sizeof(int));

    // соединяем указатели
    for (int i = 0; i < height; i++) {
        *(a+i) = (&b + height + i * width);
    }

    return a;
}