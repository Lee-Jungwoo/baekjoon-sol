#include <iostream>
#include <list>
#include <sstream>
#include <string.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;

  cin >> n;
  char *cmd = (char *)malloc(100001);
  char *arr = (char *)malloc(12000000);

  for (int i = 0; i < n; i++) {

    bool flip = false;
    bool e = false;
    list<int> l;

    cin >> cmd;
    int k;
    cin >> k;
    cin >> arr;

    int size = strlen(arr);
    arr[size - 1] = '\0';

    for (int j = 0; j < size - 1; j++) {
      if (arr[j] == ',')
        arr[j] = ' ';
    }

    arr = arr + 1;
    istringstream iss(arr);

    int x;
    while (iss >> x) {
      l.push_back(x);
    }

    char t;
    istringstream iss2(cmd);

    while (iss2 >> t) {
      if (t == 'R') {

        flip = !flip;

      } else if (t == 'D') {
        if (l.empty()) {
          e = true;
          break;
        } else if (flip) {
          l.pop_back();
        } else {
          l.pop_front();
        }
      }
    }

    if (e) {
      cout << "error\n";
    } else {
      if (!l.empty()) {
        cout << "[";

        if (flip) {
          auto it = l.rbegin();
          cout << *it;
          it++;
          while (it != l.rend()) {
            cout << ',' << *it++;
          }
          cout << "]\n";
        } else {
          auto it = l.begin();
          cout << *it;
          it++;
          while (it != l.end()) {
            cout << ',' << *it++;
          }
          cout << "]\n";
        }
      }else {
        cout<<"[]\n";
      }
    }
  }
}