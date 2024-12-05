#pragma once

#include "pico/stdlib.h"

void drive_callback_register(uint gpio, uint32_t events);

void drive_setup();

void drive_task();

void drive_stop();
