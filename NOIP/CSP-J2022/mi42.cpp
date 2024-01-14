#include <algorithm>
#include <cstdio>
using namespace std;
void shell_sort(int arr[], int len){
    int gap, i, j;
    int temp;
    for (gap = len >> 1;gap > 0; gap >>= 1){
        for (i = gap; i < len; i++){
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] >= temp; j -= gap){
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = temp;
        }
    }    
}
int main() {
        int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 64, 35, 9, 70 };
        int len = sizeof(arr) / sizeof(*arr);
//        shell_sort(arr,len);
        sort(arr, arr+len);
        int i;
        for (i = 0; i < len; i++){
            printf("%d ",arr[i]);
        }
        return 0;
}