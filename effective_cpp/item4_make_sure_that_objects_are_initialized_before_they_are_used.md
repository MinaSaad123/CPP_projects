# Item 4: Make sure that objects are initialized before they’re used.
Stop using this way
```cpp
ABEntry::ABEntry(const std::string& name, const std::string& address,
const std::list<PhoneNumber>& phones)
{
    theName = name; // these are all assignments,
    theAddress = address; // not initializations
    thePhones = phones;
    numTimesConsulted = 0;
}
```
  Use initilaized list to have the ability to trigger constructor.
```cpp
ABEntry::ABEntry(const std::string& name, const std::string& address,
const std::list<PhoneNumber>& phones)
: theName(name),
theAddress(address), // these are now all initializations
thePhones(phones),
numTimesConsulted(0)
{

}
```
if there isn't paramter you can use default contructor
```cpp
ABEntry::ABEntry()
: theName(), // call theName’s default ctor;
theAddress(), // do the same for theAddress;
thePhones(), // and for thePhones;
numTimesConsulted(0) // but explicitly initialize numTimesConsulted to zero
{

}
```
> [!NOTE]
*Sometimes the initialization list must be used, even for built-in types.
For example, data members that are const or are references must be
initialized; they can’t be assigned.*
---

## order of initialization
One aspect of C++ that isn’t fickle is the order in which an object’s
data is initialized. This order is always the same: base classes are initialized
before derived classes, and within a class,
data members are initialized in the order in which they are declared.

### static object initialization problem
the actual problem is this: if initialization
of a non-local static object in one translation unit uses a
non-local static object in a different translation unit, the object it uses
could be uninitialized, because the relative order of initialization of nonlocal
static objects defined in different translation units is undefined.
> [!CAUTION]
There is different between static objects and static keyword. static object is the objects which lifetime is until the end of the program
```cpp
class FileSystem { // from your library’s header file
public:

    std::size_t numDisks() const; // one of many member functions

};
extern FileSystem tfs; // declare object for clients touse
                        // (“tfs” = “the file system” ); definition
                        // is in some .cpp file in your library
```

The below code exist in another file.
```cpp
class Directory { // created by library client
public:
Directory( params );
};
Directory::Directory( params )
{

    std::size_t disks = tfs.numDisks(); // use the tfs object

}
```
**the relative order of initialization of non-local static
objects defined in different translation units is undefined.**
> [!NOTE]
a small design change eliminates the problem entirely.
All that has to be done is to move each non-local static object into its
own function, where it’s declared static. These functions return references
to the objects they contain

## Things to remember
* Manually initialize objects of built-in type, because C++ only sometimes
initializes them itself.
* In a constructor, prefer use of the member initialization list to assignment
inside the body of the constructor. List data members in
the initialization list in the same order they’re declared in the class.
* Avoid initialization order problems across translation units by replacing
non-local static objects with local static objects.