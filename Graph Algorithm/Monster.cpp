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

vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<char> moveChar = {'R', 'L', 'D', 'U'};

int32_t main(){
    auto begin = std::chrono::high_resolution_clock::now();
    fast_io;
    
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    rep(i, 0, n) cin >> grid[i];

    queue<pair<int, int>> q;
    pii start;
    vvi minTime(n, vi(m, 1e9));
    vector<vector<char>> direction(n, vector<char>(m));

    rep(i, 0, n){
        rep(j, 0, m){
            if(grid[i][j] == 'M'){
                q.push({i, j});
                minTime[i][j] = 0;
            }
            if(grid[i][j] == 'A') start = {i, j};
        }
    }
    while(!q.empty()){
        auto [row, col] = q.front(); q.pop();
        for(int d=0 ; d<4 ; d++){
            int nr = row + dir[d][0];
            int nc = col + dir[d][1];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && minTime[nr][nc] == 1e9 && grid[nr][nc] != '#'){
                minTime[nr][nc] = minTime[row][col] + 1;
                q.push({nr, nc});
            }
        }
    }
    
    vvbl vis(n, vbl(m, false));
    vector<vector<pii>> parent(n, vector<pii>(m, {-1, -1}));
    vvi dist(n, vi(m, 0));
    q.push(start);
    vis[start.first][start.second] = true;
    pii escape = {-1, -1};
    
    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();
        if(r == 0 || r == n-1 || c == 0 || c == m-1){
            escape = {r, c};
            break;
        }
        for(int d=0 ; d<4 ; d++){
            int nr = r + dir[d][0];
            int nc = c + dir[d][1];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] != '#'){
                if(minTime[nr][nc] > dist[r][c] + 1){
                    vis[nr][nc] = true;
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                    parent[nr][nc] = {r, c};
                }
            }
        }
    }

    if(escape.first == -1){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        string path = "";
        pii curr = escape;
        while(curr != start){
            pii prev = parent[curr.first][curr.second];
            for(int d = 0; d < 4; ++d){
                if(prev.first + dir[d][0] == curr.first && prev.second + dir[d][1] == curr.second){
                    path += moveChar[d];
                    break;
                }
            }
            curr = prev;
        }
        reverse(all(path));
        cout << path.size() << "\n";
        cout << path << "\n";
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: "<< elapsed.count() * 1e-9 << " seconds\n"; 
    return 0;
}