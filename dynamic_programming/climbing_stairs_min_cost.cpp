// You are climbing a paid staircase. It takes n steps to reach to the top and
// you have to pay p[i] to step on the i-th stair.
// Each time you can climb 1 or 2 steps. What's the cheapest amount you have to
// pay to get to the top of the staircase?

#include <algorithm>
#include <iostream>
#include <vector>

// Time Complexity: O(n)
// Space Complexity: O(n)
int ClimbStairsMinCost(int n, const std::vector<int>& p) {
  std::vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = p[1];
  for (int i = 2; i <= n; ++i) {
    dp[i] = std::min(dp[i - 1], dp[i - 2]) + p[i];
  }
  return dp[n];
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> p(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    std::cin >> p[i];
  }

  int result = ClimbStairsMinCost(n, p);
  std::cout << result << std::endl;
  return 0;
}
