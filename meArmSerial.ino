#include <Servo.h>

String in = "";
Servo servo0, servo1, servo2, servo3;

void setup()
{
    Serial.begin(9600);
    servo0.attach(9);
    servo1.attach(10);
    servo2.attach(11);
    servo3.attach(12);
}

void loop()
{
    if(Serial.available())
    {  
        while(Serial.available() > 0)
        {
            delay(3);
            char c = Serial.read();
            in +=c;
        }

        int currentServo = (in.substring(0,in.indexOf(':'))).toInt();

        int pos = (in.substring(in.indexOf(':')+1,in.indexOf(';'))).toInt();

        if(pos > 1 && pos < 180)
        {
            switch(currentServo)
            {
                case 0:
                    servo0.write(pos);
                    break;
                case 1:
                    servo1.write(pos);
                    break;
                case 2:
                    servo2.write(pos);
                    break;
                case 3:
                    servo3.write(pos);
                    break;
                default:
                    break;
            }
        }
        in = "";
    }
}
