#include <stdio.h>
#include <string.h>
#include "cJSON.h"
#include <stdlib.h>
#include <time.h>
#include "common.h"
#include "bsp_user_lib.h"

/* MODBUS�ӻ����ݵ��ṹ */
typedef struct{
    char   		key[30];		/* data name */
    uint8_t		fcode;			/* function code */
    uint16_t 	reg;			/* reg addr */
    uint8_t 	num;			/* data quantity */
    uint8_t 	endian;			/* data Endianness */
    uint8_t 	format;			/* data format */
    float 		ratio;			/* data ratio */
}MODBUS_TABLE;
/* MODBUS�ӻ�������Ϣ�ṹ */
typedef struct{
    uint8_t			slave_addr;		/* �ӻ���ַ */
//    RS485CONFIG_T 	g_config;		/* �������� */
    uint16_t		meter_data_num;		/* ���������ݵ���� */
    MODBUS_TABLE 	*meter_table;	/* ���������ݵ�� */
    uint16_t		other_data_num;		/* �����������ݵ���� */
    MODBUS_TABLE 	*other_table;	/* �����������ݵ��*/
  char   pdata_type[20];         /*other �������ݵľ������ͣ���PCS\THSensor\Alarm\DS18B20*/
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
 * ��ӡ���ʱ���
*/
void PrintTimestamp(void)
{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );                  //��ȡ����
    timeinfo = localtime ( &rawtime );  //תΪʱ���
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
 * ��ӡ�������������
 * 1.�ڹ���->ѡ��->����->interface->���ԣ������Ը�ΪChina
 * 2.�޸ı���Ŀ�༭���д���༭Ϊsystem
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

    s1 &=~0x8000;//ȥ������λ
    printf("s1ȥ������λ = %d\n",s1);
    s1 = ~s1+1;  //תΪ����
    s1 = -20/0.1;
    printf("s1תΪ���� = %d\n",s1);

}
{
    unsigned char arry[20] = {0x01,0x03,0,0,0,0x01};
    int i;
    scanf("%s",arry);
    printf("������ַ�Ϊ��%s\n",arry);
//        GetCRC16(arry,6);
}

*/




