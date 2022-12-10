#ifndef Player_h
#define Player_h

#include <Arduino.h>
#include "Gun.h"

#define LIVES 1
#define AMMO 2
#define CLIP 3


class Player
{
  private:
    int m_xPos, m_yPos;
    int m_leftColl, m_rightColl, m_topColl, m_botColl;
    boolean m_accel;
    int m_flame1, m_flame2, m_flame3;
    int m_lives;
    
    Gun weapon;
  
  public:
    Player();
    int info(int);
    void setXY(int, int);
    void shoot();
    void getLife();
    void takeLife();
    void collision();
    void animateFlames();
    void render();
};

Player::Player()
{
  m_xPos = 20;
  m_yPos = 39;
  m_leftColl = 0;
  m_rightColl = 0;
  m_topColl = 0;
  m_botColl = 0;
  m_flame1 = m_leftColl;
  m_flame2 = m_leftColl;
  m_flame3 = m_leftColl;
  m_accel = false;
  m_lives = 4;
}

int Player::info(int type)
{
  switch (type)
  {
     case 1: return m_lives;
     case 2: return weapon.getAmmo();
     case 3: return weapon.getClipSize();
     default : return 0;
  }
}

void Player::setXY(int x, int y)
{ 
  
  if (x > 438 || x < 416 || y > 427 || y < 401) m_accel = true;
  else  m_accel = false;
  
  if (x > 438) m_xPos--;
  if (x > 800) m_xPos -= 2;
  
  if (x < 416) m_xPos++;  
  if (x < 200) m_xPos += 2;
  
  if (y > 427) m_yPos++;  
  if (y > 850) m_yPos += 2;
  
  if (y < 401) m_yPos--;
  if (y < 180) m_yPos -= 2;
}

void Player::shoot()
{
  weapon.fire(m_xPos, m_yPos);
}

void Player::getLife()
{
  m_lives++;
}

void Player::takeLife()
{
  m_lives--;
}

void Player::collision()
{
  m_leftColl = m_xPos - 8;
  m_rightColl = m_xPos;
  m_topColl = m_yPos - 2;
  m_botColl = m_yPos + 2;
  
  if (m_leftColl <= 0) m_xPos = 8;
  if (m_rightColl >= 127) m_xPos = 127;
  if (m_topColl <= 16) m_yPos = 19;
  if (m_botColl >= 63) m_yPos = 60;
}

void Player::animateFlames()
{
  if (m_flame1 < m_xPos - 15 || m_flame1 > m_xPos - 12) m_flame1 = m_xPos - 9;
  if (m_flame2 < m_xPos - 12 || m_flame2 > m_xPos - 9) m_flame2 = m_xPos - 9;
  if (m_flame3 < m_xPos - 12 || m_flame3 > m_xPos - 9) m_flame3 = m_xPos - 9;
  m_flame1--;
  m_flame2--;
  m_flame3--;
}

void Player::render()
{
  collision();
  animateFlames();
  weapon.render();
  
  // center
  display.drawPixel(m_xPos, m_yPos, WHITE);
  display.drawPixel(m_xPos -1, m_yPos, WHITE);
  //display.drawPixel(m_xPos -2, m_yPos, WHITE);
  //display.drawPixel(m_xPos -3, m_yPos, WHITE);
  display.drawPixel(m_xPos -4, m_yPos, WHITE);
  //display.drawPixel(m_xPos -5, m_yPos, WHITE);
  //display.drawPixel(m_xPos -6, m_yPos, WHITE);
  display.drawPixel(m_xPos -7, m_yPos, WHITE);
  
  // rockets
  if(m_accel) display.drawPixel(m_xPos - 8, m_yPos, WHITE);
  if(m_accel) display.drawPixel(m_xPos - 8, m_yPos - 2, WHITE);
  if(m_accel) display.drawPixel(m_xPos - 8, m_yPos + 2, WHITE);
  
  // flames
  if(m_accel) display.drawPixel(m_flame1, m_yPos, WHITE);
  if(m_accel) display.drawPixel(m_flame2, m_yPos - 2, WHITE);
  if(m_accel) display.drawPixel(m_flame3, m_yPos + 2, WHITE);
  
  // upper part
  display.drawPixel(m_xPos -1, m_yPos - 1, WHITE);
  display.drawPixel(m_xPos -2, m_yPos - 1, WHITE);
  display.drawPixel(m_xPos -3, m_yPos - 1, WHITE);
  display.drawPixel(m_xPos -4, m_yPos - 1, WHITE);
  display.drawPixel(m_xPos -5, m_yPos - 1, WHITE);
  display.drawPixel(m_xPos -6, m_yPos - 1, WHITE);
  display.drawPixel(m_xPos -7, m_yPos - 1, WHITE);
  display.drawPixel(m_xPos -2, m_yPos - 2, WHITE);
  display.drawPixel(m_xPos -3, m_yPos - 2, WHITE);
  display.drawPixel(m_xPos -6, m_yPos - 2, WHITE);
  display.drawPixel(m_xPos -7, m_yPos - 2, WHITE);
  
  // lower part
  display.drawPixel(m_xPos -1, m_yPos + 1, WHITE);
  display.drawPixel(m_xPos -2, m_yPos + 1, WHITE);
  display.drawPixel(m_xPos -3, m_yPos + 1, WHITE);
  display.drawPixel(m_xPos -4, m_yPos + 1, WHITE);
  display.drawPixel(m_xPos -5, m_yPos + 1, WHITE);
  display.drawPixel(m_xPos -6, m_yPos + 1, WHITE);
  display.drawPixel(m_xPos -7, m_yPos + 1, WHITE);
  display.drawPixel(m_xPos -2, m_yPos + 2, WHITE);
  display.drawPixel(m_xPos -3, m_yPos + 2, WHITE);
  display.drawPixel(m_xPos -6, m_yPos + 2, WHITE);
  display.drawPixel(m_xPos -7, m_yPos + 2, WHITE);
  
}

#endif
