//
//  main.c
//  实验
//
//  Created by  周子龙 on 2019/1/30.
//  Copyright © 2019  周子龙. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int s[10], x;
    // s由大到小排列
    for(int i = 0; i < 10; i++){
        s[i] = 10 - i;
    }
    
    cin >> x;

    int l = 0, r = 9, mid;
    while( l <= r){
        mid = (l + r) / 2;
        if( s[mid] > x){  //中间位置的元素大于x
            l = mid + 1;
        } else if ( s[mid] < x) { //中间位置的元素小于x
            r = mid - 1;
        }  else {  // 找到了
            cout << mid;
            break;
        }
    }
    return 0;
}
