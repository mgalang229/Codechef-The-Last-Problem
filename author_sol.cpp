#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

void Precompute() {
	int n = 1000;
	// set the size of the 2D vector to 'n' + 1
	dp = vector<vector<int>>(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		// set the first value in the row to the sum of numbers from 1 to 'i'
		dp[i][1] = (i * (i + 1)) / 2;
		for (int j = 2; j <= n; j++) {
			// set the following values by adding the previous value, increase 
			// per row ('j' - 1) and increase per column ('i' - 1)
			dp[i][j] = dp[i][j - 1] + (j - 1) + (i - 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	// precompute the values in the matrix
	Precompute();
	while (tt--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		int sum = 0;
		for (int i = r1; i <= r2; i++) {
			// calculate the sum of values from the 'r1'-th row to the 'r2'-th
			// row but only add the values in the first column
			// basically, the column must be in constant position
			sum += dp[i][c1];
		}
		for (int i = c1 + 1; i <= c2; i++) {
			// calculate the sum of values from the ('c1' + 1)-th (skip the 
			// first column (since it was added above) to the 'c2'-th column
			// basically, the row must be in constant position
			sum += dp[r2][i];
		}
		cout << sum << '\n';
	}
	return 0;
}
