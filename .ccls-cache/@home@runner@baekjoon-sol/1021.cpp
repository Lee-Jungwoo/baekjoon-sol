#include <deque>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int cnt = 0;

  deque<int> d;

  for (int i = 1; i <= n; i++) {

    d.push_back(i);
  }

  deque<int> k;
  for (int i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;
    k.push_back(tmp);
  }

  while (!k.empty()) {
    
    int value = k.front();
    auto id = find(d.begin(), d.end(), value);
    int idx=1;
    deque<int>::iterator it = d.begin();
    // cout<<"elements of d: ";
    while(it != id){
      // cout<<*it<<" ";
      it++;      
      idx++;
    }
    // cout<<endl;
    
    // cout<<"index: "<<idx<<endl;
    k.pop_front();

    if (idx > (d.size() / 2 + 1)){
      for (int i = 0; i < d.size() - idx + 1; i++) {
        int tmp = d.back();
        d.pop_back();
        d.push_front(tmp);
        cnt++;
        // cout<<"right"<<endl;
      }
      
      
    } else if (idx != 1){
      for (int i = 1; i < idx; i++) {
        int tmp = d.front();
        d.pop_front();
        d.push_back(tmp);
        cnt++;
        // cout<<"left"<<endl;
      }
      
      
    }
    d.pop_front();
    // cout<<"popped "<<value<<endl;

  }

  cout << cnt;
}