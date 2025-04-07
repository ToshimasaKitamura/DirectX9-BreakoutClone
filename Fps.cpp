#include "Fps.h"
#include <Windows.h>
#include <cmath>
#include <string>
#include <stdlib.h>
#include "TSYAssist.h"
#include "Window.h"
#include "Define.h"

#pragma comment (lib, "winmm.lib")

Fps::Fps() :_counter(0), _fps(0)
{
    timeBeginPeriod(1);
}

Fps::~Fps()
{
    timeEndPeriod(1);
}

void Fps::Wait()
{
    Window window;
    if (!window.isActive()) {
        _list.clear();
        _fps = 0.0f;
        window.SetActive();
    }
    if (_fps == 0.0f) TSYAssist::DebugOut("FPS�v����...");
    else TSYAssist::DebugOut("FPS�F", _fps);
    _counter++;
    Sleep(GetWaitTime());   //�҂ׂ����Ԃ��擾���đ҂�
    Regist();
    if (_counter == Define::_targetFPS) {  //�X�V�^�C�~���O��1�񕽋ϒl���X�V����
        UpdateAverage();
        _counter = 0;
    }  
}

void Fps::UpdateAverage()
{
    int len = (int)_list.size();
    if (len < Define::_FPSUpdateInterval) {   //�܂����ς��v�Z���郌�x���ɂ܂ł��܂��Ă��Ȃ���Όv�Z���Ȃ�
        return;
    }
    int tookTime = _list.back() - _list.front();//LIST_LEN_MAX�t���[���ɂ�����������
    float average = (float)tookTime / (len - 1);//���ς����
    if (average == 0) {//0����h�~
        return;
    }
    //_fps = std::floorf(average) + (std::roundf(10.0f * (average - std::floorf(average))) / 10.0f);
    _fps = 1000 / average;
}

void Fps::Regist()
{
    _list.push_back(timeGetTime());   //���݂̎������L��
    if (_list.size() > Define::_FPSUpdateInterval) {  //�킩��R�ꂽ��|�b�v
        _list.pop_front();
    }
}

unsigned Fps::GetWaitTime() const
{
    int len = (int)_list.size();
    if (len == 0) {
        return 0;
    }
    int shouldTookTime = (int)(1000 / Define::_targetFPS *(len));            //�v�Z�ォ����ׂ�����
    int actuallyTookTime = timeGetTime() - _list.front();   //���ۂɂ�����������
    int waitTime = shouldTookTime - actuallyTookTime;       //�v�Z�ォ����ׂ����� - ���ۂɂ����������ԁ@�͂��Ȃ킿�҂ׂ�����
    waitTime = waitTime > 0 ? waitTime : 0;
    return (unsigned)(waitTime);
}