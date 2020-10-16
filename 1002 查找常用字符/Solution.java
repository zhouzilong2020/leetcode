import java.util.ArrayList;
import java.util.List;

class Solution {
  public static List<String> commonChars(String[] A) {
    int[][] cnt = new int[2][26];
    List<String> result = new ArrayList<String>();

    // 记录第一个字符串的信息
    for (int i = 0, lenStr = A[0].length(); i < lenStr; i++) {
      cnt[0][A[0].charAt(i) - 'a']++;
    }

    for (int i = 1, lenA = A.length; i < lenA; i++) {
      for (int j = 0, lenStr = A[i].length(); j < lenStr; j++) {
        if (cnt[0][A[i].charAt(j) - 'a'] != 0) {
          cnt[1][A[i].charAt(j) - 'a']++;
        }
      }
      for (int k = 0; k < 26; k++) {
        cnt[0][k] = cnt[0][k] < cnt[1][k] ? cnt[0][k] : cnt[1][k];
        cnt[1][k] = 0;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (cnt[0][i] != 0) {
        // result.add((cnt[0][i] + 97);
      }
      while (cnt[0][i] != 0) {
        result.add(String.valueOf((char) (i + 'a')));
        cnt[0][i]--;
      }
    }
    return result;
  }

  public static void main(String[] args) {
    // String[] A = { "bella", "label", "roller" };
  }
}