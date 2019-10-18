const int A_PIN = A0;

void setup() {

  Serial.begin(9600);
  pinMode(A_PIN, INPUT);
  
}

void loop() {

  int analogInput = analogRead(A_PIN);

  if (analogInput >= 0 && analogInput <= 1023) {
    float celsius = convertAnalogInputToCelsius(analogInput);
    float farenheit = convertCelsiusToFarenheit(celsius);
    float kelvin = convertCelsiusToKelvin(celsius);
    Serial.print("AnalogRead: "); Serial.println(analogInput);
    Serial.print("CelsiusTmp: "); Serial.println(celsius);
    Serial.print("FarnhtTemp: "); Serial.println(farenheit);
    Serial.print("KelvinTemp: "); Serial.println(kelvin);
  }
  
  delay(1000);
  
}

float convertAnalogInputToCelsius(int analogInput) {
  float celsius = ((( (float) analogInput / (float) 1024) * 3.3 - 0.5) * 1000) / 10;
  return celsius;
}

float convertCelsiusToFarenheit(float celsiusInput) {
  float farenheit = ((celsiusInput * (9.0/5.0)) + 32);
  return farenheit;
}

float convertCelsiusToKelvin(float celsiusInput) {
  float kelvin = (celsiusInput + 273.15);
  return kelvin;
}
