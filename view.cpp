#include "Base.h"
#include "dao.h"
#include "service.h"
#include "utils.h"
#include "view.h"

void selectLevelView()
{
	cleardevice();
	IMAGE selectleveimage;
	loadimage(&selectleveimage, "./原型图./选关@3x.png", 414, 736);
	putimage(0, 0, &selectleveimage);
	FlushBatchDraw();
	while (1)
	{
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
			{
				if ((msg.x - 105) * (msg.x - 105) + (msg.y - 240) * (msg.y - 240) <= 2500)
				{
					campaignModeView(1);
				}
				if ((msg.x - 300) * (msg.x - 300) + (msg.y - 240) * (msg.y - 240) <= 2500)
				{
					outtextxy(msg.x, msg.y, "尽情期待！");
					Sleep(1000);
					selectLevelView();
				}
				if ((msg.x - 110) * (msg.x - 110) + (msg.y - 390) * (msg.y - 390) <= 2500)
				{
					outtextxy(msg.x, msg.y, "尽情期待！");
					Sleep(1000);
					selectLevelView();
				}
				if ((msg.x - 305) * (msg.x - 305) + (msg.y - 390) * (msg.y - 390) <= 2500)
				{
					outtextxy(msg.x, msg.y, "尽情期待！");
					Sleep(1000);
					selectLevelView();
				}
				if ((msg.x - 110) * (msg.x - 110) + (msg.y - 555) * (msg.y - 555) <= 2500)
				{
					outtextxy(msg.x, msg.y, "尽情期待！");
					Sleep(1000);
					selectLevelView();
				}
				if ((msg.x - 310) * (msg.x - 310) + (msg.y - 555) * (msg.y - 555) <= 2500)
				{
					outtextxy(msg.x, msg.y, "尽情期待！");
					Sleep(1000);
					selectLevelView();
				}
				if (msg.x > 140 && msg.x < 230 && msg.y>640 && msg.y < 680)
				{
					menuView();
				}

			}
			default:
				break;
			}
		}


	}



	}

void developerView()
{
	cleardevice();
	//initgraph(414, 736);
	IMAGE developimage;

	loadimage(&developimage, "原型图/开发人员介绍@3x.png", 414, 736);
	putimage(0, 0, &developimage);
	FlushBatchDraw();
	ExMessage msg;
	while (1)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:

				if (120 < msg.x && 600 < msg.y && msg.x < 260 && msg.y < 640)
				{
					menuView();
				}
				break;
			default:
				break;
			}
		}
	}
}

void settingView()
{
	cleardevice();
	//initgraph(414, 736);
	IMAGE setimage;
	loadimage(&setimage, "原型图/游戏设置@3x.png", 414, 736);

	putimage(0, 0, &setimage);
	FlushBatchDraw();
	ExMessage msg;
	while (1)
	{

		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (180 < msg.x && 215 < msg.y && msg.x < 225 && msg.y < 240)
				{
					playMusic(0);
				}
				if (60 < msg.x && 300 < msg.y && msg.x < 100 && msg.y < 350)
				{

					skinType = 1;

				}
				if (200 < msg.x && 290 < msg.y && msg.x < 255 && msg.y < 350)
				{

					skinType = 2;
				}
				if (60 < msg.x && 410 < msg.y && msg.x < 100 && msg.y < 455)
				{

					skinType = 3;
				}
				if (200 < msg.x && 410 < msg.y && msg.x < 255 && msg.y < 455)
				{

					skinType = 4;
				}
				if (130 < msg.x && 527 < msg.y && msg.x < 270 && msg.y < 570)
				{
					menuView();
				}
				break;

			default:
				break;
			}
		}

		switch (skinType)
		{
		case 1:
			setfillcolor(GREEN);
			fillcircle(85, 330, 22);
			setfillcolor(WHITE);
			fillcircle(230, 330, 22);
			fillcircle(85, 435, 22);
			fillcircle(230, 435, 22);
			break;
		case 2:
			setfillcolor(GREEN);
			fillcircle(230, 330, 22);
			setfillcolor(WHITE);
			fillcircle(85, 330, 22);
			fillcircle(85, 435, 22);
			fillcircle(230, 435, 22);
			break;
		case 3:
			setfillcolor(GREEN);
			fillcircle(85, 435, 22);
			setfillcolor(WHITE);
			fillcircle(85, 330, 22);
			fillcircle(230, 330, 22);
			fillcircle(230, 435, 22);
			break;
		case 4:
			setfillcolor(GREEN);
			fillcircle(230, 435, 22);
			setfillcolor(WHITE);
			fillcircle(85, 330, 22);
			fillcircle(230, 330, 22);
			fillcircle(85, 435, 22);
			break;
		}
	}
}

