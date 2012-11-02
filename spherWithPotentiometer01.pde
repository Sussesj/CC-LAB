/*
Susse Sønderby Jensen, nov 2012
Inspiration by: Rotating Polyhedra Ira Greenberg
*/
// Importer arduino
import processing.serial.*;
Serial port;
float moveObject = 0; //Use potentiometer to move 
float rotY;
float rotX;
void setup(){
  println(Serial.list());
  size (400, 400, P3D);
  port = new Serial(this, Serial.list()[1], 9600);
  port.bufferUntil('\n');

  frameRate(30);
}
void draw(){
  background(255);
/* ensures shapes are drawn at the
center of the display window. In addition,
mouse y postion controls the distance
the shapes are drawn along the z-axis.
As the shapes moves further into space,
they will diminish in size*/
translate(width/2, height/2, 100);
// rotate around Y and X axes
rotateY(rotY+=.05);
rotateX(rotX+=.1);
fill(0);
stroke(255);

//draw box
box(moveObject);
noFill();
sphereDetail(8);
stroke(0);
// draw larger outer sphere
sphere(80);
}
void serialEvent (Serial port)
{
  moveObject = float(port.readStringUntil('\n'));
}
