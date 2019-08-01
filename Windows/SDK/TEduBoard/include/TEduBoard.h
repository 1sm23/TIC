/**
 * ��Ѷ�ưװ�SDK��Window��Linuxƽ̨ͷ�ļ�
 */

#pragma once

#if defined(WIN32) //Windows

#ifdef EDUSDK_EXPORTS
#define EDUSDK_API __declspec(dllexport)
#else
#define EDUSDK_API __declspec(dllimport)
#endif

#include <windows.h>

#undef DeleteFile

#define WINDOW_HANDLE HWND

#else //Unix

#define EDUSDK_API __attribute__ ((visibility("default")))

#if defined(__APPLE__) //macOS

#ifdef __cplusplus
#ifdef __OBJC__
@class NSView;
#else
struct NSView;
#endif
#define WINDOW_HANDLE NSView*
#else
#define WINDOW_HANDLE void*
#endif

#else //Linux

#define WINDOW_HANDLE unsigned long

#endif

#endif

#include <cstdint>

class TEduBoardController;


/*************************************************************************************************
 *
 * SDK�����ӿ�
 *
 *************************************************************************************************/

extern "C" {
    /**
     * �����װ������ʵ��
     * @param disableCefInit                �Ƿ����CEF��ܳ�ʼ����ͨ����Ĭ��ֵ����
     * @return �װ������ʵ��ָ��
     * @warning �ýӿڱ��������̵߳���
     * @info ����SDK����CEF���(BSD-licensed)ʵ�֣������ĳ�����Ҳʹ����CEF��ܣ����ܻ���ڳ�ͻ��
     *       �� disableCefInit == true ʱ�������õ�SDK�ڲ���CEF��ʼ��������������ڱ����ͻ��
     *       �������г�ʼ��CEFʱ����ؽ� CefSettings::browser_subprocess_path �ֶ�ָ��TEduBoardRender�����Ա�֤SDK����������
     */
    EDUSDK_API TEduBoardController *CreateTEduBoardController(bool disableCefInit = false);

    /**
     * ���ٰװ������
     * @param ppBoardController	ָ��װ������ָ��
     * @param ppBoardControllerָ��ᱻ�Զ��ÿ�
     */
    EDUSDK_API void DestroyTEduBoardController(TEduBoardController **ppBoardController);

    /**
     * ���ðװ�������Ⱦ
     * @return ����������Ⱦ�Ƿ�ɹ�
     * @info ����������Ⱦʱ��SDK���ٴ����װ�VIEW������ͨ��onTEBOffscreenPaint�ص��ӿڽ��װ�������Ⱦ�����������׳�
     * @warning �ýӿڱ���Ҫ�ڵ�һ�ε���CreateTEduBoardController֮ǰ���ò���Ч�����򽫻�ʧ��
     */
    EDUSDK_API bool EnableTEduBoardOffscreenRender();

	/**
	 * ���ðװ���־�ļ�·��
	 * @param logFilePath					Ҫ���õİװ���־�ļ�·���������ļ������ļ���׺��UTF8���룬Ϊ�ջ�nullptr��ʾʹ��Ĭ��·��
	 * @return ���ðװ���־�ļ�·���Ƿ�ɹ�
	 * @warning �ýӿڱ���Ҫ�ڵ�һ�ε���CreateTEduBoardController֮ǰ���ò���Ч�����򽫻�ʧ��
	 * @info Ĭ��·����Windows��Ϊ��%AppData%\Local\TIC\teduboard.log
	 * @info Ĭ��·����Linux��Ϊ��~/TIC/teduboard.log
	 */
	EDUSDK_API bool SetTEduBoardLogFilePath(const char *logFilePath);

	/**
	 * ��ȡSDK�汾��
	 * @return SDK�汾��
	 * @info ����ֵ�ڴ���SDK�ڲ������û�����Ҫ�Լ��ͷ�
	 */
	EDUSDK_API const char * GetTEduBoardVersion();
}


/*************************************************************************************************
 *
 * a. ����ö��ֵ
 *
 *************************************************************************************************/

/**
 * �װ�����붨�壨���أ�
 */
enum TEduBoardErrorCode {						//�¼�˵��
	TEDU_BOARD_ERROR_INIT				= 1,	//��ʼ��ʧ��
	TEDU_BOARD_ERROR_AUTH				= 2, 	//�����Ȩʧ�ܣ����ȹ������
    TEDU_BOARD_ERROR_LOAD				= 3,	//�ļ�����ʧ��
	TEDU_BOARD_ERROR_TIM_INVALID    	= 5,    //��Ѷ��IMSDK������
	TEDU_BOARD_ERROR_HISTORYDATA		= 6,	//ͬ����ʷ����ʧ��
	TEDU_BOARD_ERROR_RUNTIME			= 7,	//�װ����д���
};

/**
 * �װ�����붨�壨���棩
 */
enum TEduBoardWarningCode {							//�¼�˵��
	TEDU_BOARD_WARNING_SYNC_DATA_PARSE_FAILED       = 1,    //���յ������˵�ͬ�����ݽ�������
	TEDU_BOARD_WARNING_TIM_SEND_MSG_FAILED          = 2,    //��Ѷ��IMSDK������Ϣʧ��
	TEDU_BOARD_WARNING_H5PPT_ALREADY_EXISTS			= 3,    //Ҫ��ӵ�H5PPT�Ѵ���
	TEDU_BOARD_WARNING_BOARD_LOAD_FAILED			= 4,	//�װ���Դ����ʧ�ܣ������ڲ�����
};

/**
 * �װ幤�߶���
 */
