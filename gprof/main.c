#include <stdio.h>
#include <unistd.h>

float
f()
{
    float a = 1;
    for (int i = 0; i < 100000; i++) {
        a = a * 1.01;
    }
    return a;
}

float
g()
{
    float a = 1;
    for (int i = 0; i < 100000; i++) {
        a = a * 1.01;
    }
    return a;
}

int
main()
{
    for (int i = 0; i < 1000; i++) {
        f();
        g();
    }
    return 0;
}