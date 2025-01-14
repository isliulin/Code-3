/*************************************************************************
	> File Name: database.c
	> Author: 候军军
	> Mail: 15847703113@163.com
	> Created Time: 2019年02月15日 星期五 12时16分11秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<sqlite3.h>




/*
 * 功能:初始化数据库,就是打开数据库
 * sqlite3_open();
 * 参数:数据库的名字
 * 返回值:数据库的描述符
 * 失败返回NULL
 * */
sqlite3 *init_sqlite(char *database);




/*
 * 功能:向数据库写数据,向表中插入数据
 * sqlite3_exec();
 * 参数:要插入的数据
 * 返回值:0表示成功
 *        1表示失败
 * */
int write_sqlite(char *data);

/**
 * 功能;从数据库中读数据,
 *
 * */  



/**
 * 功能:查询数据库中数据的个数
 *
 *
 * */


/*
 * 功能:关闭数据库
 *
 *
 *
 *
 * */



