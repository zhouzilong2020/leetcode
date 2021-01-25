import java.util.List;
import java.util.ArrayList;

class Solution {
  public List<Integer> partitionLabels(String S) {
    List<Integer> result = new ArrayList<Integer>();
    int[] dp = new int[26];
    int p, last, len = S.length();

    // 初始化dp数组
    for (int i = 0; i < 26; i++) {
      dp[i] = -1;
    }
    // 记录每一个字母最后一次出现的位置
    for (int i = len - 1; i >= 0; i--) {
      p = S.charAt(i) - 'a';
      if (dp[p] == -1) {
        dp[p] = i;
      }
    }

    p = 0;
    while (p < len) {
      last = dp[S.charAt(p) - 'a'];
      for (int i = p + 1; i < last; i++) {
        if (dp[S.charAt(i) - 'a'] > last) {
          last = dp[S.charAt(i) - 'a'];
        }
      }
      result.add(last - p + 1);
      p = last + 1;
    }

    return result;
  }

  // public static void main(String[] args) {
  //   int a = 'a' - 'b';
  //   System.out.println(a);
  // }
}