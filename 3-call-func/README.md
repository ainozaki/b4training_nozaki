### kadai3-3,4
- segmantaion fault
- bar()ではローカル変数のポインタを返しており、bar()の終了と同時にスタックから取り出されたアドレスに対してアクセスしているため。

### kadai3-5
- kadai3-5-1
|addr|stack|
|:---:|:---:|
|0x7ffd6f2ecf14|x|
|0x7ffd6f2ecf1c|frame.ptr|
|0x7ffd6f2ecf24|ret.addr|
| |allignment|
|0x7ffd6f2ecf34|y|
|0x7ffd6f2ecf3c|frame.ptr|
|0x7ffd6f2ecf44|ret.addr|
| |allignment|
|0x7ffd6f2ecf54|z|

- kadai3-5-2
- fの冒頭で`subq $32, %rsp`とスタックポインタを下げているが、なぜ32なのか分かってない(TODO)

- kadai3-5-3

### kadai3-6
- `static __arrtibute__((alwaye_inline)) inline uint64_t get_rbp()`と宣言したほうが良さそう

### kadai3-7
- get_rbp()を呼ぶためにスタック・フレームが作られてしまうため。

