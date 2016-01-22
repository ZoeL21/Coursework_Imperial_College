#include "WhiteWater.h"
#include <cmath>
#include <algorithm>

using namespace std;

/*
int* create_lines(int* array_x_op[],int* array_y_op[],int* array_x_ip[],int* array_y_ip[])
{

  //create all lines between the inner polygon and store them inside an array
int lines_in[]

} */


void calc_dist(int array_x_op[],int array_y_op[],int array_x_ip[],int array_y_ip[],double array_dist[])
{

  int index = 0;
  for(unsigned int i = 0; i < sizeof(array_x_op); i++)
    {
      for(unsigned int j = 0; j < sizeof(array_y_op); j++)
	{
	  int diff_X = pow((array_x_op[i]-array_x_ip[j]),2);
          int diff_Y = pow((array_y_op[i]-array_y_ip[j]),2);
	  array_dist[index] = sqrt(diff_X + diff_Y);
	  index++;

	}
    }

}

double smallest_dist(double array_dist[])
{
  int small = 0;

  for(int i = 0; i < (sizeof(array_dist) - 1); i++)
    {
      if(array_dist[i] < array_dist[i+1])
	{
	  small = array_dist[i];
	}
    }
      return small;
 
 }
