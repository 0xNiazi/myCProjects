#include <stdio.h>

int main(int argc, char * argv[]){
	if (argc<2 ){
	printf("ERROR: File name not specified\n%s <file>",argv[0]);
	return 1;
	}
	FILE *fptr;
	fptr = fopen(argv[1],"r");
	if (fptr<=0){
	printf("ERROR: Unable to open %s",argv[1]);
	return 1;
	}
	printf("File to be analyzed: %s\n",argv[1]);
	/*char data [10];
	while (fgets(data,10,fptr)!=NULL){
	printf("%s",data);
	}
	*/
	char data[10];
	fgets(data,5,fptr);//fgets reads one less than the size
	/*
	 * fgets() reads in at most one less than size characters from stream  and  stores  them  into  the
	buffer  pointed  to by s.  Reading stops after an EOF or a newline.  If a newline is read, it is
	stored into the buffer.  A terminating null byte ('\0') is stored after the  last  character  in
	the buffer.
	*/
	printf("[=] Checking ELF headers\n");
	if (data[0]==0x7f && data[1]==0x45 && data[2]==0x4c && data[3]==0x46){
		printf("[+] FOUND ELF HEADERS\n");
	}
	else{
		printf("[-] ELF HEADERS NOT FOUND NOT A ELF FILE\nEXITING\n");
		return 1;
	}
	fgets(data,2,fptr);
	int bitformat = data[0];
	printf("[=] Checking ELF BIT format type\n");
	if(bitformat==1){
		printf("[+] 32 BIT ELF FILE\n");
	}
	else{
		printf("[+] 64 BIT ELF FILE\n");
	}
	fclose(fptr);
	return 0;
}
