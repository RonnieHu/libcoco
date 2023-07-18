# libcoco：一个协程库的实现

## 特点

* 参考并对libco的协程切换汇编进行了改进，编写了符合System V ABI的x86_64协程上下文切换的汇编实现。

* 不同于libco的C语言编程风格，本项目使用C++11语法编写，实现了一个Stackful协程，协程绑定执行函数时支持lambda表达式和可变参数函数。

* 参考云风的coroutinue实现，采用Schedule统一的对称式调度方式，依次对定时队列、就绪队列、等待队列和退出队列进行调度。

* 对于socket/accept/connect/send/recv等几个系统调用进行了HOOK，对epoll进行了封装，能够容易地运用本项目进行网络开发。


## 相关知识

* 有栈&无栈：有栈协程指协程使用栈存放其上下文，具体分为共享栈（所有协程共享一个栈）和非共享栈（也叫独立栈）；无栈协程指利用有限自动机实现协程切换。

* 对称&非对称：对称式协程指调度器统一调度每个协程；非对称式协程指当前协程让出CPU时只能它的caller继续执行。

* 协作式：指当前协程主动让出CPU供其他协程执行。 

* 栈的增长从高地址向低地址；堆元素的增长方向为从低地址向高地址，使用堆模拟栈时需要找到栈顶，从栈顶开始执行上下文。此外，堆元素内部的子元素的增长方向也是从低地址向高地址的。

* 必须保存的上下文：rip + rsp + rbp + callee-saved register(rbx r12-r15)

* dlsym 是一个在动态链接库（Dynamic Linking Library）中查找符号（Symbol）的函数。它是在 C 语言中使用的一个函数，用于在运行时从共享库（或动态链接库）中获取函数或变量的地址。


## 构建

```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

