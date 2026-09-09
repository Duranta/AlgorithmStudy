#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

/*
문제 내용

0으로만 이루어진 초기 배열을 원하는 배열로 바꾸려고 한다.
배열에서 숫자 하나를 선택하여 다음 연산을 수행할 수 있다.

1. 선택한 숫자를 포함해 오른쪽에 있는 모든 숫자에 1을 더한다.
2. 선택한 숫자를 포함해 오른쪽에 있는 모든 숫자에 1을 뺀다.

원하는 배열 goal이 주어질 때, 초기 배열에서 goal을 만들기 위해 필요한
최소 연산 횟수를 구한다.

제한 사항

- 초기 배열의 길이는 goal의 길이와 같다.
- 1 <= goal의 길이 <= 500,000
- 0 <= goal의 원소 <= 1,000,000,000

예시

goal = [1, 3, 2, 4] -> 6
goal = [1, 2, 3, 4, 5] -> 5
goal = [1, 3, 2, 1] -> 5

풀이

연산은 선택한 위치부터 오른쪽 끝까지 같은 값만큼 변경한다.
따라서 왼쪽부터 현재 값과 goal의 차이를 계산하면 필요한 연산 횟수를 구할 수 있다.

- goal[i]가 이전 값보다 크면 차이만큼 더하기 연산을 수행한다.
- goal[i]가 이전 값보다 작으면 차이의 절댓값만큼 빼기 연산을 수행한다.
- 첫 번째 값의 이전 값은 초기 배열의 0이다.

각 위치의 차이 절댓값을 모두 더하면 최소 연산 횟수가 된다.
최대 연산 횟수가 int 범위를 넘을 수 있으므로 long long을 사용한다.
*/
long long solution(vector<int> goal)
{
	long long answer = 0;

	long long caching = 0;
	for (int i = 0; i < static_cast<int>(goal.size()); ++i)
	{
		// 현재 목표값과 직전 값의 차이만큼 연산한다.
		const long long dif = static_cast<long long>(goal[i]) - caching;

		if (dif >= 0)
		{
			answer += dif;
		}
		else
		{
			answer -= dif;
		}

		caching = goal[i];
	}

	return answer;
}

int main()
{
	assert(solution({1, 3, 2, 4}) == 6);
	assert(solution({1, 2, 3, 4, 5}) == 5);
	assert(solution({1, 3, 2, 1}) == 5);

	cout << solution({1, 3, 2, 4}) << '\n';
	return 0;
}
