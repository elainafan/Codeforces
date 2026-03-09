#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define frep(i, x, y) for (int i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
void solve() {
    int n;
    ll h;
    cin >> n >> h;
    vl pre(n);
    vl suf(n);
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) a[i] = h - a[i];
    ll maxx = LLONG_MIN;
    rep(i, 0, n - 1) {
        ll tot = 0;
        ll tem = LLONG_MAX;
        frep(j, i, 0) {
            tem = min(tem, a[j]);
            tot += tem;
        }
        pre[i] = tot;
    }
    frep(i, n - 1, 0) {
        ll tot = 0;
        ll tem = LLONG_MAX;
        rep(j, i, n - 1) {
            tem = min(tem, a[j]);
            tot += tem;
        }
        suf[i] = tot;
    }
    vl cnt(n);
    rep(i, 0, n - 1) {
        cnt[i] = pre[i] + suf[i] - a[i];
        maxx = max(maxx, cnt[i]);
    }
    rep(i, 0, n - 1) {
        int idx = i;
        rep(j, i + 1, n - 1) {
            if (a[j] < a[idx]) idx = j;
            maxx = max(maxx, cnt[i] + cnt[j] - cnt[idx]);
        }
    }
    cout << maxx << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
