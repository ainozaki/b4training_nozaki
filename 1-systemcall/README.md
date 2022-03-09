## kadai1-1

- `const char *`: charの値は定数であるがポインタは定数ではない
- `char * const`: charの値は定数ではないがポインタが定数である
- `const char * const`: charの値もポインタも定数である

## kadai1-2
- 755
- rwxr-xr-x

## kadai1-3
- `open("foo.txt", O_CREAT | O_EXCL, 0644)`  
- umaskは022(8)とした

## kadai1-4
- `./a.out 2> error.txt`
- bash

## kadai1-5
- 1021

## kadai1-6
- `ulimit -Sn` -> 1024
- stdin, stdout, stderrとあわせて1024になる

## kadai1-7
- 読み込むファイル名を引数として受け取る
- ファイルをopenする
- ファイルの中身を1byteずつ読み取る
- 読み取った値を標準出力する
- ファイルの末尾まで読み取ったらファイルをcloseする

## kadai1-8
任意のポインタ型に変換可能な汎用的なポインタ型

## kadai1-9
```
メモリ上でpから始まる1024byteをreadしているが、その分のメモリが確保されているとは限らない。  
char *p = (char *)malloc(1024);
read(fd, p, 1024);
```

```
int型変数pの値をint型のポインタにcastしているため、定義されているとは限らないメモリにアクセスしている。
上記と同様の問題もある。
int *p = (int *)malloc(1024/sizeof(int));
read(fd, (int *)p, 1024);
```

```
`char p[100]`なので1024byte分確保されていない。
char p[100];
read(fd, p, sizeof(p));
```

## kadai1-10
- 書き込むファイルを引数として受け取る
- ファイルをopenする(write only, 存在しない場合は新規作成, パーミッションんは0644)
- 文字列を書き込む
- ファイルをcloseする

## kadai1-11
- `write(fd, " z", 2);
- ポインタとして渡す必要がある

## kadai1-12
- 先に8*1024*1024の要素数をもつchar型の配列を用意し、すべての要素を'a'とする
- 配列を書き込むシステムコールwriteを一度だけ呼ぶ


## kadai1-13
- write: 2.646823
- fputc: 0.000594
- writeはシステムコールそのものであるが、fputcは標準ライブラリを通じてwriteのシステムコールを呼び出しており、システムコールの呼出し回数が少なくなるようにバッファリングされているため性能が向上している。


## kadai1-14
```
0000000   a   a   a   a  \n  \0  \0  \0  \0   A
0000012
```
- `lseek(fd, 4, SEEK_END)`によりファイルオフセットをファイルサイズ + 4の値に設定
- `write(fd, "A", 1)`で更新されたファイルオフセットの場所に対して書き込みを行う
- ファイルオフセットの移動により生じるwriteされていないアドレスに対しては0が書き込まれる


## kadai1-15
- 元のプログラム実行結果
```
0000000   b   b   b   b  \n   C   B
0000007
```
- 修正後実行結果
```
0000000   B   b   b   b  \n
0000005
```
- 元のプログラムではファイルを`O_APPEND`フラグを付けてopenしており、write操作の前にファイルオフセットがファイルの末尾に設定されるため、1文字目を書き換えるのではなく、ファイル末尾に追記されている。
- 修正後のプログラムでは`O_APPEND`フラグを外して実行した。


## kadai1-16
- `kadai1-16.c`に記載
- 1文字ずつreadし, その直後にwriteする


## kadai1-17
- `kadai1-17.c`に記載
- `\n`の数を記録する

## kadai1-18
- `kadai1-18.c`に記載
- 1文字ずつread, writeし、`\n`であったらカウントしている行数も標準出力する

## kadai1-19
- `kadai1-18.c`に記載
- `struct line_info`を用意し、行末のoffsetをdouble linked listに記録。
- douvle linked listをtailから読み込み、offsetを動かすことで最終行から出力する

## kadai1-20
- forkされたプロセスで更に2回forkするため、計4回Helloが表示される。

## kadai1-21
- 子プロセスのデータは親プロセスのデータのコピーなので、子プロセスで変数の値を変更しても親プロセスの変数の値には影響しない。
- 親プロセス
```
p2: x = 0
```
- 子プロセス
```
p1: x = 2
p2: x = 1
```

## kadai1-22
- 終了ステータスは`$?`で取得できる

## kadai1-23
```
aino@~/Projects/b4-training-nozaki/1-systemcall$ echo $$
4793
aino@~/Projects/b4-training-nozaki/1-systemcall$ ./a.out
[9713]: parent = 4793
	waiting for the child...
[9714]: parent = 9713
	sleeping for a while...
[9714]: child exits with␣33
[9713]: child (9714) returns 33
```

## kadai1-24
- `kadai1-24.c`に記載

## kadai1-26
- `ps -A`と全プロセスを表示させると子プロセスのpidを持つプロセスが存在することを確認した

## kadai1-27
- `kadai1-27.c`に記載

## kadai1-28
- `kadai1-28-use-fd.c`, `kadai1-28-open-fd.c`に記載
- execve実行前にopenしたファイル記述子を用いて、execve先でreadできることを確認した

## kadai1-29
- SIGSEGVを送信したところ`Segmentation fault (core dumped)`と表示された

## kadai1-30
- SIGINTをcatchするシグナルハンドラを登録しているため、Ctrl-Cを押した時もデフォルトのハンドラーであるプロセスの停止は起こらない。

## kadai1-31
- `kill -SIGKILL <pid>`

## kadai1-32
- signal handlerの中でsleepを挟んでいるが、その間に複数のSIGCHLDが送られている。
- シグナルは個数はカウントせずフラグのみで管理しているので、複数回送られているが、シグナルは1度しか送信されず、回収できない子プロセスが生じている。
```
Child exit
Child exit
Child exit
Child exit
Catch SIGCHLD
Child exit
Catch SIGCHLD
Child exit
Child exit
Child exit
Catch SIGCHLD
Child exit
Child exit
Catch SIGCHLD
```

## kadai1-33
- シグナルを受け取る回数が10より少ないことは1-32と変わらないが、waitpidが返り値が0になるまで繰り返し実行しているため、waitpidがちょうど10回呼ばれるようになった
```
Child exit
Catch SIGCHLD
waitpid
Child exit
Child exit
Child exit
Catch SIGCHLD
waitpid
waitpid
waitpid
Child exit
Child exit
Child exit
Catch SIGCHLD
waitpid
Child exit
Catch SIGCHLD
waitpid
waitpid
waitpid
Child exit
Child exit
Catch SIGCHLD
waitpid
waitpid
Catch SIGCHLD
```
