# pthread



> ***比较两个线程 ID 是否相同***

```c
#include <pthread.h>
int pthread_equal(pthread_t t1, pthread_t t2);  //相同返回非 0 数值，不同返回 0
```



> ***获取线程自身 ID***

```c
#include <pthread.h>
pthread_t pthread_self(void);
```

