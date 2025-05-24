#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio/consumer.h>
#include <linux/gpio.h>

static struct gpio_desc *led, *button;

#define IO_LED 21
#define IO_BUTTON 20

#define IO_OFFSET 0

static int __init my_init(void)
{ 
    int status;

    // Get LED GPIO descriptor
    led = gpio_to_desc(IO_LED + IO_OFFSET);
    if (!led) {
        printk("gpioctrl - Error getting pin %d for LED\n", IO_LED);
        return -ENODEV;
    }

    // Get Button GPIO descriptor
    button = gpio_to_desc(IO_BUTTON + IO_OFFSET);
    if (!button) {
        printk("gpioctrl - Error getting pin %d for Button\n", IO_BUTTON);
        return -ENODEV;
    }

    // Set LED GPIO direction as output, initial value = 0 (OFF)
    status = gpiod_direction_output(led, 0);
    if (status) {
        printk("gpioctrl - Error setting pin %d as output\n", IO_LED);
        return status;
    }

    // Set Button GPIO direction as input
    status = gpiod_direction_input(button);
    if (status) {
        printk("gpioctrl - Error setting pin %d as input\n", IO_BUTTON);
        return status;
    }

    // Turn on LED
    gpiod_set_value(led, 1);

    // Print button state
    printk("gpioctrl - Button is %spressed\n", gpiod_get_value(button) ? "" : "not ");

    return 0;
}

static void __exit my_exit(void)
{
    // Turn off LED on exit
    gpiod_set_value(led, 0);
    printk("gpioctrl - Module exit: LED turned off\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");


