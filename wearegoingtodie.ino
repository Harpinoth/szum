#define X_MAX_PIN         2
#define Y_MAX_PIN          15
#define Z_MAX_PIN          19
int k1;
int k2;
int k3;
int buttah2;
#define buttah          3
int krokiX=0;
int krokiY=0;
int krokiZ=0;
int a;
String d;
char b;
int x = 0;
int y = 0;
int z = 0;
int flag = 1;

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_CS_PIN           53

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_CS_PIN           49

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_CS_PIN           40

void setup() {
  // put your setup code here, to run once:

/*pinMode(X_MAX_PIN,INPUT);
digitalWrite(X_MAX_PIN,HIGH);
Serial.begin(9600);*/
pinMode(buttah,INPUT);
pinMode(X_STEP_PIN,OUTPUT);
pinMode(X_DIR_PIN,OUTPUT);
pinMode(X_ENABLE_PIN,OUTPUT);
pinMode(X_CS_PIN,OUTPUT);
pinMode(Y_CS_PIN,OUTPUT);
pinMode(Y_STEP_PIN,OUTPUT);
pinMode(Y_DIR_PIN,OUTPUT);
pinMode(Y_ENABLE_PIN,OUTPUT);
pinMode(Z_CS_PIN,OUTPUT);
pinMode(Z_STEP_PIN,OUTPUT);
pinMode(Z_DIR_PIN,OUTPUT);
pinMode(Z_ENABLE_PIN,OUTPUT);
digitalWrite(X_STEP_PIN,LOW);
digitalWrite(X_DIR_PIN,LOW);
digitalWrite(X_ENABLE_PIN,LOW);
digitalWrite(X_CS_PIN,HIGH);
digitalWrite(Y_STEP_PIN,LOW);
digitalWrite(Y_DIR_PIN,LOW);
digitalWrite(Y_ENABLE_PIN,LOW);
digitalWrite(Y_CS_PIN,HIGH);
digitalWrite(Z_STEP_PIN,LOW);
digitalWrite(Z_DIR_PIN,LOW);
digitalWrite(Z_ENABLE_PIN,LOW);
digitalWrite(Z_CS_PIN,HIGH);
pinMode(X_MAX_PIN,INPUT);
digitalWrite(X_MAX_PIN,HIGH);
pinMode(Y_MAX_PIN,INPUT);
digitalWrite(Y_MAX_PIN,HIGH);
pinMode(Z_MAX_PIN,INPUT);
digitalWrite(Z_MAX_PIN,HIGH);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
/*buttah=digitalRead(X_MAX_PIN);
delay(100);
Serial.print(buttah);*/
k1=digitalRead(X_MAX_PIN);
k2=digitalRead(Y_MAX_PIN);
k3=digitalRead(Z_MAX_PIN);
buttah2=digitalRead(buttah);
/*if((buttah2==0)&&(k1==0)&&(k2==0)&&(k3==0))
{
for(int i=0;i<=99;i++)
  {
    
    digitalWrite(X_STEP_PIN,HIGH);
    delayMicroseconds(130);
    digitalWrite(X_STEP_PIN,LOW);
    digitalWrite(Y_STEP_PIN,HIGH);
    delayMicroseconds(130);
    digitalWrite(Y_STEP_PIN,LOW);
    digitalWrite(Z_STEP_PIN,HIGH);
    delayMicroseconds(130);
    digitalWrite(Z_STEP_PIN,LOW);
    
  }
  }
  */
  
  while(Serial.available())
  {
    b=Serial.read();
      d=d+b;
      if(b == '\n')
      {
        sscanf(d.c_str(),"x %d y %d z %d",&x,&y,&z);
        flag = 0;
        d = String("");
      }
          
    krokiX=x;
    krokiY=y;
    krokiZ=z;
  }
  if (krokiX>0 && k1==0)
  {  
    digitalWrite(X_DIR_PIN,LOW);
    digitalWrite(X_STEP_PIN,HIGH);
    krokiX--;
  }
  else if (krokiX<0)
  {  
    digitalWrite(X_DIR_PIN,HIGH);
    digitalWrite(X_STEP_PIN,HIGH);
    krokiX++;
  }

  if (krokiY>0 && k2==0)
  {  
    digitalWrite(Y_DIR_PIN,LOW);
    digitalWrite(Y_STEP_PIN,HIGH);
    krokiY--;
  }
  else if (krokiY<0)
  {  
    digitalWrite(Y_DIR_PIN,HIGH);
    digitalWrite(Y_STEP_PIN,HIGH);
    krokiY++;
  }

  if (krokiZ>0 && k3==0)
  {  
    digitalWrite(Z_DIR_PIN,LOW);
    digitalWrite(Z_STEP_PIN,HIGH);
    krokiZ--;
  }
  else if (krokiZ<0)
  {  
    digitalWrite(Z_DIR_PIN,HIGH);
    digitalWrite(Z_STEP_PIN,HIGH);
    krokiZ++;
  } 
  if ( flag == 0 )
  {
    Serial.write("OK");
    flag = 1;
  }
   
    delayMicroseconds(1300); 
    digitalWrite(X_STEP_PIN,LOW);  
    digitalWrite(Y_STEP_PIN,LOW);
    digitalWrite(Z_STEP_PIN,LOW);   
    
  if(k1==1 && krokiX>0){krokiX=0;}
  if(k2==1 && krokiY>0){krokiY=0;}
  if(k3==1 && krokiZ>0){krokiZ=0;}
}