enum TEduBoardToolType {						//��������
    TEDU_BOARD_TOOL_TYPE_MOUSE			= 0,	//���
    TEDU_BOARD_TOOL_TYPE_PEN			= 1,	//����
	TEDU_BOARD_TOOL_TYPE_ERASER			= 2,	//��Ƥ��
	TEDU_BOARD_TOOL_TYPE_LASER			= 3,	//�����
	TEDU_BOARD_TOOL_TYPE_LINE			= 4,	//ֱ��
	TEDU_BOARD_TOOL_TYPE_OVAL			= 5,	//������Բ
	TEDU_BOARD_TOOL_TYPE_RECT			= 6,	//���ľ���
	TEDU_BOARD_TOOL_TYPE_OVAL_SOLID		= 7,	//ʵ����Բ
	TEDU_BOARD_TOOL_TYPE_RECT_SOLID		= 8,	//ʵ�ľ���
    TEDU_BOARD_TOOL_TYPE_POINT_SELECT	= 9,	//��ѡ����
	TEDU_BOARD_TOOL_TYPE_RECT_SELECT    = 10,	//��ѡ����
	TEDU_BOARD_TOOL_TYPE_TEXT			= 11,	//�ı�����
	TEDU_BOARD_TOOL_TYPE_ZOOM_DRAG		= 12,	//�����ƶ��װ幤��
};

/**
 * �װ�ͼƬ������ģʽ����
 * @info ���Կ�Ȼ�׼�ȱ����Ŵ������;���ͬ���ж���Ч��һ�£����Ը߶Ȼ�׼�ȱ����Ŵ���Ӷ��;ӵ�ͬ���ж���Ч��һ��
 */
enum TEduBoardImageFitMode {
	TEDU_BOARD_IMAGE_FIT_MODE_CENTER	= 0,	//�Կ�Ȼ��߸߶�Ϊ��׼���ж���ȱ����Ŵ�
	TEDU_BOARD_IMAGE_FIT_MODE_LEFT		= 4,	//�Կ�Ȼ��߸߶�Ϊ��׼�����ȱ����Ŵ�
	TEDU_BOARD_IMAGE_FIT_MODE_TOP		= 5,	//�Կ�Ȼ��߸߶�Ϊ��׼������ȱ����Ŵ�
	TEDU_BOARD_IMAGE_FIT_MODE_RIGHT		= 6,	//�Կ�Ȼ��߸߶�Ϊ��׼�Ҷ���ȱ����Ŵ�
	TEDU_BOARD_IMAGE_FIT_MODE_BOTTOM	= 7,	//�Կ�Ȼ��߸߶�Ϊ��׼�׶���ȱ����Ŵ�
};

/**
 * �װ�ͼƬ״̬����
 */
enum TEduBoardImageStatus {						//״̬����
	TEDU_BOARD_IMAGE_STATUS_LOADING		= 1,	//����ͼƬ���ڼ���
	TEDU_BOARD_IMAGE_STATUS_LOAD_DONE	= 2,	//����ͼƬ�������
	TEDU_BOARD_IMAGE_STATUS_LOAD_ABORT	= 3,	//����ͼƬ�����ж�
	TEDU_BOARD_IMAGE_STATUS_LOAD_ERROR	= 4,	//����ͼƬ���ش���
};

/**
 * �װ��ı���ʽ
 */
enum TEduBoardTextStyle{
    TEDU_BOARD_TEXT_STYLE_NORMAL		= 0,	//������ʽ
    TEDU_BOARD_TEXT_STYLE_BOLD			= 1,	//������ʽ
    TEDU_BOARD_TEXT_STYLE_ITALIC		= 2,	//б����ʽ
    TEDU_BOARD_TEXT_STYLE_BOLD_ITALIC	= 3,	//��б����ʽ
};

/**
 * �װ��ϴ�״̬
 */
enum TEduBoardUploadStatus{
    TEDU_BOARD_UPLOAD_STATUS_SUCCEED	= 1,	//�ϴ��ɹ�
    TEDU_BOARD_UPLOAD_STATUS_FAILED		= 2,	//�ϴ�ʧ��
};

/**
 * H5����״̬����
 */
enum TEduBoardBackgroundH5Status{
    TEDU_BOARD_BACKGROUND_H5_STATUS_LOADING        = 1,    //H5�������ڼ���
    TEDU_BOARD_BACKGROUND_H5_STATUS_LOAD_FINISH    = 2,    //H5�����������
};

/**
 * �װ���������Ӧģʽ�����ݰ���ͼƬ���ļ���PPT������
 */
enum TEduBoardContentFitMode {
	TEDU_BOARD_CONTENT_FIT_MODE_NONE = 0,				//��ʹ����������Ӧ��Ĭ��ģʽ�����Զ������װ��߱ȣ����ݵȱ������ž�����ʾ�����ݿ��<=�װ���
	TEDU_BOARD_CONTENT_FIT_MODE_CENTER_INSIDE = 1,		//�Զ������װ��߱�������һ�£����������װ壬�װ�ȱ������ž�����ʾ���װ���<=�������
	TEDU_BOARD_CONTENT_FIT_MODE_CENTER_COVER = 2,		//�Զ������װ��߱�������һ�£����������װ壬�װ�ȱ������ž�����ʾ���װ���>=�������
};


/*************************************************************************************************
 *
 * b. �����ṹ��
 *
 *************************************************************************************************/

/**
 * ��Ȩ����
 */
struct TEduBoardAuthParam {
	uint32_t sdkAppId;
	const char * userId;
	const char * userSig;

