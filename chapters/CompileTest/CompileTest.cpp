#include "CompileTest.hpp"

#include <cassert>
#include <iostream>

namespace AlgorithmStudy::CompileTest
{
    int AddForBuildCheck(int left, int right)
    {
        return left + right;
    }

    void Run()
    {
        const int result = AddForBuildCheck(2, 3);
        assert(result == 5);

        std::cout << "CompileTest project build check passed. result = " << result << '\n';
    }
}
