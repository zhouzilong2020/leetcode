class Solution {
  public int longestMountain(int[] A) {
    if (A.length == 0) {
      return 0;
    }
    int[] l2r = new int[A.length];
    int[] r2l = new int[A.length];

    // l2r[0] = A[0] < A[1] ? 1 : 0;
    // r2l[A.length - 1] = A[A.length - 1] < A[A.length - 2] ? 1 : 0;

    for (int i = 1, len = A.length; i < len - 1; i++) {
      l2r[i] = A[i] > A[i - 1] ? l2r[i - 1] + 1 : 0;
      r2l[len - 1 - i] = A[len - 1 - i] > A[len - i] ? r2l[len - i] + 1 : 0;
    }

    int max = 0;
    for (int i = 0, len = A.length; i < len; i++) {
      max = (l2r[i] != 0 && r2l[i] != 0 )?  Math.max(max, l2r[i] + r2l[i] + 1) : max;
    }
    return max;
  }

  public static void main(String[] args) {
    int[] A = { 0, 1, 2, 3, 2};
    Solution S = new Solution();
    System.out.println(S.longestMountain(A));
  }
}