    TEduBoardAuthParam()
            : sdkAppId(0)
            , userId(nullptr)
            , userSig(nullptr)
    {

    }

    TEduBoardAuthParam(uint32_t sdkAppId, const char * userId, const char * userSig)
            : sdkAppId(sdkAppId)
            , userId(userId)
            , userSig(userSig)
    {

    }
};

/**
 * ��ɫ�������������Դ����������Ͷ��壬��ʹ�������������ͣ�
 */
struct TEduBoardColor {
	uint8_t red = 0;
	uint8_t green = 0;
	uint8_t blue = 0;
	uint8_t alpha = 0;

    TEduBoardColor()
            : red(0)
            , green(0)
            , blue(0)
            , alpha(0)
    {

    }

    TEduBoardColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
            : red(red)
            , green(green)
            , blue(blue)
            , alpha(alpha)
    {

    }
};

/**
 * �װ��ʼ������
 */
struct TEduBoardInitParam{
	bool progressEnable;					//�Ƿ�����SDK����Loadingͼ��
    const char * ratio;                     //Ĭ�ϰװ��߱ȣ��ɴ���ʽ�硰4:3������16:9�����ַ�����
    bool drawEnable;                        //�Ƿ�����Ϳѻ
    TEduBoardColor globalBackgroundColor;   //ȫ�ֱ���ɫ
    TEduBoardToolType toolType;			    //�װ幤��
    TEduBoardColor brushColor;              //������ɫ
    uint32_t brushThin;						//���ʴ�ϸ
    TEduBoardColor textColor;               //�ı���ɫ
    uint32_t textSize;                      //�ı���ϸ
    TEduBoardTextStyle textStyle;           //�ı���ʽ
    const char * textFamily;                //�ı�����
    bool timSync;                           //�Ƿ�ʹ����Ѷ��IMSDK����ʵʱ����ͬ��
	bool dataSyncEnable;					//�Ƿ���������ͬ�������ú󽫵��±��ذװ�������ᱻͬ����Զ��
	uint32_t preloadDepth;					//ͼƬԤ������ȣ�Ĭ��ֵ5����ʾԤ���ص�ǰҳǰ��5ҳ��ͼƬ
	double smoothLevel;						//�ʼ�ƽ��ϵ����Ĭ��0.1����Χ [0��1]
	TEduBoardContentFitMode contentFitMode; //��������Ӧģʽ
	const char * experimental;				//ʵ���Բ��������ֵ�����JSON��

    TEduBoardInitParam()
            : progressEnable(false)
			, ratio("16:9")
            , drawEnable(true)
            , globalBackgroundColor(255, 255, 255, 255)
            , toolType(TEDU_BOARD_TOOL_TYPE_MOUSE)
            , brushColor(255, 0, 0, 255)
            , brushThin(100)
            , textColor(0, 0, 0, 255)
            , textSize(320)
            , textStyle(TEDU_BOARD_TEXT_STYLE_NORMAL)
            , textFamily("sans-serif,serif,monospace")
            , timSync(true)
			, dataSyncEnable(true)
			, preloadDepth(5)
			, smoothLevel(0.1)
			, contentFitMode(TEDU_BOARD_CONTENT_FIT_MODE_NONE)
			, experimental(nullptr)
    {

    }
};

/**
 * �װ���Ϣ
 */
struct TEduBoardInfo {
    const char * boardId;		        //�װ�ID
    const char * backgroundUrl;		    //�װ屳��ͼ���߱���H5ҳ���URL
    TEduBoardColor backgroundColor;     //�װ屳��ɫ

    TEduBoardInfo()
            : boardId(nullptr)
            , backgroundUrl(nullptr)
    {

    }

    TEduBoardInfo(const char * boardId, const char * backgroundUrl, TEduBoardColor backgroundColor)
            : boardId(boardId)
            , backgroundUrl(backgroundUrl)
            , backgroundColor(backgroundColor)
    {

    }
};

/**
 * �װ���Ϣ�б�
 */
class TEduBoardInfoList {
protected:
    virtual ~TEduBoardInfoList() {};

public:
    /**
     * @return �װ���Ϣ����
     */
    virtual uint32_t GetCount() const = 0;

    /**
     * @return �װ���Ϣ
     */
    virtual TEduBoardInfo GetBoardInfo(uint32_t index) const = 0;
};

/**
 * �ļ���Ϣ
 */
struct TEduBoardFileInfo {
	const char * fileId;						//�ļ�ID
	const char * title;							//�ļ���
	const char * downloadUrl; 					//�ļ����ص�ַ
    uint32_t pageIndex;							//�ļ���ǰ��ʾ��ҳ��
    uint32_t pageCount;							//�ļ�ҳ��
	const TEduBoardInfoList *boardInfoList;		//�װ���Ϣ�б�

    TEduBoardFileInfo()
            : fileId(nullptr)
            , title(nullptr)
            , downloadUrl(nullptr)
            , pageIndex(0)
            , pageCount(0)
            , boardInfoList(nullptr)
    {

    }

	TEduBoardFileInfo(const char * fileId, const char * title, const char * downloadUrl, uint32_t pageIndex, uint32_t pageCount, TEduBoardInfoList *boardInfoList)
		    : fileId(fileId)
		    , title(title)
		    , downloadUrl(downloadUrl)
		    , pageIndex(pageIndex)
		    , pageCount(pageCount)
		    , boardInfoList(boardInfoList)
	{

	}
};

/**
 * �ļ���Ϣ�б�
 */
class TEduBoardFileInfoList {
protected:
	virtual ~TEduBoardFileInfoList() {};

public:
	/**
	 * @return �ļ���Ϣ����
	 */
	virtual uint32_t GetCount() const = 0;

