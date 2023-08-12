#include "Base.h"
#include "dao.h"
#include "service.h"
#include "utils.h"
#include "view.h"
int isWinInCampainMode(int level)
{
	extern vector<int> lasttime;//最后一波怪时间出现数组
	lasttime.push_back(400);//第一关
	if (myaircraft.getHP() <= 0)
		return 0;
	else if (timer >= lasttime[level - 1])
	{
		//每关最后一波出现的时间  构成一个数组lastime


		if (enemyPlanes.size() == 0)
			return 1;
	}
	else
		return 2;


}

int isWinInEndlessMode()

{
	if (myaircraft.getHP() <= 0)
		return 1;
	else
		return 0;
};
void changePlace()
{
	list<Aircraft>::iterator it = ouraircraft.begin();
	for (it; it != ouraircraft.end(); it++)
	{

		if (direction == 'B')
		{

		}

		else if (direction == 'W')
		{
			if (it->getY()-it->getSpeedY() > 0)
			{
				it->setY(it->getY() - it->getSpeedY());
			}
		}
		else if (direction == 'A')
		{
			if (it->getX() + it->getWid() / 2-it->getSpeedX() > 0)
			{
				it->setX(it->getX() - it->getSpeedX());
			}
		}
		else if (direction == 'S')
		{
			if (it->getY() + it->getLen()+it->getSpeedY() < 736)
				it->setY(it->getY() + it->getSpeedY());
		}
		else if (direction == 'D')
		{
			if (it->getX() + it->getWid()+it->getSpeedX() < 414)
			{
				it->setX(it->getX() + it->getSpeedX());
			}
		}
	}


	list<Bullet>::iterator it1 = m_bullets.begin();
	while ( it1 != m_bullets.end())
	{
		it1->setY(it1->getY() + it1->getSpeedY());
		if (it1->getY() < 0)
		{
			it1 = m_bullets.erase(it1);
		}
		else{
			it1++;
		}
	}

	list<Bullet>::iterator it2 = e_bullets.begin();
	while( it2 != e_bullets.end())
	{
		if (it2->getAngle() == 0)
		{
			it2->setY(it2->getY() + it2->getSpeedY());
		}
		else
		{
			it2->setSpeedX(it2->getSpeed() * sin(it2->getAngle()));
			it2->setSpeedY(it2->getSpeed() * cos(it2->getAngle()));
			it2->setX(it2->getX() + it2->getSpeedX());
			it2->setY(it2->getY() + it2->getSpeedY());
		}

		if (it2->getY() > 736)
		{
			it2 = e_bullets.erase(it2);
		}
		else {
			it2++;
		}
	}

	list<ActualWarProps>::iterator it3 = actual_war_props.begin();
while( it3 != actual_war_props.end())
	{
		//it3->setX(it3->getX() + it3->getSpeedX());
		it3->setY(it3->getY() + it3->getSpeedY());


		if (it3->getY() > 736)
		{
			it3 = actual_war_props.erase(it3);
		}
		else {
			it3++;
		}

	}

	int add = 0;
	list<EnemyPlane>::iterator it4 = enemyPlanes.begin();

	while( it4 != enemyPlanes.end())
	{
		if (it4->getId() != 4)
		{
			it4->setY(it4->getY() + it4->getSpeedY());
		}
		else
		{

			if (it4->getX() == 0)  add = 0;

			if (it4->getX() == 414)  add = 1;

			switch (add)
			{
			case  0:
				it4->setX(it4->getX() - 10);
				break;
			case  1:
				it4->setX(it4->getX() + 10);
				break;

			}

		}
		if (it4->getY() > 736)
		{
			it4 = enemyPlanes.erase(it4);
		}
		else {
			it4++;
		}
	}

}


