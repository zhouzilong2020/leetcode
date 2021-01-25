
class Solution {
  public static int[] sortedSquares(int[] A) {
    if (A == null) {
      return A;
    }
    int neg = 0, pos = 0, p = 0, len = A.length;
    int[] result = new int[len];
    for (int i = 0; i < len; i++) {
      // 统计正、负数的个数
      if (A[i] < 0) {
        neg++;
      } else if (A[i] > 0) {
        pos++;
      }
    }
    while (p < len) {
      if (p < len - neg - pos) {
        // 出现0,则平方和的前n项必为0
        result[p++] = 0;
      } else {
        pos = len - pos;
        neg = neg - 1;
        while (pos < len && neg >= 0) {
          // 当数组内还有正数或者负数的时候
          if (A[pos] > -A[neg]) {
            // 正数的绝对值大
            result[p++] = (A[neg]) * (A[neg]);
            neg--;
          } else {
            result[p++] = (A[pos]) * (A[pos]);
            pos++;
          }
        }
        while (pos < len) {
          // 结束循环后还有正数,直接补到后面
          result[p++] = (A[pos]) * (A[pos]);
          pos++;
        }
        while (neg >= 0) {
          result[p++] = (A[neg]) * (A[neg]);
          neg--;
        }
      }
    }

    return result;
  }

  public static void main(String[] args) {
    int[] A = { 1, 1 };
    sortedSquares(A);
    System.out.println("asd");
  }
}
