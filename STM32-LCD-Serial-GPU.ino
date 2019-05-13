#include <Adafruit_GFX.h>    // Core graphics library
#include <MCUFRIEND_kbv.h>  // LCD Sheild library slightly modified utility\mcufriend_shield.h
#include <DynamicCommandParser.h> 
#include "mandelbrot.h"

// Pinouts TFT STM32bluepill
// Data D0-D7 PA0-PA7
#define LCD_CS PB8 
#define LCD_CD PB7 
#define LCD_WR PB6 
#define LCD_RD PB5 
#define LCD_RESET PB9 

//MCUFRIEND_kbv tft; //moved to mandelbrot.h

// Initialize the data parser using the start, end and delimiting character
DynamicCommandParser dcp('^', '$', ',');

  // Parser for drawRect,x0,y0,w,h,decimal_color
void drawRectParser(char **values, int valueCount)
  {
   if(valueCount >6) {
    Serial.println("Error: drawRectParser: too many variables!");
   }
   if(valueCount <5) {
    Serial.println("Error: drawRectParser: not enough variables!");
   }
   else
   {
    int x0 = String(values[1]).toInt();
    int y0 = String(values[2]).toInt();
    int w = String(values[3]).toInt();
    int h = String(values[4]).toInt();
    int color = String(values[5]).toInt();
    Serial.println("drawRectParser values: x0:" + String(x0) + ", y0:" + String(y0) + ", w:" + String(w) + ", h:" + String(h) + ", color:" + String(color));
    tft.drawRect(x0, y0, w, h, color); //^drawRect,10,10,300,200,65535$
    Serial.println("drawRect: Done!");
   }
  }

  // Parser for fillRect,x0,y0,w,h,decimal_color
void fillRectParser(char **values, int valueCount)
  {
   if(valueCount >6) {
    Serial.println("Error: fillRectParser: too many variables!");
   }
   if(valueCount <5) {
    Serial.println("Error: fillRectParser: not enough variables!");
   }
   else
    {
    int x0 = String(values[1]).toInt();
    int y0 = String(values[2]).toInt();
    int w = String(values[3]).toInt();
    int h = String(values[4]).toInt();
    int color = String(values[5]).toInt();
    Serial.println("fillRectParser values: x0:" + String(x0) + ", y0:" + String(y0) + ", w:" + String(w) + ", h:" + String(h) + ", color:" + String(color));
    tft.fillRect(x0, y0, w, h, color); // ^fillRect,10,10,300,200,WHITE$
    Serial.println("fillRect: Done!");
    }
  }

  // Parser for fillScreen,decimal_color
void fillScreenParser(char **values, int valueCount)
  {
    if(valueCount > 2) {
      Serial.println("Error: fillScreenParser needs one variable");
    }
    if (valueCount < 2) {
      Serial.println("Error: fillScreenParser needs one variable");
    }
    else 
    {
    int color = String(values[1]).toInt();
    Serial.println("fillRectParser values: color:" + String(color));
    tft.fillScreen(color);  // ^fillScreen,1024$
    Serial.println("fillScreen: Done!");
    }
  }

  // Parser for drawCircle,x0,y0,radius,color
void drawCircleParser(char **values, int valueCount)
  {
   if(valueCount >5) {
    Serial.println("Error: drawCircleParser: too many variables!");
   }
   if(valueCount <4) {
    Serial.println("Error: drawCircleParser: not enough variables!");
   }
   else    
    {
    int x0 = String(values[1]).toInt();
    int y0 = String(values[2]).toInt();
    int radius = String(values[3]).toInt();
    int color = String(values[4]).toInt();
    Serial.println("drawCircleParser values: x0:" + String(x0) + ", y0:" + String(y0) + ", radius:" + String(radius) + ", color:" + String(color));
    tft.drawCircle(x0, y0, radius, color); // ^drawCircle,160,120,50,65535$
    Serial.println("drawCircle: Done!");
    }
  }

  // Parser for fillCircle,x0,y0,radius,color
