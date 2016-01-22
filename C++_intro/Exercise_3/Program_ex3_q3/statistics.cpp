#include "statistics.h"

#include <cmath>


//function definitions

double average(double& n1)
{
  
  double average = n1;
  return average;
}

double average(double& n1, double& n2)
{
  double av = 0;
  av = (n1 + n2)/2;
  return av;
}

double average(double& n1, double& n2, double& n3)
{  
  double av = 0;
  av = (n1 + n2 + n3)/3;
  return av;
}

double average(double& n1, double& n2, double& n3, double& n4)
{
  double av = 0;
  av = (n1 + n2 + n3 + n4)/4;
  return av;

}

double stndiv(double& n1)
{
   double av = 0;
   double stndiv = 0;
  
   //call averagefunction
   av = average(n1);
   
   stndiv = sqrt(pow((n1 - av),2)/n1);

   return stndiv;   
  
}

double stndiv(double& n1, double& n2)
{
   double av = 0;
   double stndiv = 0;
  
   //call averagefunction
   av = average(n1,n2);
   
   stndiv = sqrt((pow((n1 - av),2) + pow((n2 - av),2))/(n1 + n2));

   return stndiv;
  
}

double stndiv(double& n1, double& n2, double& n3)
{
   double av = 0;
   double stndiv = 0;
   double variance = 0;
  
   //call averagefunction
   av = average(n1,n2,n3);

   variance = (pow((n1 - av),2) + pow((n2 - av),2) + pow((n3 - av),2))/(n1 + n2 + n3);

   
   stndiv = sqrt(variance);

   return stndiv;
}

double stndiv(double& n1, double& n2, double& n3, double& n4)
{
   double av = 0;
   double stndiv = 0;
   double variance = 0;
  
   //call averagefunction
   av = average(n1,n2,n3);

   variance = (pow((n1 - av),2) + pow((n2 - av),2) + pow((n3 - av),2) + pow((n4 - av),2))/(n1 + n2 + n3 + n4);

   
   stndiv = sqrt(variance);

   return stndiv;
}
