#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"


void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  
  int x = x0;
  int y = y0;
  
  //if (x0,y0) is to the right of (x1,y1) then switch
  if (x0 > x1){
    x = x1;
    x1 = x0;
    
    y = y1;
    y1 = y0;
    
  }
  
  int A = y1 - y;
  int B = x - x1;
  
  //float  slope = (float)A/B * -1;
  
  //Octant 2                                                                                                                                                                                              
  if (A > 0 && A >= -B){//slope >= 1 || (!B && y1 > y0)){
    int d = A + 2 * B;
    while (y <= y1){
      plot (s, c, x, y);
      if (d < 0){
	x++;
	d += 2 * A;
    }
      y++;
      d += 2 * B;
    }
  }

  //Octant 1
  else if (A >= 0 && A < -B){//slope >= 0 && slope < 1 && B){
    int d = 2 * A + B;
    while (x <= x1){
      plot(s, c, x, y);
      if (d > 0){
	y++;
	d += 2 * B;
     }
      x++;
      d += 2 * A;
    }
  }
  
  //Octant 8
  else if (A < 0 && A >= B){//slope >= -1 && slope < 0 && B){
    int d = 2 * A - B;
    while (x <= x1){
      plot(s, c, x, y);
      if (d < 0){
	y--;
	d -= 2 * B;
      }
      x++;
      d += 2 * A;
    }
  }

  //Octant 7
  else{
    int d = A - 2 * B;
    while (y >= y1){
      plot(s, c, x, y);
      if (d > 0){
     	x++;
        d += 2 * A;
      } 
      y--;
      d	-= 2 * B;
    }
  }
}
