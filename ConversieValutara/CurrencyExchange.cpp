#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "ArgumentParser.h"
#include "ExchangeCalculator.h"

int main(int argc, char* argv[]) {

    ArgumentParser arg(argc, argv);

    string from,to;
    double amount;
    cout << "Introduce the currency that you want to exchange from:";
    cin >> from;
    cout << "Introduce the currency that you want to exchange to";
    cin >> to;
    cout << "Introduce the amount";
    cin >> amount;
    ExchangeCalculator c;
    cout << "The resulted amount is = "<<c.Convert(amount, from, to);

    return 0;
}