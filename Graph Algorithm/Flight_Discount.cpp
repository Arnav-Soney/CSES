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

vll dijkstra(int src, vector<vector<pll>>& adj){
    vll dist(adj.size(), inf);
    dist[src] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        auto [d, node] = pq.top();
        pq.pop();
        if(d > dist[node]) continue;
        for(auto [next, weight] : adj[node]){
            if(dist[next] > dist[node] + weight){
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }
    return dist;
}

int32_t main(){
    auto begin = std::chrono::high_resolution_clock::now();
    fast_io;
    
    int n, m; cin >> n >> m;
    vector<vector<pll>> adj(n), revAdj(n);
    rep(i, 0, m){
        int u, v, wt; cin >> u >> v >> wt;
        u--; v--;
        adj[u].pb({v, wt});
        revAdj[v].pb({u, wt});
    }
    vll startCost = dijkstra(0, adj);
    vll endCost = dijkstra(n-1, revAdj);
    ll totalMin = inf;
    rep(u, 0, n){
        for(auto& [nbr, wt]: adj[u]){
            if(startCost[u]==inf || endCost[nbr] == inf) continue;
            totalMin = min(totalMin, startCost[u]  + (wt/2) + endCost[nbr]);
        }
    }
    cout << ((totalMin == inf) ? -1 : totalMin) << endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: "<< elapsed.count() * 1e-9 << " seconds\n"; 
    return 0;
}