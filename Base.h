#pragma once
#pragma warning(disable:4996)
#include<cstdio>
#include <list>
#include <iostream>
#include <ctime>
#include<windows.h>
#include<Mmsystem.h>
#include<vector>
#include<easyx.h>
#include <fstream>
#include<iomanip>
#include<sstream>
#include <graphics.h>
#include<conio.h>
#pragma comment(lib,"winmm.lib")

using namespace std;
// 本文件负责人：漫勘


//----------------------类定义-------------------------

class GameObject {
public:
	bool operator==(const GameObject& other) const { return(m_x == other.m_x && m_y == other.m_y); }
	GameObject(int x, int y, int len, int wid);
	~GameObject() = default;
	GameObject(const GameObject& other) = default;
	//GameObject(GameObject&& other) = delete;
	//GameObject& operator=(const GameObject& other) = delete;
	//GameObject& operator=(GameObject&& other) = delete;
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();
	void setLen(int len);
	int getLen();
	void setWid(int wid);
	int getWid();
	void setSpeed(int speed);
	int getSpeed();
	void setSpeedX(int speedx);
	int getSpeedX();
	void setSpeedY(int speedy);
	int getSpeedY();
	void setNum(int num);
	int getNum();
	void setId(int id);
	int getId();
	void setAttack(int attack);
	int getAttack();
protected:
	int m_x;
	int m_y;
	int m_len;
	int m_wid;
	int m_speed;
	int m_speedx;
	int m_speedy;
	int m_num;
	int m_id;
	int m_attack;
	int m_cd;
};
//己方的飞机
class Aircraft :public GameObject {
protected:
	int m_hp;//血量
	//int m_attack;//撞击后对玩家造成的伤害
	int m_maxhp;
	bool m_shield;
	int attack_level;
	int hp_level;
	int defense_level;
	int attack_speed;
	int cd_timer;
public:
	bool operator==(const Aircraft& other) const { return(m_x == other.m_x && m_y == other.m_y); }

	Aircraft(int x, int y);
	void setMaxHP(int maxhp);
	int getMaxHP();
	void setHP(int hp);
	int getHP();
	void setAttackLevel(int attackLevel);
	int getAttackLevel();
	void setHPLevel(int hpLevel);
	int getHPLevel();
	void setDefenseLevel(int defenseLevel);
	int getDefenseLevel();
	void setShield(bool shield);
	int getShield();
	void setAttackSpeed(int attackspeed);
	int getAttackSpeed();
	bool isDead();
	bool ifCooldown();
};



//敌机类
class EnemyPlane : public GameObject {
protected:
	int m_hp;//血量
	int m_wid;
	int m_len;
	int attack_speed;
	int cd_timer;
public:
	bool operator==(const EnemyPlane& other) const { return(m_x == other.m_x && m_y == other.m_y); }

	EnemyPlane(int x, int y);
	void setHP(int hp);
	int getHP();
	bool isDead();
	virtual void func() {}//特殊技能
	bool ifCooldown();
};

class SmallEnemy :public EnemyPlane {
public:
	SmallEnemy(int x, int y);
};

class MediumEnemy :public EnemyPlane {
public:
	MediumEnemy(int x, int y);
};

class BigEnemy :public EnemyPlane {
public:
	BigEnemy(int x, int y);
};

class BossA :public EnemyPlane {
public:
	BossA(int x, int y);
	virtual void func() override;//特殊技能
};
class BossB :public EnemyPlane {
public:
	BossB(int x, int y);
	//virtual void func() override;//特殊技能
};

//道具类
class ShopProps : public GameObject
{
protected:
	int  m_id;//当前已有数量
public:
	ShopProps(int x, int y);
	void purchase();
	void usage();
};

class ActualWarProps : public GameObject
{
protected:
	int m_speed, m_id;
public:
	ActualWarProps(int x, int y);
};

class RandProp :public ActualWarProps {
	double m_angle;
public:
	RandProp(int x, int y, double angle);
	void setAngle(double angle);
	double getAngle();
};

class Shield :public ActualWarProps {
public:
	Shield(int x, int y);
	//virtual void func() override;
};

class DoubleBullet :public ActualWarProps {
public:
	DoubleBullet(int x, int y);
	//virtual void func() override;

};

class  KeysReversal :public ActualWarProps {
public:
	KeysReversal(int x, int y);
	//virtual void func() override;

};

class Doppelganger :public ActualWarProps {//分身
public:
	Doppelganger(int x, int y);
	//virtual void func() override;

};

class AidKit :public ActualWarProps {
public:
	AidKit(int x, int y);
	//virtual void func() override;
};

class Decelerator :public  ShopProps {
public:
	Decelerator(int x, int y);
	//virtual void func() override;
};

class NuclearBomb :public ShopProps {
public:
	NuclearBomb(int x, int y);

	//virtual void func() override;

};

class ResurrectionScroll :public  ShopProps {
public:
	ResurrectionScroll(int x, int y);

	//virtual void func() override;

};

class PowerFailure :public ActualWarProps {
public:
	PowerFailure(int x, int y);
	//virtual void func() override;

};


class Bullet : public GameObject {
protected:
	double m_angle;
public:
	Bullet(int x, int y);
	void setAngle(double angle);
	double getAngle();
	//void func();
};

class MiddleBullet : public Bullet {
	double m_angle;
public:
	MiddleBullet(int x, int y);
};
class BigBullet : public Bullet {
	double m_angle;
public:
	BigBullet(int x, int y);
};
class BossBullet :public Bullet {
	double m_angle;
public:
	BossBullet(int x, int y, double angel);
};
class MyBullet :public Bullet {
	double m_angle;
public:
	MyBullet(int x, int y);
};



//--------------------游戏数据------------------------
extern int score, coin, num, timer, level_succeeded;//num表示击杀敌机数量，time表示游戏开始时间
extern int skinType;
extern int sign_in;
extern Aircraft myaircraft;
extern NuclearBomb nuclear_bomb;
extern Decelerator decelerator;
extern ResurrectionScroll resurrection_scroll;
extern int attackspeed;//攻速
extern int flag[4];//有些道具只能进行一次
extern int temp_time[3];//持续时间10s
extern vector<int> lasttime;//最后一波怪时间出现数组
extern Shield shield;
extern DoubleBullet doublebullet;
extern KeysReversal keysreversal;
extern Doppelganger doppelganger;//幻影
extern AidKit aidkit;

//用于游戏内存储
extern char direction;
extern list<Aircraft > ouraircraft;//我们飞机和幻影
extern list<EnemyPlane> enemyPlanes;
extern list<Bullet> m_bullets;
extern list<Bullet> e_bullets;
extern list<ShopProps> shop_props;
extern list<ActualWarProps> actual_war_props;



