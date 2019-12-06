/**
 * @file TEduBoard.h
 * @brief ��Ѷ�ƻ����װ�SDK for Window/Linux
 * @version 2.4.0.60
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
#include <ostream>

class TEduBoardController;

/**
 * @defgroup ctrl TEduBoardController
 * �װ幦�ܵ���Ҫ�ӿ���
 */

/**
 * @defgroup callback TEduBoardCallback
 * �װ幦�ܵĻص��ӿ���
 */

/**
 * @defgroup def �ؼ����Ͷ���
 */

/**
 * @defgroup code ������
 */

#ifdef __cplusplus
extern "C" {
#endif
    /// @name ��������ʵ��
    /// @{

    /**
     * @ingroup ctrl
     * @brief �����װ������ʵ��
     * @param disableCefInit                �Ƿ����CEF��ܳ�ʼ����ͨ����Ĭ��ֵ����
     * @param cefRenderPath                 ʹ��SDK�ڲ���CEF��ʼ��ʱ������ָ���Զ���Render���̿�ִ�г����·����UTF8���룬Ϊ�ջ�nullptr��ʾʹ��SDK����Render����
     * @return �װ������ʵ��ָ��
     * @warning �ýӿڱ��������̵߳���
     * @note ����SDK����CEF���(BSD-licensed)ʵ�֣������ĳ�����Ҳʹ����CEF��ܣ����ܻ���ڳ�ͻ������Ϊ���ṩ�˳�ͻ���������
     *      1. ѡ���������ַ����е�һ���������Լ���Render����
     *          - �� disableCefInit = false��cefRenderPath ָ�����Լ���Render����
     *          - �� disableCefInit = true������ʵ��CEF��ʼ��
     *      2. ������˵����������Render�����ڵ���SDK��RenderProcessHandler
     *          - Render������������ýӿڻ�ȡһ��sdkHandlerʵ����CefRefPtr<CefRenderProcessHandler> sdkHandler = (CefRenderProcessHandler*)GetTEduBoardRenderProcessHandler();
     *          - ��Render���̵�CefApp����дGetRenderProcessHandler������ÿ�ζ���������sdkHandler
     *          - ������Ҫ�Զ���CefRenderProcessHandler���ڶ����ɷ����Զ���Handler��Ȼ�����Զ���Handler�����漸�������У�����sdkHandler�Ķ�Ӧ����
     *              - OnBrowserCreated
     *              - OnBrowserDestroyed
     *              - OnContextCreated
     */
    EDUSDK_API TEduBoardController *CreateTEduBoardController(bool disableCefInit = false, const char *cefRenderPath = nullptr);

    /**
     * @ingroup ctrl
     * @brief ���ٰװ������
     * @param ppBoardController	            ָ��װ������ָ��
     *
     * ppBoardController ָ��ᱻ�Զ��ÿ�
     */
    EDUSDK_API void DestroyTEduBoardController(TEduBoardController **ppBoardController);

    /// @}


    /// @name ��־��ؽӿ�
    /// @{

    /**
     * @ingroup ctrl
     * @brief ��ȡSDK�汾��
     * @return SDK�汾��
     *
     * ����ֵ�ڴ���SDK�ڲ������û�����Ҫ�Լ��ͷ�
     */
    EDUSDK_API const char * GetTEduBoardVersion();

    /**
     * @ingroup ctrl
     * @brief ���ðװ���־�ļ�·��
     * @param logFilePath					Ҫ���õİװ���־�ļ�·���������ļ������ļ���׺��UTF8���룬Ϊ�ջ�nullptr��ʾʹ��Ĭ��·��
     * @return ���ðװ���־�ļ�·���Ƿ�ɹ�
     * @warning �ýӿڱ���Ҫ�ڵ�һ�ε���CreateTEduBoardController֮ǰ���ò���Ч�����򽫻�ʧ��
     *
     * - Ĭ��·����Windows��Ϊ��"%AppData%\\..\\Local\TIC\\teduboard.log"
     * - Ĭ��·����Linux��Ϊ��"~/TIC/teduboard.log"
     */
    EDUSDK_API bool SetTEduBoardLogFilePath(const char *logFilePath);

    /// @}

    /// @name �߼����ܽӿ�
    /// @{

    /**
     * @ingroup ctrl
     * @brief ���ðװ�������Ⱦ
     * @return ����������Ⱦ�Ƿ�ɹ�
     * @warning �ýӿڱ���Ҫ�ڵ�һ�ε���CreateTEduBoardController֮ǰ���ò���Ч�����򽫻�ʧ��
     *
     * ����������Ⱦʱ��SDK���ٴ����װ�VIEW������ͨ��onTEBOffscreenPaint�ص��ӿڽ��װ�������Ⱦ�����������׳�
     */
    EDUSDK_API bool EnableTEduBoardOffscreenRender();

    /**
     * @ingroup ctrl
     * @brief ��ȡSDK�ڲ���CefRenderProcessHandler
     * @return SDK�ڲ���CefRenderProcessHandler
     * @see CreateTEduBoardController
     *
     * ���ӿ���ϸʹ�÷����μ�CreateTEduBoardController�ӿ�˵��
     */
    EDUSDK_API void * GetTEduBoardRenderProcessHandler();

    /// @}

#ifdef __cplusplus
}
#endif

/**
 * @ingroup code
 * @brief �װ�����루���أ�
 */
enum TEduBoardErrorCode {
    TEDU_BOARD_ERROR_INIT				= 1,	///< ��ʼ��ʧ��
    TEDU_BOARD_ERROR_AUTH				= 2, 	///< �����Ȩʧ�ܣ����ȹ������
    TEDU_BOARD_ERROR_LOAD				= 3,	///< �ļ�����ʧ��
    TEDU_BOARD_ERROR_TIM_INVALID    	= 5,    ///< ��Ѷ��IMSDK������
    TEDU_BOARD_ERROR_HISTORYDATA		= 6,	///< ͬ����ʷ����ʧ��
    TEDU_BOARD_ERROR_RUNTIME			= 100,	///< �װ����д���
    TEDU_BOARD_ERROR_OOM                = 101,  ///< �ڴ�ľ�
};

/**
 * @ingroup code
 * @brief �װ�����루���棩
 */
enum TEduBoardWarningCode {
    TEDU_BOARD_WARNING_SYNC_DATA_PARSE_FAILED       = 1,    ///< ���յ������˵�ͬ�����ݽ�������
    TEDU_BOARD_WARNING_TIM_SEND_MSG_FAILED          = 2,    ///< ��Ѷ��IMSDK������Ϣʧ��
    TEDU_BOARD_WARNING_H5PPT_ALREADY_EXISTS			= 3,    ///< Ҫ��ӵ�H5PPT�Ѵ���
    TEDU_BOARD_WARNING_AUTO_RELOAD                  = 4,    ///< �װ巢���쳣�Զ����¼���
    TEDU_BOARD_WARNING_ILLEGAL_OPERATION            = 5,    ///< �װ���ʷ���ݼ������֮ǰ��ֹ����
    TEDU_BOARD_WARNING_H5FILE_ALREADY_EXISTS        = 6,    ///< ��Ҫ��ӵ�H5File�Ѵ���ʱ�׳��þ���
    TEDU_BOARD_WARNING_VIDEO_ALREADY_EXISTS         = 7,    ///< ��Ҫ��ӵ���Ƶ�Ѵ���ʱ�׳��þ���
};

/**
 * @ingroup def
 * @brief �װ幤��
 */
