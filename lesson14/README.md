# ClassPoint

## 文件操作

> 一、文件

1. 程序文件（程序代码）
2. 数据文件
3. 操作系统***以文件为单位***对数据进行管理

> 二、文件名

> 三、文件分类

1. ASCII文件（文本文件）
2. 二进制文件

> 四、文件缓冲区

缓冲区装满后，才整体向磁盘或内存读写数据

> 五、文件类型指针

1. 文件类型指针用来保存当前文件的文件名、文件大小、位置等信息
2. 声明FILE结构体使用<stdio.h>

> 六、文件的位置指针

1. 用于标记文件读写的当前位置
2. 文件追加：先将文件位置指针移动到文件尾，然后继续写入数据
3. 随机读写：可以在文件任何位置读写数据

## 文件读写操作

> 一、fopen函数打开数据文件

> FILE *fopen(const char *path, const char *mode;

| const char *mode | 说明 |
|-----|-----|
|r   |   Open text file for reading.  The stream is positioned at the beginning of the file.|
|r+  |   Open for reading and writing.  The stream is positioned at the beginning of the file.|
|w   |   Truncate file to zero length or create text file for writing.  The stream is positioned at the beginning of the file.|
|w+  |   Open for reading and writing.  The file is created if it does not exist, otherwise it is truncated.  The stream is positioned at the beginning of the file.|
|a   |  Open for appending (writing at end of file.  The file is created if it does not exist.  The stream is positioned at the end of the file.|
|a+  |   Open for reading and appending (writing at end of file.  The file is created if it does not exist.  The initial file position for reading is at the beginning of the file, but output is always appended to the end of the file.|


