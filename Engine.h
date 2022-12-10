#ifndef Engine_h
#define Engine_h

#include <Arduino.h>
#include "graphics.h"
#include "Player.h"
#include "Button.h"

class Engine
{
  private:
  
    //timer variables
    float m_seconds;
    int m_ammoBar;
    int m_lives;
    unsigned long m_frame;
    unsigned long m_frameTimer;
    
    Button joystick;
    Player player;
  
  public:
    Engine();
    void init();
    void update();
    void drawMenu();
    void drawGame();
    void reset();
    float runtime();
    void drawHUD();
};

Engine::Engine()
{
  m_seconds = 0;
  m_frameTimer = 0;
  m_frame = 0;
}

void Engine::init()
{
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 display.setTextColor(WHITE);
 display.clearDisplay();
}

void Engine::update()
{
  m_frameTimer = millis();
  m_seconds = (float)m_frame/1000;
  
  joystick.update();
  
  if(false)
  {
    display.invertDisplay(true);
    drawMenu();
  }
  else
  {
    display.invertDisplay(false);
    drawGame();
  }
  display.display();
  display.clearDisplay();
  
  m_frame += (millis() - m_frameTimer);
}

void Engine::drawMenu()
{
  display.setTextSize(2);
  display.setCursor(2, 0);
  display.print("MENU");
  display.setCursor(90, 0);
  display.setTextSize(1);
  display.print("v1.0");
  display.setCursor(90, 8);
  display.print(m_seconds);
}

void Engine::drawGame()
{
  player.render();
  player.setXY(joystick.getX(), joystick.getY());
  if(joystick.down()) 
  {
    player.takeLife();
    player.shoot();
  }
  drawHUD();
}

void Engine::reset()
{
  m_frame = 0;
}

float Engine::runtime()
{
  return m_seconds;
}

void Engine::drawHUD()
{
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("AMMO");
  display.setCursor(0, 8);
  display.println("HEALTH");
  display.setCursor(76, 0);
  display.println("T: ");
  display.setCursor(88, 0);
  display.println(m_seconds);
  
  for (int i=5; i<5+player.info(AMMO); i++)
  {
    for (int j=0; j<7; j++)
    {
      display.drawPixel(i*5, j, WHITE);
      display.drawPixel(i*5+1, j, WHITE);
      display.drawPixel(i*5+2, j, WHITE);
      display.drawPixel(i*5+3, j, WHITE);
    }
  }
  
  for (int i=40; i<40+(8*player.info(LIVES)); i+=8)
  {
    display.drawPixel(i+1, 9, WHITE);
    display.drawPixel(i+2, 9, WHITE);
    display.drawPixel(i+4, 9, WHITE);
    display.drawPixel(i+5, 9, WHITE);
    
    display.drawPixel(i, 10, WHITE);
    display.drawPixel(i+1, 10, WHITE);
    display.drawPixel(i+2, 10, WHITE);
    display.drawPixel(i+3, 10, WHITE);
    display.drawPixel(i+4, 10, WHITE);
    display.drawPixel(i+5, 10, WHITE);
    display.drawPixel(i+6, 10, WHITE);
    
    display.drawPixel(i, 11, WHITE);
    display.drawPixel(i+1, 11, WHITE);
    display.drawPixel(i+2, 11, WHITE);
    display.drawPixel(i+3, 11, WHITE);
    display.drawPixel(i+4, 11, WHITE);
    display.drawPixel(i+5, 11, WHITE);
    display.drawPixel(i+6, 11, WHITE);
    
    display.drawPixel(i+1, 12, WHITE);
    display.drawPixel(i+2, 12, WHITE);
    display.drawPixel(i+3, 12, WHITE);
    display.drawPixel(i+4, 12, WHITE);
    display.drawPixel(i+5, 12, WHITE);
    
    display.drawPixel(i+2, 13, WHITE);
    display.drawPixel(i+3, 13, WHITE);
    display.drawPixel(i+4, 13, WHITE);
    
    display.drawPixel(i+3, 14, WHITE);
  }
  
  for (int i=0; i<128; i++)
  {
    display.drawPixel(i, 15, WHITE);
  }
}

#endif