void shopView()
{
	cleardevice();
	//initgraph(414, 736);

	IMAGE img;
	loadimage(&img, "原型图/商店@3x.png");


	// 缩放图片
	IMAGE scaledImg;

	loadimage(&scaledImg, "原型图/商店@3x.png", 414, 736);
	// 绘制缩放后的图片到窗口中

	while (true)
	{
		BeginBatchDraw(); // 开始批量绘图
		cleardevice();

		putimage(0, 0, &scaledImg);
		setbkmode(TRANSPARENT);
		settextcolor(BLACK);
		settextstyle(20, 0, _T("黑体"));

		char s[20];
		sprintf_s(s, "%d", coin);
		outtextxy(380, 10, s);

		char str[20], st[20];
		sprintf_s(str, "x%d", nuclear_bomb.getNum());//核弹
		sprintf_s(st, "lv%d", myaircraft.getAttackLevel());//火力
		sprintf_s(s, "%d", 1000 + myaircraft.getAttackLevel() * 300);//火力价格
		outtextxy(20, 250, str);
		outtextxy(220, 250, st);
		outtextxy(290, 220, s);

		sprintf_s(str, "x%d", decelerator.getNum());//时间
		sprintf_s(st, "lv%d", myaircraft.getHPLevel());//生命
		sprintf_s(s, "%d", 1500 + myaircraft.getHPLevel() * 400);
		outtextxy(20, 360, str);
		outtextxy(220, 360, st);
		outtextxy(290, 330, s);

		sprintf_s(str, "x%d", resurrection_scroll.getNum());//复活
		sprintf_s(st, "lv%d", myaircraft.getDefenseLevel());//防御
		sprintf_s(s, "%d", 1000 + myaircraft.getDefenseLevel() * 300);
		outtextxy(20, 465, str);
		outtextxy(220, 465, st);
		outtextxy(290, 430, s);
		// 打印文字
		EndBatchDraw(); // 结束批量绘图

		MOUSEMSG msg = GetMouseMsg(); // 获取鼠标事件

		if (msg.uMsg == WM_LBUTTONDOWN) // 判断是否有左键点击事件
		{
			int x = msg.x; // 获取鼠标点击的x坐标
			int y = msg.y; // 获取鼠标点击的y坐标


			if (x >= 140 && x <= 280 && y >= 630 && y <= 680)
			{
				break;//退出
			}
			else if (x >= 145 && x <= 285 && y >= 570 && y <= 600)
			{

				if (!purchase(4)) {//随机
					BeginBatchDraw();
					settextstyle(40, 0, "TRANSPARENT");
					outtextxy(100, 300, "金币不够哦");
					EndBatchDraw();
					Sleep(1000);
					shopView();
					break;
				}
			}
			else if (x >= 40 && x <= 180 && y >= 250 && y <= 270)
			{
				if (!purchase(1)) {//随机
					BeginBatchDraw();
					settextstyle(40, 0, "TRANSPARENT");
					outtextxy(100, 300, "金币不够哦");
					EndBatchDraw();
					Sleep(1000);
					shopView();
					break;
				}
			}
			else if (x >= 40 && x <= 180 && y >= 360 && y <= 380)
			{
				if (!purchase(2)) {//随机
					BeginBatchDraw();
					settextstyle(40, 0, "TRANSPARENT");
					outtextxy(100, 300, "金币不够哦");
					EndBatchDraw();
					Sleep(1000);
					shopView();
					break;
				}//时间
			}
			else if (x >= 40 && x <= 180 && y >= 460 && y <= 480)
			{
				if (!purchase(3)) {
					BeginBatchDraw();
					settextstyle(40, 0, "TRANSPARENT");
					outtextxy(100, 300, "金币不够哦");
					EndBatchDraw();
					Sleep(1000);
					shopView();
					break;
				}//复活
			}
			else if (x >= 260 && x <= 400 && y >= 460 && y <= 480)
			{
				if (!update(3)) {
					BeginBatchDraw();
					settextstyle(40, 0, "TRANSPARENT");
					outtextxy(100, 300, "金币不够哦");
					EndBatchDraw();
					Sleep(1000);
					shopView();
					break;
				}
			}
			else if (x >= 260 && x <= 400 && y >= 360 && y <= 380)
			{
				if (!update(2)) {
					BeginBatchDraw();
					settextstyle(40, 0, "TRANSPARENT");
					outtextxy(100, 300, "金币不够哦");
					EndBatchDraw();
					Sleep(1000);
					shopView();
					break;
				}//生命
			}
			else if (x >= 260 && x <= 400 && y >= 260 && y <= 280)
			{
				if (!update(1)) {
					BeginBatchDraw();
					settextstyle(40, 0, "TRANSPARENT");
					outtextxy(100, 300, "金币不够哦");
					EndBatchDraw();
					Sleep(1000);
					shopView();
					break;
				}//火力
			}
		}
	}

	menuView();

	// 关闭图形窗口
	//closegraph();
}

