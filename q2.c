/*
Q2 a) answer : see getStr()
   b) answer : Input:[30001], Output:[GIF]
                  Input:[55555], Output:[NOi]
                  Input:[77788], Output:[VNQ]
   c) answer : 238328 = 62*62*62
   d) answer : see q2_process.c, out.txt
*/

#include <stdio.h>
#include <stdint.h>

const char pool[62] = "C7xicPMGvzAZyTNodmwnV5D3B6H0Oup8E21W9sqLQX4YjSeUhIRJgafFtrKlbk";
/**
 @brief Get Small squares from given X,Y rectangle
 @param [in]  x,y 
 @param [out] arr array of square size
 @retval 0 : Error
*/
int getStr(uint32_t num, char *str)
{
    uint8_t d1, d2, d3;
    if(num>238328) // 62*62*62
        return 0;
    d3=(uint8_t)(num%62);
    d2=(uint8_t)(num/62%62);
    d1=(uint8_t)(num/(62*62));
    
    str[0]=pool[d1];
    str[1]=pool[d2];
    str[2]=pool[d3];
    str[3]=0;
    return 1;
}

void main()
{
    char buf[4];
    uint32_t in[3]={30001, 55555, 77788};
    for(int i=0; i<3; i++){
        if(getStr(in[i], buf)){
            printf("Input:[%d], Output:[%s]\n", in[i], buf);
        }else{
            printf("Wrong Input!\n");
        }
    }

}