enum TEduBoardToolType {
    TEDU_BOARD_TOOL_TYPE_MOUSE			= 0,	///< ���
    TEDU_BOARD_TOOL_TYPE_PEN			= 1,	///< ����
    TEDU_BOARD_TOOL_TYPE_ERASER			= 2,	///< ��Ƥ��
    TEDU_BOARD_TOOL_TYPE_LASER			= 3,	///< �����
    TEDU_BOARD_TOOL_TYPE_LINE			= 4,	///< ֱ��
    TEDU_BOARD_TOOL_TYPE_OVAL			= 5,	///< ������Բ
    TEDU_BOARD_TOOL_TYPE_RECT			= 6,	///< ���ľ���
    TEDU_BOARD_TOOL_TYPE_OVAL_SOLID		= 7,	///< ʵ����Բ
    TEDU_BOARD_TOOL_TYPE_RECT_SOLID		= 8,	///< ʵ�ľ���
    TEDU_BOARD_TOOL_TYPE_POINT_SELECT	= 9,	///< ��ѡ����
    TEDU_BOARD_TOOL_TYPE_RECT_SELECT    = 10,	///< ��ѡ����
    TEDU_BOARD_TOOL_TYPE_TEXT			= 11,	///< �ı�����
    TEDU_BOARD_TOOL_TYPE_ZOOM_DRAG		= 12,	///< �����ƶ��װ幤��
};

/**
 * @ingroup def
 * @brief �װ�ͼƬ������ģʽ
 * 
 * ���Կ�Ȼ�׼�ȱ����Ŵ������;���ͬ���ж���Ч��һ�£����Ը߶Ȼ�׼�ȱ����Ŵ���Ӷ��;ӵ�ͬ���ж���Ч��һ��
 */
enum TEduBoardImageFitMode {
    TEDU_BOARD_IMAGE_FIT_MODE_CENTER	= 0,	///< �Կ�Ȼ��߸߶�Ϊ��׼���ж���ȱ����Ŵ�
    TEDU_BOARD_IMAGE_FIT_MODE_LEFT		= 4,	///< �Կ�Ȼ��߸߶�Ϊ��׼�����ȱ����Ŵ�
    TEDU_BOARD_IMAGE_FIT_MODE_TOP		= 5,	///< �Կ�Ȼ��߸߶�Ϊ��׼������ȱ����Ŵ�
    TEDU_BOARD_IMAGE_FIT_MODE_RIGHT		= 6,	///< �Կ�Ȼ��߸߶�Ϊ��׼�Ҷ���ȱ����Ŵ�
    TEDU_BOARD_IMAGE_FIT_MODE_BOTTOM	= 7,	///< �Կ�Ȼ��߸߶�Ϊ��׼�׶���ȱ����Ŵ�
};

/**
 * @ingroup def
 * @brief �װ�ͼƬ״̬
 */
enum TEduBoardImageStatus {
    TEDU_BOARD_IMAGE_STATUS_LOADING		= 1,	///< ����ͼƬ���ڼ���
    TEDU_BOARD_IMAGE_STATUS_LOAD_DONE	= 2,	///< ����ͼƬ�������
    TEDU_BOARD_IMAGE_STATUS_LOAD_ABORT	= 3,	///< ����ͼƬ�����ж�
    TEDU_BOARD_IMAGE_STATUS_LOAD_ERROR	= 4,	///< ����ͼƬ���ش���
};

/**
 * @ingroup def
 * @brief �װ��ı���ʽ
 */
enum TEduBoardTextStyle{
    TEDU_BOARD_TEXT_STYLE_NORMAL		= 0,	///< ������ʽ
    TEDU_BOARD_TEXT_STYLE_BOLD			= 1,	///< ������ʽ
    TEDU_BOARD_TEXT_STYLE_ITALIC		= 2,	///< б����ʽ
    TEDU_BOARD_TEXT_STYLE_BOLD_ITALIC	= 3,	///< ��б����ʽ
};

/**
 * @ingroup def
 * @brief �װ��ϴ�״̬
 */
enum TEduBoardUploadStatus{
    TEDU_BOARD_UPLOAD_STATUS_SUCCEED	= 1,	///< �ϴ��ɹ�
    TEDU_BOARD_UPLOAD_STATUS_FAILED		= 2,	///< �ϴ�ʧ��
};

/**
 * @ingroup def
 * @brief H5����״̬
 */
enum TEduBoardBackgroundH5Status{
    TEDU_BOARD_BACKGROUND_H5_STATUS_LOADING        = 1,    ///< H5�������ڼ���
    TEDU_BOARD_BACKGROUND_H5_STATUS_LOAD_FINISH    = 2,    ///< H5�����������
};

/**
 * @ingroup def
 * @brief �װ���������Ӧģʽ
 * 
 * ���ݰ���ͼƬ���ļ���PPT����
 */
enum TEduBoardContentFitMode {
    TEDU_BOARD_CONTENT_FIT_MODE_NONE 			= 0,		///< ��ʹ����������Ӧ��Ĭ��ģʽ�����Զ������װ��߱ȣ����ݵȱ������ž�����ʾ�����ݿ��<=�װ���
    TEDU_BOARD_CONTENT_FIT_MODE_CENTER_INSIDE 	= 1,		///< �Զ������װ��߱�������һ�£����������װ壬�װ�ȱ������ž�����ʾ���װ���<=�������
    TEDU_BOARD_CONTENT_FIT_MODE_CENTER_COVER 	= 2,		///< �Զ������װ��߱�������һ�£����������װ壬�װ�ȱ������ž�����ʾ���װ���>=�������
};

/**
 * @ingroup def
 * @brief ֱ������
 */
enum TEduBoardLineType {
    TEDU_BOARD_LINE_TYPE_SOLID    = 1,    ///< ʵ��
    TEDU_BOARD_LINE_TYPE_DOTTED   = 2,    ///< ����
};

/**
 * @ingroup def
 * @brief ��ͷ����
 */
enum TEduBoardArrowType {
    TEDU_BOARD_ARROW_TYPE_NONE 		= 1,	///< �޼�ͷ
    TEDU_BOARD_ARROW_TYPE_NORMAL	= 2, 	///< ��ͨ��ͷ
    TEDU_BOARD_ARROW_TYPE_SOLID 	= 3, 	///< ʵ�ļ�ͷ
};

/**
 * @ingroup def
 * @brief ��Բ����ģʽ
 */
enum TEduBoardOvalDrawMode {
    TEDU_BOARD_OVAL_DRAW_MODE_FIX_START     = 1,    ///< �̶���ʼ�㣬��ʼ����յ���е�ΪԲ��
    TEDU_BOARD_OVAL_DRAW_MODE_FIX_CENTER    = 2,    ///< �̶�Բ�ģ���ʼ��ΪԲ��
};

/**
 * @ingroup def
 * @brief �ļ�ת��״̬
 */
enum TEduBoardFileTranscodeStatus {
    TEDU_BOARD_FILE_TRANSCODE_ERROR         = 1,    ///< ת�����
    TEDU_BOARD_FILE_TRANSCODE_UPLOADING     = 2,    ///< �ļ��ϴ���
    TEDU_BOARD_FILE_TRANSCODE_CREATED       = 3,    ///< ����ת������
    TEDU_BOARD_FILE_TRANSCODE_QUEUED        = 4,    ///< �Ŷ���
    TEDU_BOARD_FILE_TRANSCODE_PROCESSING    = 5,    ///< ת����
    TEDU_BOARD_FILE_TRANSCODE_FINISHED      = 6,    ///< ת�����
};

