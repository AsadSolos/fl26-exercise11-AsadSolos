// traffic_light.cpp

#include "traffic_light.h"
#include <QWidget>
#include <QLayout>
#include <QRadioButton>

TrafficLight::TrafficLight(QWidget * parent): QWidget(parent), current_state(0) {

  // Add the red traffic light
  redlight = new QRadioButton;
  redlight->setEnabled(false);
  redlight->toggle();   // initialize the red light to be ON
  redlight->setStyleSheet("QRadioButton::indicator:checked { background-color: red;}");
  
  yellowlight = new QRadioButton;
  yellowlight->setEnabled(false);
  yellowlight->setStyleSheet("QRadioButton::indicator:checked { background-color: yellow;}");
      
  greenlight = new QRadioButton;
  greenlight->setEnabled(false);
  greenlight->setStyleSheet("QRadioButton::indicator:checked { background-color: green;}");
    
  auto layout = new QVBoxLayout;
  layout->addWidget(redlight);
  layout->addWidget(yellowlight);
  layout->addWidget(greenlight);

  setLayout(layout);
}

void TrafficLight::light_update() {

  //advance state
  current_state = (current_state + 1) % 3;

  if (current_state == 0) {

    //red on
    redlight->toggle();
  }
  else if (current_state == 1) {

    //green on
    greenlight->toggle();
  }
  else {

    //yellow on
    yellowlight->toggle();
  }
}
