#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BITS_IN_FLOAT 32

typedef unsigned int Word;
union floatWord{
     float f;
     Word w;
};

void printNBits(Word w, unsigned int numBits);

void printBit(Word w, unsigned int pos);

void printSign(Word w);

void printExponent(Word w);

void printFraction(Word w);  
//Prints the 'numBits' least significant bits of w
void printNBits(Word w, unsigned int numBits){
    for(int i = numBits-1; i >= 0; i--){
        printBit(w,i);
    }
    printf("\n");
} 

int main(int argc, char * argv[]){
    union floatWord x;
    
    if(argc < 2){
         fprintf(stderr,"Incorrect usage: %s <float>\n",argv[0]);
         exit(1);
    }
    
    x.f = atof(argv[1]);  
    
    printf("Bits: ");
    printNBits(x.w,BITS_IN_FLOAT);    
    printf("Sign: ");
    printSign(x.w);    
    printf("Fraction: ");  
    printFraction(x.w);  
    printf("Exponent: ");
    printExponent(x.w);    
      
    return 0;   
}
#include <stdio.h>
#include <stdlib.h>

//print an individual bit from the given Word, w 
//at the given pos.  Where a pos of 0 is the least significant bit
//and a pos of 31 gives the most significant bit
//No newline character should be printed in this function
void printBit(Word w, unsigned int pos){
    unsigned int n = 1;
    unsigned int m = (*(unsigned int * ) &w);
    n = n << pos;
	if (n & m) {
    	printf("1");
    } else {
		printf("0");
    }
	//TODO
}

//prints the sign of the given 32 bit Word w, assuming that
//the 32 bits represents an IEEE floating point number
//The sign should be printed as either "+\n" or "-\n"
void printSign(Word w){
	unsigned int n = 1;
    unsigned int m = (*(unsigned int * ) &w);
	n = n << 31;
    if (n & m) {
    	printf("-\n");
    } else {
		printf("+\n");
    }
    //TODO
}

//prints the fraction of the given 32 bit Word w, assuming that
//the 32 bits represents an IEEE floating point number
//The fractional component should be printed in the format of 
//1.XXXXXXXXXXXXXXXXXXXXXXX, where the X's are the bits stored as the 
//fractional component in w.
void printFraction(Word w){
    unsigned int n = 1;
    unsigned int m = (*(unsigned int * ) &w);
    n = n << 31;
	n = n >> 8;
	for (int i = 0; i < 32 - 8; i++) {
		if (n & m) {
			printf("1");
		} else {
			printf("0");
	}
		if (i == 0) printf(".");
		n = n >> 1;
	}
	printf("\n");
}

//prints the exponent of the given 32 bit Word w, assuming that
//the 32 bits represents an IEEE floating point number
//The exponent should be printed in the format of 
//2^E where E is the exponent
void printExponent(Word w){
	
    /*
	unsigned int n = 1;
    unsigned int m = (*(unsigned int * ) &w);
	n = n << 30;
	unsigned char out = 0;
	for (int i = 0; i < 8; i++) {
		if (n & m) {
			unsigned char no = 1;
			no = no << 7;
			no = no >> i;
			out = out | no;
		}
		n = n >> 1;
	}
	printf("2^%u", out);
	*/
	unsigned int n = 1;
    unsigned int m = (*(unsigned int * ) &w);
    n = n << 30;
	int num = 0;
	for (int i = 8; i >= 0; i--) {
		if (n & m) {
			num = num + pow(2, i - 1);
		}
		n = n >> 1;
	}
	printf("%d", num - 127);
	
}
