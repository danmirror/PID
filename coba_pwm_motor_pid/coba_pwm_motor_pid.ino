
//Motor A
int m1 = 5;  
int m2 = 4;    
int multitrun =A1;
int last_error=0;
int error=0;
int max_error=100;
int tombol_1=A7; //pin tombol 1
float I=0;
float D=0;
float ki=0.00095; //intragral masukan
float kd=2; //deferent masukan
float kp=2; //proposa masukan
float output=0;
int sensor;
int input=512;

void setup() 
{
   Serial.begin(9600);
   pinMode(tombol_1,INPUT_PULLUP);
   pinMode(m1, OUTPUT);
   pinMode(m2, OUTPUT);
   pinMode(9,INPUT);
}
//char count= "512";
int cnt=0;
int old_count=0;
int rc_in=0;
bool motor_interlock;


void loop() {
  sensor = analogRead(A1);
  Serial.println(sensor);
   //Serial.print ("out: ");
  //Serial.println(output);
//input=400;
  last_error=error;
  error= input-sensor;
  if (error>max_error)error=max_error;
  if (error<-max_error)error=-max_error;
  if (abs(error) < max_error){
    I= I+error;
  }
  else {
    I=0;
  }

  D = error - last_error;
  output= (error * kp + I*ki + D*kd ); //rumus pid 
  
  //Serial.print ("error: ");
  //Serial.println(error);

  
  //Serial.println("  ");
  //Serial.print ("out: ");
  //Serial.println(output);
/*
  if (sensor<=300){

    analogWrite(m2,0 );           // Write the output to the output pin
     analogWrite(m1,0);
  }
  if (sensor>=1000){
    analogWrite(m2,0 );           // Write the output to the output pin
     analogWrite(m1,0);
  }
  
  if (output<=0){
     analogWrite(m2,0 );           // Write the output to the output pin
     analogWrite(m1,abs( output));
  }
  else{
     analogWrite(m2,abs( output)); // Write the output to the output pin
     analogWrite(m1, 0);
  }
  if (output==0){
     analogWrite(m2,0);           // Write the output to the output pin
     analogWrite(m1,0);
  }
  if (output==1){
    analogWrite(m2,1);
    analogWrite(m1,0);
 }

rc_in=pulseIn(9,HIGH);
int keadaanTombol = digitalRead(tombol_1);
 if (keadaanTombol == 0){
  cnt++;
  delay(100);
  if (cnt>=3)cnt=0;
  //kelipatan 80 buang mundur apabila maju kelipatan -80
  }
if(cnt==0){
  input=512;
}
if (cnt==1){
   input=512+240;
}
if (cnt==2){
   input=512-240;
}
/*
 if (count=='1')input = 512+80;
 if (count=='2')input = 512+40;       //1
 
  if (count=='3')input = 512-80;
 if (count=='4')input = 512;          //2

  if (count=='5')input = 512+80*2;
 if (count=='6')input = 512+30*2;     //3


  if (count=='7')input = 512-80*2;
 if (count=='8')input = 512;          //4


  if (count=='9')input = 512+80*3;
 if (count=='A')input = 512+10*3;     //5


  if (count=='B')input = 512-80*3;
 if (count=='C')input = 512;//6
 
  if (count=='D')input = 512+80*4;    //7
 if (count=='E')input = 512;
 
 */
 
}
