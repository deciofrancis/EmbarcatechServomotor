#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22  // Pino PWM para o servo
#define PWM_FREQ 50   // Frequência de 50Hz (período de 20ms)
#define PWM_TOP 25000 // Valor máximo para PWM

// Definição dos pulsos para os ângulos do servo
#define ANGLE_180 1920
#define ANGLE_90 1190
#define ANGLE_0 400

#define STEP_SIZE 5      // Passo para movimentação gradual
#define STEP_DELAY_MS 10 // Tempo entre cada passo

// Função para configurar o PWM na GPIO especificada
void init_pwm(uint gpio)
{
    gpio_set_function(gpio, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(gpio);

    pwm_set_wrap(slice, PWM_TOP);
    pwm_set_clkdiv(slice, 125.0f);
    pwm_set_enabled(slice, true);
}

// Função para definir o pulso do servo em microssegundos
void set_servo_pulse(uint gpio, uint16_t pulse_width)
{
    uint slice = pwm_gpio_to_slice_num(gpio);
    uint16_t level = (pulse_width * PWM_TOP) / 20000;
    pwm_set_chan_level(slice, pwm_gpio_to_channel(gpio), level);
}

int main()
{
    stdio_init_all();
    init_pwm(SERVO_PIN);

    sleep_ms(500); // Pequeno atraso antes de iniciar

    // Posicionamento inicial do servo
    set_servo_pulse(SERVO_PIN, ANGLE_180);
    sleep_ms(5000);

    set_servo_pulse(SERVO_PIN, ANGLE_90);
    sleep_ms(5000);

    set_servo_pulse(SERVO_PIN, ANGLE_0);
    sleep_ms(5000);

    // Loop para varredura gradual entre 0° e 180°
    while (true)
    {
        for (uint16_t pulse = ANGLE_0; pulse <= ANGLE_180; pulse += STEP_SIZE)
        {
            set_servo_pulse(SERVO_PIN, pulse);
            sleep_ms(STEP_DELAY_MS);
        }
        for (uint16_t pulse = ANGLE_180; pulse >= ANGLE_0; pulse -= STEP_SIZE)
        {
            set_servo_pulse(SERVO_PIN, pulse);
            sleep_ms(STEP_DELAY_MS);
        }
    }
}
