# Item 9: Never call virtual functions during construction or destruction

```cpp
class Transaction {
public:
    Transaction(){ 
        init(); 
    } // call to non-virtual...

    virtual void logTransaction() const = 0;

private:
    void init()
    {
    logTransaction(); // ...that calls a virtual!
    }
};

Transaction::Transaction() // implementation of
{ // base class

    logTransaction(); // as final action, log this transaction
} 
class BuyTransaction: public Transaction { // derived class
public:
    virtual void logTransaction() const; // how to log trans- actions of this type
};
class SellTransaction: public Transaction
{ // derived class
public:
    virtual void logTransaction() const; // how to log transactions of this type
};
```
Because logTransaction is pure virtual in Transaction, most
runtime systems will abort the program when the pure virtual is
called (typically issuing a message to that effect). However, if logTransaction
were a “normal” virtual function (i.e., not pure virtual) with an
implementation in Transaction, that version would be called, and the
program would merrily trot along.
```cpp
class Transaction {
public:
    Transaction(){ 
        init(); 
    } // call to non-virtual...

    virtual void logTransaction() const ;

private:
    void init()
    {
    
    logTransaction(); // ...that calls a virtual!
    }
};

//The rest of code.
```
Clearly a BuyTransaction constructor will be called, but first, a Transaction
constructor must be called; base class parts of derived class
objects are constructed before derived class parts are. The last line of
the Transaction constructor calls the virtual function logTransaction, but
this is where the surprise comes in. The version of logTransaction that’s
called is the one in Transaction, not the one in BuyTransaction
> [!NOTE]
 Static function don't have a this object.

 ## Things to Remember
 Don’t call virtual functions during construction or destruction, because
such calls will never go to a more derived class than that of
the currently executing constructor or destructor