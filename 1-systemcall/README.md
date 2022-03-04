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
