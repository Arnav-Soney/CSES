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

vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(int i, int j, int n, int m, vector<vector<int>> &a, vector<vector<bool>> &vis, int &cnt){
    queue<pii> q;
    q.push({i, j});    
    vis[i][j] = true;
    cnt++;
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(auto it: dir){
            int nrow = row + it[0];
            int ncol = col + it[1];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && a[nrow][ncol] == 1 && !vis[nrow][ncol]){
                vis[nrow][ncol] = true;
                q.push({nrow, ncol});
            }
        }
    }
    return;
}

int32_t main(){
    auto begin = std::chrono::high_resolution_clock::now();
    fast_io;
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vvbl vis(n, vbl(m, false));
    string str;
    rep(i, 0, n){
        cin >> str;
        rep(j, 0, m){
            if(str[j] == '#') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    int cnt = 0;
    rep(i, 0, n){
        rep(j, 0, m){
            if(a[i][j] == 1 && !vis[i][j]) bfs(i, j, n, m, a, vis, cnt);
        }
    }

    cout << cnt << endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: "<< elapsed.count() * 1e-9 << " seconds\n"; 
    return 0;
}