/**
 * @ingroup def
 * @brief H5�ļ�״̬
*/
enum TEduBoardH5FileStatus {
    TEDU_BOARD_H5_FILE_STATUS_LOADING       = 1,    ///< ������
    TEDU_BOARD_H5_FILE_STATUS_LOADED        = 2,    ///< �������
};

/**
 * @ingroup def
 * @brief ��Ƶ�ļ�״̬
*/
enum TEduBoardVideoStatus {
    TEDU_BOARD_VIDEO_STATUS_ERROR       = 1,    ///< ���Ŵ���
    TEDU_BOARD_VIDEO_STATUS_LOADING     = 2,    ///< ������
    TEDU_BOARD_VIDEO_STATUS_LOADED      = 3,    ///< �������
    TEDU_BOARD_VIDEO_STATUS_PLAYED      = 4,    ///< ��ʼ����
    TEDU_BOARD_VIDEO_STATUS_PLAYING     = 5,    ///< ������
    TEDU_BOARD_VIDEO_STATUS_PAUSED      = 6,    ///< ��ͣ
    TEDU_BOARD_VIDEO_STATUS_SEEKED      = 7,    ///< ��ת
    TEDU_BOARD_VIDEO_STATUS_ENDED       = 8,    ///< ����
};

/**
 * @ingroup def
 * @brief �װ���Ȩ����
 */
struct TEduBoardAuthParam {
    uint32_t sdkAppId;      ///< SDKAppID
    const char * userId;    ///< �û�ID
    const char * userSig;   ///< �û�ǩ��

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
 * @ingroup def
 * @brief ��ɫ����
 */
struct TEduBoardColor {
    uint8_t red = 0;        ///< ��ɫ����
    uint8_t green = 0;      ///< ��ɫ����
    uint8_t blue = 0;       ///< ��ɫ����
    uint8_t alpha = 0;      ///< ͸������

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
 * @ingroup def
 * @brief �װ��ʼ������
 */
struct TEduBoardInitParam {
    bool progressEnable;					///< �Ƿ�����SDK����Loadingͼ��
    const char * ratio;                     ///< Ĭ�ϰװ��߱ȣ��ɴ���ʽ�硰4:3������16:9�����ַ�����
    bool drawEnable;                        ///< �Ƿ�����Ϳѻ
    TEduBoardColor globalBackgroundColor;   ///< ȫ�ֱ���ɫ
    TEduBoardToolType toolType;			    ///< �װ幤��
    TEduBoardColor brushColor;              ///< ������ɫ
    uint32_t brushThin;						///< ���ʴ�ϸ
    TEduBoardColor textColor;               ///< �ı���ɫ
    uint32_t textSize;                      ///< �ı���ϸ
    TEduBoardTextStyle textStyle;           ///< �ı���ʽ
    bool timSync;                           ///< �Ƿ�ʹ����Ѷ��IMSDK����ʵʱ����ͬ��
    bool dataSyncEnable;					///< �Ƿ���������ͬ�������ú󽫵��±��ذװ�������ᱻͬ����Զ��
    uint32_t preloadDepth;					///< ͼƬԤ������ȣ�Ĭ��ֵ5����ʾԤ���ص�ǰҳǰ��5ҳ��ͼƬ
    double smoothLevel;						///< �ʼ�ƽ��ϵ����Ĭ��0.1����Χ [0��1]
    TEduBoardContentFitMode contentFitMode; ///< ��������Ӧģʽ
    const char * experimental;				///< ʵ���Բ��������ֵ�����JSON��

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
 * @ingroup def
 * @brief ֱ����ʽ
 */
struct TEduBoardLineStyle {
    TEduBoardLineType lineType;			///< ֱ������
    TEduBoardArrowType startArrowType;	///< ����ͷ����
    TEduBoardArrowType endArrowType; 	///< �յ��ͷ����

    TEduBoardLineStyle()
            : lineType(TEDU_BOARD_LINE_TYPE_SOLID)
            , startArrowType(TEDU_BOARD_ARROW_TYPE_NONE)
            , endArrowType(TEDU_BOARD_ARROW_TYPE_NONE)
    {

    }
};

/**
 * @ingroup def
 * @brief �����ʽ
 */
struct TEduBoardCursorIcon{
    const char *cursor; ///< ������������ָ����ʽ����ȡֵ�ο��ĵ���https://developer.mozilla.org/zh-CN/docs/Web/CSS/cursor
    const char *url;    ///< �Զ������ָ����ʽ��URL����ʽ���Ʋο��ĵ���https://developer.mozilla.org/zh-CN/docs/Web/CSS/cursor/url
    uint32_t offsetX;   ///< �Զ������ָ����ʽ�ĺ���ƫ��
    uint32_t offsetY;   ///< �Զ������ָ����ʽ������ƫ��

    TEduBoardCursorIcon()
        : cursor("none")
        , url(nullptr)
        , offsetX(0)
        , offsetY(0)
    {

    }
};

/**
 * @ingroup def
 * @brief �ļ�ת�����
 */
struct TEduBoardTranscodeConfig {
    const char *minResolution;	        ///< ָ��ת������С�ֱ��ʣ����������ת���������ȣ���ʽ��960x540�������x�ָ�
    bool isStaticPPT;                   ///< ָ������PPT�ļ��Ƿ����þ�̬ת�루תΪ��̬ͼƬ����Ĭ��תΪH5������ת���ʱ�ϳ���
    const char *thumbnailResolution;    ///< ָ��Ϊ�ļ���������ͼ�ķֱ��ʣ�Ĭ�ϲ���������ͼ����������ͼ���Ӷ���ת���ʱ������ʽ��200x200�������x�ָ�

    TEduBoardTranscodeConfig()
            : minResolution(nullptr)
            , isStaticPPT(false)
            , thumbnailResolution(nullptr)
    {
    }
};

/**
 * @ingroup def
 * @brief �ļ�ת����
 */
struct TEduBoardTranscodeFileResult {
    char taskId[32];                        ///< ����ID
    TEduBoardFileTranscodeStatus status;    ///< ת��״̬
    double progress;                        ///< ת����ȣ�ȡֵ��Χ [0, 100]
    char title[256];		                ///< �ļ�����
    char resolution[32];	                ///< �ļ��ֱ���
    uint32_t pages;			                ///< �ļ���ҳ��
    char url[1024];	                        ///< ת����URL
    char thumbnailResolution[32];           ///< Ϊ�ļ���������ͼ�ķֱ���
    char thumbnailUrl[1024];	            ///< Ϊ�ļ���������ͼURL

    TEduBoardTranscodeFileResult()
            : taskId()
            , status(TEDU_BOARD_FILE_TRANSCODE_CREATED)
            , progress(0)
            , title()
            , resolution()
            , pages(0)
            , url()
            , thumbnailResolution()
            , thumbnailUrl()
    {
    }
};

/**
 * @ingroup def
 * @brief �װ���Ϣ
 */
struct TEduBoardInfo {
    const char * boardId;		        ///< �װ�ID
    const char * backgroundUrl;		    ///< �װ屳��ͼ���߱���H5ҳ���URL
    TEduBoardColor backgroundColor;     ///< �װ屳��ɫ

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
 * @ingroup def
 * @brief �װ���Ϣ�б�
 */
class TEduBoardInfoList {
protected:
    virtual ~TEduBoardInfoList() {};

public:
    /**
     * @brief ��ȡ�װ���Ϣ����
     * @return �װ���Ϣ����
     */
    virtual uint32_t GetCount() const = 0;

