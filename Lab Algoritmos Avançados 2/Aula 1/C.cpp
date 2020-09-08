//Aluno: Marcelo Isaias de Moraes Junior
//NUSP: 10550218

#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    queue<int> left;
    queue<int> right;
    string side;
    int size;
    int n_travs;
    int L_remain;
    int N, L, M;
    cin >> N;
    
    while(N--){
        cin >> L;
        L *= 100;
        cin >> M;
        n_travs = 0;

        while(M--){
            cin>>size;
            cin>>side;

            if(side[0] == 'l'){
                left.push(size);
            }
            else{
                right.push(size);
            }
        }

        while(true){
            int n_left = left.size();
            int n_right = right.size();
            
            if(n_left == 0 && n_right == 0){
                break;
            }
            else if(n_left > 0 || n_right > 0){
                n_travs++;
            }

            L_remain = L;
            while(left.size() > 0 && (L_remain -= left.front()) >= 0){
                left.pop();
            }

            if(left.size() > 0 || n_right > 0){
                n_travs++;
            }
            
            L_remain = L;
            while(right.size() > 0 && (L_remain -= right.front()) >= 0){
                right.pop();
            }

        }
        
        cout << n_travs << endl;
    }

    return 0;
}