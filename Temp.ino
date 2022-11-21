int value = 0;
int green = 8;
int red = 9;
int yellow = 7;

void setup() {
    Serial.begin(9600);
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(yellow, OUTPUT);
}

void loop() {

    value = analogRead(A0);
    float voltage_1 = value * 5.0;
    voltage_1 /= 1024.0;
    float temp_1 = (voltage_1 - 0.5) * 100;
    Serial.println(temp_1);

    value = analogRead(A1);
    float voltage_2 = value * 5.0;
    voltage_2 /= 1024.0;
    float temp_2 = (voltage_2 - 0.5) * 100;
    Serial.println(temp_2);

    if (temp_1 < 36.5 || temp_2 < 36.5) {
        digitalWrite(green, LOW);
        digitalWrite(red, LOW);
        digitalWrite(yellow, LOW);
        delay(500);
    } else {
        if (temp_1 >= 36.5 && temp_1 <= 38.0 && temp_2 > 36.5 && temp_2 <= 38.0) {
            digitalWrite(green, HIGH);
            digitalWrite(red, LOW);
            digitalWrite(yellow, LOW);
        }

        if ((temp_1 > 38.0 && temp_1 <= 40.0) || (temp_2 > 38.0 && temp_2 <= 40.0)) {
            digitalWrite(green, LOW);
            digitalWrite(red, LOW);
            digitalWrite(yellow, HIGH);
        }

        if (temp_1 > 40.0 || temp_2 > 40.0) {
            digitalWrite(green, LOW);
            digitalWrite(red, HIGH);
            digitalWrite(yellow, LOW);
        }
    }

    delay(500);
}