void fillCircleParser(char **values, int valueCount)
  {
   if(valueCount >5) {
    Serial.println("Error: fillCircleParser: too many variables!");
   }
   if(valueCount <4) {
    Serial.println("Error: fillCircleParser: not enough variables!");
   }
   else
    {
    int x0 = String(values[1]).toInt();
    int y0 = String(values[2]).toInt();
    int radius = String(values[3]).toInt();
    int color = String(values[4]).toInt();
    Serial.println("fillCircleParser values: x0:" + String(x0) + ", y0:" + String(y0) + ", radius:" + String(radius) + ", color:" + String(color));
    tft.fillCircle(x0, y0, radius, color); // ^fillCircle,160,120,50,65535$
    Serial.println("fillCircle: Done!");
    }
  }

  // Parser for drawTriangle,x0,y0,x1,y1,x2,y2,color
void drawTriangleParser(char **values, int valueCount)
  {
   if(valueCount >8) {
    Serial.println("Error: drawTriangleParser: too many variables!");
   }
   if(valueCount <7) {
    Serial.println("Error: drawTriangleParser: not enough variables!");
   }
   else
    {
    int x0 = String(values[1]).toInt();
    int y0 = String(values[2]).toInt();
    int x1 = String(values[3]).toInt();
    int y1 = String(values[4]).toInt();
    int x2 = String(values[5]).toInt();
    int y2 = String(values[6]).toInt();
    int color = String(values[7]).toInt();
    Serial.println("drawTriangleParser values: x0:" + String(x0) + ", y0:" + String(y0)  + ", x1:" + String(x1) + ", y1:" + String(y1)  + ", x2:" + String(x2) + ", y2:" + String(y2) + "  color:" + String(color));
    tft.drawTriangle(x0, y0, x1 , y1, x2, y2, color); // ^drawTriangle,10,10,310,10,160,230,65535$
    Serial.println("drawTriangle: Done!");
    }
  }

    // Parser for fillTriangle,x0,y0,x1,y1,x2,y2,color
void fillTriangleParser(char **values, int valueCount)
  {
   if(valueCount >8) {
    Serial.println("Error: fillTriangleParser: too many variables!");
   }
   if(valueCount <7) {
    Serial.println("Error: fillTriangleParser: not enough variables!");
   }
   else
    {
    int x0 = String(values[1]).toInt();
    int y0 = String(values[2]).toInt();
    int x1 = String(values[3]).toInt();
    int y1 = String(values[4]).toInt();
    int x2 = String(values[5]).toInt();
    int y2 = String(values[6]).toInt();
    int color = String(values[7]).toInt();
    Serial.println("fillTriangleParser values: x0:" + String(x0) + ", y0:" + String(y0)  + ", x1:" + String(x1) + ", y1:" + String(y1)  + ", x2:" + String(x2) + ", y2:" + String(y2) + "  color:" + String(color));
    tft.fillTriangle(x0, y0, x1 , y1, x2, y2, color); // ^fillTriangle,10,10,310,10,160,230,65535$
    Serial.println("fillTriangle: Done!");
    }
  }

  //Parser for invertDiaplsy,bool_inv
void invertDisplayParser(char **values, int valueCount)
  {
   if(valueCount >2)
    Serial.println("Error: invertDisplayParser: boolean, 0 or 1!");
   if(valueCount <2)
    Serial.println("Error: invertDisplayParser: not enough variables!");
   else
    {
    bool inv = String(values[1]).toInt();
    Serial.println("invertDisplayParser values: inv: " + String(inv));
    tft.invertDisplay(inv);  //  ^invertDisplay,1$
    Serial.println("invertDisplay: Done!");
    }
  }

  // Parser for drawRoundRect,x0,y0,w,h,radius,decimal_color
