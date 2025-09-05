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

const int MAXN = 200005;
const int LOG = 18;

vector<int> t_dest_arr(MAXN);
vector<vector<int>> teleport_table(MAXN, vector<int>(LOG));

vector<int> dist_to_cycle_arr(MAXN);
vector<int> cycle_id_arr(MAXN);
vector<int> pos_in_cycle_arr(MAXN);
vector<int> cycle_len_arr(MAXN);
int current_cycle_id_counter;

vector<bool> visited_global_arr(MAXN);

void find_cycles_and_paths(int u) {
    vector<int> path_stack;
    map<int, int> path_map;

    int curr = u;
    int dist_in_path = 0;

    while (!visited_global_arr[curr] && path_map.find(curr) == path_map.end()) {
        path_map[curr] = dist_in_path;
        path_stack.push_back(curr);
        
        curr = t_dest_arr[curr];
        dist_in_path++;
    }

    for (int node_on_path : path_stack) {
        visited_global_arr[node_on_path] = true;
    }

    if (path_map.count(curr)) {
        int cycle_start_node = curr;
        int cycle_start_dist_in_path = path_map[curr];
        int current_cycle_length = dist_in_path - cycle_start_dist_in_path;
        
        current_cycle_id_counter++;
        cycle_len_arr[current_cycle_id_counter] = current_cycle_length;

        for (int i = cycle_start_dist_in_path; i < path_stack.size(); ++i) {
            int node_on_cycle = path_stack[i];
            cycle_id_arr[node_on_cycle] = current_cycle_id_counter;
            dist_to_cycle_arr[node_on_cycle] = 0;
            pos_in_cycle_arr[node_on_cycle] = (i - cycle_start_dist_in_path);
        }

        for (int i = cycle_start_dist_in_path - 1; i >= 0; --i) {
            int node_in_tree = path_stack[i];
            cycle_id_arr[node_in_tree] = current_cycle_id_counter;
            dist_to_cycle_arr[node_in_tree] = cycle_start_dist_in_path - i; // Corrected line
        }
    } else {
        int target_cycle_id = cycle_id_arr[curr];
        int target_dist_to_cycle = dist_to_cycle_arr[curr];

        for (int i = path_stack.size() - 1; i >= 0; --i) {
            int node_in_tree = path_stack[i];
            cycle_id_arr[node_in_tree] = target_cycle_id;
            dist_to_cycle_arr[node_in_tree] = target_dist_to_cycle + (path_stack.size() - 1 - i) + 1;
        }
    }
}

int reach_k_teleportations(int start_node, int k) {
    int curr = start_node;
    for (int j = LOG - 1; j >= 0; --j) {
        if (k >= (1 << j)) {
            curr = teleport_table[curr][j];
            k -= (1 << j);
        }
    }
    return curr;
}

int32_t main(){
    auto begin = std::chrono::high_resolution_clock::now();
    fast_io;

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> t_dest_arr[i];
    }
    
    current_cycle_id_counter = 0;
    fill(visited_global_arr.begin(), visited_global_arr.begin() + n + 1, false);
    
    for (int i = 1; i <= n; ++i) {
        if (!visited_global_arr[i]) {
            find_cycles_and_paths(i);
        }
    }

    for (int i = 1; i <= n; ++i) {
        teleport_table[i][0] = t_dest_arr[i];
    }
    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            teleport_table[i][j] = teleport_table[teleport_table[i][j-1]][j-1];
        }
    }

    for (int k_query = 0; k_query < q; ++k_query) {
        int a, b;
        cin >> a >> b;

        if (cycle_id_arr[a] != cycle_id_arr[b]) {
            cout << -1 << "\n";
        } else {
            if (dist_to_cycle_arr[a] >= dist_to_cycle_arr[b]) {
                int a_at_b_level = reach_k_teleportations(a, dist_to_cycle_arr[a] - dist_to_cycle_arr[b]);
                
                if (a_at_b_level == b) {
                    cout << dist_to_cycle_arr[a] - dist_to_cycle_arr[b] << "\n";
                } else {
                    if (dist_to_cycle_arr[b] != 0) {
                        cout << -1 << "\n";
                    } else {
                        ll total_dist = dist_to_cycle_arr[a];
                        int node_a_on_cycle = reach_k_teleportations(a, dist_to_cycle_arr[a]);
                        
                        int current_cycle_len = cycle_len_arr[cycle_id_arr[a]];
                        int pos_a = pos_in_cycle_arr[node_a_on_cycle];
                        int pos_b = pos_in_cycle_arr[b];
                        
                        ll dist_on_cycle = (pos_b - pos_a + current_cycle_len) % current_cycle_len;
                        total_dist += dist_on_cycle;
                        cout << total_dist << "\n";
                    }
                }
            } else {
                cout << -1 << "\n";
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: "<< elapsed.count() * 1e-9 << " seconds\n"; 
    return 0;
}