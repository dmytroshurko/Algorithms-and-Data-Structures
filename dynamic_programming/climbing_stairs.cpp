// You are climbing a stair case. It takes n steps to reach to the top.
//
// Each time you can climb 1...k steps. In how many distinct ways can you climb
// to the top?

#include <iostream>
#include <vector>

// Time Complexity: O(n * k)
// Space Complexity: O(k)
int ClimbStairsKSteps(int n, int k) {
  std::vector<int> dp(k);
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < k; ++j) {
      if (i - j < 0) {
        continue;
      }
      // rewrite the number of different ways to reach each stair case
      dp[i % k] += dp[(i - j) % k];
    }
  }
  return dp[n % k];
}

int main() {
  int n, k;
  std::cin >> n >> k;
  int result = ClimbStairsKSteps(n, k);
  std::cout << result << std::endl;
  return 0;
}
