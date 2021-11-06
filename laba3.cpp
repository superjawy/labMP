//Задача №1905. Удаление скобок

//Дана строка, составленная из круглых, квадратных и фигурных скобок. Определите, какое наименьшее количество символов необходимо удалить из этой строки, чтобы оставшиеся символы образовывали правильную скобочную последовательность.

#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
string ans,s;
 
vector<vector<int>>dp;
vector<char>obr(300,'.');
 
void f(int l,int r,int n){
    
    if(l > r)return;
    
    if(l == r){
        ans[r] = '/';
        return;
    }
    
    if(dp[l][r] == dp[l][r-1]+1){
        
        ans[r] = '/';
        
        f(l,r-1,n);
        
        return;
    }
    
    for(int a = l;a<r;++a){
                 
        if(obr[s[r]] == s[a]){
            
            if(a == l){
                
                if(dp[l][r] == dp[l+1][r-1]){
                
                    f(l+1,r-1,n);
                    return;
                }
                
            }
            else if(dp[l][r] == dp[l][a-1] + dp[a][r]){
                
                f(l,a-1,n);
                f(a,r,n);
                
                return;
                                
            }
            
        }
    }
    
    
    
}
 
 
 
 
int main()
{
    cin >> s;
    
    int n = s.size();
    
    dp.resize(n,vector<int>(n));
    
    obr[')'] = '(';
    obr[']'] = '[';
    obr['}'] = '{';
     
    for(int i = 0;i<n;++i)dp[i][i] = 1;
     
    for(int i = 1;i<=n;++i){
         
        for(int j = 0;j<n;++j){
             
            if(j + i >= n)break;
             
            int l = j;
            int r = j+i;
             
            dp[l][r] = dp[l][r-1] + 1;
             
            for(int a = l;a<r;++a){
                 
                if(obr[s[r]] == s[a]){
                     
                    if(a == l)dp[l][r] = min(dp[l][r],dp[l+1][r-1]);
                    else dp[l][r] = min(dp[l][r],dp[l][a-1] + dp[a][r]);
                     
                }
                 
            }
             
             
        }
         
    }
    
    ans.resize(n,'.');
    
    f(0,n-1,n);
    
    for(int i = 0;i<n;++i)if(ans[i] == '.')cout << s[i];
    
    
    
    return 0;
}
