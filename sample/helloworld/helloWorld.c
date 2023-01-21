void setup() {
  Serial.begin(115200);
  Serial.println("setup: only one time");
}

void loop() {// put your main code here, to run repeatedly:
  Serial.println("hello !");
  delay(10000);
}