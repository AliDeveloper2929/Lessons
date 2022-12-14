#include <stdio.h>
#include <stdlib.h>

// this prints missing elements whose difference is 1 in an array: 3, 7, 4, 9, 12, 6, 11, 10   missings are: 5, 8,
void findMissingElements(int A[], int length){
    int min = A[0], max = A[0];
    for(int i=1; i<length; i++){
        if(A[i] < min)
            min = A[i];
        else if(A[i] > max)
            max = A[i];
    }

    // min = 3; max = 12 // so we need an array of 12-3+1 = 10 size
    int lenHashArr = max-min+1;
    int* hashArr = (int*)malloc(lenHashArr * sizeof(int));
    for(int i =0; i<lenHashArr; i++) hashArr[i] = 0;

    for(int i = 0; i<length; i++){
        hashArr[ A[i]-min ] += 1;
    }

    for(int i =0; i<lenHashArr; i++){
        if(hashArr[i] == 0)
            printf("%d, ", i+min);
    }
}

void findDuplicates(int A[], int len){
    int min = A[0];
    int max = A[0];
    for(int i=1; i<len; i++){
        if(A[i] < min) min = A[i];
        else if(A[i] > max) max = A[i];
    }
    int lenHashArr = max-min+1;
    int* hashArr = (int*)malloc(lenHashArr*sizeof(int));
    for(int i=0; i<lenHashArr; i++) hashArr[i] = 0;

    for(int i=0; i<len; i++){
        hashArr[ A[i]-min ] ++;
    }

    for(int i= 0; i<lenHashArr; i++){
        if(hashArr[i] >1){
            printf("The number %d is appeared %d times in array\n", i+min, hashArr[i]);
        }
    }
}

// find a pair with sum k (a+b = k)

void findPair(int A[], int len, int sum){
    for(int i=0; i<len-1; i++){
        for(int j = i+1; j<len; j++){
            if(A[i] + A[j] == sum){
                printf("The sum of elements %d and %d which are at index %d and %d is %d\n", A[i], A[j], i, j, sum);
            }
        }
    }
}

void findPairUsingHash1(int A[], int len, int sum){
    int min = A[0], max = A[0];
    for(int i = 1; i<len; i++){
        if(A[i] < min) min= A[i];
        else if(A[i] > max) max= A[i];
    }

    int lenHashArr = max-min+1;
    int* hashArr = (int*)malloc(lenHashArr * sizeof(int));
    for(int i=0; i<lenHashArr; i++) hashArr[i] = 0;

    for(int i = 0; i<len; i++){
        hashArr[ A[i]-min ] +=1;
    }

    int i=0, j = lenHashArr-1;
    while(i<j){
        while(hashArr[i] == 0) i++;
        while(hashArr[j] == 0) j--;
        if( ( i+min + j+min ) == sum ){
            printf("Sum of elements %d and %d is %d\n", i+min, j+min, sum);
            i++; j--;
        }
        else if( (i+min + j+min) > sum )
            j--;
        else i++;
    }
}


void findPairUsingHash2(int A[], int len, int sum){
    int min = A[0], max = A[0];
    for(int i = 1; i<len; i++){
        if(A[i] < min) min= A[i];
        else if(A[i] > max) max= A[i];
    }

    int lenHashArr = max-min+1;
    int* hashArr = (int*)malloc(lenHashArr * sizeof(int));
    for(int i=0; i<lenHashArr; i++) hashArr[i] = 0;

    for(int i = 0; i<len; i++){
        int requiredNum = sum-A[i];
        if(hashArr[requiredNum-min] != 0)
            printf("The sum of elements %d and %d is %d\n", A[i], requiredNum, sum);
        hashArr[A[i] -min] ++;
    }
}

int main()
{
    int A[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14, -6, -4, 0};
    int lenA = sizeof(A)/sizeof(A[0]);
    findPair(A, lenA, 10);
    printf("\n");
    //findDuplicates(A, lenA);
    findPairUsingHash1(A, lenA, 10);
    findPairUsingHash2(A, lenA, 10);
    return 0;
}
