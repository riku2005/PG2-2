#pragma once
class Enemy
{
public:	// メンバ関数

	// コンストラクタ
	Enemy(int posX, int posY, int speedX);

	// 更新	
	void Update();

	// 描画
	void Draw();

	//ゲッター
	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetRadius() { return radius_; };
	//セッター
	void SetSpeedX(int speedX_);
	//void SetSpeedY(int speedY_);


private:	// メンバ変数
	int posX_;
	int posY_;
	int speedX_;
	//int speedY_;
	int radius_;
};