#include <iostream>
#include <stack>
#include <string.h>

using namespace std;
int main() {
  char s[100001];

  cin >> s;

  int len = strlen(s);
  
  int br=0;
  int cnt = 0;
  int state = 1;
  for (int i = 0; i < len; i++) {
    switch(state){
      case 1:
        if(s[i]=='('){
          state++;
          br++;
        }
        break;
      case 2:
        if(s[i]=='('){
          state = 2;
          br++;
        }else if(s[i]==')'){
          state = 3;
          cnt += (--br);
        }
        break;
      case 3:
        if(s[i]=='('){
          state=2;
          br++;
        }else if(s[i]==')'){
          state = 4;
          cnt++;
          br--;
        }
        break;
      case 4:
        if(s[i]=='('){
          state = 2;
          br++;
        }else if(s[i]==')'){
          state = 4;
          cnt++;
          br--;
        }
        break;
      default:
        break;
    }
  }

  cout<<cnt;
}