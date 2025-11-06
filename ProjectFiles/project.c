#include "spimcore.h"


/* ALU */
/* 10 Points */
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{
    //Do operations shown in table (instructions) and output correct result
    //case 1..2..3..4 etc ?
    switch (ALUControl)
    {
    //Addition
    case 0x0:
        ALUresult = A+B;
        break;
    
    //Subtraction
    case 0x1:
        ALUresult = A-B;
        break;
    
    
    case 0x2:
        //if A < B, Z = 1; otherwise, Z = 0
        break;

    case 0x3:
        //if A < B, Z = 1; otherwise, Z = 0 (A and B are unsigned integers)
        break;
        
    case 0x4:
        //Z = A AND B
        ALUresult = A & B;
        break;    
    
    case 0x5:
        //Z = A OR B
        ALUresult = A | B;
        break;

    case 0x6:
        //Z = SHIFT B LEFT BY 16 BITS
        ALUresult = B << 16;
        break;
        
    case 0x7:
        //Z = NOT A
        ALUresult = ~A;
        break;
        
        

    default:
        break;
    }

}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{

}


/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{

}



/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op,struct_controls *controls)
{

}

/* Read Register */
/* 5 Points */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{

}


/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset,unsigned *extended_value)
{

}

/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{

}

/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem)
{

}


/* Write Register */
/* 10 Points */
void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg)
{

}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC)
{

}

