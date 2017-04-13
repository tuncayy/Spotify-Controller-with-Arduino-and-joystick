
 int PlayPin = 0; //Push button pin
 int NextPin = 2;
 int PrevPin = 1;
 int potansPin = 3;
 int ledPin = 4; 
 int gerisar = 9;
 int ilerisar = 8;

int rx = 4;
int ry = 5;
 
 int buttonState;
  int buttonStateNext;
   int buttonStatePrev;
 int lastButtonState = LOW;


 int lastreadPotans = 0;

 int play = 3;
 int play2 = 4;
 int set = 0;
 int set1 = 0;
int set2 = 0;
int set3 = 0;
int set4 = 0;
 
 int enable = 0;
 int enable1 = 0;
 int enable2 = 0;
 int enable3 = 0;
 int enable4 = 0;


 int firstPress = 0;
 int lastPress = 0;
 
void setup() {
  // put your setup code here, to run once:

   pinMode (PlayPin, INPUT);
   pinMode (ledPin, OUTPUT);
   pinMode(gerisar, INPUT);
   pinMode(ilerisar, INPUT);
  pinMode(PrevPin, INPUT);
  pinMode(NextPin, INPUT);
    
    pinMode(rx, INPUT);
    pinMode(ry, INPUT);

   Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PlayPin, LOW); 
int reading= analogRead(PlayPin);
buttonState = reading;
int readnextbutton = analogRead(NextPin);
buttonStateNext = readnextbutton;
int readprevbutton = analogRead(PrevPin);
buttonStatePrev = readprevbutton;
int readPotansfirst = analogRead(potansPin);
int readPotans = readPotansfirst / 80;


int readilerisar = digitalRead(ilerisar);
int readgerisar = digitalRead(gerisar);

int readrx = analogRead(rx);
int readry = analogRead(ry);


delay(100);
//Serial.println(readPotans/60);



if(buttonState == 1023)
{
      if(enable == 0)
      {
          if (set == 0) {
                if (buttonState == 1023) {
                  Serial.println("play|");
                  set = 1;
                  enable = 1;
                }
              }
          else if(set == 1)
          {
            if (buttonState == 1023) {
                  Serial.println("pause|");
                  set = 0;
                  enable = 1;
                }
          }
      }
}
else if(buttonState == 0)
{
  enable = 0;
}


if(buttonStateNext == 1023)
{
      if(enable1 == 0)
      {
          if (set1 == 0) {
                if (buttonStateNext == 1023) {
                  Serial.println("next|");
                  set1 = 1;
                  enable1 = 1;
                }
              }
      }
}
else if(buttonStateNext == 0)
{
  set1 = 0;
  enable1 = 0;
}


if(buttonStatePrev > 500)
{
      if(enable2 == 0)
      {
          if (set2 == 0) {
                if (buttonStatePrev == 1023) {
                  Serial.println("prev|");
                  set2 = 1;
                  enable2 = 1;
                }
              }
      }
}
else if(buttonStatePrev == 0)
{
  set2 = 0;
  enable2 = 0;
}


if(readPotans != lastreadPotans)
{
  delay(0);
         
  int change = lastreadPotans - readPotans;
  if(readPotans > lastreadPotans)
  {
    int change = readPotans - lastreadPotans;
    Serial.print(change);
    Serial.println("-");
    lastreadPotans = readPotans;
  }
  else
  {
    int change = lastreadPotans - readPotans;
    Serial.print(change);
    Serial.println("+");
    lastreadPotans = readPotans;
  }
      
}


if(readilerisar == 1)
{
  Serial.println("ileri|");
}
if(readgerisar == 1)
{
  Serial.println("geri|");
}


if(readrx > 600)
{
  Serial.println("down|");
    Serial.println(readrx);
    Serial.println(readry);
  
}if(readrx < 200)
{
  Serial.println("up|");
  Serial.println(readrx);
    Serial.println(readry);
    
}



if(readry > 600)
{ 
 
  if(enable3 == 0)
  {
    if(set3 == 0)
    {
      firstPress = millis();
      set3 = 1;
      enable3 = 1;
    delay(1000);
    }
  }
}

if(enable3 == 1)
{
  if(analogRead(ry) > 600)
  {
      Serial.println("ileri|");
      Serial.println(readrx);
      Serial.println(readry);
      set3 = 2;
    //  enable3 = 0;
    
  }
  else if(set3 != 2)
  {
    Serial.println("next|");
    set3 =0;
    enable3 = 0;
  }
}
if(readry <600 && readry > 400)
{
  set3 = 0;
  enable3 = 0;
  set4  = 0;
  enable4 = 0;
}
///----------------left movement
if(readry < 200)
{
   if(enable4 == 0)
  {
    if(set4 == 0)
    {
      firstPress = millis();
      set4 = 1;
      enable4 = 1;
    delay(1000);
    }
  }
}
if(enable4 == 1)
{
  if(analogRead(ry) < 200)
  {
      Serial.println("geri|");
      Serial.println(readrx);
      Serial.println(readry);
      set4 = 2;
    //  enable4 = 0;
    
  }
  else if(set4 != 2)
  {
    Serial.println("prev|");
    set4 =0;
    enable4 = 0;
  }
}


}
