/*************************************************************************
	> File Name: PLC_communication.h
	> Author: 候军军
	> Mail: 15847703113@163.com
	> Created Time: 2018年11月29日 星期四 17时57分54秒
 ************************************************************************/

#ifndef _PLC_COMMUNICATION_H
#define _PLC_COMMUNICATION_H

/*************************************************************************
 *初始化通讯协议
 *功能:初始化串口,
 *参数:串口的参数
 *返回值:成功返回串口的文件描述符
 *       失败返回-1
 * **********************************************************************/
int PLC_communication_init(char *tty,int baud,int datalen,int check,int stop);


/*************************************************************************
 *向PLC写数据
 *功能:向PLC发送传感器数据
 *参数0:串口文件描述符
 *参数1:要发送的数据
 *参数2:要发送数据的个数
 *参数3:地址
 *参数4:超时时间
 *返回值:成功返回写入的字节个数
 *       失败返回-1
 * **********************************************************************/
int PLC_communication_write(int fd,char **buf,int buflen,int address,int time);


/*************************************************************************
 *从PLC读数据
 *功能:从PLC中读取施肥机的数据
 *参数0:串口文件描述符
 *参数1:要读的数据
 *参数2:要读的字节个数
 *参数3:要读的数据的地址
 *参数4:超时时间
 *返回值:成功返回读到的字节个数
 *       失败返回-1
 * **********************************************************************/
int PLC_communication_read(int fd,char *buf,int buflen,int address,int time);





#endif
