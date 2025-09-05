#include<bits/stdc++.h>
#define ll long long
#define lli long long int
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define vi vector<int>
#define vll vector<long long>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef pair<int,int> pii;

void solve() {
    long long n;
    cin >> n;

    long long totalSum = (n * (n + 1)) / 2;

    // If the total sum is odd, it is impossible to divide into two equal sums
    if (totalSum % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    long long target = totalSum / 2;
    vector<int> set1, set2;

    // Greedy approach to form two sets
    for (long long i = n; i > 0; --i) {
        if (target >= i){
            set1.push_back(i);
            target -= i;
        } else {
            set2.push_back(i);
        }
    }

    // Output the results
    cout << set1.size() << endl;
    for (int num : set1) {
        cout << num << " ";
    }
    cout << endl;

    cout << set2.size() << endl;
    for (int num : set2) {
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    fast_io;
    solve();
    return 0;
}