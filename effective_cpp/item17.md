# Item 17: Store newed objects in smart pointers in standalone statements.

## Look about this code can leak a memory
```cpp
processWidget(std::tr1::shared_ptr<Widget>(new Widget), priority());
```
> [!CAUTION]
The order of evaluating functino in c++ is undefined before c++ 17, So if the order of evaluating be like that:

1. Execute “new Widget”.
2. Call priority.
3. Call the tr1::shared_ptr constructor.

Consider that call to priority yields an exception.
In that case, the pointer returned from “`new Widge`t” will be lost,
because it won’t have been stored in the`tr1::shared_ptr` we were expecting
would guard against resource leaks.

To overcome this problem we should store the newed objexts in smart pointers in standalone statememnts.

## Things to Remember
* *Store newed objects in smart pointers in standalone statements.
Failure to do this can lead to subtle resource leaks when exceptions
are thrown.*