void menuView() {
	IMAGE img_Bk;
	cleardevice();
	loadimage(&img_Bk, "原型图/主页面.jpg");
	putimage(0, 0, &img_Bk);
	FlushBatchDraw();
	ExMessage msg{ 0 };
	while (true) {
		if (peekmessage(&msg, EX_MOUSE)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x < 277 && msg.x>137 && msg.y < 240 && msg.y>200) {
					selectLevelView();// 闯关模式
					break;
				}
				else if (msg.x < 277 && msg.x>137 && msg.y < 300 && msg.y>260) {
					endlessModeView();//无尽模式
					break;
				}
				else if (msg.x < 277 && msg.x>137 && msg.y < 360 && msg.y>320) {
					rankingView();//排行榜					
					
				}
				else if (msg.x < 277 && msg.x>137 && msg.y < 430 && msg.y>390) {
					shopView();//商店
					//break;
				}
				else if (msg.x < 277 && msg.x>137 && msg.y < 490 && msg.y>450) {
					settingView();//游戏设置
					break;
				}
				else if (msg.x < 277 && msg.x>137 && msg.y < 555 && msg.y>515) {
					introView();//游戏说明
					break;
				}
				else if (msg.x < 277 && msg.x>137 && msg.y < 615 && msg.y>575) {
					developerView();//开发者名单
					break;
				}
				else if (msg.x < 277 && msg.x>137 && msg.y < 675 && msg.y>635) {
					gameData(1);
					exit(0);//退出游戏
				}
				else if (msg.x > 333 && msg.x < 414 && msg.y < 38 && msg.y>0) {
					settextstyle(40, 0, "楷体");
					setbkmode(TRANSPARENT);
					settextcolor(RED);
					if (sign_in == 0) {
						outtextxy(50, 300, "签到成功加20金币");
						coin += 20;
						sign_in=1;
					} 
					else {
						outtextxy(50, 300, "今天已经签过到咯");
					}
					Sleep(1000);
					putimage(0, 0, &img_Bk);
				}
			}
		}
	}
}

void pauseView(int mode, int level) {
	cleardevice();
	IMAGE img_Bk1;
	loadimage(&img_Bk1, "原型图/暂停.png");
	putimage(0, 0, &img_Bk1);
	FlushBatchDraw();
	ExMessage msg{ 0 };
	while (true) {
		if (peekmessage(&msg, EX_MOUSE)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x < 277 && msg.x>137 && msg.y < 240 && msg.y>200) {
					break;//游戏继续
				}
				else if (msg.x < 277 && msg.x>137 && msg.y < 360 && msg.y>320) {
					if (mode == 1) {
						campaignModeView(level);//重新开始
					}
					else {
						endlessModeView();
					}
					break;
				}
				else if (msg.x < 277 && msg.x>137 && msg.y < 475 && msg.y>435) {
					menuView();//返回菜单
					break;
				}
				else if (msg.x < 277 && msg.x>137 && msg.y < 590 && msg.y>550) {
					settingView();//设置
					break;
				}
			}
		}
	}
}

