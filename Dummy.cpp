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
