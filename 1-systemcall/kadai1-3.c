#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
  // Exist->Error
  // Not exist-> Create with RDWR and rw-r--r--
  int err = open("foo.txt", O_CREAT | O_EXCL, 0644);
  if (err < 0) {
    fprintf(stderr, "err: open()\n");
    return -1;
  }
}
