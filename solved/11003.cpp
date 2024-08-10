#include <climits>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct node{
  long long int value;
  int index;
};

int main() {
  
  ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

  int N, L, tmp;
  cin >> N >> L;

  vector<long long int> v;
  vector<long long int> d;
  
  for(int i=0;i<N;i++){
    cin>>tmp;
    v.push_back(tmp);
  }

  deque<node> dq;

  for(int i=0;i<N;i++){
    if((i - L + 1) > 0){
      while(!dq.empty()&&(dq.front().index == i - L)){
        dq.pop_front();
      }
      
    }

    while(!dq.empty()&&(dq.back().value >= v[i])){
      dq.pop_back();
    }

    dq.push_back({v[i], i});
    d.push_back(dq.front().value);
  }

  for(auto it=d.begin();it!=d.end();it++){
    cout<<*it<<' ';
  }
  
  
  
  
  

  
  
  
}