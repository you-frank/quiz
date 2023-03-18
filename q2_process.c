#include <stdio.h>
#include <stdint.h>

typedef struct {int n; char s[3];} tp_str;
tp_str my_dat[] = {
    {15840,	"cGp"},
    {16465, "cmW"},
    {17941,	"cX3"},
    {17942,	"cXB"},
    {18898,	"ctR"},
    {19172,	"ckN"},
    {20512,	"PVg"},
    {20626,	"PD4"},
    {20758,	"PBR"},
    {25736,	"MYM"},
    {25893,	"MSL"},
    {26039,	"MUk"},
    {26134,	"MIE"},
    {26345,	"Mgr"},
    {26346,	"MgK"},
    {26676,	"MKd"},
    {28161,	"GVT"},
    {31622,	"vNx"},
    {31873,	"vwP"},
    {32028,	"vV9"},
    {35260,	"zAj"},
    {36368,	"zO9"},
    {36428,	"zu1"},
    {38716,	"AcO"},
    {38805,	"APF"},
    {40111,	"AHl"},
    {40893,	"ALW"},
    {40956,	"AQ9"},
    {40957,	"AQs"},
    {40958,	"AQq"},
    {40959,	"AQL"},
    {40960,	"AQQ"},
    {42541,	"Zcz"},
    {47987,	"yuk"},
    {49137,	"yh2"},
    {49169,	"yIi"},
    {49443,	"yau"},
    {49444,	"yap"},
    {49639,	"ytL"},
    {50047,	"T7T"},
    {50048,	"T7N"},
    {50127,	"Tx8"},
    {50128,	"TxE"},
    {50129,	"Tx2"},
    {51183,	"Tn2"},
    {51184,	"Tn1"},
    {51204,	"Tnf"},
    {52071,	"T2a"},
    {52977,	"Thu"},
    {54650,	"NTO"},
    {55908,	"N2e"},
    {56100,	"N9g"},
    {57924,	"ocd"},
    {60538,	"oeH"},
    {60539,	"oe0"},
    {60540,	"oeO"},
    {61474,	"okE"},
    {63141,	"dH6"},
    {64436,	"dUw"},
    {64437,	"dUn"},
    {67416,	"m2D"},
    {72677,	"wtT"},
    {73039,	"nCi"},
    {73040,	"nCc"},
    {73211,	"nxJ"},
    {73654,	"nzb"},
    {73756,	"nZq"},
    {74037,	"ndz"},
    {74038,	"ndA"},
    {76081,	"nIG"},
    {76082,	"nIv"},
    {79467,	"VXS"},
    {79564,	"VYw"},
    {79790,	"VeK"},
    {79791,	"Vel"},
    {-1, ""}
};


void main(){
    char buf[64];
    int i=0;
    uint8_t d1, d2, d3;
    FILE* f=fopen("out.txt", "w+");

    while(my_dat[i].n!=-1){
        d1=(uint8_t)(my_dat[i].n%62);
        buf[d1]=my_dat[i].s[2];
        d2=(uint8_t)(my_dat[i].n/62%62);
        buf[d2]=my_dat[i].s[1];
        d3=(uint8_t)(my_dat[i].n/(62*62));
        buf[d3]=my_dat[i].s[0];

        fprintf(f, "%d, %d, %d, (%s)\n", d3, d2, d1, my_dat[i].s);
        i++;
    }
    fclose(f);
    for(int i=0; i<64; i++)
        printf("%d:%c\n", i, buf[i]);  // this will be   const char pool[]="...";
                                       // add '5' manually in index number 21
}
