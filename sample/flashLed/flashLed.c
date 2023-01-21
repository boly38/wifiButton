int sleepDelayMs = 5000;

void setupSerial() {
  Serial.begin(115200);

  // FIX : the ch340 is slow to start and need additional delay. src: https://forum.arduino.cc/t/serial-print-not-working-in-setup-but-works-in-a-loop/1020547
  delay(500);
}

void setupLed() {
  pinMode(LED_BUILTIN, OUTPUT);  // Initialize the LED_BUILTIN pin as an output
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
}

void ledUpOneTime() {
  digitalWrite(LED_BUILTIN, LOW);  // Turn the LED on (Note that LOW is the voltage level
  // but actually the LED is on; this is because it is active low on the ESP-01)
  delay(200);                      // Wait for 200ms
  digitalWrite(LED_BUILTIN, HIGH); // Turn the LED off by making the voltage HIGH
  delay(100);
}

void setup() {
  setupSerial(); // setup Serial
  setupLed();    // setup LED off
  Serial.println("setup() is done");
}

void loop() {
  Serial.println("Led on 3 x 200ms");
  ledUpOneTime();// put LED on for 200ms
  ledUpOneTime();// put LED on for 200ms
  ledUpOneTime();// put LED on for 200ms
  Serial.print("now sleep ");
  Serial.print(sleepDelayMs);
  Serial.println("ms");
  delay(sleepDelayMs);
}
