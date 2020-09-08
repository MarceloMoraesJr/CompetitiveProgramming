#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    int K_aux, K;
    int N;
    int M;
    int A;

    cin >> K_aux;
    K = K_aux;

    while(K--){
        cin >> N;
        vector<set<int> > v(N);
        map<int,int> stamp_freq;
        int n_uniques = 0;

        for(int i = 0; i < N; i++){
            cin >> M;
            while(M--){
                cin >> A; 
                v[i].insert(A);
            }

            for(const auto& a: v[i]){
                stamp_freq[a]++;
            }
        }

        for(const auto& a: stamp_freq){
            if(a.second == 1){
                n_uniques++;
            }
        }

        cout << "Case " << (K_aux - K) << ": ";
        for(int i = 0; i < N; i++){
            int unique_count = 0;
            for(const auto& a: v[i]){
                if(stamp_freq[a] == 1){
                    unique_count++;
                }
            }
            cout << fixed << setprecision(6) << (double)(unique_count)/(double)(n_uniques)*100;
            if(i != N-1){
                cout<<"% ";
            }
            else{
                cout<<"%";
            }
        }
        cout<<endl;
    }
}