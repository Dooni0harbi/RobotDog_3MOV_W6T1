#  Quadruped Robot Dog

A four-legged robotic dog prototype built using an **Arduino Uno**, **4 SG90 servo motors**, a **breadboard**, and a **3D-printed mechanical structure**.

The robot uses **one hip joint per leg**, giving the system a total of **4 Degrees of Freedom (4-DOF)**.

The project focuses on basic quadruped motion, servo coordination, movement sequencing, and simple robotic gestures.

---

## 📸 Components Overview

The image below shows the main components prepared for the robot project, including the **3D-printed body and legs, SG90 servo motors, screws, Arduino Uno, breadboard, ESP32, jumper wires, and other mechanical parts**.
<img width="3884" height="2365" alt="IMG_5175" src="https://github.com/user-attachments/assets/82a54894-ec22-4ec7-90e2-5b8af3b54a06" />


> **Note:** The current version of the robot uses the **Arduino Uno connected to a laptop via USB** for programming and power.
> The **ESP32 shown in the image is prepared for the next development stage**, where it will be integrated with an **external battery** to allow the robot to operate without being physically connected to the laptop.

---

## 🧩 Mechanical Structure

The robot body and legs were created using **3D-printed parts**.

The mechanical structure includes:

* 3D-printed robot body/frame
* 4 × 3D-printed legs
* 4 × SG90 servo motors
* Screws and mounting hardware
* 1 hip joint per leg
* 4 Degrees of Freedom in total

Each SG90 servo controls one hip joint.

Because the servos on opposite sides are mechanically mirrored, some servo movements must be reversed in software to produce matching physical movements.

---

## ⚙️ Hardware

* Arduino Uno
* Breadboard
* 4 × SG90 Servo Motors
* 3D-printed robot body
* 4 × 3D-printed legs
* Screws and mounting hardware
* Jumper wires
* USB cable
* Laptop
* ESP32 *(prepared for the next development stage)*

---

## 🔌 Wiring

Each SG90 servo motor has three connections:

* **Signal**
* **VCC / 5V**
* **GND**

### Servo Signal Connections

| Servo       | Arduino Pin |
| ----------- | ----------: |
| Front Left  |         D11 |
| Front Right |         D10 |
| Rear Right  |          D9 |
| Rear Left   |          D8 |

### Power Connections

All servo VCC wires are connected through the breadboard power rail:

```text
Servo VCC → Breadboard + Rail → Arduino 5V
```

All servo ground wires share a common ground:

```text
Servo GND → Breadboard - Rail → Arduino GND
```
<img width="3024" height="4032" alt="IMG_5330" src="https://github.com/user-attachments/assets/16a54877-80df-4f1a-b009-a45b87e9c792" />
<img width="3024" height="4032" alt="IMG_5329" src="https://github.com/user-attachments/assets/bcc082bc-033f-4fd9-8ce0-20c58a52c558" />
<img width="3024" height="4032" alt="IMG_5325" src="https://github.com/user-attachments/assets/3490445d-ade9-4bfa-9ec8-db1a4b429085" />

Signal connections:

```text
Front Left Signal  → D11
Front Right Signal → D10
Rear Right Signal  → D9
Rear Left Signal   → D8
```
<img width="3024" height="4032" alt="IMG_5326" src="https://github.com/user-attachments/assets/2fd38855-5aa7-4d63-a647-28ea1ba0de77" />

The Arduino Uno is connected directly to the laptop using a USB cable.

The laptop is currently used for:

* Uploading the Arduino code
* Testing the robot movements
* Modifying servo angles and movement sequences
* Supplying power during the prototype testing stage

---

## 🦿 Neutral Position

The initial standing position of the robot is approximately:

```cpp
90°
```

for all four servo motors.

The exact servo angles are adjusted according to the physical orientation of each leg and servo.

Some servos require reversed angle directions because of the mirrored mechanical layout of the robot.

---

# 🎮 Implemented Robot Movements

## 1. Walking

The robot performs a basic walking motion using coordinated movement between the four legs.

The front and rear legs move in opposite directions to create a simple quadruped walking pattern.

### 🎥 Walking Demo



https://github.com/user-attachments/assets/b7f0742c-0511-4f1a-b521-492e868a0921


## 2. Dance + High Five

The robot performs a dancing motion using coordinated servo movements.

During the dance:

* The front and rear pairs move in opposite directions.
* All legs use the same controlled movement range.

After approximately five seconds of dancing:

1. The robot stops.
2. One front leg is raised to perform a **high-five / fist-bump gesture**.
3. The leg returns.
4. The robot dances again for five seconds.
5. It stops again.
6. The opposite front leg performs the same gesture.


### 🎥 Dance + High Five Demo



https://github.com/user-attachments/assets/ad3d2c7f-c50c-4f2b-ae3b-01933f6c35b3

---

## 3. Sit & Wave Dance

The robot moves both rear legs into a sitting position and remains seated.
While sitting, the robot alternately raises the two front legs to create a **waving / seated dancing motion**.

### 🎥 Sit & Wave Demo



https://github.com/user-attachments/assets/552a0e95-e18e-4724-86bc-92f28cbc3384

---

## 📁 Project Files

```text
Quadruped-Robot-Dog-Motion-Control/
│
├── README.md
├── MOVE01.ino
├── MOVE02.ino
├── MOVE03.ino

```

Each Arduino file contains one independent robot motion sequence and can be uploaded separately to the Arduino Uno.

---

## 🧠 What I Learned

Through this project, I practiced:

* Arduino programming
* SG90 servo motor control
* Breadboard wiring
* Coordinating multiple servo motors
* Understanding mirrored servo movement
* Servo angle calibration
* Mechanical servo alignment
* 3D-printed robotic assembly
* Basic quadruped locomotion
* Creating robotic gestures and movement sequences
* Translating programmed servo angles into physical robot motion

---

## 🔜 Next Development Stage

The next stage of the project will integrate the **ESP32 and an external battery**.

This upgrade will reduce dependence on the current laptop-connected setup and allow the robot to operate more independently.

Future development may also include:

* Wireless control
* Sensors
* Additional joints
* Embedded systems integration
* Computer vision
* Intelligent robotic behaviors

---

## 🚀 Project Goal

The goal of this project is to build and test a simple **4-DOF quadruped robot dog** using a 3D-printed mechanical structure and Arduino-controlled SG90 servo motors.

The prototype serves as a foundation for developing a more advanced robotic dog with improved mobility, wireless control, sensing, and intelligent behavior.

# This project was developed as one of the practical tasks completed during my Robotics Engineering Internship at Smart Methods.
