#ifndef _TIC_LOCAL_RECORD_H_
#define _TIC_LOCAL_RECORD_H_

#include <stdio.h>
#include <string>
#include <functional>
#include "../TICManager.h"

/**
*  ��Ȩ����
*/
struct TEduRecordAuthParam {
	TEduRecordAuthParam() {}
	TEduRecordAuthParam(int appId, std::string userId, std::string userSig) {
		this->appId = appId;
		this->userId = userId;
		this->userSig = userSig;
	}

	int appId = 0;
	std::string userId;
	std::string userSig;
};

struct RecordKey {
	RecordKey() {}
	RecordKey(int appid, int classid, std::string& userid, std::string& taskid) {
		this->appid = appid;
		this->class_id = classid;
		this->user_id = userid;
		this->task_id = taskid;
	}
	int appid = 0;
	int class_id = 0;	  //����д����ʾȫ��
	std::string user_id;  //����д����ʾȫ��
	std::string task_id; //����д����ʾȫ��
};

/**
*  ��Ƶ����
*/
struct TEduRecordParam {
	//���ֶκ��塿��Ƶ�ɼ�֡��
	//���Ƽ�ȡֵ��10fps �� 20fps��10fps ���»�����΢���ٸУ�5fps ���¿��ٸ����ԣ�20fps ���ϵ�֡��������˷ѣ���Ӱ��֡��Ҳֻ�� 24fps����
	int videoFps = 10;

	//���ֶκ��塿��Ƶ��������
	int videoBps = 1000; //1000kpbs

	//���ֶκ��塿��Ƶ¼�ƴ���xλ��
	int x = 0;

	//���ֶκ��塿��Ƶ¼�ƴ���Y
	int y = 0;

	//���ֶκ��塿��Ƶ¼�ƴ��ڿ�ȣ�0��ʾ�������ڿ��
	int width = 0;

	//���ֶκ��塿��Ƶ¼�ƴ��ڸ߶�, 0��ʾ�������ڸ߶�
	int Height = 0;

	//��¼�ƽ�������
	std::string AppProc;  //��QQMusic.exe

	 //��¼�ƴ���wndId
	int Wnd = 0;

	//�Ƿ�¼����Ƶ
	bool enableAudio = true;

	//�Ƿ��ϴ�����̨
	bool enableUpload = true;

	//¼�ƵĿ���ID
	int classId = 0;
};

/**
* ¼���¼��ص��ӿ�
*/
class TEduRecordCallback {
public:
	virtual void onGotStatus(int code, const char* msg) = 0;
	virtual void onUploadProgress(int total, int current) = 0;
};

class TICLocalRecorder {
public:
	virtual ~TICLocalRecorder() {};
	const std::string RecordExe = "TXCloudRecord.exe";
public:

	/**
	* ��ȡTICLocalRecord��������
	*/
	static TICLocalRecorder* GetInstance();

	/**
	* ��������¼�Ʒ���
	* @param path 		¼�Ʒ���Ŀ�ִ���ļ�exe·��
	*/
	virtual bool startService(const std::string& path) = 0;

	/**
	* ��ʼ��
	* @param authParam 		��Ȩ����
	*/
	virtual int init(const TEduRecordAuthParam& authParam, TICCallback callback) = 0;

	/**
	* ��Ƶ����¼��, ֧�ֲ�����¼�ơ�
	* @param szRecordPath:��Ƶ¼�ƺ�洢·����Ŀǰ��flv��׺�ļ���
	* @return
	*          0 �ɹ���
	*          -1 ·���Ƿ�
	*          -2 �ϴ�¼��δ����������stopRecord
	*/
	virtual int startLocalRecord(const TEduRecordParam& para, const char * szRecordPath, TICCallback callback) = 0;

	/**
	* ����¼�ƶ���Ƶ��ֹͣ�����������Ƶ����¼���У�SDK�ڲ����Զ�����¼��
	* @return
	*       0 �ɹ���
	*      -1 ������¼������
	*/
	virtual int stopLocalRecord(TICCallback callback) = 0;

	/**
	* ��ͣ����¼�ƣ���ͣ�ڼ������Ƶ����¼��
	* @return���ɹ� or ʧ�ܣ��ڴ���䡢��Դ����ʧ�ܵ�ԭ����ܻᵼ�·���ʧ��
	*/
	virtual int pauseLocalRecord(TICCallback callback) = 0;

	/**
	*  �ָ�����¼��
	*/
	virtual int resumeLocalRecord(TICCallback callback) = 0;

	/**
	* ֹͣ����¼�ƺ��������˳�����
	*/
	virtual int exit(TICCallback callback) = 0;

	/**
	* ��ȡ¼�ƵĽ��
	*/
	virtual int getRecordResult(const RecordKey& key, TICCallback callback) = 0;

};

#endif //_TIC_LOCAL_RECORD_H_
