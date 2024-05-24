# Gesture Controlled Wheelchair

This project focuses on developing a gesture-controlled wheelchair for paralysis patients using the MPU6050 module for gesture detection and the ESP32 microcontroller with ESP-NOW protocol for communication.

## Features

- **Gesture Control Using MPU6050 Module**
- **Wireless Communication with ESP-NOW Protocol**
- **Reliable and Low Latency Control**

## Components

- MPU6050 (Gyroscope + Accelerometer)
- ESP32 microcontrollers (2 units)
- Motor drivers
- Wheelchair motors
- Power supply

## Gesture Control Mechanism

The MPU6050 module is used to detect gestures made by the user. These gestures are then translated into commands for moving the wheelchair.

### Components

- MPU6050
- ESP32 (for gesture detection and command transmission)
- ESP32 (for receiving commands and controlling the wheelchair motors)
- Motor drivers
- Wheelchair motors
- Power supply

### Gesture Commands

- **Forward**: Tilt forward
- **Backward**: Tilt backward
- **Left**: Tilt left
- **Right**: Tilt right
- **Stop**: Return to neutral position

## Wireless Communication Using ESP-NOW

The ESP-NOW protocol is used for wireless communication between the two ESP32 microcontrollers. This protocol ensures low latency and reliable transmission of control commands.

### Components

- Two ESP32 microcontrollers
- ESP-NOW protocol for communication

## Installation

1. **Hardware Setup**
    - Mount the MPU6050 on the user's hand or a suitable place to capture gestures.
    - Connect one ESP32 to the MPU6050 module.
    - Connect the second ESP32 to the motor drivers and motors of the wheelchair.
    - Ensure power supply to all components.

2. **Software Setup**
    - Program the first ESP32 to read data from the MPU6050 and send control commands via ESP-NOW.
    - Program the second ESP32 to receive commands via ESP-NOW and control the wheelchair motors accordingly.
    - Ensure both ESP32 microcontrollers are paired and communicating using the ESP-NOW protocol.

## Usage

1. Power on the wheelchair and both ESP32 microcontrollers.
2. Use gestures to control the wheelchair:
    - Tilt forward to move forward.
    - Tilt backward to move backward.
    - Tilt left to turn left.
    - Tilt right to turn right.
    - Return to a neutral position to stop.
3. Adjust sensitivity and response as needed for user comfort and accuracy.

## Contributing

We welcome contributions from the community. Please feel free to submit pull requests or open issues for any bugs or feature requests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
