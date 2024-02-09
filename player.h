#pragma once
#include"Bullet.h"
class Player
{
public:	// メンバ関数

	// コンストラクタ
	Player(int posX, int posY, int speedX, int speedY);

	// 更新	
	void Update(char* keys,char* preKeys);

	// 描画
	void Draw();

	//ゲッター
	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetRadius() { return radius_; };
	int GetBulletPosX() { return bullet_->GetPosX(); };
	int GetBulletPosY() { return bullet_->GetPosY(); };
	//セッター
	void SetSpeedX(int speedX_);
	void SetSpeedY(int speedY_);


private:	// メンバ変数
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int radius_;
	Bullet* bullet_;
};