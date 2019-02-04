			/*
 * pattern.c
 *
 * Created: 11/21/2017 3:15:13 AM
 * Author : Rishav
 */ 

 #include <avr/io.h>
  #include "pattern.h"
 #include <util/delay.h>

 


 int ab[] = {0x1E,0x00,0x00,0x00,0x00,0x00,0x1E};
 int ac[] = {0b0011110,0b0010010,0b0010010,0b0010010,0b0010010,0b0010010,0b0011110};
 int bb[] = {0x0C,0x12,0x12,0x12,0x12,0x12,0x1E};
 int bc[] = {0b0001100,0b0001100,0b0001100,0b0001100,0b0001100,0b0001100,0b0011110};
 int cb[] = {0x02,0x02,0x02,0x02,0x02,0x04,0x18};
 int cc[] = {0b0000010,0b0000010,0b0000010,0b0000010,0b0000010,0b0000100,0b0011000};
 int db[] = {0x18,0x04,0x02,0x02,0x02,0x1E,0x1E};
 int dc[] = {0b0011000,0b0000100,0b0000010,0b0000010,0b0000010,0b0011110,0b0011110};
 int eb[] = {0x12,0x12,0x12,0x12,0x12,0x1E,0x1E};
 int ec[] = {0b0010010,0b0010010,0b0010010,0b0010010,0b0010010,0b0011110,0b0011110};
 int fb[] = {0x10,0x10,0x10,0x10,0x10,0x1E,0x1E};
 int fc[] = {0b0000110,0b0000110,0b0000110,0b0000110,0b0000110,0b0011110,0b0011110};
 int gb[] = {0x1E,0x12,0x12,0x02,0x02,0x04,0x18};
 int gc[] = {0b0000100,0b0000010,0b0000010,0b0000010,0b0000010,0b0000100,0b0011000};
 int hb[] = {0x1E,0x1E,0x10,0x10,0x10,0x1E,0x1E};
 int hc[] = {0b0011110,0b0011110,0b0010000,0b0010000,0b0010000,0b0011110,0b0011110};
 int ib[] = {0x02,0x02,0x02,0x1E,0x02,0x02,0x02};
 int ic[] = {0b0000010,0b0000010,0b0000010,0b0011110,0b0000010,0b0000010,0b0000010};
 int jb[] = {0x00,0x00,0x00,0x1C,0x02,0x02,0x04};
 int jc[] = {0b0000010,0b0000010,0b0000010,0b0011110,0b0000010,0b0000010,0b0000010};
 int kb[] = {0x04,0x02,0x04,0x08,0x10,0x1E,0x1E};
 int kc[] = {0b0000010,0b0000010,0b0000100,0b0001000,0b0010000,0b0011110,0b0011110};
 int lb[] = {0x02,0x02,0x02,0x02,0x02,0x1E,0x1E};
 int lc[] = {0b0000000,0b0000000,0b0000000,0b0000000,0b0000000,0b0011110,0b0011110};
 int mb[] = {0x1E,0x00,0x00,0x00,0x00,0x00,0x1E};
 int mc[] = {0b0011110,0b0000100,0b0001000,0b0010000,0b0001000,0b0000100,0b0011110};
 int nb[] = {0x1E,0x0E,0x10,0x00,0x00,0x00,0x1E};
 int nc[] = {0b0011110,0b0000000,0b0000000,0b0010000,0b0001000,0b0000110,0b0011110};
 int ob[] = {0x18,0x04,0x02,0x02,0x02,0x04,0x18};
 int oc[] = {0b0011000,0b0000100,0b0000010,0b0000010,0b0000010,0b0000100,0b0011000};
 int pb[] = {0x00,0x00,0x00,0x00,0x00,0x1E,0x1E};
 int pc[] = {0b0001100,0b0010010,0b0010010,0b0010010,0b0010010,0b0011110,0b0011110};
 int qb[] = {0x1A,0x04,0x0A,0x12,0x02,0x04,0x18};
 int qc[] = {0b0011000,0b0000010,0b0000010,0b0000010,0b0000010,0b0000100,0b0011000};
 int rb[] = {0x06,0x04,0x08,0x10,0x00,0x1E,0x1E};
 int rc[] = {0b0001100,0b0010010,0b0010010,0b0010010,0b0010010,0b0011110,0b0011110};
 int sb[] = {0x1C,0x02,0x02,0x02,0x02,0x02,0x02};
 int sc[] = {0b0000010,0b0010010,0b0010010,0b0010010,0b0010010,0b0010100,0b0001000};
 int tb[] = {0x00,0x00,0x00,0x1E,0x00,0x00,0x00};
 int tc[] = {0b0000110,0b0000110,0b0000110,0b0011110,0b0000110,0b0000110,0b0000110};
 int ub[] = {0x18,0x04,0x02,0x02,0x02,0x04,0x18};
 int uc[] = {0b0011110,0b0000000,0b0000000,0b0000000,0b0000000,0b0000000,0b0011110};
 int vb[] = {0x00,0x00,0x1C,0x06,0x1C,0x00,0x00};
 int vc[] = {0b0000110,0b0011000,0b0000000,0b0000000,0b0000000,0b0011000,0b0000110};
 int wb[] = {0x1E,0x04,0x08,0x10,0x08,0x04,0x1E};
 int wc[] = {0b0011110,0b0000000,0b0000000,0b0000000,0b0000000,0b0000000,0b0011110};
 int xb[] = {0x06,0x08,0x10,0x00,0x10,0x08,0x06};
 int xc[] = {0b0000010,0b0000100,0b0001000,0b0010000,0b0001000,0b0000100,0b0000010};
 int yb[] = {0x00,0x00,0x00,0x1E,0x00,0x00,0x00};
 int yc[] = {0b0000110,0b0001000,0b0010000,0b0010000,0b0010000,0b0001000,0b0000110};
 int zb[] = {0x02,0x02,0x02,0x02,0x12,0x0A,0x06};
 int zc[] = {0b0000110,0b0001010,0b0001010,0b0010010,0b0000010,0b0000010,0b0000010}; 




  /* 
  * Takes alphabet and delay time (millis) between columns of character
  * Provides pattern for leds to display character
  */
 void get_pattern( char character, uint8_t delay_time){
	
	 DDRB = 0xff;
	 DDRC = 0xff;
	int i;
	switch (character){
		
		case 'A' :
		for (i=0;i<7;i++){
			//letter_a
			PORTB =ab[i];
			PORTC =ac[i];
			/*delay(delay_time);*/
			_delay_ms(2);
		}
		break;

		case 'B' :
		for (i=0;i<7;i++){
			//letter_b
			PORTB =bb[i];
			PORTC =bc[i];
			delay(delay_time);
		}
		break;
		
		case 'C' :
		for (i=0;i<7;i++){
			//letter_c
			PORTB =cb[i];
			PORTC =cc[i];
			delay(delay_time);
		}
		break;
	
		case 'D' :
		for (i=0;i<7;i++){
			//letter_d
			PORTB =db[i];
			PORTC =dc[i];
			delay(delay_time);
		}
		break;
	
		case 'E' :
		for (i=0;i<7;i++){
			//letter_e
			PORTB =eb[i];
			PORTC =ec[i];
			delay(delay_time);
		}
		break;

		case 'F' :
		for (i=0;i<7;i++){
			//letter_f
			PORTB =fb[i];
			PORTC =fc[i];
			delay(delay_time);
		}
		break;
	
		case 'G' :
		for (i=0;i<7;i++){
			//letter_g
			PORTB =gb[i];
			PORTC =gc[i];
			delay(delay_time);
		}
		break;
	
		case 'H' :
		for (i=0;i<7;i++){
			//letter_h
			PORTB =hb[i];
			PORTC =hc[i];
			delay(delay_time);
		}
		break;
		case 'I' :
		for (i=0;i<7;i++){
			//letter_i
			PORTB =ib[i];
			PORTC =ic[i];
			delay(delay_time);
		}
		break;	

		case 'J' :
		for (i=0;i<7;i++){
			//letter_j
			PORTB =jb[i];
			PORTC =jc[i];
			delay(delay_time);
		}
		break;
	
		case 'K' :
		for (i=0;i<7;i++){
			//letter_k
			PORTB =kb[i];
			PORTC =kc[i];
			delay(delay_time);
		}
		break;

		case 'L' :
		for (i=0;i<7;i++){
			//letter_l
			PORTB =lb[i];
			PORTC =lc[i];
			delay(delay_time);
		}
		break;

		case 'M' :
		for (i=0;i<7;i++){
			//letter_m
			PORTB =mb[i];
			PORTC =mc[i];
			delay(delay_time);
		}
		break;

		case 'N' :
		for (i=0;i<7;i++){
			//letter_n
			PORTB =nb[i];
			PORTC =nc[i];
			delay(delay_time);
		}
		break;

		case 'O' :
		for (i=0;i<7;i++){
			//letter_o
			PORTB =ob[i];
			PORTC =oc[i];
			delay(delay_time);
		}
		break;

		case 'P' :
		for (i=0;i<7;i++){
			//letter_p
			PORTB =pb[i];
			PORTC =pc[i];
			delay(delay_time);
		}
		break;

		case 'Q' :
		for (i=0;i<7;i++){
			//letter_q
			PORTB =qb[i];
			PORTC =qc[i];
			delay(delay_time);
		}
		break;
	
		case 'R' :
		for (i=0;i<7;i++){
			//letter_r
			PORTB =rb[i];
			PORTC =rc[i];
			delay(delay_time);
		}
		break;

		case 'S' :
		for (i=0;i<7;i++){
			//letter_s
			PORTB =sb[i];
			PORTC =sc[i];
			delay(delay_time);
		}
		break;

		case 'T' :
		for (i=0;i<7;i++){
			//letter_t
			PORTB =tb[i];
			PORTC =tc[i];
			delay(delay_time);
		}
		break;

		case 'U' :
		for (i=0;i<7;i++){
			//letter_u
			PORTB =ub[i];
			PORTC =uc[i];
			delay(delay_time);
		}
		break;

		case 'V' :
		for (i=0;i<7;i++){
			//letter_v
			PORTB =vb[i];
			PORTC =vc[i];
			delay(delay_time);
		}
		break;

		case 'W' :
		for (i=0;i<7;i++){
			//letter_w
			PORTB =wb[i];
			PORTC =wc[i];
			delay(delay_time);
		}
		break;

		case 'X' :
		for (i=0;i<7;i++){
			//letter_s
			PORTB =xb[i];
			PORTC =xc[i];
			delay(delay_time);
		}
		break;

		case 'Y' :
		for (i=0;i<7;i++){
			//letter_y
			PORTB =yb[i];
			PORTC =yc[i];
			delay(delay_time);
		}
		break;

		case 'Z' :
		for (i=0;i<7;i++){
			//letter_s
			PORTB =zb[i];
			PORTC =zc[i];
			delay(delay_time);
		}
		break;

	 }
  }
 
 /*
  * Turns off the port between display of two characters
  */
 void blank_pattern(uint8_t delay_time){
	PORTB = 0;
	PORTC = 0;
	/*delay(delay_time);*/
	_delay_ms(20);
 }

 /*
  * Waits for specified time (ms)
  */
  void delay(uint8_t delay_time){
	
	while (delay_time--)
	{
		_delay_ms(1);
	}
		
	
  }