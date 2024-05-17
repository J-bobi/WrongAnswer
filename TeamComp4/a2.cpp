#include <iostream>
#include <vector>

int main() {
	int k, n;
	std::cin >> k >> n;

	std::vector<int> sticks(k);

	for (int i = 0; i < k; ++i) {
		std::cin >> sticks[i];
	}

	for (int len = 0; len <= n; ++len) {
		std::cout << len << " WIN\n";
	}

	return 0;
}

