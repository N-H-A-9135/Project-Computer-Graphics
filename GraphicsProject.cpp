#include <graphics.h>
#include <iostream>
#include <cmath>
#include<math.h>
#include<dos.h>
#include <time.h>

using namespace std;
void drawLine(int x0, int y0, int x1, int y1)//Bresenham's Line Drawing Algorithm
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    while (true)
    {
        putpixel(x0, y0, WHITE);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
        delay(10);
    }
}

void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2)//Bresenham's Line Drawing Algorithm
{
    drawLine(x0, y0, x1, y1);
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x0, y0);
}
void dda(int x1, int y1, int x2, int y2)// Digital Differential Analyzer (DDA) Algorithm
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;
    if (abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }
    float xinc = dx / (float)steps;
    float yinc = dy / (float)steps;
    float x = x1;
    float y = y1;
    for (int i = 0; i < steps; i++)
    {
        putpixel(round(x), round(y), WHITE);
        x += xinc;
        y += yinc;
        delay(10);
    }
}

void drawCircle(int xc, int yc, int r) //Midpoint Circle Algorithm
{
    int x = 0, y = r;
    int d = 1 - r;
    while (x <= y)
    {
        // plot eight symmetric points
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        x++;
        if (d < 0)
            d += 2 * x + 1;
        else
        {
            y--;
            d += 2 * (x - y) + 1;
        }
        delay(10);
    }
}
void drawTree(int x1, int y1, int angle, int depth) //Fractal Tree
{
    if (depth == 0) return;

    int x2 = x1 + (int)(cos(angle * M_PI / 180) * depth * 10.0);
    int y2 = y1 + (int)(sin(angle * M_PI / 180) * depth * 10.0);

    line(x1, y1, x2, y2);

    drawTree(x2, y2, angle - 20, depth - 1);
    drawTree(x2, y2, angle + 20, depth - 1);
}

//Solar System
const int WIDTH = 640; // width of graphics window
const int HEIGHT = 480; // height of graphics window
const int SUN_RADIUS = 50; // radius of sun
const int EARTH_RADIUS = 10; // radius of earth
const int MOON_RADIUS = 5; // radius of moon
const int EARTH_ORBIT_RADIUS = 150; // radius of earth's orbit
const int MOON_ORBIT_RADIUS = 30; // radius of moon's orbit
const int SUN_X = WIDTH / 2; // x-coordinate of sun
const int SUN_Y = HEIGHT / 2; // y-coordinate of sun
const double PI = 3.14159; // value of pi

void drawSun()
{
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(SUN_X, SUN_Y, SUN_RADIUS);
    floodfill(SUN_X, SUN_Y, YELLOW);
}

void drawEarth(int x, int y)
{
    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    circle(x, y, EARTH_RADIUS);
    floodfill(x, y, BLUE);
}

void drawMoon(int x, int y)
{
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    circle(x, y, MOON_RADIUS);
    floodfill(x, y, LIGHTGRAY);
}
//Solar System

