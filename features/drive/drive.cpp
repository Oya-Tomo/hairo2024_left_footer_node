#include "features/drive/drive.h"
#include "features/connection/connection.h"

#include "sclp/sclp.h"

MotorDriver3Pins body_belt_motor(0, 1);
MotorDriver3Pins::config_t body_belt_motor_config = {
    .pwm_clkdiv = pwm_clkdiv_calc(10 * 1000, 1000),
    .pwm_wrap = 1000,
    .reverse = false,
};

MotorDriver3Pins flipper_belt_motor(0, 1);
MotorDriver3Pins::config_t flipper_belt_motor_config = {
    .pwm_clkdiv = pwm_clkdiv_calc(10 * 1000, 1000),
    .pwm_wrap = 1000,
    .reverse = false,
};

QEI body_belt_qei(0, 0);
QEI::config_t body_belt_qei_config = {
    .ppr = 48,
    .reverse = false,
};

QEI flipper_belt_qei(0, 0);
QEI::config_t flipper_belt_qei_config = {
    .ppr = 48,
    .reverse = false,
};

PID body_belt_pid(PID::sPID);
PID::config_t body_belt_pid_config = {
    .Kp = 0.01,
    .Ki = 0.00,
    .Kd = 0.01,
    .Kf = 0,
    .guard = true,
    .min = -0.1,
    .max = 0.1,
};

PID flipper_belt_pid(PID::sPID);
PID::config_t flipper_belt_pid_config = {
    .Kp = 0.01,
    .Ki = 0.00,
    .Kd = 0.01,
    .Kf = 0,
    .guard = true,
    .min = -0.1,
    .max = 0.1,
};

void drive_callback_register(uint gpio, uint32_t events)
{
    body_belt_qei.callback_register(gpio, events);
    flipper_belt_qei.callback_register(gpio, events);
}

void drive_setup()
{
    body_belt_motor.configure(body_belt_motor_config);
    flipper_belt_motor.configure(flipper_belt_motor_config);

    body_belt_qei.configure(body_belt_qei_config);
    flipper_belt_qei.configure(flipper_belt_qei_config);

    body_belt_pid.configure(body_belt_pid_config);
    flipper_belt_pid.configure(flipper_belt_pid_config);
}

void drive_stop()
{
    body_belt_motor.set_duty_ratio(0);
    flipper_belt_motor.set_duty_ratio(0);
}

void drive_task()
{
    drive_state_t drive_state = get_drive_state();
}
