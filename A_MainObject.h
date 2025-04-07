#pragma once

class A_MainObject
{
public:
	explicit A_MainObject() = default;
	~A_MainObject() = default;

protected:
	//�O�g�̍��� / �t���[���̒��� + 1
	static constexpr int _outFrameVNum = 35;

	//�O�g�̕� / �t���[���̒��� + 1
	static constexpr int _outFrameHNum = 46;

	//���g�̍��� / �t���[���̒��� + 1
	static constexpr int _inFrameVNum = 32;

	//���g�̕� / �t���[���̒���
	static constexpr int _inFrameHNum = 40;

	//�t���[���̑���
	static constexpr int _frameThickness = 3;

	//�t���[���̒���
	static constexpr int _frameLength = 14;

	//��ʑS�̂̃t���[����
	static constexpr int _screenFrameSize = 40;

	//�o�[�̏���x���W
	static constexpr float _barStartPosX = 320.0f;

	//�o�[��y��
	static constexpr float _barY = 430.0f;

	//�o�[�̈ړ��X�s�[�h
	static constexpr float _barSpeed = 8.0f;

	//�o�[�̑���
	static constexpr int _barThickness = 10;

	//�o�[�̒���
	static constexpr int _barLength = 64;

	//�o�[�̌X����
	static constexpr float _barSlopeSmall = 4.0f;

	//�o�[�̌X����
	static constexpr float _barSlopeMedium = 8.0f;

	//�o�[�̌X����
	static constexpr float _barSlopeLarge = 16.0f;

	//�o�[�̌X�����ς��Ԋu
	static constexpr int _barSlopeChangeInterval = 8;

	//�u���b�N�̏c�̑���
	static constexpr int _blockVMax = 12;

	//�u���b�N�̉��̑���
	static constexpr int _blockHMax = 12;

	//�u���b�N�̏c��
	static constexpr int _blockH = 18;

	//�u���b�N�̉���
	static constexpr int _blockW = 42;

	//����̃u���b�N�̏���x���W
	static constexpr float _blockStartPosX = 69.0f;

	//����̃u���b�N�̏���y���W
	static constexpr float _blockStartPosY = 69.0f;

	//�{�[���̏���x���W
	static constexpr float _ballStartPosX = 400.0f;

	//�{�[���̏���y���W
	static constexpr float _ballStartPosY = 300.0f;

	//�{�[���̏����X�s�[�h
	static constexpr float _ballStartSpeed = 5.0f;

	//�{�[���̏����p�x
	static constexpr float _ballStartAngle = -120.0f;

	//�{�[���̒��a
	static constexpr int _ballDiameter = 8;

	//�u���b�N�̏���y���W
	static constexpr float _brackStartPosY = -628.0f;

	//�u���b�N�̏c��
	static constexpr int _brackH = 128;

	//�u���b�N�̓�����
	static constexpr int _brackTransparentH = 17;

	//�u���b�N�̉���
	static constexpr int _brackW = 128;

	//�u���b�N�������X�s�[�h
	static constexpr float _brackSpeed = 10.0f;

	//�������C�t�̐�
	static constexpr int _startLifeNum = 3;

	//���C�t�̃T�C�Y
	static constexpr int _lifeW = 32;

	//���C�u��x���W
	static constexpr float _lifeX = (1240 - _lifeW) / 2;

	//�ŉ����C�t��y���W
	static constexpr float _lifeY = 430.0f;

	//���C�t�̔z�u�Ԋu
	static constexpr float _lifeInterval = 40.0f;
};

