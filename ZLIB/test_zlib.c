#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <zlib.h>
int TestZlib(void);
int TestZlib(void)
{
    /* 计算缓冲区大小，并为其分配内存 */
    FILE *fp;
    char buff[4096]={0};
    uLong blen = 0;
    uLong tlen = 0;
    char* buf = NULL;
    /*
     * 从文件中读取字符串
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
     * 数据压缩
    */
    blen = compressBound(tlen);
    if((buf = (char*)malloc(sizeof(char) * blen)) == NULL)//分配空间分配一个最大压缩上限，压缩后的长度是不会超过blen的
    {
        printf("no enough memory!\n");
        return -1;
    }

    if(compress(buf, &blen, buff, tlen) != Z_OK)            //压缩后将会改变blen的大小
    {
        printf("compress failed!\n");
        return -1;
    }
    printf("tlen = %d\r\n",tlen);                       //打印压缩后字符串长度
    printf("blen = %d\r\n",blen);
    if(buf != NULL)
    {
        free(buf);
        buf = NULL;
    }
}
/*
char text[] = "compress1 1111111111zlib compress2 and uncompress test (compress3)\nturingo (compress4677)\n2012-1compress21-05\n";
uLong tlen = strlen(text) + 1;  ///需要把字符串的结束符'\0'也一并处理
char* buf = NULL;
uLong blen;
printf("tlen = %d\r\n",sizeof(text));

//printf("after compress string %s\r\n",buf);
解压缩
//if(uncompress(text, &tlen, buf, blen) != Z_OK)
//{
//printf("uncompress failed!\n");
//return -1;
//}
打印结果，并释放内存
//printf("%s", text);

*/

