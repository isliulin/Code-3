/*************************************************************************
	> File Name: LED.h
	> Author: HJJ
	> Mail: 15847703113@163.com
	> Created Time: 2018年09月22日 星期六 11时08分13秒
    > 功能：实现向ＬＥＤ显示屏发送传感器数据
 ************************************************************************/

#ifndef _LED_H
#define _LED_H

int switch_1;   /*0表示主线程可以将数据写入ＬＥＤ的缓冲区，ＬＥＤ这边不可
                 以读缓冲区，1标示ＬＥＤ可以读缓冲区，主线程不可以写缓冲
                 区*/

typedef struct
{
    char id[10];
    char A_temp[10];
    char A_homidity[10];
    char A_EC[10];
    char B_temp[10];
    char B_homidity[10];
    char B_EC[10];
}LED;

LED led_data[2];

/*********************************************
 * 初始化ＬＥＤ显示屏
 * 参数１：ＬＥＤ显示屏的ｉｐ地址
 * 参数２：ＬＥＤ显示屏的端口
 * 返回值：ＬＥＤ显示屏的ＴＣＰ套接字
 * ******************************************/
int initLED(char *ip,int port);


/*********************************************
 * 向ＬＥＤ显示屏发送数据的线程
 * 无参数
 * 无返回值
 * ******************************************/
void *write_LED(void);


#endif
