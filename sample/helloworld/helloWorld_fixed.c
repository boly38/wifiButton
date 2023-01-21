void setup() {
  Serial.begin(115200);

  // FIX : the ch340 is slow to start and need additional delay. src: https://forum.arduino.cc/t/serial-print-not-working-in-setup-but-works-in-a-loop/1020547
  delay(500);

  Serial.println("setup: only one time");

  // More details about Serial: number of characters available for writing : https://arduinogetstarted.com/reference/serial-availableforwrite
  int wlen = Serial.availableForWrite();
  Serial.print("TX buffer size: ");
  Serial.println(wlen);
}

void loop() {// put your main code here, to run repeatedly:
  Serial.println("hello fixed !");
  delay(10000);
}