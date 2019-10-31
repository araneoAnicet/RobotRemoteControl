#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Привет Мир!" << endl;
    return 0;
}