void loseView(int level) {
	cleardevice();
	IMAGE img_Bk1;
	loadimage(&img_Bk1, "原型图/失败界面关卡.png");
	putimage(0, 0, &img_Bk1);

	FlushBatchDraw();
	ExMessage msg{ 0 };
	while (true) {
		if (peekmessage(&msg, EX_MOUSE)) {
			if (msg.message == WM_LBUTTONDOWN) {
				if (msg.x < 267 && msg.x>127 && msg.y < 485 && msg.y>445) {
					campaignModeView(level);//重新开始
					break;
				}
				else if (msg.x < 267 && msg.x>127 && msg.y < 565 && msg.y>525) {
					menuView();//主菜单
					break;
				}
			}
		}
	}
}

void winView(int mode, int level) {
	if (mode == 1) {
		cleardevice();
		IMAGE img_Bk;
		loadimage(&img_Bk, "原型图/胜利界面关卡.jpg");
		putimage(0, 0, &img_Bk);
		FlushBatchDraw();
		ExMessage msg{ 0 };
		while (true) {
			if (peekmessage(&msg, EX_MOUSE)) {
				if (msg.message == WM_LBUTTONDOWN) {
					if (msg.x < 267 && msg.x>127 && msg.y < 457 && msg.y>417) {
						campaignModeView(level);//重新开始
						break;
					}
					else if (msg.x < 267 && msg.x>127 && msg.y < 530 && msg.y>490) {
						level++;
						campaignModeView(level);//下一关
						break;
					}
					else if (msg.x < 267 && msg.x>127 && msg.y < 600 && msg.y>560) {
						menuView();//主菜单
						break;
					}
				}
			}
		}
	}
	else if (mode == 0) {
		cleardevice();
		IMAGE img_Bk;
		loadimage(&img_Bk, "./原型图/胜利界面无尽.png");
		putimage(0, 0, &img_Bk);
		char numCharArray[20]; // 假设整数的最大位数不超过 20 位

    // 使用 std::sprintf 将整数转换为 char 数组
		sprintf(numCharArray, "你获得了%d分，%d金币", num,num/10);
		coin += num / 10;

	
		settextstyle(40, 0, "微软雅黑");
		setbkmode(TRANSPARENT);
		settextcolor(BLUE);
		//outtextxy(50, 200, "你获得了   分");
		outtextxy(50, 200, numCharArray);
		FlushBatchDraw();
		if (rankCompare(score)) {
		settextstyle(40, 0, "微软雅黑");
		setbkmode(TRANSPARENT);
		settextcolor(BLUE);
			outtextxy(10, 300, "打破了记录！请输入你的名字：");
			FlushBatchDraw();
			int l = 50;
			string name;
			while (true)
			{
				if (_kbhit())
				{
					char a = _getch();
					if (a <= 'z' && a >= 'a') {
						outtextxy(l, 350, a);
						FlushBatchDraw();
						l += 20;
						name += a;
					}
					if (a == '\r')break;
				}
			}
			rankWriting(score, name);
		}
		ExMessage msg{ 0 };
		while (true) {
			if (peekmessage(&msg, EX_MOUSE)) {
				if (msg.message == WM_LBUTTONDOWN) {
					if (msg.x < 267 && msg.x>127 && msg.y < 485 && msg.y>445) {
						endlessModeView();//重新开始
						break;
					}
					else if (msg.x < 267 && msg.x>127 && msg.y < 565 && msg.y>525) {
						menuView();//主菜单
						break;
					}
				}
			}
		}
	}
}

