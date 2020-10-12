
class Solution416 {
  static public boolean canPartition(int[] nums) {
    int sum = getSum(nums);
    // 奇数不可能拆成两子集和
    if (sum % 2 == 1) {
      return false;
    }
    // 初始化dp数组
    int len = nums.length;
    boolean dp[][] = new boolean[2][sum / 2 + 1];
    for (int i = 0; i < len; i++) {
      for (int j = 1; j < sum / 2 + 1; j++) {
        dp[i % 2][j] = dp[(i + 1) % 2][j] // 前一项可以直接到达
            || (j - nums[i] > 0 ? dp[(i + 1) % 2][j - nums[i]] : false)// 加上前一项后可以到达
            || (j == nums[i] ? true : false);// 本项可以直接到达
      }
    }
    return dp[len % 2][sum / 2];
  }

  static public int getSum(int[] nums) {

    int cnt = 0;
    for (int i : nums) {
      cnt += i;
    }
    return cnt;
  }

  public static void main(String[] args) {
    int nums[] = { 1, 2, 5, 2 };
    if (canPartition(nums)) {
      System.out.println("true");
    } else {
      System.out.println("false");
    }
  }
}
