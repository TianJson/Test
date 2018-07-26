#include <stdio.h>
#include <string.h>
#include "cJSON.h"
#include <stdlib.h>
#include <time.h>
#include "common.h"
#include "bsp_user_lib.h"

/* MODBUS从机数据点表结构 */
typedef struct{
    char   		key[30];		/* data name */
    uint8_t		fcode;			/* function code */
    uint16_t 	reg;			/* reg addr */
    uint8_t 	num;			/* data quantity */
    uint8_t 	endian;			/* data Endianness */
    uint8_t 	format;			/* data format */
    float 		ratio;			/* data ratio */
}MODBUS_TABLE;
/* MODBUS从机配置信息结构 */
typedef struct{
    uint8_t			slave_addr;		/* 从机地址 */
//    RS485CONFIG_T 	g_config;		/* 串口配置 */
    uint16_t		meter_data_num;		/* 电气量数据点个数 */
    MODBUS_TABLE 	*meter_table;	/* 电气量数据点表 */
    uint16_t		other_data_num;		/* 其他类型数据点个数 */
    MODBUS_TABLE 	*other_table;	/* 其他类型数据点表*/
  char   pdata_type[20];         /*other 类型数据的具体类型，如PCS\THSensor\Alarm\DS18B20*/
}MODBUS_INFO;

MODBUS_INFO *p_tModInfo = NULL;



extern void json_publish(void);
extern void TestFloatToShort(void);
extern int TestMd5(void);
extern void TestSHA256(void);
extern int TestZlib(void);
extern void SaveDelete(void);
extern unsigned short GetCRC16(unsigned char *pbuf,  unsigned short len);
void PrintTimestamp(void);
uint16_t MODH_Get16uValue(uint8_t *pIn);
char arr[50];
int main(int argc, char *argv[])
{
/****************************************
//    TestMd5();
//    TestSHA256();
//    TestFloatToShort();
//    SaveDelete();
//    TestZlib();
****************************************/
    PrintTimestamp();
    json_publish();
//    SaveDelete();
}
/*
 * 打印输出时间戳
*/
void PrintTimestamp(void)
{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );                  //获取秒数
    timeinfo = localtime ( &rawtime );  //转为时间戳
    printf("");
    printf ( "\007The current date/time is: %s", asctime (timeinfo) );
}
void TestStruct(void)
{
        int i;
        p_tModInfo = (MODBUS_INFO *)malloc(5*sizeof(MODBUS_INFO));
        p_tModInfo[0].other_table = (MODBUS_TABLE *)malloc(6*sizeof(MODBUS_TABLE));
        memcpy(p_tModInfo[0].other_table[0].key,"fatempa",strlen("fatempa"));
        memcpy(p_tModInfo[0].other_table[1].key,"fatempb",strlen("fatempb"));

        memcpy(p_tModInfo[0].other_table[2].key,"fatempc",strlen("fatempc"));

        memcpy(p_tModInfo[0].other_table[3].key,"fatempn",strlen("fatempn"));

        memcpy(p_tModInfo[0].other_table[4].key,"fatempa",strlen("fatempa"));

        for(i=0;i<5;i++)
        {
            printf("p_tModInfo[0].other_table%d is %s\n",i,p_tModInfo[0].other_table[i].key);
        }
        free(p_tModInfo[0].other_table);
        free(p_tModInfo);

}
uint16_t MODH_Get16uValue(uint8_t *pIn)
{
    return (pIn[0]|((uint16_t)pIn[1]<<8));
}

/*
 * 打印中文乱码的问题
 * 1.在工具->选项->环境->interface->语言，将语言改为China
 * 2.修改本项目编辑器中代码编辑为system
 *
{
    char *f1 = "123.33";
    float fs = atof(f1);
    printf("atof %05f\n",fs);

}
{
    unsigned short s2 = 0x8064;
    short s1 = 0;
    s1 =s2;
    printf("s2 = %d\n",s2);
    printf("s1 = %d\n",s1);

    s1 &=~0x8000;//去除符号位
    printf("s1去除符号位 = %d\n",s1);
    s1 = ~s1+1;  //转为负数
    s1 = -20/0.1;
    printf("s1转为负数 = %d\n",s1);

}
{
    unsigned char arry[20] = {0x01,0x03,0,0,0,0x01};
    int i;
    scanf("%s",arry);
    printf("输入的字符为：%s\n",arry);
//        GetCRC16(arry,6);
}

*/




