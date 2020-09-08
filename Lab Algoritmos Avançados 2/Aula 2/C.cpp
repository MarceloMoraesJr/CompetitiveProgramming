#include <iostream>
#include <algorithm>    
#include <vector>       
#include <tuple>
#include <queue>

using namespace std;


bool comparator(const tuple<int,int,int>& t1, const tuple<int,int,int>& t2){
    if(get<0>(t1) < get<0>(t2)){
        return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n, k;

    cin >> n;
    cin >> k;

    vector< tuple<int,int,int> > books;
    queue<int> g[3];

    int time;
    int alice;
    int bob;
    
    for(int i = 0; i < n; i++){
       cin >> time;
       cin >> alice;
       cin >> bob;
       books.push_back(make_tuple(time,alice,bob));
    }  

    sort(books.begin(), books.end(), comparator);

    for(const auto& book: books){
        if(get<1>(book) == 1 && get<2>(book) == 1){
            g[2].push(get<0>(book));
        }
        else if(get<1>(book) == 1){
            g[0].push(get<0>(book));
        }
        else if(get<2>(book) == 1){
            g[1].push(get<0>(book));
        }
    }
    int N_reads = k;
    int total_time = 0;
    int indListsSize = min(g[0].size(), g[1].size());

    if(g[2].size() + indListsSize >= k){
        while(N_reads > 0){
            if(indListsSize > 0 && g[2].size() > 0){
                if(g[0].front() + g[1].front() < g[2].front()){
                    total_time += g[0].front() + g[1].front();
                    g[0].pop();
                    g[1].pop();
                    indListsSize--;
                }
                else{
                    total_time += g[2].front();
                    g[2].pop();
                }
            }
            else if(indListsSize > 0){
                total_time += g[0].front() + g[1].front();
                g[0].pop();
                g[1].pop();
                indListsSize--;
            }
            else{
                total_time += g[2].front();
                g[2].pop();
            }

            N_reads--;
        }

        cout << total_time << endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}