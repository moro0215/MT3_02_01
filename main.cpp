#include <Novice.h>
#include <function.h>
#include <imgui.h>

const char kWindowTitle[] = "GC2A_11_モロズミ_サトシ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	const int kWindowWidth = 1280;
	const int kWindowHeight = 720;
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Vector3 cameraTranslate{ 0.0f,1.9f,-6.49f };
	Vector3 cameraRotate{ 0.26f,0.0f,0.0f };

	Vector3 rotate{};
	Vector3 translate{};

	Sphere sphere1{
		{0,0,0},
		0.5f,
	};
	Sphere sphere2{
		{1,0,0.5f},
		0.5f,
	};

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

		Matrix4x4 cameraMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraTranslate);
		Matrix4x4 viewMatrix = Inverse(cameraMatrix);
		Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.0f);
		//WVPマトリックスを作る
		Matrix4x4 worldViewProjectionMatrix = Multiply(viewMatrix, projectionMatrix);

		Matrix4x4 viewportMatrix = MakeViewportMatrix(0, 0, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);
		
		DrawGrid(worldViewProjectionMatrix, viewportMatrix);

		if (IsCollisionSphereSphere(sphere1, sphere2)== true) {
			DrawSphere(sphere2, worldViewProjectionMatrix, viewportMatrix, RED);
		}
		else {
			DrawSphere(sphere2, worldViewProjectionMatrix, viewportMatrix, WHITE);
		}

		DrawSphere(sphere1, worldViewProjectionMatrix, viewportMatrix, WHITE);
		

		ImGui::Begin("Window");
		ImGui::DragFloat3("CameraTranslate", &cameraTranslate.x, 0.01f);
		ImGui::DragFloat3("CameraRotate", &cameraRotate.x, 0.01f);
		ImGui::DragFloat3("Sphere1Center", &sphere1.center.x, 0.01f);
		ImGui::DragFloat("Sphere1Radius", &sphere1.radius, 0.01f);
		ImGui::DragFloat3("Sphere2Center", &sphere2.center.x, 0.01f);
		ImGui::DragFloat("Sphere2Radius", &sphere2.radius, 0.01f);
		ImGui::End();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///


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
	return 0;
}