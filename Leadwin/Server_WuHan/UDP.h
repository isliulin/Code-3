/*************************************************************************
	> File Name: UDP.h
	> Author: HJJ
	> Mail: 15847703113@163.com
	> Created Time: 2018年09月18日 星期二 08时56分06秒
    > 通过ＵＤＰ从ｓｅｎｓｏｒ接收数据
 ************************************************************************/

#ifndef _UDP_H
#define _UDP_H

/*******************************************************
 *初始化ＵＤＰ通信
 *参数２：端口号
 *返回值：成功返回套接字，失败返回－１
 * ****************************************************/
int initUDP(uint16_t hostshort);

/*******************************************************
 *接收客户端发来的数据的函数
 *
 *
 * ****************************************************/
char * read_UDP(int UDP_fd);

void *read_UDP_pthread(void *UDP_fd);


/*******************************************************
 *向客户端发送数据接收情况的函数
 *
 * ****************************************************/


/*******************************************************
 *关闭ＵＤＰ套接字
 *参数１：ＵＤＰ套接字
 *返回值：无返回值
 * ****************************************************/
void close_UDP(int sockfd);

#endif
