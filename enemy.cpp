﻿#include "enemy.h"
#include "Novice.h"

Enemy::Enemy(int posX, int posY, int speedX)
{
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	//speedY_ = speedY;
	radius_ = 40;
}

void Enemy::Update() {
	posX_ += speedX_;
	//posY_ += speedY_;

	if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
		speedX_ *= -1;
	}
	//if (posY_ - radius_ <= 0 || posY_ + radius_ >= 720) {
		//speedY_ *= -1;
	//}
}

void Enemy::Draw() {
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
}

void Enemy::SetSpeedX(int num1) {
	this->speedX_ *= num1;
}

