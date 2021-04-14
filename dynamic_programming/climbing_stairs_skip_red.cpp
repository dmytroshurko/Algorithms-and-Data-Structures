// You are climbing a staircase. It takes n steps to reach to the top.
// Each time you can climb 1...k steps. You are not allowed to step on the red
// stairs. In how many distinct ways can you climb to the top?

#include <algorithm>
#include <iostream>
#include <vector>

// Time Complexity: O(n * k)
// Space Complexity: O(k)
int ClimbStairsKStepsSkipRed(int n, int k, const std::vector<bool>& stairs) {
  std::vector<int> dp(k);
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    // if it is a red stair
    if (stairs[i]) {
      dp[i % k] = 0;
    } else {
      for (int j = 1; j < k; ++j) {
        if (i - j < 0) {
          continue;
        }
        dp[i % k] += dp[(i - j) % k];
      }
    }
  }
  return dp[n % k];
}

int main() {
  int n, k;
  std::cin >> n >> k;

  // 0-th stair is always false (not red)
  std::vector<bool> red_stairs(n + 1);
  int stair;
  for (int i = 1; i <= n; ++i) {
    std::cin >> stair;
    red_stairs[i] = static_cast<bool>(stair);
  }

  int result = ClimbStairsKStepsSkipRed(n, k, red_stairs);
  std::cout << result << std::endl;
  return 0;
}
