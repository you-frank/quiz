/* 
void testGetSquarefunc() result

test0(0x0), The area of rectangle is [0], the number of square is [0]
test1(0x1), The area of rectangle is [0], the number of square is [0]
test2(0x1), The area of rectangle is [0], the number of square is [0]

test3(1x2), The area of rectangle is [2], the number of square is [2]
1x1, 1x1,
Sum of areas of small Squares is [2]

test4(2x1), The area of rectangle is [2], the number of square is [2]
1x1, 1x1,
Sum of areas of small Squares is [2]

test5(3x9), The area of rectangle is [27], the number of square is [3]
3x3, 3x3, 3x3,
Sum of areas of small Squares is [27]

test6(7x5), The area of rectangle is [35], the number of square is [5]
5x5, 2x2, 2x2, 1x1, 1x1,
Sum of areas of small Squares is [35]

test7(10x2), The area of rectangle is [20], the number of square is [5]
2x2, 2x2, 2x2, 2x2, 2x2,
Sum of areas of small Squares is [20]

test8(7x5), The area of rectangle is [35], the number of square is [5]
5x5, 2x2, 2x2, 1x1, 1x1,
Sum of areas of small Squares is [35]

test9(3x8), The area of rectangle is [24], the number of square is [5]
3x3, 3x3, 2x2, 1x1, 1x1,
Sum of areas of small Squares is [24]
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>

/**
 @brief Get Small squares from given X,Y rectangle
 @param [in]  x,y 
 @param [out] arr array of square size
 @retval number of square
*/
int getSquare(int x, int y, int* arr)
{
    int i=0, tmp;
    int sm = x<y?x:y;
    int lr = x>y?x:y;

    if(x<=0 || y<=0)
        return 0;
    
    while(sm!=0 && lr!=0){
        int num = floor(lr/sm);
        if(num==1) {
            arr[i++]=sm;
            lr-=sm;
            if(lr==sm)
                sm-=sm;
        }else{
            while(num--){
                arr[i++]=sm;
                lr-=sm;
            }
        }
        if(sm>lr){
            tmp=sm;  sm=lr;  lr=tmp;  // swap small<->large
        }
    }
    arr[i]=0;
    return i;
}

/*
 @brief Test getSquar() with testDat[TEST_NUM]
        print given testDat[i] area and sum of small squares area to compare.
*/
typedef struct{int x; int y;} test_str;
#define TEST_NUM 10
void testGetSquarefunc()
{
    test_str testDat[TEST_NUM] = {{0,0}, {0,1}, {0,1}, {1,2}, {2,1}, {3,9}, {7,5}, {10,2}, {7,5}, {3,8}};
    int arr[100];

    for(int i=0; i<TEST_NUM; i++){
        int num=getSquare(testDat[i].x,testDat[i].y,arr);
        printf("test%d(%dx%d), The area of rectangle is [%d], the number of square is [%d]\n"
                , i, testDat[i].x, testDat[i].y, testDat[i].x*testDat[i].y, num);
        if(num>0){
            int sqAreaSum=0;
            for(int sq=0; sq<num; sq++){
                printf("%dx%d, ",arr[sq], arr[sq]);
                sqAreaSum+=arr[sq]*arr[sq];
            }
            printf("\nSum of areas of small Squares is [%d]\n\n", sqAreaSum);
        }
    }
}



int main()
{
    //testGetSquarefunc();
    uint8_t in[3]={0x63, 0x58, 0x33};
    printf("%d", crc16(in, 3));
    return 0;
}

