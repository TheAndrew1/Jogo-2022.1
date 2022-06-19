#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>             // Arduino SPI library
#include <Fonts/FreeSansBold12pt7b.h>
#include <string.h>
 
// ST7789 TFT module connections
#define TFT_CS     10
#define TFT_RST    8  // define reset pin, or set to -1 and connect to Arduino RESET pin
#define TFT_DC     9  // define data/command pin
 
// Initialize Adafruit ST7789 TFT library
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

/*
#define nave_w 40
#define nave_h 36
static unsigned char nave[] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x08, 0x00, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x24, 0x00,
   0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x55, 0x00, 0x00, 0x00,
   0x80, 0x29, 0x08, 0x00, 0x00, 0x90, 0x12, 0x12, 0x00, 0x00, 0xa8, 0x55,
   0x06, 0x00, 0x00, 0xac, 0xa9, 0xaa, 0x00, 0x40, 0xad, 0xaa, 0x27, 0x02,
   0x80, 0x4d, 0x49, 0x43, 0x03, 0xa8, 0x5a, 0x93, 0x4a, 0x06, 0xac, 0x4e,
   0xd5, 0xb6, 0x15, 0xcc, 0x4c, 0x95, 0x22, 0x09, 0x94, 0x44, 0xa3, 0x13,
   0x03, 0xa4, 0x29, 0xa5, 0xa2, 0x0a, 0xcc, 0x4d, 0xc9, 0x12, 0x0b, 0x94,
   0x4d, 0x95, 0x62, 0x0b, 0xa4, 0x6c, 0xd5, 0x92, 0x0d, 0xac, 0x49, 0xbf,
   0x27, 0x09, 0xa4, 0x4c, 0xa9, 0x50, 0x0d, 0xec, 0x8f, 0x72, 0x63, 0x07,
   0x94, 0xa8, 0x2c, 0x14, 0x09, 0xac, 0xa8, 0xea, 0x02, 0x03, 0x24, 0x40,
   0x69, 0x05, 0x05, 0x4c, 0xa0, 0xd5, 0x01, 0x15, 0xb8, 0x40, 0x5a, 0x01,
   0x09, 0x00, 0xa0, 0x6a, 0x01, 0x00, 0x00, 0x80, 0x44, 0x00, 0x00, 0x00,
   0x40, 0x7d, 0x01, 0x00, 0x00, 0x80, 0x82, 0x00, 0x00, 0x00, 0x80, 0x81,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
*/
   
typedef struct
{
  char nome[4];
  int pontos;
} rank;

rank jogador;
rank players[3] = {{"JOS", 250},
                   {"AND", 750},
                   {"DAN", 500}};

int drawMenu();
void drawSubJogar();
void Inserir();
void drawRanking();
void Organizar();
void drawCreditos();
void drawSair();
 
void setup(void) {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
 
  tft.init(240, 240, SPI_MODE2);    // Init ST7789 display 240x240 pixel
  tft.setRotation(2);

  tft.fillScreen(ST77XX_BLACK);
  //tft.drawBitmap(tft.width()/2, 194, nave, nave_w, nave_h, ST77XX_YELLOW);
}
 
void loop() {
  switch(drawMenu())
  {
    case 76:
      Organizar();
      drawSubJogar();
      break;
         
    case 102:
      Organizar();
      drawRanking();
      break;
        
    case 128:
      drawCreditos();
      break;

    case 154:
      drawSair();
      break;

    default:
      break;
  }
}

