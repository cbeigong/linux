scanf 
read(0)
open(fifo) 
read(fd_fifo) 左边都是阻塞函数
write(fd_fifo)  也是一个阻塞函数

定时监听，每过一段时间就判断是否是是
监听集合最多又1024 个字节
创建 fd_set sets
select 
int arr[32] 一个32个整数数组就可以表示1024个位了。
0 - 31 arr[0]
32-63 arr[1];
i >> 3 ===> i / 32  
i % 32 ====> i & 0x1f  //左边和右边的写法是相同的

===>
arr[i >> 5] & (1 << (1 % 32))

992 - 1023 arr[31]

 
fd 0_1023

1024 bit
0 - obit;
5
i - ibit
0755123
1 billion
统计不重复的电话号码 时间和空间复杂度最小，
思路：用1 歌bit 表示一个电话号码。

