#include <iostream>

using namespace std;


int sum(int n){
    if(n == 0) return 0;
    else return (n+sum(n-1));
}

int sum1(int n){
    int s = 0;
    for(int i = 1; i<=n; i++){
        s+=i;
    }
    return s;
}

int sum2(int n){
    return n*(n+1)/2;
}
int main()
{
    printf("%d ", sum(233));
    return 0;
}