    /**
     * @brief ��ȡָ���İװ���Ϣ
     * @param index ������ȡֵ��Χ [0, �װ����)
     * @return �װ���Ϣ
     */
    virtual TEduBoardInfo GetBoardInfo(uint32_t index) const = 0;
};

/**
 * @ingroup def
 * @brief �ļ���Ϣ
 */
struct TEduBoardFileInfo {
    const char * fileId;						///< �ļ�ID
    const char * title;							///< �ļ���
    const char * downloadUrl; 					///< �ļ����ص�ַ
    uint32_t pageIndex;							///< �ļ���ǰ��ʾ��ҳ��
    uint32_t pageCount;							///< �ļ�ҳ��
    const TEduBoardInfoList *boardInfoList;		///< �װ���Ϣ�б�

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
 * @ingroup def
 * @brief �ļ���Ϣ�б�
 */
class TEduBoardFileInfoList {
protected:
    virtual ~TEduBoardFileInfoList() {};

public:
    /**
     * @brief ��ȡ�ļ���Ϣ����
     * @return �ļ���Ϣ����
     */
    virtual uint32_t GetCount() const = 0;

    /**
     * @brief ��ȡָ�����ļ���Ϣ
     * @param index ������ȡֵ��Χ [0, �ļ�����)
     * @return �ļ���Ϣ
     */
    virtual TEduBoardFileInfo GetFileInfo(uint32_t index) const = 0;

    /**
     * @brief �ͷ��ļ���Ϣ�б�
     * @warning �ļ���Ϣ�б�ʹ����֮����ص��øýӿ����ͷ��ڴ�
     */
    virtual void Release() = 0;
};

/**
 * @ingroup def
 * @brief �ַ����б�
 */
class TEduBoardStringList {
protected:
    virtual ~TEduBoardStringList() {};

public:
    /**
     * @brief ��ȡ�ַ�������
     * @return �ַ�������
     */
    virtual uint32_t GetCount() const = 0;

    /**
     * @brief ��ȡָ�����ַ���
     * @param index ������ȡֵ��Χ [0, �ַ�������)
     * @return �ַ���
     * @warning ����ֵ�ڴ���SDK�ڲ���������Ҫ�û������ͷ�
     */
    virtual const char * GetString(uint32_t index) const = 0;

    /**
     * @brief �ͷ��ַ����б�
     * @warning �ַ����б�ʹ����֮����ص��øýӿ����ͷ��ڴ�
     */
    virtual void Release() = 0;
};


/**
 * @ingroup callback
 * @brief �װ��¼��ص��ӿ�
 */
struct TEduBoardCallback {
     /// @name ͨ���¼��ص�
     /// @{

     /**
      * @brief �װ����ص�
      * @param code				�����룬�μ�TEduBoardErrorCode����
      * @param msg				������Ϣ�������ʽΪUTF8
      * @see TEduBoardErrorCode
      */
    virtual void onTEBError(TEduBoardErrorCode code, const char *msg) = 0;

    /**
     * @brief �װ徯��ص�
     * @param code				�����룬�μ�TEduBoardWarningCode����
     * @param msg				������Ϣ�������ʽΪUTF8
     * @see TEduBoardWarningCode
     */
    virtual void onTEBWarning(TEduBoardWarningCode code, const char *msg) = 0;

    /// @}


    /// @name �������̻ص�
    /// @{

    /**
     * @brief �װ��ʼ����ɻص�
     *
     * �յ��ûص����ʾ�װ��Ѵ��ڿ���������״̬����ʱ�װ�Ϊ�հװװ壬��ʷ������δ��ȡ����
     */
    virtual void onTEBInit() = 0;

    /**
     * @brief �װ���ʷ����ͬ����ɻص�
     */
    virtual void onTEBHistroyDataSyncCompleted() {};

    /**
     * @brief �װ�ͬ�����ݻص�
     * @param data				�װ�ͬ�����ݣ�JSON��ʽ�ַ�����
     *
     * �յ��ûص�ʱ��Ҫ���ص�����ͨ������ͨ�����͸������������ˣ��������յ������AddSyncData�ӿڽ�������ӵ��װ���ʵ������ͬ��
     * �ûص����ڶ���װ�������ͬ����ʹ����Ѷ��IMSDK����ʵʱ����ͬ��ʱ�������յ��ûص�
     */
    virtual void onTEBSyncData(const char *data) {};

    /**
     * @brief �װ�ɳ���״̬�ı�ص�
     * @param canUndo			�װ嵱ǰ�Ƿ���ִ��Undo����
     */
    virtual void onTEBUndoStatusChanged(bool canUndo) {};

    /**
     * @brief �װ������״̬�ı�ص�
     * @param canRedo			�װ嵱ǰ�Ƿ���ִ��Redo����
     */
    virtual void onTEBRedoStatusChanged(bool canRedo) {};

    /**
     * @brief �װ�������Ⱦ�ص�
     * @param buffer            �װ��������ݣ���СΪwidth * height * 4�������԰װ����Ϸ�Ϊԭ������Ҵ��ϵ��°�BGRA����
     * @param width             �װ��������ݵĿ��
     * @param height            �װ��������ݵĸ߶�
     *
     * �ûص�ֻ��������������Ⱦʱ�Żᱻ����
     */
    virtual void onTEBOffscreenPaint(const void* buffer, uint32_t width, uint32_t height) {};

    /// @}


    /// @name Ϳѻ���ܻص�
    /// @{

     /**
      * @brief �װ�ͼƬ״̬�ı�ص�
      * @param boardId			�װ�ID
      * @param url				�װ�ͼƬURL
      * @param status			�µİװ�ͼƬ״̬
      */
    virtual void onTEBImageStatusChanged(const char *boardId, const char *url, TEduBoardImageStatus status) {};

    /**
     * @brief ���ðװ屳��ͼƬ�ص�
     * @param url				����SetBackgroundImageʱ�����URL
     *
     * ֻ�б��ص���SetBackgroundImageʱ���յ��ûص�
     * �յ��ûص���ʾ����ͼƬ�Ѿ��ϴ������سɹ���������ʾ����
     */
    virtual void onTEBSetBackgroundImage(const char *url) {};

    /**
     * @brief ���ðװ屳��H5״̬�ı�ص�
     * @param boardId           �װ�ID
     * @param url               �װ�ͼƬURL
     * @param status            �µİװ�ͼƬ״̬
     */
    virtual void onTEBBackgroundH5StatusChanged(const char *boardId, const char *url, TEduBoardBackgroundH5Status status) {};

    /// @}


    /// @name �װ�ҳ�����ص�
    /// @{

    /**
     * @brief ���Ӱװ�ҳ�ص�
     * @param boardList		���ӵİװ�ҳID�б�ʹ�ú���Ҫ���е���Release�����ͷţ�SDK�ڲ��Զ��ͷţ�
     * @param fileId			���ӵİװ�ҳ�������ļ�ID��Ŀǰ�汾ֻ����Ϊ#DEFAULT��
     */
    virtual void onTEBAddBoard(const TEduBoardStringList *boardList, const char *fileId) {};

    /**
     * @brief ɾ���װ�ҳ�ص�
     * @param boardList			ɾ���İװ�ҳID��ʹ�ú���Ҫ���е���Release�����ͷţ�SDK�ڲ��Զ��ͷţ�
     * @param fileId			ɾ���İװ�ҳ�������ļ�ID��Ŀǰ�汾ֻ����Ϊ#DEFAULT��
     */
    virtual void onTEBDeleteBoard(const TEduBoardStringList *boardList, const char *fileId) {};