	/**
	 * @return �ļ���Ϣ
	 */
	virtual TEduBoardFileInfo GetFileInfo(uint32_t index) const = 0;

	/**
	 * �ͷ��ļ���Ϣ�б�
	 * @warning �ļ���Ϣ�б�ʹ����֮����ص��øýӿ����ͷ��ڴ�
	 */
	virtual void Release() = 0;
};

/**
 * �װ�ID�б�
 */
class TEduBoardList {
protected:
	virtual ~TEduBoardList() {};

public:
	/**
	 * @return �װ����
	 */
	virtual uint32_t GetCount() const = 0;

	/**
	 * @return �װ�ID
	 * @info ����ֵ�ڴ���SDK�ڲ���������Ҫ�û������ͷ�
	 */
	virtual const char * GetBoard(uint32_t index) const = 0;

	/**
	 * �ͷŰװ�ID�б�
	 * @warning �װ�ID�б�ʹ����֮����ص��øýӿ����ͷ��ڴ�
	 */
	virtual void Release() = 0;
};


/*************************************************************************************************
 *
 * c. �¼��ص��ӿ�
 *
 *************************************************************************************************/
struct TEduBoardCallback {
	/*********************************************************************************************
	 *
	 *										һ���������̻ص�
	 *
	 *********************************************************************************************/
	 /**
	  * �װ����ص�
	  * @param code				�����룬�μ�TEduBoardErrorCode����
	  * @param msg				������Ϣ�������ʽΪUTF8
	  */
	virtual void onTEBError(TEduBoardErrorCode code, const char *msg) = 0;

	/**
	 * �װ徯��ص�
	 * @param code				�����룬�μ�TEduBoardWarningCode����
	 * @param msg				������Ϣ�������ʽΪUTF8
	 */
	virtual void onTEBWarning(TEduBoardWarningCode code, const char *msg) = 0;

	/**
	 * �װ��ʼ����ɻص����յ��ûص����ʾ�װ��Ѵ��ڿ���������״̬����ʱ�װ�Ϊ�հװװ壬��ʷ������δ��ȡ����
	 */
	virtual void onTEBInit() = 0;

	/**
	 * �װ���ʷ����ͬ����ɻص�
	 */
	virtual void onTEBHistroyDataSyncCompleted() {};

	/**
	 * �װ�ͬ�����ݻص�
	 * @param data				�װ�ͬ�����ݣ�JSON��ʽ�ַ�����
	 * @info �յ��ûص�ʱ��Ҫ���ص�����ͨ������ͨ�����͸������������ˣ��������յ������AddSyncData�ӿڽ�������ӵ��װ���ʵ������ͬ��
	 * @info �ûص����ڶ���װ�������ͬ����ʹ����Ѷ��IMSDK����ʵʱ����ͬ��ʱ�������յ��ûص�
	 */
	virtual void onTEBSyncData(const char *data) {};

	/**
	 * �װ�ɳ���״̬�ı�ص�
	 * @param canUndo			�װ嵱ǰ�Ƿ���ִ��Undo����
	 */
	virtual void onTEBUndoStatusChanged(bool canUndo) {};

	/**
	 * �װ������״̬�ı�ص�
	 * @param canRedo			�װ嵱ǰ�Ƿ���ִ��Redo����
	 */
	virtual void onTEBRedoStatusChanged(bool canRedo) {};

	/**
	 * �װ�������Ⱦ�ص�
	 * @param buffer            �װ��������ݣ���СΪwidth * height * 4�������԰װ����Ϸ�Ϊԭ������Ҵ��ϵ��°�BGRA����
	 * @param width             �װ��������ݵĿ��
	 * @param height            �װ��������ݵĸ߶�
	 * @info �ûص�ֻ��������������Ⱦʱ�Żᱻ����
	 */
	virtual void onTEBOffscreenPaint(const void* buffer, uint32_t width, uint32_t height) {};


	/*********************************************************************************************
	 *
	 *										����Ϳѻ��ػص�
	 *
	 *********************************************************************************************/
	 /**
	  * �װ�ͼƬ״̬�ı�ص�
	  * @param boardId			�װ�ID
	  * @param url				�װ�ͼƬURL
	  * @param status			�µİװ�ͼƬ״̬
	  */
	virtual void onTEBImageStatusChanged(const char *boardId, const char *url, TEduBoardImageStatus status) {};

	/**
	 * ���ðװ屳��ͼƬ�ص�
	 * @param url				����SetBackgroundImageʱ�����URL
	 * @info ֻ�б��ص���SetBackgroundImageʱ���յ��ûص�
	 * @info �յ��ûص���ʾ����ͼƬ�Ѿ��ϴ������سɹ���������ʾ����
	 */
	virtual void onTEBSetBackgroundImage(const char *url) {};

	/**
	 * ���ðװ屳��H5״̬�ı�ص�
	 * @param boardId           �װ�ID
	 * @param url               �װ�ͼƬURL
	 * @param status            �µİװ�ͼƬ״̬
	 */
	virtual void onTEBBackgroundH5StatusChanged(const char *boardId, const char *url, TEduBoardBackgroundH5Status status) {};


	/*********************************************************************************************
	 *
	 *										�����װ�ҳ�����ص�
	 *
	 *********************************************************************************************/
	 /**
	  * ���Ӱװ�ҳ�ص�
	  * @param boardList		���ӵİװ�ҳID�б�ʹ�ú���Ҫ���е���Release�����ͷţ�SDK�ڲ��Զ��ͷţ�
	  * @param fileId			���ӵİװ�ҳ�������ļ�ID��Ŀǰ�汾ֻ����Ϊ#DEFAULT��
	  */
	virtual void onTEBAddBoard(const TEduBoardList *boardList, const char *fileId) {};

