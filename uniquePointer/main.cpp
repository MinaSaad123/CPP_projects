/*
 * uniquePointer.cpp
 *
 *  Created on: Jun 28, 2025
 *      Author: Hp-Victus
 */
#include <iostream>
#include <utility> // For std::move
#include <functional> // For custom deleters
#include <memory>

template <typename T, typename Deleter = std::default_delete<T>>
class uniquePtr
{
private:
	T* ptr;
	Deleter deleter;

public:
	//constructor
	explicit uniquePtr (T* rawPtr = nullptr) : ptr(rawPtr) {}

	//destructor
	~uniquePtr ()
	{
		if (ptr)
		{
			delete(ptr);
		}
	}

	//copy constructor
	uniquePtr (const uniquePtr &) = delete;
	//copy assignment
	uniquePtr & operator=(const uniquePtr &) = delete;

	//move constructor
	uniquePtr (uniquePtr && other) noexcept : ptr(other.ptr), deleter(other.deleter)
	{
		other.ptr = nullptr;
	}

	//move assignment
	uniquePtr & operator=(uniquePtr && other) noexcept
	{
		 reset();
		 this->ptr = other.ptr;
		 this->deleter = other.deleter;
		 other.ptr = nullptr;

		 return *this;
	}

	void reset( T* newPtr = nullptr )
	{
		if (newPtr)
		{
			delete(newPtr);
		}

		ptr = newPtr;
	}

	//dereference operator
	T& operator*() const
	{
		return *ptr;
	}

	//get the pointer
	T* get() const
	{
		return ptr;
	}

	 // Arrow operator
	 T* operator->() const
	 {
	    return ptr;
	 }

	 // Release ownership and return the raw pointer
	 T* release()
	 {
		 T* temp = ptr;
		 ptr = nullptr;
		 return temp;
	 }

	 // Check if the pointer is not null
	 explicit operator bool() const
	 {
		 return ptr != nullptr;
	 }

	 void operator()() const
	 {
		 std::cout << " callable function for test\n";
	 }

};


// int main() {
//     uniquePtr<int> ptr(new int(42));
//     std::cout << "Value: " << *ptr << '\n';

//     ptr.reset(new int(100));
//     std::cout << "New Value: " << *ptr << '\n';

//     return 0;
// }

int main()
{
    uniquePtr<int> ptr1(new int(10));
    std::cout << "ptr1 value: " << *ptr1 << '\n';

    uniquePtr<int> ptr2 = std::move(ptr1); // Transfer ownership
    if (!ptr1) {
        std::cout << "ptr1 is now null\n";
    }

    std::cout << "ptr2 value: " << *ptr2 << '\n';

    return 0;
}



