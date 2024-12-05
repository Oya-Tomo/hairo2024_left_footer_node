#include <stdio.h>
#include "pico/stdlib.h"

#include "features/connection/connection.h"
#include "features/drive/drive.h"
#include "features/ticker/ticker.h"

void irq_callback_register(uint gpio, uint32_t events)
{
    drive_callback_register(gpio, events);
}

void setup()
{
    stdio_init_all();

    connection_setup();
    drive_setup();

    gpio_set_irq_callback(irq_callback_register);
    irq_set_enabled(IO_IRQ_BANK0, true);
}

int main()
{
    setup();

    while (true)
    {
        frame_wait();
    }

    return 0;
}
