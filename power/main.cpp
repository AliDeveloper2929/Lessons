#include <iostream>

using namespace std;

int power(int m, int n){
    if(n == 0) return 1;
    return m*power(m, n-1);
}

int power3(int m, int n){
    if(n == 0) return 1;
    if(n%2 == 0) return power3(m*m, n/2);
    else return m*power3(m*m, (n-1)/2);

}

int power1(int m, int n){
    if(n == 0) return 1;
    else{
        int result = 1;
        for(int i = 1; i<=n; i++)
            result = result*m;
        return result;
    }

}
int main()
{
    cout << power3(5, 4) << endl;
    return 0;
}
