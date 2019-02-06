#include<LiquidCrystal.h>
bool controllo = true;
int meta;
int contatore;
const int meno = 2;
const int piu = 3;
const int conferma = 8;
const int resetta = 9;
int precedente;
int x = 1;

LiquidCrystal lcd(11,10,7,6,5,4);


void setup()
{
    controllo = true;
    Serial.begin(9600);
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(meno, INPUT_PULLUP);
    pinMode(piu, INPUT_PULLUP);
    pinMode(conferma, INPUT_PULLUP);
    pinMode(resetta, INPUT_PULLUP);
    meta = 30;
    contatore = 0;
    precedente = 0;
}

void loop()
{
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  
  if(controllo == true)
  {
    aggiornalcd();
    //Serial.println("inserisci meta");
    while(controllo == true){
        inseriscimeta();
    }
   
  }
  else
  {
    gioco();
  }
  
  
    
}

void restart()
{
  controllo = true;
}

void inseriscimeta(){
  //Serial.println("dentro");
  
  if(digitalRead(meno) == LOW)
  {
    aggiornalcd();
    Serial.println("prova");
    meta--;
    while(digitalRead(meno) == LOW)
    {
    
    Serial.println("meno");
    
    }
  }

  if(digitalRead(piu) == LOW)
  {
    aggiornalcd();
    meta++;
    Serial.println("funziona?");
    while(digitalRead(piu) == LOW)
    {
    Serial.println("piu");
    
  }
  }
  if(digitalRead(conferma) == LOW)
  {
    aggiornalcd();
    controllo = false;
    while(digitalRead(conferma) == LOW)
    {
    Serial.println("CONFERMA");
    
    }
  }
  if(digitalRead(resetta) == LOW)
  {
    setup();
    while(digitalRead(resetta) == LOW)
    {
    }
  }
  
}

void gioco(){
  
  
  aggiornalcd2();

  if(digitalRead(meno) == LOW)
  {
    if(x>0){
      if(x+1+precedente!=7){
        x--;
      }
      else{
        if(x-1>0){
          x--;
          x--;
        }
      }
      
    }
    precedente = x;
    aggiornalcd2();
    
    while(digitalRead(meno) == LOW)
    {
    
    Serial.println("meno");
    
    }
  }

  if(digitalRead(piu) == LOW)
  {
if(x<7){
      if(x+1+precedente!=7){
        x++;
      }
      else{
        if(x+1<7){
          x++;
          x++;
        }
      }
      
    }
    precedente = x;
    aggiornalcd2();
    
    while(digitalRead(piu) == LOW)
    {
    Serial.println("piu");
    
  }
  }
  if(digitalRead(conferma) == LOW)
  {


    contatore = contatore + x;
    aggiornalcd2();
    while(digitalRead(conferma) == LOW)
    {
    
    }
  }
  if(digitalRead(resetta) == LOW)
  {
    setup();
    while(digitalRead(resetta) == LOW)
    {
    }
  }
  
}

void aggiornalcd(){
  lcd.clear();
  lcd.setCursor(0,0);
  
  lcd.print("inserisci meta(30-100):");
  lcd.setCursor(0,1);
  lcd.print("-     "+ String(meta) +"    +");
}

void aggiornalcd2(){
  lcd.clear();
  lcd.setCursor(0,0);
  
  lcd.print("scegli numero"+x);
  lcd.setCursor(0,1);
  lcd.print("contatore  "+contatore);
}

void controllavittoria(){
  
}
