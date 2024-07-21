#include <iostream>
#include <stack>
#include <string.h>
#include <vector>

using namespace std;

int main() {

  stack<char> s;
  vector<int> v = vector<int>(100,0);

  char str[100] = {0};

  cin >> str;

  int len = strlen(str);

  for (int i = 0; i < len; i++) {
    switch (str[i]) {
    case '(':

      s.push('(');
      break;
      
    case '[':
      
      s.push('[');
      break;
      
    case ')': {
      if(s.empty()){
        cout<<0;
        return 0;
      }
      char t = s.top();
      if (t == '(') {
        s.pop();

        int size = s.size();

        v[size] += v[size+1] != 0 ? 2 * (v[size+1]) : 2;
        v[size+1] = 0;
        
      } else {
        cout << 0;
        return 0;
      }
      break;
    }
    case ']': {
      if(s.empty()){
        cout<<0;
        return 0;
      }
      char t = s.top();
      if (t == '[') {
        s.pop();

        int size = s.size();

        v[size] += v[size+1] != 0 ? 3 * (v[size+1]) : 3;
        v[size+1] = 0;
      } else {
        cout << 0;
        return 0;
      }
      break;
    }
    }
    
  }

  if(s.size()){
    cout<<0;
  }else {
    cout<<v[0];
  }
  return 0;
}