void drawRoundRectParser(char **values, int valueCount)
  {
   if(valueCount >7) {
    Serial.println("Error: drawRoundRectParser: too many variables!");
   }
   if(valueCount <6) {
    Serial.println("Error: drawRoundRectParser: not enough variables!");
   }
   else
   {
    int x0 = String(values[1]).toInt();
    int y0 = String(values[2]).toInt();
    int w = String(values[3]).toInt();
    int h = String(values[4]).toInt();
    int radius = String(values[5]).toInt();
    int color = String(values[6]).toInt();
    Serial.println("drawRoundRectParser values: x0:" + String(x0) + ", y0:" + String(y0) + ", w:" + String(w) + ", h:" + String(h) + ", radius:" + String(radius) + ", color:" + String(color));
    tft.drawRoundRect(x0, y0, w, h, radius, color); //  ^drawRoundRect,10,10,300,200,20,65535$
    Serial.println("drawRoundRect: Done!");
   }
  }

  // Parser for fillRoundRect,x0,y0,w,h,radius,decimal_color
void fillRoundRectParser(char **values, int valueCount)
  {
   if(valueCount >7) {
    Serial.println("Error: fillRoundRectParser: too many variables!");
   }
   if(valueCount <6) {
    Serial.println("Error: fillRoundRectParser: not enough variables!");
   }
   else
   {
    int x0 = String(values[1]).toInt();
    int y0 = String(values[2]).toInt();
    int w = String(values[3]).toInt();
    int h = String(values[4]).toInt();
    int radius = String(values[5]).toInt();
    int color = String(values[6]).toInt();
    Serial.println("fillRoundRectParser values: x0:" + String(x0) + ", y0:" + String(y0) + ", w:" + String(w) + ", h:" + String(h) + ", radius:" + String(radius) + ", color:" + String(color));
    tft.fillRoundRect(x0, y0, w, h, radius, color); //  ^fillRoundRect,10,10,300,200,20,65535$
    Serial.println("fillRoundRect: Done!");
   }
  }

  // Parser for mandelbrot
void mandelbrotParser(char **values, int valueCount)
{
  if(valueCount != 1) {
    Serial.println("Error: mandelbrotParser does not like variables");
  }
  else
    {
      Serial.println("mandelbrotParser executing...");
      drawMandelbrot();  // ^mandelbrot$
      Serial.println("mandelbrot: Done!");
    }
}

void setup() {
  Serial.begin(115200);  
  tft.reset();
  Serial.println("STM32-LCD-Serial-GPU!\n");
  uint16_t identifier = tft.readID();  
  Serial.print(F("tft.readID = 0x"));
  Serial.println(identifier, HEX);  // 9341

  tft.begin(identifier);
  
  tft.setRotation(1); 
  tft.fillScreen(0);
  
  Serial.println("\nColor values:");
  Serial.println("Black: 0");
  Serial.println("Blue: 16");
  Serial.println("Red: 63488");
  Serial.println("Green: 1024");
  Serial.println("Cyan: 1040");
  Serial.println("Magenta: 32784");
  Serial.println("Yellow: 65248");
  Serial.println("White: 65535\n");
  
  // Add the two parser commands to the DynamicCommandParser
  dcp.addParser("mandelbrot", mandelbrotParser); 
  dcp.addParser("drawRect", drawRectParser);
  dcp.addParser("fillRect", fillRectParser);
  dcp.addParser("fillScreen", fillScreenParser);
  dcp.addParser("drawCircle", drawCircleParser);
  dcp.addParser("fillCircle", fillCircleParser);
  dcp.addParser("drawTriangle", drawTriangleParser);
  dcp.addParser("fillTriangle", fillTriangleParser);
  dcp.addParser("invertDisplay", invertDisplayParser);
  dcp.addParser("drawRoundRect", drawRoundRectParser);
  dcp.addParser("fillRoundRect", fillRoundRectParser);
  Serial.println("^READY$");
}

void loop() {
  unsigned long start;
  unsigned long finish;

  while(Serial.available() > 0)
  {
    dcp.appendChar(Serial.read());
  }
}
