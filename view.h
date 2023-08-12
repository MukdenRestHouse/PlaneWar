#pragma once
//---------------------游戏界面---------------------
//注：各个页面上需要打印的按钮以及跳转到的页面参考原型图
//	  所有页面均需要调用对应的音乐，音乐暂未确定的，先留有对应的接口



/*
负责人：fgg永恒
功能：打印菜单界面，并且接收用户鼠标输入跳转至对应页面
	右上角签到按钮，签到成功加20金币，签到成功和失败均需要打印对应画面
参数，返回值：void
*/
void menuView();


/*
负责人：fgg永恒
功能：打印暂停页面，并且接收用户鼠标输入跳转至对应页面
参数：int level
返回值：void
*/
void pauseView(int mode,int level);

/*
负责人：fgg永恒
功能：打印获胜页面，并且接收用户鼠标输入跳转至对应页面，若为无限模式下，同时调用排行榜函数bool rankCampare(int num);传入n为本次分数num
		若返回true，表示超过了排行榜上的数量，则弹窗询问用户名后调用函数void rankWriting(int n,string name);
参数：int mode,0表示无限模式,1表示闯关模式,int level为当前关卡
返回值：void
*/
void winView(int mode,int level);


/*
负责人：fgg永恒
功能：打印失败页面，其他同上，无尽模式没有失败页面，所以不需要排行榜，传参也只有一个level
*/
void loseView(int level);


/*
负责人：Lululzz.
功能：打印设置页面，并且接收用户鼠标输入操作对应的设置项
	音量开关：void playMusic(bool music);传入TRUE表示关闭音乐
	皮肤更换：修改全局变量skinType,1,2,3,4分别对应不同的皮肤
参数，返回值：void
*/
void settingView();

/*
负责人：月亮打烊了
功能：打印商店页面，并且接收用户鼠标输入跳转至对应页面
	升级功能：调用bool update(int type);
	购买新装备：调用bool purchase(int type);
	打印成功失败购买的页面
参数，返回值：void
*/
void shopView();

/*
负责人：粒石
功能：打印选关界面，返回选择的关卡作为参数
		若选中未设计的关卡，打印敬请期待
		若选中的关卡的前一关尚未通过，打印提示语，先通过前面的关卡
参数：void
返回值：void
*/
void selectLevelView();

/*
负责人：Lululzz.
功能：打印开发人员介绍页面，并且接收用户鼠标输入退出该页面
参数，返回值：void
*/
void developerView();

/*
负责人：lululzz
！！！！！！！核心！！！！！！！
功能：打印无限模式游戏界面
	void init();
	while(1){
	打印地图
	判断用户是否有输入，若有，接收参数，
		判断接收到的参数，完成对应功能
			使用道具(若该道具不足，返回0，打印提示语)调用bool usingPros(int id);
			改变方向
			暂停游戏，调用void pauseView();

	调用改变敌机、我方飞机、所有子弹的位置函数
	调用我方飞机发射子弹函数
	调用敌方飞机发射子弹函数
	调用随机生成新敌机函数
	调用我方飞机碰撞敌方飞机、子弹或道具的函数
	调用敌机碰撞我方子弹或飞机函数

	判断游戏输赢int isWinInEndlessMode();
		胜利，调用胜利函数void winView(int mode,int level);
		失败，调用失败函数void loseView(int mode);
	sleep(100)
	}
参数，返回值：void
*/
void endlessModeView();

/*
负责人：lululzz
！！！！！！！！！核心！！！！！！！
功能：打印闯关模式游戏界面
	void init();
	while(1){
	打印地图
	判断用户是否有输入，若有，接收参数，
		判断接收到的参数，完成对应功能
			使用道具(若该道具不足，返回0，打印提示语)调用bool usingPros(int id);
			改变方向
			暂停游戏，调用void pauseView();
	调用改变敌机、我方飞机、所有子弹的d位置函数
	调用我方飞机发射子弹函数
	调用敌方飞机发射子弹函数
	调用生成闯关模式对应关卡新敌机函数void addPlaneInCampaignModeView(int level);
	调用我方飞机碰撞敌方飞机、子弹或道具的函数
	调用敌机碰撞我方子弹或飞机函数


	判断游戏是否结束，调用int isWinInCampainMode();
		胜利，调用胜利函数void winView(int mode,int level);
		失败，调用失败函数void loseView(int mode);
	sleep(100)
}
参数：int level选择的关卡
返回值：void
*/
void campaignModeView(int level);

/*
* 负责人：lululzz
功能：打印地图
参数：void
返回值：void
*/
void showMap();


/*
负责人：月亮打烊了
功能：调用排行榜函数void ranking();，打印排行榜
参数：void
返回值：void
*/
void rankingView();

/*
功能：打印游戏介绍，并根据点击的位置切换页面
参数：void
返回自：void
*/
void introView();
