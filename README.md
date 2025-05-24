# Linux Kernel Drivers 

This repository contains a collection of Linux kernel module and driver programming examples, ranging from basic kernel modules to slightly mind numbing drivers implementing communication protocols. 


## Overview of Drivers

The repository includes the following examples organized by complexity:

### Basic Kernel Module Examples
- **01_hello_world**: A minimal kernel module that demonstrates the basic structure of a Linux kernel module, including initialization and exit functions. This example shows how to print messages to the kernel log and the basic module macros.

- **02_better_hello_world**: An improved version of the hello world module with better error handling, module parameters, and proper resource management. This example introduces more advanced concepts like module parameters and cleanup.

### GPIO Related
- **03_gpio_control**: Demonstrates how to interact with GPIO pins directly using the GPIO subsystem in the Linux kernel. This example shows how to request, configure, and manipulate GPIO pins for input and output operations.

- **04_gpio_driver**: Implements a complete GPIO character device driver, allowing userspace applications to interact with GPIO pins through file operations. This demonstrates the full device driver model including file operations and device registration.

- **08_Sending_Signals**: Shows how to handle GPIO interrupts and send signals to userspace applications. This example includes a test application (testapp.c) that receives signals from the kernel module when GPIO events occur.

### Display and PWM
- **05_lcd_driver**: A driver for controlling LCD displays connected to the system. This example demonstrates how to create a driver for character-based displays, showing text manipulation and display control techniques.

- **06_pwm_driver**: Implements a Pulse Width Modulation (PWM) driver for controlling devices that require variable power control. This example shows how to generate PWM signals for applications like LED brightness control or motor speed control.

### Communication Protocols
- **07_spi_bmp280**: An SPI driver for the BMP280 temperature and pressure sensor. This example demonstrates how to interface with SPI hardware and implement a complete sensor driver including reading measurements and handling device-specific protocols.

- **10_serdev**: A Serial Device driver implementation that shows how to use the serdev subsystem to communicate with devices connected via serial ports. This example implements an echo service that demonstrates bidirectional serial communication.

- **13_i2c_driver**: Implements an I2C bus driver showing how to communicate with I2C devices. This example demonstrates device detection, data transfer over I2C, and handling multiple device types on the same bus.

### Device Tree Related
- **09_dt_probe**: A basic example of Device Tree probing that shows how to parse and extract information from device tree nodes. This demonstrates the modern way of handling hardware description in Linux.

- **11_dt_iio**: Device Tree Industrial I/O (IIO) implementation that interfaces with an Atmega I2C ADC. This example shows how to implement the IIO framework for sensor data acquisition and how to handle I2C communication within that framework.

- **12_dt_spi**: Device Tree SPI implementation for an Atmega SPI ADC. Similar to the IIO example but using SPI instead of I2C, this demonstrates the flexibility of the IIO framework across different bus types.

## Note

### Environment Analysis
- Kernel version 6.11.0 (Ubuntu) with support for all required subsystems
- Properly configured build environment and headers


## Key Learnings by Driver Type

### Basic Modules (01_hello_world, 02_better_hello_world)
- Module initialization and cleanup process
- Kernel logging mechanisms
- Module parameters and their declaration
- Basic kernel module structure and macros

### GPIO Drivers (03_gpio_control, 04_gpio_driver, 08_Sending_Signals)
- GPIO subsystem interaction methods
- Character device driver implementation
- Interrupt handling in kernel space
- Signal communication between kernel and userspace

### Display & PWM Drivers (05_lcd_driver, 06_pwm_driver)
- Hardware control interfaces
- Timing-sensitive operations
- Device-specific protocols
- Power management considerations

### Protocol Drivers (07_spi_bmp280, 10_serdev, 13_i2c_driver)
- Bus-specific API usage
- Multi-device management
- Protocol timing and error handling
- Device addressing and identification

### Device Tree Drivers (09_dt_probe, 11_dt_iio, 12_dt_spi)
- Device tree parsing and property extraction
- Hardware description through device tree
- Platform device binding
- Framework-specific implementations (IIO)



## Getting Started

To build and test these drivers:

1. Ensure you have the Linux kernel headers installed
2. Navigate to the specific driver directory
3. Run `make` to build the kernel module
4. Load the module using `sudo insmod <module_name>.ko`
5. Check kernel logs with `dmesg` to verify operation
6. Unload the module using `sudo rmmod <module_name>`

However, for device tree-based drivers, you'll need to compile and apply the device tree overlay before loading the module :D

