#ifndef Button_h
#define Button_h

#include <Arduino.h>

class Button 
{
  private:
    boolean m_down, m_hold, m_holded;
    int m_toggleDown;
    
    int m_lastTime, m_totalTime;
    
    int m_x;
    int m_y;
    
    int m_leftRight, m_upDown;
 
  public:
    Button();
    void update();
    boolean down();
    boolean hold();
    int getX();
    int getY();
};
  
Button::Button()
{ 
  m_down = false;
  m_hold = false;
  m_holded = false;
  m_toggleDown = false;
  pinMode(5, INPUT);
}

void Button::update()
{
  m_lastTime = millis();
  m_down = !digitalRead(5);
  m_x = analogRead(3);
  m_y = analogRead(2);
  
  // calculating hold time
  if (m_down)
  {
    m_totalTime += millis() - m_lastTime;
    if (m_totalTime > 4 && m_holded)
    {
      m_hold = !m_hold;
      m_holded = false;
    }
    m_toggleDown = true;
  }
  else
  {
    m_totalTime = 0;
    m_holded = true;
    m_toggleDown = false;
  }
}

boolean Button::down()
{
  return m_toggleDown;
}

boolean Button::hold()
{
  return m_hold;
}

int Button::getX()
{
  return m_x;
}

int Button::getY()
{
  return m_y;  
}

#endif
