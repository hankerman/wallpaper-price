#include <iostream>
#include "Flat.h"

int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите колличество комнат в квартире: ";
    cin >> n;
    cout << endl;

    Flat flat(n);
    flat.fill();
    flat.fillWallpapers();
    flat.print();
}
