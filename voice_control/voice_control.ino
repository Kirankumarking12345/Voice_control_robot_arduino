
int lir=2;
int rir=3;
int lm1=4;//+ve
int lm2=5;//-ve
int rm1=6;//+ve
int rm2=7;//-ve
int lirvalue;
int rirvalue;

void setup() 
{
  Serial.begin(9600);
  pinMode(lir,INPUT);
  pinMode(rir,INPUT);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
 
}

void loop() 
{
  String cmd;
  while(Serial.available()>0)
  {
    delay(3);
    char c =Serial.read();
    cmd +=c;
  }
  if(cmd.length()>0)
  {
    Serial.println(cmd);
    if(cmd=="forward")
    {
      forward();
    }
    else if(cmd=="backward")
    {
      backward();
    }
    else if(cmd=="left")
    {
      left();
    }
    else if(cmd=="right")
    {
      right();
    }
    else
    {
      Stop();
    }
  }
  
}
void forward()
{
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
}
void backward()
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,1);
  digitalWrite(rm1,0);
  digitalWrite(rm2,1);
}
void Stop()
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,0);
}
void left()
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,1);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
}
void right()
{
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,1);
}
