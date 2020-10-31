class Solution {
  public boolean isOneBitCharacter(int[] bits) {
    if (bits[bits.length - 1] == 1) {
      return false;
    }
    return isBitImpt(bits, bits.length - 2);
  }

  boolean isBitImpt(int[] bits, int i) {
    if (i == -1) {
      return true;
    }
    if (i - 1 >= 0 && bits[i] == 1 && bits[i - 1] == 1) {
      return isBitImpt(bits, i - 2);
    } else if (i - 1 >= 0 && bits[i] == 0) {
      return isBitImpt(bits, i - 2);
    } else {
      return false;
    }
  }

  public static void main(String[] args) {
    Solution s = new Solution();
    int[] arr = { 1, 1,1, 0 };
    System.out.println(s.isOneBitCharacter(arr));
  }
}