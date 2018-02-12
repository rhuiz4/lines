#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);

  int i = 1000;
  int x = 0;
  int y = 0;
  while (i >= 0){
    if (x == 0){
      draw_line(250,250,x,y,s,c);
      y += 2;
    }
    if (y == 500){
      draw_line(250,250,x,y,s,c);
      x += 2;
    }
    if (x == 500){
      draw_line(250,250,x,y,s,c);
      y -= 2;
    }
    if (y == 0){
      draw_line(250,250,x,y,s,c);
      x -= 2;
    }

    if (c.red < 255 && c.green > 0 && c.blue == 0){
      c.red = c.red + 3;
      c.green = c.green - 3;
    }
    else if(c.blue < 255 && c.red > 0 && c.green == 0){
      c.blue = c.blue + 3;
      c.red = c.red - 3;
    }
    else{
      c.green = c.green + 3;
      c.blue = c.blue - 3;
    }
    i--;      
    
  }

  //scrapped design
  /*
  int i = 500;
  
  int x = 250;
  int y = 0;

  while (i >= 0){
    if (y < 250 && x <= 250){
      draw_line(0,0,x,y,s,c);
      x -= 2;
      y += 2;
    }
    else if (y >= 250 && x < 250){
      draw_line(0,500,x,y,s,c);
      x += 2;
      y += 2;
    }
    else if (y > 250 && x >= 250){
      draw_line(500,500,x,y,s,c);
      x += 2;
      y -= 2;
    }
    else{
      draw_line(500,0,x,y,s,c);
      x -= 2;
      y -= 2;
    }
    
    if (c.red < 255 && c.green > 0 && c.blue == 0){
      c.red = c.red + 3;
      c.green = c.green - 3;
    }
    else if(c.blue < 255 && c.red > 0 && c.green == 0){
      c.blue = c.blue + 3;
      c.red = c.red - 3;
    }
    else{
      c.green = c.green + 3;
      c.blue = c.blue - 3;
    }
    
    i--;
  }


  
  int sx0 = 250;
  int sy0 = 350;
  int sx1 = 250;
  int sy1 = 350;
  int j = 200;
  c.red = 0;
  c.green = MAX_COLOR*3/4;
  c.blue = MAX_COLOR;
  while (j >= 0){
    if(sy0 >= 250){
      draw_line(sx0,sy0,sx1,sy1,s,c);
      sx0--;
      sx1++;
      sy0--;
      sy1--;
    }
    else{
      draw_line(sx0,sy0,sx1,sy1,s,c);
      sx0++;
      sx1--;
      sy0--;
      sy1--;

    }
    c.blue--;
    c.red++;
    j--;
  }
  */
    /*
  //test
  //Q1
  draw_line(250,250,500,300,s,c);
  draw_line(250,250,500,400,s,c);
  draw_line(250,250,500,500,s,c);
  draw_line(250,250,400,500,s,c);
  draw_line(250,250,300,500,s,c);

  //Q2
  draw_line(250,250,0,300,s,c);
  draw_line(250,250,0,400,s,c);
  draw_line(250,250,0,500,s,c);
  draw_line(250,250,100,500,s,c);
  draw_line(250,250,200,500,s,c);

  //Q3
  draw_line(250,250,0,200,s,c);
  draw_line(250,250,0,100,s,c);
  draw_line(250,250,0,0,s,c);
  draw_line(250,250,100,0,s,c);
  draw_line(250,250,200,0,s,c);
  
  //Q4
  draw_line(250,250,500,200,s,c);
  draw_line(250,250,500,100,s,c);
  draw_line(250,250,500,0,s,c);
  draw_line(250,250,400,0,s,c);
  draw_line(250,250,300,0,s,c);
  */  

  display(s);
  save_extension(s, "lines.png");
}
