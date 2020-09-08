#include <iostream>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    int t;
    int n;
    int a;
    cin >> t;

    while(t--){
        map<int,int> numbersLookUp;
        cin >> n;

        for(int i = 0; i < 2*n; i++){
            cin >> a;
            if(numbersLookUp[a] == 1){
                cout << a <<" ";
            }
            else{
                numbersLookUp[a] = 1;
            }
        }

        cout << endl;
    }
    return 0;
}