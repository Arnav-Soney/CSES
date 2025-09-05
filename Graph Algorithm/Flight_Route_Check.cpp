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
void dfs1(int node, vvll& adj, vbl& vis, stack<int>& st) {
    vis[node] = true;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs1(it, adj, vis, st);
        }
    }
    st.push(node);
}

void dfs2(int node, vvll& revAdj, vbl& vis, vi& component, int compID) {
    vis[node] = true;
    component[node] = compID;
    for(auto it : revAdj[node]) {
        if(!vis[it]) {
            dfs2(it, revAdj, vis, component, compID);
        }
    }
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    fast_io;

    int n, m;
    cin >> n >> m;

    vvll adj(n), revAdj(n);
    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        revAdj[v].pb(u);
    }

    vbl vis(n, false);
    stack<int> st;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs1(i, adj, vis, st);
        }
    }

    vis.assign(n, false);
    vi component(n, -1);
    int compID = 0;

    while(!st.empty()) {
        int u = st.top(); st.pop();
        if(!vis[u]) {
            dfs2(u, revAdj, vis, component, compID);
            compID++;
        }
    }

    if(compID == 1) cout << "YES\n";
    else {
        cout << "NO\n";
        int a = -1, b = -1;
        rep(i, 0, n) {
            if(component[i] != component[0]) {
                a = 0;
                b = i;
                break;
            }
        }
        vis.assign(n, false);
        stack<int> dummy;
        dfs1(b, adj, vis, dummy);
        if(!vis[a]) cout << b + 1 << " " << a + 1 << endl;
        else cout << a + 1 << " " << b + 1 << endl;
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: "<< elapsed.count() * 1e-9 << " seconds\n"; 
    return 0;
}