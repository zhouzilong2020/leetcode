
const int I_AM_CONST = 0; // 遵循大keba命名法
// 这是一个类的介绍
class IAmAClass {
private:
  int aPrivateMember; //遵循小驼峰命名法

public:
  int aFunction(int a, int b); //遵循小驼峰命名法
};

/**
 * @brief: 这是函数的大概逻辑
 * @param: 这是函数的参数, a 是一个啊的时间, b, 是一个asdasd
 * @ret: 我是这个函数的返回什么东西的说明
 * @birth: created by Dablelv on 20180802, 我是这个函数的作者
 */
int IAmAClass::aFunction(int a, int b) { return 0; }

int mian() {
  // 一些逻辑
}