void rankingView()
{
	cleardevice();
	// 初始化图形窗口
	//initgraph(414, 736);
	IMAGE img;
	loadimage(&img, "原型图/排行榜@3x.png");


	// 缩放图片
	IMAGE scaledImg;

	loadimage(&scaledImg,  "原型图/排行榜@3x.png", 414, 736);

	// 绘制缩放后的图片到窗口中
	putimage(0, 0, &scaledImg);
	FlushBatchDraw();

	ifstream file("ranking list.txt");
	if (!file)
	{
		outtextxy(100, 100, "Failed to open rank.txt");
	}
	else
	{
		int lineNum = 1;
		string line;
		while (getline(file, line))
		{
			// 将排行榜信息打印到图形窗口上
			setbkmode(TRANSPARENT);
			settextcolor(BLACK);
			settextstyle(20, 0, "黑体");
			outtextxy(80, 170 + 25 * lineNum, line.c_str());
			lineNum++;
			if (lineNum > 10)break;
		}
		file.close();
	}
	while (true)
	{
		MOUSEMSG msg = GetMouseMsg(); // 获取鼠标事件

		if (msg.uMsg == WM_LBUTTONDOWN) // 判断是否有左键点击事件
		{
			int x = msg.x; // 获取鼠标点击的x坐标
			int y = msg.y; // 获取鼠标点击的y坐标

			// 判断点击区域是否在图片上，如果是则关闭排行榜界面
			if (x >= 140 && x <= 280 && y >= 480 && y <= 520)
			{
				break;
			}
		}
	}


	// 关闭图形窗口
	//closegraph();
	menuView();
}
void introView()
{
	cleardevice();
	IMAGE introimage;
	loadimage(&introimage, "./原型图./游戏说明@3x.png", 414, 736);
	IMAGE copy1;
	loadimage(&copy1, "./原型图./游戏说明 Copy 1@3x.png", 414, 736);
	IMAGE copy2;
	loadimage(&copy2, "./原型图./游戏说明 Copy 2@3x.png", 414, 736);
	IMAGE copy3;
	loadimage(&copy3, "./原型图./游戏说明 Copy 3@3x.png", 414, 736);
	putimage(0, 0, &introimage);
	FlushBatchDraw();
	while (1)
	{
		ExMessage msg;
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
			{
				if ((msg.x - 105) * (msg.x - 105) + (msg.y - 630) * (msg.y - 630) < 400)
				{
					putimage(0, 0, &introimage);
				}
				if ((msg.x - 168) * (msg.x - 168) + (msg.y - 630) * (msg.y - 630) < 400)
				{
					putimage(0, 0, &copy1);
				}
				if ((msg.x - 230) * (msg.x - 230) + (msg.y - 630) * (msg.y - 630) < 400)
				{
					putimage(0, 0, &copy2);
				}
				if ((msg.x - 290) * (msg.x - 290) + (msg.y - 630) * (msg.y - 630) < 400)
				{
					putimage(0, 0, &copy3);
				}
				if (msg.x > 127 && msg.x < 266 && msg.y>655 && msg.y < 690)
				{

					menuView();
				}
			default:
				break;
			}
			}
		}
	}
}
void campaignModeView(int level)
{
	cleardevice();
	init();
	BeginBatchDraw();
	ExMessage msg;
	while (1)
	{
		myaircraft = *(ouraircraft.begin());
		showMap();
		FlushBatchDraw();


		addPlaneInCampaignModeView(level);

		shoot();
		changePlace();
		restore();
		isCrash();


		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:

				if (0 < msg.x && 0 < msg.y && msg.x < 50 && msg.y < 50)
				{
					if (usingProp(1));

				}
				if (0 < msg.x && 50 < msg.y && msg.x < 50 && msg.y < 100)
				{
					if (usingProp(2));

				}
				if (0 < msg.x && 100 < msg.y && msg.x < 50 && msg.y < 150)
				{
					if (usingProp(3));

				}

			defalut:
				break;
			}

		}

		if (GetAsyncKeyState('W'))
		{
			direction = 'W';
		}
		else if (GetAsyncKeyState('A'))
		{
			direction = 'A';
		}
		else if (GetAsyncKeyState('S'))
		{
			direction = 'S';
		}
		else if (GetAsyncKeyState('D'))
		{
			direction = 'D';
		}

		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			pauseView(1, level);
		}
		else
		{
			direction = 'B';
		}
		overturn();


		if (isWinInCampainMode(level) == 1)
		{
			winView(1, level);
		}
		else if (isWinInCampainMode(level) == 0)
		{
			if (resurrection_scroll.getNum())
			{
				int ret = MessageBox(GetHWnd(), "请问您是否要使用复活卷轴", "复活卷轴", MB_OKCANCEL);
				if (ret == IDOK)
				{
					usingProp(3);
					resurrection_scroll.setNum(resurrection_scroll.getNum() - 1);
				}
				else
				{
					printf_s("你的游戏之旅到此结束！");
					loseView(0);
				}
			}
			else {
				loseView(0);
			}
		}
		else {}


		Sleep(100);
		timer++;
	}
	EndBatchDraw();


}

