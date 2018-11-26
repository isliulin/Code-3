/*************************************************************************
	> File Name: modbus.h
	> Author: HJJ
	> Mail: 15847703113@163.com
	> Created Time: 2018年08月26日 星期日 11时11分35秒
 ************************************************************************/

#ifndef _MODBUS_H
#define _MODBUS_H

/*******************************
 * 初始化modbus串口
 * 参数０：串口的地址
 * 参数１：波特率
 * 参数２：数据位
 * 参数３：校验位
 * 参数４：停止位
 * 返回值：成功返回文件描述符，失败返回－１
 * ****************************/
int initModbus(char *tty,int baud,int datalen,int check,int stop);
    
/******************************
 * modbus串口的线程
 * 参数０：
 *
 * ****************************/


#endif
