#include <iostream>
#include <functional>
#include <math.h>
#include <random>
#include <time.h>
using namespace std;
using domain_t = std::vector<double>;
std::random_device rd;
std::mt19937 mt_generator(rd());

auto himmelblau_function(double x, double y)
{
    //-5 , 5
    return (x*x + y - 11.0)*(x * x + y - 11.0) + (x + y * y - 7.0)*(x + y * y - 7.0);
}

auto beale_function(double x, double y)
{
//    -4.5, 4.5
    double first_square = (1.5 - x - x * y)*(1.5 - x - x * y);
    double second_square = (2.25 - x - x * y * y)*(2.25 - x - x * y * y);
    double third_square = (2.625 - x - x * y * y * y)*(2.625 - x - x * y * y * y);
    return first_square + second_square + third_square;
}

auto matyas_function(double x, double y)
{
//    -10 , 10
    return 0.26*(x*x + y*y) - 0.48*x*y;
}

auto booth_function(double x, double y)
{
    //-10 , 10
    return (2 * y + x - 7) * (2 * y + x - 7) + (2 * x + y - 5) * (2 * x + y - 5);
}

double optimise(auto function, auto domain, int maxIterations = 1000)
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    std::uniform_real_distribution<double> dist(domain.at(0), domain.at(1));
    double lowest = function(domain.at(0), domain.at(1));
    for (int i = 0; i < maxIterations - 1; i++)
    {
        double rand1 = dist(mt_generator);
        double rand2 = dist(mt_generator);
        double temp;
        temp = function(rand1, rand2);
        if (temp < lowest)
            lowest = temp;
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "Iterations: " << maxIterations << " Time needed: " << cpu_time_used << " Result: ";
    return lowest;
}

int main()
{
    double result = 0;

    auto himmel_f = [](double x, double y)
    { return pow(pow(x, 2) + y - 11, 2) + pow(x + pow(y, 2) - 7, 2); };

    vector<double> domain = {-5, 5};

    for (int i = 0; i < 20; i++)
    {
        cout <<fixed<< optimise(himmel_f, domain, 100000) << endl;
    }
    return 0;
}



