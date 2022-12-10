#ifndef Bullet_h
#define Bullet_h

#include <Arduino.h>

class Bullet
{
  private:
    int m_bulletX, m_bulletY;
  
  public:
    Bullet();
    void setXY(int, int);
    int getPos();
    void render();
};

Bullet::Bullet()
{
  m_bulletX = 128;
  m_bulletY = 64;
}

void Bullet::setXY(int x, int y)
{
  m_bulletX = x;
  m_bulletY = y;
}

int Bullet::getPos()
{
  return m_bulletX;
}

void Bullet::render()
{
  m_bulletX += 3;
  display.drawPixel(m_bulletX, m_bulletY, WHITE);
}

#endif
