#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define i32 int32_t
#define i64 int_fast64_t
#define lli long long int
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repv(i,a,b) for(int i = a; i >=b; i--)
#define mod 1000000007
#define inf (1LL<<60)
const ll mod1 = 998244353ll;
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vbl vector<bool>
#define vvbl vector<vector<bool>>
#define mkp make_pair
#define vpll vector<pair<long long, long long>>
#define vpi vector<pair<int, int>>
#define dsort(a) sort(all(a), greater<ll>())
#define read(a, n) for(int_fast64_t i=0 ; i<n ; i++) cin >> a[i]
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define maxof(...) max({__VA_ARGS__})
#define minof(...) min({__VA_ARGS__})
#ifdef Arnav
#include <iostream>
#define debug(x) \
    std::cerr << #x << " = " << (x) << std::endl;
#else
#define debug(x)
#endif
#define sumv(arr) accumulate(all(arr), 0LL)

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

/*-----------------------------------------------------------------------------------------------------------------------*/

vector<int> path; 

void dfs(int node, vector<unordered_set<int>>& adj) {
    while (!adj[node].empty()) {
        int v = *adj[node].begin();
        adj[node].erase(v);
        adj[v].erase(node);
        dfs(v, adj);
    }
    path.push_back(node);
}


int32_t main(){ 
    auto begin = std::chrono::high_resolution_clock::now(); 
    fast_io;
    int n, m;
    cin >> n >> m;
    // Changed from set to unordered_set since TC of set O(LogN) and of unorderedset is O(1)
    vector<unordered_set<int>> adj(n); 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (int i = 0; i < n; ++i) {
        if (adj[i].size() % 2 != 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    vector<bool> vis(n, false);
    int cnt = 0;

    function<void(int)> dfs_visit = [&](int node){
        if (vis[node]) return;
        vis[node] = true;
        cnt++;
        for (int v : adj[node])
            if (!vis[v]) dfs_visit(v);
    };

    dfs_visit(0);
    int used_nodes = 0;
    for (int i = 0; i < n; ++i){
        if (!adj[i].empty()) used_nodes++;
    }

    if (cnt < used_nodes) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    dfs(0, adj);
    if ((int)path.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int x : path) cout << x + 1 << ' ';
    cout << '\n';

    auto end = std::chrono::high_resolution_clock::now(); 
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
    cerr << "Time measured: "<< elapsed.count() * 1e-9 << " seconds\n";  
    return 0; 
}
