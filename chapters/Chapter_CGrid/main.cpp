#include <array>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Point
{
	int rows = 0;
	int cols = 0;
};

/*
문제 내용

r행 c열의 빈 격자가 있다. 이 격자를 C 모양으로 순회하면서 1부터 숫자를 채운다.

C 모양으로 채우는 방법은 다음과 같다.

1. 격자의 우측 상단부터 채우기 시작한다.
2. 격자의 끝에 도착하거나 이미 방문한 격자를 만날 때까지 왼쪽으로 움직인다.
3. 격자의 끝에 도착하거나 이미 방문한 격자를 만날 때까지 아래로 움직인다.
4. 격자의 끝에 도착하거나 이미 방문한 격자를 만날 때까지 오른쪽으로 움직인다.
5. 위로 한 칸 움직인다.
6. 격자의 끝에 도착하거나 이미 방문한 격자를 만날 때까지 왼쪽으로 움직인다.
7. 격자의 끝에 도착하거나 이미 방문한 격자를 만날 때까지 위로 움직인다.
8. 격자의 끝에 도착하거나 이미 방문한 격자를 만날 때까지 오른쪽으로 움직인다.
9. 아래로 한 칸 움직인다.
10. 2~9번을 반복한다.

각 번호를 실행하다가 격자를 모두 채우게 되면 반복을 멈추고 종료한다.

제한 사항

- 3 <= r <= 999
- r은 홀수이다.
- (r + 1) / 2 <= c <= 1000

예시

r = 5, c = 4

[
    [ 4,  3,  2,  1],
    [ 5, 16, 17, 18],
    [ 6, 15, 20, 19],
    [ 7, 14, 13, 12],
    [ 8,  9, 10, 11]
]

r = 3, c = 5

[
    [ 5,  4,  3,  2,  1],
    [ 6, 15, 14, 13, 12],
    [ 7,  8,  9, 10, 11]
]
*/
vector<vector<int>> solution(int r, int c)
{
	// 원본 오류: 행과 열을 각각 1개씩 작게 생성했다.
	// int curRows = r - 1;
	// int curCols = c - 1;
	// 수정
	int curRows = r;
	int curCols = c;
	vector<vector<int>> grid(curRows, vector<int>(curCols, 0));

	const int gridSize = r * c;

	Point cur;
	cur.rows = 0;
	cur.cols = c - 1;

	int num = 1;
	grid[cur.rows][cur.cols] = num;

	// 원본 오류
	// for (int i = 0; i < gridSize; ++i)
	// 고정 횟수보다 아직 채우지 않은 칸을 기준으로 반복해야 한다.
	// 수정
	while (num < gridSize)
	{
		// 원본 오류
		// for (int nextCols = cur.cols - 1;
		// 	nextCols > 0 && grid[cur.rows][nextCols] == 0;
		// 	--nextCols)
		// 0번 열까지 이동해야 하므로 >= 0이어야 한다.
		// 수정
		for (int nextCols = cur.cols - 1;
			nextCols >= 0 && grid[cur.rows][nextCols] == 0 && num < gridSize;
			--nextCols)
		{
			cur.cols = nextCols;
			grid[cur.rows][cur.cols] = ++num;
		}

		// 원본 오류
		// for (int nextRow = cur.rows + 1;
		// 	nextRow > r && grid[nextRow][cur.cols] == 0;
		// 	++nextRow)
		// 행 인덱스는 r보다 작아야 격자 내부에 있다.
		// 수정
		for (int nextRow = cur.rows + 1;
			nextRow < r && grid[nextRow][cur.cols] == 0 && num < gridSize;
			++nextRow)
		{
			cur.rows = nextRow;
			grid[cur.rows][cur.cols] = ++num;
		}

		for (int nextCols = cur.cols + 1;
			nextCols < c && grid[cur.rows][nextCols] == 0 && num < gridSize;
			++nextCols)
		{
			cur.cols = nextCols;
			grid[cur.rows][cur.cols] = ++num;
		}

		if (num >= gridSize)
		{
			break;
		}

		// 원본 오류
		// if ((cur.rows - 1 < 0) && (grid[cur.rows - 1][cur.cols] == 0))
		// 위 칸으로 이동하려면 다음 행이 0 이상이어야 한다.
		// 수정
		const int oneUp = cur.rows - 1;
		if (oneUp >= 0 && grid[oneUp][cur.cols] == 0)
		{
			cur.rows = oneUp;
			grid[cur.rows][cur.cols] = ++num;
		}

		// 원본 오류
		// for (int nextCols = cur.cols - 1;
		// 	nextCols > 0 && grid[cur.rows][nextCols] == 0;
		// 	--nextCols)
		// 두 번째 왼쪽 이동도 0번 열을 포함해야 한다.
		// 수정
		for (int nextCols = cur.cols - 1;
			nextCols >= 0 && grid[cur.rows][nextCols] == 0 && num < gridSize;
			--nextCols)
		{
			cur.cols = nextCols;
			grid[cur.rows][cur.cols] = ++num;
		}

		// 원본 오류
		// for (int nextRow = cur.rows - 1;
		// 	nextRow < 0 && grid[nextRow][cur.cols] == 0;
		// 	--nextRow)
		// 위로 이동할 때는 행이 0 이상인 동안 이동해야 한다.
		// 수정
		for (int nextRow = cur.rows - 1;
			nextRow >= 0 && grid[nextRow][cur.cols] == 0 && num < gridSize;
			--nextRow)
		{
			cur.rows = nextRow;
			grid[cur.rows][cur.cols] = ++num;
		}

		for (int nextCols = cur.cols + 1;
			nextCols < c && grid[cur.rows][nextCols] == 0 && num < gridSize;
			++nextCols)
		{
			cur.cols = nextCols;
			grid[cur.rows][cur.cols] = ++num;
		}

		if (num >= gridSize)
		{
			break;
		}

		// 원본 오류
		// if ((cur.rows + 1 > r) && (grid[cur.rows + 1][cur.cols] == 0))
		// 아래 칸으로 이동하려면 다음 행이 r보다 작아야 한다.
		// 수정
		const int oneDown = cur.rows + 1;
		if (oneDown < r && grid[oneDown][cur.cols] == 0)
		{
			cur.rows = oneDown;
			grid[cur.rows][cur.cols] = ++num;
		}
	}

	return grid;
}