int main()
{

    int Graphics;
    cout<<"\t\t\tName:Nayem Hasan Arman \n\t\t\tId:CSE2001019135\n\n";
    cout<<"\t\tInventory of Content & Functions*\n";
    cout<<"\n1.Triangle drawing using Bresenham's Line Drawing Algorithm*\n";
    cout<<"\n2.Rectangle drawing using Digital Differential Analyzer (DDA) Algorithm*\n";
    cout<<"\n3.Circle drawing using Midpoint Circle Algorithm Algorithm*\n";
    cout<<"\n4.Fractal Tree drawing using Geometrical Equation*\n";
    cout<<"\n5.Drawing of rectangle,circle,triangle filled with color*\n";
    cout<<"\n6.Drawing of  static cargo ship**\n";
    cout<<"\n7.Implementation of DigitalClock*\n";
    cout<<"\n8.Drawing of capital letters A-Z****\n";
    cout<<"\n9.Drawing of  static solar system**\n";
    cout<<"\n10.Drawing of a village***\n";
    cout<<"\n11.Drawing of dynamic solar system****\n";
    cout<<"\n12.Drawing of dynamic submarine***\n\n";

    cout << "Enter a number between 1 and 12: ";
    cin >> Graphics;

    switch(Graphics)
    {
    case 1:                          //Bresenham's Line Drawing Algorithm
    {

        int gd = DETECT, gm;
        initgraph(&gd, &gm, "");
        int x0=100, y0=300, x1=300, y1=300, x2=200, y2=100;
        drawTriangle(x0, y0, x1, y1, x2, y2);

        line(10,10,10,40);//n
        line(20,10,20,40);
        line(10,10,20,40);
        line(30,10,40,40);//a
        line(20,40,30,10);//a
        line(24,30,37,30);
        line(40,10,48,20);//Y
        line(48,20,55,10);
        line(48,20,48,40);
        line(60,10,60,40);//e
        line(60,10,80,10);
        line(60,25,75,25);
        line(60,40,80,40);
        line(90,10,90,40);//m
        line(110,10,110,40);
        line(90,10,100,40);
        line(100,40,110,10);

        line(125,10,125,40);//h
        line(135,10,135,40);
        line(125,20,135,20);

        line(150,10,140,40);//a
        line(150,10,160,40);
        line(145,25,155,25);

        line(165,10,175,10);//s
        line(165,10,165,25);
        line(165,25,175,25);
        line(175,25,175,40);
        line(165,40,175,40);

        line(180,40,185,10);//a
        line(185,10,190,40);
        line(183,25,188,25);

        line(200,10,200,40);//n
        line(200,10,210,40);
        line(210,10,210,40);

        line(230,40,240,10);//a
        line(240,10,250,40);
        line(234,25,247,25);

        line(260,10,260,40);//r
        line(260,10,270,10);
        line(270,10,270,25);
        line(260,25,270,25);
        line(260,25,270,40);

        line(280,10,280,40);//m
        line(280,10,290,40);
        line(290,40,300,10);
        line(300,10,300,40);

        line(310,40,320,10);//a
        line(320,10,330,40);
        line(314,25,327,25);

        line(340,10,340,40);//n
        line(340,10,360,40);
        line(360,10,360,40);

        rectangle(366,35,370,40);//dot

        line(380,10,380,40);//i
        line(375,10,385,10);
        line(375,40,385,40);

        line(390,10,390,40);//d
        ellipse(390,25,270,90,15,15);

        rectangle(410,10,415,15);//dot
        rectangle(410,35,415,40);//dot

        ellipse(435,25,90,270,15,15);//c

        line(440,10,450,10);//s
        line(440,10,440,25);
        line(440,25,450,25);
        line(450,25,450,40);
        line(440,40,450,40);

        line(455,10,455,40);//e
        line(455,10,465,10);
        line(455,25,465,25);
        line(455,40,465,40);

        line(470,10,480,10);//2
        line(480,10,480,25);
        line(470,25,480,25);
        line(470,25,470,40);
        line(470,40,480,40);

        ellipse(490,25,0,360,10,17);//0
        ellipse(508,25,0,360,10,17);//0

        line(525,10,525,40);//1
        line(521,13,525,10);
        line(521,40,529,40);

        ellipse(540,25,0,360,10,17);//0


        line(555,10,555,40);//1
        line(551,13,555,10);
        line(551,40,559,40);

        ellipse(565,15,0,360,7,7);//9
        ellipse(565,25,270,90,10,17);//9

        line(580,10,580,40);//1
        line(576,13,580,10);
        line(576,40,584,40);

        ellipse(595,17,260,100,8,8);//3
        ellipse(595,33,260,100,8,8);

        line(610,10,610,26);//5
        line(610,10,620,10);
        ellipse(610,33,260,100,11,8);

        getch();
        closegraph();


    }
    break;
    case 2:                               // Digital Differential Analyzer (DDA) Algorithm
    {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, "");


        int x1 = 100, y1 = 100;
        int x2 = 200, y2 = 300;
        int x3 = 300, y3 = 150;
        int x4 = 200, y4 = 400;

        dda(x1, y1, x3, y1);
        dda(x1, y1, x1, y2);
        dda(x1, y2, x3, y2);
        dda(x3, y2, x3, y1);

        line(10,10,10,40);//n
        line(20,10,20,40);
        line(10,10,20,40);
        line(30,10,40,40);//a
        line(20,40,30,10);//a
        line(24,30,37,30);
        line(40,10,48,20);//Y
        line(48,20,55,10);
        line(48,20,48,40);
        line(60,10,60,40);//e
        line(60,10,80,10);
        line(60,25,75,25);
        line(60,40,80,40);
        line(90,10,90,40);//m
        line(110,10,110,40);
        line(90,10,100,40);
        line(100,40,110,10);

        line(125,10,125,40);//h
        line(135,10,135,40);
        line(125,20,135,20);

        line(150,10,140,40);//a
        line(150,10,160,40);
        line(145,25,155,25);

        line(165,10,175,10);//s
        line(165,10,165,25);
        line(165,25,175,25);
        line(175,25,175,40);
        line(165,40,175,40);

        line(180,40,185,10);//a
        line(185,10,190,40);
        line(183,25,188,25);

        line(200,10,200,40);//n
        line(200,10,210,40);
        line(210,10,210,40);

        line(230,40,240,10);//a
        line(240,10,250,40);
        line(234,25,247,25);

        line(260,10,260,40);//r
        line(260,10,270,10);
        line(270,10,270,25);
        line(260,25,270,25);
        line(260,25,270,40);

        line(280,10,280,40);//m
        line(280,10,290,40);
        line(290,40,300,10);
        line(300,10,300,40);

        line(310,40,320,10);//a
        line(320,10,330,40);
        line(314,25,327,25);

        line(340,10,340,40);//n
        line(340,10,360,40);
        line(360,10,360,40);

        rectangle(366,35,370,40);//dot

        line(380,10,380,40);//i
        line(375,10,385,10);
        line(375,40,385,40);

        line(390,10,390,40);//d
        ellipse(390,25,270,90,15,15);

        rectangle(410,10,415,15);//dot
        rectangle(410,35,415,40);//dot

        ellipse(435,25,90,270,15,15);//c

        line(440,10,450,10);//s
        line(440,10,440,25);
        line(440,25,450,25);
        line(450,25,450,40);
        line(440,40,450,40);

        line(455,10,455,40);//e
        line(455,10,465,10);
        line(455,25,465,25);
        line(455,40,465,40);

        line(470,10,480,10);//2
        line(480,10,480,25);
        line(470,25,480,25);
        line(470,25,470,40);
        line(470,40,480,40);

        ellipse(490,25,0,360,10,17);//0
        ellipse(508,25,0,360,10,17);//0

        line(525,10,525,40);//1
        line(521,13,525,10);
        line(521,40,529,40);

        ellipse(540,25,0,360,10,17);//0


        line(555,10,555,40);//1
        line(551,13,555,10);
        line(551,40,559,40);

        ellipse(565,15,0,360,7,7);//9
        ellipse(565,25,270,90,10,17);//9

        line(580,10,580,40);//1
        line(576,13,580,10);
        line(576,40,584,40);

        ellipse(595,17,260,100,8,8);//3
        ellipse(595,33,260,100,8,8);

        line(610,10,610,26);//5
        line(610,10,620,10);
        ellipse(610,33,260,100,11,8);


        getch();
        closegraph();

    }
    break;
    case 3:                                  //Midpoint Circle Algorithm
    {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, "");

        int xc = 250, yc = 250, r = 100;
        drawCircle(xc, yc, r);

        line(10,10,10,40);//n
        line(20,10,20,40);
        line(10,10,20,40);
        line(30,10,40,40);//a
        line(20,40,30,10);//a
        line(24,30,37,30);
        line(40,10,48,20);//Y
        line(48,20,55,10);
        line(48,20,48,40);
        line(60,10,60,40);//e
        line(60,10,80,10);
        line(60,25,75,25);
        line(60,40,80,40);
        line(90,10,90,40);//m
        line(110,10,110,40);
        line(90,10,100,40);
        line(100,40,110,10);

        line(125,10,125,40);//h
        line(135,10,135,40);
        line(125,20,135,20);

        line(150,10,140,40);//a
        line(150,10,160,40);
        line(145,25,155,25);

        line(165,10,175,10);//s
        line(165,10,165,25);
        line(165,25,175,25);
        line(175,25,175,40);
        line(165,40,175,40);

        line(180,40,185,10);//a
        line(185,10,190,40);
        line(183,25,188,25);

        line(200,10,200,40);//n
        line(200,10,210,40);
        line(210,10,210,40);

        line(230,40,240,10);//a
        line(240,10,250,40);
        line(234,25,247,25);

        line(260,10,260,40);//r
        line(260,10,270,10);
        line(270,10,270,25);
        line(260,25,270,25);
        line(260,25,270,40);

        line(280,10,280,40);//m
        line(280,10,290,40);
        line(290,40,300,10);
        line(300,10,300,40);

        line(310,40,320,10);//a
        line(320,10,330,40);
        line(314,25,327,25);

        line(340,10,340,40);//n
        line(340,10,360,40);
        line(360,10,360,40);

        rectangle(366,35,370,40);//dot

        line(380,10,380,40);//i
        line(375,10,385,10);
        line(375,40,385,40);

        line(390,10,390,40);//d
        ellipse(390,25,270,90,15,15);

        rectangle(410,10,415,15);//dot
        rectangle(410,35,415,40);//dot

        ellipse(435,25,90,270,15,15);//c

        line(440,10,450,10);//s
        line(440,10,440,25);
        line(440,25,450,25);
        line(450,25,450,40);
        line(440,40,450,40);

        line(455,10,455,40);//e
        line(455,10,465,10);
        line(455,25,465,25);
        line(455,40,465,40);

        line(470,10,480,10);//2
        line(480,10,480,25);
        line(470,25,480,25);
        line(470,25,470,40);
        line(470,40,480,40);

        ellipse(490,25,0,360,10,17);//0
        ellipse(508,25,0,360,10,17);//0

        line(525,10,525,40);//1
        line(521,13,525,10);
        line(521,40,529,40);

        ellipse(540,25,0,360,10,17);//0


        line(555,10,555,40);//1
        line(551,13,555,10);
        line(551,40,559,40);

        ellipse(565,15,0,360,7,7);//9
        ellipse(565,25,270,90,10,17);//9

        line(580,10,580,40);//1
        line(576,13,580,10);
        line(576,40,584,40);

        ellipse(595,17,260,100,8,8);//3
        ellipse(595,33,260,100,8,8);

        line(610,10,610,26);//5
        line(610,10,620,10);
        ellipse(610,33,260,100,11,8);

        getch();
        closegraph();

    }
    break;

    case 4:                                        //Fractal Tree:
    {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, "");

        initwindow(800, 600, "Fractal Tree");

        setcolor(GREEN);
        drawTree(400, 550, -90, 10);

        getch();
        closegraph();
        return 0;

        line(10,10,10,40);//n
        line(20,10,20,40);
        line(10,10,20,40);
        line(30,10,40,40);//a
        line(20,40,30,10);//a
        line(24,30,37,30);
        line(40,10,48,20);//Y
        line(48,20,55,10);
        line(48,20,48,40);
        line(60,10,60,40);//e
        line(60,10,80,10);
        line(60,25,75,25);
        line(60,40,80,40);
        line(90,10,90,40);//m
        line(110,10,110,40);
        line(90,10,100,40);
        line(100,40,110,10);

        line(125,10,125,40);//h
        line(135,10,135,40);
        line(125,20,135,20);

        line(150,10,140,40);//a
        line(150,10,160,40);
        line(145,25,155,25);

        line(165,10,175,10);//s
        line(165,10,165,25);
        line(165,25,175,25);
        line(175,25,175,40);
        line(165,40,175,40);

        line(180,40,185,10);//a
        line(185,10,190,40);
        line(183,25,188,25);

        line(200,10,200,40);//n
        line(200,10,210,40);
        line(210,10,210,40);

        line(230,40,240,10);//a
        line(240,10,250,40);
        line(234,25,247,25);

        line(260,10,260,40);//r
        line(260,10,270,10);
        line(270,10,270,25);
        line(260,25,270,25);
        line(260,25,270,40);

        line(280,10,280,40);//m
        line(280,10,290,40);
        line(290,40,300,10);
        line(300,10,300,40);

        line(310,40,320,10);//a
        line(320,10,330,40);
        line(314,25,327,25);

        line(340,10,340,40);//n
        line(340,10,360,40);
        line(360,10,360,40);

        rectangle(366,35,370,40);//dot

        line(380,10,380,40);//i
        line(375,10,385,10);
        line(375,40,385,40);

        line(390,10,390,40);//d
        ellipse(390,25,270,90,15,15);

        rectangle(410,10,415,15);//dot
        rectangle(410,35,415,40);//dot

        ellipse(435,25,90,270,15,15);//c

        line(440,10,450,10);//s
        line(440,10,440,25);
        line(440,25,450,25);
        line(450,25,450,40);
        line(440,40,450,40);

        line(455,10,455,40);//e
        line(455,10,465,10);
        line(455,25,465,25);
        line(455,40,465,40);

        line(470,10,480,10);//2
        line(480,10,480,25);
        line(470,25,480,25);
        line(470,25,470,40);
        line(470,40,480,40);

        ellipse(490,25,0,360,10,17);//0
        ellipse(508,25,0,360,10,17);//0

        line(525,10,525,40);//1
        line(521,13,525,10);
        line(521,40,529,40);

        ellipse(540,25,0,360,10,17);//0


        line(555,10,555,40);//1
        line(551,13,555,10);
        line(551,40,559,40);

        ellipse(565,15,0,360,7,7);//9
        ellipse(565,25,270,90,10,17);//9

        line(580,10,580,40);//1
        line(576,13,580,10);
        line(576,40,584,40);

        ellipse(595,17,260,100,8,8);//3
        ellipse(595,33,260,100,8,8);

        line(610,10,610,26);//5
        line(610,10,620,10);
        ellipse(610,33,260,100,11,8);

        getch();
        closegraph();

    }
    break;
    case 5:                                    //Draw rectangle,circle,triangle filled with color
    {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, "");
        initwindow(1080,720,"Arman");


