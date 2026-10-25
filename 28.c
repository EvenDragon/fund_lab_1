#include <stdio.h>
#include <math.h>
#define GOAL 1.3077
#define E 0.000001
#define A 1.2
#define B 2


double f(double x)
{
    return x - 2 + sin(1/x);
}


void dichotomy()
{
    double m;
    int c = 0;
    double a = A;
    double b = B;
    while (b - a > E)
    {
        m = (a+b)/2;
        if (f(a)*f(m) < 0)
        {
            b = m;
        }
        else
            a = m;
        c++;
    }
    double ans = (a + b) / 2;
    printf("dichotomy:\tval: %f, goal: %f, accuracy: %f, iter: %d\n", ans, GOAL, fabs(ans-GOAL), c);
}


void iteration() //сходится, так как cos меньше 1 по модулю
{
    double m = (A+B)/2;
    double prM = 100000;
    int c = 0;
    while(fabs(m-prM) > E)
    {
        prM = m;
        m = 2 - sin(1/m);
        c++;
    }
    printf("iteraion:\tval: %f, goal: %f, accuracy: %f, iter: %d\n", m, GOAL, fabs(m-GOAL), c);
}


void newton() 
{
    double m = (A+B)/2;
    double prM = 100000;
    int c = 0;
    while(fabs(m-prM) > E)
    {
        prM = m;
        m = prM - f(prM) / (1 - cos(1/prM) / (prM * prM));
        c++;
    }
    printf("newton:  \tval: %f, goal: %f, accuracy: %f, iter: %d\n", m, GOAL, fabs(m-GOAL), c);
}


int main(void)
{
    dichotomy();
    iteration();
    newton();
    return 0;
}
