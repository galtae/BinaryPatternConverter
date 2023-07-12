// ConvertPattern.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <atlstr.h>

#define MAX_LENGTH 1024

//#define __TEST

unsigned long long CopyClipBoard(CString szBuff, int str_lenth)
{
    int Ret = 0;
    ::OpenClipboard(NULL);
    EmptyClipboard();

    HGLOBAL hglbCopy = GlobalAlloc(GMEM_MOVEABLE, 256);
    char* mem = (char*)GlobalLock(hglbCopy);

    strcpy_s(mem, str_lenth, szBuff);
    GlobalUnlock(hglbCopy);
    ::SetClipboardData(CF_TEXT, mem);
    CloseClipboard();
    return Ret;
}

int main()
{
    char input_str[MAX_LENGTH];
    CString c_input_str;
    //input_str.GetBuffer();

#ifdef __TEST
    //strcpy_s(input_str, 17, "0x74, 0x66, 0x13");
    strcpy_s(input_str, 17, "77 66 55 44");
#endif

#ifndef __TEST
    scanf_s("%[^\n]s", &input_str, sizeof(input_str));
#endif
    int str_len = _tcslen(input_str);
    //_tcscpy_s((LPSTR)(LPCSTR)c_input_str, str_len + 1, input_str);
    c_input_str = input_str;

    
    // 1.0x83, -> 83
    if (c_input_str.Find("0x", 0) == 0)
    {
        c_input_str = input_str;
        c_input_str.Replace("0x", "");
        c_input_str.Replace(",", "");
        printf("%s", c_input_str);
    }

    // 2. 83 -> 0x83
    else
    {       
        c_input_str = "0x" + c_input_str;
        c_input_str.Replace(" ", ", 0x");        
    }
    str_len = c_input_str.GetLength();
    CopyClipBoard(c_input_str, str_len + 1);
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
