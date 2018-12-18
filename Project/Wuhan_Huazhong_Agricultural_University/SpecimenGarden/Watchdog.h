/*************************************************************************
	> File Name: Watchdog.h
	> Author: HJJ
	> Mail: 15847703113@163.com
	> Created Time: 2018年11月13日 星期二 09时54分33秒
 ************************************************************************/

#ifndef _WATCHDOG_H
#define _WATCHDOG_H


//宏定义,
#define SpectrumRetriever 1       //retriever的设备编号为1



/*************************************************************************
 * 初始化看门狗,开启计时
 * 参数1:时间(单位:s)
 * 参数2:要监视的设备
 * 返回值:成功返回0
 *        失败返回-1
 * **********************************************************************/
int initWatchdog(int time,int device);

/*************************************************************************
 * 喂狗函数
 * 参数1:要监视的设备
 * 返回值:成功返回0
 *        失败返回-1
 * **********************************************************************/
int loadWatchdog(int device);

#endif


