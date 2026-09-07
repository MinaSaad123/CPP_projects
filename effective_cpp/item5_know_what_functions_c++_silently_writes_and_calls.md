# Item 5: Know what functions C++ silently writes and calls.
## Introduction
Compilers will declare their
own versions of a copy constructor, a copy assignment operator, and a
destructor. Furthermore, if you declare no constructors at all, compilers
will also declare a default constructor for you. All these functions
will be both `public` and `inline`.

This code:

```cpp
class Empty{

};
```
will implicity be like that.
```cpp
class Empty {
public:
    Empty() {

    } // default constructor
    Empty(const Empty& rhs) {

    } // copy constructor
    ~Empty() {

    } // destructor
    Empty& operator=(const Empty& rhs) {

    } // copy assignment operator
};
```
> [!NOTE]
the generated destructor is non-virtual  unless it’s for a class inheriting from a base class that itself
declares a virtual destructor.

> [!NOTE]
the copy constructor and the copy assignment operator, the
compiler-generated versions **simply copy each non-static data member**
of the source object over to the target object

C++ refuses to compile the code. If you
want to support copy assignment in a class containing a reference
member, you must define the copy assignment operator yourself.
Compilers behave similarly for classes containing const members. It’s not legal to modify
const members.