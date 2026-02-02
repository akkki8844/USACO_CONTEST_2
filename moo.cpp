#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;

    vector<int> x(K), y(K), z(K);
    for (int i = 0; i < K; i++) {
        cin >> x[i] >> y[i] >> z[i];
        --x[i]; --y[i]; --z[i];
    }

    long long best = -1;
    long long ways = 0;

    int total = 1 << N;
    for (int mask = 0; mask < total; mask++) {
        long long score = 0;

        for (int i = 0; i < K; i++) {
            if (((mask >> x[i]) & 1) == 0 &&
                ((mask >> y[i]) & 1) == 1 &&
                ((mask >> z[i]) & 1) == 1) {
                score++;
            }
        }

        if (score > best) {
            best = score;
            ways = 1;
        } else if (score == best) {
            ways++;
        }
    }

    cout << best << " " << ways << "\n";
    return 0;
}
