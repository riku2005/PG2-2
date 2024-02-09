#pragma once
class Bullet
{
public:	// メンバ関数

	// コンストラクタ
	Bullet(int posX, int posY, int speedY);

	// 更新	
	void Update();

	// 描画
	void Draw();

	//ゲッター
	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetRadius() { return radius_; };
	bool GetIsShot() { return isShot_; };
	//セッター
	void SetPosX (int posX_);
	void SetPosY(int posY_);
	void SetSpeedY(int speedY_);
	void SetIsShot(bool isShot_);


private:	// メンバ変数
	int posX_;
	int posY_;
	int speedY_;
	int radius_;
	bool isShot_;
};