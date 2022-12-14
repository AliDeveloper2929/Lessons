#include <iostream>

using namespace std;

int func(int n){
    if(n>0){
        return func(n-1) + n;
    }
    else return 0;
}

int func1(int n){
    static int num = 0;
    if(n>0){
        num++;
        return func1(n-1) + num;
    }
    else return 0;
}

int main()
{
    int x = 5;
    printf("%d ", func(x));

    printf("\n%d ", func1(x));
    return 0;
}
