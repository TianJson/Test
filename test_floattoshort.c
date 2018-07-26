#include <stdio.h>
void TestFloatToShort(void);
/*
* shor1的范围是-32768~32767，
* 当float类型的fl超出这个范围shor1=-32768或者shor1=32767
* 测试float转short
*/
void TestFloatToShort(void)
{
    float fl = -4000.5;
    short shor1 = 0;
    unsigned char arry[2];
    shor1 = (short)fl;
    printf("shor1=%x\r\n",shor1);
    arry[0] = (shor1>>8)&0xff;
    arry[1] = shor1&0xff;
    printf("******************TestFloatToShort***********************\r\n");
    printf("arry[0]=%x,arry[1]=%x\r\n",arry[0],arry[1]);
    printf("******************TestFloatToShort***********************\r\n");
}
