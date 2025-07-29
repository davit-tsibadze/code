#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
 
#define ff first
#define sc second
#define pb push_back
#define ll long long
#define pll pair<ll, ll>
#define pii pair<ll, ll>
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll wmod = 998244353;
const ll hashp = 79333;
const ll hashmod = 2234558939;
#define int long long
int n, m, k;
vector <int> d(200001, inf), t(200001, inf);
vector <vector <pii>> g(200001), G(200001);
void dijkstra(){
    d[k] = 0;
    set <pii> st;
    st.insert({0, k});
    while(st.size()){
        auto cur = *st.begin();
        st.erase(cur);
        for (auto y : g[cur.sc]){
            if (d[y.ff] > d[cur.sc] + y.sc){
                st.erase({d[y.ff], y.ff});
                d[y.ff] = d[cur.sc] + y.sc;
                st.insert({d[y.ff], y.ff});
            }
        }
    }
}
void dijkstra1(){
    t[1] = -d[1];
    set <pii> st;
    st.insert({t[1], 1});
    while(st.size()){
        auto cur = *st.begin();
        st.erase(cur);
        for (auto y : G[cur.sc]){
            int x = max(cur.ff + y.sc, -d[y.ff]);
            // cout << '\n';
            // cout << "AGER ";
            // cout << y.ff << ' ' << x << '\n';
            if (x >= d[y.ff])continue;
            if (t[y.ff] > x){
                st.erase({t[y.ff], y.ff});
                t[y.ff] = x;
                st.insert({t[y.ff], y.ff});
            }
        }
    }
}
void solve(){
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        g[x].pb({y, r});
        g[y].pb({x, r});
        G[x].pb({y, l});
        G[y].pb({x, l});
    } dijkstra(); dijkstra1();
    cout << (t[n] == inf ? "NO" : "YES");
    // for (int i = 1; i <= n; i++){
    //     cout << t[i] << ' ';
    // }
    for (int i = 1; i <= n; i++){
        g[i].clear();
        G[i].clear();
        d[i] = inf; t[i] = inf;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr); 

    ll T = 1;
    cin >> T;
    while(T--){
        solve();    
        cout << '\n';
    }
    return 0;
}









