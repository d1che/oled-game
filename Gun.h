#ifndef Gun_h
#define Gun_h

#include <Arduino.h>
#include "Bullet.h"

class Gun
{
  private:
    int m_ammo, m_clipSize;
    int m_index;
    int m_rate;
    Bullet* bullets[10];
  
  public:
    Gun();
    int getAmmo();
    int getClipSize();
    void fire(int x, int y);
    void reload();
    void render();
};

Gun::Gun()
{
  m_index = 0;
  m_clipSize = 10;
  m_ammo = 10;
  reload();
}

int Gun::getAmmo()
{
  return m_ammo;
}

int Gun::getClipSize()
{
  return m_clipSize; 
}

void Gun::fire(int x, int y)
{
  bullets[m_index] = setXY(x, y);
  m_ammo--;
  m_index++;
}

void Gun::reload()
{  
  for(int i=0; i<m_clipSize; i++)
  {
    bullets[i] = new Bullet;
  }
  m_index = 0;
  m_ammo = m_clipSize;
}

void Gun::render()
{
  if (m_ammo <= 0) reload();  
  for (int i=0; i<m_clipSize; i++)
  {
    bullets[i]->render();
    if (bullets[m_index]->getPos() > 127) delete(bullets[m_index]);
  }
}
  
#endif
