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
#define debug(x) std::cerr << #x << " = " << (x) << std::endl;
#else
#define debug(x)
#endif
#define sumv(arr) accumulate(all(arr), 0LL)
typedef vector<vector<pll>> adjList;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

/*-----------------------------------------------------------------------------------------------------------------------*/

int32_t main(){
    auto begin = std::chrono::high_resolution_clock::now();
    fast_io;
    
    ll n, m;
    cin >> n >> m;

    vector<vector<pll>> adj(n);       // Forward graph
    vector<vector<int>> radj(n);      // Reverse graph for reachability

    for (int i = 0; i < m; i++) {
        ll a, b, x;
        cin >> a >> b >> x;
        a--, b--;
        adj[a].push_back({b, -x});    // Negate for max score → min path
        radj[b].push_back(a);
    }

    vector<ll> dist(n, inf);
    dist[0] = 0;

    // Bellman-Ford for n-1 iterations
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (auto &[v, w] : adj[u]) {
                if (dist[u] != inf && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    // Mark nodes affected by a negative cycle
    vector<bool> in_neg_cycle(n, false);
    for (int u = 0; u < n; u++) {
        for (auto &[v, w] : adj[u]) {
            if (dist[u] != inf && dist[u] + w < dist[v]) {
                in_neg_cycle[v] = true;
            }
        }
    }

    // BFS from nodes in negative cycle to check if node n-1 can be reached
    vector<bool> visited(n, false);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_neg_cycle[i]) {
            q.push(i);
            visited[i] = true;
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == n - 1) {
            cout << -1 << '\n'; // Infinite score possible
            return 0;
        }
        for (auto &[v, w] : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    // Case 1: destination unreachable at all
    if (dist[n - 1] == inf) {
        cout << -1 << '\n';
        return 0;
    }

    // Otherwise, return max score
    cout << -dist[n - 1] << '\n';


    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds\n"; 
    return 0;
}
