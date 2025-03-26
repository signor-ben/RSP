#include <iostream>

using namespace std;

int main()
{
    int* arr;
    arr = new  int[10];

    for(int i = 0;i< 10; i++)
    {
        arr[i] = i;
    }


    cout << arr[5] << endl;

    delete[] arr;

    return -1;
}