void arrowsConfig(void)
{
	P4SEL &= ~(BIT4|BIT5);
	P2SEL &= ~(BIT6);
	P1SEL &= ~(BIT3);
	
	
	P4DIR &= ~(BIT4|BIT5);
	P2DIR &= ~(BIT6);
	P1DIR &= ~(BIT3);
	
	P4REN |= (BIT4|BIT5);  
	P2REN |= (BIT6);
	P1REN |= (BIT3);	
}

char arrowsIO(void)
{

	unsigned char ret_val = 1;

	
	
	if ((P4IN & BIT4)==1)
		ret_val = 'U';
	if ((P4IN & BIT5)==1)
		ret_val = 'L';
	if ((P2IN & BIT6)==1)
		ret_val = 'D';
	if ((P1IN & BIT3)==1)
		ret_val = 'R';
	return(ret_val);
}


void configUserLED(char inbits)
{
	P4SEL &= ~(BIT0|BIT1);
	P4DIR &= (BIT0|BIT1);
	P4REN |= (BIT0|BIT1);  

	P5SEL &= ~(BIT0|BIT1);
	P5DIR &= (BIT0|BIT1);
	P5REN |= (BIT0|BIT1);


	if((P5IN & BIT0) == inbits)
	{
		P4OUT|=~BIT0;
	}
	if((P5IN & BIT0) == inbits)
	{
		P4OUT|=BIT0;
	}
	if((P5IN & BIT1) == inbits)
	{
		P4OUT|=~BIT1;
	}
	if((P5IN & BIT1) == inbits)
	{
		P4OUT|=BIT1;
	}
}




// to store led, tone and duration i will use a struct int, int, int, these could also be stores in a 3 
//dimensional array of type int
