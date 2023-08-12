#include "Base.h"
#include "dao.h"
#include "service.h"
#include "utils.h"
#include "view.h"


//--------------------游戏数据------------------------
int score, coin, num=0, timer, level_succeeded;//num表示击杀敌机数量，time表示游戏开始时间
int skinType=1;
int sign_in;
Aircraft myaircraft(172,656);
//Aircraft shadow(172,656);//幻影
NuclearBomb nuclear_bomb(0, 0);
Decelerator decelerator(0, 0);
ResurrectionScroll resurrection_scroll(0, 0);
int attackspeed = 4;//攻速
int flag[4] = { 0 };//有些道具只能进行一次
int temp_time[3];//持续时间10s
vector<int> lasttime;//最后一波怪时间出现数组
/*Shield shield;
DoubleBullet doublebullet;
KeysReversal keysreversal;
Doppelganger doppelganger;//幻影
AidKit aidkit;
*/

//用于游戏内存储
char direction = 0;
list<Aircraft> ouraircraft;//我们飞机和幻影
list<EnemyPlane> enemyPlanes;
list<Bullet> m_bullets;
list<Bullet> e_bullets;
list<ShopProps> shop_props;
list<ActualWarProps> actual_war_props;





int main(void) {
	initgraph(414, 736, EX_SHOWCONSOLE);
	gameData(true);
	menuView();
	return 0;
}


