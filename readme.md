日志库不使用 loguru, 在win10上无法编译. 使用google的glog. 

先实现一个单线程的内存分配. 

接下来要实现
- [x] free(包括大对象, 用map实现)
- [x] 多线程缓存
    在没有多线程的情况下, 就是线程为1的多线程特例. 
- [ ] 什么时候将内存还给操作系统?
- [ ] 内存碎片(率)的检测
- [ ] 重载 new 和 delete


关于多线程缓存.

如果用线程id作为唯一标识, 那么一个线程申请了空间, 然后过了一段时间线程销毁了, 我应该将这个资源还给全局吗? 

还是暂时保留, 因为id是会复用的. 但是暂时保留会带来的问题是, 如果那个线程id之后都没有再使用过, 怎么办?

或者第三种方式, 线程销毁的时候, 并不还给全局, 而是加入到一个等待队列中, 等到之后有新的线程的时候, 从这个列表中请求分配资源cache.

最开始的时候, 这个队列为空, 所以需要新建一个. 之后每次线程结束都将这个cache结构加入到等待队列. 
其他线程需要申请的时候, 先从这个队列中取, 如果取不到, 那么建立新的.
绑定的时候使用线程id进行绑定. 


突然想到一个办法, 那就是我并不需要给每个线程都绑定一个 cache, 给CPU绑定就可以了!
对于一个CPU核心, 在这个CPU上工作的线程是不可能发生并发执行的.

但是我觉得这样会损失局部性. 因为一个线程这次可能在cpu1上运行, 那次在cpu2上运行. 
切换之后, 之前在cpu1上的负载到cpu2上就不一样了, 就是另一种分配模式. 会造成一些性能的影响. 


cache与线程的生命周期. 