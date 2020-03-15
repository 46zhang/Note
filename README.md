# Note
this repository is to record my study
## 📑 目录

* [➕ C/C++](#-cc)
* [⚡️ 算法](#️-算法)
* [💻 操作系统](#-操作系统)
* [☁️ 计算机网络](#️-计算机网络)
* [🌩 网络编程](#-网络编程)
* [〽️ 高性能服务器设计](#️-高性能服务器设计)


但是，总要有个建议的阈值吧，关于这个值。阮一峰在自己的博客中有过以下建议：

当系统负荷持续大于0.7，你必须开始调查了，问题出在哪里，防止情况恶化。

当系统负荷持续大于1.0，你必须动手寻找解决办法，把这个值降下来。

当系统负荷达到5.0，就表明你的系统有很严重的问题，长时间没有响应，或者接近死机了。你不应该让系统达到这个值。
以上指标都是基于单CPU的，但是现在很多电脑

但是，总要有个建议的阈值吧，关于这个值。阮一峰在自己的博客中有过以下建议：

当系统负荷持续大于0.7，你必须开始调查了，问题出在哪里，防止情况恶化。

当系统负荷持续大于1.0，你必须动手寻找解决办法，把这个值降下来。

当系统负荷达到5.0，就表明你的系统有很严重的问题，长时间没有响应，或者接近死机了。你不应该让系统达到这个值。
以上指标都是基于单CPU的，但是现在很多电脑
## ➕ C/C++   
### 智能指针的实现
````cpp
#include<iostream>
#include<mutex>


using namespace std;

/*  实现一个线程安全的智能指针 */


/* 引用计数基类 */
class Sp_counter
{
private :
    size_t *_count;
    std::mutex mt;
public :
    Sp_counter()
    {
        cout<<"父类构造,分配counter内存"<<endl;
        _count = new size_t(0);
    }
    virtual ~Sp_counter()
    {
        if(_count && !(*_count) ){
            cout<<"父类析构"<<endl;
            cout<<"[释放counter内存]"<<endl;
            delete _count;
            _count = NULL;
        }
    }
    Sp_counter &operator=(Sp_counter &spc)
    {
        cout<<"父类重载="<<endl;
        cout<<"[释放counter内存]"<<endl;
        delete _count;
        this->_count = spc._count;
        return *this;
    }
    Sp_counter &GetCounter()
    {
        return *this;
    }
    size_t Get_Reference()
    {
        return *_count;
    }
    virtual void Increase()
    {
        mt.lock();
        (*_count)++;
        //cout<<"_count++:"<<*_count<<endl;
        mt.unlock();
    }
    virtual void Decrease()
    {
        mt.lock();
        (*_count)--;
        //cout<<"_count--:"<<*_count<<endl;
        mt.unlock();
    }
};

template<typename T>
class smart_pointer : public Sp_counter
{
private :
    T *_ptr;
public :
    smart_pointer(T *ptr = NULL);
    ~smart_pointer();
    smart_pointer(smart_pointer<T> &);
    smart_pointer<T> &operator=(smart_pointer<T> &);
    T &operator*();
    T *operator->(void);
    size_t use_count();

};



template <typename T>
smart_pointer<T>::smart_pointer(T *ptr):
        _ptr(ptr)
{
    this->Increase();
    cout<<"构造完成"<<endl;
}
template <typename T>
smart_pointer<T>::~smart_pointer(){
    if(this->Get_Reference())
    {
        this->Decrease();
    }
    else{
        cout<<"析勾父类"<<endl;
        delete _ptr;
        _ptr=NULL;
    }
}

template<typename T>
smart_pointer<T>::smart_pointer(smart_pointer<T> &a) {
    if(this!=&a)
    {
        this->_ptr=a._ptr;
        this->GetCounter()=a.GetCounter();
        this->Increase();
    }

}
template<typename T>
smart_pointer<T>& smart_pointer<T>::operator=(smart_pointer<T> &sp) {
    if(this!=&sp)
    {
        //左边引用计数-1，右边引用技术+1
        this->Decrease();
        if(this->Get_Reference()==0)
            this->~smart_pointer();
    }
    sp.Increase();
    this->_ptr=sp._ptr;
    this->GetCounter()=sp.GetCounter();
}

template<typename T>
T& smart_pointer<T>::operator*() {
    return *_ptr;
}

template<typename T>
T* smart_pointer<T>::operator->() {
    return _ptr;
}

template<typename T>
inline size_t smart_pointer<T>::use_count()
{
    return this->Get_Reference();
}


int main()
{
    int *a = new int(10);
    int *b = new int(20);
    


    cout<<"===================end main===================="<<endl;
    return 0;
}
````
代码转载自 https://blog.csdn.net/gt1025814447/article/details/81217324
### 注意
1. 智能指针中shared_ptr的实现借助了一个计数器类，这个计数器类必须是对象共享对象，因为多个shared_ptr对象副本都是增减减少同一个引用计数器    
2. 如果在多线程环境下，引用技术的增加、减少必须是线程安全的，可以用原子操作，这里采用的是加锁，至于原子操作的版本等我研究后再进行更新
3. 这里采用了一种存在争议的做法，就是手动调用析勾函数，这相当于调用了一次普通的函数，但是在对象正式被析勾时会再调用一次析勾函数，然后释放栈的内存，销毁对象，手动调用析勾不会析勾栈上面的对象，此外，如果对象A是堆上面的对象，系统不会自动调用A的析勾函数，必须用delete A才会调用，只有栈上面的对象会自动调用析勾函数。
### 手动调用析勾函数
````cpp
class aaa
{
public:
    aaa(){p = new char[1024];} //申请堆内存
    ~aaa(){cout<<"deconstructor"<<endl; delete []p;}
    void disp(){cout<<"disp"<<endl;}
private:
    char *p;
};

void main()
{
aaa a;
a.~aaa();
a.disp(); //a is stack object so it will auto desory
aaa * b=new aaa();
b->~aaa(); // b is heap object ,will not auto desory
} 
````
在上述的例子中，因为a是栈上的对象，所以它在最后程序退出的时候会调用析勾函数，所以会俩次删除p，造成异常，而b是堆上的对象，堆上的对象不会自动调用析勾函数，所以b不存在问题，但是b对象并没有进行销毁，会造成b的内存泄露。

### 面向对象

- 面向对象：封装是基础，继承是手段，多态是目的。
- 泛型编程：参数化类型是基础，模板是手段，通用是目的。
- 面向对象的编程依赖运行时多态，泛型编程是编译时多态。

### STL

​	主要涉及六部分：容器、算法、分配器、适配器、迭代器、配置器

​	STL采用自己的Allocator分配内存，以内存池的方式来管理这些内存，会大大减少内存碎片，从而会提升系统的整体性能。

### Const关键字

用于修饰常量性，即不可修改，可修饰变量、引用、指针、函数、类

const可以用在对象需要保护的场所，有以下好处：

1. 避免被间接修改
2. 避免被误用为左值，例如函数返回值

```c++
string getString(string b)
	return  b;
//误用右值
if(getString(b)="afff")

//可以用const避免这种情况
    
const string getString(string b)
    return b;

//会报错
if(getString(b)="asff")

```

### Static关键字

3个作用：

1. 延长生命周期：当其修饰变量时，可以让变量存在的生命周期与程序同样 长
2. 限制函数范围：修饰函数时，可以限制其作用域仅在本文件
3. 共享内存或者方法：当方法被static修饰时，类中所有对象都可以访问该变量或者方法



   **不可以同时用const和static修饰成员函数。**

   C++编译器在实现const的成员函数的时候为了确保该函数不能修改类的实例的状态，会在函数中添加一个隐式的参数const this*。但当一个成员为static的时候，该函数是没有this指针的。也就是说此时const的用法和static是冲突的。

   我们也可以这样理解：两者的语意是矛盾的。**static的作用是表示该函数只作用在类型的静态变量上，与类的实例没有关系；而const的作用是确保函数不能修改类的实例的状态**，与类型的静态变量没有关系。因此不能同时用它们。

### inline

将函数体直接展开，省去函数调用的开销，inline只是建议，具体是否展开取决于编译器

编译器对inline函数展开的步骤：

1. 将inline函数体移动到inline函数调用处
2. 为Inline函数局部变量分配空间
3. 将inline函数的输入参数跟返回值映射到调用方法的局部变量空间
4. 如果 inline 函数有多个返回点，将其转变为 inline 函数代码块末尾的分支（使用 GOTO）

inline有2个好处跟3个缺点

1. 好处
   - 省去函数调用的开销
   - 编译器会对inline函数进行优化
2. 坏处
   - 过分使用inline会造成代码膨胀，降低指令缓冲器的击中率，造成系统性能下降
   - inline修改时，包含其头文件的都需要重新编译，无法降低编译依存性
   - inline函数无法使用断点调式

值得注意的是：程序员可以隐式或者显式生明inline函数，但是具体执行与否取决于编译器，inline函数一般不能修饰虚构函数，因为虚构函数会在运行时多态联编，而inline是编译期间展开，只有在虚函数不表现多态性时才可以用inline

### volatile

- volatile 关键字是一种类型修饰符，用它声明的类型变量表示可以被某些编译器未知的因素（操作系统、硬件、其它线程等）更改。所以使用 volatile 告诉编译器不应对这样的对象进行优化。
- volatile 关键字声明的变量，每次访问时都必须从内存中取出值（没有被 volatile 修饰的变量，可能由于编译器的优化，从 CPU 寄存器中取值）
- const 可以是 volatile （如只读的状态寄存器）
- 指针可以是 volatile

### strcu 与class

struct与class几乎一样，在描述数据结构上几乎可相互代替，但是其还是存在一点区别，就是默认的成员访问限制

1. struct默认的成员访问限制是private，class是public

### union 联合

联合（union）是一种节省空间的特殊的类，一个 union 可以有多个数据成员，但是在任意时刻只有一个数据成员可以有值。当某个成员被赋值后其他成员变为未定义状态。联合有如下特点：

- 默认访问控制符为 public
- 可以含有构造函数、析构函数
- 不能含有引用类型的成员
- 不能继承自其他类，不能作为基类
- 不能含有虚函数
- 匿名 union 在定义所在作用域可直接访问 union 成员
- 匿名 union 不能包含 protected 成员或 private 成员
- 全局匿名联合必须是静态（static）的

匿名联合的作用：

1.共享内存

2.自动类型转换

```c++
/*匿名联合的另一个用途是：自动类型转换（自动类型转换是不安全的）。例如：当要把一个指针看作十进制数时，你可以如下面的联合一样声明。*/
int some_val;

union

{

void *p;

int n;

};

p = &some_val;

//现在没有必要把指针显式的转为int类型的：

std::cout << ”address of p is:” << n << std::endl;
```

### :: 范围解析运算符

分类

1. 全局作用域符（`::name`）：用于类型名称（类、类成员、成员函数、变量等）前，表示作用域为全局命名空间
2. 类作用域符（`class::name`）：用于表示指定类型的作用域范围是具体某个类的
3. 命名空间作用域符（`namespace::name`）:用于表示指定类型的作用域范围是具体某个命名空间的

### 多态

- 多态，即多种状态（形态）。简单来说，我们可以将多态定义为消息以多种形式显示的能力。
- 多态是以封装和继承为基础的。
- C++ 多态分类及实现：
  1. 重载多态（Ad-hoc Polymorphism，编译期）：函数重载、运算符重载
  2. 子类型多态（Subtype Polymorphism，运行期）：虚函数
  3. 参数多态性（Parametric Polymorphism，编译期）：类模板、函数模板
  4. 强制多态（Coercion Polymorphism，编译期/运行期）：基本类型转换、自定义类型转换

## Python

### 面向切面编程AOP

就是代码只要考虑主要的逻辑,将一些通用的功能性任务交付给其他类去完成，**把和主业务无关的事情，放到代码外面去做。**，例如验证一个用户是否有权限访问这一功能就可以交由一个代理类去完成。

AOP可以用一个代理类来实现，可以是动态代理(运行时代理)也可以是静态代理(自己写的类)

AOP的好处：**对原有代码毫无入侵性**，将一些功能通用，代码重复的函数进行复用，减少代码的重复

### Python中的重载

函数重载主要是为了解决两个问题。

1. 可变参数类型。
2. 可变参数个数。

对于情况1，python可以接受任何类型的参数，所以无需重载，对于情况2，python可以用缺省参数接受多个 参数，因此python不需要函数重载

### 新式类与旧式类

python3的类都是新式类,新式类继承object类，其内置了许多常见的基本魔术方法,不单是这个不同，其多重继承的机制也不同，新式类继承是根据C3算法,旧式类是深度优先

```python
#新式类
class C(object):
    pass
#经典类
class B:
    pass

#在python2运行旧式类
class A():
    def foo1(self):
        print "A"
class B(A):
    def foo2(self):
        pass
class C(A):
    def foo1(self):
        print "C"
class D(B, C):
    pass

d = D()
d.foo1()


#结果是输出'A'
"""
按照经典类的查找顺序从左到右深度优先的规则，在访问d.foo1()的时候,D这个类是没有的..那么往上查找,先找到B,里面没有,深度优先,访问A,找到了foo1(),所以这时候调用的是A的foo1()，从而导致C重写的foo1()被绕过
"""
```

### 为什么采用C3算法

C3算法最早被提出是用于Lisp的，应用在Python中是为了解决原来基于深度优先搜索算法不满足本地优先级，和单调性的问题。
 本地优先级：指声明时父类的顺序，比如C(A,B)，如果访问C类对象属性时，应该根据声明顺序，优先查找A类，然后再查找B类。

```python
class A(O):pass
class B(O):pass
class C(O):pass
class E(A,B):pass
class F(B,C):pass
class G(E,F):pass

mro(F) = [F] + merge(mro(B), mro(C), [B,C])
           = [F] + merge([B,O], [C,O], [B,C])
           = [F,B] + merge([O], [C,O], [C])
           = [F,B,C] + merge([O], [O])
           = [F,B,C,O]

mro(G) = [G] + merge(mro[E], mro[F], [E,F])
           = [G] + merge([E,A,B,O], [F,B,C,O], [E,F])
           = [G,E] + merge([A,B,O], [F,B,C,O], [F])
           = [G,E,A] + merge([B,O], [F,B,C,O], [F])
           = [G,E,A,F] + merge([B,O], [B,C,O])
           = [G,E,A,F,B] + merge([O], [C,O])
           = [G,E,A,F,B,C] + merge([O], [O])
           = [G,E,A,F,B,C,O]
```

### init与new的区别

```python
"""
真正创建对象的是__new__方法，__init__只是完成初始化工作
"""

class Person(object):
    def __new__(cls, *args, **kwargs):
        print("in __new__")
        instance = object.__new__(cls, *args, **kwargs)
        return instance

    def __init__(self, name, age):
        print("in __init__")
        self._name = name
        self._age = age

p = Person("Wang", 33)

"""
用__new__实现singleton模式
"""


class singleton(object):
    def __new__(cls,*args, **kwargs):
        if not hasattr(cls, '_instance'):
            orig = super(Singleton, cls)
            cls._instance = orig.__new__(cls, *args, **kw)
        return cls._instance
        

```

### Pyhton2 和Python3的差异

1. print函数
2. 整除  python2:   3/2=1,3/2.0=1.5
3. Unicode
4. xrange range不同

### is与==

is比较的是地址，==比较的值

### GIL线程全局锁

线程全局锁(Global Interpreter Lock),即Python为了保证线程安全而采取的独立线程运行的限制,说白了就是一个核只能在同一时间运行一个线程.**对于io密集型任务，python的多线程起到作用，但对于cpu密集型任务，python的多线程几乎占不到任何优势，还有可能因为争夺资源而变慢。**

### Python垃圾回收机制

**python采用的是引用计数机制为主，标记-清除和分代收集两种机制为辅的策略**

Python GC主要使用引用计数（reference counting）来跟踪和回收垃圾。在引用计数的基础上，通过“标记-清除”（mark and sweep）解决容器对象可能产生的循环引用问题，通过“分代回收”（generation collection）以空间换时间的方法提高垃圾回收效率。

### 检查内存泄露的工具:valgrind

algrind [valgrind-options] [your-program] [your-program-options]

valgrind的底层模拟了一个核心，即一个软件模拟的CPU，被调试的程序就是运行在这个假核心上，此外还包含一系列调试工具。它的工具运行依赖于底层的核心，由于是模块化架构，工具可单独开发，只要与核心的版本匹配即可。它的默认工具是memcheck，通过--tool=<toolname>来指定运行的工具。

****

valgrind指令
valgrind --tool=memcheck --leak-check=full ./test
-h –help 显示帮助信息。（除了以下参数，可用帮助-h查看更多信息）    
​    --version 显示valgrind内核的版本，每个工具都有各自的版本。    
​    -q –quiet 安静地运行，只打印错误信息。    
​    -v –verbose 更详细的信息, 增加错误数统计。    
​    --trace-children=no|yes 跟踪子线程? [no]    
​    --track-fds=no|yes 跟踪打开的文件描述？[no]    
​    --time-stamp=no|yes 增加时间戳到LOG信息? [no]    
​    --log-fd=<number> 输出LOG到描述符文件 [2=stderr]    
​    --log-file=<file> 将输出的信息写入到filename.PID的文件里，PID是运行程序的进行ID    
​    --log-file-exactly=<file> 输出LOG信息到 file     
​    --log-file-qualifier=<VAR> 取得环境变量的值来做为输出信息的文件名。 [none]    
​    --log-socket=ipaddr:port 输出LOG到socket ，ipaddr:port    
--xml=yes 将信息以xml格式输出，只有memcheck可用    
​    --num-callers=<number> show <number> callers in stack traces [12]    
​    --error-limit=no|yes 如果太多错误，则停止显示新错误? [yes]   
​    --error-exitcode=<number> 如果发现错误则返回错误代码 [0=disable]   
​    --db-attach=no|yes 当出现错误，valgrind会自动启动调试器gdb。[no]   
​    --db-command=<command> 启动调试器的命令行选项[gdb -nw %f %p]    

​    
适用于Memcheck工具的相关选项
--leak-check=no|summary|full 要求对leak给出详细信息? [summary]
​    --leak-resolution=low|med|high how much bt merging in leak check [low]
​    --show-reachable=no|yes show reachable blocks in leak check? [no]




    ==3185== Use of uninitialised value of size 8
    ==3185== at 0x108602: main (a.c:6)
这种情况是很常见的, 原因是使用了未初始化的的地址, 这时候应该查看一下程序是否使用了未初始化的指针


    ==3223== Invalid write of size 4
    ==3223== at 0x108602: main (a.c:6)8
    ==3223== Address 0x0 is not stack’d, malloc’d or (recently) free’d

这个错误原因是往错误的地址写入值, 这时候我们也应该查看一下程序用未初始化的指针赋值, 或者指针未被赋值.
和这个错误相对应的, 还有Invalid read of size 4错误提示.




    ==3397== Conditional jump or move depends on uninitialised value(s)
    ==3397== at 0x108656: main (in /home/ciaiy/Desktop/codingSpace/c/free/a)

这个错误原因是变量未被初始化, 就被使用




    ==3886== Invalid free() / delete / delete[] / realloc()
    ==3886== at 0x4C2CE1B: free (vg_replace_malloc.c:530)
    ==3886== by 0x1086CD: main (a.c:10)

这个错误原因是free掉了不属于自己的空间, 错误原因有可能是指针指向的内存不再属于它了



    ==3839== HEAP SUMMARY:
    ==3839== in use at exit: 412 bytes in 1 blocks
    ==3839== total heap usage: 2 allocs, 1 frees, 924 bytes allocated

最后一个是堆内存分析, 如上面的提示所示, 程序在退出时, 仍有412字节的空间未被free


更多valgrind错误分析可看博客https://blog.csdn.net/ciaiy/article/details/81276155

## ☁️ 计算机网络  
### TCP
#### 建立连接

TCP建立连接是三次握手，以客户端主动建立连接例

(1). 第一次握手(SYN=1,Ack(标志位)=0，ACK(确认号)=0, seq=x)

client发送SYN数据段，进入SYN_SEND状态

![](G:\个人总结\面经\章世楠的面经\照片\tcp数据帧.jpg)

(2).第二次握手(SYN=K,Ack(标志位)=1,ACK(确认号)=j+1,seq=y)

服务器必须确认客户A的SYN（ACK=j+1），同时自己也发送一个SYN包（SYN=k），即SYN+ACK包，服务器端选择自己 ISN 序列号，放到 Seq 域里此时服务器B进入SYN_RECV状态

![](G:\个人总结\面经\章世楠的面经\照片\tcp第二次握手数据帧.jpg)

(3). 第三次握手(ACK=K+1)

客户端再次发送确认包(ACK)SYN标志位为0,ACK标志位为1.并且把服务器发来ACK的序号字段+1,放在确定字段中发送给对方.并且在数据段放写ISN的+1，发送最后一次ACK，客户端进入ESTABLISHED状态， 服务器接受到ACK进入ESTABLISHED状态 

![](G:\个人总结\面经\章世楠的面经\照片\tcp第三次握手数据帧.jpg)

TCP断开连接采用的是四次握手，以客户端主动断开连接为例子

(1). 客户端发送FIN，进入FIN_WAIT1状态

(2). 服务器接受FIN,关闭读通道进入CLOSED_WAIT状态，然后发送ACK确认接受FIN

(3). 客户端接受到ACK开始关闭写通道，进入FIN_WAIT2状态,然后服务器发送FIN字段，进入LAST状态

(4). 客户端接受FIN字段，关闭读通道，进入TIME_WAIT状态，发送ACK字段，服务器接受ACK字段关闭写通道，进入CLOASED状态

如果服务器是端口不可达，也就是可以访问到该主机，但是端口没有listen，此时返回RST复位报文段，如果主机不可达，也就是该由于器不存在该端口的缓存，或在是某一条链路断开，此时返回ICMP主机不可达报文端。
1. connect出错：

(1) 若TCP客户端没有收到syn分节的响应，则返回ETIMEOUT错误；调用connect函数时，内核发送一个syn，若无响应则等待2s后再发送一个，若仍然无响应则等待4s后在发送一个，连续发送7次，1 2 4 6 8 16 32 64，若仍未收到响应则，交给底层IP ARP协议去完成，返回本错误；     

(2) 若对客户的syn响应是rst，则表明该服务器在我们指定的端口上没有进程在等待与之连接，这是一种硬错误，客户一收到rst马上返回ECONNREFUSED错误；        

(3) 若客户发送的syn在中间的某个路由器上引发了目的不可达icmp错误，则认为是一种软错误。客户主机内核保存该消息，并按照第一种情况的时间间隔继续发送syn，咋某个规定时间后仍未收到响应，则把保存的消息作为EHOSTUNREACH或者ENETUNREACH错误返回给进程，在我测试的环境下当收到2个ICMP不可达报文时，通常就会确认为无法连接进行断开；      

#### 发送数据
##### 丢包问题
TCP是基于不可靠的网络实现可靠的传输，肯定也会存在掉包的情况，如果通信中发现缺少数据或者丢包，那么，最大的可能在于程序发送的过程或者接收的过程出现问题。    

        例如服务端要给客户端发送大量数据，Send频率很高，那么就很有可能在Send环节出现错误（1.程序处理逻辑错误，2.多线程同步问题，3.缓冲区溢出等），如果没有对Send发送失败做处理，那么客户端收到的数据比理论要收到的数据少，就会造成丢数据，丢包现象。

常用的解决方法有：拆包，加包头，发送组合包
粘包问题的解决策略    
由于底层的TCP无法理解上层的业务逻辑，所以在底层是无法确保数据包不被拆分和重组的，这个问题只能通过上层的应用协议栈设计来解决，根据业界的主流协议的解决方案，归纳如下：      

    1.消息定长，例如每个报文的大小为固定长度200字节,如果不够，空位补空格；
    2.在包尾增加回车换行符进行分割，例如FTP协议；
    3.将消息分为消息头和消息体，消息头中包含表示消息总长度（或者消息体长度）的字段，通常设计思路是消息头的第一个字段用int来表示消息的总长度；（我之前linux C开发，就用的这种）。
    4.更复杂的应用层协议；

 

原文链接：https://blog.csdn.net/q764424567/article/details/78034622     
#### TCP可靠传输的设计
1. 超时重传：tcp设计了超时记时器，如果数据没有收到期待的响应则会重复数据包    
2. 接受确认：tcp采用累加确认的方法，每个数据包都有一个序号x，接受方要发送x+1的序号或在是当发送多个数据时y时，返回x+y+1的确认    
3. 滑动窗口协议：用来告知对方的接受窗口容量，用于控制流量    
4. 数据分片：发送端对数据进行分片，接受端要对数据进行重组，由TCP确定分片的大小并控制分片和重组    
5. 失序处理：作为IP数据报来传输的TCP分片到达时可能会失序，TCP将对收到的数据进行重新排序，将收到的数据以正确的顺序交给应用层    
6. 数据校验：TCP将保持它首部和数据的检验和，这是一个端到端的检验和，目的是检测数据在传输过程中的任何变化。如果收到分片的检验或有差错，TCP将丢弃这个分片，并不确认收到此报文段导致对端超时并重发    


### Linux抓包工具TCPDUMP
tcpdump采用命令行方式，它的命令格式为：

　　tcpdump [ -adeflnNOpqStvx ] [ -c 数量 ] [ -F 文件名 ]

　　　　　　　　　　[ -i 网络接口 ] [ -r 文件名] [ -s snaplen ]

                                       [ -T 类型 ] [ -w 文件名 ] [表达式 ]
 tcpdump的选项介绍

　　　-a 　　　将网络地址和广播地址转变成名字；

　　　-d 　　　将匹配信息包的代码以人们能够理解的汇编格式给出；

　　　-dd 　　　将匹配信息包的代码以c语言程序段的格式给出；

　　　-ddd 　　　将匹配信息包的代码以十进制的形式给出；

　　　-e 　　　在输出行打印出数据链路层的头部信息，包括源mac和目的mac，以及网络层的协议；

　　　-f 　　　将外部的Internet地址以数字的形式打印出来；

　　　-l 　　　使标准输出变为缓冲行形式；

　　　-n 　　　指定将每个监听到数据包中的域名转换成IP地址后显示，不把网络地址转换成名字；

           -nn：    指定将每个监听到的数据包中的域名转换成IP、端口从应用名称转换成端口号后显示

　　　-t 　　　在输出的每一行不打印时间戳；

　　　-v 　　　输出一个稍微详细的信息，例如在ip包中可以包括ttl和服务类型的信息；

　　　-vv 　　　输出详细的报文信息；

　　　-c 　　　在收到指定的包的数目后，tcpdump就会停止；

　　　-F 　　　从指定的文件中读取表达式,忽略其它的表达式；

　　　-i 　　　指定监听的网络接口；

      -p：    将网卡设置为非混杂模式，不能与host或broadcast一起使用

　　　-r 　　　从指定的文件中读取包(这些包一般通过-w选项产生)；

　　　-w 　　　直接将包写入文件中，并不分析和打印出来；

            -s snaplen         snaplen表示从一个包中截取的字节数。0表示包不截断，抓完整的数据包。默认的话 tcpdump 只显示部分数据包,默认68字节。

　　　-T 　　　将监听到的包直接解释为指定的类型的报文，常见的类型有rpc （远程过程调用）和snmp（简单网络管理协议；）

          -X            告诉tcpdump命令，需要把协议头和包内容都原原本本的显示出来（tcpdump会以16进制和ASCII的形式显示），这在进行协议分析时是绝对的利器。


1)只想查目标机器端口是21或80的网络包，其他端口的我不关注：    

　　sudo tcpdump -i eth0 -c 10 'dst port 21 or dst port 80'   

(2) 想要截获主机172.16.0.11 和主机210.45.123.249或 210.45.123.248的通信，使用命令(注意括号的使用)：   

　　sudo tcpdump -i eth0 -c 3 'host 172.16.0.11 and (210.45.123.249 or210.45.123.248)'    

(3)想获取使用ftp端口和ftp数据端口的网络包   

   sudo tcpdump 'port ftp or ftp-data'   

   这里 ftp、ftp-data到底对应哪个端口？ linux系统下 /etc/services这个文件里面，就存储着所有知名服务和传输层端口的对应关系。如果你直接把/etc/services里   

   的ftp对应的端口值从21改为了3333，那么tcpdump就会去抓端口含有3333的网络包了。    

(4) 如果想要获取主机172.16.0.11除了和主机210.45.123.249之外所有主机通信的ip包，使用命令：   

 sudo tcpdump ip ‘host 172.16.0.11 and ! 210.45.123.249’    

(5) 抓172.16.0.11的80端口和110和25以外的其他端口的包   

sudo tcpdump -i eth0 ‘host 172.16.0.11 and! port 80 and ! port 25 and ! port 110’   





## 💻 操作系统


### 进程与线程

​	进程是资源分配的基本单位

​	线程是独立调度的基本单位，多个线程可以共享一个进程的资源

区别：

1. 线程是独立调度的基本单位，在同一进程中，线程的切换不会引起进程切换，从一个进程中的线程切换到另一个进程中的线程时，会引起进程切换。
2. 线程不拥有资源，但是可以访问其隶属进程的资源
3. 在创建撤销进程时，系统需要为之分配或回收资源，如内存空间、I/O 设备等，所以其创建、撤销的系统开销比线程大，在进行进程切换时，涉及当前执行进程 CPU 环境的保存及新调度进程 CPU 环境的设置，而线程切换时只需保存和设置少量寄存器内容，开销很小。



   **进程之间私有和共享的资源**

- 私有：地址空间、堆、全局变量、栈、寄存器
- 共享：代码段，公共数据，进程目录，进程 ID

   **线程之间私有和共享的资源**

- 私有：线程栈，寄存器，程序计数器
- 共享：堆，地址空间，全局变量，静态变量

### 管程



### 进程同步

- 同步：多个进程因为合作产生的直接制约关系，使得进程有一定的先后执行关系。
- 互斥：多个进程在同一时刻只有一个进程能进入临界区。

可以通过信号量或者其他IPC实现进程同步

### 进程通信

进程同步与进程通信很容易混淆，它们的区别在于：

- 进程同步：控制多个进程按一定顺序执行；
- 进程通信：进程间传输信息。

进程通信是一种手段，而进程同步是一种目的。也可以说，为了能够达到进程同步的目的，需要让进程进行通信，传输一些进程同步所需要的信息。

1. 管道：管道是通过调用 pipe 函数创建的，fd[0] 用于读，fd[1] 用于写，管道有以下几个限制

   - 只能用户父子进程或者兄弟进程
   - 只支持半双工通信（单向交替传输）；

   ![](G:\个人总结\面经\章世楠的面经\照片\管道通信.png)

2. FIFO：也称为命名管道，去除了管道只能在父子进程中使用的限制。FIFO 常用于客户-服务器应用程序中，FIFO 用作汇聚点，在客户进程和服务器进程之间传递数据。

   ![](G:\个人总结\面经\章世楠的面经\照片\FIFO.png)

3. 信号量：它是一个计数器，用于为多个进程提供对共享数据对象的访问。

4. 消息队列：消息队列可以独立于读写进程存在

5. socket：扩展性好，可靠性强，存在以下优点：

   - 可拓展到多个机器
   - TCP是可靠通信，保证了数据的可靠传输

### 线程通信

线程间的通信方式主要是用于同步或者互斥访问临界区，不需要向进程一样进行数据交换。

1. 锁机制：

   - 互斥锁：通过互斥锁来实现线程安全，互斥地访问临界资源，互斥锁又分为俩种，可重入锁跟不可重入锁，不可重复锁在对用一个锁再次上锁时会造成死锁，不可重入锁允许多次对该锁上锁，所以在对某个临界资源上锁后可能存在其他线程访问并修改它的情况，造成程序崩溃，相比起可重入锁，不可重入锁更加容易及时发现跟解决问题。
   - 读写锁：适用于读者-写者问题，允许同时读，但是对于写线程是互斥的，读锁是可重入，死锁不可重入，为了防止写进程饥饿，写锁会阻塞后来的读锁，因此reader lock 在重入的时候可能死锁。写锁阻塞读锁的做法也不适用于追求低延迟读取的场景。

   2.条件变量：条件变量是用来等待而不是用来上锁的。条件变量用来自动阻塞一个线程，直到某特殊情况发生为止。通常条件变量和互斥锁同时使用。

   - 假唤醒：由系统原因造成，inux的phread_cond_wait是futex系统调用，是慢速系统调用，



## 内存管理

### 程序链接

程序经过编译器编译之后，可以通过链接器，将可重定位的文件经过链接成一个可执行的目标文件。程序链接使得不同的模块文件可以分开编写，分开编译。

### 程序链接的步骤

程序链接主要是符号解析跟符号重定位俩个步骤，每个文件都有一个符号表，记录三种该文件的符号，主要有3种：

1. 文件本身定义的可供其他文件使用的符号，非static函数跟全局变量
2. 系统本身没定义的，引用其他文件的符号，如extern声明的变量等
3. 系统本身定义，其他文件无法看到的，如局部变量,static函数

在编译时，编译器会将符号写入符号表，如果文件的定义跟使用都在同一个文件，那么就直接写入该符号的地址即可，如果符号是引用其他文件的，那么编译器就写上一个条目，告诉链接器该符号的定义在其他文件，链接器如果在其他文件找不到该符号的定义就会发送错误报告并终止该程序的链接。

程序解析符号表后会将各个模块的文件聚合在一起，给各个符号分配运行时内存。

### 静态链接、动态链接、装入时动态链接的区别

静态链接是在链接时一次性将所有的链接文件进行链接，完成各种符号的内存分配，链接完成后，当某个链接文件发生更改，不会影响该程序的运行，因为已经链接完成了，比较占用内存，因为要一次全部装完。

动态链接是程序一开始不链接完成所有文件，而是等到运行时需要用到这一部分的符号再去链接，所以如果在运行期间存在链接文件修改的情况，可能会发生错误，动态链接运行速度会比较慢，因为边运行边链接。

装入时动态链接是程序在装入时，一边装入一边链接

### 程序的装入

程序的编译让程序变为二进制代码，链接将分离的多个模块聚合链接成一个可执行文件，此时已经分配好逻辑空间，但是并没有实际的内存物理空间。只有在装入时，程序才会将逻辑地址映射成物理地址。

装入分配3种

1. 绝对装入：在装入内存的时候写入的地址是绝对地址
2. 动态装入：链接完成的都是逻辑地址，通过地址变换将逻辑地址映射成物理地址

### 操作系统有几种内存分配方式

1. 连续内存分配：固定分区分配、可变式分区分配
   - 内存分配的方法：最佳适应算法、首次适应算法、最坏适应算法
2. 基本分页系统
3. 基本分段系统
4. 段页式系统

2 3 4都是非连续的内存分配方式

### 讲一下内存的碎片化

内存的碎片化主要分为俩种：外部碎片化跟内部碎片化

1. 外部碎片化：在基本分页系统中，以每页1Kb为例子，如果你先申请了20页(0-19页被申请)，然后在申请4页（20-23被申请），当你用完20页后释放，此时(20-23被占用，0-19被释放），当有人申请一个30页的时候只能从24开始申请，0-19的内存无法使用，造成内存的一个碎片化
2. 内部碎片化：假设系统1页1kb，我现在一个程序只需要100b，也是分配1页，那么造成900b的内存浪费，这就是内部的碎片化

### 怎么解决

内存的外部碎片化可以采用伙伴算法，linux采用该算法来避免内存的外部碎片化，内部碎片化可以采用slab分配器

### 伙伴算法

伙伴算法的思想就是内存中有11组链表，每个链表存放的是内存大小相等的内存块，每组链表元素的内存大小依次递增，例如第一组链表包含所有内存为1个页框大小的内存块，第二组内存是2个页框大小，第三组内存为4个页框大小，第11组内存为1024个页框大小，一个页框一般是4kb，所以最大可以分配一块4MB的内存。

在进行内存分配的时候，例如要申请一块32个页框大小的内存，先去32的链表组里面找，如果找到了，就直接分配，如果找不到则去64页框内存的那个链表去找，如果找到，则64分为2块，一块用以程序使用，一块加入到页框大小为32的链表。

内存的释放相当于一个逆过程，加入到32的链表里面，然后判断是否存在伙伴，如果有则合并成一个内存块，加入到64的链表中，然后再判断64的链表里面是否有伙伴，有的继续合并。

这里伙伴必须满足3个条件，缺一不可：

1. 内存大小相等
2. 物理地址连续
3. 假设该块的内存页框大小为b,第一块内存的起始地址必须是2 * b * 4kb的整数倍，也即是说在内存框大小为32的链表中，0与1是伙伴，2-3是伙伴，但是1-2不是伙伴，因为1的地址为 1 * 32 * 4kb不是整数倍

### slab分配器

![](G:\个人总结\面经\章世楠的面经\照片\slab.png)

伙伴算法只能解决内存的外部锁片化，内存的内部碎片化得用slab分配器

​	在linux内核中伙伴系统用来管理物理内存，其分配的单位是页，但是向用户程序一样，内核也需要动态分配内存，而伙伴系统分配的粒度又太大。由于内核无法借助标准的C库，因而需要别的手段来实现内核中动态内存的分配管理，linux采用的是slab分配器。slab分配器不仅可以提供动态内存的管理功能，而且可以作为经常分配并释放的内存的缓存。通过slab缓存，内核能够储备一些对象，供后续使用。需要注意的是slab分配器只管理内核的常规地址空间（准确的说是直接被映射到内核地址空间的那部分内存包括ZONE_NORMAL和ZONE_DMA）。

​	slab分配器预先从body system中申请一大块连续的内存，然后中分配成小的、固定大小的内存块，当需要时，直接进行分配，不需要再向系统申请，用完内存后不进行释放，而是返回到原来的slab链表中。

​	为了提升效率，SLAB分配器为每一个CPU都提供了对应各个CPU的数据结构struct array_cache，该结构指向被释放的对象。当CPU需要使用申请某一个对象的内存空间时，会先检查array_cache中是否有空闲的对象，如果有的话就直接使用。如果没有空闲对象，就像SLAB分配器进行申请。
​	slab分配器有俩种类型，一种是通用slab，用来分配小内存，一种是专用的slab为特定的对象分配内存，例如tcp,cpu等。

slab有几个优点：‘

1. 预先分配内存，以空间换时间提高运行效率，省去申请、初始化、释放的系统开销
2. 分配的内存比较小，解决了内部碎片化问题

slab适用的场所：

1. 频繁申请跟释放内存
2. 内存块固定大小，且比较小，小于或者等于一页

每个缓存都包含了一个 **slabs** 列表，这是一段连续的内存块（通常都是页面）。存在 3 种 slab：

- **slabs_full**

  完全分配的 slab

- **slabs_partial**

  部分分配的 slab

- **slabs_empty**

  空 slab，或者没有对象被分配

  刚开始创建kmem_cache完成后，这三个链表都为空，只有在申请对象时发现没有可用的slab时才会创建一个新的SLAB，并加入到这三个链表中的一个中。也就是说kmem_cache中的SLAB数量是动态变化的，当SLAB数量太多时，kmem_cache会将一些SLAB释放回页框分配器中。

  ![](G:\个人总结\面经\章世楠的面经\照片\slab分配器的数据结构总结.jpg)

### 关于SLAB着色

​	slab着色就是希望通过的偏移量提高cache的击中率。

​	SLAB着色就是在同一个kmem_cache中对不同的SLAB添加一个偏移量，就让相同对象号的对象不会对齐，也就不会放入硬件高速缓存的同一行中，提高了效率。假设cpu的缓存一行为32字节,cpu包含 512 个缓存行（缓存大小16K ）。
​     假设对象 A,B均为32字节，且 A 的地址从 0 开始， B 的地址从 16K 开始，则根据组相联或直接相联映射方式（全相联方式很少使用）， A,B 对象很可能映射到缓存的第0行，此时，如果CPU 交替的访问 A,B 各 50 次，每一次访问 缓存的第 0 行都失效，从而需要从内存传送数据。而 slab 着色就是为解决该问题产生的，不同的颜色代表了不同的起始对象偏移量，对于 B 对象，如果将其位置偏移向右偏移 32字节 ，则其可能会被映射到 cache 的第 1 行上，这样交替的访问 A,B 各 50 次，只需要 2 次内存访问即可。
   这里的偏移量就代表了 slab 着色中的一种颜色，不同的颜色代表了不同的偏移量，尽量使得不同的对象的对应到不同的硬件高速缓存行上，以最大限度的提高效率。实际的情况比上面的例子要复杂得多， slab 的着色还要考虑内存对齐等因素，以及 slab内未用字节的大小，只有当未用字节数足够大时，着色才起作用。

### 思考的问题

为什么Linux内存管理要用到slab分配器？

它能解决什么问题？

它的核心思想是什么？

- 使用对象的概念来管理内存
- 以空间换时间，预先申请内存、用完不释放内存，直接回收等待下次使用

它的最小分配单元是多大？最大分配单元又是多少？

- 最小的是32KB，最大分配单元依赖体系架构。

它是否依赖buddy系统？或者和buddy系统有啥关系？

它有什么优点？又有什么缺点？

- slab系统的缺点也是存在的，有以下几点：

  1). 缓存队列管理复杂；2). 管理数据存储开销大；3). 对NUMA支持复杂；4). 调试调优困难

为什么要着色？着色有什么好处？又有什么不好的地方？

### 高速缓存

高速缓存又分成两种类型：普通的和专用的。普通高速缓存是slab用于自己目的的缓存，比方kmem_cache就是slab用来分配其余高速缓存描述符的，再比如上面讲到的kmalloc对应的缓存。而专用缓存是内核其它地方用到的缓存。普通缓存调用kmem_cache_init接口来初始化，其中cache_cache保存着第一个缓存描述符。专用缓存调用的是kmem_cache_create接口来创建。

### 虚拟存储器

我们先来分析一下如果所有的进程直接访问同一块连续的物理地址有什么弊端呢？

1. 主存的容量有限。虽然我们现在的主存容量在不断上升，4G，8G，16G的主存都出现在市面上。但是我们的进程是无限，如果计算机上的每一个进程都独占一块物理存储器(即物理地址空间)。那么，主存就会很快被用完。但是，实际上，每个进程在不同的时刻都是只会用同一块主存的数

但是，总要有个建议的阈值吧，关于这个值。阮一峰在自己的博客中有过以下建议：

当系统负荷持续大于0.7，你必须开始调查了，问题出在哪里，防止情况恶化。

当系统负荷持续大于1.0，你必须动手寻找解决办法，把这个值降下来。

当系统负荷达到5.0，就表明你的系统有很严重的问题，长时间没有响应，或者接近死机了。你不应该让系统达到这个值。
以上指标都是基于单CPU的，但是现在很多电脑据，这就说明了其实只要在进程想要主存数据的时候我们把需要的主存加载上就好，换进换出。针对这样的需求，直接提供一整块主存的物理地址就明显不符合。
2. 进程间通信的需求。如果每个进程都 独占一块物理地址，这样就只能通过socket这样的手段进行进程通信，但如果进程间能使用同一块物理地址就可以解决这个问题。
3. 主存的保护问题。对于主存来说，需要说明这段内存是可读的，可写的，还是可执行的。针对这点，光用物理地址也是很难做到的。
   针对物理地址的直接映射的许多弊端，计算机的设计中就采取了一个虚拟化设计，就是虚拟内存。CPU通过发出虚拟地址，虚拟地址再通过MMU翻译成物理地址，最后获得数据。

![](G:\个人总结\面经\章世楠的面经\照片\虚拟内存.jpg)

​	虚拟内存是计算机系统管理内存的一种技术，它通过虚拟的逻辑地址，使得应用似乎在使用一大块连续的内存空间，虚拟内存不只是“用磁盘空间来扩展物理内存”的意思，而是指将主存以及外存的地址与虚拟地址进行映射，对用户来说好像是一整块连续的内存空间，但是实际上背后隐藏着很多的技术细节来实现这种虚拟。

​	虚拟内存技术实际上就是建立了 “内存一外存”的两级存储器的结构，利用局部性原理实现髙速缓存。 

​	实现：

1. 地址变换结构：需要虚拟地址与真实物理的地址的映射
2. 缺页中断机制：当内存不够时，需要有一个缺页中断处理
3. 页面置换函数：对页面进行换入换出，当发生缺页中断时，需要进行页面置换

## 〽️ 高性能服务器设计
高性能是每个后端开发工程师所追求的目标，要想设计一个高性能的服务器，然后我们就需要知道高性能服务器的指标，怎样才算高性能？影响服务器性能有哪些因素？如何去进行测试？

### 高性能服务器指标
平常的工作中，在衡量服务器的性能时，经常会涉及到几个指标，load、cpu、mem、qps、rt，其中load、cpu、mem来衡量机器性能，qps、rt来衡量应用性能。
qps： 一秒钟内完成的请求数量  
rt：  一个请求完成的时间   
Tic： 线程的cpu计算时间   
Tiw： 线程的等待时间（io/网络/锁）   
Tn：  线程数   
Tno： 最佳线程数   
Cn：  cpu核数   
Cu：  cpu使用率    
关于上述指标的计算以及意义可以参考以下这篇博客：https://blog.csdn.net/weixin_33725807/article/details/90588634?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task   
首先我们谈谈影响应用性能的俩个因素qps、rt
#### 应用性能
1.一秒钟内完成的请求数量：该数量的多少与硬件有关，更与我们的程序代码有关，影响其主要的因素有以下几种：   
(1). 请求的数据大小   
(2). 请求的计算量大小   
(3). 如果需要进行磁盘IO还需要看磁盘IO的读取速度   
(4). 网络带宽   
(5). GC SWAP等内存操作
2. 一个请求完成的时间: 与1类似，也是很受到程序代码的影响
#### 机器性能
接下来让我们来看看衡量机器性能的指标——load 和 cpu使用率。   

cpu使用率：程序在运行期间实时使用的cpu比率。   
load：代表着一段时间内正在使用和等待使用cpu的任务平均数  
机器负荷高，但应用负荷不高

即机器的load很高，但是应用的qps、rt都不高，这种情况可能有以下几种原因：

    其他资源导致cpu利用率上不去，大量线程在执行其他动作或者在等待，比如io的速度太慢，内存gc等。
    如果系统资源不是瓶颈，则由可能是锁竞争、后端依赖的服务吞吐低、没有充分利用多核资源，多核却使用单线程。

查看机器load高的常见方法：

    机器的io（磁盘io、网络io）：vmstat、iostat、sar -b等。
    网络io：iftop、iptraf、ntop、tcpdump等。
    内存：gc、swap、sar -r。
    锁竞争、上下文切换、后端依赖。
    

机器负荷高，应用负荷也高

即机器load很高，应用qps也很高

    典型的cpu型应用，rt中Tiw很小，基本上全是cpu计算，可以尝试查找cpu耗的较多的线程，降低cpu计算的复杂度。
    应用的负荷真的很大，当所有优化手段都做了，还是无法降下来，可以考虑加机器，不丢人。


导致负载高的原因可能很复杂，有可能是硬件问题也可能是软件问题。
如果是硬件问题，那么说明机器性能确实就不行了，那么解决起来很简单，直接换机器就可以了。
CPU使用、内存使用、IO消耗都可能导致负载高。如果是软件问题，有可能由于的某些线程被长时间占用、大量内存持续占用等导致。建议从以下几个方面排查代码问题：

1、是否有内存泄露

2、是否有死锁发生

3、是否有大字段的读写

4、会不会是数据库操作导致的，排查SQL语句问题。

这里还有个建议，如果发现线上机器Load飙高，可以考虑先把堆栈内存dump下来后，进行重启，暂时解决问题，然后再考虑回滚和排查问题。

### 零拷贝操作
简单一点来说，零拷贝就是一种避免 CPU 将数据从一块存储拷贝到另外一块存储的技术。

零拷贝技术可以减少数据拷贝和共享总线操作的次数，消除传输数据在存储器之间不必要的中间拷贝次数，从而有效地提高数据传输效率。

而且，零拷贝技术减少了用户应用程序地址空间和操作系统内核地址空间之间因为上下文切换而带来的开销。进行大量的数据拷贝操作其实是一件简单的任务，从操作系统的角度来说，如果 CPU 一直被占用着去执行这项简单的任务，那么这将会是很浪费资源的；如果有其他比较简单的系统部件可以代劳这件事情，从而使得 CPU 解脱出来可以做别的事情，那么系统资源的利用则会更加有效。

零拷贝技术的要点：

    避免操作系统内核缓冲区之间进行数据拷贝操作。
    避免操作系统内核和用户应用程序地址空间这两者之间进行数据拷贝操作。
    用户应用程序可以避开操作系统直接访问硬件存储。
    数据传输尽量让 DMA 来做。

DMA：是指外部设备不通过CPU而直接与系统内存交换数据的接口技术。

零拷贝技术分类
Linux 中的零拷贝技术主要有下面这几种：

    直接 I/O
    mmap
    sendfile
    splice

三.sendfile实现零拷贝的原理

1.描述
sendfile系统调用在两个文件描述符之间直接传递数据(完全在内核中操作)，从而避免了数据在内核缓冲区和用户缓冲区之间的拷贝，操作效率很高，被称之为零拷贝。

2.原理
sendfile() 系统调用利用 DMA 引擎将文件中的数据拷贝到操作系统内核缓冲区中，然后数据被拷贝到与 socket 相关的内核缓冲区中去。接下来，DMA 引擎将数据从内核 socket 缓冲区中拷贝到协议引擎中去。

sendfile() 系统调用不需要将数据拷贝或者映射到应用程序地址空间中去，所以 sendfile() 只是适用于应用程序地址空间不需要对所访问数据进行处理的情况。因为 sendfile 传输的数据没有越过用户应用程序 / 操作系统内核的边界线，所以 sendfile () 也极大地减少了存储管理的开销。

简单归纳上述的过程：

    sendfile系统调用利用DMA引擎将文件数据拷贝到内核缓冲区，之后数据被拷贝到内核socket缓冲区中
    DMA引擎将数据从内核socket缓冲区拷贝到协议引擎中

这里没有用户态和内核态之间的切换，也没有内核缓冲区和用户缓冲区之间的拷贝，大大提升了传输性能。
四.带有 DMA 收集拷贝功能的 sendfile

上面介绍的 sendfile() 技术在进行数据传输仍然还需要一次多余的数据拷贝操作，通过引入一点硬件上的帮助，这仅有的一次数据拷贝操作也可以避免。为了避免操作系统内核造成的数据副本，需要用到一个支持收集操作的网络接口。主要的方式是待传输的数据可以分散在存储的不同位置上，而不需要在连续存储中存放。这样一来，从文件中读出的数据就根本不需要被拷贝到 socket 缓冲区中去，而只是需要将缓冲区描述符传到网络协议栈中去，之后其在缓冲区中建立起数据包的相关结构，然后通过 DMA 收集拷贝功能将所有的数据结合成一个网络数据包。网卡的 DMA 引擎会在一次操作中从多个位置读取包头和数据。Linux 2.4 版本中的 socket 缓冲区就可以满足这种条件，这种方法不但减少了因为多次上下文切换所带来开销，同时也减少了处理器造成的数据副本的个数。对于用户应用程序来说，代码没有任何改变。

主要过程如下：
首先，sendfile() 系统调用利用 DMA 引擎将文件内容拷贝到内核缓冲区去；然后，将带有文件位置和长度信息的缓冲区描述符添加到 socket 缓冲区中去，此过程不需要将数据从操作系统内核缓冲区拷贝到 socket 缓冲区中，DMA 引擎会将数据直接从内核缓冲区拷贝到协议引擎中去，这样就避免了最后一次数据拷贝。
五.总结

上述的两种几种I/O操作对比：

1.传统I/O
硬盘—>内核缓冲区—>用户缓冲区—>内核socket缓冲区—>协议引擎

2.sendfile
硬盘—>内核缓冲区—>内核socket缓冲区—>协议引擎

3.sendfile（ DMA 收集拷贝）
硬盘—>内核缓冲区—>协议引擎

Tips:用户态和内核态切换的代价在哪？

首先，用户态一个进程，内核态一个进程，切换就要进行进程间的切换。
拿系统调用举例来说，系统调用一般都需要保存用户程序得上下文(context), 在进入内核得时候需要保存用户态得寄存器，在内核态返回用户态得时候会恢复这些寄存器得内容。这是一个开销的地方。

如果需要在不同用户程序间切换的话，那么还要更新cr3寄存器，这样会更换每个程序的虚拟内存到物理内存映射表的地址，也是一个比较高负担的操作。

而且内核代码对用户不信任，需要进行额外的检查。系统调用的返回过程有很多额外工作，比如检查是否需要调度等。

作者：叫我不矜持
链接：https://www.jianshu.com/p/028cf0008ca5
来源：简书

### mmap原理:   
一般的写   
用户空间(程序调用write)----copy data---->内核空间(查看页缓存)   
					|----------击中-------->写入内存   
					|----------没有-------->根据文件innode查看磁盘所在位置---copy data---->磁盘   
一般的读
用户空间(程序调用read)---->内核空间(查看页缓存)    
					|--------击中------>读取内存数据----copy data-->内核空间------copy data------->用户空间
					|--------没有------>加载磁盘到内存---缺页终端---->磁盘-------copy data--->内核----copy 											data------->用户空间   
mmap的写  
用户空间-----直接映射------->内存 
			|----------击中-------->写入内存   
			|----------没有-------->根据文件innode查看磁盘所在位置---加载到内存---->内存     
mmap的读
磁盘空间----直接映射--->用户空间   
|----------击中-------->读到内存   
|----------没有-------->根据文件innode查看磁盘所在位置---加载到内存---->内存   


#### mmap的步骤：  
1.用户空间调用mmap，先进行进程空间的初始化    
2.内核空间调用mmap(与用户空间的不同)，建立页表，将虚拟地址与文件地址一一映射  
3.前2步做好了前期功能，但是没有将页表加载到内存，在进行读写操作时，会发生却页中断，将页表加载到内存  
mmap的优点：   
1.mmap绕过页缓存机制，将用户程序空间与磁盘空间进行映射，直接进行数据读写，减少了用户空间到内核空间的数据拷贝。  
2.可以被多个进程共享，作为进程间的IPC  


#### mmap缺点：  
1.缺乏同步机制，作为进程间通信的方式，需要进行额外的同步操作  
2.在内存紧张需要进行换页的系统，由于mmap不需要经过页缓存，所以会被经常换出，造成性能下降  
3.其中一个访问出错会对另一个进程造成影响。   
我们做个测试：

场景A：物理内存+swap space: 16G，映射文件30G，使用一个进程进行mmap，成功后映射后持续写入数据  
场景B：物理内存+swap space: 16G，映射文件15G，使用两个进程进行mmap，成功后映射后持续写入数据  
场景 	序列 	映射类型 	结果  
A 	1 	MAP_PRIVATE 	mmap报错
A 	2 	MAP_PRIVATE + MAP_NORESERVE 	mmap成功，在持续写入情况下，遇到OOM Killer
A 	3 	MAP_SHARED 	mmap成功，在持续写入正常
B 	4 	MAP_PRIVATE 	mmap成功，在持续写入情况下，有一个进程会遇到OOM Killer
B 	5 	MAP_PRIVATE + MAP_NORESERVE 	mmap成功，在持续写入情况下，有一个进程会遇到OOM Killer
B 	6 	MAP_SHARED 	mmap成功，在持续写入正常

从上述测试可以看出，从现象上看，NORESERVE是绕过mmap的校验，让其可以mmap成功。但其实在RESERVE的情况下(序列4)，从测试结果看，也没有保障。  


#### mmap考参以下链接  
作者：招财二师兄  
https://www.jianshu.com/p/eece39beee20   
mmap 函数的深入理解https://blog.csdn.net/qq_33611327/article/details/81738195   
linux文件读写 https://www.cnblogs.com/huxiao-tee/p/4657851.html   
  
