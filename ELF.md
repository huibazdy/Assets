# ELF



```c
/*
 * SimpleSection.c
 * 参考《程序员的自我修养》3.3节
 */

#include <stdio.h>

int global_init_val = 1;
int global_uninit_val;

void func1(int i) {
    printf("%d\n",i);
}

int main()
{
    static int static_init_val = 8;
    static int static_uninit_val;
    
    int a = 1;
    int b;
    
    func1(static_init_val + static_uninit_val + a + b);
    
    return a;
}
```



用到的工具：

* gcc
* binutils
* objdump
* readelf