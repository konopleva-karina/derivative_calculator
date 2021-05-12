#include <fstream>
#include <ios>
#include <iostream>

#include "derivative_calculator.h"
#include "operators.h"

using namespace Derivatives;

int main() {
    std::ofstream fout("../test_out.txt", std::ios_base::out);
    if (!fout.is_open()) {
        std::cout << "couldn't open the file\n";
    }

    auto x = Argument{};
    auto expr1 = 2 * x + 3;
    fout << "Input: 2 * x + 3\nOutput:";
    auto ans1 = DerivativesCalculator(expr1);
    ans1.Print(fout);
    fout << "\n";

    auto expr2 = x / 2 + 2 / x + (x - 3) / Pow(x, 2);
    fout << "Input: x / 2 + 2 / x + (x - 3) / x^2\nOutput:";
    auto ans2 = DerivativesCalculator(expr2);
    ans2.Print(fout);
    fout << "\n";

    auto expr3 = Sin(2 * x + 3);
    fout << "Input: Sin(2 * x + 3)\nOutput: ";
    auto ans3 = DerivativesCalculator(expr3);
    ans3.Print(fout);
    fout << "\n";

    fout << "Утрем нос Стивену Вольфраму!";
    fout.close();
}
