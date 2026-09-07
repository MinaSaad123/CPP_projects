# Item 11: Handle assignment to self in operator=

```cpp 
a[i] = a[j]; // potential assignment to self
```
```cpp 
*px = *py; // potential assignment to self
```

```cpp
class Base {  };
class Derived: public Base {  };
void doSomething(const Base& rb, Derived* pd); 
```
All of these are examples to  potential self-assignment.


This code is unsafe to use:
```cpp
Widget&
Widget::operator=(const Widget& rhs) // unsafe impl. of operator=
{
    delete pb; // stop using current bitmap
    pb = new Bitmap(*rhs.pb); // start using a copy of rhs’s bitmap
    return *this; // see Item 10
}
```
We will solve the **self-assignment** problem through two strategies
1. if statement
```cpp
Widget& Widget::operator=(const Widget& rhs)
{
if (this == &rhs) return *this; // identity test: if a self-assignment,
    // do nothing
    delete pb;
    pb = new Bitmap(*rhs.pb);
    return *this;
}
```
2. copy and swap method
```cpp
Widget& Widget::operator=(const Widget& rhs)
{
    Bitmap *pOrig = pb; // remember original pb
    pb = new Bitmap(*rhs.pb); // point pb to a copy of rhs’s bitmap
    delete pOrig; // delete the original pb
    return *this;
}
```
