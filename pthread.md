# pthread



> ***比较两个线程 ID 是否相同***

---

```c
#include <pthread.h>
int pthread_equal(pthread_t t1, pthread_t t2);  //相同返回非 0 数值，不同返回 0
```



> ***获取线程自身 ID***

---

```c
#include <pthread.h>
pthread_t pthread_self(void);
```



> **创建线程**：将函数扔进某个线程来执行

---

* 创建者
* 线程属性
* 线程执行的函数
* 函数参数



```c
#include <pthread.h>
int pthread_create(pthread_t *restrict tidp,
                   const pthread_attr_t *restrict attr,
                   void *(*start_rtn)(void *),
                   void *restrict arg);
```

