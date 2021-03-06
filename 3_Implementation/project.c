#include<stdio.h>
#include<math.h>
#include<string.h>
void getColorCode(char colorCode[]);
long getResistorValue( char colorCode[], int colorValue[], int resistor_value );


int main (void)
{
    long resistor_value = 0; 
    char colorCode[4];
    int  colorValue[4];

    
    printf("This program will calculate the value of a resistor.\n\n");
    printf("B = Black\nN = Brown\nR= Red\nO = Orange\nY = Yellow\nx = black\n");
    printf("G = Green\nL = Blue\nV = Violet\nE = Gray\nW = White\n\n");
    printf("Enter the 3-character color description of the resistor: ");
    
    getColorCode(colorCode);

      resistor_value =  getResistorValue(colorCode, colorValue, resistor_value);
        
    printf("\n\nThe resistor with color code %c %c  has a value of %ld Ohms.\n",colorCode[0], colorCode[1], resistor_value);
            
    return 0;
}

void getColorCode(char colorCode[])
{
    int i;
    for(i = 0; i < 4; i++)
        colorCode[i] = getchar();
}

long getResistorValue( char colorCode[], int colorValue[], int resistor_value )
{

    int i;
    int j;
    long multiplier;
      
    for( i = 0; i < 3; i++)
    {
        switch (colorCode[i])
        {
            case('b'):
            case('B'):
                colorValue[i] = 0;
                break;
        
            case('n'):
            case('N'):
                colorValue[i] = 1;
                break;
        
            case('r'):
            case('R'):
                colorValue[i] = 2;
                break;
        
            case('o'):
            case('O'):
                colorValue[i] = 3;
                break;

            case('y'):
            case('Y'):
                colorValue[i] = 4;
                break;
    
            case('g'):
            case('G'):
                colorValue[i] = 5;
                break;
    
            case('l'):
            case('L'):
                colorValue[i] = 6;
                break;
    
            case('v'):
            case('V'):
                colorValue[i] = 7;
                break;
    
            case('e'):
            case('E'):
                colorValue[i] = 8;
                break;
    
            case('w'):
            case('W'):
                colorValue[i] = 9;
                break;
			default: break;
        }
    }
    
    for( j = 0; j < 8; j++)
       {
        switch (colorCode[3])
         {
             case('x'):
            case('X'):
                multiplier = 0;
                break;
            case('b'):
            case('B'):
                multiplier = 1;
                break;
                
            case('n'):
            case('N'):
                multiplier = 10;
                break;
            
            case('r'):
            case('R'):
                multiplier = 100;
                break;
                
            case('o'):
            case('O'):
                multiplier = 1000;
                break;
            
            case('y'):
            case('Y'):
                multiplier = 10000;
                break;
                
            case('G'):
            case('g'):
                multiplier = 100000;
                break;
                
            case('l'):
            case('L'):
                multiplier = 1000000;
                break;
                
            case('v'):
            case('V'):
                multiplier = 10000000;
                break;
			
			default: break;
        }

        resistor_value = (((colorValue[0])*10 *multiplier) + ((colorValue[1])  * multiplier));
        
    }
    
    return resistor_value;
}