#include <iostream>
using namespace std;

#include "factorial.h"

/* IMPLEMENT Factorial() HERE */
int Factorial(int n)
{
  if(n <= 0)
  {
    return 1;
  }
  else
  {
    return (n * Factorial(n-1));
  }
}
    
  
