#include <Arduino.h>
#include <unity.h>
#include <ButtonListener.h>
#include <joystick.h>
int pinBtn = 0;
 


void setUp(void) {
    
}



void test_button_pressedON(void)
{
   
        delay(500);
    TEST_ASSERT_TRUE(digitalRead(pinBtn) > 0);
}

void test_button_pressedOFF(void)
{
    
        delay(500);
    TEST_ASSERT_FALSE(digitalRead(pinBtn) == 0);
}

void setup() {
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN();    // Start unittesting
    
    RUN_TEST(test_button_pressedON);



    RUN_TEST(test_button_pressedOFF);

    UNITY_END(); // Stop unittesting
    
}

void loop()
{
    
}