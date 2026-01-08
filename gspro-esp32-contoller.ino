#include <BleKeyboard.h>
BleKeyboard bleKeyboard("GSPro Controller");

struct BtnMap {
  uint8_t pin;
  uint8_t key;
  bool combo;   // true = Ctrl+M
};

BtnMap btns[] = {
  {23, 'o', false},                  // Flyover
  {22, 'm', true},                   // Ctrl + M
  {21, 'j', false},                  // J
  {19, 'a', false},                  // Reset Aim
  {18, KEY_RIGHT_ARROW, false},      // Aim Right
  {17, 'i', false},                  // Club Up
  {33, 'k', false},                  // Club Down (moved to GPIO 33)
  {26, 'y', false},                  // Y
  {25, KEY_LEFT_ARROW, false}        // Aim Left
};

const uint32_t DEBOUNCE_MS = 20;
const size_t BTN_COUNT = sizeof(btns) / sizeof(btns[0]);

bool stableState[BTN_COUNT];
bool lastRead[BTN_COUNT];
uint32_t lastChangeMs[BTN_COUNT];

void pressCtrlM() {
  bleKeyboard.press(KEY_LEFT_CTRL);
  delay(6);
  bleKeyboard.press('m');
}

void releaseCtrlM() {
  bleKeyboard.release('m');
  bleKeyboard.release(KEY_LEFT_CTRL);
}

void setup() {
  Serial.begin(115200);

  for (size_t i = 0; i < BTN_COUNT; i++) {
    pinMode(btns[i].pin, INPUT_PULLUP);   // button → GND
    stableState[i] = digitalRead(btns[i].pin);
    lastRead[i] = stableState[i];
    lastChangeMs[i] = millis();
  }

  bleKeyboard.begin();
}

void loop() {
  if (!bleKeyboard.isConnected()) return;

  for (size_t i = 0; i < BTN_COUNT; i++) {
    bool r = digitalRead(btns[i].pin);

    if (r != lastRead[i]) {
      lastRead[i] = r;
      lastChangeMs[i] = millis();
    }

    if ((millis() - lastChangeMs[i]) >= DEBOUNCE_MS && r != stableState[i]) {
      stableState[i] = r;

      // PRESSED
      if (stableState[i] == LOW) {
        if (btns[i].combo) {
          pressCtrlM();
        } else {
          bleKeyboard.press(btns[i].key);
        }
      }
      // RELEASED
      else {
        if (btns[i].combo) {
          releaseCtrlM();
        } else {
          bleKeyboard.release(btns[i].key);
        }
      }
    }
  }
}
