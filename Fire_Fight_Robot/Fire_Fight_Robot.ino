 #include <NewPing.h>
const int motor1A = 9;
const int motor1B = 6;
const int motor2A = 5;
const int motor2B = 3;
const int triggerLeft = 7;
const int triggerRight = 8;
const int triggerCenter = 2;
const int echoLeft = 12;
const int echoRight = 11;
const int echoCenter = 10;
const int maxDistance = 230;

int distanceLeft = 0;
int distanceRight = 0;
int distanceCenter = 0;
int rightTurns = 0;

int previousLeft;
int previousRight;

bool madeLeftTurn = false;
bool madeRightTurn = false;
int leftDelay = 0;
int rightDelay = 0;

NewPing sonarLeft(triggerLeft, echoLeft, maxDistance);
NewPing sonarRight(triggerRight, echoRight, maxDistance);
NewPing sonarCenter(triggerCenter, echoCenter, maxDistance);

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  distanceCenter = sonarCenter.ping_median();
  distanceLeft = sonarLeft.ping_median();
  distanceRight = sonarRight.ping_median();
  distanceCenter = sonarCenter.convert_cm(distanceCenter);
  distanceLeft = sonarLeft.convert_cm(distanceLeft);
  distanceRight = sonarRight.convert_cm(distanceRight);

  Serial.println(distanceLeft);
  //Serial.println(distanceCenter);
  Serial.println(distanceRight);
  Serial.println();

  if(leftDelay == 5){
    leftDelay = 0;
    madeLeftTurn = false;
  }

  if(rightDelay == 5){
    rightDelay = 0;
    madeRightTurn = false;
  }

  if(true){
    analogWrite(motor1A, 200);
    analogWrite(motor1B, 0);
    analogWrite(motor2A, 0);
    analogWrite(motor2B, 200);
    delay(3000);
    analogWrite(motor1A, 0);
    analogWrite(motor1B, 0);
    analogWrite(motor2A, 0);
    analogWrite(motor2B, 0);
    delay(3000);
  }
  if((rightTurns >= 5 && distanceLeft > 45)  || (distanceLeft > 45 && distanceRight < 40 && distanceRight != 0) && !madeLeftTurn){   
    analogWrite(motor1A, 10);
    analogWrite(motor1B, 0);
    analogWrite(motor2A, 255);
    analogWrite(motor2B, 0);
    delay(1300);
    rightTurns = 0;

    analogWrite(motor1A, 200);
    analogWrite(motor1B, 0);
    analogWrite(motor2A, 200);
    analogWrite(motor2B, 0);
    delay(200);

    madeLeftTurn = true;
  }
  else if(distanceRight > 45 && !madeRightTurn){
    analogWrite(motor1A, 255);
    analogWrite(motor1B, 0);
    analogWrite(motor2A, 10);
    analogWrite(motor2B, 0);
    delay(1350);

    analogWrite(motor1A, 200);
    analogWrite(motor1B, 0);
    analogWrite(motor2A, 200);
    analogWrite(motor2B, 0);
    delay(200);

    madeRightTurn = true;
  }
  else if(distanceCenter < 30 && distanceLeft < 46 && distanceRight < 46){
    analogWrite(motor1A, 200);
    analogWrite(motor1B, 0);
    analogWrite(motor2A, 0);
    analogWrite(motor2B, 200);
    delay(3000);

    analogWrite(motor1A, 200);
    analogWrite(motor1B, 0);
    analogWrite(motor2A, 200);
    analogWrite(motor2B, 0);
    delay(200);
  }

  //use previousLeft and previosRight to compare
  //check if ping is broken

  /*if(previousLeft < distanceLeft - 1){
    analogWrite(motor1A, 25);   //Left Forwards
    analogWrite(motor1B, 0);    //Left Reverse
    analogWrite(motor2A, 254);  //Right Forwards
    analogWrite(motor2B, 0);    //Right Reverse
    delay(200);
  }
  if(previousRight < distanceRight - 1){
    analogWrite(motor1A, 254);
    analogWrite(motor1B, 0);
    analogWrite(motor2A, 25);
    analogWrite(motor2B, 0);
    delay(200);
  }
  
  analogWrite(motor1A, 200);
  analogWrite(motor1B, 0);
  analogWrite(motor2A, 200);
  analogWrite(motor2B, 0);
  delay(50);
    
  previousLeft = distanceLeft;
  previousRight = distanceRight;
  
  if(madeLeftTurn)
    leftDelay++;
  if(madeRightTurn)
    rightDelay++; */
}
  /*
  else if(distanceRight > 55){
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, HIGH);
    delay(600);
    rightTurns++;
  }
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor2A, HIGH);
    digitalWrite(motor2B, LOW);
    delay(500);
  }
*/