int drawMenu()
{
  int pos_y = 76;

  do
  {
    tft.setTextWrap(false);   //Nao vai ter quebra de linha
    tft.drawRect(1, 1, tft.width()-2, tft.height()-2, ST77XX_WHITE);  //Faz a borda em branco com 1 pixel de distancia da beirada do display
    tft.setCursor(36, 35);  //y = 30  //Determina a posição do cursor
    tft.setTextColor(ST77XX_GREEN);
    tft.setTextSize(1); //Tamanho da fonte
    tft.setFont(&FreeSansBold12pt7b);   //22p altura
    tft.println("Nibirus Attack");
    tft.setFont(NULL);  //Retorna para a fonte padrão
    tft.setTextSize(2);
    tft.setCursor(36, 76);  //y = 76
    tft.print("Jogar");
    tft.setCursor(36, 102);
    tft.print("Ranking");
    tft.setCursor(36, 128);
    tft.print("Creditos");
    tft.setCursor(36, 154);
    tft.print("Sair");
  
    if(!digitalRead(3))
    {
      if(pos_y < 154)
      {
        pos_y += 26;
      }
      delay(50);
    }
  
    if(!digitalRead(2))
    {
      if(pos_y > 76)
      {
        pos_y -= 26;
      }
      delay(50);
    }
  
    switch(pos_y)
    {
      case 76:
        tft.setCursor(20, pos_y);
        tft.print(">");
        tft.setTextColor(ST77XX_BLACK);
        tft.setCursor(20, 102);
        tft.print(">");
        tft.setCursor(20, 128);
        tft.print(">");
        tft.setCursor(20, 154);
        tft.print(">");
        tft.setTextColor(ST77XX_GREEN);
        break;
      
      case 102:
        tft.setCursor(20, pos_y);
        tft.print(">");
        tft.setTextColor(ST77XX_BLACK);
        tft.setCursor(20, 76);
        tft.print(">");
        tft.setCursor(20, 128);
        tft.print(">");
        tft.setCursor(20, 154);
        tft.print(">");
        tft.setTextColor(ST77XX_GREEN);
        break;
      
      case 128:
        tft.setCursor(20, pos_y);
        tft.print(">");
        tft.setTextColor(ST77XX_BLACK);
        tft.setCursor(20, 102);
        tft.print(">");
        tft.setCursor(20, 76);
        tft.print(">");
        tft.setCursor(20, 154);
        tft.print(">");
        tft.setTextColor(ST77XX_GREEN);
        break;
  
      case 154:
        tft.setCursor(20, pos_y);
        tft.print(">");
        tft.setTextColor(ST77XX_BLACK);
        tft.setCursor(20, 102);
        tft.print(">");
        tft.setCursor(20, 128);
        tft.print(">");
        tft.setCursor(20, 76);
        tft.print(">");
        tft.setTextColor(ST77XX_GREEN);
        break;
    }
    
    if(!digitalRead(4))
    {
      tft.fillScreen(ST77XX_BLACK);
      return pos_y;
    }
  } while(1);
}

