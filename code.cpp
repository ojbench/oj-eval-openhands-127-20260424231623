
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n + 2);
    a[0] = 1;
    a[n + 1] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0));

    for (int len = 3; len <= n + 2; ++len) {
        for (int i = 0; i <= n + 2 - len; ++i) {
            int j = i + len - 1;
            for (int k = i + 1; k < j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);
            }
        }
    }

    cout << dp[0][n + 1] << endl;

    return 0;
}
