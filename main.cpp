#include <bits/stdc++.h>

using namespace std;

int arr[101][101][101];
int visited[101][101][101];
size_t r = 0; // remaining unaged tomatoes
int m, n, h;  // size

// 틀리면 경계조건
vector<int> seek(vector<int>, int, int, int);

int bfs(deque<vector<int>> start)
{
  int depth = 0;

  deque<vector<int>> q = start;

  
  bool flag = false;
  while(!q.empty()){
    size_t q_size = q.size();
    flag = false;
    for (size_t i = 0; i < q_size; i++)
    {
      auto pos = q.front();
      
      auto adj = seek(q.front(), m,n,h);
      
      for(auto dir : adj){
        flag = true;
        switch (dir)
        {
        case 0:
          q.push_back(vector<int>{pos[0]+1, pos[1], pos[2]});
          break;
        case 1:
          q.push_back(vector<int>{pos[0]-1, pos[1], pos[2]});
          break;
        case 2:
          q.push_back(vector<int>{pos[0], pos[1]+1, pos[2]});
          break;
        case 3:
          q.push_back(vector<int>{pos[0], pos[1]-1, pos[2]});
          break;
        case 4:
          q.push_back(vector<int>{pos[0], pos[1], pos[2]+1});
          break;
        case 5:
          q.push_back(vector<int>{pos[0], pos[1], pos[2]-1});
          break;
        default:
          break;
        }
      }
      q.pop_front();
    }
    if(flag) depth ++;
    


  }
  
  return depth;
}

// 주변의 '탐색하지 않은 노드' 리스트 리턴하는 함수
// 위 아래 동서남북을 0~5 로 인코딩
// pos : h,n,m 배열
vector<int> seek(vector<int> pos, int m, int n, int h)
{

  vector<int> result;

  if (pos[0] < h - 1)
  {
    // 위
    if (!visited[pos[0] + 1][pos[1]][pos[2]] && arr[pos[0] + 1][pos[1]][pos[2]] == 0)
    {
      visited[pos[0] + 1][pos[1]][pos[2]] = 1;
      result.push_back(0);
    }
  }

  if (pos[0] > 0)
  {
    // 아래
    if (!visited[pos[0] - 1][pos[1]][pos[2]] && arr[pos[0] - 1][pos[1]][pos[2]] == 0)
    {
      visited[pos[0] - 1][pos[1]][pos[2]] = 1;
      result.push_back(1);
    }
  }

  if (pos[1] < n - 1)
  {
    // 북
    if (!visited[pos[0]][pos[1] + 1][pos[2]] && arr[pos[0]][pos[1] + 1][pos[2]] == 0)
    {
      visited[pos[0]][pos[1] + 1][pos[2]] = 1;
      result.push_back(2);
    }
  }

  if (pos[1] > 0)
  {
    // 남
    if (!visited[pos[0]][pos[1] - 1][pos[2]] && arr[pos[0]][pos[1] - 1][pos[2]] == 0)
    {
      visited[pos[0]][pos[1] - 1][pos[2]] = 1;
      result.push_back(3);
    }
  }

  if (pos[2] < m - 1)
  {
    // 동
    if (!visited[pos[0]][pos[1]][pos[2] + 1] && arr[pos[0]][pos[1]][pos[2] + 1] == 0)
    {
      visited[pos[0]][pos[1]][pos[2] + 1] = 1;
      result.push_back(4);
    }
  }

  if (pos[2] > 0)
  {
    // 서
    if (!visited[pos[0]][pos[1]][pos[2] - 1] && arr[pos[0]][pos[1]][pos[2] - 1] == 0)
    {
      visited[pos[0]][pos[1]][pos[2] - 1] = 1;
      result.push_back(5);
    }
  }

  r -= result.size();
  return result;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // 2 ≤ M ≤ 100, 2 ≤ N ≤ 100, 1 ≤ H ≤ 100

  cin >> m >> n >> h;

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < m; k++)
      {
        cin >> arr[i][j][k];
      }
    }
  }

  deque<vector<int>> start; // h, n, m

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < m; k++)
      {
        if (arr[i][j][k] == 1)
        {
          start.push_back(vector<int>{i, j, k});
        }
        else if (arr[i][j][k] == 0)
        {
          r++;
        }
      }
    }
  }


  int depth = bfs(start);
  
  if (r > 0)
  {
    cout << -1 << '\n';
  }else if(r == 0){
    cout << depth << '\n';
  }
  

  return 0;
}
