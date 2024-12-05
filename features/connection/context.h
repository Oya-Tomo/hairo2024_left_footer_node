#pragma once

#include "pico/stdlib.h"
#include "pico/i2c_slave.h"
#include "hardware/i2c.h"

// I2C context

typedef struct
{
    uint8_t memory[256];
    uint8_t address;
    bool written_address;
} i2c_context_t;

// System State Structures

typedef struct
{
    bool is_running;
} system_state_t;

typedef struct
{
    float speed; // 0.0 ~ 1.0
} drive_state_t;

typedef struct
{
    float angle; // radians (-pi / 2 ~ pi / 2)
} flipper_state_t;