/*
==================== 다른 풀이 ====================
solution2 풀이

기존 풀이처럼 방향별 for문을 여러 개 나누지 않고, 문제의 이동 순서를
방향 배열 하나로 표현한다.

왼쪽, 아래, 오른쪽, 위 한 칸,
왼쪽, 위, 오른쪽, 아래 한 칸

위 8단계를 반복하면서 다음 칸이 격자 안에 있고 아직 방문하지 않았다면
숫자를 채운다. 위/아래 한 칸 이동만 한 번 이동하고, 나머지는 막힐 때까지 이동한다.
*/
vector<vector<int>> solution2(int r, int c)
{
	// r행 c열의 빈 격자를 만든다.
	vector<vector<int>> grid(r, vector<int>(c, 0));
	// 격자에 채워야 하는 전체 칸의 개수다.
	const int gridSize = r * c;

	// 문제에서 정한 8단계 이동 순서다.
	const array<Point, 8> directions =
	{
		Point{0, -1},  // 왼쪽
		Point{1, 0},   // 아래
		Point{0, 1},   // 오른쪽
		Point{-1, 0},  // 위 한 칸
		Point{0, -1},  // 왼쪽
		Point{-1, 0},  // 위
		Point{0, 1},   // 오른쪽
		Point{1, 0}    // 아래 한 칸
	};

	// 우측 상단에서 시작한다.
	Point cur{0, c - 1};
	// 첫 번째 숫자를 시작 위치에 기록한다.
	int num = 1;
	grid[cur.rows][cur.cols] = num;

	// 모든 칸을 채울 때까지 8단계 이동을 반복한다.
	int directionIndex = 0;
	while (num < gridSize)
	{
		// 현재 단계에서 사용할 이동 방향을 가져온다.
		const Point direction = directions[directionIndex];
		// 4번째와 8번째 방향은 한 칸만 이동한다.
		const bool oneStep = directionIndex == 3 || directionIndex == 7;
		// 한 칸 이동 방향이 몇 번 이동했는지 기록한다.
		int stepCount = 0;

		// 긴 방향은 막힐 때까지, 한 칸 방향은 한 번만 이동한다.
		while (num < gridSize)
		{
			// 현재 방향으로 이동했을 때의 다음 위치를 계산한다.
			const int nextRow = cur.rows + direction.rows;
			const int nextCols = cur.cols + direction.cols;

			// 격자 밖이거나 이미 숫자가 채워진 칸이면 현재 방향을 종료한다.
			if (nextRow < 0 || nextRow >= r ||
				nextCols < 0 || nextCols >= c ||
				grid[nextRow][nextCols] != 0)
			{
				break;
			}

			// 계산한 다음 위치를 현재 위치로 갱신한다.
			cur.rows = nextRow;
			cur.cols = nextCols;
			// 현재 위치에 다음 번호를 기록한다.
			grid[cur.rows][cur.cols] = ++num;
			// 현재 방향으로 이동한 횟수를 증가시킨다.
			++stepCount;

			// 위/아래 한 칸 이동은 한 번 이동하면 방향을 종료한다.
			if (oneStep && stepCount == 1)
			{
				break;
			}
		}

		// 다음 방향 단계로 이동하고, 8단계가 끝나면 다시 0단계로 돌아간다.
		directionIndex = (directionIndex + 1) % directions.size();
	}

	// 숫자가 채워진 최종 격자를 반환한다.
	return grid;
}

int main()
{
	const vector<vector<int>> expected =
	{
		{4, 3, 2, 1},
		{5, 16, 17, 18},
		{6, 15, 20, 19},
		{7, 14, 13, 12},
		{8, 9, 10, 11}
	};

	const vector<vector<int>> expected2 =
	{
		{5, 4, 3, 2, 1},
		{6, 15, 14, 13, 12},
		{7, 8, 9, 10, 11}
	};

	assert(solution(5, 4) == expected);
	assert(solution2(5, 4) == expected);
	assert(solution2(3, 5) == expected2);
	cout << "C-grid solution verified" << '\n';
	return 0;
}
