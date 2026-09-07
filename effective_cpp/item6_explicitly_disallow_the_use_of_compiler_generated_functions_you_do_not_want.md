# Item 6: Explicitly disallow the use of compiler generated functions you do not want

## how to prevent the copy constructor and copy assignment from working
Look at this code:
```cpp
HomeForSale h1;
HomeForSale h2;
HomeForSale h3(h1); // attempt to copy h1 — should not compile!
h1 = h2; // attempt to copy h2 — should not compile!
```
To stop copy constructor and copy assignment from taking actions, we put them in private section.
```cpp
class HomeForSale {
public:

private:

    HomeForSale(const HomeForSale&); // declarations only
    HomeForSale& operator=(const HomeForSale&);
};
```
---
## copy constructor and copy assignment in inheritance

```cpp
class Uncopyable {
protected: // allow construction
    Uncopyable() {} // and destruction of
    ~Uncopyable() {} // derived objects...
private:
    Uncopyable(const Uncopyable&); // ...but prevent copying
    Uncopyable& operator=(const Uncopyable&);
};
```
To keep HomeForSale objects from being copied, all we have to do now
is inherit from Uncopyable:
```cpp
class HomeForSale: private Uncopyable {
};
```
This works, because compilers will try to generate a copy constructor
and a copy assignment operator if anybody — even a member or friend
function — tries to copy a HomeForSale object. the
compiler-generated versions of these functions will try to call their
base class counterparts, and those calls will be rejected, because the
copying operations are private in the base class.

> [!NOTE] 
 if you want to prevent the friend function and member function from use copy constructor and assignment operator you shouldn't provide a defination for it, if you provide then they can use it.
 ## Things to Remember
 To disallow functionality automatically provided by compilers, declare
the corresponding member functions private and give no implementations.
Using a base class like Uncopyable is one way to do this.
