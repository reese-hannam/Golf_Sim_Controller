YouTube Video: https://youtu.be/1dWvbpeyYvU

GSPro ESP32 Bluetooth Button Controller

This project is a custom wireless button controller built using an ESP32 microcontroller. It acts as a Bluetooth keyboard and is designed to be placed on the ground next to a golfer so common actions in GSPro can be performed without walking back to a computer keyboard.

The controller uses physical arcade-style buttons mapped to specific keyboard inputs such as aiming left and right, changing clubs, resetting aim, and triggering GSPro features like flyover and shot camera. The enclosure for the controller was custom designed and 3D printed, and the internal wiring was soldered for reliability.

⸻

Materials Used

Below is a list of the materials used to build the controller. Links can be added or substituted depending on availability or personal preference.

Electronics

•	ESP32 Development Board
Used as the main microcontroller and Bluetooth interface.

Link: https://a.co/d/b0uIlZR

•	Momentary Push Buttons (Arcade-Style Buttons)
Used for all physical inputs such as aiming, club selection, and view controls.

Link: https://a.co/d/8ponmfz

•	Spade Hookup Wire
Used for connecting buttons to the ESP32 and internal wiring.

Link: https://a.co/d/5NotrxG

•	Breadboard
Used to connect buttons to ESP32 to avoid soldering.

Link: https://a.co/d/9BubrzX

•	Power Supply
Used to power the led lights inside the buttons. Not needed if you do not plan to use lights.

Link: https://a.co/d/dr4U3iI

Tools and Assembly

•	Soldering Iron and Solder

Used to make permanent and reliable electrical connections.

•	3D Printed Enclosure

Custom designed enclosure to house the ESP32 and buttons. Print files are included in this repository.

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

•Each button is wired between its assigned GPIO pin and GND using INPUT_PULLUP

•Buttons should not be connected to 3.3V when using internal pull-ups

•Solid solder joints are recommended to avoid intermittent button behavior

I do not necessarily recommend the spade-style wires I used to connect the buttons to the ESP32. I originally thought there was a breadboard-style connection on the other side of the buttons, but it turned out to be bare wire. Because of this, I had to cut breadboard jumper wires in half and solder them to the other side in order to connect everything properly. This setup did work, but there are likely cleaner or more reliable wiring options depending on the buttons and connectors used.

To power the LED lights using a 12V power supply, I cut a section off an old extension cord and used it as a power distribution point. I soldered all nine positive LED connections to the live wire and all nine ground connections to the neutral wire. This method worked reliably for me, but there are likely better and safer ways to distribute power depending on the hardware and tools available.

⸻

Software Setup

1.	Install the Arduino IDE
2.	Add ESP32 board support in the Arduino IDE using the Boards Manager
3.	Install the Bluetooth library used by this project
	
This project uses the ESP32 BLE Keyboard library by T-vK, which allows the ESP32 to function as a Bluetooth keyboard.
GitHub repository: https://github.com/T-vK/ESP32-BLE-Keyboard

To install using the Arduino IDE:

•	Go to Sketch → Include Library → Manage Libraries…
•	Search for ESP32 BLE Keyboard
•	Install the library by T-vK
	
To install directly from GitHub:

•	Download the repository as a ZIP from: https://github.com/T-vK/ESP32-BLE-Keyboard
•	In the Arduino IDE, go to Sketch → Include Library → Add .ZIP Library…
•	Select the downloaded ZIP file
•	Restart the Arduino IDE

Include the library in the code using:
#include <BleKeyboard.h>

4.	Open the gspro-esp32-controller.ino file in the Arduino IDE
5.	Select your ESP32 board and the correct COM port
6.	Upload the sketch to the ESP32

After uploading, power the ESP32 and pair it with your computer via Bluetooth. It will appear as a keyboard named GSPro Controller.

⸻

3D Print Files

This repository includes 3D print files for the enclosure that houses the ESP32 and buttons. The files will be provided in the 3D Print directory.

File Types

•	.3MF
	
This is the recommended file to use. It preserves print orientation, scale, and multi-part organization. The .3MF file can be opened directly in Bambu Studio and sliced without additional setup.

•	.STL
	
The STL files are provided for compatibility with other slicers and printers. If using STL files, you may need to set orientation and print settings manually in your slicer.

Printing Notes
•	The enclosure was designed to be printed in PLA or PETG
•	No supports are required
•	Button holes are sized for standard arcade-style momentary buttons
•	Print orientation is already optimized in the .3MF file

⸻

Customization

The enclosure design can be modified if needed to fit different button layouts or ESP32 boards. The files can be imported into most CAD or slicer software for adjustments.

Customization

You can change key mappings by editing the BtnMap array in the code. GPIO pins and keyboard keys can be reassigned as needed, as long as safe ESP32 pins are used.

⸻

Use Case

This controller is intended to sit on the ground next to the golfer during a simulator session. It allows for quick adjustments like aiming, changing clubs, or viewing data without breaking focus or walking back to the computer.

⸻

Disclaimer

This project is provided as-is. Use at your own risk and verify pin connections before powering the ESP32.
