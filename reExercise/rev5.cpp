#include <stdio.h>

int main() {
	unsigned char chars[] = { 0xAD, 0xD8, 0xCB, 0xCB, 0x9D, 0x97, 0xCB, 0xC4, 0x92, 0xA1, 0xD2, 0xD7, 0xD2, 0xD6,
		0xA8, 0xA5, 0xDC, 0xC7, 0xAD, 0xA3, 0xA1, 0x98, 0x4C, 0x00 };
	unsigned char res[24] = { 0, };

	for (int i = 22; i >= 0; i--) {
		res[i] = chars[i] - res[i + 1];
	}

	for (int k = 0; k < 23; k++) {
		printf("%c", res[k]);
	}
	return 0;
}
