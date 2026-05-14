//cat /usr/include/elf.h | less
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
	char data[10];
	fgets(data,5,fptr);//fgets reads one less than the size
	/*
	 fgets() reads in at most one less than size characters from stream  and  stores  them  into  the
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
	
	printf("[=] Checking ELF Byte encoding format type\n");
	fgets(data,2,fptr);
	if(data[0]==1){
		printf("[+] 2's Compliment Little Endian FILE\n");
	}
	else{
		printf("[+] 2's Compliment Big Endian FILE\n");

	}

	fgets(data,2,fptr);
	printf("[=] Checking ELF Version\n");
	printf("[+] File version is : %d \n",data[0]);

	printf("[=] Checking ELF OS ABI\n");
	fgets(data,2,fptr);
	switch (data[0]){
		case 0:
			printf("[+] UNIX SYSTEM V ABI \n");
			break;
		case 1:
			printf("[+] HP-UX ABI \n");
			break;
		case 2:
			printf("[+] NetBSD ABI \n");
			break;
		case 3:
			printf("[+] GNU/LINUX ABI \n");
			break;
		case 6:
			printf("[+] Sun Solaris ABI \n");
			break;
		case 7:
			printf("[+] IBM AIX ABI \n");
			break;
		case 8:
			printf("[+] SGI Irix ABI \n");
			break;
		case 9:
			printf("[+] Free BSD ABI \n");
			break;
		case 10:
			printf("[+] Compaq TRU64 UNIX ABI \n");
			break;
		case 11:
			printf("[+] Novell Modesto ABI \n");
			break;
		case 12:
			printf("[+] Open BSD ABI \n");
			break;
		case 64:
			printf("[+] ARM EABI \n");
			break;
		case 97:
			printf("[+] ARM ABI \n");
			break;
		case 255:
			printf("[+] STAND ALONE APPLICATION  \n");
			break;
		}
	printf("[=] Checking ELF ABI Version\n");
	fgets(data,2,fptr);
	printf("[+] The ABI version is : %d\n",data[0]);
	fclose(fptr);
	return 0;
}
