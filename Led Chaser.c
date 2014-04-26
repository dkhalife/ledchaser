unsigned int i;

void main() {
	//**
	//  Oscillator Configuration:
	//  0b0
	//  - 4 MHz (110)
	//  - Primary system clock (1)
	//  - Stable frequency (1)
	//  - System clock : Internal RC (10)
	//  - Total : 0b01101110
	//**
	OSCCON=0x6E;

	//**
	//  Comparator Configuration:
	//  Disable all
	//  - Total : 0b00000111;
	//**
	CMCON=0x07;

	//**
	//  A/D Configuration:
	//  0b
	//  Left Justified (1)
	//  A/D Clock divide by 2 disabled (0)
	//  VRef - = VSS (0)
	//  VRef + = VDD (0)
	//  - AllDigital (1111)
	//  - Total : 0b10001111;
	//**
	ADCON1=0x8F;

	//**
	//  PORT Directions
	//  - Output:
	//    + PORTB
	//**
	TRISB=0x00;

	//**
	//  Main Program
	//**
	TRISB=0x00;
	while(1){ // Forever
		PORTB=0x80;	// RD7 is on at first
		for(i=0; i<7; i++){
			Delay_ms(100);	// 100 ms delay between shifts
			PORTB=PORTB>>1;	// Shift status one bit to the right 
		}
		Delay_ms(100);
		PORTB=0x01;	// RD0 is on now
		for(i=0; i<7; i++){
			Delay_ms(100);
			PORTB=PORTB<<1; // Shift status one bit to the left
		}
		Delay_ms(100);
	}
}