	/**
	 * ɾ���װ�ҳ�ص�
	 * @param boardList			ɾ���İװ�ҳID��ʹ�ú���Ҫ���е���Release�����ͷţ�SDK�ڲ��Զ��ͷţ�
	 * @param fileId			ɾ���İװ�ҳ�������ļ�ID��Ŀǰ�汾ֻ����Ϊ#DEFAULT��
	 */
	virtual void onTEBDeleteBoard(const TEduBoardList *boardList, const char *fileId) {};

	/**
	 * ��ת�װ�ҳ�ص�
	 * @param boardId			��ת���İװ�ҳID
	 * @param fileId			��ת���İװ�ҳ�������ļ�ID
	 */
	virtual void onTEBGotoBoard(const char *boardId, const char *fileId) {};


	/*********************************************************************************************
	 *
	 *										�ġ��ļ������ص�
	 *
	 *********************************************************************************************/
	 /**
	  * �����ļ��ص�
	  * @param fileId			���ӵ��ļ�ID
	  * @info �ļ��ϴ���ɺ�Żᴥ���ûص�
	  */
	virtual void onTEBAddFile(const char *fileId) {};

	/**
	 * ����H5����PPT�ļ��ص�
	 * @param fileId			���ӵ��ļ�ID
	 * @info �ļ�������ɺ�Żᴥ���ûص�
	 */
	virtual void onTEBAddH5PPTFile(const char *fileId) {};

	/**
	 * ɾ���ļ��ص�
	 * @param fileId			ɾ�����ļ�ID
	 */
	virtual void onTEBDeleteFile(const char *fileId) {};

	/**
	 * �л��ļ��ص�
	 * @param fileId			�л������ļ�ID
	 */
	virtual void onTEBSwitchFile(const char *fileId) {};

	/**
	 * �ļ��ϴ����Ȼص�
	 * @param fileId            �����ϴ����ļ�ID
	 * @param currentBytes      ��ǰ���ϴ���С����λbytes
	 * @param totalBytes        �ļ��ܴ�С����λbytes
	 * @param uploadSpeed       �ļ��ϴ��ٶȣ���λbytes
	 * @param percent			�ļ��ϴ����ȣ�ȡֵ��Χ [0, 1]
	 */
	virtual void onTEBFileUploadProgress(const char *fileId, int currentBytes, int totalBytes, int uploadSpeed, double percent) {};

	/**
	 * �ļ��ϴ�״̬�ص�
	 * @param fileId            �����ϴ����ļ�ID
	 * @param status            �ļ��ϴ�״̬
	 * @param errorCode			�ļ��ϴ�������
	 * @param errorMsg			�ļ��ϴ�������Ϣ
	 */
	virtual void onTEBFileUploadStatus(const char *fileId, TEduBoardUploadStatus status, int errorCode, const char *errorMsg) {};

};


/*************************************************************************************************
 *
 * d. �װ������
 *
 *************************************************************************************************/
class TEduBoardController {
protected:
	/**
	 * ��������
	 */
	virtual ~TEduBoardController() {};

public:
    /*********************************************************************************************
     *
     *										һ���������̽ӿ�
     *
     *********************************************************************************************/

	/**
	 * �����¼��ص�����
	 * @param callback 			�¼��ص�����
	 * @warning ������Init֮ǰ���ø÷�����֧�ִ�����
	 */
	virtual void AddCallback(TEduBoardCallback * callback) = 0;

	/**
	 * ɾ���¼��ص�����
	 * @param callback 			�¼��ص�����
	 */
	virtual void RemoveCallback(TEduBoardCallback *callback) = 0;

    /**
     * ��ʼ���װ�
     * @param authParam 		��Ȩ����
     * @param roomId 			����ID
     * @param initParam	 	 	��ѡ������ָ�����ڳ�ʼ���װ��һϵ������ֵ
     * @info ���� initParam.timSync ָ���Ƿ�ʹ����Ѷ��IMSDK����ʵʱ����ͬ��
     * @info initParam.timSync == true ʱ���᳢�Է��������Ѷ��IMSDK��Ϊ����ͨ������ʵʱ�����շ���ֻʵ����Ϣ�շ�����ʼ���������Ȳ�����Ҫ�û�����ʵ�֣���Ŀǰ��֧��IMSDK 4.3.118�����ϰ汾
     * @warning ʹ����Ѷ��IMSDK����ʵʱ����ͬ��ʱ��ֻ֧��һ���װ�ʵ������������װ�ʵ�����ܵ���Ϳѻ״̬�쳣
     */
	virtual void Init(const TEduBoardAuthParam & authParam, uint32_t roomId, const TEduBoardInitParam &initParam = TEduBoardInitParam()) = 0;

	/**
	 * ��ȡ�װ���ȾView
	 * @param callback 			�¼��ص�����
	 * @warning ������Init֮ǰ���ø÷�����֧�ִ�����
	 */
	virtual WINDOW_HANDLE GetBoardRenderView() = 0;

	/**
	 * ��Ӱװ�ͬ������
	 * @param data 				���յ��ķ����������˷��͵�ͬ������
	 * @info �ýӿ����ڶ���װ�������ͬ����ʹ������IM��Ϊ����ͨ��ʱ������Ҫ���øýӿ�
	 */
	virtual void AddSyncData(const char * data) = 0;

