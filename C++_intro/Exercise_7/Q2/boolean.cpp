#include "boolean.h"

using namespace std;

bool smaller(strptr &string1,strptr &string2)
{
  //save original pointer position
  strptr position1 = string1;
  strptr position2 = string2;

  int size1 = 0;
  int size2 = 0;

  for(; *string1 != '\0'; string1++)
    {
      size1 += *string1;
    }

  for(; *string2 != '\0'; string2++)
    {
      size2 += *string2;
    }

  string1 = position1;
  string2 = position2;


  return (size1 < size2) ? (true) : (false);


}
