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
        *ALUresult = A+B;
        break;
    
    //Subtraction
    case 0x1:
        *ALUresult = A-B;
        break;
    
    case 0x2:
        //if A < B, Z = 1; otherwise, Z = 0
        *ALUresult = (A < B) ? 1 : 0;
        break;

    case 0x3:
        //if A < B, Z = 1; otherwise, Z = 0 (A and B are unsigned integers)
        *ALUresult = (A < B) ? 1 : 0;
        break;
        
    case 0x4:
        //Z = A AND B
        *ALUresult = A & B;
        break;    
    
    case 0x5:
        //Z = A OR B
        *ALUresult = A | B;
        break;

    case 0x6:
        //Z = SHIFT B LEFT BY 16 BITS
        *ALUresult = B << 16;
        break;
        
    case 0x7:
        //Z = NOT A
        *ALUresult = ~A;
        break;

    default:
        break;
    }
    //Flag
    *Zero = (*ALUresult == 0) ? 1 : 0; 
}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{

//returns signal error for incorrect address
if (PC % 4 != 0) {
    return 1;
}

//Gets correct word from memory
*instruction = Mem[PC >> 2];

//if fetch works, return 0
return 0;
}


/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{ 
    //mask/shift bits for each instruction
    //opcode
    *op = instruction >> 26;
    //rs
    *r1 = (instruction >> 21) & 0x1F;
    //rt
    *r2 = (instruction >> 16) & 0x1F;
    //rd
    *r3 = (instruction >>11) & 0x1F;
    //funct
    *funct = instruction & 0x3F;
    //immediate
    *offset = instruction & 0xFFFF;
    //jump
    *jsec = instruction & 0x3FFFFFF;

}

/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op,struct_controls *controls)
{
    //initialize every signal to zero
    controls->ALUOp = 0;
    controls->ALUSrc = 0;
    controls->Branch = 0;
    controls->Jump = 0;
    controls->MemRead = 0;
    controls->MemtoReg = 0;
    controls->MemWrite = 0;
    controls->RegDst = 0;
    controls->RegWrite = 0;


    //Switch function to decode each instruction
    switch(op) {
        //r type instruction
        case 0x0:
        controls->RegWrite = 1;
        controls->RegDst = 1;
        controls->ALUOp = 7;
        break;

        //lw
        case 0x23: 
        controls->RegWrite = 1;
        controls->MemRead = 1;
        controls->MemtoReg = 1;
        controls->ALUSrc = 1;
        break;

        //sw
        case 0x2B:
        controls->MemWrite = 1;
        controls->ALUSrc = 1;
        controls->RegDst = 1;
        controls->MemtoReg = 1;
        break;

        //beq
        case 0x4:
        controls->Branch = 1;
        controls->RegDst = 1;
        controls->MemtoReg = 1;
        controls->ALUSrc = 1;
        controls->ALUOp = 1;
        break;

        //addi
        case 0x8:
        controls->RegWrite = 1;
        controls->ALUSrc = 1;
        break;

        //slti
        case 0xA:
        controls->ALUOp = 1;
        controls->RegWrite = 1;
        controls->ALUSrc = 1;
        break;

        //sltiu
        case 0xB:
        controls->ALUOp = 1;
        controls->RegWrite = 1;
        controls->ALUSrc = 1;
        break;

        //lui
        case 0xF:
        controls->ALUOp = 1;
        controls->ALUSrc = 1;
        controls->RegWrite = 1;
        break;

        //j
        case 0x2:
        controls->Jump = 1;
        controls->RegDst = 1;
        controls->Branch = 1;
        controls->MemtoReg = 1;
        controls->ALUSrc = 1;
        controls->ALUOp = 1;
        break;

        //halt condition, nothing applies so return 1
        default:
         return 1;
    }
   return 0;
}

/* Read Register */
/* 5 Points */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{
    //Read registers and store into ptrs
    *data1 = Reg[r1];
    *data2 = Reg[r2];

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