void drawSubJogar()
{
  tft.setTextColor(ST77XX_BLUE);
  int jogo = 0;
  tft.drawRect(1, 1, tft.width()-2, tft.height()-2, ST77XX_WHITE);
  int i, x, y=80;
  tft.setCursor(15, 40);
  tft.print("Selecionar jogador");
  for(i=0; i<3; i++)
  {
    x = 50;
    tft.setCursor(x, y);
    tft.print(players[i].nome);
    x += 90;
    tft.setCursor(x, y);
    tft.print(players[i].pontos);
    y += 31;
  }
  tft.setCursor(30, y);
  tft.print("Criar novo");
  
  y = 80;
  do
  {
    if(jogo == 0)
    {
      if(!digitalRead(3))
      {
        if(y < 173)
        {
          y += 31;
        }
        delay(150);
      }
      
      if(!digitalRead(2))
      {
        if(y > 80)
        {
          y -= 31;
        }
        delay(150);
      }
      
      switch(y)
      {
        case 80:
          tft.setCursor(34, y);
          tft.print(">");
          tft.setTextColor(ST77XX_BLACK);
          tft.setCursor(34, 111);
          tft.print(">");
          tft.setCursor(34, 142);
          tft.print(">");
          tft.setCursor(14, 173);
          tft.print(">");
          tft.setTextColor(ST77XX_BLUE);
          break;
        
        case 111:
          tft.setCursor(34, y);
          tft.print(">");
          tft.setTextColor(ST77XX_BLACK);
          tft.setCursor(34, 80);
          tft.print(">");
          tft.setCursor(34, 142);
          tft.print(">");
          tft.setCursor(14, 173);
          tft.print(">");
          tft.setTextColor(ST77XX_BLUE);
          break;
        
        case 142:
          tft.setCursor(34, y);
          tft.print(">");
          tft.setTextColor(ST77XX_BLACK);
          tft.setCursor(34, 80);
          tft.print(">");
          tft.setCursor(34, 111);
          tft.print(">");
          tft.setCursor(14, 173);
          tft.print(">");
          tft.setTextColor(ST77XX_BLUE);
          break;
    
        case 173:
          tft.setCursor(14, y);
          tft.print(">");
          tft.setTextColor(ST77XX_BLACK);
          tft.setCursor(34, 80);
          tft.print(">");
          tft.setCursor(34, 111);
          tft.print(">");
          tft.setCursor(34, 142);
          tft.print(">");
          tft.setTextColor(ST77XX_BLUE);
          break;
      }
    }
    else if(jogo == 1)
    {
      tft.drawRect(1, 1, tft.width()-2, tft.height()-2, ST77XX_WHITE);
      tft.setCursor(40, tft.height()/2);
      tft.print("Em Construcao!");
    }
    else
    {
      tft.setTextSize(3);
      tft.drawRect(1, 1, tft.width()-2, tft.height()-2, ST77XX_WHITE);
      tft.setCursor(30, tft.height()/4);
      tft.print("Nome");
      
      char letra[3];
      for(i=0; i<3; i++)
      {
        letra[i] = 65;
      }

      int j = 0;
      x = 50;
      do
      {
        for(i=0; i<3; i++)
        {
          int x1 = i*60 + 50;
          tft.setCursor(x1, tft.height()/2);
          tft.print(letra[i]);
        }
        tft.setCursor(x, tft.height()/2+10);
        tft.print("_");
        /*delay(500);
        tft.setTextColor(ST77XX_BLACK);
        tft.setCursor(x, tft.height()/2+10);
        tft.print("_");
        tft.setTextColor(ST77XX_BLUE);
        delay(500);*/

        if(!digitalRead(3))
        {
          if(letra[j]<90)
          {
            tft.setTextColor(ST77XX_BLACK);
            tft.setCursor(x, tft.height()/2);
            tft.print(letra[j]);
            tft.setTextColor(ST77XX_BLUE);
            letra[j]++;
            delay(150);
          }
        }
      
        if(!digitalRead(2))
        {
          if(letra[j]>65)
          {
            tft.setTextColor(ST77XX_BLACK);
            tft.setCursor(x, tft.height()/2);
            tft.print(letra[j]);
            tft.setTextColor(ST77XX_BLUE);
            letra[j]--;
            delay(150);
          }
        }

        if(!digitalRead(4))
        {
          if(j<2)
          {
            tft.setTextColor(ST77XX_BLACK);
            tft.setCursor(x, tft.height()/2+10);
            tft.print("_");
            tft.setTextColor(ST77XX_BLUE);
            x += 60;
            j++;
          }
          else
          {
            break;
          }
          delay(200);
        }

        if(!digitalRead(5))
        {
          tft.fillScreen(ST77XX_BLACK);
          return;
        }
      }while(1);

      for(i = 0; i<3; i++)
      {
        jogador.nome[i] = letra[i];
      }

      for(i = 0; i<3; i++)
      {
        if(!strcmp(jogador.nome, players[i].nome))
        {
          tft.fillScreen(ST77XX_BLACK);
          tft.drawRect(1, 1, tft.width()-2, tft.height()-2, ST77XX_WHITE);
          tft.setTextSize(2);
          tft.setCursor(15, tft.height()/2);
          tft.print("Nome ja registrado");
          delay(1000);
          jogo = 0;
          tft.fillScreen(ST77XX_BLACK);
        }
      }
      if(jogo == 0)
        break;

      tft.fillScreen(ST77XX_BLACK);
      tft.drawRect(1, 1, tft.width()-2, tft.height()-2, ST77XX_WHITE);
      tft.setCursor(30, tft.height()/4);
      tft.print("Pontos");
      
      int pontos = 0;
      do
      {
        tft.setCursor(tft.width()/2 - 20, tft.height()/2);
        tft.print(pontos);

        if(!digitalRead(3))
        {
          if(pontos<1000000)
          {
            tft.setTextColor(ST77XX_BLACK);
            tft.setCursor(tft.width()/2 - 20, tft.height()/2);
            tft.print(pontos);
            tft.setTextColor(ST77XX_BLUE);
            pontos++;
            delay(50);
          }
        }
      
        if(!digitalRead(2))
        {
          if(pontos>0)
          {
            tft.setTextColor(ST77XX_BLACK);
            tft.setCursor(tft.width()/2 - 20, tft.height()/2);
            tft.print(pontos);
            tft.setTextColor(ST77XX_BLUE);
            pontos--;
            delay(50);
          }
        }

        if(!digitalRead(4))
        {
          break;
          delay(1000);
        }

        if(!digitalRead(5))
        {
          tft.fillScreen(ST77XX_BLACK);
          return;
        }
      }while(1);

      if(pontos == 0)
      {
        tft.fillScreen(ST77XX_BLACK);
        tft.drawRect(1, 1, tft.width()-2, tft.height()-2, ST77XX_WHITE);
        tft.setTextSize(2);
        tft.setCursor(30, tft.height()/2);
        tft.print("Pontuacao nula");
        delay(1000);
        jogo = 0;
        tft.fillScreen(ST77XX_BLACK);
      }
      if(jogo == 0)
        break;
      
      jogador.pontos = pontos;
      if(jogador.pontos < players[2].pontos)
      {
        players[2] = jogador;
      }
      else
      {
        Inserir();
      }

      tft.fillScreen(ST77XX_BLACK);
      tft.drawRect(1, 1, tft.width()-2, tft.height()-2, ST77XX_WHITE);
      tft.setTextSize(2);
      tft.setCursor(10, tft.height()/2);
      tft.print("Jogador adicionado!");
      delay(2000);
      jogo = 1;
      y = 80;
      tft.fillScreen(ST77XX_BLACK);
    }

    if(!digitalRead(4))
    {
      if(y < 173)
      {
        tft.fillScreen(ST77XX_BLACK);
        jogo = 1;
      }
      else
      {
        tft.fillScreen(ST77XX_BLACK);
        jogo = 2;
      }
    }
    
    if(!digitalRead(5))
    {
      tft.fillScreen(ST77XX_BLACK);
      break;
    }
  } while(1);
}

