#include <iostream>
int main ()
{
    int a[][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };
    for (int i = 0; i < 3; ++i) {
        cout << a[i] << endl;
    }
}
