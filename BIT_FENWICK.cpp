#include <bits/stdc++.h>
 
using namespace std;
using ll=long long;
#define all(x) (x).begin(), (x).end()
#define Fi first
#define Se second


const int N = 1e5 ;
vector<int> tree(N), a(N);
int n;
// 1 indexed; 

int sum(int k){
	// Returns sum of (1, k);
	int s = 0;
	while(k >= 1){
		s += tree[k];
		k -= (k & -k);
	}
	return s;
}

void add(int k, int x){
	// increase k by x;
	while(k <= n){
		tree[k] += x;
		k += (k & -k);
	}
}


void goriber_solve(){
	cin >> n;
	for(int i = 1; i <= n ; i+= 1){
		cin >> a[i];
		add(i, a[i]); // add to tree ;
	}

	int q;
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		cout << sum(r) - sum(l - 1) << '\n';
	}
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t = 1; 
    // cin >> t ;

    while(t--){
        goriber_solve() ;
    }
}

