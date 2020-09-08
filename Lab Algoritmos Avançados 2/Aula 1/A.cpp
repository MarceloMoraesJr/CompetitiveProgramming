//Aluno: Marcelo Isaias de Moraes Junior
//NUSP: 10550218

#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    int N;
    int K;
    int lines;
    char c;
    int value;
    string line;
    int total;
    map<char, int> m_lookup;

    cin >> N;

    while(N--){
        cin >> K;
        total = 0.0;
        while(K--){
            cin >> c;
            cin >> value;
            m_lookup.insert(make_pair(c,value));
        }
        
        cin >> lines;
        cin.ignore(1);
        while(lines--){
            getline(cin, line);
            int line_size = line.size();

            for(int i = 0; i < line_size; i++){
                total += m_lookup[line[i]];
            }
        }
        cout << fixed << setprecision(2) << (double)(total)/(double)(100) <<"$"<<endl;
        m_lookup.clear();
    }

    return 0;
}