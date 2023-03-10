### kadai2-1

```
double w: 0x102fc0000
double x: 0x102fc0008
float  y: 0x102fc0010
float  z: 0x102fc0014
```
double: 8byte
float: 4byte


### kadai2-2

```
x=10, *xp=10, y=20, *yp=20
x=10, *xp=30, y=30, *yp=30
```

`xp = yp;` よりint型のポインタxpの値はypの値と一致し、つまりポインタxpもポインタypもともにyへのポインタとなる。
`*yp=30;`よりyの値を変更したため、2回目のprintfではy自身、yを指すポインタxp, ypの指す値が変化した。


### kadai2-3

例示されているswap関数は引数を値渡しで受け取っているため、関数内で呼び出し元の変数を更新することはできない。
関数内で呼び出し元の変数を更新するためには、ポインタを引数で渡す必要がある。正しく動作するswap関数は`kadai1-3.c`に示す。

```

a: 10, b; 20
a: 20, b: 10

```

### kadai2-4

```
p[0] = f4, p[1] = f3, p[2] = f2, p[3] = f1
```

xの値は0xf1f2f3f4であるが、1byteずつメモリの中身を表示させると上記のように最下位バイトから若いアドレスに格納されている。
これはコンピュータがリトルエンディアンを採用しているからである。


### kadai2-5

```
p[0] = -12, p[1] = -13, p[2] = -14, p[3] = -15
```
printfには引数としてchar型を渡しているが、printfの引数は暗黙のうちにint型へと符号拡張される。
charポインタであるp[0]が指す値は0xf4だが、これをint型に符号拡張すると、0xfffffff4となり-12が表示されている。


### kadai2-6

```
char x: 0x104660000
int  y: 0x104660004
```

int型の変数であるyを4の倍数のアドレスに配置するため。


### kadai2-7
int型の場合

```
&p = 0x102418028
 p = 0x102418000 | &a[0] = 0x102418000
*p =           5 |  a[5] =           5 | *(a+5) =           5
 p = 0x102418014 | &a[5] = 0x102418014 |  (a+5) = 0x102418014
 ```

 &a[3]: 0x10241800c  


 short型の場合
 ```
&q = 0x1028f0048
 q = 0x1028f0028 | &b[0] = 0x1028f0028
*q =           5 |  b[5] =           5 | *(b+5) =           5
 q = 0x1028f0032 | &b[5] = 0x1028f0032 |  (b+5) = 0x1028f0032
 ```

 - &b[0]の値をvとすると、&b[n]の値はv+2nと表せる。
 - a[10]に書き込むと、宣言した配列の範囲外であるメモリに書き込みする。C言語によるチェックはなく、実行できてしまう。
 - sizeof(a):40 , sizeof(int):4 であり、配列の長さを計算している。
 - 関数の引数として渡されたa[]は配列の先頭へのポインタであり、要素数の情報は含まれない。init_array内のsizeof(a)はポインタのサイズを求めている。
										 

### kadai2-8
- `Hello`
- 文字列を指すポインタに対して`*`もしくは添字アクセスすることによりより、実態であるASCII値を取り出している。

### kadai2-9
```
   &x = 0x5598e8347010,    &y = 0x5598e8347014
 str1 = 0x5598e8347010,  str2 = 0x5598e8347014
&str1 = 0x5598e8347018, &str2 = 0x5598e8347020
str1: Hi!
str2: Finep4�U#
```
- x, y, str1, str2は連続してメモリ上に割り当てられた変数で、x, yは4byte、str1, str2はポインタ型で64bitである。&x, &y, &str1, &str2の結果からその間隔が確認できる。
- str1, str2はポインタはそれぞれx, yを指す。str1, str2の結果と&x, &yの結果が一致していることから確認できる。

### kadai2-10
```
sizeof(double) = 8, sizeof(bar) = 24
&bar = 0x55a0f3ab5020
&bar.a = 0x55a0f3ab5020
&bar.b = 0x55a0f3ab5024
&bar.c = 0x55a0f3ab5028
&bar.d = 0x55a0f3ab5030
```
- アライメント規約によりdouble型のdが8バイト境界に配置されるため、cのパディングが7byte取られている。

### kadai2-11
- アライメント規約によりパディングが取られると、その隙間の部分の値は0に初期化されるとは限らない。memcmp()を利用するとメンバ以外のパディングの部分も比較するため、正しい結果が得られない。

### kadai2-12
```
sizeof(double) = 8, sizeof(bar) = 14
&bar = 0x55a2f0fe1018
&bar.a = 0x55a2f0fe1018
&bar.b = 0x55a2f0fe1019
&bar.c = 0x55a2f0fe101d
&bar.d = 0x55a2f0fe101e
```
- パディング無くメンバが詰められるオプション。

### kadai2-13
```
char:      sizeof(char)=1,      alignof(char)=1
char:     sizeof(short)=2,     alignof(short)=2
char:       sizeof(int)=4,       alignof(int)=4
char:      sizeof(long)=8,      alignof(long)=8
char: sizeof(long long)=8, alignof(long long)=8
char:     sizeof(float)=4,     alignof(float)=4
char:    sizeof(double)=8,    alignof(double)=8
```

### kadai2-14
```
struct ColoredPoint {
	struct Point point;
	int color;
};
```
- ColoredPointでメンバとしてPointを持たせる
