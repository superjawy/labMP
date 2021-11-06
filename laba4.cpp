//Задача №165. Банкет

//На банкет были приглашены N Очень Важных Персон (ОВП). Были поставлены 2 стола. Столы достаточно большие, чтобы все посетители банкета могли сесть за любой из них. Проблема заключается в том, что некоторые ОВП не ладят друг с другом и не могут сидеть за одним столом. Вас попросили определить, возможно ли всех ОВП рассадить за двумя столами.

#include <vector>
#include <iostream>
#include <set>
 
using namespace std;
 
vector <int> col;
vector <pair<int,int>> pr;
vector<int> res;

int m;
int n;

bool analiz(int t, vector <int> color){
       for (int z = t; z < m; z++){
             int a = pr[z].first;
             int b = pr[z].second;
             if (color[a - 1] == 0){
                    if (color[b - 1] == 0){
                           color[a - 1] = 1;
                           color[b - 1] = -1;
                           if (!analiz(z+1, color)){
                                  color[a - 1] = -1;
                                  color[b - 1] = 1;
                                  return analiz(z+1, color);
                           }
                    }
                    else color[a - 1] = -color[b - 1];
             }
             else{
                    if (color[b - 1] == 0) color[b - 1] = -color[a - 1];
                    else{
                           if (color[b - 1] == color[a - 1])
                                  return false;
                    }
             }
       }
       for(int z = t; z < m; z++){
           int a = pr[z].first;
           int b = pr[z].second;
           if(color[a - 1] == 1){
               res.push_back(pr[z].first);
           }
           if(color[b - 1] == 1){
               res.push_back(pr[z].second);
           }
        }
       
       return true;
}
 
int main(){
    std::cin >> n >> m;
    int a, b;
    for (int z = 0; z < n; z++) col.push_back(0);
    for (int z = 0; z < m; z++){
        std::cin >> a >> b;
        pr.push_back(make_pair(a, b));
    }
    if (n < 2){
        std::cout << "YES";
        return 0;
    }
      
    if (analiz(0,col)){
        std::cout << "YES" << "\n";
    }
    else std::cout << "NO";
    
    set<int> int_set(res.begin(), res.end());
    res.assign(int_set.begin(), int_set.end());
    
    for(int i = 0; i < res.size(); i++){
        std::cout << res[i] << " ";
    }
    return 0;
}
