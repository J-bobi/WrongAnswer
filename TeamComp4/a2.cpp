#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int k, n;
	std::cin >> k >> n;

	std::vector<int> sticks(k);

	for (int i = 0; i < k; ++i) {
		std::cin >> sticks[i];
	}

	std::sort(sticks.begin(), sticks.end());

	while (!sticks.empty() && sticks.back() > n) {
		sticks.pop_back();
		--k;
	}

	std::vector<std::vector<bool>> win(1 << k, std::vector<bool>(n + 1, false));

	for (int len = 0; len <= n; ++len) {
		for (int mask = 0; mask < (1 << k); ++mask) {
			for (int i = 0; i < k; ++i) {
				if ((mask & (1 << i)) && sticks[i] <= len) {
					if (!win[mask ^ (1 << i)][len - sticks[i]]) {
						win[mask][len] = true;
					}
				}
			}
		}
		std::cout << len << ' ' << (win[(1 << k) - 1][len] ? "WIN" : "LOSE") << '\n';
	}

	return 0;
}
