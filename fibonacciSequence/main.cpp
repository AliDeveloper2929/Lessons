#include <iostream>

using namespace std;

/*
    fib(n)   =>    0,   1,   1,   2,   3,   5,   8  ....
    n        =>    0,   1,   2,   3,   4,   5,   6  ....
*/
// using recursion.  returns the number at position n
int fib(int n){
    if(n<=1) return n;
    return fib(n-2) + fib(n-1);
}

// using loop
int fib1(int n){
    if(n<=1) return n;
    int x1 = 0; int x2 = 1; int nextFib;
    for(int i = 2; i<=n; i++){ //fib(o), fib(1) is already found
        nextFib = x1+x2;
        x1 = x2;
        x2 = nextFib;
    }
    return nextFib;
}

// memorization method.
int fibArray[10];
int fib3(int n){
    if(n<=1)
    {
        fibArray[n] = n;
        return n;
    }
    else
    {
        if(fibArray[n-2] == -1) fibArray[n-2] = fib3(n-2);
        if(fibArray[n-1] == -1) fibArray[n-1] = fib3(n-1);
        return fibArray[n-2] + fibArray[n-1];
    }
}

int main()
{
    for(int i = 0; i<=10; i++) fibArray[i] = -1;
    cout << fib3(5) << endl;
    return 0;
}
