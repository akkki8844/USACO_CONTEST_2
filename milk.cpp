// Run g++ -O2 -std=gnu++17 milk.cpp -o milk to compile it
// Run ./milk after compiling to run the program
// After doing the above, put in your input to get the accurate result.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<long long> cost(N);
    for (int i = 0; i < N; i++) cin >> cost[i];

    for (int i = 1; i < N; i++) {
        cost[i] = min(cost[i], 2 * cost[i - 1]);
    }

    vector<long long> size(N);
    size[0] = 1;
    for (int i = 1; i < N; i++) {
        size[i] = min((long long)1e18, size[i - 1] * 2);
    }

    while (Q--) {
        long long x;
        cin >> x;

        long long used = 0;
        long long ans = LLONG_MAX;

        for (int i = N - 1; i >= 0; i--) {
            long long take = x / size[i];
            used += take * cost[i];
            x -= take * size[i];

            if (x > 0) {
                ans = min(ans, used + cost[i]);
            } else {
                ans = min(ans, used);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
