#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    int t;
    int n;
    int m;

    cin >> t;
    
    while(t--){
        cin >> n;
        cin >> m;

        vector< vector<int> > counter(n + m - 1, vector<int>(2));
        //Cada posicao do vetor armazena a quantidade de 0's e 1's na quantidade de passos dados em relacao a origem

        int a;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a;
                counter[i + j][a]++;
            }
        }

        int nchanges = 0;
        
        for(int i = 0, j = n + m - 2; i < n + m - 1; i++, j--){
            if(i > j){
                nchanges += min(counter[i][0] + counter[j][0], counter[i][1] + counter[j][1]);
            }
        }

        cout << nchanges << endl;
    }

    return 0;
}