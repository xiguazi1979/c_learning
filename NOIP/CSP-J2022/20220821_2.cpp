#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
void bubble_sort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void selection_sort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = arr[i];
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < min) {
                int temp = min;
                min = arr[j];
                arr[j] = temp;
                arr[i] = min;
            }
        }
    }
}

void insertion_sort (int arr[], int len) {
    for (int i = 0; i < len; i++) {
        int key = arr[i];
        int j = i - 1;
        while ((j >= 0) && (arr[j] > key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void shell_sort (int arr[], int len) {
    int i, j, gap;
    int temp;
    for (gap = len >> 1; gap > 0; gap >>= 1) {
        for (i = gap + 1; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap) {
                arr[j + gap] = arr[j];
                
            }
            arr[j + gap] = temp; 
        }
    }
}

void merge_sort(int arr[], int len) {
    int *a = arr;
    int *b = (int*) malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg += seg) {
        for (start = 0; start < len; start += seg * 2) {
            int k = start;
            int start1 = start;
            int end1 = min(start + seg, len);
            int start2 = end1;
            int end2 = min(start + 2 * seg, len);
            while (start1 < end1 && start2 < end2) {
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            }
            while (start1 < end1) {
                b[k++] = a[start1++];
            }
            while (start2 < end2) {
                b[k++]=  a[start2++];
            }
        }
        int *temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        for (int i = 0; i < len; i++) {
            arr[i] = a[i];
        }
    }
}
typedef struct _Range {
    int start, end;
} Range;

Range new_Range (int s, int e){
    Range r;
    r.start = s;
    r.end = e;
    return r;
}

void swap (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quick_sort(int arr[], const int len){
    if (len <= 0){
        return;
    }
    Range r[len];
    int p = 0;
    r[p++] = new_Range(0, len - 1);
    while (p > 0) {
        Range range = r[--p];
        if (range.start > range.end) {
            continue;
        }
        int mid = arr[(range.start + range.end) / 2];
        int left = range.start;
        int right = range.end;
        do{
            while (arr[left] < mid) {
                left++;
            }
            while (arr[right] > mid) {
                right++;
            }  
        }while (left <= right);

        if (left <= right) {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
        if (range.start < right) {
            r[p++] = new_Range(range.start, right);
        }
        if (left < range.end) {
            r[p++] = new_Range(left, range.end);
        }
    }
}

int main() {
        int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
        int len = (int) sizeof(arr) / sizeof(*arr);
        quick_sort(arr, len);
        int i;
        for (i = 0; i < len; i++)
                printf("%d ", arr[i]);
        return 0;
}