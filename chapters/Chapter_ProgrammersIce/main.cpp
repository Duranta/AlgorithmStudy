#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

/*
문제 내용

물이 담긴 컵 안에 얼음이 일렬로 탑처럼 쌓여 있다. 배열은 컵 바닥의 얼음부터
위쪽 얼음 순서로 주어진다. 얼음이 떠오르거나 가라앉아도 순서는 바뀌지 않는다.

1. 물에 잠긴 얼음 크기의 합은 물 밖 얼음 크기의 합 이상이어야 한다.
2. 최대한 많은 얼음이 물 밖으로 떠오른다.
3. 물에 잠긴 얼음은 1분마다 3씩, 물 밖 얼음은 1분마다 1씩 줄어든다.
4. 물에 잠긴 얼음의 합이 물 밖 얼음의 합보다 작아지면 1번 조건을 만족할 때까지
   얼음이 가라앉는다. 반대로 물에 잠긴 얼음의 합이 충분히 크면 얼음이 떠오를 수 있다.
5. 크기가 0 이하가 된 얼음은 녹아 사라진다.

예시

ices = [10, 10, 10, 10, 10], t = 4

0분: [10, 10, 10, 10, 10]
1분: [ 7,  7,  7,  9,  9]
2분: [ 4,  4,  4,  8,  8]
3분: [ 1,  1,  1,  5,  7]
4분: [ 0,  0,  0,  2,  6]

4분 후 남은 얼음 크기의 합은 2 + 6 = 8이다.

풀이

매 분 아래쪽 얼음부터 누적하여 물의 경계를 찾는다.
처음으로 submergedSum >= total - submergedSum을 만족하는 위치를 경계로 정한다.
경계까지는 물에 잠긴 얼음이므로 3을 빼고, 경계 위쪽은 물 밖 얼음이므로 1을 뺀다.
감소 후 크기가 음수가 되면 0으로 보정한다.
*/
int solution(vector<int> ices, int t)
{
	int answer = -1;

	// 총합
	int total = 0;
	for (int ice : ices)
	{
		total += ice;
	}

	for (int min = 0; min < t; ++min)
	{
		int waterSurfaceIndex = 0;
		int waterSurfaceSum = 0;
		int iceCount = 0;

		for (int i = 0; i < static_cast<int>(ices.size()); ++i)
		{
			if (ices[i] > 0)
			{
				++iceCount;
			}

			waterSurfaceSum += ices[i];

			if (waterSurfaceSum >= total - waterSurfaceSum)
			{
				waterSurfaceIndex = i;
				break;
			}
		}

		if (iceCount == 0)
		{
			break;
		}

		total = 0;
		for (int i = 0; i < static_cast<int>(ices.size()); ++i)
		{
			if (i > waterSurfaceIndex)
			{
				ices[i] -= 1;
			}
			else
			{
				ices[i] -= 3;
			}

			if (ices[i] < 0)
			{
				ices[i] = 0;
			}

			total += ices[i];
		}

		answer = total;
	}

	return answer < 0 ? 0 : answer;
}

int main()
{
	assert(solution({10, 10, 10, 10, 10}, 4) == 8);

	cout << solution({10, 10, 10, 10, 10}, 4) << '\n';
	return 0;
}
