#include <bits/stdc++.h>
 
using namespace std;
using ll=long long;
#define all(x) (x).begin(), (x).end()
#define Fi first
#define Se second


const int N = 100000 + 5;
const int K = 21;
const int M = 998244353;
int a[N];
int st[N][K];
int Log[N];

void build(int n){
    for (int i = 0; i < n; i++) st[i][0] = a[i];
    
    for (int j = 1; j < K; j++){
        for (int i = 0; i < n; i++){
            if ((i + (1 << (j - 1))) >= n)
                break;
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]); // gcd,sum,min,max
        }
    }
    for (int i = 2; i <= n; i++){
        Log[i] = Log[i / 2] + 1;
    }
}

int query(int l, int r){
    int j = Log[r - l + 1];
    return max(st[l][j], st[r + 1 - (1 << j)][j]); // gcd,min, max in o(1)
}
// for sum query we can just use segment tree
// How to uSe :
/*
	build(n);
	query(l, r); // 0 based;
*/

void goriber_solve(){
	
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	build(n);

	cout << query(0, 4) << '\n';
}



void tower_of_hanoi(int count, char source, char destination, char intermediate){
	if(count == 1){
		printf("Move top disc from pole %c to pole %c\n", source, destination);
	}
	else{
		tower_of_hanoi(count - 1, source, intermediate, destination);
		tower_of_hanoi(1, source, destination, intermediate);
		tower_of_hanoi(count -1, intermediate, destination, source);
	}
}


// void sliding_window(int a[], int n, int k){
// 	// minimum in k window, 
// 	deque< pair<int, int> > window ;
// 	for(int i = 0 ; i < n ; i += 1){
// 		while(!window.empty() and window.back().first >= a[i]) window.pop_back();
// 		window.push_back({a[i], i});

// 		while(window.front().second <= i - k) window.pop_front();

// 		if(i + 1 >= k) cout << window.front() << " " ; // -> Minimum ; 
// 	}
// }


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t = 1; 
    // cin >> t ;


    while(t--){
    	// tower_of_hanoi(5, 'A', 'C', 'B');
        goriber_solve() ;
    }
}

