#include "Base.h"


GameObject::GameObject(int x, int y, int len, int wid)
	:m_x(x), m_y(y), m_len(len), m_wid(wid) {
	m_speedx = 0;
	m_speedy = 0;
	m_num = 0;
	m_id = 0;
	m_attack = 0;
	m_cd = 0;
}
Aircraft::Aircraft(int x, int y)
	:GameObject(x, y, 80, 80) {
	cd_timer = 0;
	m_attack = 0;
	m_hp = 100;//ÑªÁ¿
	m_maxhp = 100;
	m_shield = 0;
	attack_level =0 ;
	hp_level = 0;
	defense_level = 0;
	attack_speed = 4;
	m_speedx = 40;
	m_speedy = 40;
}
EnemyPlane::EnemyPlane(int x, int y)
	: GameObject(x, y, 50, 50) {
	m_attack = 30;
	m_wid = 80;
	m_len = 80;
	attack_speed = 4;
}
SmallEnemy::SmallEnemy(int x, int y)
	:EnemyPlane(x, y) {
	m_wid = 50;
	m_speedy = 20;
	m_id = 1;
	m_hp = 30;
	m_len = 50;
}

MediumEnemy::MediumEnemy(int x, int y)
	:EnemyPlane(x, y) {
	m_wid = 80;
	m_hp = 50;
	m_id = 2;
	m_speedy = 20;
	cd_timer = 8;
	m_len = 80;
}
BigEnemy::BigEnemy(int x, int y)
	:EnemyPlane(x, y) {
	m_wid = 130;
	m_speedy = 20;
	m_id = 3;
	cd_timer = 8;
	m_hp = 100;
	m_len = 130;
}
BossA::BossA(int x, int y)
	:EnemyPlane(x, y) {
	m_wid = 180;
	m_len = 180;
	m_id = 4;
}
BossB::BossB(int x, int y)
	:EnemyPlane(x, y) {
	m_wid = 180;
	m_id = 5;
	m_len = 180;
}
ActualWarProps::ActualWarProps(int x, int y)
	: GameObject(x, y, 80, 80) {
	m_speed = 20;
	m_id = 0;
}
RandProp::RandProp(int x, int y, double angle)
	:ActualWarProps(x, y) {
	m_x = x;
	m_y = y;
	m_angle = angle;
	m_id = 11;
}
ShopProps::ShopProps(int x, int y)
	: GameObject(x, y, 80, 80) {
	m_id = 0;
}
Shield::Shield(int x, int y)
	: ActualWarProps(x, y) {
	m_id = 5;
}
DoubleBullet::DoubleBullet(int x, int y)
	: ActualWarProps(x, y) {
	m_id = 6;
}
KeysReversal::KeysReversal(int x, int y)
	: ActualWarProps(x, y) {
	m_id = 7;
}
Doppelganger::Doppelganger(int x, int y)
	: ActualWarProps(x, y) {
	m_id = 8;
}
AidKit::AidKit(int x, int y)
	:ActualWarProps(x, y) {
	m_id = 9;
}
Decelerator::Decelerator(int x, int y)
	: ShopProps(x, y) {

}
NuclearBomb::NuclearBomb(int x, int y)
	: ShopProps(x, y) {

}
ResurrectionScroll::ResurrectionScroll(int x, int y)
	: ShopProps(x, y) {

}
PowerFailure::PowerFailure(int x, int y)
	: ActualWarProps(x, y) {
	m_id = 10;
}

Bullet::Bullet(int x, int y)
	: GameObject(x, y, 20, 40) {
	m_attack = 20;
	m_angle = 0;
}