void Inserir()
{
  int i;
  for (i = 0; i<3; i++)
  {
    rank aux;
    if (jogador.pontos > players[i].pontos) //Compara pontuação do jogador com as do ranking
    {
      aux = players[i];
      players[i] = jogador;
      jogador = aux;
    }
  }
}

void drawRanking()
{
  int i, x, y=90;
  tft.drawRect(1, 1, tft.width()-2, tft.height()-2, ST77XX_WHITE);  //Faz a borda em branco com 1 pixel de distancia da beirada do display
  tft.setTextColor(ST77XX_RED);
  tft.setCursor(80, 40);
  tft.print("Ranking");
  for(i=0; i<3; i++)
  {
    x = 40;
    tft.setCursor(x, y);
    tft.print(players[i].nome);
    x += 90;
    tft.setCursor(x, y);
    tft.print(players[i].pontos);
    y += 31;
  }

  while(digitalRead(5))
  {}
  tft.fillScreen(ST77XX_BLACK);
}

void Organizar()
{
  int i;
  bool subs;
  
  do
  {
    subs = 0;
    for (i = 0; i<2 /*&& players[i+1].pontos != 0*/; i++)
    {
      rank aux;
      if (players[i].pontos < players[i+1].pontos) //Compara as pontuações do ranking
      {
        aux = players[i+1];
        players[i+1] = players[i];
        players[i] = aux;
        subs = 1;
      }
    }
  } while(subs != 0);
}

void drawCreditos()
{
  int y;
  tft.drawRect(1, 1, tft.width()-2, tft.height()-2, ST77XX_WHITE);  //Faz a borda em branco com 1 pixel de distancia da beirada do display
  tft.setTextColor(ST77XX_MAGENTA);
  tft.setCursor(25, 35);
  tft.print("Desenvolvedores");
  tft.setCursor(25, 70);
  tft.println("Andre");
  y = tft.getCursorY();
  tft.setCursor(25, y);
  tft.println("\tProgramador");
  tft.setCursor(25, 110);
  tft.println("Josue");
  y = tft.getCursorY();
  tft.setCursor(25, y);
  tft.println("\tIdealizaor");
  tft.setCursor(25, 150);
  tft.println("Dani");
  y = tft.getCursorY();
  tft.setCursor(25, y);
  tft.println("\tScrum Master");
  tft.setCursor(25, 190);
  tft.println("Hamada");
  y = tft.getCursorY();
  tft.setCursor(25, y);
  tft.println("\tPatrocinador");
    
  while(digitalRead(5))
  {}
  tft.fillScreen(ST77XX_BLACK);
}

void drawSair()
{
  tft.drawRect(1, 1, tft.width()-2, tft.height()-2, ST77XX_WHITE);  //Faz a borda em branco com 1 pixel de distancia da beirada do display
  tft.setTextColor(ST77XX_YELLOW);
  tft.setCursor(50, 104);
  tft.print("Saindo...");
  delay(15000);
  tft.fillScreen(ST77XX_BLACK);
  delay(15000);
}
