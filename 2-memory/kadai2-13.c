#include <stdalign.h>
#include <stdio.h>

int main() {
  printf("char:      sizeof(char)=%zu,      alignof(char)=%zu\n", sizeof(char),
         alignof(char));
  printf("char:     sizeof(short)=%zu,     alignof(short)=%zu\n", sizeof(short),
         alignof(short));
  printf("char:       sizeof(int)=%zu,       alignof(int)=%zu\n", sizeof(int),
         alignof(int));
  printf("char:      sizeof(long)=%zu,      alignof(long)=%zu\n", sizeof(long),
         alignof(long));
  printf("char: sizeof(long long)=%zu, alignof(long long)=%zu\n",
         sizeof(long long), alignof(long long));
  printf("char:     sizeof(float)=%zu,     alignof(float)=%zu\n", sizeof(float),
         alignof(float));
  printf("char:    sizeof(double)=%zu,    alignof(double)=%zu\n",
         sizeof(double), alignof(double));
  return 0;
}