	/**
	 * ���ðװ��Ƿ�������ͬ��
	 * @param enable    �Ƿ���
	 * @brief �װ崴����Ĭ�Ͽ�������ͬ�����ر�����ͬ�������ص����аװ��������ͬ����Զ�˺ͷ�����
	 */
	virtual void SetDataSyncEnable(bool enable) = 0;

	/**
	 * ��ȡ�װ��Ƿ�������ͬ��
	 * @return �Ƿ�������ͬ����true ��ʾ������false ��ʾ�ر�
	 */
	virtual bool IsDataSyncEnable() = 0;

    /**
     * ���ðװ�
     * @info ���øýӿں󽫻�ɾ�����еİװ�ҳ���ļ�
     */
    virtual void Reset() = 0;

    /**
     * ���ðװ���ȾView��λ�úʹ�С
     * @param x                 Ҫ���õİװ���ȾView��λ��X����
     * @param y                 Ҫ���õİװ���ȾView��λ��Y����
     * @param width             Ҫ���õİװ���ȾView�Ŀ��
     * @param height            Ҫ���õİװ���ȾView�ĸ߶�
     * @info �װ���ȾView�и�����ʱ��(x, y) ָ������丸���ڵ�λ��
     */
    virtual void SetBoardRenderViewPos(int32_t x, int32_t y, uint32_t width, uint32_t height) = 0;

	/**
	 * ���ðװ�ʵ���Խӿ�
	 * @param apiExp			Ҫִ�еİװ����JS����
	 * @return JSִ�к�ķ���ֵת���������ַ���
	 */
	virtual const char * CallExperimentalAPI(const char * apiExp) = 0;


    /*********************************************************************************************
     *
     *										����Ϳѻ��ؽӿ�
     *
     *********************************************************************************************/

	 /**
	  * ���ðװ��Ƿ�����Ϳѻ
	  * @param enable 			�Ƿ�����Ϳѻ��true ��ʾ�װ����Ϳѻ��false ��ʾ�װ岻��Ϳѻ
	  * @info �װ崴����Ĭ��Ϊ����Ϳѻ״̬
	  */
	virtual void SetDrawEnable(bool enable) = 0;

    /**
     * ��ȡ�װ��Ƿ�����Ϳѻ
     * @return �Ƿ�����Ϳѻ��true ��ʾ�װ����Ϳѻ��false ��ʾ�װ岻��Ϳѻ
     */
    virtual bool IsDrawEnable() = 0;

    /**
     * �������аװ�ı���ɫ
     * @param color 			Ҫ���õ�ȫ�ֱ���ɫ
     * @info ���øýӿڽ��������аװ�ı���ɫ�����ı�
     * @info �´����װ��Ĭ�ϱ���ɫȡȫ�ֱ���ɫ
     */
	virtual void SetGlobalBackgroundColor(const TEduBoardColor &color) = 0;

    /**
	 * ��ȡ�װ�ȫ�ֱ���ɫ
	 * @return ȫ�ֱ���ɫ
	 */
    virtual TEduBoardColor GetGlobalBackgroundColor() = 0;

	/**
	 * ���õ�ǰ�װ�ҳ�ı���ɫ
	 * @param color 			Ҫ���õı���ɫ
	 * @info �װ�ҳ�����Ժ��Ĭ�ϱ���ɫ��SetDefaultBackgroundColor�ӿ��趨
	 */
	virtual void SetBackgroundColor(const TEduBoardColor & color) = 0;

    /**
     * ��ȡ��ǰ�װ�ҳ�ı���ɫ
     * @return ��ǰ�װ�ҳ�ı���ɫ
     */
    virtual TEduBoardColor GetBackgroundColor() = 0;

	/**
	 * ����Ҫʹ�õİװ幤��
	 * @param type 				Ҫ���õİװ幤��
	 */
	virtual void SetToolType(TEduBoardToolType type) = 0;

    /**
     * ��ȡ����ʹ�õİװ幤��
     * @return ����ʹ�õİװ幤��
     */
    virtual TEduBoardToolType GetToolType() = 0;

	/**
	 * ���û�����ɫ
	 * @param color 			Ҫ���õĻ�����ɫ
	 * @info ������ɫ��������Ϳѻ����
	 */
	virtual void SetBrushColor(const TEduBoardColor & color) = 0;

    /**
     * ��ȡ������ɫ
     * @return ������ɫ
     */
    virtual TEduBoardColor GetBrushColor() = 0;

	/**
	 * ���û��ʴ�ϸ
	 * @param thin 				Ҫ���õĻ��ʴ�ϸ
	 * @info ���ʴ�ϸ��������Ϳѻ���ƣ�ʵ������ֵȡֵ(thin * �װ�ĸ߶� / 10000)px��������С��1px����Ϳѻ��������Ƚ���
	 */
	virtual void SetBrushThin(uint32_t thin) = 0;

    /**
     * ��ȡ���ʴ�ϸ
     * @return ���ʴ�ϸ
     */
    virtual uint32_t GetBrushThin() = 0;

	/**
	 * �����ı���ɫ
	 * @param color 			Ҫ���õ��ı���ɫ
	 */
	virtual void SetTextColor(const TEduBoardColor & color) = 0;

    /**
     * ��ȡ�ı���ɫ
     * @return �ı���ɫ
     */
    virtual TEduBoardColor GetTextColor() = 0;

	/**
	 * �����ı���С
	 * @param thin 				Ҫ���õ��ı���С
	 * @info ʵ������ֵȡֵ(size * �װ�ĸ߶� / 10000)px
	 */
	virtual void SetTextSize(uint32_t size) = 0;

