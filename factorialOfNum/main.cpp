#include <iostream>

using namespace std;

int factorial(int n){
    if(n==0) return 1;
    else return n*factorial(n-1);
}

int factorial2(int n){
    if(n == 0) return 1;
    int result = 1;
    for(int i = 1; i<=n; i++){
        result*=i;
    }
    return result;
}

int main()
{
    cout << factorial(25) << endl;
    return 0;
}
