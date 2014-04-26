#line 1 "I:/Documents/Projects/Pic Tools/Published Projects/Led Chaser/Led Chaser.c"
unsigned int i;

void main() {









 OSCCON=0x6E;






 CMCON=0x07;
#line 32 "I:/Documents/Projects/Pic Tools/Published Projects/Led Chaser/Led Chaser.c"
 ADCON1=0x8F;






 TRISB=0x00;




 TRISB=0x00;
 while(1){
 PORTB=0x80;
 for(i=0; i<7; i++){
 Delay_ms(100);
 PORTB=PORTB>>1;
 }
 Delay_ms(100);
 PORTB=0x01;
 for(i=0; i<7; i++){
 Delay_ms(100);
 PORTB=PORTB<<1;
 }
 Delay_ms(100);
 }
}
