#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22
#define LED_PIN 12

//configuração do PWM para o servomotor
void pwm_setup_servo() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);

    //configuração do PWM para 50Hz (período de 20ms)
    pwm_set_clkdiv(slice_num, 125.0f); //civisor de clock para 50Hz
    pwm_set_wrap(slice_num, 20000);    //período de 20ms (50Hz)
    pwm_set_enabled(slice_num, true);  //habilita o PWM
}

//função para ajustar o ângulo do servomotor
void set_servo_angle(uint16_t pulse_width_us) {
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    pwm_set_gpio_level(SERVO_PIN, pulse_width_us);
}

//configuração do PWM para o LED
void pwm_setup_led() {
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(LED_PIN);

    pwm_set_clkdiv(slice_num, 4.0f);   //divisor de clock para o LED
    pwm_set_wrap(slice_num, 255);      //wrap para 8 bits (0-255)
    pwm_set_enabled(slice_num, true);  //habilita o PWM
}

//função principal
int main() {
    stdio_init_all(); //inicializa o sistema padrão de I/O

    pwm_setup_servo(); //configura o PWM para o servomotor
    pwm_setup_led();   //configura o PWM para o LED

    while (true) {
        //posição 180 graus (2.400μs)
        set_servo_angle(2400);
        pwm_set_gpio_level(LED_PIN, 255); //LED aceso
        sleep_ms(5000);

        //posição 90 graus (1.470μs)
        set_servo_angle(1470);
        pwm_set_gpio_level(LED_PIN, 128); //LED com brilho médio
        sleep_ms(5000);

        //posição 0 graus (500μs)
        set_servo_angle(500);
        pwm_set_gpio_level(LED_PIN, 0); //LED apagado
        sleep_ms(5000);

        //movimentação suave entre 0 e 180 graus
        for (uint16_t pulse = 500; pulse <= 2400; pulse += 5) {
            set_servo_angle(pulse);
            sleep_ms(10); //atraso de 10ms para suavizar a movimentação
        }
        for (uint16_t pulse = 2400; pulse >= 500; pulse -= 5) {
            set_servo_angle(pulse);
            sleep_ms(10); //atraso de 10ms para suavizar a movimentação
        }
    }
}