#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet(int posX, int posY, int speedY)
{
	posX_ = posX;
	posY_ = posY;
	speedY_ = speedY;
	radius_ = 20;
	isShot_ = false;
}

void Bullet::Update() {
	posY_ -= speedY_;
}

void Bullet::Draw() {
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, BLUE, kFillModeSolid);
}

void Bullet::SetPosX(int posX)
{
	this->posX_ = posX;
}

void Bullet::SetPosY(int posY)
{
	this->posY_ = posY;
}

void Bullet::SetSpeedY(int num2)
{
	this->speedY_ = num2;
}

void Bullet::SetIsShot(bool isShot)
{
	this->isShot_ = isShot;
}
