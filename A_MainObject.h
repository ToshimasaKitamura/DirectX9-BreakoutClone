#pragma once

class A_MainObject
{
public:
	explicit A_MainObject() = default;
	~A_MainObject() = default;

protected:
	//外枠の高さ / フレームの長さ + 1
	static constexpr int _outFrameVNum = 35;

	//外枠の幅 / フレームの長さ + 1
	static constexpr int _outFrameHNum = 46;

	//内枠の高さ / フレームの長さ + 1
	static constexpr int _inFrameVNum = 32;

	//内枠の幅 / フレームの長さ
	static constexpr int _inFrameHNum = 40;

	//フレームの太さ
	static constexpr int _frameThickness = 3;

	//フレームの長さ
	static constexpr int _frameLength = 14;

	//画面全体のフレーム幅
	static constexpr int _screenFrameSize = 40;

	//バーの初期x座標
	static constexpr float _barStartPosX = 320.0f;

	//バーのy軸
	static constexpr float _barY = 430.0f;

	//バーの移動スピード
	static constexpr float _barSpeed = 8.0f;

	//バーの太さ
	static constexpr int _barThickness = 10;

	//バーの長さ
	static constexpr int _barLength = 64;

	//バーの傾き小
	static constexpr float _barSlopeSmall = 4.0f;

	//バーの傾き中
	static constexpr float _barSlopeMedium = 8.0f;

	//バーの傾き大
	static constexpr float _barSlopeLarge = 16.0f;

	//バーの傾きが変わる間隔
	static constexpr int _barSlopeChangeInterval = 8;

	//ブロックの縦の総数
	static constexpr int _blockVMax = 12;

	//ブロックの横の総数
	static constexpr int _blockHMax = 12;

	//ブロックの縦幅
	static constexpr int _blockH = 18;

	//ブロックの横幅
	static constexpr int _blockW = 42;

	//左上のブロックの初期x座標
	static constexpr float _blockStartPosX = 69.0f;

	//左上のブロックの初期y座標
	static constexpr float _blockStartPosY = 69.0f;

	//ボールの初期x座標
	static constexpr float _ballStartPosX = 400.0f;

	//ボールの初期y座標
	static constexpr float _ballStartPosY = 300.0f;

	//ボールの初期スピード
	static constexpr float _ballStartSpeed = 5.0f;

	//ボールの初期角度
	static constexpr float _ballStartAngle = -120.0f;

	//ボールの直径
	static constexpr int _ballDiameter = 8;

	//ブラックの初期y座標
	static constexpr float _brackStartPosY = -628.0f;

	//ブラックの縦幅
	static constexpr int _brackH = 128;

	//ブラックの透明部
	static constexpr int _brackTransparentH = 17;

	//ブラックの横幅
	static constexpr int _brackW = 128;

	//ブラックが動くスピード
	static constexpr float _brackSpeed = 10.0f;

	//初期ライフの数
	static constexpr int _startLifeNum = 3;

	//ライフのサイズ
	static constexpr int _lifeW = 32;

	//ライブのx座標
	static constexpr float _lifeX = (1240 - _lifeW) / 2;

	//最下ライフのy座標
	static constexpr float _lifeY = 430.0f;

	//ライフの配置間隔
	static constexpr float _lifeInterval = 40.0f;
};

