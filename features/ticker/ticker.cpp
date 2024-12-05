#include "ticker.h"

static uint32_t ms_per_frame = 1000 / 20;
static bool in_frame = false;

int64_t break_frame_wait_callback(alarm_id_t id, void *user_data)
{
    in_frame = false;
    return 0;
}

void frame_wait()
{
    while (in_frame)
    {
        sleep_us(1);
    }
    in_frame = true;
    add_alarm_in_ms(ms_per_frame, break_frame_wait_callback, NULL, false);
}