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

vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
vector<char> moves = {'D', 'U', 'L', 'R'};

bool vis[7][7];

ll ans = 0;

void solve(int index, string s, int row, int col){
    if(index == 48){
        ans += (row == 6 && col == 0);
        return;
    }
    if(row == 6 && col == 0) return;

    ll ans = 0;
    
    if(( (row == 0 || vis[row-1][col]) && (row == 6 || vis[row+1][col]) ) &&
                        (col > 0 && !vis[row][col-1]) && (col < 6 && !vis[row][col+1])) return;


    if(( (col == 0 || vis[row][col-1]) && (col == 6 || vis[row][col+1]) ) && 
                            (row > 0 && !vis[row-1][col]) && (row < 6 && !vis[row+1][col])) return;

    if(s[index] == '?'){
        rep(d, 0, 4){
            int nrow = row + dir[d][0];
            int ncol = col + dir[d][1];
            if(nrow >=0 && nrow < 7 && ncol >=0 && ncol < 7 && !vis[nrow][ncol]){
                vis[nrow][ncol] = true;
                // s[index] = moves[d];
                solve(index+1, s, nrow, ncol);
                vis[nrow][ncol] = false;
                // s[index] = '?';
            }
        }
    }
    else{
        int d = -1;
        rep(d, 0, 4){
            if(moves[d] == s[index]){
                int nrow = row + dir[d][0];
                int ncol = col + dir[d][1];
                if(nrow >=0 && nrow < 7 && ncol >=0 && ncol < 7 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = true;
                    solve(index+1, s, nrow, ncol);
                    vis[nrow][ncol] = false;
                }
                return;
            }
        }
    }
    return;
}

int32_t main(){
    auto begin = std::chrono::high_resolution_clock::now();
    fast_io;

    string s;
    cin >> s;
    memset(vis, 0, sizeof(vis));
    vis[0][0] = 1;
    solve(0, s, 0, 0);

    cout << ans << endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: "<< elapsed.count() * 1e-9 << " seconds\n"; 
    return 0;
}