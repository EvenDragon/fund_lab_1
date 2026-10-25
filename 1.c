#include <stdio.h>
#include <math.h>
#define GOAL 3.5265
#define E 0.000001
#define A 3
#define B 4


double f(double x)
{
    return exp(x) + log(x) - 10*x;
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


void iteration()
{
    double m = (A+B)/2;
    double prM = 100000;
    int c = 0;
    while(fabs(m-prM) > E)
    {
        prM = m;
        m = log(10 * prM - log(prM));
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
        m = prM - f(prM) / (exp(prM) + 1 / prM - 10);
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
