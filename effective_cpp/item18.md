# Item 18: Make interfaces easy to use correctly and hard to use incorrectly.

```cpp
class Date 
{
public:
    Date(int month, int day, int year);
};
```
At first glance, this interface may seem reasonable (at least in the
USA), but there are at least two errors that clients might easily make.
First, they might pass parameters in the wrong order:
```cpp
Date d(30, 3, 1995); // Oops! Should be “3, 30” , not “30, 3”
```
Second, they might pass an invalid month or day number:
```cpp
Date d(3, 40, 1995); // Oops! Should be “3, 30” , not “3, 40”
```
```cpp
struct Day {
    explicit Day(int d) : val(d){}
    int val;
}
struct Month {
    explicit Month(int d) : val(d){}
    int val;
}

struct Year {
    explicit Year(int d) : val(d){}
    int val;
}
class Date {
public:
Date(const Month& m, const Day& d, const Year& y);
...
};
Date d(30, 3, 1995); // error! wrong types
Date d(Day(30), Month(3), Year(1995)); // error! wrong types
Date d(Month(3), Day(30), Year(1995)); // okay, types are corr
```
Making Day, Month, and Year full-fledged classes with encapsulated
data would be better than the simple use of structs above

Once the right types are in place, it can sometimes be reasonable to
restrict the values of those types
```cpp
class Month {
public:
static Month Jan() { return Month(1); }
static Month Feb() { return Month(2); } 
static Month Dec() { return Month(12); } 
private:
explicit Month(int m);
};
Date d(Month::Mar(), Day(30), Year(1995));
```

## Things to Remember
 * *Good interfaces are easy to use correctly and hard to use incorrectly.
You should strive for these characteristics in all your interfaces.*
* *Ways to facilitate correct use include consistency in interfaces and
behavioral compatibility with built-in types.*
 * *Ways to prevent errors include creating new types, restricting operations
on types, constraining object values, and eliminating client resource
management responsibilities.*
 * *tr1::shared_ptr supports custom deleters. This prevents the cross-
DLL problem, can be used to automatically unlock mutexes*