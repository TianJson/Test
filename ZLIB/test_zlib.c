#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <zlib.h>
int TestZlib(void);
int TestZlib(void)
{
    /* ���㻺������С����Ϊ������ڴ� */
    FILE *fp;
    char buff[4096]={0};
    uLong blen = 0;
    uLong tlen = 0;
    char* buf = NULL;
    /*
     * ���ļ��ж�ȡ�ַ���
     */
    fp = fopen("C:\\Users\\admin\\Desktop\\cfg.txt","r");
    if(fp==NULL)
    {
        printf("file open failed\r\n");
        return -1;
    }
    fread(buff, 4096, 1, fp);
    fclose(fp);
    printf("buff string size = %d\r\n",strlen(buff));

    tlen = strlen(buff);

    /*
     * ����ѹ��
    */
    blen = compressBound(tlen);
    if((buf = (char*)malloc(sizeof(char) * blen)) == NULL)//����ռ����һ�����ѹ�����ޣ�ѹ����ĳ����ǲ��ᳬ��blen��
    {
        printf("no enough memory!\n");
        return -1;
    }

    if(compress(buf, &blen, buff, tlen) != Z_OK)            //ѹ���󽫻�ı�blen�Ĵ�С
    {
        printf("compress failed!\n");
        return -1;
    }
    printf("tlen = %d\r\n",tlen);                       //��ӡѹ�����ַ�������
    printf("blen = %d\r\n",blen);
    if(buf != NULL)
    {
        free(buf);
        buf = NULL;
    }
}
/*
char text[] = "compress1 1111111111zlib compress2 and uncompress test (compress3)\nturingo (compress4677)\n2012-1compress21-05\n";
uLong tlen = strlen(text) + 1;  ///��Ҫ���ַ����Ľ�����'\0'Ҳһ������
char* buf = NULL;
uLong blen;
printf("tlen = %d\r\n",sizeof(text));

//printf("after compress string %s\r\n",buf);
��ѹ��
//if(uncompress(text, &tlen, buf, blen) != Z_OK)
//{
//printf("uncompress failed!\n");
//return -1;
//}
��ӡ��������ͷ��ڴ�
//printf("%s", text);

*/

