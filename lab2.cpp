#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
#include <random>
#include <string>
double beale_function(std::vector <double> numbers)
{
//    -4.5, 4.5
    double x = numbers[0];
    double y = numbers[1];
    double first_square = (1.5 - x - x * y)*(1.5 - x - x * y);
    double second_square = (2.25 - x - x * y * y)*(2.25 - x - x * y * y);
    double third_square = (2.625 - x - x * y * y * y)*(2.625 - x - x * y * y * y);
    return first_square + second_square + third_square;
}

double matyas_function(std::vector <double> numbers)
{
//    -10 , 10
    double x = numbers[0];
    double y = numbers[1];
    return 0.26*(x*x + y*y) - 0.48*x*y;
}

double himmelblau_function(std::vector <double> numbers)
{
//    -5 ,5
    double x = numbers[0];
    double y = numbers[1];
    return (x*x + y - 11.0)*(x * x + y - 11.0) + (x + y * y - 7.0)*(x + y * y - 7.0);
}

double booth_fun(std::vector <double> numbers)
{
    //-10 , 10
    double x = numbers[0];
    double y = numbers[1];
    return (2 * y + x - 7) * (2 * y + x - 7) + (2 * x + y - 5) * (2 * x + y - 5);
}

//Czesc z wykladu
std::vector<double> get_result(std::function<double(std::vector<double>)> f, double minimal, double maximal, int iterations){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_real_distribution<double> dis(minimal, maximal); //
    std::vector<double> closest_numbers = {dis(gen), dis(gen)}; //

    double result = f(closest_numbers);
    for(int u = 0; u < iterations; u++){
        std::vector<double> args = {dis(gen), dis(gen)};
        double new_result = f(args);
        if (new_result < result){
            result = new_result;
            closest_numbers = args;
        }
    }
    return closest_numbers;
}

int main(int argc, char **argv)
{
    std::vector<double> values;
    transform(argv + 1, argv + argc,  std::back_inserter(values), [](const char* z){return std::stod(z);}); //
    double border_low = values.at(0);
    double border_high = values.at(1);
    std::vector<double> my_result = get_result(booth_fun, -5.0, 5.0, 1000);
    std::cout << my_result[0] << std::endl;
    std::cout << my_result[1] << std::endl;

    return 0;
}
