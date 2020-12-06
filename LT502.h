#define PIN 6
#define COM 13
/*
  PIN : a~g : 6~12 , COM : 13 ~
*/

bool number_LED[10][7] = {
  {0,0,0,0,0,0,1},
  {1,0,0,1,1,1,1},
  {0,0,1,0,0,1,0},
  {0,0,0,0,1,1,0},
  {1,0,0,1,1,0,0},
  {0,1,0,0,1,0,0},
  {1,1,0,0,0,0,0},
  {0,0,0,1,1,0,1},
  {0,0,0,0,0,0,0},
  {0,0,0,1,1,0,0},};

class NumberDisplay {
	public :
		int light( int digit, int number );
};

int NumberDisplay :: light( int digit, int number ) {
	int digit_choose[digit][digit] ;
	int *zero = &digit_choose[0][0] ;
	
	for( int momery_zero = 0 ; momery_zero < digit*digit ; momery_zero++ ) 
	   { *zero = 0 ; zero++ ; }
	for( int digit_array = 0 ; digit_array < digit ; digit_array++ ) 
	   { digit_choose[digit_array][digit_array] = 1 ; }
	
	int number_each[digit] ;
	for( int dis = 0 ; dis < digit ; dis++ ) {
	     number_each[dis] = number/pow(10, digit-dis-1) ;
		   number -= number_each[dis]	* pow(10, digit-dis-1) ;
	   }

	unsigned long start = millis() ;
	for( unsigned long pass = 0 ; pass < 100 ; pass = millis() - start ) {
		   for( int scan = 0 ; scan < digit ; scan++ ) {
		 	      for( int choose = 0 ; choose < digit ; choose++ ) 
		 	         { digitalWrite(choose+COM, digit_choose[scan][choose]); }
		 	      for( int lightNum = 0 ; lightNum < 7 ; lightNum++ )
		 	         { digitalWrite(lightNum+PIN, number_LED[ number_each[digit-1-scan] ][ lightNum ]); }
		 	      delay(5) ;
			    } //  
	    }
}
