#define leftSensor 2
#define centerSensor 3
#define rightSensor 4

#define IN1 5
#define IN2 6
#define IN3 9
#define IN4 10

int nodeCount = 0;
int totalNodes = 12;   // based on your image

void setup() {
  pinMode(leftSensor, INPUT);
  pinMode(centerSensor, INPUT);
  pinMode(rightSensor, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {

  int left = digitalRead(leftSensor);
  int center = digitalRead(centerSensor);
  int right = digitalRead(rightSensor);

  // Intersection detected (All sensors on black)
  if (left == LOW && center == LOW && right == LOW) {
    nodeCount++;
    stopRobot();
    delay(15000);   // wait 15 sec
    reverseRobot();
    delay(800);     // adjust reverse timing
    turnToNextPath();
  }
  else if (center == LOW) {
    forward();
  }
  else if (left == LOW) {
    turnLeft();
  }
  else if (right == LOW) {
    turnRight();
  }
  else {
    forward();
  }

  if (nodeCount >= totalNodes) {
    stopRobot();
    while (1);  // Stop permanently at exit
  }
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void reverseRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void turnToNextPath() {
  turnRight();   // or left depending on design
  delay(600);
}
