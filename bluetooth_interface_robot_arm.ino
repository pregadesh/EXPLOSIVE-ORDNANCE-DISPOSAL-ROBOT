 

int IN1 = 2; // GPIO12 D6
int IN2 = 3;
int IN3 = 4; //
int IN4 = 5;

const int arm1=7;
const int arm2=6;
const int dip1=9;
const int dip2=8;

const int cut1=10;
const int cut2=11;

const int angle1=12;
const int angle2=13;

//const int VCC = 8;
//--------------------------Call A Function-------------------------------//  
void front(){
    Serial.println("MOVING FORWARD");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4,HIGH);
   delay(3000);
   digitalWrite(IN1, LOW);   
   digitalWrite(IN4, LOW); 
   delay(200);
}
void back(){
    Serial.println("MOVING BACKWARD");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    delay(3000);
   digitalWrite(IN2, LOW);   
   digitalWrite(IN3, LOW); 
   delay(200);
}
void left(){
    Serial.println("TURNING LEFT");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4,LOW);
    delay(500);
   digitalWrite(IN1, LOW);   
   digitalWrite(IN3, LOW); 
   delay(200);
}
void right(){
    Serial.println("TURNING ROGHT");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4,HIGH);
    delay(500);
   digitalWrite(IN2, LOW);   
   digitalWrite(IN4, LOW);
   delay(200);
}
void stop(){
    Serial.println("STOP");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4,LOW);
}
void armup(){
  Serial.println("ARM UP");
  digitalWrite(arm1,HIGH);
  digitalWrite(arm2,LOW);
  delay(100);
  digitalWrite(arm1,LOW);
  delay(100);
}

void armdown(){
  Serial.println("ARM DOWN");
  digitalWrite(arm2,HIGH);
  digitalWrite(arm1,LOW);
  delay(100);
  digitalWrite(arm2,LOW);
  delay(100);
}
void armclose(){
  Serial.println("ARM CLOSE");
  digitalWrite(dip1,HIGH);
  digitalWrite(dip2,LOW);
  delay(1000);
  digitalWrite(dip1,LOW);
  delay(500);
}

void armopen(){
  Serial.println("ARM OPEN");
  digitalWrite(dip2,HIGH);
  digitalWrite(dip1,LOW);
  delay(1000);
  digitalWrite(dip2,LOW);
  delay(500);
}


void cutoff(){
  Serial.println("CUTTER STOPPED");
  digitalWrite(cut1,LOW);
  digitalWrite(cut2,LOW);
  delay(2000);
  digitalWrite(cut1,LOW);
  delay(1000);
}


void cuton(){
  Serial.println("CUTTER STARTED");
  digitalWrite(cut2,HIGH);
  digitalWrite(cut1,LOW);
  delay(2000);
  digitalWrite(cut1,LOW);
  delay(1000);
}

void angleascend(){
  Serial.println("angle up");
  digitalWrite(angle1,HIGH);
  digitalWrite(angle2,LOW);
  delay(500);
  digitalWrite(angle1,LOW);
  delay(100);
}

void angledescend(){
  Serial.println("angle down");
  digitalWrite(angle1,LOW);
  digitalWrite(angle2,HIGH);
  delay(500);
  digitalWrite(angle2,LOW);
  delay(100);
}


//-----------------------------------------------------------------------//  
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
Serial.begin(9600);
Serial.print("ROBOTICS");
  pinMode(arm1,OUTPUT); 
  pinMode(arm2,OUTPUT); 
  pinMode(dip1,OUTPUT); 
  pinMode(dip2,OUTPUT); 
  pinMode(cut1,OUTPUT); 
  pinMode(cut2,OUTPUT);
  pinMode(angle1,OUTPUT);
  pinMode(angle2,OUTPUT);   
}
void loop() {
if(Serial.available()>0){
  String rcv = Serial.readString();
  Serial.println(rcv);
      if( rcv.indexOf("front") != -1) {
        front();
        }
        
  else if (rcv.indexOf("back") != -1) {
     back();
  }
  else if (rcv.indexOf("left") != -1) {
     left();
  }
 else if(rcv.indexOf("right") != -1) {
     right();
  }
  else if(rcv.indexOf("stop") != -1) {
     stop();
  }
  else if(rcv.indexOf("up") != -1) {
     armup();
  }
  else if(rcv.indexOf("down") != -1) {
     armdown();
  }
   else if(rcv.indexOf("open") != -1) {
     armopen();
  }
  else if(rcv.indexOf("close") != -1) {
     armclose();
  }
   else if(rcv.indexOf("cut on") != -1) {
     cuton();
  }
  else if(rcv.indexOf("cut off") != -1) {
     cutoff();

  }
  else if(rcv.indexOf("ascend") != -1) {
     angleascend();

  }
  else if(rcv.indexOf("descend") != -1) {
     angledescend();

  }
}

}
