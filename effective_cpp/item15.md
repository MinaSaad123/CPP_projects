# Item 15: Provide access to raw resources in resourcemanaging classes

## Manage raw pointer returned for smart pointer
### Explicit conversation
Many APIs refer to resources directly, so unless you
plan to foreswear use of such APIs (something that’s rarely practical),
you’ll have to bypass resource-managing objects and deal with raw
resources from time to time.

For example:
pInv is an smart pointer and you want to deal with raw pointer not smart one so, We use `get` member function to return the raw pointer that smart pointer is holding.
```cpp
int days = daysHeld(pInv); // error!
```

```cpp
int days = daysHeld(pInv.get()); //right way
```
### Implicit conversation
```cpp
class Font {
public:

    operator FontHandle() const // implicit conversion function
    { return f; }

};
```
The downside is that implicit conversions increase the chance of
errors. For example, a client might accidently create a FontHandle
when a Font was intended

## Overloaded dereferences operators
```cpp
std::tr1::shared_ptr<Investment> pi1(createInvestment());
bool taxable1 = !(pi1->isTaxFree());
bool taxable2 = !((*pi2).isTaxFree());
```

## Things to Remember
*  APIs often require access to raw resources, so each RAII class
should offer a way to get at the resource it manages.
* Access may be via explicit conversion or implicit conversion. In general,
explicit conversion is safer, but implicit conversion is more convenient
for clients.