// Draw a rectangle filled with color
        setcolor(BLUE);
        setfillstyle(SOLID_FILL, YELLOW);
        rectangle(450, 350, 600, 450);
        floodfill(500, 360, BLUE);

        // Draw a circle filled with color
        setcolor(RED);
        setfillstyle(SOLID_FILL, GREEN);
        circle(525,300, 50);
        floodfill(530,300, RED);

        // Draw a triangle filled with color
        setcolor(CYAN);
        setfillstyle(SOLID_FILL, CYAN);


        line(475,250,575,250);
        line(575,250,525,150);
        line(525,150,475,250);

        floodfill(525,200,CYAN );

        getch();
        closegraph();


    }
    break;

    case 6:                                    //cargo ship

    {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, "");
        initwindow(1980,720,"Arman");

        line(100,250,200,350);//st down
        line(100,250,250,250);
        line(250,250,330,350);
        line(200,350,290,450);
        line(290,450,880,450);
        line(200,350,900,350);
        line(900,350,900,400);
        line(850,400,900,400);
        line(850,400,850,450);

        circle(880,450,10);//fan
        circle(880,440,10);
        circle(890,450,10);
        circle(880,460,10);//fan


        rectangle(350,200,750,350);//st1 up
        line(400,200,400,350);
        line(350,250,750,250);
        line(450,200,450,350);
        line(350,300,750,300);
        line(500,200,500,350);
        line(550,200,550,350);
        line(600,200,600,350);
        line(650,200,650,350);
        line(700,200,700,350);
        rectangle(800,150,900,350);//st up
        line(800,200,900,200);
        line(800,250,900,250);
        line(800,300,900,300);
        line(760,150,800,200);
        line(760,150,800,150);
        rectangle(880,130,900,150);


        line(10,10,10,40);//n
        line(20,10,20,40);
        line(10,10,20,40);
        line(30,10,40,40);//a
        line(20,40,30,10);//a
        line(24,30,37,30);
        line(40,10,48,20);//Y
        line(48,20,55,10);
        line(48,20,48,40);
        line(60,10,60,40);//e
        line(60,10,80,10);
        line(60,25,75,25);
        line(60,40,80,40);
        line(90,10,90,40);//m
        line(110,10,110,40);
        line(90,10,100,40);
        line(100,40,110,10);

        line(125,10,125,40);//h
        line(135,10,135,40);
        line(125,20,135,20);

        line(150,10,140,40);//a
        line(150,10,160,40);
        line(145,25,155,25);

        line(165,10,175,10);//s
        line(165,10,165,25);
        line(165,25,175,25);
        line(175,25,175,40);
        line(165,40,175,40);

        line(180,40,185,10);//a
        line(185,10,190,40);
        line(183,25,188,25);

        line(200,10,200,40);//n
        line(200,10,210,40);
        line(210,10,210,40);

        line(230,40,240,10);//a
        line(240,10,250,40);
        line(234,25,247,25);

        line(260,10,260,40);//r
        line(260,10,270,10);
        line(270,10,270,25);
        line(260,25,270,25);
        line(260,25,270,40);

        line(280,10,280,40);//m
        line(280,10,290,40);
        line(290,40,300,10);
        line(300,10,300,40);

        line(310,40,320,10);//a
        line(320,10,330,40);
        line(314,25,327,25);

        line(340,10,340,40);//n
        line(340,10,360,40);
        line(360,10,360,40);

        rectangle(366,35,370,40);//dot

        line(380,10,380,40);//i
        line(375,10,385,10);
        line(375,40,385,40);

        line(390,10,390,40);//d
        ellipse(390,25,270,90,15,15);

        rectangle(410,10,415,15);//dot
        rectangle(410,35,415,40);//dot

        ellipse(435,25,90,270,15,15);//c

        line(440,10,450,10);//s
        line(440,10,440,25);
        line(440,25,450,25);
        line(450,25,450,40);
        line(440,40,450,40);

        line(455,10,455,40);//e
        line(455,10,465,10);
        line(455,25,465,25);
        line(455,40,465,40);

        line(470,10,480,10);//2
        line(480,10,480,25);
        line(470,25,480,25);
        line(470,25,470,40);
        line(470,40,480,40);

        ellipse(490,25,0,360,10,17);//0
        ellipse(508,25,0,360,10,17);//0

        line(525,10,525,40);//1
        line(521,13,525,10);
        line(521,40,529,40);

        ellipse(540,25,0,360,10,17);//0


        line(555,10,555,40);//1
        line(551,13,555,10);
        line(551,40,559,40);

        ellipse(565,15,0,360,7,7);//9
        ellipse(565,25,270,90,10,17);//9

        line(580,10,580,40);//1
        line(576,13,580,10);
        line(576,40,584,40);

        ellipse(595,17,260,100,8,8);//3
        ellipse(595,33,260,100,8,8);

        line(610,10,610,26);//5
        line(610,10,620,10);
        ellipse(610,33,260,100,11,8);



        getch();
        closegraph();
    }
    break;
    case 7:
    {
        int gd=DETECT, gm, i, x, y;
        initgraph(&gd, &gm, "");
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);

        while (1)
        {


            time_t now = time(NULL);
            struct tm *local = localtime(&now);
            char time_str[9];
            sprintf(time_str, "%02d:%02d:%02d", local->tm_hour, local->tm_min, local->tm_sec);

            outtextxy(100, 100, time_str);
            line(10,10,10,40);//n
            line(20,10,20,40);
            line(10,10,20,40);
            line(30,10,40,40);//a
            line(20,40,30,10);//a
            line(24,30,37,30);
            line(40,10,48,20);//Y
            line(48,20,55,10);
            line(48,20,48,40);
            line(60,10,60,40);//e
            line(60,10,80,10);
            line(60,25,75,25);
            line(60,40,80,40);
            line(90,10,90,40);//m
            line(110,10,110,40);
            line(90,10,100,40);
            line(100,40,110,10);

            line(125,10,125,40);//h
            line(135,10,135,40);
            line(125,20,135,20);

            line(150,10,140,40);//a
            line(150,10,160,40);
            line(145,25,155,25);

            line(165,10,175,10);//s
            line(165,10,165,25);
            line(165,25,175,25);
            line(175,25,175,40);
            line(165,40,175,40);

            line(180,40,185,10);//a
            line(185,10,190,40);
            line(183,25,188,25);

            line(200,10,200,40);//n
            line(200,10,210,40);
            line(210,10,210,40);

            line(230,40,240,10);//a
            line(240,10,250,40);
            line(234,25,247,25);

            line(260,10,260,40);//r
            line(260,10,270,10);
            line(270,10,270,25);
            line(260,25,270,25);
            line(260,25,270,40);

            line(280,10,280,40);//m
            line(280,10,290,40);
            line(290,40,300,10);
            line(300,10,300,40);

            line(310,40,320,10);//a
            line(320,10,330,40);
            line(314,25,327,25);

            line(340,10,340,40);//n
            line(340,10,360,40);
            line(360,10,360,40);

            rectangle(366,35,370,40);//dot

            line(380,10,380,40);//i
            line(375,10,385,10);
            line(375,40,385,40);

            line(390,10,390,40);//d
            ellipse(390,25,270,90,15,15);

            rectangle(410,10,415,15);//dot
            rectangle(410,35,415,40);//dot

            ellipse(435,25,90,270,15,15);//c

            line(440,10,450,10);//s
            line(440,10,440,25);
            line(440,25,450,25);
            line(450,25,450,40);
            line(440,40,450,40);

            line(455,10,455,40);//e
            line(455,10,465,10);
            line(455,25,465,25);
            line(455,40,465,40);

            line(470,10,480,10);//2
            line(480,10,480,25);
            line(470,25,480,25);
            line(470,25,470,40);
            line(470,40,480,40);

            ellipse(490,25,0,360,10,17);//0
            ellipse(508,25,0,360,10,17);//0

            line(525,10,525,40);//1
            line(521,13,525,10);
            line(521,40,529,40);

            ellipse(540,25,0,360,10,17);//0


            line(555,10,555,40);//1
            line(551,13,555,10);
            line(551,40,559,40);

            ellipse(565,15,0,360,7,7);//9
            ellipse(565,25,270,90,10,17);//9

            line(580,10,580,40);//1
            line(576,13,580,10);
            line(576,40,584,40);

            ellipse(595,17,260,100,8,8);//3
            ellipse(595,33,260,100,8,8);

            line(610,10,610,26);//5
            line(610,10,620,10);
            ellipse(610,33,260,100,11,8);

            delay(1000);
        }

        getch();
        closegraph();
    }
    break;
    case 8:
    {
        char ch;

        cout<<"Enter Any Capital Letters Between A to Z:"; //input alphabet from user
        cin>>ch;//store the Entered Alphabet in ch




        switch(ch)
        {
        case 'A':
        {
            int gd=0,gm;
            initgraph(&gd,&gm,"");
            line(241,60,190,270);
            line(241,60,303,268);
            line(210,186,280,186);


            line(10,10,10,40);//n
            line(20,10,20,40);
            line(10,10,20,40);
            line(30,10,40,40);//a
            line(20,40,30,10);//a
            line(24,30,37,30);
            line(40,10,48,20);//Y
            line(48,20,55,10);
            line(48,20,48,40);
            line(60,10,60,40);//e
            line(60,10,80,10);
            line(60,25,75,25);
            line(60,40,80,40);
            line(90,10,90,40);//m
            line(110,10,110,40);
            line(90,10,100,40);
            line(100,40,110,10);

            line(125,10,125,40);//h
            line(135,10,135,40);
            line(125,20,135,20);

            line(150,10,140,40);//a
            line(150,10,160,40);
            line(145,25,155,25);

            line(165,10,175,10);//s
            line(165,10,165,25);
            line(165,25,175,25);
            line(175,25,175,40);
            line(165,40,175,40);

            line(180,40,185,10);//a
            line(185,10,190,40);
            line(183,25,188,25);

            line(200,10,200,40);//n
            line(200,10,210,40);
            line(210,10,210,40);

            line(230,40,240,10);//a
            line(240,10,250,40);
            line(234,25,247,25);

            line(260,10,260,40);//r
            line(260,10,270,10);
            line(270,10,270,25);
            line(260,25,270,25);
            line(260,25,270,40);

            line(280,10,280,40);//m
            line(280,10,290,40);
            line(290,40,300,10);
            line(300,10,300,40);

            line(310,40,320,10);//a
            line(320,10,330,40);
            line(314,25,327,25);

            line(340,10,340,40);//n
            line(340,10,360,40);
            line(360,10,360,40);

            rectangle(366,35,370,40);//dot

            line(380,10,380,40);//i
            line(375,10,385,10);
            line(375,40,385,40);

            line(390,10,390,40);//d
            ellipse(390,25,270,90,15,15);

            rectangle(410,10,415,15);//dot
            rectangle(410,35,415,40);//dot

            ellipse(435,25,90,270,15,15);//c

            line(440,10,450,10);//s
            line(440,10,440,25);
            line(440,25,450,25);
            line(450,25,450,40);
            line(440,40,450,40);

            line(455,10,455,40);//e
            line(455,10,465,10);
            line(455,25,465,25);
            line(455,40,465,40);

            line(470,10,480,10);//2
            line(480,10,480,25);
            line(470,25,480,25);
            line(470,25,470,40);
            line(470,40,480,40);

            ellipse(490,25,0,360,10,17);//0
            ellipse(508,25,0,360,10,17);//0

            line(525,10,525,40);//1
            line(521,13,525,10);
            line(521,40,529,40);

            ellipse(540,25,0,360,10,17);//0


            line(555,10,555,40);//1
            line(551,13,555,10);
            line(551,40,559,40);

            ellipse(565,15,0,360,7,7);//9
            ellipse(565,25,270,90,10,17);//9

            line(580,10,580,40);//1
            line(576,13,580,10);
            line(576,40,584,40);

            ellipse(595,17,260,100,8,8);//3
            ellipse(595,33,260,100,8,8);

            line(610,10,610,26);//5
            line(610,10,620,10);
            ellipse(610,33,260,100,11,8);
            getch();
            closegraph();
        }

        break;

        case 'B':
        {
            int gd = DETECT, gm;
            initgraph(&gd, &gm, "");
            initwindow(720,1080,"B");

            line(50, 100, 50, 500);

            ellipse(50,200,270,0,100,100);
            ellipse(50,200,0,90,100,100);

            ellipse(50,400,0,90,100,100);
            ellipse(50,400,270,0,100,100);


            getch();
            closegraph();

        }
        break;

        case 'C':
        {
            int gd=0,gm;
            initgraph(&gd,&gm,"");
            ellipse(200,200,45,300,100,100);
            getch();
            closegraph();

        }
        break;

        case 'D':
        {


            int gd = DETECT, gm;
            initgraph(&gd, &gm, "");
            line(100, 100, 100, 300);

            ellipse(100, 200, 270, 90, 50, 100);

            getch();
            closegraph();
        }
        break;

        case 'E':
        {
            int gd=0,gm;
            initgraph(&gd,&gm,"");
            line(241,60,241,260);
            line(241,60,400,60);
            line(241,160,350,160);
            line(241,260,400,260);
            getch();
            closegraph();
        }


        break;

        case 'F':
        {
            int gd=0,gm;
            initgraph(&gd,&gm,"");
            line(241,60,241,270);
            line(237,270,245,270);
            line(241,60,400,60);
            line(400,57,400,63);
            line(241,150,400,150);
            line(400,147,400,153);

            getch();
            closegraph();
        }
        break;

        case 'G':
        {
            int gd=0,gm;
            initgraph(&gd,&gm,"");
            ellipse(200,200,30,320,100,100);
            line(275,245,275,300);
            line(260,245,275,245);
            getch();
            closegraph();

        }
        break;

        case 'H':
        {
            int gd=0,gm;
            initgraph(&gd,&gm,"");
            line(150, 50, 150, 200);
            line(225, 50, 225, 200);
            line(150, 125, 225, 125);
            getch();
            closegraph();

        }
        break;

        case 'I':
        {
            int gd=0,gm;
            initgraph(&gd,&gm,"");
            line(275, 50, 325, 50);
            line(300, 50, 300, 200);
            line(275, 200, 325, 200);

            getch();
            closegraph();

        }
        break;

        case 'J':
        {
            int gd=0,gm;
            initgraph(&gd,&gm,"");
            line(375, 50, 425, 50);
            line(425, 50, 425, 175);
            line(425, 175, 400, 200);
            line(400, 200, 375, 175);
            getch();
            closegraph();

        }

        break;

        case 'K':
        {
            int gd=0,gm;
            initgraph(&gd,&gm,"");
            line(240,120,240,300);
            line(240,210,250,210);
            line(250,210,350,120);
            line(250,210,350,300);


            getch();
            closegraph();
        }
        break;
        case 'L':
        {
            int gd=0,gm;
            initgraph(&gd,&gm,"");
            line(240,120,240,300);
            line(240,300,340,300);


            getch();
            closegraph();
        }
        break;
        case 'M':
        {

            int gd=0,gm;
            initgraph(&gd,&gm,"");
            line(140,60,140,300);
            line(140,60,220,300);
            line(300,60,300,300);
            line(300,60,220,300);

            getch();
            closegraph();
        }
        break;
        case 'N':
        {
            int gd=0,gm;
            initgraph(&gd,&gm,"");
            line(240,60,240,300);
            line(400,60,400,300);
            line(240,60,400,300);
            getch();
            closegraph();
        }
        break;
        case 'O':
        {
            int gd = DETECT, gm;
            initgraph(&gd, &gm, "");

            ellipse(100, 200, 270, 90, 50, 100);


            ellipse(100, 200, 90, 270, 50, 100);

            getch();
            closegraph();

        }
        break;
        case 'P':
        {
            int gd = DETECT, gm;
            initgraph(&gd, &gm, "");

            ellipse(100, 200, 270, 90, 50, 100);


            line(100,100,100,400);
            line(90,400,110,400);
            getch();
            closegraph();

        }
        break;
        case 'Q':
        {
            int gd = DETECT, gm;
            initgraph(&gd, &gm, "");

            circle(300,200,70);
            line(310,265,330,275);
            getch();
            closegraph();
        }
        break;
        case'R':
        {

            int gd = DETECT, gm;
            initgraph(&gd, &gm, "");
            ellipse(300,200,0,90,100,100);
            ellipse(300,200,270,0,100,100);

            line(300,100,300,400);
            line(300,300,400,400);
            getch();
            closegraph();

        }
        break;

        case'S':
        {
            int gd = DETECT, gm;
            initgraph(&gd, &gm, "");
            line(100,100,300,100);
            line(100,100,100,200);
            line(100,200,300,200);
            line(300,200,300,300);
            line(100,300,300,300);
            getch();
            closegraph();



        }
        break;
        case'T':
        {
            int gd=0,gm;
            initgraph(&gd,&gm,"");
            line(240,120,240,300);
            line(160,120,160,130);
            line(320,120,320,130);
            line(230,300,250,300);
            line(160,120,320,120);


            getch();
            closegraph();

        }
        break;
        case'U':
        {

            int gd = DETECT, gm;
            initgraph(&gd, &gm, "");
            line(200,50,200,200);
            line(190,50,210,50);
            line(390,50,410,50);
            line(400,50,400,200);
            ellipse(300,200,180,270,100,100);
            ellipse(300,200,270,0,100,100);


            getch();
            closegraph();

        }
        break;
        case'V':
        {
            int gd=0,gm;
            initgraph(&gd,&gm,"");
            line(240,120,320,300);
            line(235,120,245,120);
            line(400,120,320,300);
            line(395,120,405,120);



            getch();
            closegraph();

        }
        break;
        case'W':
        {
            int gd=0,gm;
            initgraph(&gd,&gm,"");
            line(140,60,140,300);
            line(140,300,220,180);
            line(300,60,300,300);
            line(220,180,300,300);
            getch();
            closegraph();

        }
        break;
        case'X':
        {
            int gd=0,gm;
            initgraph(&gd,&gm,"");
            line(300,120,100,360);
            line(100,120,300,360);

            getch();
            closegraph();

        }
        break;
        case'Y':
        {
            int gd=0,gm;
            initgraph(&gd,&gm,"");
            line(240,120,320,300);
            line(235,120,245,120);
            line(400,120,320,300);
            line(395,120,405,120);
            line(320,300,320,400);
            line(310,400,330,400);



            getch();
            closegraph();

        }
        break;
        case'Z':
        {
            int gd=0,gm;
            initgraph(&gd,&gm,"");
            line(100,120,300,120);
            line(100,120,100,130);
            line(100,360,300,360);
            line(300,120,100,360);
            line(300,360,300,350);



            getch();
            closegraph();

        }
        break;

        }

    }

    break;

    case 9:
    {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, "");
        initwindow(1500, 1000, "Arman");

        // Draw the sun
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        circle(700, 400, 50);
        floodfill(700, 400, YELLOW);

        // Draw mercury
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        circle(700, 400, 70);
        circle(770, 400, 5);


        // Draw venus
        setcolor(LIGHTBLUE);
        setfillstyle(SOLID_FILL, LIGHTBLUE);
        circle(700, 400, 100);
        circle(700, 500, 7);



        // Draw earth
        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        circle(700, 400, 130);
        circle(830, 400, 9);

        // Draw mars
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        circle(700, 400, 160);
        circle(540, 400, 10);

        // Draw jupiter
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        circle(700, 400, 180);
        circle(700, 220, 13);

        // Draw saturn
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        circle(700, 400, 210);
        circle(700, 610, 11);

        // Draw uranus
        setcolor(LIGHTBLUE);
        setfillstyle(SOLID_FILL, LIGHTBLUE);
        circle(700, 400, 240);
        circle(460, 400, 8);

        // Draw neptune
        setcolor(BLUE);
        setfillstyle(SOLID_FILL, BLUE);
        circle(700, 400, 270);
        circle(970, 400, 9);

        // Draw pluto
        setcolor(LIGHTGRAY);
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        circle(700, 400, 300);
        circle(700, 100, 6);
        floodfill(701,101,LIGHTGRAY);


        line(10,10,10,40);//n
        line(20,10,20,40);
        line(10,10,20,40);
        line(30,10,40,40);//a
        line(20,40,30,10);//a
        line(24,30,37,30);
        line(40,10,48,20);//Y
        line(48,20,55,10);
        line(48,20,48,40);
        line(60,10,60,40);//e
        line(60,10,80,10);
        line(60,25,75,25);
        line(60,40,80,40);
        line(90,10,90,40);//m
        line(110,10,110,40);
        line(90,10,100,40);
        line(100,40,110,10);

        line(125,10,125,40);//h
        line(135,10,135,40);
        line(125,20,135,20);

        line(150,10,140,40);//a
        line(150,10,160,40);
        line(145,25,155,25);

        line(165,10,175,10);//s
        line(165,10,165,25);
        line(165,25,175,25);
        line(175,25,175,40);
        line(165,40,175,40);

        line(180,40,185,10);//a
        line(185,10,190,40);
        line(183,25,188,25);

        line(200,10,200,40);//n
        line(200,10,210,40);
        line(210,10,210,40);

        line(230,40,240,10);//a
        line(240,10,250,40);
        line(234,25,247,25);

        line(260,10,260,40);//r
        line(260,10,270,10);
        line(270,10,270,25);
        line(260,25,270,25);
        line(260,25,270,40);

        line(280,10,280,40);//m
        line(280,10,290,40);
        line(290,40,300,10);
        line(300,10,300,40);

        line(310,40,320,10);//a
        line(320,10,330,40);
        line(314,25,327,25);

        line(340,10,340,40);//n
        line(340,10,360,40);
        line(360,10,360,40);

        rectangle(366,35,370,40);//dot

        line(380,10,380,40);//i
        line(375,10,385,10);
        line(375,40,385,40);

        line(390,10,390,40);//d
        ellipse(390,25,270,90,15,15);

        rectangle(410,10,415,15);//dot
        rectangle(410,35,415,40);//dot

        ellipse(435,25,90,270,15,15);//c

        line(440,10,450,10);//s
        line(440,10,440,25);
        line(440,25,450,25);
        line(450,25,450,40);
        line(440,40,450,40);

        line(455,10,455,40);//e
        line(455,10,465,10);
        line(455,25,465,25);
        line(455,40,465,40);

        line(470,10,480,10);//2
        line(480,10,480,25);
        line(470,25,480,25);
        line(470,25,470,40);
        line(470,40,480,40);

        ellipse(490,25,0,360,10,17);//0
        ellipse(508,25,0,360,10,17);//0

        line(525,10,525,40);//1
        line(521,13,525,10);
        line(521,40,529,40);

        ellipse(540,25,0,360,10,17);//0


        line(555,10,555,40);//1
        line(551,13,555,10);
        line(551,40,559,40);

        ellipse(565,15,0,360,7,7);//9
        ellipse(565,25,270,90,10,17);//9

        line(580,10,580,40);//1
        line(576,13,580,10);
        line(576,40,584,40);

        ellipse(595,17,260,100,8,8);//3
        ellipse(595,33,260,100,8,8);

        line(610,10,610,26);//5
        line(610,10,620,10);
        ellipse(610,33,260,100,11,8);


        getch();
        closegraph();

    }

    break;
    case 10:
    {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, "");

        // Draw sky
        setcolor(CYAN);
        rectangle(0, 0, 639, 479);
        setfillstyle(SOLID_FILL, CYAN);
        floodfill(320, 240, CYAN);

        // Draw sun
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        circle(100, 100, 50);
        floodfill(100, 100, YELLOW);

        // Draw mountains
        setcolor(GREEN);
        setfillstyle(SOLID_FILL, GREEN);
        line(0, 250, 100, 150);
        line(100, 150, 200, 250);
        line(200, 250, 300, 150);
        line(300, 150, 400, 250);
        line(400, 250, 500, 150);
        line(500, 150, 600, 250);
        line(600, 250, 639, 300);
        line(639, 300, 639, 479);
        floodfill(320, 350, GREEN);

        // Draw ground
        setcolor(BROWN);
        rectangle(0, 350, 639, 479);
        setfillstyle(SOLID_FILL, BROWN);
        floodfill(320, 400, BROWN);

        // Draw houses
        setcolor(LIGHTGRAY);
        rectangle(50, 300, 200, 400);
        rectangle(250, 300, 400, 400);
        rectangle(450, 300, 600, 400);
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        floodfill(100, 350, LIGHTGRAY);
        floodfill(300, 350, LIGHTGRAY);
        floodfill(500, 350, LIGHTGRAY);

        // Draw roofs
        setcolor(RED);
        line(50, 300, 125, 250);
        line(125, 250, 200, 300);
        line(250, 300, 325, 250);
        line(325, 250, 400, 300);
        line(450, 300, 525, 250);
        line(525, 250, 600, 300);

        // Draw windows
        setcolor(YELLOW);
        rectangle(75, 325, 125, 375);
        rectangle(275, 325, 325, 375);
        rectangle(475, 325, 525, 375);
        setfillstyle(SOLID_FILL, YELLOW);
        floodfill(100, 350, YELLOW);
        floodfill(300, 350, YELLOW);
        floodfill(500, 350, YELLOW);

        // Draw doors
        setcolor(BLUE);
        rectangle(100, 375, 150, 400);
        rectangle(300, 375, 350, 400);
        rectangle(500, 375, 550, 400);
        setfillstyle(SOLID_FILL, BLUE);
        floodfill(125, 385, BLUE);
        floodfill(325, 385, BLUE);
        floodfill(525, 385, BLUE);


        line(10,10,10,40);//n
        line(20,10,20,40);
        line(10,10,20,40);
        line(30,10,40,40);//a
        line(20,40,30,10);//a
        line(24,30,37,30);
        line(40,10,48,20);//Y
        line(48,20,55,10);
        line(48,20,48,40);
        line(60,10,60,40);//e
        line(60,10,80,10);
        line(60,25,75,25);
        line(60,40,80,40);
        line(90,10,90,40);//m
        line(110,10,110,40);
        line(90,10,100,40);
        line(100,40,110,10);

        line(125,10,125,40);//h
        line(135,10,135,40);
        line(125,20,135,20);

        line(150,10,140,40);//a
        line(150,10,160,40);
        line(145,25,155,25);

        line(165,10,175,10);//s
        line(165,10,165,25);
        line(165,25,175,25);
        line(175,25,175,40);
        line(165,40,175,40);

        line(180,40,185,10);//a
        line(185,10,190,40);
        line(183,25,188,25);

        line(200,10,200,40);//n
        line(200,10,210,40);
        line(210,10,210,40);

        line(230,40,240,10);//a
        line(240,10,250,40);
        line(234,25,247,25);

        line(260,10,260,40);//r
        line(260,10,270,10);
        line(270,10,270,25);
        line(260,25,270,25);
        line(260,25,270,40);

        line(280,10,280,40);//m
        line(280,10,290,40);
        line(290,40,300,10);
        line(300,10,300,40);

        line(310,40,320,10);//a
        line(320,10,330,40);
        line(314,25,327,25);

        line(340,10,340,40);//n
        line(340,10,360,40);
        line(360,10,360,40);

        rectangle(366,35,370,40);//dot

        line(380,10,380,40);//i
        line(375,10,385,10);
        line(375,40,385,40);

        line(390,10,390,40);//d
        ellipse(390,25,270,90,15,15);

        rectangle(410,10,415,15);//dot
        rectangle(410,35,415,40);//dot

        ellipse(435,25,90,270,15,15);//c

        line(440,10,450,10);//s
        line(440,10,440,25);
        line(440,25,450,25);
        line(450,25,450,40);
        line(440,40,450,40);

        line(455,10,455,40);//e
        line(455,10,465,10);
        line(455,25,465,25);
        line(455,40,465,40);

        line(470,10,480,10);//2
        line(470,10,470,15);
        line(470,40,480,10);
        line(470,40,485,40);

        ellipse(490,25,0,360,10,17);//0
        ellipse(508,25,0,360,10,17);//0

        line(525,10,525,40);//1
        line(521,13,525,10);
        line(521,40,529,40);

        ellipse(540,25,0,360,10,17);//0


        line(555,10,555,40);//1
        line(551,13,555,10);
        line(551,40,559,40);

        ellipse(565,15,0,360,7,7);//9
        ellipse(565,25,270,90,10,17);//9

        line(580,10,580,40);//1
        line(576,13,580,10);
        line(576,40,584,40);

        ellipse(595,17,260,100,8,8);//3
        ellipse(595,33,260,100,8,8);

        line(610,10,610,26);//5
        line(610,10,620,10);
        ellipse(610,33,260,100,11,8);

        getch();
        closegraph();

    }

    break;
    case 11:    //Solar System
    {
        initwindow(WIDTH, HEIGHT, "Solar System Demo");

        int earthX, earthY, moonX, moonY;
        double earthAngle = 0.0, moonAngle = 0.0;

        while (true)
        {
            // clear the screen
            cleardevice();
            // draw the sun
            drawSun();

            // calculate earth's position
            earthX = SUN_X + EARTH_ORBIT_RADIUS * cos(earthAngle);
            earthY = SUN_Y + EARTH_ORBIT_RADIUS * sin(earthAngle);

            // draw earth
            drawEarth(earthX, earthY);

            // calculate moon's position
            moonX = earthX + MOON_ORBIT_RADIUS * cos(moonAngle);
            moonY = earthY + MOON_ORBIT_RADIUS * sin(moonAngle);

            // draw moon
            drawMoon(moonX, moonY);

            // update the angles for the next frame
            earthAngle += 0.01;
            moonAngle += 0.02;
            delay(500);


            line(10,10,10,40);//n
            line(20,10,20,40);
            line(10,10,20,40);
            line(30,10,40,40);//a
            line(20,40,30,10);//a
            line(24,30,37,30);
            line(40,10,48,20);//Y
            line(48,20,55,10);
            line(48,20,48,40);
            line(60,10,60,40);//e
            line(60,10,80,10);
            line(60,25,75,25);
            line(60,40,80,40);
            line(90,10,90,40);//m
            line(110,10,110,40);
            line(90,10,100,40);
            line(100,40,110,10);

            line(125,10,125,40);//h
            line(135,10,135,40);
            line(125,20,135,20);

            line(150,10,140,40);//a
            line(150,10,160,40);
            line(145,25,155,25);

            line(165,10,175,10);//s
            line(165,10,165,25);
            line(165,25,175,25);
            line(175,25,175,40);
            line(165,40,175,40);

            line(180,40,185,10);//a
            line(185,10,190,40);
            line(183,25,188,25);

            line(200,10,200,40);//n
            line(200,10,210,40);
            line(210,10,210,40);

            line(230,40,240,10);//a
            line(240,10,250,40);
            line(234,25,247,25);

            line(260,10,260,40);//r
            line(260,10,270,10);
            line(270,10,270,25);
            line(260,25,270,25);
            line(260,25,270,40);

            line(280,10,280,40);//m
            line(280,10,290,40);
            line(290,40,300,10);
            line(300,10,300,40);

            line(310,40,320,10);//a
            line(320,10,330,40);
            line(314,25,327,25);

            line(340,10,340,40);//n
            line(340,10,360,40);
            line(360,10,360,40);

            rectangle(366,35,370,40);//dot

            line(380,10,380,40);//i
            line(375,10,385,10);
            line(375,40,385,40);

            line(390,10,390,40);//d
            ellipse(390,25,270,90,15,15);

            rectangle(410,10,415,15);//dot
            rectangle(410,35,415,40);//dot

            ellipse(435,25,90,270,15,15);//c

            line(440,10,450,10);//s
            line(440,10,440,25);
            line(440,25,450,25);
            line(450,25,450,40);
            line(440,40,450,40);

            line(455,10,455,40);//e
            line(455,10,465,10);
            line(455,25,465,25);
            line(455,40,465,40);

            line(470,10,480,10);//2
            line(470,10,470,15);
            line(470,40,480,10);
            line(470,40,485,40);

            ellipse(490,25,0,360,10,17);//0
            ellipse(508,25,0,360,10,17);//0

            line(525,10,525,40);//1
            line(521,13,525,10);
            line(521,40,529,40);

            ellipse(540,25,0,360,10,17);//0


            line(555,10,555,40);//1
            line(551,13,555,10);
            line(551,40,559,40);

            ellipse(565,15,0,360,7,7);//9
            ellipse(565,25,270,90,10,17);//9

            line(580,10,580,40);//1
            line(576,13,580,10);
            line(576,40,584,40);

            ellipse(595,17,260,100,8,8);//3
            ellipse(595,33,260,100,8,8);

            line(610,10,610,26);//5
            line(610,10,620,10);
            ellipse(610,33,260,100,11,8);
        }

        closegraph(); // close the graphics window

        return 0;

    }

    break;

    case 12:    //Submarine
    {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, "");
        initwindow(1980,720,"Arman");

        // set initial position of ship
        int x = 0, y = 300;

        // draw the submarine
        setfillstyle(SOLID_FILL, BLUE);
        rectangle(x+100, y-50, x+300, y);
        floodfill(x+150, y-25, WHITE);
        rectangle(x+150, y-100, x+250, y-50);
        floodfill(x+200, y-75, WHITE);

        while (x < 800)
        {
            cleardevice();
            setfillstyle(SOLID_FILL, BLUE);
            rectangle(x+100, y-50, x+300, y);
            floodfill(x+150, y-25, WHITE);
            rectangle(x+150, y-100, x+250, y-50);
            floodfill(x+200, y-75, WHITE);

            setfillstyle(SOLID_FILL, LIGHTBLUE);
            rectangle(x, y, x+400, y+100);
            floodfill(x+50, y+50, WHITE);


            line(10,10,10,40);//n
            line(20,10,20,40);
            line(10,10,20,40);
            line(30,10,40,40);//a
            line(20,40,30,10);//a
            line(24,30,37,30);
            line(40,10,48,20);//Y
            line(48,20,55,10);
            line(48,20,48,40);
            line(60,10,60,40);//e
            line(60,10,80,10);
            line(60,25,75,25);
            line(60,40,80,40);
            line(90,10,90,40);//m
            line(110,10,110,40);
            line(90,10,100,40);
            line(100,40,110,10);

            line(125,10,125,40);//h
            line(135,10,135,40);
            line(125,20,135,20);

            line(150,10,140,40);//a
            line(150,10,160,40);
            line(145,25,155,25);

            line(165,10,175,10);//s
            line(165,10,165,25);
            line(165,25,175,25);
            line(175,25,175,40);
            line(165,40,175,40);

            line(180,40,185,10);//a
            line(185,10,190,40);
            line(183,25,188,25);

            line(200,10,200,40);//n
            line(200,10,210,40);
            line(210,10,210,40);

            line(230,40,240,10);//a
            line(240,10,250,40);
            line(234,25,247,25);

            line(260,10,260,40);//r
            line(260,10,270,10);
            line(270,10,270,25);
            line(260,25,270,25);
            line(260,25,270,40);

            line(280,10,280,40);//m
            line(280,10,290,40);
            line(290,40,300,10);
            line(300,10,300,40);

            line(310,40,320,10);//a
            line(320,10,330,40);
            line(314,25,327,25);

            line(340,10,340,40);//n
            line(340,10,360,40);
            line(360,10,360,40);

            rectangle(366,35,370,40);//dot

            line(380,10,380,40);//i
            line(375,10,385,10);
            line(375,40,385,40);

            line(390,10,390,40);//d
            ellipse(390,25,270,90,15,15);

            rectangle(410,10,415,15);//dot
            rectangle(410,35,415,40);//dot

            ellipse(435,25,90,270,15,15);//c

            line(440,10,450,10);//s
            line(440,10,440,25);
            line(440,25,450,25);
            line(450,25,450,40);
            line(440,40,450,40);

            line(455,10,455,40);//e
            line(455,10,465,10);
            line(455,25,465,25);
            line(455,40,465,40);

            line(470,10,480,10);//2
            line(470,10,470,15);
            line(470,40,480,10);
            line(470,40,485,40);

            ellipse(490,25,0,360,10,17);//0
            ellipse(508,25,0,360,10,17);//0

            line(525,10,525,40);//1
            line(521,13,525,10);
            line(521,40,529,40);

            ellipse(540,25,0,360,10,17);//0


            line(555,10,555,40);//1
            line(551,13,555,10);
            line(551,40,559,40);

            ellipse(565,15,0,360,7,7);//9
            ellipse(565,25,270,90,10,17);//9

            line(580,10,580,40);//1
            line(576,13,580,10);
            line(576,40,584,40);

            ellipse(595,17,260,100,8,8);//3
            ellipse(595,33,260,100,8,8);

            line(610,10,610,26);//5
            line(610,10,620,10);
            ellipse(610,33,260,100,11,8);

            x += 10;
            delay(100);
        }

        closegraph(); // close the graphics window

        return 0;

    }

    break;


    }
    cout << "\nInvalid input,Please try again\n" << endl;


    return 0;

}



