#pragma once

#include <memory>
#include "..\SDK\TIC\TICLocalRecord.h"

class CPushDlg
	: public CDialogEx
	, public std::enable_shared_from_this<CPushDlg>
{
	DECLARE_MESSAGE_MAP()
public:
	CPushDlg(CWnd* pParent = nullptr);

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PUSH_DIALOG };
#endif

private:
	virtual BOOL OnInitDialog() override;
	virtual void DoDataExchange(CDataExchange* pDX) override;

private:
	TICLocalRecorder* mLocalRecorder;

public:
	afx_msg void OnBnClickedChkEnableDraw();
	afx_msg void OnBnClickedCheckEnablePush();
};