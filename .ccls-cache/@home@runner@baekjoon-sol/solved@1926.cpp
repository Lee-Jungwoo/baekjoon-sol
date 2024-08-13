#include <bits/stdc++.h>

using namespace std;

int board[500][500] = {0};

bool vst[500][500] = {0};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  queue<pair<int, int>> Q;
  pair<int, int> cur;
  vector<vector<int>> v;
  int r, c;
  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    v.push_back({});
    for (int j = 0; j < c; j++) {
      v[i].push_back(0);
      int tmp;
      cin>>tmp;
      board[i][j] = tmp;
    }
  }
  int cnt=0;
  int big=0;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (!vst[i][j] && board[i][j]) {
        int area=0;
        cnt++;
        Q.push({i, j});
        vst[i][j] = true;

        while (!Q.empty()) {
          cur = Q.front();
          Q.pop();
          area++;

          // cout << "now checking: " << cur.first << ' ' << cur.second << endl;
          v[cur.first][cur.second] = 1;

          for (int dir = 0; dir < 4; dir++) {

            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx >= r || nx < 0 || ny >= c || ny < 0 || vst[nx][ny])
              continue;
            if (!board[nx][ny])
              continue;

            vst[nx][ny] = true;

            Q.push({nx, ny});
          }
        }
        if(area > big) big = area;
      }
    }
  }

  // for (auto i : v) {
  //   for (auto j : i) {
  //     cout << j << ' ';
  //   }
  //   cout << endl;
  // }

  cout<< cnt<<endl<<big;
}
