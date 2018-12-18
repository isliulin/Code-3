/*************************************************************************
	> File Name: main.c
	> Author: 候军军
	> Mail: 15847703113@163.com
	> Created Time: 2018年12月04日 星期二 13时25分59秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"Data_Delivery_Cloud.h"
#include"Watchdog.h"
#include"ReuseFunction.h"
#include"Reteiever_Processing.h"
#include"Retriever_collection.h"
#include"LEDDisplayNetworkPortModule.h"

#define PLC "/dev/ttyO5"   //PLC的串口地址
#define RETRIEVER "/dev/ttyO1"   //retriever的串口地址

#define IP "http://39.105.67.7/LWI-getVersion.php"
#define DATA_IP "http://39.105.67.7/LWI-pushData.php"

int main(void)
{
    FILE *retriever_fd;  //retriever的串口
    int PLC_fd;   //PLC的串口
    int T = 60; //定时60分钟

    while(init_Data_Delivery_Cloud(IP) < 0)  //初始化数据上传
    {
        printf("init_Data_Delivery_Cloud:erroe!!!\n");
        return -1;
    }

    while(initWatchdog(T,SpectrumRetriever) < 0)  //初始化看门狗
    {
        printf("initWatchdog:error!!!\n");
        return -1;
    }

    int sun;
    if(InitLEDModule("192.168.0.236",5005) < 0)
    {
        printf("InitLEDModule:error!!!!!!!\n");
        return -1;
    }

    retriever_fd = init_Retriever(RETRIEVER,9600,8,0,1);   //初始化retriever的串口
    if(retriever_fd == NULL)
    {
        printf("init_Data_Delivery_Cloud:error!!!\n");
        return -1;
    }

    printf("初始化完成!!!\n");
    char data[200] = {0};  //串口接收到的数据
    PUP pup_data;  //解析出来的数据
    char *pup[20] = {0};  //向PLC发送的数组
    char buff0[20] = {0}; 
    char buff1[20] = {0}; 
    char buff2[20] = {0}; 
    char buff3[20] = {0}; 
    char buff4[20] = {0}; 
    char buff5[20] = {0}; 
    char buff6[20] = {0}; 
    char buff7[20] = {0}; 
    char buff8[20] = {0}; 
    char buff9[20] = {0}; 
    char ren[20];  //转换的数

    while(1)
    {
        memset(buff0,0,20);
        memset(buff1,0,20);
        memset(buff2,0,20);
        memset(buff3,0,20);
        memset(buff4,0,20);
        memset(buff5,0,20);
        memset(buff6,0,20);
        memset(buff7,0,20);
        memset(buff8,0,20);
        memset(buff9,0,20);

        //读取数据
        if(0 > Read_Retriever(retriever_fd,data,200))
        {
            printf("Read_Retriever:error!!!\n");
            continue;
        }
        //发送数据到云平台
        comply_Data_Delivery_Cloud(DATA_IP,data);
        printf("%s\n",data);
        //喂狗
        loadWatchdog(SpectrumRetriever);
        //提取数据
        printf("开始拆分数据!!!\n");
        if(0 > Reteiever_Processing(data,&pup_data))
        {
            printf("Reteiever_Processing:error!!!\n");
            continue;
        }
        //处理数据
        printf("数据拆分完成!!!\n");
        
        //处理pup的id
        strcpy(buff0,pup_data.pup_id + 0);

        pup[0] = buff0;
        printf("buff0 = %s\n",buff0);
        printf("pup_data.pup_id = %s\n",pup_data.pup_id);
        //处理时间
        strcpy(buff1,pup_data.time+5);
        pup[1] = buff1;
        printf("时间:%s\n",pup[1]);
        //处理温度
        memset(ren,0,20);
        TemperatureConversionFunction(pup_data.pup_A0,ren);  //将华氏温度转成摄氏温度
        printf("ren = %s\n",ren);
        
        sprintf(buff2,"%2.1f",atof(ren));
        printf("buff2 = %s\n",buff2);

        pup[2] = buff2;
        printf("pup[2] = %s\n",pup[2]);
        
        memset(ren,0,20);
        TemperatureConversionFunction(pup_data.pup_B0,ren);
        printf("ren = %s\n",ren);
        
        sprintf(buff5,"%2.1f",atof(ren));
        printf("buff5 = %s\n",buff5);
        pup[5] = buff5;
       // printf("pup[5] = %s\n",pup[5]);
        //处理湿度
        sprintf(buff3,"%2.1f",atof(pup_data.pup_A1));
        printf("buff3 = %s\n",buff3);
        pup[3] = buff3;
        //printf("pup[3] = %s\n",pup[3]);
         
        sprintf(buff6,"%2.1f",atof(pup_data.pup_B1));
        printf("buff6 = %s\n",buff6);
        pup[6] = buff6;
        //printf("pup[6] = %s\n",pup[6]);
        //处理EC 
        
        sprintf(buff4,"%1.2f",atof(pup_data.pup_A2));
        pup[4] = buff4;
        //printf("pup[4] = %s\n",pup[4]);

        sprintf(buff7,"%1.2f",atof(pup_data.pup_B2));
        pup[7] = buff7;
        //printf("pup[7] = %s\n",pup[7]);
        printf("数据处理完成!!!\n");
        //发送数据到PLC 
        printf("pup[0] = %s\n",pup[0]);
        if(0 > SendLEDData(pup,8))
        {
            printf("SendLEDData:error!!!\n");
            continue;
        }
    printf("数据发送完成!!!\n");
    }
}
