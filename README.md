# ☀️ Sun Tracking Solar System

A **dual-axis sun tracking solar panel** that automatically follows the sun across the sky, keeping the panel perpendicular to the incoming sunlight to capture more energy than a fixed panel.

---

## 📌 Overview

A fixed solar panel only receives peak sunlight for a short part of the day. This project uses light sensors and servo motors to continuously detect the brightest direction and rotate the panel along two axes:

- **Horizontal axis (azimuth):** tracks the sun from east to west
- **Vertical axis (elevation):** adjusts for the sun's height through the day and across seasons

---

## ✨ Features

- Dual-axis tracking (horizontal + vertical)
- Light-based tracking using LDR sensors
- Smooth servo movement with a tolerance band to avoid jitter
- Low-cost, easy to build and extend
- Modular code that is easy to modify

---

## 🧰 Components Used

| Component | Quantity | Purpose |
|-----------|----------|---------|
| [Arduino Uno / ESP32] | 1 | Main controller |
| LDR (Light Dependent Resistor) | 4 | Detect light intensity from each direction |
| 10kΩ resistors | 4 | Voltage dividers for LDRs |
| Servo motor ([SG90 / MG90S]) | 2 | Rotate the panel on each axis |
| Solar panel ([voltage/wattage]) | 1 | Energy source |
| Power supply / battery | 1 | Powers the controller and servos |
| Jumper wires, breadboard | – | Connections |
| Mechanical frame / mount | 1 | Holds the panel and sensors |

> Edit this table to match the parts you actually used.

---

## ⚙️ Working Principle

1. Four LDRs are placed at the corners of the panel, separated by a cross-shaped divider so that each one receives different amounts of light when the panel is not facing the sun.
2. The microcontroller reads the four analog values:
   - **Top-Left (TL), Top-Right (TR), Bottom-Left (BL), Bottom-Right (BR)**
3. It averages the sensors in pairs and compares them:
   - Top average vs. Bottom average → controls the **vertical** servo
   - Left average vs. Right average → controls the **horizontal** servo
4. If the difference is larger than a set tolerance, the matching servo rotates toward the brighter side.
5. When all four sensors read about the same, the panel is facing the sun and stays still.

```
        TL | TR
       ----+----
        BL | BR
```

---

## 🔌 Circuit Connections

| Component | Pin |
|-----------|-----|
| LDR Top-Left | [A0] |
| LDR Top-Right | [A1] |
| LDR Bottom-Left | [A2] |
| LDR Bottom-Right | [A3] |
| Horizontal servo | [D9] |
| Vertical servo | [D10] |

Each LDR is wired as a voltage divider with a 10kΩ resistor to GND, and the midpoint goes to the analog pin.

> Update the pin numbers to match your wiring. Add your circuit diagram to the `images/` folder.

---

## 🚀 Getting Started

### Prerequisites
- Arduino IDE (or PlatformIO)
- `Servo` library (included with the Arduino IDE)

### Steps
1. Clone this repository:
   ```bash
   git clone https://github.com/narendra8010/Sun-Tracking-Solar-System.git
   ```
2. Open the `.ino` file from the `code/` folder in the Arduino IDE.
3. Select your board and COM port.
4. Upload the code.
5. Place the setup under sunlight (or a bright lamp for testing) and watch the panel align itself.

---

## 📁 Project Structure

```
Sun-Tracking-Solar-System/
├── code/          # Arduino / ESP32 source code
├── images/        # Circuit diagram and project photos
├── docs/          # Reports, notes, datasheets (optional)
└── README.md
```

---

## 🔧 Tuning

| Parameter | Description |
|-----------|-------------|
| `tolerance` | Minimum light difference before a servo moves. Higher values reduce jitter. |
| `delay` | Time between readings. Higher values give slower, smoother tracking. |
| Servo step size | Degrees moved per update. |
| Servo limits | Minimum and maximum angles, to protect the frame and wiring. |

---

## 📸 Demo

_Add photos or a demo video link here._

![Project photo](images/project.jpg)

---

## 🔮 Future Improvements

- Add a voltage/current sensor to measure the actual power gain over a fixed panel
- Use a real-time clock (RTC) for time-based tracking as a fallback on cloudy days
- Add a battery charge controller for off-grid use
- Display live readings on an LCD or a web dashboard (ESP32 Wi-Fi)
- Use stepper motors for larger panels

---

## 👤 Author

**Narendra**
- GitHub: [@narendra8010](https://github.com/narendra8010)

---

## 📄 License

This project is open source. Add a license of your choice (for example MIT) if you want others to reuse it.
