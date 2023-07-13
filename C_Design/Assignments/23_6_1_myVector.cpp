#include "23_5_25_myAlloc.cpp"

template<typename _Tp, typename _Alloc>
struct myVector_base        // <-- 容器基类
{
	typedef typename myAllocator<_Tp>::template rebind<_Tp>::other _Tp_alloc_type;
	typedef typename myAllocator<_Tp>::template rebind<_Tp>::other::pointer pointer;

	struct _Vector_impl_data
	{
		_Tp* _M_start;
		_Tp* _M_finish;
		_Tp* _M_end_of_storage;

		_Vector_impl_data() : _M_start(nullptr), _M_finish(nullptr), _M_end_of_storage(nullptr)
		{ }

		_Vector_impl_data(_Vector_impl_data&& __x) noexcept : _M_start(__x._M_start), _M_finish(__x._M_finish), _M_end_of_storage(__x._M_end_of_storage)
		{ __x._M_start = __x._M_finish = __x._M_end_of_storage = nullptr; }

		void _M_copy_data(_Vector_impl_data const& __x) noexcept
		{
			_M_start = __x._M_start;
			_M_finish = __x._M_finish;
			_M_end_of_storage = __x.end_of_storage;
		}

		void _M_swap_data(_Vector_impl_data& __x) noexcept
		{
			_Vector_impl_data __tmp;
			__tmp._M_copy_data(*this);
			_M_copy_data(__x);
			__x._M_copy_data(__tmp);
		}
	};

	struct _Vector_impl : _Vector_impl_data, _Tp_alloc_type
	{
		_Vector_impl() _GLIBCXX_NOEXCEPT_IF(                // <-- 默认构造函数
											std::is_nothrow_default_constructible<_Tp_alloc_type>::value)
			: _Tp_alloc_type()
		{ }

		_Vector_impl(_Tp_alloc_type const& __a) noexcept    // <-- 拷贝构造函数
			: _Tp_alloc_type(__a)
		{ }

		_Vector_impl(_Tp_alloc_type&& __a) noexcept         // <-- 移动构造函数
			: _Tp_alloc_type(std::move(__a))
		{ }

		_Vector_impl(_Vector_impl&& __x) noexcept           // <-- 移动构造函数
			: _Vector_impl_data(std::move(__x)), _Tp_alloc_type(std::move(__x))
		{ }

		_Vector_impl(_Vector_impl&& __x, _Tp_alloc_type&& __a) noexcept     // <-- 移动构造函数
			: _Vector_impl_data(std::move(__x)), _Tp_alloc_type(std::move(__a))
		{ }
	};

public:
	typedef _Alloc allocator_type;

	_Tp_alloc_type& _M_get_Tp_allocator() noexcept              //非常量分配器获取函数 (供内部调用)
	{ return this->_M_impl; }

	const _Tp_alloc_type& _M_get_Tp_allocator() const noexcept  //常量分配器获取函数 (供内部调用)
	{ return this->_M_impl; }

	allocator_type get_allocator() const noexcept               //外部获取分配器 (供外部调用)
	{ return allocator_type(_M_get_Tp_allocator()); }

	myVector_base() = default;                                  //默认构造函数

	myVector_base(const allocator_type& __a) noexcept           //拷贝构造函数
		: _M_impl(__a)
	{ }

	myVector_base(size_t __n)
		: _M_impl() { _M_create_storage(__n); }

	myVector_base(size_t __n, const allocator_type& __a)
		: _M_impl(__a) { _M_create_storage(__n); }

	//移动构造函数
	myVector_base(myVector_base&&) = default;

	//移动构造函数
	myVector_base(_Tp_alloc_type&& __x) noexcept
		: _M_impl(std::move(__x)) { }

	//移动构造函数
	myVector_base(myVector_base&& __x, const allocator_type& __a)
		: _M_impl(__a)
	{
		if (__x.get_allocator() == __a)
			//如果两个容器的分配器相同, 直接交换数据
			this->_M_impl._M_swap_data(__x._M_impl);
		else
		{   //否则, 重新分配内存, 拷贝数据
			size_t __n = __x._M_impl._M_finish - __x._M_impl._M_start;
			_M_create_storage(__n);
		}
	}

