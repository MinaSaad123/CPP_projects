# Item 21: Don’t try to return a reference when you must return an object.

Temptation of avoiding expensive copy makes you use references in every place which is wrong because you can return a reference for a local variables which will be destroyed after getting out the scope of function

```cpp
class Rational {
public:
    Rational(int numerator = 0, // see Item 24 for why this
    int denominator = 1); // ctor isn’t declared explicit
...
private:
    int n, d; // numerator and denominator
    friend
    const Rational // see Item 3 for why the
    operator*(const Rational& lhs, // return type is const
    const Rational& rhs);

    bool operator==(const Rational& lhs, // an operator==
    const Rational& rhs); // for Rationals
}; 

const Rational& operator*(const Rational& lhs, // warning! yet more
const Rational& rhs) // bad code!
{
    static Rational result; // static object to which a
    // reference will be returned
    result = ... ; // multiply lhs by rhs and put the
    // product inside result
    return result;
}
```
Using static is not thread-safe

Here there is a problem:)
```cpp
if ((a * b) == (c * d)) {
    //do whatever’s appropriate when the products are equal;
} else {
    //do whatever’s appropriate when they’re not;
}
```
the returned reference to static var from (a * b) is same like (c * d)

## Things to Remember
*Never return a pointer or reference to a local stack object, a reference
to a heap-allocated object, or a pointer or reference to a local
static object if there is a chance that more than one such object will
be needed. (Item 4 provides an example of a design where returning
a reference to a local static is reasonable, at least in single-threaded
environments.)*