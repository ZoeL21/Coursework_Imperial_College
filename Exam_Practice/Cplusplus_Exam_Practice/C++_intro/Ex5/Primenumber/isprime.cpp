#include "isprime.h"

bool isprime(int number){
  //if its a one it's not a prime
  if(number == 1){
    return false;
  }
  //if can divide by 2, its not a prime
  if(number % 2 == 0){
    return false;
  }
  //divide by every number between number-1 and 1
  for(int i = (number - 1);i>1;i--){
    if(number % i == 0){
      return false;
    }
  }

  //otherwise the number must be prime
  return true;
}
