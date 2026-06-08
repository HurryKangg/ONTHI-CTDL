#include <stdio.h>
#include <conio.h>

//Tìm kiếm và sắp xếp cây nhị phân
int binarySearch(int a[], int n, int x){
    int left = 0;
    int right = n - 1;
    //Search value
    while(left <= right){
        int mid = (left + right) / 2;
        if(a[mid] == x){
            return mid;
        }else if(a[mid] < x){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}
int main(){
    int a[7] = {11,0,13,15,18,17,14};
    int result = binarySearch(a, 7, 15);
    if(result != -1){
         printf("Index of 15: %d", result);
    }else{
        printf("15 not found in the array.");
    }
   
    return 0;
}
