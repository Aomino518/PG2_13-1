#include <Novice.h>
#include "Object.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "EnemyA.h"
#include "EnemyB.h"

const char kWindowTitle[] = "LC1B_26_モリ_アオト_静的メンバ変数_確認課題	";

int Enemy::isAlive;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player;
	Enemy* enemies[2];
	for (int i = 0; i < 2; i++) {
		if (i < 1) {
			enemies[i] = new EnemyA;
		}
		else {
			enemies[i] = new EnemyB;
		}
	}

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

		player->Update(keys, preKeys);
		
		for (int i = 0; i < 2; i++) {
			enemies[i]->Update(player->bullet->GetPos(), player->bullet->GetRadius());
			enemies[i]->Reset(keys, preKeys);
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();
		for (int i = 0; i < 2; i++) {
			enemies[i]->Draw();
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

	// ライブラリの終了
	Novice::Finalize();
	
	for (int i = 0; i < 2; i++) {
		delete enemies[i];
	}

	delete player;
	return 0;
}
