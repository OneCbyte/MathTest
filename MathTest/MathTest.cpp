#include <iostream>
#include <cstdlib>
#include <ctime>
#include "lib.h"

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    MathTest test(5, 1, 20);
    test.run();
    return 0;
}

