/*************************************************************************
	> File Name: ReuseFunction.h
	> Author: 候军军
	> Mail: 15847703113@163.com
	> Created Time: 2018年11月30日 星期五 09时55分04秒
    >简介: 一些会重复使用的功能函数放到这里.
 ************************************************************************/

#ifndef _REUSEFUNCTION_H
#define _REUSEFUNCTION_H

/*************************************************************************
 *温度转换函数
 *功能:将华氏温度转换为摄氏温度
 *参数0:华氏温度的字符串
 *参数1:摄氏温度的字符串
 *返回值:成功返回0
 *       失败返回-1
 * **********************************************************************/
int TemperatureConversionFunction(char *F,char *C);


/*************************************************************************
 *数据放大函数
 *功能:PLC无法处理浮点数据,所以在使用中将浮点数据扩到到相应的整数
 *参数0:要扩大的字符串数据
 *参数1:扩大的倍数
 *参数2:扩大后的字符串
 *返回值:成功返回0
 *       失败返回-1
 * **********************************************************************/
int DataAmplificationFunction(char *data,int multiple,char *BigData);

/*************************************************************************
 *
 *
 *
 *
 *
 * **********************************************************************/




#endif
