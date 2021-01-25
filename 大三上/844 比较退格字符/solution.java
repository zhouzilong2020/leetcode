class Solution {
  public boolean backspaceCompare(String S, String T) {
    int i = S.length() - 1, j = T.length() - 1;
    int back = 0;
    while (i >= 0 && j >= 0) {

      back = 0;

      while (S.charAt(i) == '#') {
        back++;
        i--;
        while (back > 0 && i >= 0) {
          if (S.charAt(i) == '#') {
            i--;
            back++;
          } else {
            i--;
            back--;
          }
        }
        if (i < 0) {
          break;
        }
      }

      back = 0;
      while (T.charAt(j) == '#') {
        back++;
        j--;
        while (back > 0 && j >= 0) {
          if (T.charAt(j) == '#') {
            j--;
            back++;
          } else {
            j--;
            back--;

          }
        }
        if (j < 0) {
          break;
        }
      }

      if (i < 0 || j < 0) {
        break;
      } else {
        if (T.charAt(j) == S.charAt(i)) {
          j--;
          i--;
        } else {
          return false;
        }
      }
    }

    int cnt = 0;
    if (i >= 0) {
      if( S.charAt(i) != '#'){
        return false;
      }
      cnt = i / 2 + 1;
      while (i >= 0) {
        if (S.charAt(i) == '#') {
          cnt--;
        }
        i--;
      }
    } else if (j >= 0) {
      if( T.charAt(j) != '#'){
        return false;
      }
      cnt = j / 2 + 1;
      while (j >= 0) {
        if (T.charAt(j) == '#') {
          cnt--;
        }
        j--;
      }
    }
    if (cnt <= 0) {
      return true;
    }
    return false;
  }
//   "j##yc##b"
//  "j##yc##bs#srqpf#zantto###########"

  // public static void main(String[] args) {
  //   String A = "j##yc##bs#srqpfzantto###########i#mwb",B = "j##yc##bs#srqpf#zantto###########i#mwb";
  //   // String A = "ab##", B = "c#d#";
  //   Solution s = new Solution();
  //   if (s.backspaceCompare(A, B)) {
  //     System.out.println("true");
  //   } else {
  //     System.out.println("false");
  //   }
  // }
}