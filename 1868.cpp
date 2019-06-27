#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int t, n, ans;
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
char map[300][300];
vector<pair<int, int>> coordinate;
int result[21];

void bfs(int coX, int coY)
{
	queue<pair<int, int>> q;
	map[coX][coY] = 'X';
	q.push({ coX,coY });
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i<8; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx<0 || nx >= n || ny<0 || ny >= n) continue;
			if (map[nx][ny] == '*' || map[nx][ny] == 'X') continue;
			if (map[nx][ny] == '0') q.push({ nx,ny });
			map[nx][ny] = 'X';
		}
	}
}

int main()
{
	cin >> t;
	for (int T = 1; T <= t; T++)
	{
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> map[i];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] != '.') continue;
				int cnt = 0;
				for (int k = 0; k < 8; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (map[i + dx[k]][j + dy[k]] == '*') cnt++;
				}
				if (!cnt) coordinate.push_back({ i,j });
				map[i][j] = cnt + '0';
			}
		}
		int size = coordinate.size();
		for (int i = 0; i < size; i++)
		{
			int x = coordinate[i].first, y = coordinate[i].second;
			if (map[x][y] != 'X') {
				bfs(x, y);
				ans++;
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) {
				if (map[i][j] >= '1' && map[i][j] <= '8') 
					ans++;
			}
	}
		
		result[T] = ans;
		ans = 0, coordinate.clear();
	}

	for (int T = 1; T <= t; T++)
	{
		cout << "#" << T << " " << result[T] << endl;
	}

	return 0;
}
