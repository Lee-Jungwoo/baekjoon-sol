#include <bits/stdc++.h>

using namespace std;

int board[100][100] = {0};

bool vst[100][100] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int r, c;

queue<tuple<int, int, int>> q; // row, col, route length
pair<int, int> cur;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      char tmp;
      cin >> tmp;
      board[i][j] = tmp - 48;
    }
  }

  q.push({0, 0, 1});
  vst[0][0] = true;
  tuple<int, int, int> cur;

  while (!q.empty()) {

    cur = q.front();
    q.pop();
    int x = get<0>(cur);
    int y = get<1>(cur);
    int l = get<2>(cur);

    if ((x == r - 1) && (y == c - 1))
      break;

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      int nl = l + 1;

      if (nx >= r || nx < 0 || ny >= c || ny < 0 || vst[nx][ny])
        continue;
      if (!board[nx][ny])
        continue;

      vst[nx][ny] = true;
      q.push({nx, ny, nl});
    }
  }

  cout << get<2>(cur);
}