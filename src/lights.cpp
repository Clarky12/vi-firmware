#include "timer.h"
#include "lights.h"
#include "listener.h"
#include "log.h"

using openxc::time::delayMs;

openxc::lights::Palette openxc::lights::COLORS = {
    {255, 0, 0}, // red
    {0, 255, 0}, // green
    {0, 0, 255}, // blue
    {0, 0, 0}, // black (i.e. off)
    {255, 255, 255}, // white
};

void openxc::lights::disable(Light light, int duration) {
    enable(light, COLORS.black, duration);
}

void openxc::lights::disable(Light light) {
    enable(light, COLORS.black, 0);
}

void openxc::lights::enable(Light light, RGB color, int duration) {
    enable(light, color);
    // TODO dim up
}

void openxc::lights::flash(Light light, RGB color, int duration) {
    enable(light, color);
    // TODO make a non-blocking version of this using timers
    delayMs(duration);
    disable(light);
}