    /**
     * @brief ��ת�װ�ҳ�ص�
     * @param boardId			��ת���İװ�ҳID
     * @param fileId			��ת���İװ�ҳ�������ļ�ID
     */
    virtual void onTEBGotoBoard(const char *boardId, const char *fileId) {};

    /**
     * @brief �װ�ҳ���������ص�
     * @param currentStep		��ǰ�װ�ҳ����������ȡֵ��Χ [0, totalStep)
     * @param totalStep			��ǰ�װ�ҳ�����ܲ���
     */
    virtual void onTEBGotoStep(uint32_t currentStep, uint32_t totalStep) {};

    /// @}


    /// @name �ļ������ص�
    /// @{

    /**
     * @brief �ļ�ת����Ȼص�
     * @param path              ����ת��ı����ļ�·��
     * @param errorCode         �ļ�ת������룬���쳣ʱΪ���ַ��� ""
     * @param errorMsg          �ļ�ת�������Ϣ�����쳣ʱΪ���ַ��� ""
     * @param result            �ļ�ת����
     */
    virtual void onTEBFileTranscodeProgress(const char *path, const char *errorCode, const char *errorMsg, const TEduBoardTranscodeFileResult &result) {};

    /**
     * @brief ����ת���ļ��ص�
     * @param fileId			���ӵ��ļ�ID
     *
     * �ļ�������ɺ�Żᴥ���ûص�
     */
    virtual void onTEBAddTranscodeFile(const char *fileId) {};

    /**
     * @brief ��Ƶ�ļ�״̬�ص�
     * @param fileId            �ļ�ID
     * @param status            �ļ�״̬
     * @param progress          ��ǰ���ȣ��룩����֧��mp4��ʽ��
     * @param duration          ��ʱ�����룩����֧��mp4��ʽ��
     */
    virtual void onTEBVideoStatusChanged(const char *fileId, TEduBoardVideoStatus status, double progress, double duration) {};

    /**
     * @brief H5�ļ�״̬�ص�
     * @param fileId            �ļ�ID
     * @param status            �ļ�״̬
     */
    virtual void onTEBH5FileStatusChanged(const char *fileId, TEduBoardH5FileStatus status) {};

    /**
     * @brief ɾ���ļ��ص�
     * @param fileId			ɾ�����ļ�ID
     */
    virtual void onTEBDeleteFile(const char *fileId) {};

    /**
     * @brief �л��ļ��ص�
     * @param fileId			�л������ļ�ID
     */
    virtual void onTEBSwitchFile(const char *fileId) {};

    /**
     * @brief �ļ��ϴ����Ȼص�
     * @param fileId            �����ϴ����ļ�ID
     * @param currentBytes      ��ǰ���ϴ���С����λbytes
     * @param totalBytes        �ļ��ܴ�С����λbytes
     * @param uploadSpeed       �ļ��ϴ��ٶȣ���λbytes
     * @param percent			�ļ��ϴ����ȣ�ȡֵ��Χ [0, 1]
     */
    virtual void onTEBFileUploadProgress(const char *fileId, int currentBytes, int totalBytes, int uploadSpeed, double percent) {};

    /**
     * @brief �ļ��ϴ�״̬�ص�
     * @param fileId            �����ϴ����ļ�ID
     * @param status            �ļ��ϴ�״̬
     * @param errorCode			�ļ��ϴ�������
     * @param errorMsg			�ļ��ϴ�������Ϣ
     */
    virtual void onTEBFileUploadStatus(const char *fileId, TEduBoardUploadStatus status, int errorCode, const char *errorMsg) {};

    /// @}

};


/**
 * @ingroup ctrl
 * @brief �װ������
 */
class TEduBoardController {
protected:
    virtual ~TEduBoardController() {};

public:
    /// @name ���� TEduBoardCallback �ص�
    /// @{

    /**
     * @brief �����¼��ص�����
     * @param callback 			�¼��ص�����
     * @warning ������Init֮ǰ���ø÷�����֧�ִ�����
     */
    virtual void AddCallback(TEduBoardCallback * callback) = 0;

    /**
     * @brief ɾ���¼��ص�����
     * @param callback 			�¼��ص�����
     */
    virtual void RemoveCallback(TEduBoardCallback *callback) = 0;

    /// @}


    /// @name �������̽ӿ�
    /// @{

    /**
     * @brief ��ʼ���װ�
     * @param authParam 		��Ȩ����
     * @param roomId 			����ID
     * @param initParam	 	 	��ѡ������ָ�����ڳ�ʼ���װ��һϵ������ֵ
     * @warning ʹ����Ѷ��IMSDK����ʵʱ����ͬ��ʱ��ֻ֧��һ���װ�ʵ������������װ�ʵ�����ܵ���Ϳѻ״̬�쳣
     * 
     * ���� initParam.timSync ָ���Ƿ�ʹ����Ѷ��IMSDK����ʵʱ����ͬ��
     * initParam.timSync == true ʱ���᳢�Է��������Ѷ��IMSDK��Ϊ����ͨ������ʵʱ�����շ���ֻʵ����Ϣ�շ�����ʼ���������Ȳ�����Ҫ�û�����ʵ�֣���Ŀǰ��֧��IMSDK 4.3.118�����ϰ汾
     */
    virtual void Init(const TEduBoardAuthParam & authParam, uint32_t roomId, const TEduBoardInitParam &initParam = TEduBoardInitParam()) = 0;

    /**
     * @brief ��ȡ�װ���ȾView
     * @return �װ���ȾView
     */
    virtual WINDOW_HANDLE GetBoardRenderView() = 0;

    /**
     * @brief ��Ӱװ�ͬ������
     * @param data 				���յ��ķ����������˷��͵�ͬ������
     *
     * �ýӿ����ڶ���װ�������ͬ����ʹ������IM��Ϊ����ͨ��ʱ������Ҫ���øýӿ�
     */
    virtual void AddSyncData(const char * data) = 0;

    /**
     * @brief ���ðװ��Ƿ�������ͬ��
     * @param enable    �Ƿ���
     *
     * �װ崴����Ĭ�Ͽ�������ͬ�����ر�����ͬ�������ص����аװ��������ͬ����Զ�˺ͷ�����
     */
    virtual void SetDataSyncEnable(bool enable) = 0;

    /**
     * @brief ��ȡ�װ��Ƿ�������ͬ��
     * @return �Ƿ�������ͬ����true ��ʾ������false ��ʾ�ر�
     */
    virtual bool IsDataSyncEnable() = 0;

    /**
     * @brief ���ðװ�
     * 
     * ���øýӿں󽫻�ɾ�����еİװ�ҳ���ļ�
     */
    virtual void Reset() = 0;

    /**
     * @brief ���ðװ���ȾView��λ�úʹ�С
     * @param x                 Ҫ���õİװ���ȾView��λ��X����
     * @param y                 Ҫ���õİװ���ȾView��λ��Y����
     * @param width             Ҫ���õİװ���ȾView�Ŀ��
     * @param height            Ҫ���õİװ���ȾView�ĸ߶�
     * 
     * �װ���ȾView�и�����ʱ��(x, y) ָ������丸���ڵ�λ��
     */
    virtual void SetBoardRenderViewPos(int32_t x, int32_t y, uint32_t width, uint32_t height) = 0;

    /**
     * @brief ��ȡͬ��ʱ���
     * @return ���뼶ͬ��ʱ���
     */
    virtual uint64_t GetSyncTime() = 0;

    /**
     * @brief ͬ��Զ��ʱ���
     * @param userId			Զ���û�ID
     * @param timestamp			Զ���û����뼶ͬ��ʱ���
     */
    virtual void SyncRemoteTime(const char *userId, uint64_t timestamp) = 0;

