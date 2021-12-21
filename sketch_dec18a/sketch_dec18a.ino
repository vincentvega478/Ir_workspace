long count = 700; //Start at 2- 1 doesn't count
long printDelay = 100000; //Minimum prime number delay

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(A0, OUTPUT);
}

void loop() {
  unsigned long start = millis();
  if(isPrime(count)) {
    digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);
    digitalWrite(A1, HIGH);
    delay(50);
    digitalWrite(A2, HIGH);
    delay(50);
    digitalWrite(A3, HIGH);
    delay(50);
    digitalWrite(A4, HIGH);
    delay(50);
    digitalWrite(3, HIGH);
    delay(50);
    digitalWrite(A0, HIGH);
    delay(50);
    digitalWrite(A5, HIGH);
    delay(50);
    digitalWrite(13, LOW);   // turn the LED on (HIGH is the voltage level)
    Serial.println(count);
    delay(100);   // wait for a second
    
    if(millis() - start < printDelay) {
      Serial.print("Time taken = ");
      Serial.println(abs(printDelay - (millis() - start)));
      digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
      delay(50);
      digitalWrite(A2, LOW);
      delay(50);
      digitalWrite(A1, LOW);
      delay(50);
      digitalWrite(A3, LOW);
      delay(50);
      digitalWrite(A4, LOW);
      delay(50);
      digitalWrite(3, LOW);
      delay(50);
      digitalWrite(A5, LOW);
      delay(50);
      digitalWrite(A0, LOW);
      delay(50);
      digitalWrite(13, HIGH);    // turn the LED off by making the voltage LOW
      delay(200);                       // wait for a second
    }
  }
  count++;
}

boolean isPrime(long x) {
  boolean prime = true;
  
  for(long i = 2; i <= x/2; i++) { //Loop every number up to half
    if(x % i == 0) { //If it's divisible...
      prime = false; //It isn't prime!
      break;
    }
  }
  
  return prime;
}
