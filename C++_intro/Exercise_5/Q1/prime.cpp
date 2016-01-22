#include "prime.h"
#include <cmath>
//function definition

bool prime(int val)
{
  if(val > 999 || val < 2)
    {
      return false;
    }

  
  //test if val is even and not 2
  if(val != 2 && (val % 2) == 0)
    {
      return false;
    }
  //divide by all intergers lower than val
  for(int i = 3; i < val; i++)
    {
      if((val % i) == 0)
	{
          return false;
	}
    }
  //must be a prime number
  return true;

}