bool usingProp(int id)
{
	if (id == 1)//核弹
	{

		enemyPlanes.clear();
		e_bullets.clear();
		return 1;
	}

	if (id == 2)//时间减速器
	{



		temp_time[0] = timer;//重置时间
		if (flag[0] == 0)//持续时间中只做一次
		{
			for (list<EnemyPlane>::iterator it = enemyPlanes.begin(); it != enemyPlanes.end(); it++)
			{
				int temp = (*it).getSpeedY();
				(*it).setSpeedY(temp / 2);
			}
			for (list<Bullet>::iterator it = e_bullets.begin(); it != e_bullets.end(); it++)
			{
				int temp = (*it).getSpeedY();
				(*it).setSpeedY(temp / 2);
			}
			flag[0]++;

		}

	}


	if (id == 3)//复活卷轴
	{
		static int count = 0;//记录复活次数
		if (myaircraft.getHP() <= 0)
		{
			if (coin >= pow(2, count) * 50)//判断钱够不够
			{
				myaircraft.setHP(myaircraft.getMaxHP());
				coin = coin - 2 ^ count * 50;
				count++;
				return 1;
			}
		}
		else {
			return 0;
		}

	}



	if (id == 5)//护盾
	{
		myaircraft.setShield(1);
		return 1;
	}
	if (id == 6)//双倍子弹
	{

		if (flag[1] == 0)//外面弄了个全局变量flag初值为0，实现双倍子弹无法叠加
		{
			int attackspeed = myaircraft.getSpeedY();
			myaircraft.setSpeedY(attackspeed / 2);
			flag[1]++;
			return 1;
		}

		return 0;


	}

	if (id == 7)//翻转
	{
		temp_time[1] = timer;//持续10s
		return 1;
	}

	if (id == 8)//分身幻影
	{//重新定义一个对象？幻影和玩家同操作，只是x不同，
		if (flag[3] == 0)//实现只能搞一个幻影
		{
			Aircraft shadow(myaircraft);
			int x = myaircraft.getX() + 10 + myaircraft.getWid();
			shadow.setX(x);
			shadow.setHP(myaircraft.getMaxHP());
			ouraircraft.push_back(shadow);//插入幻影
			flag[3]++;
			return 1;
		}
		return 0;
	}
	if (id == 9)//医疗包
	{
		int hp = myaircraft.getHP();
		int MAXHP = myaircraft.getMaxHP();
		if (hp >= 0.7 * MAXHP)//恢复30%血量
		{
			myaircraft.setHP(MAXHP);
		}
		else
		{
			myaircraft.setHP(hp + 0.3 * MAXHP);
		}

		return 1;
	}

	if (id == 10) //动力失效
	{
		temp_time[2] = timer;

		if (flag[2] == 0)
		{
			for (list<Aircraft>::iterator it = ouraircraft.begin(); it != ouraircraft.end(); it++)
			{
				int temp = (*it).getSpeedY();
				(*it).setSpeedY(temp / 2);
			}
			flag[2]++;
		}
		return 1;

	}

	if (id == 11)//盲盒
	{
		srand((unsigned int)time(NULL));
		int id_3 = rand() % 6 + 5;
		usingProp(id_3);
	}

}


void init() {
	Aircraft myaircraft(172, 656);
	ouraircraft.clear();
	ouraircraft.push_back(myaircraft);
	score = 0; coin = 0; num = 0; timer = 0;
	actual_war_props.clear();
	direction = 'B';
	enemyPlanes.clear();
	m_bullets.clear();
	e_bullets.clear();
}


bool update(int type) {
	int price = 0;
	int maxLevel = 10;
	int l = 0;//当前等级
	switch (type) {
	case 1: // 火力增强升级

		// 判断金额是否足够购买或升级装备
		l = myaircraft.getAttackLevel();
		price = 1000 + (l-1) * 300;
		if (coin >= price && l < maxLevel) {
			myaircraft.setAttackLevel(l + 1);
			coin -= price;
			return true;
		}
		else {

			return false;
		}


	case 2: // 生命值增加升级

		// 判断金额是否足够购买或升级装备
		l = myaircraft.getHPLevel();
		price = 1500 + (l-1) * 400;
		if (coin >= price && l < maxLevel) {
			myaircraft.setHPLevel(l + 1);
			coin -= price;
			return true;
		}
		else {

			return false;
		}


	case 3: // 防御加强升级

		// 判断金额是否足够购买或升级装备
		l = myaircraft.getDefenseLevel();
		price = 1000 + (l-1) * 300;
		if (coin >= price && l < maxLevel) {
			myaircraft.setDefenseLevel(l + 1);
			coin -= price;
			return true;
		}
		else {

			return false;
		}


	default:
		return false;
	}


}


