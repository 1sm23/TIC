#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"

class CTICDemoApp : public CWinApp
{
	DECLARE_MESSAGE_MAP()
public:
	CTICDemoApp();

	virtual BOOL InitInstance();
};

extern CTICDemoApp theApp;
