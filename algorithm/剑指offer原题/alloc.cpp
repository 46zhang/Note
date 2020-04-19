#include<iostream>
#include<vector>
namespace my_alloc
{
	// allocate的实际实现，简单封装new，当无法获得内存时，报错并退出
	template <class T>
	inline T* _allocate(ptrdiff_t size, T*) {
		//set_new_handler(0);
		T* tmp = (T*)(::operator new((size_t)(size * sizeof(T))));
		if (tmp == 0) {
			std::cout << "out of memory" << std::endl;
			exit(1);
		}
		return tmp;
	}

	// deallocate的实际实现，简单封装delete
	template <class T>
	inline void _deallocate(T* buffer) { ::operator delete(buffer); }

	// construct的实际实现，直接调用对象的构造函数
	template <class T1, class T2>
	inline void _construct(T1* p, const T2& value) { new(p) T1(value); }

	// destroy的实际实现，直接调用对象的析构函数
	template <class T>
	inline void _destroy(T* ptr) { ptr->~T(); }

	template <class T>
	class allocator {
	public:
		typedef T           value_type;
		typedef T*          pointer;
		typedef const T*    const_pointer;
		typedef T&          reference;
		typedef const T&    const_reference;
		typedef size_t      size_type;
		typedef ptrdiff_t   difference_type;

		// 构造函数
		allocator() { return; }
		template <class U>
		allocator(const allocator<U>& c) {}

		// rebind allocator of type U
		template <class U>
		struct rebind { typedef allocator<U> other; };

		// allocate，deallocate，construct和destroy函数均调用上面的实际实现
		// hint used for locality. ref.[Austern],p189
		pointer allocate(size_type n, const void* hint = 0) {
			return _allocate((difference_type)n, (pointer)0);
		}
		void deallocate(pointer p, size_type n) { _deallocate(p); }
		void construct(pointer p, const T& value) { _construct(p, value); }
		void destroy(pointer p) { _destroy(p); }

		pointer address(reference x) { return (pointer)&x; }
		const_pointer const_address(const_reference x) { return (const_pointer)&x; }

		size_type max_size() const { return size_type(UINT_MAX / sizeof(T)); }
	};
} // end of namespace myalloc


/*int main()
{
	std::vector<int, my_alloc::allocator<int> > v;
	getchar();
	// Do something;
	return 0;
}*/