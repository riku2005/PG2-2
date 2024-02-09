#include <Novice.h>
#include <player.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "enemy.h"
#include "player.h"
#include "Bullet.h"
#define _USE_MATH_DEFINES

const char kWindowTitle[] = "GC1B_05_サクライ_リク";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;

enum Scene {
	TITLE,
	PLAY,
	RESULT
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	int gameScene = TITLE;
	int gameTimer = 900;
	int resetTimer = 900;
	bool enemyIsDead = false;
	int enemyDeadTimer = 0;

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Enemy* enemy = new Enemy(100, 150, -3);
	//Bullet* bullet = new Bullet(-100, -600, 5);
	Player* player = new Player(100, 650, 5, 5);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		//当たり判定宣言
		float distX = float(enemy->GetPosX() - player->GetBulletPosX());
		float distY = float(enemy->GetPosY() - player->GetBulletPosY());
		float dist = float((distX * distX) + (distY * distY));
		int radius = enemy->GetRadius() + player->GetRadius();

		switch (gameScene) {

		case TITLE:

			gameTimer = resetTimer;

			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				gameScene = PLAY;
			}
			break;

		case PLAY:

			enemy->Update();
			//bullet->Update();
			player->Update(keys, preKeys);

			gameTimer--;

			// エネミーと弾同士の当たり判定処理
			if (dist <= radius * radius) {
				enemyIsDead = true;
			}

			if (enemyIsDead == true) {
				enemyDeadTimer++;
			}

			if (enemyDeadTimer >= 90) {
				enemyIsDead = false;
				enemyDeadTimer = 0;
			}

			if (gameTimer == 0) {
				gameScene = RESULT;
			}

			break;

		case RESULT:
			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				gameScene = TITLE;
			}
			break;
		}

		

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (gameScene) {

		case TITLE:
			Novice::DrawBox(0, 0, kWindowWidth, kWindowHeight, 0.0f, BLACK, kFillModeSolid);
			Novice::ScreenPrintf(620, 360, "Push:SPACE");
			break;

		case PLAY:
			
			if (enemyIsDead == false) {
				enemy->Draw();
			}
		
			player->Draw();

			Novice::ScreenPrintf(0, 0, "%d", gameTimer);
			break;

		case RESULT:
			Novice::DrawBox(0, 0, kWindowWidth, kWindowHeight, 0.0f, BLACK, kFillModeSolid);
			Novice::ScreenPrintf(620, 360, "push:ENTER");
			break;

		}

		

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
