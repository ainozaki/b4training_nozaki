### kadai1-1

```
double w: 0x102fc0000
double x: 0x102fc0008
float  y: 0x102fc0010
float  z: 0x102fc0014
```
double: 8byte
float: 4byte


### kadai1-2

```
x=10, *xp=10, y=20, *yp=20
x=10, *xp=30, y=30, *yp=30
```

`xp = yp;` よりint型のポインタxpの値はypの値と一致し、つまりポインタxpもポインタypもともにyへのポインタとなる。
`*yp=30;`よりyの値を変更したため、2回目のprintfではy自身、yを指すポインタxp, ypの指す値が変化した。