    /**
     * @brief ���ðװ�ʵ���Խӿ�
     * @param apiExp			Ҫִ�еİװ����JS����
     * @return JSִ�к�ķ���ֵת���������ַ���
     */
    virtual const char * CallExperimentalAPI(const char * apiExp) = 0;

    /// @}


    /// @name Ϳѻ��ؽӿ�
    /// @{

    /**
     * @brief ���ðװ��Ƿ�����Ϳѻ
     * @param enable 			�Ƿ�����Ϳѻ��true ��ʾ�װ����Ϳѻ��false ��ʾ�װ岻��Ϳѻ
     *
     * �װ崴����Ĭ��Ϊ����Ϳѻ״̬
     */
    virtual void SetDrawEnable(bool enable) = 0;

    /**
     * @brief ��ȡ�װ��Ƿ�����Ϳѻ
     * @return �Ƿ�����Ϳѻ��true ��ʾ�װ����Ϳѻ��false ��ʾ�װ岻��Ϳѻ
     */
    virtual bool IsDrawEnable() = 0;

    /**
     * @brief �������������Щ�û����Ƶ�ͼ��
     * @param users             ָ������������û�����Ϊnullptr��ʾ��������
     * @param userCount         ָ��users�����������û�����
     * 
     * �ýӿڻ��������Ӱ�죺
     *    1. ERASER ����ֻ�ܲ���users�����г����û����Ƶ�Ϳѻ���޷����������˻��Ƶ�Ϳѻ
     *    2. POINTSELECT��SELECT ����ֻ��ѡ��users�����г����û����Ƶ�Ϳѻ���޷�ѡ�������˻��Ƶ�Ϳѻ
     *    3. clear �ӿ�ֻ���������ѡ��Ϳѻ�Լ�users�����г����û����Ƶ�Ϳѻ���޷���ձ����������˻��Ƶ�Ϳѻ
     *    4. �װ��������������δ�ڱ��б���ȷ�г��߶�����ȷ�����ܱ��ӿ�Ӱ��
     */
    virtual void SetAccessibleUsers(const char **users, uint32_t userCount) = 0;

    /**
     * @brief �������аװ�ı���ɫ
     * @param color 			Ҫ���õ�ȫ�ֱ���ɫ
     * 
     * ���øýӿڽ��������аװ�ı���ɫ�����ı�
     * �´����װ��Ĭ�ϱ���ɫȡȫ�ֱ���ɫ
     */
    virtual void SetGlobalBackgroundColor(const TEduBoardColor &color) = 0;

    /**
     * @brief ��ȡ�װ�ȫ�ֱ���ɫ
     * @return ȫ�ֱ���ɫ
     */
    virtual TEduBoardColor GetGlobalBackgroundColor() = 0;

    /**
     * @brief ���õ�ǰ�װ�ҳ�ı���ɫ
     * @param color 			Ҫ���õı���ɫ
     *
     * �װ�ҳ�����Ժ��Ĭ�ϱ���ɫ��SetDefaultBackgroundColor�ӿ��趨
     */
    virtual void SetBackgroundColor(const TEduBoardColor & color) = 0;

    /**
     * @brief ��ȡ��ǰ�װ�ҳ�ı���ɫ
     * @return ��ǰ�װ�ҳ�ı���ɫ
     */
    virtual TEduBoardColor GetBackgroundColor() = 0;

    /**
     * @brief ����Ҫʹ�õİװ幤��
     * @param type 				Ҫ���õİװ幤��
     */
    virtual void SetToolType(TEduBoardToolType type) = 0;

    /**
     * @brief ��ȡ����ʹ�õİװ幤��
     * @return ����ʹ�õİװ幤��
     */
    virtual TEduBoardToolType GetToolType() = 0;

    /**
     * @brief �Զ���װ幤�������ʽ
     * @param type              Ҫ���������ʽ�İװ幤������
     * @param icon              Ҫ���õ������ʽ
     */
    virtual void SetCursorIcon(TEduBoardToolType type, const TEduBoardCursorIcon &icon) = 0;

    /**
     * @brief ���û�����ɫ
     * @param color 			Ҫ���õĻ�����ɫ
     *
     * ������ɫ��������Ϳѻ����
     */
    virtual void SetBrushColor(const TEduBoardColor & color) = 0;

    /**
     * @brief ��ȡ������ɫ
     * @return ������ɫ
     */
    virtual TEduBoardColor GetBrushColor() = 0;

    /**
     * @brief ���û��ʴ�ϸ
     * @param thin 				Ҫ���õĻ��ʴ�ϸ
     *
     * ���ʴ�ϸ��������Ϳѻ���ƣ�ʵ������ֵȡֵ(thin * �װ�ĸ߶� / 10000)px��������С��1px����Ϳѻ��������Ƚ���
     */
    virtual void SetBrushThin(uint32_t thin) = 0;

    /**
     * @brief ��ȡ���ʴ�ϸ
     * @return ���ʴ�ϸ
     */
    virtual uint32_t GetBrushThin() = 0;

    /**
     * @brief �����ı���ɫ
     * @param color 			Ҫ���õ��ı���ɫ
     */
    virtual void SetTextColor(const TEduBoardColor & color) = 0;

    /**
     * @brief ��ȡ�ı���ɫ
     * @return �ı���ɫ
     */
    virtual TEduBoardColor GetTextColor() = 0;

    /**
     * @brief �����ı���С
     * @param size 				Ҫ���õ��ı���С
     *
     * ʵ������ֵȡֵ(size * �װ�ĸ߶� / 10000)px
     */
    virtual void SetTextSize(uint32_t size) = 0;

    /**
     * @brief ��ȡ�ı���С
     * @return �ı���С
     */
    virtual uint32_t GetTextSize() = 0;

    /**
     * @brief �����ı���ʽ
     * @param style 			Ҫ���õ��ı���ʽ
     */
    virtual void SetTextStyle(TEduBoardTextStyle style) = 0;

    /**
     * @brief ��ȡ�ı���ʽ
     * @return �ı���ʽ
     */
    virtual TEduBoardTextStyle GetTextStyle() = 0;

    /**
     * @brief ����ֱ����ʽ
     * @param style 			Ҫ���õ�ֱ����ʽ
     */
    virtual void SetLineStyle(const TEduBoardLineStyle & style) = 0;

    /**
     * @brief ��ȡֱ����ʽ
     * @return ֱ����ʽ
     */
    virtual TEduBoardLineStyle GetLineStyle() = 0;

    /**
     * @brief ������Բ����ģʽ
     * @param drawMode 			Ҫ���õ���Բ����ģʽ
     */
    virtual void SetOvalDrawMode(TEduBoardOvalDrawMode drawMode) = 0;

    /**
     * @brief ��ȡ��Բ����ģʽ
     * @return ��Բ����ģʽ
     */
    virtual TEduBoardOvalDrawMode GetOvalDrawMode() = 0;

    /**
     * @brief ��յ�ǰ�װ�ҳͿѻ
     * @param clearBackground 	�Ƿ�ͬʱ��ձ���ɫ�Լ�����ͼƬ
     * @param clearSelectedOnly �Ƿ�ֻ���ѡ�в���Ϳѻ
     * @warning Ŀǰ��֧�����ѡ�в��ֵ�ͬʱ�������
     */
    virtual void Clear(bool clearBackground = false, bool clearSelectedOnly = false) = 0;

