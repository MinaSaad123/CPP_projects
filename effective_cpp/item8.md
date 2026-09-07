# Item 8: Prevent exceptions from leaving destructors

C++ can't handle simultaneously active exceptions at the same time, So we should handle the exception in destructor from moment it arise.
there are three strategies
1. **Terminate the program if close throws, typically by calling abort:**
```cpp
DBConn::~DBConn()
{
    try { 
        db.close(); 
    }
    catch (...) {
    make log entry that the call to close failed;
    std::abort();
    }
}
```
2. **Swallow the exception**
```cpp
DBConn::~DBConn()
{
    try { db.close(); }
    catch (...) {
    //make a log
    }
}
```
3. **Let the client "user of class" call `close()` outside the class**
```cpp
class DBConn {
public:

    void close() // new function for
    { // client use
        db.close();
        closed = true;
    }
~DBConn()
    {
        if (!closed) {
        try { // close the connection
        db.close(); // if the client didn’t
    }
    catch (...) { 
        }
    }
}
private:
    DBConnection db;
    bool closed;
};
```