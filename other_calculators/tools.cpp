#include <iostream>
#include <iomanip>
#include <cmath>
#include <bits/stdc++.h>
#include <compsim_enums/enums.h>
#include <compsim_classes/event_base.h>


double rdsigfigs(double N, double n)  // rounding to n siginificant figures, taken from: https://www.geeksforgeeks.org/round-off-number-given-number-significant-digits/
{
    int h;
    double l, a, b, c, d, e, i, j, m, f, g;
    b = N;
    c = std::floor(N);

    // Counting the no. of digits to the left of decimal point
    // in the given no.
    for (i = 0; b >= 1; ++i)
        b = b / 10;

    d = n - i;
    b = N;
    b = b * pow(10, d);
    e = b + 0.5;
    if ((float)e == (float)std::ceil(b)) {
        f = (std::ceil(b));
        h = f - 2;
        if (h % 2 != 0) {
            e = e - 1;
        }
    }
    j = std::floor(e);
    m = pow(10, d);
    j = j / m;
    return j;
}


template <typename T>
T absolute(T number)
{
    if number < 0:
        number = -number
    return number
}