void endlessModeView()
{
	cleardevice();
	init();
	BeginBatchDraw();
	ExMessage msg;
	while (1)
	{
		myaircraft = *(ouraircraft.begin());
		showMap();
		FlushBatchDraw();

		if (timer % 10 == 0) {
			addPlaneInEndlessMode();
		}
		shoot();
		changePlace();
		restore();
		isCrash();


		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:

				if (0 < msg.x && 0 < msg.y && msg.x < 50 && msg.y < 50)
				{
					if (usingProp(1));

				}
				if (0 < msg.x && 50 < msg.y && msg.x < 50 && msg.y < 100)
				{
					if (usingProp(2));

				}
				//if (0 < msg.x && 100 < msg.y && msg.x < 50 && msg.y < 150)
				//{
					//if (usingProp(3));

				//}

			defalut:
				break;
			}

		}

		if (GetAsyncKeyState('W'))
		{
			direction = 'W';
		}
		else if (GetAsyncKeyState('A'))
		{
			direction = 'A';
		}
		else if (GetAsyncKeyState('S'))
		{
			direction = 'S';
		}
		else if (GetAsyncKeyState('D'))
		{
			direction = 'D';
		}

		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			pauseView(0, 0);
		}
		else
		{
			direction = 'B';
		}
		overturn();
		if (isWinInEndlessMode() == 1)
		{
			if (resurrection_scroll.getNum())
			{
				int ret = MessageBox(GetHWnd(), "请问您是否要使用复活卷轴", "复活卷轴", MB_OKCANCEL);
				if (ret == IDOK)
				{
					usingProp(3);
					resurrection_scroll.setNum(resurrection_scroll.getNum() - 1);
				}
				else
				{
					printf_s("你的游戏之旅到此结束！");
					winView(0,0);
				}
			}
			else {
				winView(0,0);
			}
		}

		else {}


		Sleep(100);
		timer++;
	}
	EndBatchDraw();

}