    /**
     * ��ȡ�ı���С
     * @return �ı���С
     */
    virtual uint32_t GetTextSize() = 0;

    /**
     * �����ı���ʽ
     * @param style 				Ҫ���õ��ı���ʽ
     */
    virtual void SetTextStyle(TEduBoardTextStyle style) = 0;

    /**
     * ��ȡ�ı���ʽ
     * @return �ı���ʽ
     */
    virtual TEduBoardTextStyle GetTextStyle() = 0;

    /**
     * �����ı�����
     * @param family 				Ҫ���õ��ı�����
     */
    virtual void SetTextFamily(const char * family) = 0;

    /**
     * ��ȡ�ı�����
     * @return �ı�����
     */
    virtual const char * GetTextFamily() = 0;

	/**
	 * ��յ�ǰ�װ�ҳͿѻ
	 * @param clearBackground 	�Ƿ�ͬʱ��ձ���ɫ�Լ�����ͼƬ
	 */
	virtual void Clear(bool clearBackground = false) = 0;

    /**
     * ���õ�ǰ�װ�ҳ�ı���ͼƬ
     * @param url 				Ҫ���õı���ͼƬURL�������ʽΪUTF8
     * @param mode				Ҫʹ�õ�ͼƬ������ģʽ
     * @info ��URL��һ����Ч�ı����ļ���ַʱ�����ļ��ᱻ�Զ��ϴ���COS
     */
    virtual void SetBackgroundImage(const char * url, TEduBoardImageFitMode mode) = 0;

    /**
	 * ���õ�ǰ�װ�ҳ�ı���H5ҳ��
	 * @param url				Ҫ���õı���H5ҳ��URL
	 * @info �ýӿ���SetBackgroundImage�ӿڻ���
     * @warning Ŀǰ�汾�ù�����δʵ��
	 */
    virtual void SetBackgroundH5(const char * url) = 0;

	/**
	 * ������ǰ�װ�ҳ��һ�ζ���
	 */
	virtual void Undo() = 0;

	/**
	 * ������ǰ�װ�ҳ��һ�γ���
	 */
	virtual void Redo() = 0;


    /*********************************************************************************************
     *
     *										�����װ�ҳ�����ӿ�
     *
     *********************************************************************************************/
	 /**
	  * ����һҳ�װ�
	  * @param url				Ҫʹ�õı���ͼƬURL�������ʽΪUTF8��Ϊnullptr��ʾ��ָ������ͼƬ
	  * @return �װ�ID
	  * @info ����ֵ�ڴ���SDK�ڲ������û�����Ҫ�Լ��ͷ�
	  * @warning �װ�ҳ�ᱻ��ӵ�Ĭ���ļ����ļ�IDΪ#DEFAULT)�������ϴ����ļ��޷���Ӱװ�ҳ
	  */
	virtual const char * AddBoard(const char * url = nullptr) = 0;

	/**
	 * ɾ��һҳ�װ�
	 * @param boardId			Ҫɾ���İװ�ID��Ϊnullptr��ʾɾ����ǰҳ
	 * @warning ֻ����ɾ��Ĭ���ļ����ļ�IDΪ#DEFAULT���ڵİװ�ҳ����Ĭ�ϰװ�ҳ���װ�IDΪ#DEFAULT���޷�ɾ��
	 */
	virtual void DeleteBoard(const char * boardId = nullptr) = 0;

    /**
     * ��һ��
     * @info ÿ��Step��ӦPPT��һ������Ч��������ǰû����չʾ�Ķ���Ч������ýӿڵ��ûᵼ����ǰ��ҳ
     */
    virtual void PrevStep() = 0;

    /**
     * ��һ��
     * @info ÿ��Step��ӦPPT��һ������Ч��������ǰû��δչʾ�Ķ���Ч������ýӿڵ��ûᵼ�����ҳ
     */
    virtual void NextStep() = 0;

	/**
	 * ��ǰ��ҳ
	 * @param resetStep			ָ������ָ��ҳ�Ժ��Ƿ�����PPT��������
	 * @info ����ǰ�װ�ҳΪ��ǰ�ļ��ĵ�һҳ����ýӿڵ�����Ч
	 */
	virtual void PrevBoard(bool resetStep = false) = 0;

	/**
	 * ���ҳ
	 * @param resetStep			ָ������ָ��ҳ�Ժ��Ƿ�����PPT��������
	 * @info ����ǰ�װ�ҳΪ��ǰ�ļ������һҳ����ýӿڵ�����Ч
	 */
	virtual void NextBoard(bool resetStep = false) = 0;

	/**
	 * ��ת��ָ���װ�ҳ
	 * @param boardId			Ҫ��ת���İװ�ҳID
	 * @param resetStep			ָ������ָ��ҳ�Ժ��Ƿ�����PPT��������
	 * @info ������ת�������ļ��İװ�ҳ
	 */
	virtual void GotoBoard(const char * boardId, bool resetStep = false) = 0;

	/**
	 * ��ȡ��ǰ�װ�ҳID
	 * @return ��ǰ�װ�ҳID
	 * @info ����ֵ�ڴ���SDK�ڲ������û�����Ҫ�Լ��ͷ�
	 */
	virtual const char * GetCurrentBoard() = 0;

	/**
	 * ��ȡ�����ļ��İװ��б�
	 * @return �����ļ��İװ��б�
	 * @warning ����ֵ����ʹ��ʱ����Ҫ����delete��������ص�����release�������ͷ��ڴ�ռ��
	 */
	virtual TEduBoardList *GetBoardList() = 0;

