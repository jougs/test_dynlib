
#include "func.h"
#include <iostream>

#include <ltdl.h>

int x = 10;

int main()
{
  typedef int (*func_t)(int);
  func_t FUNC = *func;

  std::cout << "func(5) via function pointer yields " << FUNC(5) << std::endl;

  lt_dlinit();
  lt_dlhandle handle = lt_dlopen("./libtwo.so");

  if (not handle)
  {
    std::cout << lt_dlerror() << std::endl;
  }
  std::cout << "successfully dlopen'ed libtwo.so" << std::endl;

  std::cout << "func(5) via function pointer yields" << FUNC(5) << std::endl;

  std::cout << "resetting function pointer using symbol from libtwo.so" << std::endl;
  FUNC = (func_t) lt_dlsym(handle, "func");
  std::cout << "func(5) via function pointer yields" << FUNC(5) << std::endl;

  return 0;
}
