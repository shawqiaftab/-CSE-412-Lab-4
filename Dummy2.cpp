#include <iostream>

using namespace std;
using ll = long long;

char alter(char x){
    if (x == '.') return '#';
    return '.';
}

void generate(int x, int mode) {
    for (int i = 0; i < 50; ++i) {
        char p = mode == 1 ? '#' : '.';
        if (i & 1) {
            for (int j = 0; j < 100; ++j) {
                if (j & 1) {
                    if (x) {
                        cout << alter(p);
                        --x;
                    }
                    else cout << p;
                }
                else cout << p;
            }
        }
        else for (int j = 0; j < 100; ++j) cout << p;
        cout << "\n";
    }
}

void goriber_solve() {
    cout << "100 100\n";
    int a, b;
    cin >> a >> b;
    a -= 1;
    b -= 1;
    generate(a, 1);
    generate(b, 0);
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

//