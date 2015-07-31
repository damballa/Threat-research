#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
unsigned int i, numdoms, domain_iterator, domain_length, initial_seed;

initial_seed = 0x2b44c;
//initial_seed = 0x7ac7;
domain_length = 0;
domain_iterator = 0x00;
numdoms = 0;

char dom[16];
int dom_byte;

while( numdoms < 30)
	{
	unsigned int xor1 = 0; 
	unsigned int shl = initial_seed << 1;
	domain_iterator += 1;
	unsigned int step1 = domain_iterator * shl;
	unsigned int step1b = domain_iterator * initial_seed;
	domain_iterator -= 1;
	unsigned int iter_seed = domain_iterator * initial_seed;

	unsigned int imul_edx = iter_seed * 0x1a;
	xor1 = step1 ^ imul_edx;
	domain_length = 0;
	
	while(domain_length < 0x10)
		{

		unsigned int xor1_divide = xor1 / 0x1a;
		unsigned int xor1_remainder = xor1 % 0x1a;
		unsigned int xo1_rem_20 = xor1_remainder + 0x20;
		unsigned int xo1_step2 = xo1_rem_20 ^ 0xa1;
				
		dom_byte = 0x41 + (0xa1 ^ xo1_step2);
		
		sprintf(dom, "%c", dom_byte);
		printf("%s", dom);			
		
		unsigned int imul_iter = domain_length * step1;
		unsigned int imul_result = domain_length * imul_iter;
		unsigned int imul_1a = 0x1a * imul_result;
		unsigned int xor2 = xor1 ^ imul_1a;
		xor1 = xor1 + xor2;
		
		domain_length += 1;

		}
	printf(".org\n");	
	domain_iterator +=1;
	numdoms +=1;
		
	}

return 0;	
}
