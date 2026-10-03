// main.cpp

#include <QApplication>
#include <QTimer>

#include "traffic_light.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  TrafficLight light;
  int ret;

  //set up timer
  QTimer * timer = new QTimer(&light);

  //connect signal to slot
  QObject::connect(timer, &QTimer::timeout, &light, &TrafficLight::light_update);

  //start timer at half second
  timer->start(500);

  light.show();
  ret = app.exec();
    
  return ret;
}
