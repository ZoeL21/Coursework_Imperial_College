#include <iostream>
#include <cmath>
#include "WhiteWater.h"

using namespace std;

int main()
{

  int op_numberofpoints = 0;
  int ip_numberofpoints = 0;

  int* array_x_op = new int[op_numberofpoints];
  int* array_y_op = new int[op_numberofpoints];

  int* array_x_ip = new int[ip_numberofpoints];
  int* array_y_ip = new int[ip_numberofpoints];
  double* array_dist = new double[ip_numberofpoints*op_numberofpoints];

  for(int i = 0; i < sizeof(array_dist); i++)
    {
      array_dist[i] = 0;
    }

  //getting input

  cin>>op_numberofpoints;
  cin>>ip_numberofpoints;

  for(int i = 0; i < op_numberofpoints; i++)
    {
      cin>>array_x_op[i]>>array_y_op[i];
    }

for(int i = 0; i < ip_numberofpoints; i++)
    {
      cin>>array_x_ip[i]>>array_y_ip[i];
    }


  //creating the lines between each points
  // create_lines(array_x_op,array_y_op,array_x_ip,array_y_ip);

  //calculating the smallest distance between the lines
  calc_dist(array_x_op,array_y_op,array_x_ip,array_y_ip,array_dist);

  cout<<"smallest distance is: "<<smallest_dist(array_dist)<<endl;

  // saving each line created between the points of the outer polygon
  return 0;
}
