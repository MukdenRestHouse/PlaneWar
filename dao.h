#pragma once
#include <string>

//数据存储相关内容
//账号存储
/*
功能：*/


//排行榜存储
/*
负责人：月亮打烊了
功能：将本次分数与排行榜分数进行比较，若超过第10名，返回true
参数：int
返回值：bool
*/
bool rankCompare(int n);

/*
功能：将新分数写入
参数：int n,string name);
返回值：void
*/
void rankWriting(int n, string name);

//该账号对应的道具、升级、金币数量、闯过的关数

/*
负责人：漫勘
功能：根据当前账号的道具、升级、金币数量、闯过的关数，写入对应账号的txt文档中
		传入参数为0表示读取，为1表示存入
* 返回值：void
* 参数：bool
*/
void gameData(bool n);
 