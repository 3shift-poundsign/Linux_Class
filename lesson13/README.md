#ClassPoint


> Memory Management

1. 编译器分配：编译完成后，内存空间已经定了：全局变量、静态变量、字符串。
2. 局部变量（stack）：放在栈中，先进后出。开始时，栈的低与栈顶相同，数据入栈通常向低地址或小地址方向改变；也就是说，栈的内存空间是在程序运行时分配的。通常存储程序调用时的返回地址、传递参数、局部变量。
3. 动态分配内存（堆）：这样的内存是由程序员利用指令根据需要分配的。
4. 代码段：存放程序的指令，这个区域是受保护的，是只读的。


> test_struct.c

- 位域测试

> test_malloc.c

- malloc&free测试