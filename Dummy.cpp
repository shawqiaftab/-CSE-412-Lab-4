#include <iostream>

using namespace std;
using ll = long long;

void goriber_solve() {
    int n;
    cin >> n;
    int a[n];
    for (int &i : a) cin >> i;
    ll pres[n + 1] = {}, prexr[n + 1] = {};
    for (int i = 0; i < n; ++i) {
        pres[i + 1] = pres[i] + a[i];
        prexr[i + 1] = prexr[i] ^ a[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int lo = i, hi = n;
        while (lo <= hi) {
            int mid = lo + hi >> 1;
            ll sum = pres[mid] - pres[i - 1];
            ll xr = prexr[mid] ^ prexr[i - 1];
            if (sum == xr) lo = mid + 1;
            else hi = mid - 1;
        }
        ans += hi - i + 1;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    // cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        goriber_solve();
    }
}
/* TLE KHAY
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void goriber_solve() {
    int n, c;
    cin >> n >> c;

    int d[c + 1][c + 1] = {},
        a[n + 1][n + 1] = {};

    for (int i = 1; i <= c; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> d[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    int ans = 1e9;
    vector<int> group[3];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            group[(i + j) % 3].push_back(a[i][j]);
        }
    }

    for (int c0 = 1; c0 <= c; ++c0) {
        for (int c1 = 1; c1 <= c; ++c1) {
            for (int c2 = 1; c2 <= c; ++c2) {
                if (c1 == c0 or c0 == c2 or c1 == c2) continue;
                int cost = 0;

                for (auto &x : group[0]) {
                    cost += d[x][c0];
                }
                for (auto &x : group[1]) {
                    cost += d[x][c1];
                }
                for (auto &x : group[2]) {
                    cost += d[x][c2];
                }
                ans = min(ans, cost);
            } 
        }
    }
    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    // cin >> T;
    cerr << 30 * 30 * 30 * 500 << "\n";
    cerr << (int) 2e8 << "\n";

    for (int tc = 1; tc <= T; ++tc) {
        goriber_solve();
    }
}
*/
