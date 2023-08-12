#include "Base.h"
#include "dao.h"
#include "service.h"
#include "utils.h"
#include "view.h"
void playMusic(int x)
//共有5个界面
{
	static int music = 1;
	switch (x)
	{


	case 0: {
		setfillcolor(GREEN);
		fillcircle(200, 230, 20);
		music++;

		if (music % 2 == 0)
		{
			mciSendString("setaudio ./BGM1.mp3 volume to 0", NULL, 0, NULL);
			mciSendString("setaudio ./BGM2.mp3 volume to 0", NULL, 0, NULL);
			mciSendString("setaudio ./BGM3.mp3 volume to 0", NULL, 0, NULL);
			mciSendString("setaudio ./BGM4.mp3 volume to 0", NULL, 0, NULL);
			mciSendString("setaudio ./BGM5.mp3 volume to 0", NULL, 0, NULL);

		}
		if (music % 2 == 1)
		{
			mciSendString("setaudio ./BGM1.mp3 volume to 50", NULL, 0, NULL);
			mciSendString("setaudio ./BGM2.mp3 volume to 50", NULL, 0, NULL);
			mciSendString("setaudio ./BGM3.mp3 volume to 50", NULL, 0, NULL);
			mciSendString("setaudio ./BGM4.mp3 volume to 50", NULL, 0, NULL);
			mciSendString("setaudio ./BGM5.mp3 volume to 50", NULL, 0, NULL);
			break;
		}
	}
	case 1: {
		mciSendString("open ./BGM1.mp3 repeat", 0, 0, 0);
		mciSendString("play ./BGM1.mp3 repeat", 0, 0, 0);
		break; }
	case 2: {
		mciSendString("open ./BGM2.mp3 repeat", 0, 0, 0);
		mciSendString("play ./BGM2.mp3 repeat", 0, 0, 0); }
		  break;
	case 3: {
		mciSendString("open ./BGM3.mp3 repeat", 0, 0, 0);
		mciSendString("play ./BGM3.mp3 repeat", 0, 0, 0); }
		  break;
	case 4: {
		mciSendString("open ./BGM4.mp3 repeat", 0, 0, 0);
		mciSendString("play ./BGM4.mp3 repeat", 0, 0, 0); }
		  break;
	case 5: {
		mciSendString("open ./BGM5.mp3 repeat", 0, 0, 0);
		mciSendString("play ./BGM5.mp3 repeat", 0, 0, 0); }
		  break;

	  defalut:
		  break;
	}

	if (music % 2 == 0)
	{
		setfillcolor(WHITE);
		fillcircle(200, 230, 20);
	}
	else
	{
		setfillcolor(GREEN);
		fillcircle(200, 230, 20);
	}
}

