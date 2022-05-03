#include<iostream>
using namespace std;

int main()
{   
    int x;
    cin>>x;
    int *arr = new int(x);
    for(int n=0; n<x; n++)
    {
        cin >> arr[n];
    }

    for (int n=0; n<x; n++)
    {
        cout << arr[n];
    }
    return 0;
}