# STM32-LCD-Serial-GPU
STM32 bluepill with 8bit parallel shield, serial parsing. Basic GPU to use with another MCU, or serial console

Compatable with MCUFriend commands.

## Requires:

MCUFriend_kbv library with modified utility\mcufriend_shield.h 
https://github.com/WacKEDmaN/MCUFRIEND_kbv

DynamicCommandParser library 
https://github.com/WacKEDmaN/DynamicCommandParser


## Commands implemented:

^mandelbrot$

^drawRect,x0,y0,h,w,color$   x0,y0=top left, h=height,w=width, all color values must be added as decimal values

^fillRect,x0,y0,h,w,color$

^fillScreen,color$

^drawCircle,x0,y0,radius,color$   x0,y0=centre 

^fillCircle,x0,y0,radius,color$

^drawTriangle,x0,y0,1,y1,x2,y2,color$  x0,y0=corner 1  x1,y1=corner 2  x2,y2=corner 3

^fillTriangle,x0,y0,1,y1,x2,y2,color$

^invertDisplay,0-1$  

^drawRoundRect,x0,y0,h,w,radius,color$  

^fillRoundRect,x0,y0,h,w,radius,color$

^setTextColor,color,bgcolor$   bgcolor must be added

^print,text$  text in a string w/o ',' string ends at $

^println,text$ 

^setCursor,col,row$  

^setTextSize,size$

^setRotation,0-3$

^drawPixel,x0,y0,color$

^readPixel,x0,y0$  returns color value

^drawLine,x0,y0,x1,y1,color$ 
