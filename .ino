#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <math.h>

// ===== LED pini =====
const int LED_DARK = 7;     // tema
const int LED_LIGHT = 8;    // svetlo
const int LED_BRIGHT = 9;   // ekstra svetlo

LiquidCrystal_I2C lcd(0x27, 16, 2);

// ===== KALIBRACIJA =====
const double adc1 = 200.0;
const double lux1 = 27.0;

const double adc2 = 700.0;
const double lux2 = 300.2;

const double adc3 = 900.0;
const double lux3 = 1500.0;

double correctionFactor = 1.0;

// ===== POVPREČENJE ADC =====
int readADC() {
  long sum = 0;
  for (int i = 0; i < 20; i++) {
    sum += analogRead(A0);
    delay(2);
  }
  return sum / 20;
}

// ===== INTERPOLACIJA =====
double interpolate(double x,
                   double x1, double y1,
                   double x2, double y2,
                   double x3, double y3) {

  double lx = log(x);
  double a1 = log(x1);
  double a2 = log(x2);
  double a3 = log(x3);

  if (x <= x2) {
    return exp(
      log(y1) +
      (lx - a1) * (log(y2) - log(y1)) / (a2 - a1)
    );
  } else {
    return exp(
      log(y2) +
      (lx - a2) * (log(y3) - log(y2)) / (a3 - a2)
    );
  }
}

// ===== LUX IZRAČUN =====
double calculateLux(int raw) {
  if (raw < 1) raw = 1;

  double lux = interpolate(raw,
                           adc1, lux1,
                           adc2, lux2,
                           adc3, lux3);

  lux *= correctionFactor;

  if (!isfinite(lux) || lux < 0) lux = 0;

  return lux;
}

// ===== SETUP =====
void setup() {
  Serial.begin(9600);

  pinMode(LED_DARK, OUTPUT);
  pinMode(LED_LIGHT, OUTPUT);
  pinMode(LED_BRIGHT, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Light meter");
  delay(1000);
  lcd.clear();
}

// ===== LOOP =====
void loop() {
  int raw = readADC();
  double lux = calculateLux(raw);

  Serial.print("ADC: ");
  Serial.print(raw);
  Serial.print("  Lux: ");
  Serial.println(lux);

  // ===== LED LOGIKA =====
  digitalWrite(LED_DARK, LOW);
  digitalWrite(LED_LIGHT, LOW);
  digitalWrite(LED_BRIGHT, LOW);

  if (lux <= 150) {
    digitalWrite(LED_DARK, HIGH);   // tema
  }
  else if (lux <= 500) {
    digitalWrite(LED_LIGHT, HIGH);  // svetlo
  }
  else {
    digitalWrite(LED_BRIGHT, HIGH); // ekstra svetlo
  }

  // ===== LCD =====
  lcd.setCursor(0, 0);
  lcd.print("Lux:            ");
  lcd.setCursor(5, 0);
  lcd.print((int)lux);

  lcd.setCursor(0, 1);
  lcd.print("ADC:            ");
  lcd.setCursor(5, 1);
  lcd.print(raw);

  delay(1000);
}