void isCrash() {
	//碰撞判断
	/*1.子弹碰撞我方飞机*/
	list<Bullet>::iterator it = e_bullets.begin();//自定义迭代器遍历容器
	list<Aircraft >::iterator it_o = ouraircraft.begin();
while( it != e_bullets.end())
	{
		//判断子弹是否与我方飞机碰撞
		bool bulletRemoved = false; // 标志，用于检查子弹是否被删除
		for (; it_o != ouraircraft.end(); it_o++)
		{
			if (it == e_bullets.end()) { break; }
			if (abs(it->getX() + it->getWid() / 2 - it_o->getWid() / 2 - it_o->getX()) < (it->getWid() + (*it_o).getWid()) / 2 && (abs(it->getY() + it->getLen() / 2 - (*it_o).getLen() / 2 - (*it_o).getY()) < (it->getLen() + (*it_o).getLen()) / 2))//判断子弹是否和我方飞机碰撞
			{
				if ((*it_o).getShield() == 1) {
					(*it_o).setShield(0);
				}
				else {
					(*it_o).setHP((*it_o).getHP() - it->getAttack()); //扣除对应子弹伤害的量
				}
				it = e_bullets.erase(it);
				bulletRemoved = true;
			}
		}
			if (bulletRemoved)
			{
				continue;
			}
			it++;
	}
	/*敌方飞机碰撞我方飞机*/
	list<EnemyPlane>::iterator it_e_Plane = enemyPlanes.begin();
	while (it_e_Plane != enemyPlanes.end())
	{
		bool enemyPlanesRemoved = false;
		for (it_o=ouraircraft.begin(); it_o != ouraircraft.end(); it_o++)
		{
			if (it_e_Plane == enemyPlanes.end()) { break; }
			//判断敌方飞机是否存在&&敌方飞机是否与我方飞机碰撞
			if (!it_e_Plane->isDead() && (abs(it_e_Plane->getX() + it_e_Plane->getWid() / 2 - (*it_o).getWid() / 2 - (*it_o).getX()) < (it_e_Plane->getWid() + (*it_o).getWid()) / 2) && (abs(it_e_Plane->getY() + it_e_Plane->getLen() / 2 - (*it_o).getLen() / 2 - (*it_o).getY()) < (it_e_Plane->getLen() + (*it_o).getLen() / 2)))//判断敌方飞机是否和我方飞机碰撞
			{
				if (it_e_Plane->getId() == 1)
				{
					num += 30;
				}
				if (it_e_Plane->getId() == 2)
				{
					num += 50;
				}
				if (it_e_Plane->getId() == 3)
				{
					num += 100;
				}
				if (it_e_Plane->getId() == 4)
				{
					num += 500;
				}//碰撞完得分对应的分数
				if ((*it_o).getShield() == 1) {
					(*it_o).setShield(0);
				}
				else {
					(*it_o).setHP((*it_o).getHP() - it_e_Plane->getAttack());//扣除对应飞机伤害的血量
				}
				it_e_Plane = enemyPlanes.erase(it_e_Plane);
				enemyPlanesRemoved = true;
			}
		}
		if (!enemyPlanesRemoved)
		{
			
		it_e_Plane++;
		}
	}
	/*子弹碰撞敌方飞机*/
	list<Bullet>::iterator it_Bullet = m_bullets.begin();//自定义迭代器遍历容器
	while (it_Bullet != m_bullets.end())
	{
		srand(time(NULL));//设置一个随机数种子
		bool bulletRemoved = false; // 标志，用于检查子弹是否被删除

		list<EnemyPlane>::iterator it_Plane = enemyPlanes.begin();
		while (it_Plane != enemyPlanes.end())
		{
			if (it_Bullet == m_bullets.end()) {
				break;
			}
			bool enemyPlanesRemoved = false;

			if (!it_Plane->isDead() && (abs(it_Bullet->getX() + it_Bullet->getWid() / 2 - it_Plane->getWid() / 2 - it_Plane->getX()) < (it_Bullet->getWid() + it_Plane->getWid()) / 2) && (abs(it_Bullet->getY() + it_Bullet->getLen() / 2 - it_Plane->getLen() / 2 - it_Plane->getY()) < (it_Bullet->getLen() + it_Plane->getLen()) / 2))//判断敌方飞机是否和我方飞机碰撞
			{
				it_Plane->setHP(it_Plane->getHP() - it_Bullet->getAttack());//扣除对应飞机伤害的量
				it_Bullet = m_bullets.erase(it_Bullet);

				bulletRemoved = true;
			}
			int a = rand() % 101;//产生一个0到100的数
			if (it_Plane->getHP() <= 0)//若敌机被击落，则有概率生成道具并且从容器中删掉
			{
				if (it_Plane->getId() == 1)
				{
					num += 30;
				}
				if (it_Plane->getId() == 2)
				{
					num += 50;
				}
				if (it_Plane->getId() == 3)
				{
					num += 100;
				}
				if (it_Plane->getId() == 4)
				{
					num += 500;
				}//计算分数

				if (a >= 0 && a < 5 && it_Plane->getId() == 1)//%5的概率
				{
					srand(time(NULL));//设置一个随机数种子
					int b = rand() % 8;//随机生成一个1-7的数字

					if (b == 1)
					{
						Shield  shield(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(shield);//生成护盾道具；
					}

					if (b == 2)
					{
						DoubleBullet  doubleBullet(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(doubleBullet);//生成双倍子弹道具；
					}

					if (b == 3)
					{
						KeysReversal keysReversal(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(keysReversal);//生成键位反转道具
					}


					if (b == 4)
					{
						Doppelganger doppelganger(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(doppelganger);//生成分身幻影道具
					}

					if (b == 5)
					{
						AidKit aidKit(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(aidKit);//生成医疗包道具
					}

					if (b == 6)
					{
						PowerFailure decelerator(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(decelerator);//生成动力失效道具；
					}

					if (b == 7)
					{
						RandProp randprops(it_Plane->getX(), it_Plane->getY(), 0);
						actual_war_props.push_back(randprops);//生成随机道具
					}

				}

				else if (a >= 5 && a < 15 && it_Plane->getId() == 2)//%10的概率
				{
					srand(time(NULL));//设置一个随机数种子
					int b = rand() % 8;//随机生成一个1-7的数字

					if (b == 1)
					{
						Shield  shield(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(shield);//生成护盾道具；
					}

					if (b == 2)
					{
						DoubleBullet  doubleBullet(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(doubleBullet);//生成双倍子弹道具；
					}

					if (b == 3)
					{
						KeysReversal keysReversal(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(keysReversal);//生成键位反转道具
					}


					if (b == 4)
					{
						Doppelganger doppelganger(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(doppelganger);//生成分身幻影道具
					}

					if (b == 5)
					{
						AidKit aidKit(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(aidKit);//生成医疗包道具
					}

					if (b == 6)
					{
						PowerFailure decelerator(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(decelerator);//生成动力失效道具；
					}

					if (b == 7)
					{
						RandProp randprops(it_Plane->getX(), it_Plane->getY(), 0);
						actual_war_props.push_back(randprops);//生成随机道具
					}

				}
				if (a >= 15 && a < 45 && it_Plane->getId() == 3)//%30的概率
				{
					srand(time(NULL));//设置一个随机数种子
					int b = rand() % 8;//随机生成一个1-7的数字

					if (b == 1)
					{
						Shield  shield(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(shield);//生成护盾道具；
					}

					if (b == 2)
					{
						DoubleBullet  doubleBullet(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(doubleBullet);//生成双倍子弹道具；
					}

					if (b == 3)
					{
						KeysReversal keysReversal(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(keysReversal);//生成键位反转道具
					}


					if (b == 4)
					{
						Doppelganger doppelganger(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(doppelganger);//生成分身幻影道具
					}

					if (b == 5)
					{
						AidKit aidKit(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(aidKit);//生成医疗包道具
					}

					if (b == 6)
					{
						PowerFailure decelerator(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(decelerator);//生成动力失效道具；
					}

					if (b == 7)
					{
						RandProp randprops(it_Plane->getX(), it_Plane->getY(), 0);
						actual_war_props.push_back(randprops);//生成随机道具
					}

				}

				if (it_Plane->getId() == 4)
				{
					srand(time(NULL));//设置一个随机数种子
					int b = rand() % 8;//随机生成一个1-7的数字

					if (b == 1)
					{
						Shield  shield(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(shield);//生成护盾道具；
					}

					if (b == 2)
					{
						DoubleBullet  doubleBullet(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(doubleBullet);//生成双倍子弹道具；
					}

					if (b == 3)
					{
						KeysReversal keysReversal(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(keysReversal);//生成键位反转道具
					}


					if (b == 4)
					{
						Doppelganger doppelganger(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(doppelganger);//生成分身幻影道具
					}

					if (b == 5)
					{
						AidKit aidKit(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(aidKit);//生成医疗包道具
					}

					if (b == 6)
					{
						PowerFailure decelerator(it_Plane->getX(), it_Plane->getY());
						actual_war_props.push_back(decelerator);//生成动力失效道具；
					}

					if (b == 7)
					{
						RandProp randprops(it_Plane->getX(), it_Plane->getY(), 0);
						actual_war_props.push_back(randprops);//生成随机道具
					}
				}
				it_Plane = enemyPlanes.erase(it_Plane);
				enemyPlanesRemoved = true;

			}
			if (!enemyPlanesRemoved)
			{
				it_Plane++;
			}

		}

			if (!bulletRemoved) {
			it_Bullet++;
			}
	}

	/*若我方触碰道具则*/
	list<ActualWarProps>::iterator it_props = actual_war_props.begin();
	while (it_props != actual_war_props.end())
	{
		bool actual_war_propsRemoved = false;
		for (it_o=ouraircraft.begin(); it_o != ouraircraft.end(); it_o++)
		{
			if (it_props == actual_war_props.end()) { break; }
			if ((abs(it_props->getX() + it_props->getWid() / 2 - (*it_o).getWid() / 2 - (*it_o).getX()) < (it_props->getWid() + (*it_o).getWid()) / 2) && (abs(it_props->getY() + it_props->getLen() / 2 - (*it_o).getLen() / 2 - (*it_o).getY()) < (it_props->getLen() + (*it_o).getLen() / 2)))//判断敌方飞机是否和我方飞机碰撞
			{
				usingProp(it_props->getNum());
				it_props = actual_war_props.erase(it_props);
				actual_war_propsRemoved = true;
			}
		}
			if (actual_war_propsRemoved)
			{
				continue;
			}
			it_props++;
	}
}
bool purchase(int type) {
	int price = 0;

	switch (type) {
	case 1: // 核弹
		price = 500;
		if (coin < price)
			return false;

		else
			nuclear_bomb.purchase();
		coin -= price;
		return true;



	case 2: // 时间减速器
		price = 180;
		if (coin < price)
			return false;

		else
			decelerator.purchase();
		coin -= price;
		return true;

	case 3: // 复活卷轴
		price = 150;
		if (coin < price)
			return false;

		else
			resurrection_scroll.purchase();
		coin -= price;
		return true;

	case 4: // 抽卡
		price = 260;
		if (coin < price)
			return false;

		else {
			srand((unsigned int)time(NULL));
			// 生成随机数
			int randomNumber = rand() % 100;
			if (randomNumber < 33)
				nuclear_bomb.purchase();
			else if (randomNumber >= 33 && randomNumber < 66)
				decelerator.purchase();
			else
				resurrection_scroll.purchase();
		}

		coin -= price;
		return true;

	default:
		return false;
	}
}


void shoot()
{
	list<Aircraft>::iterator it = ouraircraft.begin();
	for (it; it != ouraircraft.end(); it++)
	{
		if (it->ifCooldown())
		{
			MyBullet mybullet(it->getX() + it->getWid() / 2, it->getY());
			m_bullets.push_back(mybullet);
		}

	}


	list<EnemyPlane>::iterator it5 = enemyPlanes.begin();
	for (it5; it5 != enemyPlanes.end(); it5++)
	{
		if (it5->ifCooldown())
		{
			if (it5->getId() == 2) {
				MiddleBullet middlebullet(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen());

				e_bullets.push_back(middlebullet);
			}
			else if (it5->getId() == 3)
			{
				BigBullet bigbullet(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen());

				e_bullets.push_back(bigbullet);
			}
			else if (it5->getId() == 4)
			{
				BossBullet bossbullet1(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen(), 0);
				BossBullet bossbullet2(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen(), 20);
				BossBullet bossbullet3(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen(), 40);
				BossBullet bossbullet4(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen(), 60);
				BossBullet bossbullet5(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen(), 80);
				BossBullet bossbullet6(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen(), 100);
				BossBullet bossbullet7(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen(), 120);
				BossBullet bossbullet8(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen(), 140);
				BossBullet bossbullet9(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen(), 160);
				BossBullet bossbullet10(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen(), 180);
				BossBullet bossbullet11(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen(), 200);
				BossBullet bossbullet12(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen(), 220);
				BossBullet bossbullet13(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen(), 240);
				BossBullet bossbullet14(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen(), 260);
				BossBullet bossbullet15(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen(), 280);
				BossBullet bossbullet16(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen(), 300);
				BossBullet bossbullet17(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen(), 320);
				BossBullet bossbullet18(it5->getX() + it5->getWid() / 2, it5->getY() + it5->getLen(), 340);
				e_bullets.push_back(bossbullet1);
				e_bullets.push_back(bossbullet2);
				e_bullets.push_back(bossbullet3);
				e_bullets.push_back(bossbullet4);
				e_bullets.push_back(bossbullet5);
				e_bullets.push_back(bossbullet6);
				e_bullets.push_back(bossbullet7);
				e_bullets.push_back(bossbullet8);
				e_bullets.push_back(bossbullet9);
				e_bullets.push_back(bossbullet10);
				e_bullets.push_back(bossbullet11);
				e_bullets.push_back(bossbullet12);
				e_bullets.push_back(bossbullet13);
				e_bullets.push_back(bossbullet14);
				e_bullets.push_back(bossbullet15);
				e_bullets.push_back(bossbullet16);
				e_bullets.push_back(bossbullet17);
				e_bullets.push_back(bossbullet18);
			}
		}
	}
}

void addPlaneInCampaignModeView(int level)
{
	if (level == 1)
	{
		if (timer == 50)
		{
			createplane(1);
		}
		if (timer == 100)
		{
			createplane(1);
		}
		if (timer == 150)
		{
			createplane(1);
			createplane(1);
		}
		if (timer == 200)
		{
			createplane(1);
			createplane(1);
		}
		if (timer == 250)
		{
			createplane(1);
			createplane(1);
			createplane(1);
		}
		if (timer == 300)
		{
			createplane(1);
			createplane(1);
			createplane(1);
		}
		if (timer == 350)
		{
			createplane(1);
			createplane(1);
			createplane(2);
		}
		if (timer == 400)
		{
			createplane(1);
			createplane(1);
			createplane(2);
		}


	}

}

void createplane(int x)
{
	if (x == 1)//小飞机
	{
		int x = 0;
		int y = 0;
		srand((unsigned int)time(NULL));

		SmallEnemy enemyplane(x, y);
		x = rand() % (414 - enemyplane.getWid());
		enemyplane.setX(x);
		enemyPlanes.push_back(enemyplane);
	}
	else if (x == 2)//中飞机
	{
		int x = 0;
		int y = 0;
		srand((unsigned int)time(NULL));

		MediumEnemy enemyplane(x, y);
		x = rand() % (414 - enemyplane.getWid());
		enemyplane.setX(x);
		enemyPlanes.push_back(enemyplane);

	}
}

void overturn()
{
	if (timer <= temp_time[1] + 100)
	{
		if (direction == 'w')
			direction = 's';
		if (direction == 's')
			direction = 'w';
		if (direction == 'a')
			direction = 'd';
		if (direction == 'd')
			direction = 'a';
	}
}

void restore()
{
	if (timer >= temp_time[0] + 100 && flag[0] == 1)//持续10s恢复
	{
		for (list<EnemyPlane>::iterator it = enemyPlanes.begin(); it != enemyPlanes.end(); it++)
		{
			int temp = (*it).getSpeedY();
			(*it).setSpeedY(temp * 2);
		}
		for (list<Bullet>::iterator it = m_bullets.begin(); it != m_bullets.end(); it++)
		{
			int temp = (*it).getSpeedY();
			(*it).setSpeedY(temp * 2);
		}
		flag[0]--;
	}

	if (timer >= temp_time[2] + 100 && flag[2] == 1)
	{
		for (list<Aircraft>::iterator it = ouraircraft.begin(); it != ouraircraft.end(); it++)
		{
			int temp = (*it).getSpeedY();
			(*it).setSpeedY(temp * 2);
		}
		flag[2]--;
	}


}

void addPlaneInEndlessMode()
{
	srand((unsigned)time(NULL));
	int randomNum = rand() % 1000 + 1; // 生成1~1000的随机数
	int Rand = rand() % 414 + 1; // 生成0~414的随机数
	double probability = 0;

	// 计算不同类型敌机在不同阶段的生成概率
	if (timer <= 600) {
		// 前期
		randomNum = rand() % 1000 + 1;

		probability = timer / 600.0 * 1000; // 小飞机
		if (randomNum <= probability) {
			Rand = rand() % 414 + 1;
			SmallEnemy newPlane(Rand - 60, 0);
			enemyPlanes.push_back(newPlane);
		}

		probability = timer / 3000.0 * 1000; // 中飞机
		if (randomNum <= probability) {
			Rand = rand() % 414 + 1;
			MediumEnemy newPlane(Rand - 60, 0);
			enemyPlanes.push_back(newPlane);
		}
	}

	else if (timer <= 1200) {
		// 中期

		SmallEnemy newPlane(Rand - 60, 0);
		enemyPlanes.push_back(newPlane);
		randomNum = rand() % 1000 + 1;
		probability = timer / 2000.0 * 1000; // 中飞机
		if (randomNum <= probability) {
			Rand = rand() % 414 + 1;
			MediumEnemy newPlane(Rand - 60, 0);
			enemyPlanes.push_back(newPlane);
		}

		probability = timer / 8000.0 * 1000; // 大飞机
		if (randomNum <= probability) {
			Rand = rand() % 414 + 1;
			BigEnemy newPlane(Rand - 60, 0);
			enemyPlanes.push_back(newPlane);
		}
	}
	else {
		// 后期
		SmallEnemy newPlane(Rand - 60, 0);
		enemyPlanes.push_back(newPlane);
		Rand = rand() % 414 + 1;
		SmallEnemy newPlane2(Rand - 60, 0);
		enemyPlanes.push_back(newPlane2);

		Rand = rand() % 414 + 1;
		MediumEnemy newPlane3(Rand - 60, 0);
		enemyPlanes.push_back(newPlane);

		probability = timer / 10000.0 * 1000; // 大飞机
		if (randomNum <= probability) {
			Rand = rand() % 414 + 1;
			BigEnemy newPlane(Rand - 60, 0);
			enemyPlanes.push_back(newPlane);
		}

		probability = timer / 30000.0 * 1000; // BOSSA
		if (randomNum <= probability) {
			Rand = rand() % 414 + 1;
			BossA newPlane(Rand - 60, 0);
			enemyPlanes.push_back(newPlane);
		}

		probability = timer / 30000.0 * 1000;// BOSSB

		if (randomNum <= probability) {
			Rand = rand() % 414 + 1;
			BossB newPlane(Rand - 60, 0);
			enemyPlanes.push_back(newPlane);
		}
	}
}

