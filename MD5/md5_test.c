#include <stdio.h>
#include <stdlib.h>
#include "md5.h"
int TestMd5(void);
int TestMd5(void)
{
    int i;
    unsigned char encrypt[] ="admin";//21232f297a57a5a743894a0e4a801fc3
    unsigned char decrypt[16];
    MD5_CTX md5;
    MD5Init(&md5);
    MD5Update(&md5,encrypt,strlen((char *)encrypt));
    MD5Final(&md5,decrypt);
    printf("before encrypt:%s\r\nafter encrypt:",encrypt);
    for(i=0;i<16;i++)
    {
        printf("%02x",decrypt[i]);
    }
//    getchar();
    return 0;
}
