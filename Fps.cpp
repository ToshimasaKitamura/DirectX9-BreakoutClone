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
    if (_fps == 0.0f) TSYAssist::DebugOut("FPS計測中...");
    else TSYAssist::DebugOut("FPS：", _fps);
    _counter++;
    Sleep(GetWaitTime());   //待つべき時間を取得して待つ
    Regist();
    if (_counter == Define::_targetFPS) {  //更新タイミングに1回平均値を更新する
        UpdateAverage();
        _counter = 0;
    }  
}

void Fps::UpdateAverage()
{
    int len = (int)_list.size();
    if (len < Define::_FPSUpdateInterval) {   //まだ平均を計算するレベルにまでたまっていなければ計算しない
        return;
    }
    int tookTime = _list.back() - _list.front();//LIST_LEN_MAXフレームにかかった時間
    float average = (float)tookTime / (len - 1);//平均を取る
    if (average == 0) {//0割り防止
        return;
    }
    //_fps = std::floorf(average) + (std::roundf(10.0f * (average - std::floorf(average))) / 10.0f);
    _fps = 1000 / average;
}

void Fps::Regist()
{
    _list.push_back(timeGetTime());   //現在の時刻を記憶
    if (_list.size() > Define::_FPSUpdateInterval) {  //器から漏れたらポップ
        _list.pop_front();
    }
}

unsigned Fps::GetWaitTime() const
{
    int len = (int)_list.size();
    if (len == 0) {
        return 0;
    }
    int shouldTookTime = (int)(1000 / Define::_targetFPS *(len));            //計算上かかるべき時間
    int actuallyTookTime = timeGetTime() - _list.front();   //実際にかかった時間
    int waitTime = shouldTookTime - actuallyTookTime;       //計算上かかるべき時間 - 実際にかかった時間　はすなわち待つべき時間
    waitTime = waitTime > 0 ? waitTime : 0;
    return (unsigned)(waitTime);
}