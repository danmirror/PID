//===========================
// PID MOTOR
// Danu Andrean Repository
//
//===========================


boolean motor_start = false;
const byte pin_a = 3;   //for encoder pulse A
const byte pin_b = 2;   //for encoder pulse B
const byte pin_fwd = 9; //for H-bridge: run motor forward
const byte pin_bwd = 4; //for H-bridge: run motor backward
const byte pin_pwm = 6; //for H-bridge: motor speed

int encoder = 0;
int m_direction = 0;
int sv_speed = 100;     //this value is 0~255
double pv_speed = 0;
double set_speed = 0;
double e_speed = 0; //error of speed = set_speed - pv_speed
double e_speed_pre = 0;  //last error of speed
double e_speed_sum = 0;  //sum error of speed
double pwm_pulse = 0;     //this value is 0~255
double kp = 0;
double ki = 0;
double kd = 0;
int timer1_counter; //for timer
int i=0;

void setup() {
  
  pinMode(pin_a,INPUT_PULLUP);
  pinMode(pin_b,INPUT_PULLUP);
  pinMode(pin_fwd,OUTPUT);
  pinMode(pin_bwd,OUTPUT);
  pinMode(pin_pwm,OUTPUT);

 
  attachInterrupt(digitalPinToInterrupt(pin_a), detect_a, RISING);
  // start serial port at 9600 bps:
  Serial.begin(9600);
  
  //--------------------------timer interupt setup
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  timer1_counter = 59286;   // preload timer 65536-16MHz/256/2Hz (34286 for 0.5sec) (59286 for 0.1sec)

  
  TCNT1 = timer1_counter;   // preload timer
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();             // enable all interrupts
  //--------------------------timer setup


  analogWrite(pin_pwm,0);   //stop motor
  digitalWrite(pin_fwd,0);  //stop motor
  digitalWrite(pin_bwd,0);  //stop motor
}

void loop() {
  
  digitalWrite(pin_fwd,1);      //run motor run forward
  digitalWrite(pin_bwd,0);
  digitalWrite(pin_fwd,1);      //run motor run forward
  digitalWrite(pin_bwd,0);
  
//  =======================set PID============/
  set_speed = 30;
  kp = 0.07;
  ki =0.05;
  kd = 0.03; 
  motor_start = 1;
}

void detect_a() {
  encoder+=1;                           //increasing encoder at new pulse
  m_direction = digitalRead(pin_b);     //read direction of motor
}

ISR(TIMER1_OVF_vect)                     // interrupt service routine - tick every 0.1sec
{
  TCNT1 = timer1_counter;                // set timer
  pv_speed = 60.0*(encoder/200.0)/0.1;  //calculate motor speed, unit is rpm
  encoder=0;
 
 
//  Serial.print("speed");
  Serial.println(pv_speed);         //Print speed (rpm) value to Visual Studio

  //PID program
  if (motor_start){
    e_speed = set_speed - pv_speed;
    pwm_pulse = e_speed*kp + e_speed_sum*ki + (e_speed - e_speed_pre)*kd;
    e_speed_pre = e_speed;      //save last (previous) error
    e_speed_sum += e_speed;     //sum of error
    if (e_speed_sum >4000) e_speed_sum = 4000;
    if (e_speed_sum <-4000) e_speed_sum = -4000;
  }
  
    e_speed = 0;
    e_speed_pre = 0;
    e_speed_sum = 0;
   
  
  //update new speed
  if (pwm_pulse <255 & pwm_pulse >0){
    analogWrite(pin_pwm,pwm_pulse);  //set motor speed  
    analogWrite(pin_pwm,pwm_pulse);
  }
  else{
    if (pwm_pulse>255){
      analogWrite(pin_pwm,255);
      analogWrite(pin_pwm,255);
    }
  }
  
}
