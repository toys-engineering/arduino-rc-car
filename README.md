# Arduino RC car

License: Attribution-NonCommercial 4.0 International

For commercial usage, please contact us at hey@toys.engineering with a description of your project and how do you plan to use this project.

### Getting started

Arduino RC Car project can be used to control any toy with one servo motor and one DC motor. It can be an RC car, a robot etc. The project includes 2 subprojects:

- A car controller - the firmware that should be uploaded on a board installed in a car
- A remote controller - the firmware that should be uploaded on a remote control with a joystick

### How to upload the firmware

- Open uno files in "car_controller" and "remote_controller" folders in Arduino IDE
- Set GPIOs you use on your boards
- Upload projects into boards

### Requirements

- ESP32-S3, ESP32-C3, ESP32-C6 based boards
- DC motor driver connected to the board from the previous point
- Arduino IDE
