#include <stdio.h>
#include <stdlib.h>
//below functions work for only sorted arrays

// this function returns single missing element from an array -> which is arithmetic progression.
int findSingleMissingEle(int A[], int length){
    int d1 = A[1] - A[0];
    int d2 = A[2] - A[1];
    int d;
    if(d1<=d2) d = d1;
    else d = d2;
    for(int i = 0; i<length-1; i++){
        if(A[i+1] - A[i] != d) return A[i+1]-d;
    }
    printf("There is no missing element in Arithmetic progression\n");
    return -1;
}

// 2-way of finding missing element
int findSingleMissingEle2(int A[], int length){
    int a1 = A[0];
    int a_n = A[length-1];
    int d;
    int d1 = A[1] - A[0];
    int d2 = A[2] - A[1];
    if(d1 <= d2) d = d1;
    else d = d2;
    int n = (a_n - a1)/d + 1;
    if(length == n){
        printf("There is no missing element\n");
        return -1;
    }
    int sum = (a1 + a_n)*(length+1)/2;
    int sumOfA = 0;
    for(int i = 0; i<length; i++) sumOfA +=A[i];
    return sum - sumOfA;
}

// finding missing elements. d = 1;
void findMissingElements(int A[], int length){
    int a1 = A[0];
    int diff = A[0] - 0; // diff is difference between element and its index
    for(int i = 0; i<length; i++){
        if(A[i]-i != diff){
            while(diff < A[i]-i ){
                printf("%d, ", diff+i);
                diff++;
            }
        }
    }
}
int main()
{
    int B[] = {6, 11, 16, 21, 26, 31, 36, 41, 51};
    int A[] = {5, 7, 8, 9, 11, 14, 15, 16, 17};
    findMissingElements(A, 9);
    return 0;
}
