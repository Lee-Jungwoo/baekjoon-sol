#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);


  int n,m;
  cin>>n>>m;
  int cnt=0;

  deque<int> d;
  
  for(int i=1;i<=n;i++){
    
    d.push_back(i);
  }
  
  deque<int> k;
  for(int i=0;i<m;i++){
    int tmp;
    cin>>tmp;
    k.push_back(tmp);
    
  }

  while(!k.empty()){
    int idx = k.front();
    k.pop_front();

    if (idx > (n/2 + 1)){
      for(int i=0;i<d.size() - idx + 1;i++){
        int tmp = d.front();
        d.pop_front();
        d.push_back(tmp);
        cnt++;
      }
    }else {
      for(int i=0;i<idx;i++){
        int tmp = d.front();
        d.pop_front();
        d.push_back(tmp);
        cnt++;
      }
    }

  }

  cout<<cnt;

  
  
  
}