#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    int ElsieTypingMode;
    cin >> T >> ElsieTypingMode;

    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        vector<char> typed(N);
        int flip = 0;

        for (int i = N - 1; i >= 0; i--) {
            int desired = (S[i] == 'O');
            int cur = desired ^ flip;
            typed[i] = cur ? 'O' : 'M';
            if (typed[i] == 'O') flip ^= 1;
        }

        cout << "YES\n";
        if (ElsieTypingMode == 1) {
            for (char c : typed) cout << c;
            cout << "\n";
        }
    }
    return 0;
}
