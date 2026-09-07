# Item 16: Use the same form in corresponding uses of new and delete

There is a problrm
```cpp
std::string *stringArray = new std::string[100];
delete stringArray;
```
To solve this problem you should use brackets in the delete keyword
```cpp
std::string *stringPtr1 = new std::string;
std::string *stringPtr2 = new std::string[100];
...
delete stringPtr1; // delete an object
delete [] stringPtr2; // delete an array of objects
```
## Using typedef with array
```cpp
typedef std::string AddressLines[4];
std::string *pal = new AddressLines; // note that “new AddressLines” returns a string*, just like “new string[4]” would

delete []pal; //fine
```
# Things to Remember
* *If you use [] in a new expression, you must use [] in the corresponding
delete expression. If you don’t use [] in a new expression, you
mustn’t use [] in the corresponding delete expression.*