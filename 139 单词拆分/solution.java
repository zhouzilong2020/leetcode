import java.util.List;
import java.util.HashSet;

class Solution {

  public boolean wordBreak(String s, List<String> wordDict) {
    if (s.length() == 0 || wordDict.size() == 0) {
      return false;
    }

    HashSet<String> set = new HashSet<>(wordDict);
    boolean[] dp = new boolean[s.length() + 1];
    dp[0] = true;

    for (int i = 1, len = s.length(); i <= len; i++) {
      for (int j = 0; j < i; j++) {
        if (dp[j] && set.contains(s.substring(j, i))) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[s.length()];
  }

  public static void main(String[] args) {

  }
}