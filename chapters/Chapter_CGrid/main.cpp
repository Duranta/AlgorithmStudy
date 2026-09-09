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

	assert(solution(5, 4) == expected);
	cout << "C-grid solution verified" << '\n';
	return 0;
}
