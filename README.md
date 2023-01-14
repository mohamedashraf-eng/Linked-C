<p align="center">
  <img width="400" height="400" src="https://j.top4top.io/p_2562ucj861.png">
</p>

## About library  
The library is mainly built to reduce the complexity of implementing linked list in c every time user want to use or implement something with it.  
Library is built `compatible` with lower **GCC** versions, easy to be `reusable` and deployed into variant type of projects, also `reliable` and `maintainable`; It has built-in logging functions makes it easy to track the code. The library is also built for small memory size capacity such as **Embedded Systems** based programs. Also worth mentioning that library is `scalable` and `modular` so it can be easily deployed into other data structure such as *Queue*, *Stack*, *Tree* with small complexity to be added.

## How to use the library
First you want to make sure that you have installed:  
```c
1. GCC / MinGW
2. Make
3. CMake
4. IDE / Text Editor
```
If already installed then:  
1. create empty directory
2. Open `cmd/powershell` at the directory
3. Then write
```c
mkdir datastructures_library
cd ./datastructures_library/
git clone https://github.com/mohamedashraf-eng/Linked-C.git
```
4. Create a directory with name `build`
```c
mkdir build
```
5. Then write
```c
cd /build/
CMake -G "MinGW Makefiles" .. 
```
6. to compile & run the `main.c` after modifying it
```c
make
./linkedc.exe
```
Simple main program  
```c
#include <stdio.h>
#include "linked_c.h"

int main(void){
  // Create user status type.
  en_ll_user_status myStatus;
  // Get instance to the sll list.
  sll_class myList = sll_getInstance(&myStatus);
  // Check the returned status.
  if((InstanceCreateSucc == myStatus)){
    /* Everything is right */
    // Insert whatever data 
    // For Ex:
    double myFavNum = 13.32f;
    sll_append(&myList, myFavNum);
    // To output
    printf("\n my favorite number is: %llf", myList->data); // Head data.
  }else{
    /* Something went wrong */
    ; // Error handler function.
  } 

  return 0;
}
```
To turn on the `Detailed User Interface (DUI)` option.  
Set the macro `DETAILED_USER_INTERFACE` to `DUI_ACTIVE` in `linked_c.h`
```c
/**
 * @brief Detailed user interface flag
 * @details The detailed user interface option is used to display all
 *          hidden data in the backend.
 *
 * @defgroup Configuration Parameters
 *    @arg DUI_INACTIVE
 *    @arg DUI_ACTIVE
 */
#define DETAILED_USER_INTERFACE (DUI_ACTIVE)
```

## Credits
[mohamedashraf-eng](https://github.com/mohamedashraf-eng)