    /**
     * @brief ���õ�ǰ�װ�ҳ�ı���ͼƬ
     * @param url 				Ҫ���õı���ͼƬURL�������ʽΪUTF8
     * @param mode				Ҫʹ�õ�ͼƬ������ģʽ
     * 
     * ��URL��һ����Ч�ı����ļ���ַʱ�����ļ��ᱻ�Զ��ϴ���COS
     */
    virtual void SetBackgroundImage(const char * url, TEduBoardImageFitMode mode) = 0;

    /**
     * @brief ���õ�ǰ�װ�ҳ�ı���H5ҳ��
     * @param url				Ҫ���õı���H5ҳ��URL
     *
     * �ýӿ���SetBackgroundImage�ӿڻ���
     */
    virtual void SetBackgroundH5(const char * url) = 0;

    /**
     * @brief ������ǰ�װ�ҳ��һ�ζ���
     */
    virtual void Undo() = 0;

    /**
     * @brief ������ǰ�װ�ҳ��һ�γ���
     */
    virtual void Redo() = 0;

    /// @}


    /// @name �װ�ҳ�����ӿ�
    /// @{

    /**
     * @brief ����һҳ�װ�
     * @param url				Ҫʹ�õı���ͼƬURL�������ʽΪUTF8��Ϊnullptr��ʾ��ָ������ͼƬ
     * @return �װ�ID
     * @warning �װ�ҳ�ᱻ��ӵ�Ĭ���ļ����ļ�IDΪ#DEFAULT)�������ϴ����ļ��޷���Ӱװ�ҳ
     *
     * ����ֵ�ڴ���SDK�ڲ������û�����Ҫ�Լ��ͷ�
     */
    virtual const char * AddBoard(const char * url = nullptr) = 0;

    /**
     * @brief ���ͼƬ��Դ
     * @param url               Ҫ��ӵ�ͼƬԪ��URL��ַ�������ʽΪUTF8
     */
    virtual void AddImageElement(const char * url) = 0;

    /**
     * @brief ɾ��һҳ�װ�
     * @param boardId			Ҫɾ���İװ�ID��Ϊnullptr��ʾɾ����ǰҳ
     * @warning ֻ����ɾ��Ĭ���ļ����ļ�IDΪ#DEFAULT���ڵİװ�ҳ����Ĭ�ϰװ�ҳ���װ�IDΪ#DEFAULT���޷�ɾ��
     */
    virtual void DeleteBoard(const char * boardId = nullptr) = 0;

    /**
     * @brief ��һ��
     *  ÿ��Step��ӦPPT��һ������Ч��������ǰû����չʾ�Ķ���Ч������ýӿڵ��ûᵼ����ǰ��ҳ
     */
    virtual void PrevStep() = 0;

    /**
     * @brief ��һ��
     * 
     * ÿ��Step��ӦPPT��һ������Ч��������ǰû��δչʾ�Ķ���Ч������ýӿڵ��ûᵼ�����ҳ
     */
    virtual void NextStep() = 0;

    /**
     * @brief ��ǰ��ҳ
     * @param resetStep			ָ������ָ��ҳ�Ժ��Ƿ�����PPT��������
     *
     * ����ǰ�װ�ҳΪ��ǰ�ļ��ĵ�һҳ����ýӿڵ�����Ч
     */
    virtual void PrevBoard(bool resetStep = false) = 0;

    /**
     * @brief ���ҳ
     * @param resetStep			ָ������ָ��ҳ�Ժ��Ƿ�����PPT��������
     *
     * ����ǰ�װ�ҳΪ��ǰ�ļ������һҳ����ýӿڵ�����Ч
     */
    virtual void NextBoard(bool resetStep = false) = 0;

    /**
     * @brief ��ת��ָ���װ�ҳ
     * @param boardId			Ҫ��ת���İװ�ҳID
     * @param resetStep			ָ������ָ��ҳ�Ժ��Ƿ�����PPT��������
     *
     * ������ת�������ļ��İװ�ҳ
     */
    virtual void GotoBoard(const char * boardId, bool resetStep = false) = 0;

    /**
     * @brief ��ȡ��ǰ�װ�ҳID
     * @return ��ǰ�װ�ҳID
     *
     * ����ֵ�ڴ���SDK�ڲ������û�����Ҫ�Լ��ͷ�
     */
    virtual const char * GetCurrentBoard() = 0;

    /**
     * @brief ��ȡ�����ļ��İװ��б�
     * @return �����ļ��İװ��б�
     * @warning ����ֵ����ʹ��ʱ����Ҫ����delete��������ص�����release�������ͷ��ڴ�ռ��
     */
    virtual TEduBoardStringList *GetBoardList() = 0;

    /**
     * @brief ���õ�ǰ�װ�ҳ��߱�
     * @param ratio				Ҫ���õİװ��߱�
     *
     * ��ʽ��: "4:3"��"16:9"
     */
    virtual void SetBoardRatio(const char *ratio) = 0;

    /**
     * @brief ��ȡ��ǰ�װ�ҳ��߱�
     * @return �װ��߱ȣ���ʽ��SetBoardRatio�ӿڲ�����ʽһ��
     */
    virtual const char * GetBoardRatio() = 0;

    /**
     * @brief ���õ�ǰ�װ�ҳ���ű���
     * @param scale				Ҫ���õİװ����ű���
     *
     * ֧�ַ�Χ: [100��300]��ʵ�����ű�Ϊ: scale/100
     */
    virtual void SetBoardScale(uint32_t scale) = 0;

    /**
     * @brief ��ȡ��ǰ�װ�ҳ���ű���
     * @return �װ����ű�������ʽ��SetBoardScale�ӿڲ�����ʽһ��
     */
    virtual uint32_t GetBoardScale() = 0;

    /**
     * @brief ���ðװ���������Ӧģʽ
     * @param mode				Ҫ���õİװ���������Ӧģʽ
     *
     * ��������Ӧģʽ���Ӱ�����к����װ����ݲ���,��Ӱ��ӿڰ�����AddTranscodeFile
     */
    virtual void SetBoardContentFitMode(TEduBoardContentFitMode mode) = 0;

    /**
     * @brief ��ȡ�װ���������Ӧģʽ
     * @return �װ���������Ӧģʽ
     */
    virtual TEduBoardContentFitMode GetBoardContentFitMode() = 0;

    /// @}


    /// @name �ļ������ӿ�
    /// @{

    /**
     * @brief �����ļ�ת������
     * @param path				Ҫת����ļ�·���������ʽΪUTF8
     * @param config            ת�����
     * @warning ���ӿ���������ڽ���׶ο�������ת�빦�ܣ�ԭ���ϲ�����������������ʹ�ã����������е�ת��������ʹ�ú�̨����ӿڷ���
     * @see TEduBoardCallback::onTEBFileTranscodeProgress
     *
     * ֧�� PPT��PDF��Word�ļ�ת��
     * PPT�ĵ�Ĭ��תΪH5�������ܹ���ԭPPTԭ�ж���Ч���������ĵ�ת��Ϊ��̬ͼƬ
     * PPT����ת���ʱԼ1��/ҳ�������ĵ��ľ�̬ת���ʱԼ0.5��/ҳ
     * ת����Ⱥͽ������ͨ��onTEBFileTranscodeProgress�ص����أ�����μ��ûص�˵���ĵ�
     */
    virtual void ApplyFileTranscode(const char * path, const TEduBoardTranscodeConfig &config = TEduBoardTranscodeConfig()) = 0;

