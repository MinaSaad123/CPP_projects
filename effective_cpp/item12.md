# Item 12: Copy all parts of an object

## 
```cpp
void logCall(const std::string& funcName); // make a log entry
class Customer {
public:

    Customer(const Customer& rhs);
    Customer& operator=(const Customer& rhs);

private:
    std::string name;
};

Customer::Customer(const Customer& rhs)
: name(rhs.name) // copy rhs’s data
{
    logCall("Customer copy constructor");
}
Customer& Customer::operator=(const Customer& rhs)
{
    logCall("Customer copy assignment operator");
    name = rhs.name; // copy rhs’s data
    return *this;
}
```
```cpp
class PriorityCustomer: public Customer { // a derived class
public:

    PriorityCustomer(const PriorityCustomer& rhs);
    PriorityCustomer& operator=(const PriorityCustomer& rhs);

private:
    int priority;
};

PriorityCustomer::PriorityCustomer(const PriorityCustomer& rhs)
: priority(rhs.priority)
{
    logCall("PriorityCustomer copy constructor");
}
PriorityCustomer&
PriorityCustomer::operator=(const PriorityCustomer& rhs)
{
    logCall("PriorityCustomer copy assignment operator");
    priority = rhs.priority;
    return *this;
}
```
I didn't provide a copy assignment operator in the derived class for the base class, So the base object part is not copied.

the solution:
```cpp
PriorityCustomer&
PriorityCustomer::operator=(const PriorityCustomer& rhs)
{
    logCall("PriorityCustomer copy assignment operator");
    Customer::operator=(rhs); // assign base class parts
    priority = rhs.priority;
    return *this;
}
```
## Things to Remember
*  Copying functions should be sure to copy all of an object’s data
members and all of its base class parts.
*  Don’t try to implement one of the copying functions in terms of the
other. Instead, put common functionality in a third function that
both call.