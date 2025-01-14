/*************************************************************************
	> File Name: Transmission.h
	> Author: HJJ
	> Mail: 15847703113@163.com
	> Created Time: 2018年10月09日 星期二 10时47分35秒
 ************************************************************************/

#ifndef _TRANSMISSION_H
#define _TRANSMISSION_H

/*************************************************************************
 * 获取后台接口的版本号,版本号定义形式如V20180929.GET方法
 * 该接口可同时用来测试接口的连通情况
 * 无参数
 * 返回值:成功返回0
 *        失败返回-1
 * **********************************************************************/
int getVersion(void);

/*************************************************************************
 * 上送数据流,POST方法,
 * 参数格式:data=RS;2018-09-07 17:10;10180016;100;20180034;40;100;4;9;A;0;3;a;75.9;A;1;37;a;4.9;A;2;38;a;0.01;B;0;3;a;80.9;B;1;37;a;0.0;B;2;38;a;0.01;C;0;3;a;81.5;C;1;37;a;0.0;C;2;38;a;0.01;2633
 * 无参数
 * 返回值:成功返回0
 *        失败返回-1
 * **********************************************************************/
int pushData(void);




#endif
