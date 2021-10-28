#if 1
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>

int Memory[100];
int MAR, MBR, AC = 0;
int PC = 0;
int end_flag;
typedef struct ir {
    int save;
    int OPcode;
    int operand;
}Ir;

Ir IR;

// ########## declare Func ###########//
void instruct_fetch();
void instruct_execution();
void Decode();
void Reset();
void end();
void add();
void subtract();
void store();
void load();
void branch_always();
void branch_0();
void branch_up0();
void input();
void output();

// ########## Main Function ###########//
int main(void) {
    char line[100];
    char *string;
    char* pLine;
    FILE* in = fopen("for_sum.txt", "r");
    int i = 0;
    int clock = 0;
    while (1) {
        
        //line = (char*)malloc(sizeof(char) * 100);
        pLine = fgets(line, 100, in);
        if (pLine == NULL) break;
        string = pLine;
        Memory[i] = atoi(string);
        i++;
       
    }

    int number;
    while (1) {
        printf("1. CPU Reset\n");
        printf("2. Execution\n");
        printf("Input Number : ");
        scanf_s("%d", &number);
        Sleep(100);
        system("cls");
        if (number == 1) {
            Reset();
        }
        else if (number == 2) {
            instruct_fetch();
            printf("����������������������������������������������������\n");
            printf("\t   AC : %d\n", AC);
            printf("\t  IR : %d\n", IR.save);
            printf("����������������������������������������������������\n");
            instruct_execution();
            clock++;
        }
        if (end_flag == 1) {
            printf("\n\t Clock : %d", clock);
            break;
        }
    }
    
    fclose(in);
    return 0;
}

// ########## Functions ###########//
void instruct_fetch() {
    MAR = PC;
    MBR = Memory[MAR];
    IR.save = MBR;
    return;
}

void instruct_execution() {
    IR.OPcode = IR.save / 100;
    IR.operand = IR.save % 100;
    Decode();
    return;
}

void Reset() {
    PC = 0;
    AC = 0;
    return;
}

void Decode() {
    
    switch (IR.OPcode) {
    case 0:
        end();
        break;
    case 1:
        add();
        break;
    case 2:
        subtract();
        break;
    case 3:
        store();
        break;
    case 5:
        load();
        break;
    case 6:
        branch_always();
        break;
    case 7:
        branch_0();
        break;
    case 8:
        branch_up0();
        break;
    case 9:
        if (IR.operand == 1)
            input();
        else if (IR.operand == 2)
            output();

        break;
    }
    return;
}

void end() {
    printf("The End!!\n");
    PC = 0;
    AC = 0;
    end_flag = 1;
    return;
}

void load() {
    MAR = IR.operand;
    MBR = Memory[MAR];
    AC = MBR;
    PC++;
    return;
}

void add() {
    MAR = IR.operand;
    MBR = Memory[MAR];
    AC = AC + MBR;
    PC++;
    return;
}


void subtract() {
    MAR = IR.operand;
    MBR = Memory[MAR];
    AC = AC - MBR;
    PC++;
    return;
}

void store() {
    MAR = IR.operand;
    MBR = AC;
    Memory[MAR] = MBR;
    PC++;
    return;
}

void branch_always() {
    PC = IR.operand;
    return;
}

void branch_0() {
    if (AC == 0)
        PC = IR.operand;
    else
        PC++;
    return;
}

void branch_up0() {
    if (AC >= 0)
        PC = IR.operand;
    else
        PC++;
    return;
}

void input() {
    printf("Input Value ������ ");
    scanf_s("%d", &AC);
    PC++;
    return;
}

void output() {
    printf("######## Print AC ########\n");
    printf("            %d            \n", AC);
    printf("##########################\n");
    PC++;
    return;
}
#endif