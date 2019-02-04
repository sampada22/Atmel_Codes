/*
 * pov_2.cpp
 *
 * Created: 11/20/2017 5:17:00 AM
 * Author : Sampada Dhakal21211
 */ 
#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED1 PINB1
#define LED2 PINB2
#define LED3 PINB3
#define LED4 PINB4
#define LED5 PINC4
#define LED6 PINC3
#define LED7 PINC2
#define LED8 PINC1

#define rps 

int i;
int main(void)
{   int ab[] = {0x1E,0x00,0x00,0x00,0x00,0x00,0x1E};
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
		
		
   
    while (1) 
    {
		for (i=0;i<7;i++){
			//letter_a
			PORTB =ab[i];
			PORTC =ac[i];
			_delay_ms(200);
			
		}
		for (i=0;i<7;i++){
			//letter_b
			PORTB =bb[i];
			PORTC =bc[i];
			_delay_ms(200);
			
		}
		for (i=0;i<7;i++){
			//letter_c
			PORTB =cb[i];
			PORTC =cc[i];
			_delay_ms(200);
			
		}
		for (i=0;i<7;i++){
			//letter_d
			PORTB =db[i];
			PORTC =dc[i];
			_delay_ms(200);
			
		}
		for (i=0;i<7;i++){
			//letter_e
			PORTB =eb[i];
			PORTC =ec[i];
			_delay_ms(200);
			
		}
		for (i=0;i<7;i++){
			//letter_f
			PORTB =fb[i];
			PORTC =fc[i];
			_delay_ms(200);
			
    }
	for (i=0;i<7;i++){
		//letter_g
		PORTB =gb[i];
		PORTC =gc[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_h
		PORTB =hb[i];
		PORTC =hc[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_i
		PORTB =ib[i];
		PORTC =ic[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_j
		PORTB =jb[i];
		PORTC =jc[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_k
		PORTB =kb[i];
		PORTC =kc[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_l
		PORTB =lb[i];
		PORTC =lc[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_m
		PORTB = mb[i];
		PORTC =mc[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_n
		PORTB =nb[i];
		PORTC =nc[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_o
		PORTB =ob[i];
		PORTC =oc[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_p
		PORTB =pb[i];
		PORTC =pc[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_q
		PORTB =qb[i];
		PORTC =qc[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_r
		PORTB =rb[i];
		PORTC =rc[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_s
		PORTB =sb[i];
		PORTC =sc[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_t
		PORTB =tb[i];
		PORTC =tc[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_u
		PORTB =ub[i];
		PORTC =uc[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_v
		PORTB =vb[i];
		PORTC =vc[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_w
		PORTB =wb[i];
		PORTC =wc[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_x
		PORTB =xb[i];
		PORTC =xc[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_y
		PORTB =yb[i];
		PORTC =yc[i];
		_delay_ms(200);
		
	}
	for (i=0;i<7;i++){
		//letter_z
		PORTB =zb[i];
		PORTC =zc[i];
		_delay_ms(200);
		
	}
}

}