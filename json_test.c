#include "cJSON.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//void json_publish(cJSON *data);
void json_publish(void);
static int MODH_ReadConfigInfo(cJSON *root);
void SaveDelete(void);

char  Errorpcsmsg[10][896];
/*
 *
 *
*/
void SaveDelete(void)
{
    cJSON *data = NULL;
    cJSON *table = NULL;
    cJSON *parse = NULL;
    cJSON *arry1 = NULL;
    data = cJSON_CreateObject();
//    cJSON_AddNumberToObject(data,"cosc",1.0);
//    cJSON_AddNumberToObject(data,"cosb",1.0);
//    cJSON_AddNumberToObject(data,"cosa",1.0);
//    cJSON_AddNumberToObject(data,"kvarhci",0.0);
//    cJSON_AddNumberToObject(data,"kwhbe",0.0);
//    cJSON_AddNumberToObject(data,"ia",1.035);
//    cJSON_AddNumberToObject(data,"kwhbi",2.1244);
//    cJSON_AddNumberToObject(data,"ua",225.69);
//    cJSON_AddNumberToObject(data,"uc",225.24);
    cJSON_AddStringToObject(data,"ub","224.91");
    cJSON_AddItemToObject(data, "temperature", table = cJSON_CreateArray());
    cJSON_AddItemToArray(table,cJSON_CreateNumber(3));
    cJSON_AddItemToArray(table,cJSON_CreateNumber(0));
    cJSON_AddItemToArray(table,cJSON_CreateNumber(1));
    cJSON_AddItemToArray(table,cJSON_CreateString(">h"));
    cJSON_AddItemToArray(table,cJSON_CreateString("1234"));



//    parse = cJSON_GetObjectItem(data,"temperature");
//    arry1 = cJSON_GetArrayItem(parse,4);
//    printf("***************%s\n",arry1->valuestring);

    char* out = cJSON_PrintUnformatted(data);

    memcpy(Errorpcsmsg[0],out,strlen(out)+1);
    printf("second Errorpcsmsg[0] lens = %d\r\n",strlen(Errorpcsmsg[0]));

    printf("********************SaveDeletedata*****************\n%s"
           "********************************\n",out);
    free(out);
//    json_publish(data);
//    data  = NULL;
    cJSON_Delete(data);
}
/*
 * Create cJSON
*/
//void json_publish(cJSON *data)
void json_publish(void)
{
    char str1[20] = {0};
    char *out = NULL;
    str1[0] = 'P';
    str1[1] = 'C';
    str1[2] = 'S';
    cJSON *root = cJSON_CreateObject();
    cJSON *other_data = NULL;
    cJSON *table = NULL;
    cJSON *table2 = NULL;
    cJSON *data_table = NULL;
    unsigned int error_code;
    cJSON_AddStringToObject(root,"datatype","element");
    cJSON_AddStringToObject(root,"td_peripheral_version","v0.1");
    cJSON_AddStringToObject(root,"td_type","pb620");
    cJSON_AddStringToObject(root,"message_type","meter");
    cJSON_AddStringToObject(root,"td_mctd","10170701000370");
    cJSON_AddStringToObject(root,"message_version","v1.0");
    cJSON_AddStringToObject(root,"meter_type","pb620");
    cJSON_AddStringToObject(root,"time","2017-09-20 00:05:48");
    cJSON_AddStringToObject(root,"td_soft_version","v2.6");

//    cJSON_AddItemToObject(root,"newAddItem",data);

    cJSON_AddItemToObject(root, "other_data", other_data = cJSON_CreateObject());
//    cJSON_AddNullToObject(other_data,"data_type");
//    cJSON_AddStringToObject(other_data,"data_type",str1);
    cJSON_AddNumberToObject(other_data,"data_type",123.1);
    cJSON_AddItemToObject(other_data,"data_table",data_table = cJSON_CreateObject());
    cJSON_AddItemToObject(data_table, "temperature", table = cJSON_CreateArray());
    cJSON_AddItemToArray(table,cJSON_CreateNumber(3));
    cJSON_AddItemToArray(table,cJSON_CreateNumber(0));
    cJSON_AddItemToArray(table,cJSON_CreateNumber(1));
    cJSON_AddItemToArray(table,cJSON_CreateString(">h"));
    cJSON_AddItemToArray(table,cJSON_CreateNumber(0.1));

    cJSON_AddItemToObject(data_table, "Humidity", table2 = cJSON_CreateArray());
    cJSON_AddItemToArray(table2,cJSON_CreateNumber(3));
    cJSON_AddItemToArray(table2,cJSON_CreateNumber(1));
    cJSON_AddItemToArray(table2,cJSON_CreateNumber(1));
    cJSON_AddItemToArray(table2,cJSON_CreateString(">H"));
    cJSON_AddItemToArray(table2,cJSON_CreateNumber(0.1));
    cJSON_AddItemToArray(table2,cJSON_CreateString("invalid"));

    MODH_ReadConfigInfo(table2);
    out = cJSON_PrintUnformatted(root);

//    printf("%s\r\n",out);
//    memcpy(Errorpcsmsg[0],out,strlen(out)+1);
//    printf("Errorpcsmsg[0] lens = %d\r\n",strlen(Errorpcsmsg[0]));


//    printf("*************json_publish*********\n%s*********************\r\n",out);
    free(out);
    cJSON_Delete(root);
    root = NULL;
}

/*
"other_data":{"data_type":123.1,"data_table":{"temperature":[3,0,1,">h",0.1],"Humidity":[3,1,1,">H",0.1]}}
*/
static int MODH_ReadConfigInfo(cJSON *root)
{
    unsigned int i,data_num;
    cJSON *data_table = NULL;
    cJSON *item = NULL;
    char *item_name = NULL;
    item_name = root->string;
    data_num = cJSON_GetArraySize(root);

    printf("%s's data_num = %d\r\n",item_name,data_num);

    for(i=0;i<data_num;i++)
    {
        item = cJSON_GetArrayItem(root,i);
        if(NULL==item)
            return 0;
        if(NULL!=item->valuestring)
            printf("%s[%d]=%s\r\n",item_name,i,item->valuestring);
        else if(i<=2)
            printf("%s[%d]=%d\r\n",item_name,i,item->valueint);
        else if(i==4)
            printf("%s[%d]=%f\r\n",item_name,i,item->valueint);
        else continue;
    }


//    char str1[20] = {0};
//    cJSON *other_data = NULL;
//    cJSON *data_type = NULL;

//    if(!strcmp(root->string,"other_data"))
//    {
//        printf("yes it's other_data item %s\r\n",root->string);
//    }
//    data_type = cJSON_GetObjectItem(root,"data_type");
//    if(data_type==NULL)
//    {
//        return 2;
//    }
//    printf("data_type->valuestring = 0x%02x \n",data_type->valuestring);
//    printf("data_type->valueint = %02x\n",data_type->valueint);
//    printf("data_type->valuedouble = %f\n",data_type->valuedouble);
    return 0;
}















