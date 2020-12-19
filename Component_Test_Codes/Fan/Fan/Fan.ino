//  written by : GODSON THOMAS
int k=10;

void setup()
{
  //MOTOR DECLARATION
  
  pinMode(4,OUTPUT);
  pinMode(2,OUTPUT);


  //STARTING SERIAL COMMUNICATION
  
  Serial.begin(9600);
}
void loop()
{
  if(k==10){
    ON();
    
  }
    

 }
void ON(){
     digitalWrite(4,HIGH);
  digitalWrite(2,LOW);
}