    /**
     * @brief ������ѯ�ļ�ת�����
     * @param taskId            ͨ��onTEBFileTranscodeProgress�ص��õ���ת������taskId
     * @warning �ýӿڽ���������ҵ�񳡾���������ѯ�ļ�ת����ȣ�����ApplyFileTranscode��SDK�ڲ������Զ����ڴ���onTEBFileTranscodeProgress�ص������������������Ҫ�������ô˽ӿ�
     * @see TEduBoardCallback::onTEBFileTranscodeProgress
     * 
     * ת����Ⱥͽ������ͨ��onTEBFileTranscodeProgress�ص����أ�����μ��ûص�˵���ĵ�
     */
    virtual void GetFileTranscodeProgress(const char *taskId) = 0;

    /**
     * @brief ���ת���ļ�
     * @param  result 			�ļ�ת����
     * @return �ļ�ID
     * @warning �������ļ���URL�ظ�ʱ���ļ�ID����Ϊ���ַ���
     * @warning ���յ���Ӧ��onTEBAddTranscodeFile�ص�ǰ���޷��÷��ص��ļ�ID��ѯ���ļ���Ϣ
     * @see TEduBoardCallback::onTEBAddTranscodeFile
     *
     * ���ӿ�ֻ����������ṹ���title��resolution��url��pages�ֶ�
     * ���øýӿں�SDK���ں�̨�����ļ����أ��ڼ��û������������������������سɹ���ʧ�ܺ�ᴥ����Ӧ�ص�
     * �ļ����سɹ��󣬽��Զ��л������ļ�
     */
    virtual const char * AddTranscodeFile(const TEduBoardTranscodeFileResult & result) = 0;

    /**
     * @brief �����Ƶ�ļ�
     * @param url               �ļ����ŵ�ַ
     * @return �ļ�ID
     *
     * �ƶ���֧��mp4/m3u8�������֧��mp4/m3u8/flv/rtmp������״̬�ı�ص� onTEBVideoStatusChange
     */
    virtual const char *AddVideoFile(const char *url) = 0;

    /**
     * @brief ��ʾ��������Ƶ������
     * @param show        �Ƿ���ʾ
     * @warning ȫ�ֿ������������Ƶ�ļ���Ч
     * ���غ���ʾĬ����Ƶ��������Ĭ����ʾϵͳ�Դ���video����������ͬƽ̨����UI��ʽ��ͬ
     */
    virtual void ShowVideoControl(bool show) = 0;

    /**
     * @brief ������Ƶ
     * @warning ֻ�Ե�ǰ�ļ���Ч
     *
     * ����״̬�ı�ص� onTEBVideoStatusChange��һ����ʹ���Զ�����Ƶ������ʱʹ��
     */
    virtual void PlayVideo() = 0;

    /**
     * @brief ��ͣ��Ƶ
     * @warning ֻ�Ե�ǰ�ļ���Ч
     *
     * ����״̬�ı�ص� onTEBVideoStatusChange��һ����ʹ���Զ�����Ƶ������ʱʹ��
     */
    virtual void PauseVideo() = 0;

    /**
     * @brief ��ת����֧�ֵ㲥��Ƶ��
     * @param time              ���Ž��ȣ���λ��
     * @warning ֻ�Ե�ǰ�ļ���Ч
     *
     * ����״̬�ı�ص� onTEBVideoStatusChange��һ����ʹ���Զ�����Ƶ������ʱʹ��
     */
    virtual void SeekVideo(double time) = 0;

    /**
     * @brief �Ƿ�ͬ��������Ƶ������Զ��
     * @param enable            �Ƿ�ͬ��
     * @warning ȫ�ֿ������������Ƶ�ļ���Ч
     *
     * play/pause/seek�ӿ��Լ��������¼��Ĵ����Ƿ�Ӱ��Զ�ˣ�Ĭ��Ϊtrue
     * һ�������ѧ������Ϊfalse����ʦ����Ϊtrue
     */
    virtual void SetSyncVideoStatusEnable(bool enable) = 0;

    /**
     * @brief �ڲ�������ʱ������ʱͬ����Ƶ״̬��Զ�ˣ�������mp4��
     * @param interval          ͬ���������������5��
     * @warning ֻ�Ե�ǰ�ļ���Ч
     *
     * һ������ʦ����Ƶ������ɺ���ã��л��ļ����ڲ��Զ����ٶ�ʱ����
     */
    virtual void StartSyncVideoStatus(uint32_t interval) = 0;

    /**
     * @brief ֹͣͬ����Ƶ״̬
     * @warning ֻ�Ե�ǰ�ļ���Ч
     */
    virtual void StopSyncVideoStatus() = 0;

    /**
     * @brief ���H5ҳ��
     * @note ֻ֧��չʾ����֧�ֻ���
     * @param url               ��ҳ��ַ
     * @return �ļ�ID
     */
    virtual const char *AddH5File(const char *url) = 0;

    /**
     * @brief ɾ���ļ�
     * @param fileId			Ҫɾ�����ļ�ID
     *
     * �ļ�IDΪnullptrʱ��ʾ��ǰ�ļ���Ĭ���ļ��޷�ɾ��
     */
    virtual void DeleteFile(const char * fileId) = 0;

    /**
     * @brief �л��ļ�
     * @param fileId			Ҫ�л������ļ�ID
     * @param boardId           �л��ļ�����ת������װ�ҳ
     * @param stepIndex         ��ת���װ�ҳ���л����������
     * @warning �ýӿڽ��������ļ��л�����������fileIdΪ��ǰ�ļ�ID��SDK��������������������κβ���
     * @note �ļ�IDΪ�����Ϊnullptr����ַ����������ļ��л�ʧ��
     */
    virtual void SwitchFile(const char * fileId, const char *boardId = nullptr, int32_t stepIndex = -1) = 0;

    /**
     * @brief ��ȡ��ǰ�ļ�ID
     * @return ��ǰ�ļ�ID
     */
    virtual const char * GetCurrentFile() = 0;

    /**
     * @brief ��ȡ�װ���ָ���ļ����ļ���Ϣ
     * @return �ļ���Ϣ
     * @warning ÿ�ε��øýӿڵķ���ֵ���ݶ�ָ��ͬһ���ڴ棬����Ҫ���淵����Ϣ�������õ�����ֵ��ʱ������
     */
    virtual TEduBoardFileInfo GetFileInfo(const char *fileId) = 0;

    /**
     * @brief ��ȡ�װ����ϴ��������ļ����ļ���Ϣ�б�
     * @return �ļ���Ϣ�б�
     * @warning ����ֵ����ʹ��ʱ����Ҫ����delete��������ص�����release�������ͷ��ڴ�ռ��
     */
    virtual TEduBoardFileInfoList * GetFileInfoList() = 0;

    /**
     * @brief ��ȡָ���ļ��İװ�ID�б�
     * @param fileId			�ļ�ID
     * @return �װ�ID�б�
     * @warning ����ֵ����ʹ��ʱ����Ҫ����delete��������ص�����release�������ͷ��ڴ�ռ��
     */
    virtual TEduBoardStringList * GetFileBoardList(const char * fileId) = 0;

    /**
     * @brief ��ȡָ���ļ�������ͼ����֧��Ĭ���ļ���fileId=#DEFAULT��
     * @param fileId        	�ļ�ID
     * @return ����ͼURL�б�
     * @note �û��ڵ���rest api����ת��ʱ����Ҫ���� "thumbnail_resolution" ��������������ͼ���ܣ����򷵻ص�����ͼurl��Ч
     */
    virtual TEduBoardStringList * GetThumbnailImages(const char * fileId) = 0;

    /**
     * @brief ���ָ���ļ������аװ�Ϳѻ
     * @param fileId			�ļ�ID
     */
    virtual void ClearFileDraws(const char * fileId) = 0;

    /// @}
};
