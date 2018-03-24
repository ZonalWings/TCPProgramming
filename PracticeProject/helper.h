#include <stdio.h>
#include <stdint.h>
#include <string.h>

long getFileSize(FILE* fp);											/* Return the file size; does not change the current position in the file. */
uint8_t getType(FILE* fp);											/* Returns the Type of the Unit */
uint8_t getT0Amount(FILE* fp);										/* Returns the amount of a Type 0 Unit */
void getT1Amount(FILE* fp, char* t1Amount);							/* Reads the amount of a Type 1 Unit into t1Amount */
int validateT1Amount(char* t1Amount);								/* Checks that the amount is only made up of numeric ASCII digits */
void t0AmountTot1Amount(uint8_t t0Amount, char* t1Amount);			/* Converts t0Amount to its corresponding Type 1 Amount and stores it into t1Amount */ 
uint16_t t1AmountTot0Amount(char* t1Amount);						/* Returns the Type 0 equivalent of a t1Amount */
void populateT0Buffer(FILE* fp, uint16_t* buffer, uint8_t amount);	/* Reads the Numbers of a Type 0 Unit into buffer */
void printT0Numbers(uint16_t* buffer, uint8_t amount);				/* Prints the Type 0 Numbers of a Unit to the screen */
int sizeOfT1Numbers(FILE* fp, long fileSize);						/* Returns the size in bytes of the Numbers of a Type 1 Unit */
void populateT1Buffer(FILE* fp, uint8_t* buffer, uint8_t amount);	/* Reads the Numbers of a Type 1 Unit into buffer */
void printT1Numbers(uint8_t* buffer, int unitSize);					/* Prints the Type 1 Numbers of a Unit to the screen */
void writeType0(FILE* out, uint8_t amount, uint16_t* buffer);		/* Writes a Type 0 Unit to the out file, given Type 0 data */
void writeType0FromType1(FILE* out, uint8_t amount, uint8_t* buffer, int unitSize);	/* Writes a Type 0 Unit to the out file, given Type 1 data */
