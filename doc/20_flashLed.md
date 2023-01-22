[< home](../readme.md)

[< previous: 1: set up IDE ](./10_setupIDE.md) | 2: flash LED | [next: 3: reset >](./30_reset.md)


# Sample : flash the on-board LED

## Introduction

The goal is to interact with the on-board LED.

### Take the idea from Arduino basic examples

On Arduino there is already a bunch of sample.

So interact with the LED is a basic feature also included.

Try to do the following : 
`| File > Example > 01.Basics > Blink `

Arduino IDE open a new sketch with a basic blink sample and his documentation ^^

```c
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
```

With this sample, you understand how to init the LED_BUILTIN, how to put it on or off after some delay.

### Next steps

- *for Junior DEV*: Improve the sample yourself !

Try to update this code to fit your own needs. For example, you could create a function that put the led on 200ms and off 100ms and call this function multiple times.

```c 
void ledUpOneTime() {
  digitalWrite(LED_BUILTIN, LOW);  // Turn the LED on 
  delay(200);                      // Wait for 200ms
  digitalWrite(LED_BUILTIN, HIGH); // Turn the LED off
  delay(100);                      // Wait for 100ms
}
```

You could pick an updated blink full sample from [flashLed.c](../sample/flashLed/flashLed.c)