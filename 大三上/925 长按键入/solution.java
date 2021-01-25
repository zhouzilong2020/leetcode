class Solution {
  public boolean isLongPressedName(String name, String typed) {
    int i = name.length() - 1, j = typed.length() - 1;
    int nameCnt, typeCnt;
    if (j < i) {
      // typed只可能大于name的长度!
      return false;
    }
    while (i >= 0 && j >= 0) {
      nameCnt = 0;
      typeCnt = 0;
      while (j > 0 && typed.charAt(j) == typed.charAt(j - 1)) {
        j--;
        typeCnt++;
      }
      while (i > 0 && name.charAt(i) == name.charAt(i - 1)) {
        i--;
        nameCnt++;
      }
      if (name.charAt(i) == typed.charAt(j) && nameCnt <= typeCnt) {
        i--;
        j--;
      } else {
        return false;
      }
    }
    if (i >= 0 || j >= 0) {
      return false;
    }
    return true;
  }

  public static void main(String[] args) {
    Solution s = new Solution();

    if (s.isLongPressedName("zlexya", "aazlllllllllllllleexxxxxxxxxxxxxxxya")) {
      System.out.println("true");
    } else {
      System.out.println("false");
    }
  }
}