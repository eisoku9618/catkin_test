#include "child/fuga.h"
#include <parent/hoge.h>
#include <iostream>

Fuga::Fuga()
{
  Hoge my_hoge;
  std::cout << "Fuga Constructor is called" << std::endl;
}
