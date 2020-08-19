#include "STM32_periphery.h"

 struct  pin  green_led = {
    .port = ES_GPIOD,
    .num = 12,
    .dir = GPIO_MODE_OUTPUT,
    .mode = GPIO_OTYPE_PP,
    .otype = GPIO_OTYPE_PP,
    .speed = GPIO_OSPEED_2MHZ,
    .pull_up_down = GPIO_PUPD_NONE,
    .is_inverse = false
};

 struct pin   orange_led = {
    .port = ES_GPIOD,
    .num = 13,
    .dir = GPIO_MODE_OUTPUT,
    .mode = GPIO_OTYPE_PP,
    .otype = GPIO_OTYPE_PP,
    .speed = GPIO_OSPEED_2MHZ,
    .pull_up_down = GPIO_PUPD_NONE,
    .is_inverse = false
};


 struct pin  red_led = {
    .port = ES_GPIOD,
    .num = 14,
    .dir = GPIO_MODE_OUTPUT,
    .mode = GPIO_OTYPE_PP,
    .otype = GPIO_OTYPE_PP,
    .speed = GPIO_OSPEED_2MHZ,
    .pull_up_down = GPIO_PUPD_NONE,
    .is_inverse = false
};

 struct pin  blue_led = {
    .port = ES_GPIOD,
    .num = 15,
    .dir = GPIO_MODE_OUTPUT,
    .mode = GPIO_OTYPE_PP,
    .otype = GPIO_OTYPE_PP,
    .speed = GPIO_OSPEED_2MHZ,
    .pull_up_down = GPIO_PUPD_NONE,
    .is_inverse = false
};