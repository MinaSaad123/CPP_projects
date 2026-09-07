# Item 20: Prefer pass-by-reference-to-const to pass-byvalue.

```cpp
class Window {
public:
...
std::string name() const; // return name of window
virtual void display() const; // draw window and contents
};
class WindowWithScrollBars: public Window {
public:
...
virtual void display() const;
};

void printNameAndDisplay(Window w) // incorrect! parameter
{ // may be sliced!
    std::cout << w.name();
    w.display();
}
```
```cpp
WindowWithScrollBars wwsb;
printNameAndDisplay(wwsb);
```
Passing by value would encounter the constructed object to be sliced

To solve this problem we should pass by reference 
```cpp
void printNameAndDisplay(const Window& w) // fine, parameter won’t
{ // be sliced
    std::cout << w.name();
    w.display();
}
```
> [!CAUTION]
> If you peek under the hood of a C++ compiler, you’ll find that references
are typically implemented as pointers, so passing something by
reference usually means really passing a pointer

> [!CAUTION]
> For built-in types, then, when you
have a choice between pass-by-value and pass-by-reference-to-const,
it’s not unreasonable to choose pass-by-value. This same advice
applies to **iterators** and **function objects** in the STL

## Things to Remember
* Prefer pass-by-reference-to-const over pass-by-value. It’s typically
more efficient and it avoids the slicing problem.
* The rule doesn’t apply to built-in types and STL iterator and function
object types. For them, pass-by-value is usually appropriate.