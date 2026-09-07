# Item 7: Declare destructors virtual in polymorphic base classes

## Factory function
```cpp
class TimeKeeper {
public:
    TimeKeeper();
    ~TimeKeeper();
};

class AtomicClock: public TimeKeeper { ... };
class WaterClock: public TimeKeeper { ... };
class WristWatch: public TimeKeeper { ... };
```
Many clients will want access to the time without worrying about the
details of how it’s calculated, so a factory function — a function that
returns a base class pointer to a newly-created derived class object —
can be used to return a pointer to a timekeeping object.
```cpp
TimeKeeper* getTimeKeeper();
```
In keeping with the conventions of factory functions, the objects
returned by getTimeKeeper are on the heap, so to avoid leaking memory
and other resources, it’s important that each returned object be
properly deleted:
```cpp
TimeKeeper *ptk = getTimeKeeper(); // get dynamically allocated object

delete ptk; // release it to avoid resource leak
```
> [!CAUTION]
It is wrong to let the user delete the pointer by itself it's error-prone

## Virtual destructor
`TimeKeeper` base class has a curious flaw, the destructor isn't virtual, the consequence for this: it would destroy the base object and letting the base part will be leaked.
## Factory function
```cpp
class TimeKeeper {
public:
    TimeKeeper();
    virtual ~TimeKeeper();
};
```
> [!NOTE]
 The implementation of virtual functions requires that objects carry
information that can be used at runtime to determine which virtual
functions should be invoked on the object. This information typically
takes the form of a pointer called a `vptr` (“virtual table pointer”). The
`vptr` points to an array of function pointers called a vtbl (“virtual
table”); each class with virtual functions has an associated vtbl. When
a virtual function is invoked on an object, the actual function called is
determined by following the object’s `vptr` to a `vtbl` and then looking up
the appropriate function pointer in the `vtbl`.

## Destructor as pure virtual
pure virtual member function shouldn't provide for it a definiation in base class  
```cpp
class AWOV { // AWOV = “Abstract w/o Virtuals”
public:
    virtual ~AWOV() = 0; // declare pure virtual destructor
};

AWOV::~AWOV() {} // definition of pure virtual dtor
```
But destructor is an exception: The way destructors work is that the most derived class’s destructor
is called first, then the destructor of each base class is called. compilers will generate a call to `~AWOV` from its derived classes’ destructors,
so you have to be sure to provide a body for the function. If you don’t,
the linker will complain.

---
## Things to Remember
*  Polymorphic base classes should declare virtual destructors. If a
class has any virtual functions, it should have a virtual destructor.
* Classes not designed to be base classes or not designed to be used
polymorphically should not declare virtual destructors.