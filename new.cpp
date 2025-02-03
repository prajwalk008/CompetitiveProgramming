#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<lli, lli> pll;
typedef pair<pll, lli> ppl;


void solve() {
    int n; cin >> n;

    int op = INT_MAX;

    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        op = min(op, abs(0-x));
    }

    cout << op << "\n";
}


int main() {
    solve();
}