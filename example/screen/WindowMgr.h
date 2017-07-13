/*************************************************************************
	> File Name: WindowMgr.h
	> Author: 
	> Mail: 
	> Created Time: 2017年06月06日 星期二 21时38分50秒
 ************************************************************************/

#ifndef _WINDOWMGR_H
#define _WINDOWMGR_H

#include<vector>
#include<string>
#include<iostream>
#include "Screen.h"

class Window_mgr{
public:
    // 窗口中每个屏幕的编号
    typedef std::vector<Screen>::size_type ScreenIndex;
    // 按照编号将指定的Screen 重置为空白
    void clear(ScreenIndex);

private:
    std::vector<Screen> screens{Screen(24,80,' ')};
};

inline void Window_mgr::clear(ScreenIndex i)
{
    //s是一个Screen的引用，指向我们想清空的那个屏幕
    Screen &s=screens[i];
    //将那个选定的Screen重置为空白
    s.contents=string(s.begin*s.width,' ');
}


#endif