	/**
	 * ���õ�ǰ�װ�ҳ��߱�
	 * @param ratio				Ҫ���õİװ��߱�
	 * @info ��ʽ��: "4:3"��"16:9"
	 */
    virtual void SetBoardRatio(const char *ratio) = 0;

	/**
	 * ��ȡ��ǰ�װ�ҳ��߱�
	 * @return �װ��߱ȣ���ʽ��SetBoardRatio�ӿڲ�����ʽһ��
	 */
	virtual const char * GetBoardRatio() = 0;

	/**
	 * ���õ�ǰ�װ�ҳ���ű���
	 * @param scale				Ҫ���õİװ����ű���
	 * @info ֧�ַ�Χ: [100��300]��ʵ�����ű�Ϊ: scale/100
	 */
	virtual void SetBoardScale(uint32_t scale) = 0;

	/**
	 * ��ȡ��ǰ�װ�ҳ���ű���
	 * @return �װ����ű�������ʽ��SetBoardScale�ӿڲ�����ʽһ��
	 */
	virtual uint32_t GetBoardScale() = 0;

	/**
	 * ���ðװ���������Ӧģʽ
	 * @param mode				Ҫ���õİװ���������Ӧģʽ
	 * @info ��������Ӧģʽ���Ӱ�����к����װ����ݲ���,��Ӱ��ӿڰ�����AddFile��AddH5PPTFile
	 */
	virtual void SetBoardContentFitMode(TEduBoardContentFitMode mode) = 0;

	/**
	 * ��ȡ�װ���������Ӧģʽ
	 * @return �װ���������Ӧģʽ
	 */
	virtual TEduBoardContentFitMode GetBoardContentFitMode() = 0;


    /*********************************************************************************************
     *
     *										�ġ��ļ������ӿ�
     *
     *********************************************************************************************/
	 /**
	  * �����ļ�
	  * @param path				Ҫ���ӵ��ļ�·���������ʽΪUTF8
	  * @return �ļ�ID
	  * @info ֧�� PPT��PDF��Word��Excel
	  * @info ��pathָ��һ����Ч�ı����ļ�ʱ��SDK���Ƚ��ļ��ϴ���COS����ִ�к�����������ʱ�ᴥ���ļ��ϴ���ػص�
	  * @info ��path����һ����Ч�ı����ļ�·������ᱻ����URL����URL����ָ����Ѷ��COS�ļ�·��������ӿڵ�����Ч
	  * @info �ļ������ɺ󣬽��Զ��л������ļ�
	  * @warning ���յ���Ӧ��onTEBAddFile�ص�ǰ���޷��÷��ص��ļ�ID��ѯ���ļ���Ϣ
	  */
	virtual const char * AddFile(const char * path) = 0;

    /**
     * ����H5����PPT�ļ�
     * @param url				Ҫ���ӵ�H5����PPT��URL
	 * @return �ļ�ID
     * @info ���øýӿں�SDK���ں�̨����H5���أ��ڼ��û������������������������سɹ���ʧ�ܺ�ᴥ����Ӧ�ص�
     * @info H5���سɹ��󣬽��Զ��л������ļ�
     * @warning �������URL�ظ�ʱ���ļ�ID����Ϊ���ַ���
	 * @warning ���յ���Ӧ��onTEBAddH5PPTFile�ص�ǰ���޷��÷��ص��ļ�ID��ѯ���ļ���Ϣ
     */
    virtual const char * AddH5PPTFile(const char * url) = 0;

	/**
	 * ɾ���ļ�
	 * @param fileId			Ҫɾ�����ļ�ID
	 * @info �ļ�IDΪnullptrʱ��ʾ��ǰ�ļ���Ĭ���ļ��޷�ɾ��
	 */
	virtual void DeleteFile(const char * fileId) = 0;

	/**
	 * �л��ļ�
	 * @param fileId			Ҫ�л������ļ�ID
	 * @info �ļ�IDΪ�����Ϊnullptr����ַ����������ļ��л�ʧ��
	 */
	virtual void SwitchFile(const char * fileId) = 0;

    /**
     * ��ȡ��ǰ�ļ�ID
     * @return ��ǰ�ļ�ID
     */
    virtual const char * GetCurrentFile() = 0;

	/**
	 * ��ȡ�װ���ָ���ļ����ļ���Ϣ
	 * @return �ļ���Ϣ
	 * @warning ÿ�ε��øýӿڵķ���ֵ���ݶ�ָ��ͬһ���ڴ棬����Ҫ���淵����Ϣ�������õ�����ֵ��ʱ������
	 */
	virtual TEduBoardFileInfo GetFileInfo(const char *fileId) = 0;

	/**
	 * ��ȡ�װ����ϴ��������ļ����ļ���Ϣ�б�
	 * @return �ļ���Ϣ�б�
	 * @warning ����ֵ����ʹ��ʱ����Ҫ����delete��������ص�����release�������ͷ��ڴ�ռ��
	 */
	virtual TEduBoardFileInfoList * GetFileInfoList() = 0;

	/**
	 * ��ȡָ���ļ��İװ�ID�б�
	 * @param fileId			�ļ�ID
	 * @return �װ�ID�б�
	 * @warning ����ֵ����ʹ��ʱ����Ҫ����delete��������ص�����release�������ͷ��ڴ�ռ��
	 */
	virtual TEduBoardList * GetFileBoardList(const char * fileId) = 0;

	/**
	 * ���ָ���ļ������аװ�Ϳѻ
	 * @param fileId			�ļ�ID
	 */
	virtual void ClearFileDraws(const char * fileId) = 0;
};
