﻿#include "MFRC522.h"
#include "bcm2835.h"
#include <iostream>

using namespace std;
int main() {
	setlocale(LC_ALL, "Turkish");
	cout << "Kartı okutunuz..." << endl;
	
	MFRC522 mfrc;
	mfrc.PCD_Init();

	while (true) {
		if (!mfrc.PICC_IsNewCardPresent())
			continue;

		if (!mfrc.PICC_ReadCardSerial())
			continue;

		printf("Kart seri no: ");
		for (byte i = 0; i < mfrc.uid.size; ++i) {
			if (mfrc.uid.uidByte[i] < 0x10) {
				printf(" 0");
				printf("%X", mfrc.uid.uidByte[i]);
			}
			else {
				printf(" ");
				printf("%X", mfrc.uid.uidByte[i]);
			}
		}
		printf("\n");

		delay(1000);
	}
}