void showMap()
{
	IMAGE bk, img_role[4], img_role_mask[4], Gamingimage, img_bull[5], img_bull_mask[5], enemy_role[5], enemy_role_mask[5], props[11], props_mask[11];
	loadimage(&Gamingimage, "./原型图/游戏页面@3x.png", 414, 736);
	loadimage(&img_role[0], "./飞机/皮肤1.png", 80, 80);
	loadimage(&img_role[1], "./飞机/皮肤2.png", 80, 80);
	loadimage(&img_role[2], "./飞机/皮肤3.png", 80, 80);
	loadimage(&img_role[3], "./飞机/皮肤4.png", 80, 80);
	loadimage(&img_role_mask[0], "./掩码图/皮肤1.png", 80, 80);
	loadimage(&img_role_mask[1], "./掩码图/皮肤2。.png", 80, 80);
	loadimage(&img_role_mask[2], "./掩码图/皮肤3。.png", 80, 80);
	loadimage(&img_role_mask[3], "./掩码图/皮肤。4.png", 80, 80);
	loadimage(&img_bull[0], "./子弹/我的子弹.png", 10, 10);
	//loadimage(&img_bull[1], "./子弹/图层16.png", 10, 10);
	loadimage(&img_bull[2], "./子弹/中飞机子弹.png", 10, 10);
	loadimage(&img_bull[3], "./子弹/大飞机子弹.png", 10, 10);
	loadimage(&img_bull[4], "./子弹/BOSS子弹.png", 10, 10);
	loadimage(&img_bull_mask[0], "./掩码图/我的子弹。.png", 10, 10);
	loadimage(&img_bull_mask[1], "./掩码图/图层16。.png", 10, 10);
	loadimage(&img_bull_mask[2], "./掩码图/中飞机子弹。.png", 10, 10);
	loadimage(&img_bull_mask[3], "./掩码图/大飞机子弹。.png", 10, 10);
	loadimage(&img_bull_mask[4], "./掩码图/BOSS子弹。.png", 10, 10);
	loadimage(&enemy_role_mask[0], "./掩码图/小飞机。.png", 50, 50);
	loadimage(&enemy_role_mask[1], "./掩码图/中飞机。.png", 80, 80);
	loadimage(&enemy_role_mask[2], "./掩码图/大飞机。.png", 130, 130);
	loadimage(&enemy_role[0], "./飞机/小飞机.png", 50, 50);
	loadimage(&enemy_role[1], "./飞机/中飞机.png", 80, 80);
	loadimage(&enemy_role[2], "./飞机/大飞机.png", 130, 130);
	//loadimage(&enemy_role[3], "./BOSSA.png", 180, 180);
	//loadimage(&enemy_role[4], "./BOSSB.png", 180, 180);

	loadimage(&props[0], "道具/道具盲盒.png", 180, 180);
	loadimage(&props[1], "./道具/动力失效.png", 180, 180);
	loadimage(&props[2], "./道具/盾.png", 50, 50);
	loadimage(&props[3], "./道具/分身.png", 80, 80);
	loadimage(&props[4], "./道具/复活.png", 130, 130);
	loadimage(&props[5], "./道具/核弹.png", 180, 180);
	loadimage(&props[6], "./道具/键位反转.png", 180, 180);
	loadimage(&props[7], "./道具/时间.png", 50, 50);
	loadimage(&props[8], "./道具/双倍子弹.png", 80, 80);
	loadimage(&props[9], "./道具/随机.png", 130, 130);
	loadimage(&props[10], "./道具/医疗包.png", 180, 180);
	loadimage(&props_mask[0], "./道具/道具盲盒。.png", 180, 180);
	loadimage(&props_mask[1], "./道具/动力失效。.png", 180, 180);
	loadimage(&props_mask[2], "./道具/盾。.png", 50, 50);
	loadimage(&props_mask[3], "./道具/分身。.png", 80, 80);
	loadimage(&props_mask[4], "./道具/复活。.png", 130, 130);
	loadimage(&props_mask[5], "./道具/核弹。.png", 180, 180);
	loadimage(&props_mask[6], "./道具/键位反转。.png", 180, 180);
	loadimage(&props_mask[7], "./道具/时间。.png", 50, 50);
	loadimage(&props_mask[8], "./道具/双倍子弹。.png", 80, 80);
	loadimage(&props_mask[9], "./道具/随机。.png", 130, 130);
	loadimage(&props_mask[10], "./道具/医疗包。.png", 180, 180);

	putimage(0, 0, &Gamingimage);
	switch (skinType)
	{
	case 1:
		putimage(myaircraft.getX(), myaircraft.getY(), &img_role_mask[0], SRCAND);
		putimage(myaircraft.getX(), myaircraft.getY(), &img_role[0], SRCINVERT);
		break;
	case 2:
		putimage(myaircraft.getX(), myaircraft.getY(), &img_role_mask[1], SRCAND);
		putimage(myaircraft.getX(), myaircraft.getY(), &img_role[1], SRCINVERT);
		break;
	case 3:
		putimage(myaircraft.getX(), myaircraft.getY(), &img_role_mask[2], SRCAND);
		putimage(myaircraft.getX(), myaircraft.getY(), &img_role[2], SRCINVERT);
		break;
	case 4:
		putimage(myaircraft.getX(), myaircraft.getY(), &img_role_mask[3], SRCAND);
		putimage(myaircraft.getX(), myaircraft.getY(), &img_role[3], SRCINVERT);
		break;
	}

	if (!m_bullets.empty())
	{
		list<Bullet>::iterator it = m_bullets.begin();
		for (; it != m_bullets.end(); it++) {
			putimage(it->getX() + it->getWid() / 2, it->getY(), &img_bull_mask[0], SRCAND);
			putimage(it->getX() + it->getWid() / 2, it->getY(), &img_bull[0], SRCINVERT);
		}
	}

	if (!e_bullets.empty())
	{
		list<Bullet>::iterator it = e_bullets.begin();
		for (; it != e_bullets.end(); it++) {
			if (it->getId() == 2) {

				putimage(it->getX() + it->getWid() / 2, it->getY(), &img_bull_mask[2], SRCAND);
				putimage(it->getX() + it->getWid() / 2, it->getY(), &img_bull[2], SRCINVERT);

			}
			else if (it->getId() == 3) {

				putimage(it->getX() + it->getWid() / 2, it->getY(), &img_bull_mask[3], SRCAND);
				putimage(it->getX() + it->getWid() / 2, it->getY(), &img_bull[3], SRCINVERT);
			}

		}
	}

	list<EnemyPlane>::iterator it4 = enemyPlanes.begin();

	for (it4; it4 != enemyPlanes.end(); it4++)
	{
		switch (it4->getId())
		{
		case 1:
			putimage(it4->getX(), it4->getY(), &enemy_role_mask[0], SRCAND);
			putimage(it4->getX(), it4->getY(), &enemy_role[0], SRCINVERT);
			break;
		case 2:
			putimage(it4->getX(), it4->getY(), &enemy_role_mask[1], SRCAND);
			putimage(it4->getX(), it4->getY(), &enemy_role[1], SRCINVERT);
			break;
		case 3:
			putimage(it4->getX(), it4->getY(), &enemy_role_mask[2], SRCAND);
			putimage(it4->getX(), it4->getY(), &enemy_role[2], SRCINVERT);
			break;
		case 4:
			putimage(it4->getX(), it4->getY(), &enemy_role_mask[0], SRCAND);
			putimage(it4->getX(), it4->getY(), &enemy_role[0], SRCINVERT);
			break;
		}
	}

	list<ActualWarProps>::iterator it6 = actual_war_props.begin();

	for (it6; it6 != actual_war_props.end(); it6++)
	{
		switch (it6->getId())
		{
		case 1:
			putimage(it6->getX(), it6->getY(), &props_mask[0], SRCAND);
			putimage(it6->getX(), it6->getY(), &props[0], SRCINVERT);
			break;
		case 2:
			putimage(it6->getX(), it6->getY(), &props_mask[1], SRCAND);
			putimage(it6->getX(), it6->getY(), &props[1], SRCINVERT);
			break;
		case 3:
			putimage(it6->getX(), it6->getY(), &props_mask[2], SRCAND);
			putimage(it6->getX(), it6->getY(), &props[2], SRCINVERT);
			break;
		case 4:
			putimage(it6->getX(), it6->getY(), &props_mask[3], SRCAND);
			putimage(it6->getX(), it6->getY(), &props[3], SRCINVERT);
			break;
		case 5:
			putimage(it6->getX(), it6->getY(), &props_mask[4], SRCAND);
			putimage(it6->getX(), it6->getY(), &props[4], SRCINVERT);
			break;
		case 6:
			putimage(it6->getX(), it6->getY(), &props_mask[5], SRCAND);
			putimage(it6->getX(), it6->getY(), &props[5], SRCINVERT);
			break;
		case 7:
			putimage(it6->getX(), it6->getY(), &props_mask[6], SRCAND);
			putimage(it6->getX(), it6->getY(), &props[6], SRCINVERT);
			break;
		case 8:
			putimage(it6->getX(), it6->getY(), &props_mask[7], SRCAND);
			putimage(it6->getX(), it6->getY(), &props[7], SRCINVERT);
			break;
		case 9:
			putimage(it6->getX(), it6->getY(), &props_mask[8], SRCAND);
			putimage(it6->getX(), it6->getY(), &props[8], SRCINVERT);
			break;
		case 10:
			putimage(it6->getX(), it6->getY(), &props_mask[9], SRCAND);
			putimage(it6->getX(), it6->getY(), &props[9], SRCINVERT);
			break;
		case 11:
			putimage(it6->getX(), it6->getY(), &props_mask[10], SRCAND);
			putimage(it6->getX(), it6->getY(), &props[10], SRCINVERT);
			break;
		}
	}
	char buffer[100];
	sprintf(buffer, "当前HP：%d",myaircraft.getHP());
	settextstyle(25,0,"微软雅黑");
	setbkmode(TRANSPARENT);
	settextcolor(RED);
	outtextxy(0, 715,buffer);
}


