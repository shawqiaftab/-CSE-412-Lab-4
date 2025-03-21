#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define Fi first
#define Se second

const int N = 1e6 + 10;
ll ans = 0;
vector<ll> a;
ll freq[N];

void remove(int id){
    ll num = a[id];

    ans -= freq[num] * freq[num] * num;
    freq[num] -= 1;
    ans += freq[num] * freq[num] * num;
}

void add(int id){
    ll num = a[id];

    ans -= max(0ll, freq[num] * freq[num] * num);
    freq[num] += 1;
    ans += freq[num] * freq[num] * num;
}

inline ll get_ans(){
    return ans;
}

const int block_size = 1246;
struct Query {
    int l, r, idx;
    bool operator<(Query other) const {
        if (l / block_size != other.l / block_size)
            return l < other.l;
        return ((l / block_size) & 1) ? (r > other.r) : (r < other.r);
    }
};

vector<ll> mo_s_algorithm(vector<Query> queries) {
    vector<ll> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_ans();
    }
    return answers;
}

void goriber_solve(){
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for(auto &k : a) cin >> k;
    vector<Query> qu(q);
    int c = 0;;
    for(auto &[x, y, id] : qu){
        cin >> x >> y;
        id = c; 
        c += 1;
        x -= 1, y -= 1;
    }
    vector<ll> ans = mo_s_algorithm(qu);
    for(const auto &k : ans)
        cout << k << '\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t = 1; 
    // cin >> t ;
    // cerr << sqrtl(1e6) << '\n';

    while(t--){
        goriber_solve() ;
    }
}
