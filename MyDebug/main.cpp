#include <iostream>

using namespace std;

int main()
{

    cout << "Hello world!" << endl;
    int sum = 0;
    int nums[] = {10, 20, 30, 40, 50};
    for(auto x:nums){
        sum+=x;
    }
    cout << sum;
    return 0;
}
