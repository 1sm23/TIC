#ifndef _TIC_LOCAL_RECORD_H_
#define _TIC_LOCAL_RECORD_H_

#include <stdio.h>
#include <string>
#include <functional>

class TICLocalRecorder {
public:
	virtual ~TICLocalRecorder() {};

public:

	enum TEduRecordReslution {
		// ���� 4:3
		TXE_VIDEO_RESOLUTION_320x240 = 1,
		TXE_VIDEO_RESOLUTION_480x360 = 2,
		TXE_VIDEO_RESOLUTION_640x480 = 3,
		TXE_VIDEO_RESOLUTION_960x720 = 4,
		TXE_VIDEO_RESOLUTION_1280x960 = 5,

		// ����16:9
		TXE_VIDEO_RESOLUTION_320x180 = 101,
		TXE_VIDEO_RESOLUTION_480x272 = 102,
		TXE_VIDEO_RESOLUTION_640x360 = 103,
		TXE_VIDEO_RESOLUTION_960x540 = 104,
		TXE_VIDEO_RESOLUTION_1280x720 = 105,
		TXE_VIDEO_RESOLUTION_1920x1080 = 106,
	};

	/**
	 *  ��Ȩ����
	 */
	struct TEduRecordAuthParam {
		int appId;
		std::string userId;
		std::string userSig;
	};

	/**
	 *  ��Ƶ����
	 */
	struct TEduRecordParam {
		//���ֶκ��塿 ��Ƶ�ֱ���
		//���Ƽ�ȡֵ�� - ��Ƶͨ������ѡ��360 �� 640�����·ֱ��ʣ�resMode ѡ�� Portrait��
		//           - �ֻ�ֱ������ѡ�� 540 �� 960��resMode ѡ�� Portrait��
		//           - Window �� iMac ����ѡ�� 640 �� 360 �����Ϸֱ��ʣ�resMode ѡ�� Landscape��
		//���ر�˵���� ���� TRTCVideoResolution ֻ���ҵ�����ģʽ�ķֱ��ʣ����磺640 �� 360 �����ķֱ��ʡ�
		//             �����Ҫʹ�������ֱ��ʣ���ָ�� resMode Ϊ Portrait�����磺640 �� 360 + Portrait = 360 �� 640��
		int videoResolution = TXE_VIDEO_RESOLUTION_1280x720; //1280x720

		//���ֶκ��塿��Ƶ�ɼ�֡��
		//���Ƽ�ȡֵ��15fps �� 20fps��10fps ���»�����΢���ٸУ�5fps ���¿��ٸ����ԣ�20fps ���ϵ�֡��������˷ѣ���Ӱ��֡��Ҳֻ�� 24fps����
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
		int Wnd;

		//�Ƿ�¼����Ƶ
		bool enableAudio = true;
	};

	/**
	 * ¼���¼��ص��ӿ�
	 */
	class TEduRecordCallback {
	public:
		virtual void onGotStatus(int state, const char* msg) = 0;
	};

	/**
	* ��ʼ��
	 * @param authParam 		��Ȩ����
	*/
	virtual int init(TEduRecordAuthParam authParam) = 0;

	/**
	* ��Ƶ����¼��, ֧�ֲ�����¼�ơ�
	* @param szRecordPath:��Ƶ¼�ƺ�洢·����Ŀǰ�� flv��mp4 ��׺�ļ���
	* @return
	*          0 �ɹ���
	*          -1 ·���Ƿ�
	*          -2 �ϴ�¼��δ����������stopRecord
	*/
	virtual int startLocalRecord(const TEduRecordParam& para, const char * szRecordPath) = 0;

	/**
	* ����¼�ƶ���Ƶ��ֹͣ�����������Ƶ����¼���У�SDK�ڲ����Զ�����¼��
	* @return
	*       0 �ɹ���
	*      -1 ������¼������
	*/
	virtual int stopLocalRecord() = 0;

	/**
	* �������� (�ڷ������ͳ�ȥ����������ֻ����Ƶ)
	* @param url - һ���Ϸ���������ַ����Ѷ�Ƶ����� URL ��Ҫ����� txSecret �� txTime ������ǩ������������������Ʋ���ȥ������������ǩ���Ƿ�Ϸ���
	* @return���ɹ� or ʧ�ܣ��ڴ���䡢��Դ����ʧ�ܵ�ԭ����ܻᵼ�·���ʧ��
	*/
	virtual int startPush(const TEduRecordParam& para, const char * url) = 0;

	/**
	* ֹͣ������ע������ url �������ԣ�Ҳ����һ������ Url ͬʱֻ����һ����������������
	*/
	virtual int stopPush() = 0;


	/**
	* ֹͣ����¼�ƺ��������˳�����
	*/
	virtual int exit() = 0;

};



#endif //_TIC_LOCAL_RECORD_H_