	~myVector_base() noexcept
	{
		_M_deallocate(this->_M_impl._M_start,
						this->_M_impl._M_end_of_storage - this->_M_impl._M_start);
	}

public:
	_Vector_impl _M_impl;

	pointer _M_allocate(size_t __n)
	{
		//分配内存, 调用分配器的allocate函数
		typedef myAllocator<_Tp_alloc_type> _Alloc_traits;
		return __n != 0 ? _Alloc_traits::allocate(_M_impl, __n) : nullptr;
	}

	void _M_deallocate(pointer __p, size_t __n)
	{
		//释放内存, 调用分配器的deallocate函数   
		typedef myAllocator<_Tp_alloc_type> _Alloc_traits;
		if (__p != nullptr)
			_Alloc_traits::deallocate(_M_impl, __p, __n);
	}

protected:
	void _M_create_storage(size_t __n)
	{
		this->_M_impl._M_start = this->_M_allocate(__n);
		this->_M_impl._M_finish = this->_M_impl._M_start;
		this->_M_impl._M_end_of_storage = this->_M_impl._M_start + __n;
	}
};

template<typename _Tp, typename _Alloc = myAllocator<_Tp>>
class myVector : protected myVector_base<_Tp, _Alloc>
{
	static_assert(std::is_same<typename std::remove_cv<_Tp>::type, _Tp>::value);
	static_assert(std::is_same<typename _Alloc::value_type, _Tp>::value);

	typedef myVector_base<_Tp, _Alloc> _Base;
	typedef typename _Base::_Tp_alloc_type _Tp_alloc_type;
	typedef myAllocator<_Tp_alloc_type> _Alloc_traits;

public:
	typedef _Tp value_type;
	typedef typename _Base::pointer pointer;
	typedef typename _Alloc_traits::const_pointer const_pointer;
	typedef typename _Alloc_traits::reference reference;
	typedef typename _Alloc_traits::const_reference const_reference;
	// TODO: 用自己实现的迭代器替换
	typedef __gnu_cxx::__normal_iterator<pointer, myVector> iterator;
	typedef __gnu_cxx::__normal_iterator<const_pointer, myVector> const_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef _Alloc allocator_type;

private:
	//判断是否可以使用memmove函数, 可以使用则返回true
	static constexpr bool
		_S_nothrow_relocate(std::true_type)
	{
		return noexcept(std::__relocate_a(std::declval<pointer>(),
						std::declval<pointer>(),
						std::declval<pointer>(),
						std::declval<_Tp_alloc_type&>()));
	}

	//判断是否可以使用memmove函数, 不能使用则返回false
	static constexpr bool
		_S_nothrow_relocate(std::false_type)
	{ return false; }

	//判断是否可以使用重分配优化, 可以使用则返回true
	static constexpr bool
		_S_use_relocate()
	{ return _S_nothrow_relocate(std::__is_move_insertable<_Tp_alloc_type>{}); }

	//在移动构造函数或移动赋值运算符存在时, 重分配优化
	static pointer
		_S_do_relocate(pointer __first, pointer __last, pointer __result, _Tp_alloc_type& __alloc, std::true_type) noexcept
	{ return std::__relocate_a(__first, __last, __result, __alloc); }

	//在移动构造函数或移动赋值运算符不存在时, 不重分配优化
	static pointer
		_S_do_relocate(pointer, pointer, pointer __result, _Tp_alloc_type&, std::false_type) noexcept
	{ return __result; }

	//不支持重分配优化时, 重新分配内存, 拷贝数据
	static pointer
		_S_relocate(pointer __first, pointer __last, pointer __result, _Tp_alloc_type& __alloc) noexcept
	{
		using __do_it = std::__bool_constant<_S_use_relocate()>;
		return _S_do_relocate(__first, __last, __result, __alloc, __do_it{});
	}

protected:
	using _Base::_M_allocate;
	using _Base::_M_deallocate;
	using _Base::_M_impl;
	using _Base::_M_get_Tp_allocator;

public:
	myVector = default;

	explicit myVector(const allocator_type& __a) noexcept
		:_Base(__a) { }

	explicit
		myVector(size_type __n, const allocator_type& __a = allocator_type())
		: _Base(std::)

};