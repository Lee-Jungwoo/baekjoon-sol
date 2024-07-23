#include <iostream>
#include <vector>
#include <stack>

using namespace std;
struct info{
    bool LR = false;
    int value = 0;
    int index = 0;
};

int main() {
    int n;

    cin>>n;

    vector<int> arr;
    stack<info *> s;
    info lr[500001]; //0 -> L, 1 -> R

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    for(int i=n-1;i>=0;i--){

        if(s.empty()){
            lr[i].LR = true;
            lr[i].index = n;
            info * tmp = new info;
            tmp->value = arr[i];
            tmp->index = i;
            s.push(tmp);
        } else {
            while(!s.empty()){
                info top = *s.top();
                if(top.value <= arr[i]){
                    s.pop();
                } else {
                    lr[i] = top;
                    info * tmp = new info;
                    tmp->value = arr[i];
                    tmp->index = i;
                    s.push(tmp);
                    break;
                }
            }
            if(s.empty()){
                lr[i].LR = true;
                lr[i].index = n;
                info * tmp = new info;
                tmp->value = arr[i];
                tmp->index = i;
                s.push(tmp);
            }
        }
    }

    long long cnt=0;
    for(int i=0;i<n;i++){
        if(lr[i].LR){

            cout<<"true, "<<(n-i-1)<<endl;
        }else{
            cnt += (lr[i].index - i);
            cout<<lr[i].index - i<<endl;        

        }
    }

    cout<<cnt;

}