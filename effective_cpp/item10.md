# Item 10: Have assignment operators return a reference to *this
One of the interesting things about assignments is that you can chain
them together:
```cpp
int x, y, z;
x = y = z = 15; // chain of 
```
Also interesting is that assignment is right-associative, so the above
assignment chain is parsed like this:
```cpp
x = (y = (z = 15)); 
```
Here, 15 is assigned to z, then the result of that assignment (the
updated z) is assigned to y, then the result of that assignment (the
updated y) is assigned to x.
The way this is implemented is that assignment returns a reference to
its left-hand argument, and that’s the convention you should follow
when you implement assignment operators for your classes:
```cpp
class Widget {
public:
    Widget& operator=(const Widget& rhs) // return type is a reference to
    { // the current class

        return *this; // return the left-hand object
    }

};
class Widget {
public:
    Widget& operator+=(const Widget& rhs) // the convention applies to +=, -=, *=, etc.
    { 

        return *this;
    }
    Widget& operator=(int rhs) 
    { 
        return *this;
    }

};
```