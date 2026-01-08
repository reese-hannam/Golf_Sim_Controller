GSPro ESP32 Bluetooth Button Controller

This project is a custom wireless button controller built using an ESP32 microcontroller. It acts as a Bluetooth keyboard and is designed to be placed on the ground next to a golfer so common actions in GSPro can be performed without walking back to a computer keyboard.

The controller uses physical arcade-style buttons mapped to specific keyboard inputs such as aiming left and right, changing clubs, resetting aim, and triggering GSPro features like flyover and shot camera. The enclosure for the controller was custom designed and 3D printed, and the internal wiring was soldered for reliability.

⸻

Hardware Used
	•	ESP32 development board
	•	Momentary push buttons (arcade-style buttons recommended)
	•	Hookup wire
	•	Soldering iron and solder
	•	3D printed enclosure
	•	Computer with Bluetooth (Windows or macOS)

⸻

How It Works

The ESP32 is programmed using the Arduino framework and the BleKeyboard library. When powered on, the ESP32 advertises itself as a Bluetooth keyboard. Each button press pulls a GPIO pin to ground, and the ESP32 sends the corresponding keyboard key over Bluetooth.

Holding a button results in smooth continuous input, which is useful for actions like aiming left or right.

⸻

GPIO Pin Mapping

Each button should be wired between the listed GPIO pin and GND. All pins use INPUT_PULLUP.

	•	GPIO 23 → O (Flyover)
	•	GPIO 22 → Ctrl + M
	•	GPIO 21 → J
	•	GPIO 19 → A (Reset Aim)
	•	GPIO 18 → Right Arrow (Aim Right)
	•	GPIO 17 → I (Club Up)
	•	GPIO 33 → K (Club Down)
	•	GPIO 26 → Y
	•	GPIO 25 → Left Arrow (Aim Left)

Only safe, stable ESP32 GPIOs are used to avoid boot or reliability issues.

⸻

Wiring Notes
	•	Each button connects from its GPIO pin directly to GND
	•	Do not connect buttons to 3.3V when using INPUT_PULLUP
	•	GPIO 34–39 are input-only pins and can be used, but this project avoids them for simplicity
	•	All solder joints should be solid to prevent intermittent button behavior

⸻

Software Setup
	1.	Install the Arduino IDE
	2.	Add ESP32 board support using the Arduino Boards Manager
	3.	Install the ESP32 BLE Keyboard library by T-vK
	4.	Select your ESP32 board and correct COM port
	5.	Upload the provided sketch to the ESP32

After uploading, power the ESP32 and pair it with your computer via Bluetooth. It will appear as a keyboard named:

GSPro Controller

⸻

Customization

You can change key mappings by editing the BtnMap array in the code. GPIO pins and keyboard keys can be reassigned as needed, as long as safe ESP32 pins are used.

⸻

Use Case

This controller is intended to sit on the ground next to the golfer during a simulator session. It allows for quick adjustments like aiming, changing clubs, or viewing data without breaking focus or walking back to the computer.

⸻

Disclaimer

This project is provided as-is. Use at your own risk and verify pin connections before powering the ESP32.
