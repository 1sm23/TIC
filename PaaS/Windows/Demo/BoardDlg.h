#pragma once

#include <memory>

enum class BoardState
{
	NotInit,
	Inited,
};

//Ϳѻ������ǩҳ
class CDrawTabDlg : public CDialogEx
{
	DECLARE_MESSAGE_MAP()
public:
	CDrawTabDlg(CWnd* pParent = nullptr);

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOARD_TAB_DRAW };
#endif

	void Init();

	void UpdateUndoState(bool canUndo);
	void UpdateRedoState(bool canRedo);

	void UpdateBackgroundColor();
	void UpdateBoardScale();

private:
	virtual BOOL OnInitDialog() override;
	virtual void DoDataExchange(CDataExchange* pDX) override;
	
	// ��Ϣӳ�亯��
	afx_msg void OnBnClickedChkEnableDraw();

	afx_msg void OnBnClickedBtnUndo();
	afx_msg void OnBnClickedBtnRedo();

	afx_msg void OnBnClickedBtnClearDraw();
	afx_msg void OnBnClickedBtnClearBoard();
	afx_msg void OnBnClickedBtnBkImage();

	afx_msg void OnBnClickedBtnBrushColor();
	afx_msg void OnBnClickedBtnBackColor();
	afx_msg void OnBnClickedBtnTextColor();

	afx_msg void OnCbnSelchangeComboToolType();

	afx_msg void OnNMCustomdrawSliderBrushThin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSliderTextSize(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void OnBnClickedBtnAddH5Ppt();
	afx_msg void OnBnClickedBtnSetBackH5();

	afx_msg void OnNMCustomdrawSliderScale(NMHDR *pNMHDR, LRESULT *pResult);

private:
	CButton chkDrawEnable_;

	CButton btnUndo_;
	CButton btnRedo_;

	CMFCButton btnBrushColor_;
	CMFCButton btnBackColor_;
	CMFCButton btnTextColor_;

	CComboBox comboToolType_;

	CSliderCtrl sliderBrushThin_;
	CSliderCtrl sliderTextSize_;

	CComboBox comboH5_;
	CEdit editBackH5_;

	CSliderCtrl sliderScale_;
};

//�װ������ǩҳ
class CBoardTabDlg : public CDialogEx
{
	DECLARE_MESSAGE_MAP()
public:
	CBoardTabDlg(CWnd* pParent = nullptr);

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOARD_TAB_BOARD };
#endif

	void UpdateBoardList();

private:
	virtual BOOL OnInitDialog() override;
	virtual void DoDataExchange(CDataExchange* pDX) override;

	// ��Ϣӳ�亯��
	afx_msg void OnBnClickedBtnPrevBoard();
	afx_msg void OnBnClickedBtnNextBoard();
	afx_msg void OnBnClickedBtnPrevStep();
	afx_msg void OnBnClickedBtnNextStep();

	afx_msg void OnBnClickedBtnAddBoard();
	afx_msg void OnBnClickedBtnDelBoard();
	afx_msg void OnLbnSelchangeListBoard();

private:
	CButton chkResetStep_;
	CListBox listBoard_;
};

//�ļ�������ǩҳ
class CFileTabDlg : public CDialogEx
{
	DECLARE_MESSAGE_MAP()
public:
	CFileTabDlg(CWnd* pParent = nullptr);

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOARD_TAB_FILE };
#endif

	void UpdateFileList();

private:
	virtual BOOL OnInitDialog() override;
	virtual void DoDataExchange(CDataExchange* pDX) override;

	// ��Ϣӳ�亯��
	afx_msg void OnBnClickedBtnAddFile();
	afx_msg void OnBnClickedBtnDelFile();
	afx_msg void OnNMDbClkListFile(NMHDR *pNMHDR, LRESULT *pResult);

private:
	CListCtrl listFile_;
};

class CBoardDlg 
	: public CDialogEx
	, public TEduBoardCallback
	, public std::enable_shared_from_this<CBoardDlg>
{
	DECLARE_MESSAGE_MAP()
public:
	CBoardDlg(CWnd* pParent = nullptr);

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOARD_DIALOG };
#endif

	void Init();
	void Uninit();
	void UpdateUI();

private:
	virtual BOOL OnInitDialog() override;
	virtual void DoDataExchange(CDataExchange* pDX) override;

	void UpdateBoardPos();
	void UpdateBoardRatio();

	// ��Ϣӳ�亯��
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTabSelChange(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void OnCbnSelchangeComboRatio();
	afx_msg void OnCbnSelchangeComboFitMode();

	//TEduBoardCallback
	virtual void onTEBError(TEduBoardErrorCode code, const char * msg) override;
	virtual void onTEBWarning(TEduBoardWarningCode code, const char * msg) override;
	virtual void onTEBInit() override;
	virtual void onTEBHistroyDataSyncCompleted() override;
	virtual void onTEBSyncData(const char * data) override;
	virtual void onTEBUndoStatusChanged(bool canUndo) override;
	virtual void onTEBRedoStatusChanged(bool canRedo) override;
	virtual void onTEBImageStatusChanged(const char * boardId, const char * url, TEduBoardImageStatus status) override {}
	virtual void onTEBSetBackgroundImage(const char * url) override {}
	virtual void onTEBAddBoard(const TEduBoardStringList *boardList, const char * fileId) override;
	virtual void onTEBDeleteBoard(const TEduBoardStringList *boardList, const char * fileId) override;
	virtual void onTEBGotoBoard(const char * boardId, const char * fileId) override;
	virtual void onTEBAddFile(const char * fileId) override;
	virtual void onTEBAddH5PPTFile(const char * fileId) override;
	virtual void onTEBDeleteFile(const char * fileId) override;
	virtual void onTEBSwitchFile(const char * fileId) override;
	virtual void onTEBFileUploadProgress(const char *fileId, int currentBytes, int totalBytes, int uploadSpeed, double percent) override {};
	virtual void onTEBFileUploadStatus(const char *fileId, TEduBoardUploadStatus status, int errorCode, const char *errorMsg) override {};

private:
	BoardState boardState_ = BoardState::NotInit;
	bool histroySync_;

	CStatic staticBoard_;

	CTabCtrl tabBoardCtrl_;
	CDrawTabDlg		drawTabDlg_;
	CBoardTabDlg	boardTabDlg_;
	CFileTabDlg		fileTabDlg_;

	CComboBox comboRatio_;
	CComboBox comboFitMode_;
};
