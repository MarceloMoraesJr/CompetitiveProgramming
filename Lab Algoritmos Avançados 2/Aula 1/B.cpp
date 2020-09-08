#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    stack<int> inverter;
    stack<int> permutation;

    int ncoaches;
    int coache;
    int nzeros = 0;
    bool newblock = true;
    
    while(true){
        if(newblock){
            cin >> ncoaches;
            newblock = false;
            if(ncoaches == 0){
                break;
            }
        }

        for(int j = 0; j < ncoaches; j++){ 
            cin >> coache;
            if(coache == 0){
                cout << endl;
                newblock = true;
                break;
            }
            permutation.push(coache);
        }

        if(coache == 0){
            continue;
        }

        int i = ncoaches;
        while(!permutation.empty()){
            if(inverter.empty()){ //primeiro elemento
                inverter.push(permutation.top());
                permutation.pop();
            }
            
            
            while(!inverter.empty() && inverter.top() == i){
                inverter.pop();
                i--;
            }

            if(!inverter.empty() && inverter.top() != i){
                inverter.push(permutation.top());
                permutation.pop();
            }

            
        }

        while(!inverter.empty() && inverter.top() == i){
            inverter.pop();
            i--;
        }

        if(inverter.empty()){
            cout << "Yes" << endl; 
        }
        else{
            cout << "No" << endl;
        }

        while(!inverter.empty()){
            inverter.pop();
        }
        while(!permutation.empty()){
            permutation.pop();
        }
    }

    return 0;
}