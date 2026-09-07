# Item 2 prefer const, enum and inline to #define

  ## When replacing `#defines` with constants, two special cases are worth mentioning:
 ### Case 1: const pointer
  The first is defining constant pointers. Because constant definitions are typically put in header files (where many different source files will include them), it’s important that the pointer be declared const 

> [!NOTE]  
it’s worth reminding you here that string objects are generally preferable to their char*-based

### Case 2: class-specific constant of static intergral type
 ```cpp 
 class GamePlayer {
private:
static const int NumTurns = 5; // constant declaration
int scores[NumTurns]; // use of constant
};
```
>What you see above is a declaration for `NumTurns`, not a definition.
Usually, C++ requires that you provide a **definition** for anything you
use ,but that is an exception when we deal with static integral type in class
```cpp
#include <iostream>
using namespace std;

class gameplayer {
	static const std::string x;
};

const std::string gameplayer::x { "mina" };

```
As you can see, we change the data type to `std::string` , so we can't apply this rule, we need to give a defination for `x` outside the class.
> [!NOTE] enum hack
```cpp
class GamePlayer {
private:
enum { NumTurns = 5 }; // “the enum hack” — makes NumTurns a symbolic name  which is friendly in debugging.
int scores[NumTurns]; 
};
```
> [!caution]
> 1. For simple constants, prefer const objects or enums to #defines.
> 2. For function-like macros, prefer inline functions to #defines


