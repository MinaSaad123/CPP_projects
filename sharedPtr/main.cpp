/*
 * main.cpp
 *
 *  Created on: Jun 29, 2025
 *      Author: Hp-Victus
 */
#include <iostream>
#include <utility>
#include <functional>
#include <atomic>
#include <memory>


template <typename T>
class sharedPtr
{
private:
	T* ptr;
	std::atomic<unsigned int>* refCount;

	//release implementation
	void release ()
	{
		if (refCount && --(*refCount) == 0)
		{
			delete ptr;
			delete refCount;
			ptr = nullptr;
			refCount = nullptr;
		}
	}
public:
	//default constructor
	sharedPtr () : ptr(nullptr), refCount(nullptr) {}

	//constructor
	explicit sharedPtr (T* rawPtr = nullptr, std::atomic<unsigned int>* atomicCount = new std::atomic<unsigned int>(1)) : ptr(rawPtr), refCount(atomicCount) {}

	//copy constructor
	sharedPtr (const sharedPtr<T> & other): ptr(other.ptr), refCount(other.refCount)
	{
		if (refCount)
		{
			++(*refCount);
		}
	}

	//move constructor
	sharedPtr (sharedPtr<T> && other) : ptr(other.ptr), refCount(other.refCount)
	{
		other.ptr = nullptr;
		other.refCount = nullptr;
	}

	//destructor
	~sharedPtr ()
	{
		release();
	}

    // Copy assignment operator
	sharedPtr& operator=(const sharedPtr<T>& other)
	{
        if (this != &other)
        {
            release(); // Release current resource
            ptr = other.ptr;
            refCount = other.refCount;

            if (refCount)
            {
                ++(*refCount);
            }
        }
        return *this;
    }

    // Move assignment operator
    sharedPtr& operator=(sharedPtr<T>&& other) noexcept
    {
        if (this != &other)
        {
            release(); // Release current resource
            ptr = other.ptr;
            refCount = other.refCount;
            other.ptr = nullptr;
            other.refCount = nullptr;
        }
        return *this;
    }


    // Access the raw pointer
    T* get() const
    {
        return ptr;
    }

    // Dereference operators
    T& operator*() const
    {
        return *ptr;
    }

    T* operator->() const
    {
        return ptr;
    }

    // Check reference count
    unsigned int used_count() const
    {
        return refCount ? (unsigned int)*refCount : 0;
    }

    // Reset the pointer
    void reset(T* newPtr = nullptr)
    {
        release();
        if (newPtr)
        {
            ptr = newPtr;
            refCount = new std::atomic<unsigned int>(1);
        } else
        {
            ptr = nullptr;
            refCount = nullptr;
        }
    }

    // Check if the pointer is not null
    bool unique() const
    {
        return used_count() == 1;
    }

    explicit operator bool() const
    {
        return ptr != nullptr;
    }



};

int main()
{
    sharedPtr<int> sp1(new int(10)); // Create a SharedPointer
    std::cout << "sp1 use count: " << sp1.used_count() << '\n'; // 1

    sharedPtr<int> sp2 = sp1; // Share ownership
    std::cout << "sp1 use count: " << sp1.used_count() << '\n'; // 2
    std::cout << "sp2 use count: " << sp2.used_count() << '\n'; // 2

    {
    	sharedPtr<int> sp3 = sp2; // Another shared pointer
        std::cout << "sp3 use count: " << sp3.used_count() << '\n'; // 3
    } // sp3 goes out of scope, ref count decreases

    std::cout << "sp1 use count after sp3 scope: " << sp1.used_count() << '\n'; // 2

    sp2.reset(); // Release ownership
    std::cout << "sp1 use count after sp2 reset: " << sp1.used_count() << '\n'; // 1

    return 0; // sp1 goes out of scope, object is destroyed
}



