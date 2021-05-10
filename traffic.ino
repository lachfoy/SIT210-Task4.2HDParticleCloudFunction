SYSTEM_THREAD(ENABLED);

SerialLogHandler logHandler;

const pin_t LED_PIN_R = D6;
const pin_t LED_PIN_G = D7;
const pin_t LED_PIN_B = D8;

int trafficLight(String command);

void setup()
{
    pinMode(LED_PIN_R, OUTPUT);
    pinMode(LED_PIN_G, OUTPUT);
    pinMode(LED_PIN_B, OUTPUT);
    
    digitalWrite(LED_PIN_R, LOW);
    digitalWrite(LED_PIN_G, LOW);
    digitalWrite(LED_PIN_B, LOW);
    
    Particle.function("traffic", trafficLight);
}

void loop()
{

}

int trafficLight(String command)
{
    if (command == "red")
    {
        digitalWrite(LED_PIN_R, HIGH);
        digitalWrite(LED_PIN_G, LOW);
        digitalWrite(LED_PIN_B, LOW);
        return 1;
    }
    else if (command == "green")
    {
        digitalWrite(LED_PIN_R, LOW);
        digitalWrite(LED_PIN_G, HIGH);
        digitalWrite(LED_PIN_B, LOW);
        return 1;
    }
    else if (command == "blue")
    {
        digitalWrite(LED_PIN_R, LOW);
        digitalWrite(LED_PIN_G, LOW);
        digitalWrite(LED_PIN_B, HIGH);
        return 1;
    }
    else return -1;
}