MiddleBullet::MiddleBullet(int x, int y)
	: Bullet(x, y) {
	m_attack = 10;
	m_speedy = 30;
	m_id = 2;
	m_angle = 0;
}
BigBullet::BigBullet(int x, int y)
	: Bullet(x, y) {
	m_attack = 20;
	m_speedy = 30;
	m_id = 3;
	m_angle = 0;
}
BossBullet::BossBullet(int x, int y, double angle)
	: Bullet(x, y) {
	m_angle = angle;
	m_attack = 30;
}
MyBullet::MyBullet(int x, int y)
	: Bullet(x, y) {
	m_attack = 10;
	m_speedy = -30;
	m_angle = 0;
}

void GameObject::setX(int x) {
	m_x = x;
}

void GameObject::setY(int y) {
	m_y = y;
}

int GameObject::getX() {
	return m_x;
}

int GameObject::getY() {
	return m_y;
}

void GameObject::setNum(int num) {
	m_num = num;
}
int GameObject::getNum() {
	return m_num;
}
void GameObject::setId(int id) {
	m_id = id;
}
int GameObject::getId() {
	return m_id;
}
void GameObject::setAttack(int attack) {
	m_attack = attack;
}
int GameObject::getAttack() {
	return m_attack;
}
void Aircraft::setHP(int hp) {
	m_hp = hp;
}
int Aircraft::getHP() {
	return m_hp;
}

void EnemyPlane::setHP(int hp) {
	m_hp = hp;
}
int EnemyPlane::getHP() {
	return m_hp;
}

bool Aircraft::isDead() {
	if (m_hp <= 0) {
		return true;
	}
	return false;
}

bool EnemyPlane::isDead() {
	if (m_hp <= 0) {
		return true;
	}
	return false;
}

void Aircraft::setShield(bool shield) {
	m_shield = shield;
}
int Aircraft::getShield() {
	return m_shield;
}


void GameObject::setLen(int len) {
	m_len = len;
}
int GameObject::getLen() {
	return m_len;
}
void GameObject::setWid(int wid) {
	m_wid = wid;
}
int GameObject::getWid() {
	return m_len;
}

void Aircraft::setAttackLevel(int attackLevel) {
	attack_level = attackLevel;
}
int Aircraft::getAttackLevel() {
	return attack_level;
}
void Aircraft::setHPLevel(int hpLevel) {
	hp_level = hpLevel;
}
int Aircraft::getHPLevel() {
	return hp_level;
}
void Aircraft::setDefenseLevel(int defenseLevel) {
	defense_level = defenseLevel;
}
int Aircraft::getDefenseLevel() {
	return defense_level;
}

void Aircraft::setMaxHP(int maxhp) {
	m_maxhp = maxhp;
}
int Aircraft::getMaxHP() {
	return m_maxhp;
}
void Aircraft::setAttackSpeed(int attackspeed) {
	attack_speed = attackspeed;
}
int Aircraft::getAttackSpeed() {
	return attack_speed;
}
void GameObject::setSpeedX(int speedx) {
	m_speedx = speedx;
}
int GameObject::getSpeedX() {
	return m_speedx;
}
void GameObject::setSpeedY(int speedy) {
	m_speedy = speedy;
}
int GameObject::getSpeedY() {
	return m_speedy;
}
void GameObject::setSpeed(int speed) {
	m_speed = speed;
}
int GameObject::getSpeed() {
	return m_speed;
}

void BossA::func() {

}

bool Aircraft::ifCooldown() {
	cd_timer++;
	if (cd_timer == attack_speed) {
		cd_timer = 0;
		return true;
	}
	return false;
}
bool EnemyPlane::ifCooldown() {
	cd_timer++;
	if (cd_timer == attack_speed) {
		cd_timer = 0;
		return true;
	}
	return false;
}


void ShopProps::purchase() {
	m_num++;
}
void ShopProps::usage() {
	m_num--;
}

void RandProp::setAngle(double angle) {
	m_angle = angle;
}
double RandProp::getAngle() {
	return m_angle;
}

void Bullet::setAngle(double angle) {
	m_angle = angle;
}
double Bullet::getAngle() {
	return m_angle;
}

