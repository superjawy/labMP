#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <set>
#include <deque>
#include <queue>
#include <map>
#define int long long
#define endl "\n"
using namespace std;
const int inf = 1e9;
long double eps = 1e-9;
vector <int> h;
vector <int> p;
vector <int> h1;
vector <int> p1;
int  b = 27;
int M = 1e9 + 7;
int get(int l, int r) {
    return (h[r + 1] - (h[l] * p[r - l + 1]) % M + M) % M;
}
int get1(int l, int r) {
    return (h1[r + 1] - (h1[l] * p1[r - l + 1]) % M + M) % M;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, t;
    cin >> t;
    int n = t.size();
    h.resize(n + 1);
    p.resize(n + 1);
    int len, i;
    h[0] = 0;
    p[0] = 1;
    for (i = 0; i < n; i++) {
        h[i + 1] = (h[i] * b + (t[i] - 'a' + 1)) % M;
        p[i + 1] = (p[i] * b) % M;
    }
    h1.resize(n + 1);
    p1.resize(n + 1);
    h1[0] = 0;
    p1[0] = 1;
    for (i = 1; i <= t.size(); i++) {
        s += t[i - 1];
        h1[i] = (h1[i - 1] * b + (s[i - 1] - 'a' + 1)) % M;
        p1[i] = (p1[i - 1] * b) % M;
        int j = 0;
        int ep = s.size();
        for (int e = 0; e <= n - ep; e += i) {
            if (get(e, e + ep - 1) == get1(0, ep - 1)) {
                j++;
            }
        }
        if (n % i == 0 && t.size() / i == j) {
            cout << t.size() / i;
            return 0;
        }
    }
    return 0;
}
