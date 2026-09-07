# Item 13: Use objects to manage resources

```cpp
class Investment { ... }; // root class of hierarchy of
// investment types
```
Use a factory function
```cpp
Investment* createInvestment();
```
A function to use the factory function:

```cpp
void f()
{
    Investment *pInv = createInvestment(); // call factory function
    ... // use pInv
    delete pInv; // release object
    }

```
As you can see we let the client to delete the resource by itself, under any conditions there is exception could happens or goto, return and so on, This will lead to memory leaks, therefore instead of using raw pointers we used an object to manage the resource throughout destructor **(Smart pointer)**.

```cpp
void f()
{
    std::auto_ptr<Investment> pInv(createInvestment());
}
```
> [!CAUTION]
*`auto_ptr` is old-broken design, Instead of it use `unique_ptr`.*

> [!NOTE]
*the idea of using objects to manage resources is often called
**Resource Acquisition Is Initialization (RAII),***

## Things to Remember
*  To prevent resource leaks, use RAII objects that acquire resources
in their constructors and release them in their destructors.
* Two commonly useful RAII classes are tr1::shared_ptr and auto_ptr.
tr1::shared_ptr is usually the better choice, because its behavior when
copied is intuitive. Copying an auto_ptr sets it to null.