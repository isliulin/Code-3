/*************************************************************************
	> File Name: LEDDisplayNetworkPortModule.h
	> Author: 候军军
	> Mail: 15847703113@163.com
	> Created Time: 2018年12月03日 星期一 10时20分41秒
 ************************************************************************/

#ifndef _LEDDISPLAYNETWORKPORTMODULE_H
#define _LEDDISPLAYNETWORKPORTMODULE_H

/********************************************
data[0] : pup编号 xxxxxxxx
data[1] : 数据采集时间,去掉年 xx-xx xx:xx
data[2] : 温度  xx.x
data[3] : 湿度  xx.x
data[4] : EC    x.xx
data[5] : 温度  xx.x
data[6] : 湿度  xx.x
data[7] : EC    x.xx
********************************************/

/*************************************************************************
 *初始化LED屏的通信
 *功能:创建一个UDP的套接字,创建一个线程向LED屏发送数据
 *参数0:LED屏的IP地址
 *参数1:LED屏的端口
 *返回值:成功返回0
 *       失败返回-1
 * **********************************************************************/
int InitLEDModule(char *ip,int port);

/*************************************************************************
 *向LED发送数据
 *功能:向LED显示屏发送数据
 *参数0:待发送的数据(用一个二维数组)
 *参数1:数据的个数(温度,湿度,EC,时间,pup编号)
 *返回值:成功返回0
 *       失败返回-1
 * **********************************************************************/
int SendLEDData(char **data,int datalen);





#endif
