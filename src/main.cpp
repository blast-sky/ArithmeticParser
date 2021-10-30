#include <iostream>
#include "Parser.hpp"
#include "Computer.hpp"

double countExpr(const std::string& expr)
{
    ap::Variables variables;
    variables.setVariable("x", 1);
    variables.setVariable("y", 10);
    variables.setVariable("z", 100.1);

    ap::Parser parser(expr, variables);
    auto graph = parser.parse();
    ap::Computer computer(graph, variables);
    return computer.compute();
}

int main()
{
    std::string expression;

    while (true)
    {
        std::getline(std::cin, expression);
        std::cin.seekg(1);
        try
        {
            std::cout << countExpr(expression) << std::endl;
        }
        catch (std::exception& exception)
        {
            std::cout << exception.what() << std::endl;
        }
    }

    return 0;
}
