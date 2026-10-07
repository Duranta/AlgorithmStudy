#include "CompileTest.hpp"

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> solution(vector<int> numbers) {

	vector<int> temp;
	int size = numbers.size();
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; i < size; ++j)
		{
			int add_num = numbers[i] + numbers[j];
			temp.push_back(add_num);
		}

	}
	vector<int> answer;
	unique(temp.begin(), temp.end());
	
	answer = std::move(temp);
	sort(answer.begin(),answer.end());

	return answer;
}

int main()
{
    AlgorithmStudy::CompileTest::Run();
    return 0;
}
