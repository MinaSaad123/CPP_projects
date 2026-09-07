# Item 3: Use const whenver possible

> [!NOTE]
**it’s never legal to modify the return value of a function
that returns a built-in type.**

**There are two prevailing notions: bitwise
constness (also known as physical constness) and logical constness**

## bitwise constness (physical const)
**it means no bits in the object is changed.**
```cpp
class CTextBlock {
public:
    //do anything
    char& operator[](std::size_t position) const // inappropriate (but bitwise const) declaration of operator[]
    { return pText[position]; } 

private:
    char *pText;
};
```
This class (inappropriately) declares operator[] as a const member
function, even though that function returns a reference to the object’s
internal data
## logical const
**the object is const but members of the object is changed throughout mutuable keyword.**
```cpp
class CTextBlock {
public:
    //do anything
    std::size_t length() const;
    private:
    char *pText;
    mutable std::size_t textLength;
    mutable bool lengthIsValid; 
}; 
std::size_t CTextBlock::length() const
{
    if (!lengthIsValid) {
        textLength = std::strlen(pText); // now fine
        lengthIsValid = true; // also fine
    }
    return textLength;
}
```
### Avoiding Duplication in const and Non-const Member Functions
```cpp
class TextBlock {
public:
    //do anything

    const char& operator[](std::size_t position) const // same as before
    {

       return text[position];
    }
    char& operator[](std::size_t position) // now just calls const op[]
    {
        return
            const_cast<char&>(static_cast<const TextBlock&>(*this)[position]);
    }
};
```
> [!CAUTION] 
it's wrong to make the reverse **"call non-const inside const function"**
---
## const with pointers
```cpp
char greeting[] = "Hello";
char *p = greeting; // non-const pointer, non-const data
const char *p = greeting; // non-const pointer, const data
char * const p = greeting; // const pointer, non-const data
const char * const p = greeting; // const pointer, const data
```
there are two level of constness: top-level and low level
1. **top-level const:** effects the object itself, `char* const p = greeting;` there is a const restriction on the pointer itself.
2. **low-level const:** effect the object which the pointer points to, `const char* p = greeting;`

## const with the iterators
```cpp
std::vector<int> vec;
const std::vector<int>::iterator iter = // iter acts like a T* const
vec.begin();
*iter = 10; // OK, changes what iter points to
++iter; // error! iter is const
std::vector<int>::const_iterator cIter = // cIter acts like a const T*
vec.begin();
*cIter = 10; // error! *cIter is const
++cIter; // fine, changes cIter
```
STL iterators are modeled on pointers, so an iterator acts much like a
`T* pointer`. 

1. `const std::vector<int>::iterator iter` is like declaring a pointer const
(i.e., declaring a `T* const pointer`): **the iterator isn’t allowed to point to something different, but the thing it points to may be modified**.

2. `std::vector<int>::const_iterator cIter` is analogue of a` const T* pointer`.
---
> [!NOTE]
**const is a wonderful thing. On
pointers and iterators; on the objects referred to by pointers, iterators, and references; on function parameters and return types; on local
variables; and on member functions, const is a powerful ally. Use it
whenever you can. You’ll be glad you did.**

## NOTES
* *Declaring something const helps compilers detect usage errors. const can be applied to objects at any scope, to function parameters and
return types, and to member functions as a whole.*
* *Compilers enforce bitwise constness, but you should program using
logical constness*.
*  *When const and non-const member functions have essentially identical
implementations, code duplication can be avoided by having the
non-const version call the const version.*

