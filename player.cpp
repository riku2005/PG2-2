#include "player.h"
#include "Novice.h"

Player::Player(int posX, int posY, int speedX, int speedY)
{
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	speedY_ = speedY;
	radius_ = 30;
	bullet_ = new Bullet(-100,-100,5);
}

void Player::Update(char* keys,char* preKeys) {

	if (keys[DIK_W]) {
		posY_ -= speedY_;
	}
	if (keys[DIK_S]) {
		posY_ += speedY_;
	}
	if (keys[DIK_A]) {
		posX_ -= speedX_;
	}
	if (keys[DIK_D]) {
		posX_ += speedX_;
	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && !bullet_->GetIsShot()){
		bullet_->SetPosX(posX_);
		bullet_->SetPosY(posY_);
		bullet_->SetIsShot(true);
	}

	if (bullet_->GetPosY() <= -50) {
		bullet_->SetIsShot(false);
	}

	if (bullet_->GetIsShot() == true) {
		bullet_->Update();
	}

}

void Player::Draw() {
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	bullet_->Draw();
}

void Player::SetSpeedX(int num1) {
	this->speedX_ *= num1;
}

void Player::SetSpeedY(int num2)
{
	this->speedY_ = num2;
}