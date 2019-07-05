#ifndef SDK_TIM_CLOUD_DEF_HEADER_
#define SDK_TIM_CLOUD_DEF_HEADER_
#include "TIMCloudComm.h"

/////////////////////////////////////////////////////////////////////////////////
//
//                      ������
//
/////////////////////////////////////////////////////////////////////////////////
//��ϸ [������](https://cloud.tencent.com/document/product/269/1671)�������Ʋ������鿴
enum TIMErrCode {
    ERR_SUCC                             = 0,    // �ɹ�               
    ERR_PARSE_RESPONSE_FAILED            = 6001, // �ذ�����ʧ��,�ڲ�����
    ERR_SERIALIZE_REQ_FAILED             = 6002, // �ĵ�δ����
    ERR_NO_SUCC_RESULT                   = 6003, // ���������޳ɹ����,���������б��Ƿ�Ϸ������û��Ƿ����,�����б������Ƿ��� API ƥ�䣩
    ERR_INVALID_CONVERSATION             = 6004, // �Ự��Ч,getConversation ʱ����Ƿ��Ѿ���¼,��δ��¼��ȡ�Ự,���д˴����뷵��
    ERR_LOADMSG_FAILED                   = 6005, // ���ر�����Ϣ�洢ʧ��,���ܴ洢�ļ�����
    ERR_FILE_TRANS_AUTH_FAILED           = 6006, // �ļ�����-��Ȩʧ��
    ERR_FILE_TRANS_NO_SERVER             = 6007, // �ļ�����-��ȡ Server �б�ʧ��
    ERR_FILE_TRANS_UPLOAD_FAILED         = 6008, // �ļ�����-�ϴ�ʧ��,���������Ƿ�����
    ERR_FILE_TRANS_DOWNLOAD_FAILED       = 6009, // �ļ�����-����ʧ��,��������,�����ļ��������Ƿ��Ѿ�����,Ŀǰ��Դ�ļ��洢 7 ��
    ERR_HTTP_REQ_FAILED                  = 6010, // HTTP ����ʧ��
    ERR_TO_USER_INVALID                  = 6011, // ��Ϣ���շ���Ч,�Է��û������ڣ����շ����¼�� ImSDK �����ʺŵ���ӿڵ��룩
    ERR_REQUEST_TIMEOUT                  = 6012, // ����ʱ,�������ָ������ԡ���Android SDK 1.8.0 ������Ҫ�ο� Android ����������÷�ʽ��������,�������ִ˴���
    ERR_SDK_NOT_INITIALIZED              = 6013, // SDK δ��ʼ�������û�δ��¼�ɹ�,���ȵ�¼,�ɹ��ص�֮������
    ERR_SDK_NOT_LOGGED_IN                = 6014, // SDK δ��¼,���ȵ�¼,�ɹ��ص�֮������,���߱�������,��ʹ�� TIMManager getLoginUser ��鵱ǰ�Ƿ�����
    ERR_IN_PROGESS                       = 6015, // �����ýӿڵ��ÿ���,��һ�� login �����ص�ǰ,������ login �����᷵�ظô�����
    ERR_INVALID_MSG_ELEM                 = 6016, // ע�ᳬʱ,��Ҫ����
    ERR_INVALID_PARAMETERS               = 6017, // API ������Ч,��������Ƿ����Ҫ��,����ɲ鿴������Ϣ��һ�������ĸ��ֶ�
    ERR_INIT_CORE_FAIL                   = 6018, // SDK ��ʼ��ʧ��,�����ǲ���Ŀ¼��Ȩ��
    ERR_DATABASE_OPERATE_FAILED          = 6019, // �������ݿ����ʧ��,�����ǲ���Ŀ¼��Ȩ�޻������ݿ��ļ�����
    ERR_EXPIRED_SESSION_NODE             = 6020, // Session Node ����
    ERR_INVALID_SDK_OBJECT               = 6021, // ������Դ�ļ���������,�绹δ�ϴ��ɹ����ýӿ�������Դ,�����û��Լ����� TIMImage �ȶ���
    ERR_IO_OPERATION_FAILED              = 6022, // �������� IO ����,����Ƿ��ж�дȨ��,�����Ƿ�����
    ERR_LOGGED_OUT_BEFORE_LOGIN_FINISHED = 6023, // �ڵ�¼����û�����ǰ�����˵ǳ����������߱������ߣ�
    ERR_TLSSDK_NOT_INITIALIZED           = 6024, // TLSSDKδ��ʼ��
    ERR_TLSSDK_FIND_NO_USER              = 6025, // TLSSDKû���ҵ���Ӧ���û���Ϣ

    ERR_REQUEST_NO_NET_ONREQ             = 6200, // ����ʱû������,�������ָ�������
    ERR_REQUEST_NO_NET_ONRSP             = 6201, // ��Ӧʱû������,�������ָ�������
    ERR_SERIVCE_NOT_READY                = 6205, // QAL����δ����
    ERR_USER_SIG_EXPIRED                 = 6206, // Ʊ�ݹ���(imcore)
    ERR_LOGIN_KICKED_OFF_BY_OTHER        = 6208, // �����ն˵�¼�ʺű���,�����µ�¼
    ERR_NEVER_CONNECT_AFTER_LAUNCH       = 6209, // ����������û�г�������

    ERR_REQUEST_FAILED                   = 6210, // QALִ��ʧ��
    ERR_REQUEST_INVALID_REQ              = 6211, // ����Ƿ�,toMsgService�Ƿ�
    ERR_REQUEST_OVERLOADED               = 6212, // ������М�
    ERR_REQUEST_KICK_OFF                 = 6213, // �Ѿ��������ն�����
    ERR_REQUEST_SERVICE_SUSPEND          = 6214, // ������ͣ
    ERR_REQUEST_INVALID_SIGN             = 6215, // SSOǩ������
    ERR_REQUEST_INVALID_COOKIE           = 6216, // SSO cookie��Ч
    ERR_LOGIN_TLS_RSP_PARSE_FAILED       = 6217, // ��¼ʱTLS�ذ�У��,���峤�ȴ���
    ERR_LOGIN_OPENMSG_TIMEOUT            = 6218, // ��¼ʱOPENSTATSVC��OPENMSG�ϱ�״̬ʱ��ʱ
    ERR_LOGIN_OPENMSG_RSP_PARSE_FAILED   = 6219, // ��¼ʱOPENSTATSVC��OPENMSG�ϱ�״̬ʱ�����ذ�ʧ��
    ERR_LOGIN_TLS_DECRYPT_FAILED         = 6220, // ��¼ʱTLS����ʧ��
    ERR_WIFI_NEED_AUTH                   = 6221, // �����ϵ�wifi��Ҫ��֤������֤�������,�޷��������磩
    ERR_USER_CANCELED                    = 6222, // �û���ȡ��
    ERR_REVOKE_TIME_LIMIT_EXCEED         = 6223, // ��Ϣ���س�����ʱ�����ƣ�Ĭ��2���ӣ�

    ERR_QAL_NO_SHORT_CONN_AVAILABLE      = 6300, // û�п��õĶ�����sso
};


/// @name ���ú�ͻ�������ѡ��
/// @{
/**
* @brief ���ýӿڵķ���ֵ
*
* @note
* ���ӿڲ������лص���ֻ�е��ӿڷ���TIM_SUCCʱ���ص��Żᱻ����
*/
enum TIMResult {
    TIM_SUCC = 0,          // �ӿڵ��óɹ�
    TIM_ERR_SDKUNINIT = -1,// �ӿڵ���ʧ�ܣ�ImSDKδ��ʼ��
    TIM_ERR_NOTLOGIN = -2, // �ӿڵ���ʧ�ܣ��û�δ��¼
    TIM_ERR_JSON = -3,     // �ӿڵ���ʧ�ܣ������Json��ʽ��Json Key
    TIM_ERR_PARAM = -4,    // �ӿڵ��óɹ�����������
    TIM_ERR_CONV = -5,     // �ӿڵ��óɹ�����Ч�ĻỰ
    TIM_ERR_GROUP = -6,    // �ӿڵ��óɹ�����Ч��Ⱥ��
};

/**
* @brief ��־����
*/
enum TIMLogLevel {
    kTIMLog_Off,     // �ر���־���
    kTIMLog_Verbose, // �������Թ�����һЩ��ϸ��Ϣ��־
    kTIMLog_Debug,   // ������־
    kTIMLog_Info,    // ��Ϣ��־
    kTIMLog_Warn,    // ������־
    kTIMLog_Error,   // ������־
    kTIMLog_Assert,  // ������־
};

/**
* @brief �����¼�����
*/
enum TIMNetworkStatus {
    kTIMConnected,       // ������
    kTIMDisconnected,    // ʧȥ����
    kTIMConnecting,      // ��������
    kTIMConnectFailed,   // ����ʧ��
};

/**
* @brief �Ự�¼�����
*/
enum TIMConvEvent {
    kTIMConvEvent_Add,    // �Ự����,�����յ�һ������Ϣ,����һ���µĻỰ���¼�����
    kTIMConvEvent_Del,    // �Ựɾ��,�����Լ�ɾ��ĳ�Ựʱ�ᴥ��
    kTIMConvEvent_Update, // �Ự����,�Ự����Ϣ��δ�������仯���յ�����Ϣʱ����
};

/**
* @brief �Ự����
*/
enum TIMConvType {
    kTIMConv_Invalid, // ��Ч�Ự
    kTIMConv_C2C,     // ���˻Ự
    kTIMConv_Group,   // Ⱥ��Ự
    kTIMConv_System,  // ϵͳ�Ự
};

/**
* @brief ��ʼ��ImSDK������
*/
// Struct SdKConfig JsonKey
static const char* kTIMSdkConfigConfigFilePath     = "sdk_config_config_file_path";// string, ֻд(ѡ��), �����ļ�·��,Ĭ��·��Ϊ"/"
static const char* kTIMSdkConfigLogFilePath        = "sdk_config_log_file_path";   // string, ֻд(ѡ��), ��־�ļ�·��,Ĭ��·��Ϊ"/"
// EndStruct


/**
* @brief Ⱥ���Ա��Ϣ��ʶ
*/
enum TIMGroupMemberInfoFlag {
    kTIMGroupMemberInfoFlag_None         = 0x00,       // ��
    kTIMGroupMemberInfoFlag_JoinTime     = 0x01,       // ����ʱ��
    kTIMGroupMemberInfoFlag_MsgFlag      = 0x01 << 1,  // Ⱥ��Ϣ����ѡ��
    kTIMGroupMemberInfoFlag_MsgSeq       = 0x01 << 2,  // ��Ա�Ѷ���Ϣseq
    kTIMGroupMemberInfoFlag_MemberRole   = 0x01 << 3,  // ��Ա��ɫ
    kTIMGroupMemberInfoFlag_ShutupUntill = 0x01 << 4,  // ����ʱ�䡣0: û�н���
    kTIMGroupMemberInfoFlag_NameCard     = 0x01 << 5,  // Ⱥ��Ƭ
};

/**
* @brief Ⱥ���Ա��ɫ��ʶ
*/
enum TIMGroupMemberRoleFlag {
    kTIMGroupMemberRoleFlag_All    = 0x00,       // ��ȡȫ����ɫ����
    kTIMGroupMemberRoleFlag_Owner  = 0x01,       // ��ȡ������(Ⱥ��)
    kTIMGroupMemberRoleFlag_Admin  = 0x01 << 1,  // ��ȡ����Ա��������Ⱥ��
    kTIMGroupMemberRoleFlag_Member = 0x01 << 2,  // ��ȡ��ͨȺ��Ա��������Ⱥ���͹���Ա
};

/**
* @brief ��ȡȺ���Ա��Ϣ��ѡ��
*/
// Struct GroupMemberGetInfoOption JsonKey
static const char* kTIMGroupMemberGetInfoOptionInfoFlag    = "group_member_get_info_option_info_flag";     // uint64 [TIMGroupMemberInfoFlag](), ��д(ѡ��), ������Ҫ��ȡ����Ϣ���ˣ�Ĭ��ֵΪ0xffffffff(��ȡȫ����Ϣ)
static const char* kTIMGroupMemberGetInfoOptionRoleFlag    = "group_member_get_info_option_role_flag";     // uint64 [TIMGroupMemberRoleFlag](), ��д(ѡ��), ���ݳ�Ա��ɫ���ˣ�Ĭ��ֵΪkTIMGroupMemberRoleFlag_All����ȡ���н�ɫ
static const char* kTIMGroupMemberGetInfoOptionCustomArray = "group_member_get_info_option_custom_array";  // array string, ֻд(ѡ��), ��ο�[�Զ����ֶ�](https://cloud.tencent.com/document/product/269/1502#.E8.87.AA.E5.AE.9A.E4.B9.89.E5.AD.97.E6.AE.B5)
// EndStruct


/**
* @brief Ⱥ���Ա��Ϣ��ʶ
*/
enum TIMGroupGetInfoFlag {
    kTIMGroupInfoFlag_None         = 0x00,
    kTIMGroupInfoFlag_Name         = 0x01,       // Ⱥ������
    kTIMGroupInfoFlag_CreateTime   = 0x01 << 1,  // Ⱥ�鴴��ʱ��
    kTIMGroupInfoFlag_OwnerUin     = 0x01 << 2,  // Ⱥ�鴴�����ʺ�
    kTIMGroupInfoFlag_Seq          = 0x01 << 3,  
    kTIMGroupInfoFlag_LastTime     = 0x01 << 4,  // Ⱥ����Ϣ����޸�ʱ��
    kTIMGroupInfoFlag_NextMsgSeq   = 0x01 << 5,  
    kTIMGroupInfoFlag_LastMsgTime  = 0X01 << 6,  // ����Ⱥ����Ϣʱ��
    kTIMGroupInfoFlag_AppId        = 0x01 << 7,
    kTIMGroupInfoFlag_MemberNum    = 0x01 << 8,  // Ⱥ���Ա����
    kTIMGroupInfoFlag_MaxMemberNum = 0x01 << 9,  // Ⱥ���Ա�������
    kTIMGroupInfoFlag_Notification = 0x01 << 10, // Ⱥ��������
    kTIMGroupInfoFlag_Introduction = 0x01 << 11, // Ⱥ�������
    kTIMGroupInfoFlag_FaceUrl      = 0x01 << 12, // Ⱥͷ��URL
    kTIMGroupInfoFlag_AddOpton     = 0x01 << 13, // ��Ⱥѡ��
    kTIMGroupInfoFlag_GroupType    = 0x01 << 14, // Ⱥ����
    kTIMGroupInfoFlag_LastMsg      = 0x01 << 15, // Ⱥ��������һ����Ϣ
    kTIMGroupInfoFlag_OnlineNum    = 0x01 << 16, // Ⱥ�����߳�Ա��
    kTIMGroupInfoFlag_Visible      = 0x01 << 17, // Ⱥ���Ƿ�ɼ�
    kTIMGroupInfoFlag_Searchable   = 0x01 << 18, // Ⱥ���Ƿ��������
    kTIMGroupInfoFlag_ShutupAll    = 0x01 << 19, // Ⱥ���Ƿ�ȫ����
};

/**
* @brief ��ȡȺ����Ϣ��ѡ��
*/
// Struct GroupGetInfoOption JsonKey
static const char* kTIMGroupGetInfoOptionInfoFlag    = "group_get_info_option_info_flag";     // uint64 [TIMGroupGetInfoFlag](), ��д(ѡ��), ������Ҫ��ȡ����Ϣ���ˣ�Ĭ��ֵΪ0xffffffff(��ȡȫ����Ϣ)
static const char* kTIMGroupGetInfoOptionCustomArray = "group_get_info_option_custom_array";  // array string, ֻд(ѡ��), ��ο�[�Զ����ֶ�](https://cloud.tencent.com/document/product/269/1502#.E8.87.AA.E5.AE.9A.E4.B9.89.E5.AD.97.E6.AE.B5)
// EndStruct

/**
* @brief ����������Ϣ
*/
// Struct UserConfig JsonKey
static const char* kTIMUserConfigIsReadReceipt            = "user_config_is_read_receipt";             // bool, ֻд(ѡ��), true��ʾҪ���Ѷ���ִ�¼�
static const char* kTIMUserConfigIsSyncReport             = "user_config_is_sync_report";              // bool, ֻд(ѡ��), true��ʾ�����Ҫɾ���Ѷ�״̬
static const char* kTIMUserConfigIsIngoreGroupTipsUnRead  = "user_config_is_ingore_grouptips_unread";  // bool, ֻд(ѡ��), true��ʾȺtips������Ⱥ��Ϣ�Ѷ�����
static const char* kTIMUserConfigGroupGetInfoOption       = "user_config_group_getinfo_option";        // object [GroupGetInfoOption](),  ֻд(ѡ��),��ȡȺ����ϢĬ��ѡ��
static const char* kTIMUserConfigGroupMemberGetInfoOption = "user_config_group_member_getinfo_option"; // object [GroupMemberGetInfoOption](),  ֻд(ѡ��),��ȡȺ���Ա��ϢĬ��ѡ��
// EndStruct

/**
* @brief HTTP������Ϣ
*/
// Struct HttpProxyInfo JsonKey
static const char* kTIMHttpProxyInfoIp      = "http_proxy_info_ip";   // string, ֻд(����), �����IP
static const char* kTIMHttpProxyInfoPort    = "http_proxy_info_port"; // int,    ֻд(����), ����Ķ˿�
// EndStruct

/**
* @brief SOCKS5������Ϣ
*/
// Struct Socks5ProxyInfo JsonKey
static const char* kTIMSocks5ProxyInfoIp       = "socks5_proxy_info_ip";       // string, ֻд(����), socks5�����IP
static const char* kTIMSocks5ProxyInfoPort     = "socks5_proxy_info_port";     // int,    ֻд(����), socks5����Ķ˿�
static const char* kTIMSocks5ProxyInfoUserName = "socks5_proxy_info_username"; // string, ֻд(ѡ��), ��֤���û���
static const char* kTIMSocks5ProxyInfoPassword = "socks5_proxy_info_password"; // string, ֻд(ѡ��), ��֤������
// EndStruct

/**
* @brief ��������
* > �Զ�������
* + �����߿����Զ��������(��������Ϊ64���ֽ�)��ImSDKֻ����͸������ͨ��IM��̨�󣬿���ͨ���������ص�[״̬����ص�](https://cloud.tencent.com/document/product/269/2570)��֪������ҵ���̨��
* > HTTP����
* + HTTP������Ҫ���ڷ���ͼƬ���������ļ���΢��Ƶ����Ϣʱ��������ļ��ϴ���COS���Լ����յ�ͼƬ���������ļ���΢��Ƶ����Ϣ��������ļ����ص�����ʱ�õ���
*   ����ʱ�����õ�IP����Ϊ�գ��˿ڲ���Ϊ0.�����Ҫȡ��HTTP����ֻ�轫�����IP����Ϊ���ַ������˿�����Ϊ0
* > SOCKS5����
* + SOCKS5������Ҫ�ڳ�ʼ��֮ǰ���á�����֮��ImSDK���͵�����Э���ͨ��SOCKS5������������͵���ͨ��IM��̨��
*/
// Struct SetConfig JsonKey
static const char* kTIMSetConfigLogLevel           = "set_config_log_level";             // uint [TIMLogLevel](),  ֻд(ѡ��), �������־�ļ������Ӽ���
static const char* kTIMSetConfigCackBackLogLevel   = "set_config_callback_log_level";    // uint [TIMLogLevel](),  ֻд(ѡ��), ���ӻص�����־���� 
static const char* kTIMSetConfigIsLogOutputConsole = "set_config_is_log_output_console"; // bool,                  ֻд(ѡ��), �Ƿ����������̨ 
static const char* kTIMSetConfigUserConfig         = "set_config_user_config";           // object [UserConfig](), ֻд(ѡ��), �û�����
static const char* kTIMSetConfigUserDefineData     = "set_config_user_define_data";      // string,                ֻд(ѡ��), �Զ������ݣ������Ҫ����ʼ��ǰ����
static const char* kTIMSetConfigHttpProxyInfo      = "set_config_http_proxy_info";       // object [HttpProxyInfo](),  ֻд(ѡ��), ����HTTP���������Ҫ���ڷ���ͼƬ���ļ�����������Ƶǰ����
static const char* kTIMSetConfigSocks5ProxyInfo    = "set_config_socks5_proxy_info";     // object [Socks5ProxyInfo](), ֻд(ѡ��), ����SOCKS5���������Ҫ����ʼ��ǰ����
// EndStruct
/// @}

/// @name ��Ϣ�ؼ�����
/// @brief ��Ϣ��غ궨�壬�Լ���ؽṹ��Ա��ȡJson Key����
/// @{
/**
* @brief ��Ϣ��ǰ״̬����
*/
enum TIMMsgStatus {
    kTIMMsg_Sending = 1,        // ��Ϣ���ڷ���
    kTIMMsg_SendSucc = 2,       // ��Ϣ���ͳɹ�
    kTIMMsg_SendFail = 3,       // ��Ϣ����ʧ��
    kTIMMsg_Deleted = 4,        // ��Ϣ��ɾ��
    kTIMMsg_LocalImported = 5,  // ��Ϣ����״̬
    kTIMMsg_Revoked = 6,        // ��Ϣ����״̬
};

/**
* @brief ��ʶ��Ϣ�����ȼ�������Խ�����ȼ�Խ��
*/
enum TIMMsgPriority {
    kTIMMsgPriority_High,   // ���ȼ���ߣ�һ��Ϊ�������������Ϣ
    kTIMMsgPriority_Normal, // ��ʾ���ȼ���֮������Ϊ��ͨ��Ϣ
    kTIMMsgPriority_Low,    // ����Ϊ������Ϣ��
    kTIMMsgPriority_Lowest, // ���ȼ���ͣ�һ��Ϊ��Ա����Ⱥ֪ͨ(��̨�·�)
};

/**
* @brief ��ϢJson Keys
*
* @note 
* > ��ӦElem��˳��
* + Ŀǰ�ļ�������Elem��һ���ᰴ�����˳���䣬����Elem����˳�򣬲������鲻Ҫ��������Elem˳����д���Ӧ���������Elem���ʹ�����ֹ�쳣����½���Crash��
* > ���Ⱥ��ĺ���͵�����Ϣ
* + ����ֱ�����������е��޺ͷ�������ܣ�����������ȼ��ϵͣ������Ϣ���ȼ��ϸߣ�������Ϣ���ݿ���ʹ���Զ�����Ϣ[CustomElem]()���ж��壬������Ϣʱ����ͨ�� kTIMMsgPriority ������Ϣ���ȼ���
* > �ĺ󼴷���Ϣ
* + ������ͨ������ kTIMMsgIsOnlineMsg �ֶ�Ϊtrueʱ����ʾ�����ĺ󼴷���Ϣ,����Ϣ����������
* >>C2C�Ự,������Ϣ����ʱ��ֻ�жԷ����ߣ��Է��Ż��յ��������ʱ���ߣ������ٵ�¼Ҳ�ղ�������Ϣ��
* >>Ⱥ�Ự,������Ϣ����ʱ��ֻ��Ⱥ�����ߵĳ�Ա�Ż��յ��������ʱ���ߣ������ٵ�¼Ҳ�ղ�������Ϣ��
* >>����Ϣ���������ᱣ��
* >>����Ϣ������δ������
* >>����Ϣ�ڱ��ز���洢
* > ��Ϣ�Զ����ֶ�
* + �����߿��Զ���Ϣ�����Զ����ֶΣ����Զ�������(ͨ�� kTIMMsgCustomInt ָ��)���Զ������������(ͨ�� kTIMMsgCustomStr ָ��������ת����String��Json��֧�ֶ����ƴ���)�����Ը����������ֶ��������ֲ�ͬЧ��������������Ϣ�Ƿ��Ѿ����ŵȵȡ�������Ҫע�⣬���Զ����ֶν��洢�ڱ��أ�����ͬ����Server�������ն˻�ȡ������
*/
// Struct Message JsonKey
static const char* kTIMMsgElemArray   = "message_elem_array";    //array [Elem](), ��д(����), ��Ϣ��Ԫ���б�
static const char* kTIMMsgConvId      = "message_conv_id";       //string,         ��д(ѡ��),       ��Ϣ�����ỰID
static const char* kTIMMsgConvType    = "message_conv_type";     //uint [TIMConvType](), ��д(ѡ��), ��Ϣ�����Ự����
static const char* kTIMMsgSender      = "message_sender";        //string,         ��д(ѡ��),       ��Ϣ�ķ�����
static const char* kTIMMsgPriority    = "message_priority";      //uint [TIMMsgPriority](), ��д(ѡ��), ��Ϣ���ȼ�
static const char* kTIMMsgClientTime  = "message_client_time";   //uint64,         ��д(ѡ��),       �ͻ���ʱ��
static const char* kTIMMsgServerTime  = "message_server_time";   //uint64,         ��д(ѡ��),       �����ʱ��
static const char* kTIMMsgIsFormSelf  = "message_is_from_self";  //bool,           ��д(ѡ��),       ��Ϣ�Ƿ������Լ�
static const char* kTIMMsgIsRead      = "message_is_read";       //bool,           ��д(ѡ��),       ��Ϣ�Ƿ��Ѷ�
static const char* kTIMMsgIsOnlineMsg = "message_is_online_msg"; //bool,           ��д(ѡ��),       ��Ϣ�Ƿ���������Ϣ��Ĭ��Ϊfalse��ʾ��ͨ��Ϣ,true��ʾ�ĺ󼴷���Ϣ
static const char* kTIMMsgIsPeerRead  = "message_is_peer_read";  //bool,           ֻ��,            ��Ϣ�Ƿ񱻻Ự�Է��Ѷ�
static const char* kTIMMsgStatus      = "message_status";        //uint [TIMMsgStatus](), ��д(ѡ��), ��Ϣ��ǰ״̬
static const char* kTIMMsgRand        = "message_rand";          //uint64,         ֻ��,       Ψһ��ʶ 
static const char* kTIMMsgSeq         = "message_seq";           //uint64,         ֻ��,       ��Ϣ����
static const char* kTIMMsgCustomInt   = "message_custom_int";    //uint32_t,       ��д(ѡ��), �Զ�������ֵ�ֶ�
static const char* kTIMMsgCustomStr   = "message_custom_str";    //string,         ��д(ѡ��), �Զ��������ֶ�
// EndStruct

/**
* @brief ��Ϣ�Ѷ���ִ
*/
// Struct MessageReceipt JsonKey
static const char* kTIMMsgReceiptConvId    = "msg_receipt_conv_id";     //string, ֻ��, �ỰID
static const char* kTIMMsgReceiptConvType  = "msg_receipt_conv_type";   //uint [TIMConvType](), ֻ��, �Ự����
static const char* kTIMMsgReceiptTimeStamp = "msg_receipt_time_stamp";  //uint64, ֻ��, ʱ���
// EndStruct

/**
* @brief Ԫ�ص�����
*/
enum TIMElemType {
    kTIMElem_Text,           // �ı�Ԫ��
    kTIMElem_Image,          // ͼƬԪ��
    kTIMElem_Sound,          // ����Ԫ��
    kTIMElem_Custom,         // �Զ���Ԫ��
    kTIMElem_File,           // �ļ�Ԫ��
    kTIMElem_GroupTips,      // Ⱥ��ϵͳ��ϢԪ��
    kTIMElem_Face,           // ����Ԫ��
    kTIMElem_Location,       // λ��Ԫ��
    kTIMElem_GroupReport,    // Ⱥ��ϵͳ֪ͨԪ��
    kTIMElem_Video,          // ��ƵԪ��
};

/**
* @brief Ԫ�ص�����
*/
// Struct Elem JsonKey
static const char* kTIMElemType         = "elem_type";    // uint [TIMElemType](), ��д(����), Ԫ������
// EndStruct

/**
* @brief �ı�Ԫ��
*/
// Struct TextElem JsonKey
static const char* kTIMTextElemContent  = "text_elem_content"; // string, ��д(����), �ı�����
// EndStruct

/**
* @brief ����Ԫ��
*
* @note 
* ImSDK�����ṩ�����������������б��������ʹ�� kTIMFaceElemIndex �洢�����ڱ�����е����������û��Զ��塣
* ����ֱ��ʹ�� kTIMFaceElemBuf �洢�����������Ϣ(����ת����String��Json��֧�ֶ����ƴ���)�����û��Զ��壬ImSDK�ڲ�ֻ��͸����
*/
// Struct FaceElem JsonKey
static const char* kTIMFaceElemIndex          = "face_elem_index";  // int,    ��д(����), ��������
static const char* kTIMFaceElemBuf            = "face_elem_buf";    // string, ��д(ѡ��), ������������,�����û��Զ�����д����Ҫ��������ƣ��鷳��ת����ַ�����Jsonֻ֧���ַ���
// EndStruct

/**
* @brief λ��Ԫ��
*/
// Struct LocationElem JsonKey
static const char* kTIMLocationElemDesc       = "location_elem_desc";          // string, ��д(ѡ��), λ������
static const char* kTIMLocationElemLongitude  = "location_elem_longitude";     // double, ��д(����), ����
static const char* kTIMLocationElemlatitude   = "location_elem_latitude";      // double, ��д(����), γ��
// EndStruct


/**
* @brief ͼƬ��������
*/
enum TIMImageLevel {
    kTIMImageLevel_Orig,        // ԭͼ����
    kTIMImageLevel_Compression, // ��ѹ����ͼ����(ͼƬ��С,Ĭ��ֵ)
    kTIMImageLevel_HD,          // ����ͼ����(ͼƬ�ϴ�)
};

/**
* @brief ͼƬԪ��
*
* @note
* >  ͼƬ���˵����ÿ��ͼƬ�����ֹ�񣬷ֱ���Original��ԭͼ����Large����ͼ����Thumb������ͼ����
* >> ԭͼ��ָ�û����͵�ԭʼͼƬ���ߴ�ʹ�С�����ֲ��䡣
* >> ��ͼ���ǽ�ԭͼ�ȱ�ѹ����ѹ��������н�С��һ������720���ء�
* >> ����ͼ���ǽ�ԭͼ�ȱ�ѹ����ѹ��������н�С��һ������198����
* >  ���ԭͼ�ߴ��С��198���أ������ֹ�񶼱���ԭʼ�ߴ磬����ѹ����
* >  ���ԭͼ�ߴ���198-720֮�䣬���ͼ��ԭͼһ��������ѹ����
* >  ���ֻ���չʾͼƬʱ����������չʾ����ͼ���û���������ͼʱ�����ش�ͼ��������ͼʱ������ԭͼ����Ȼ������Ҳ����ѡ��������ͼ����������ͼʱֱ������ԭͼ��
* >  ��Pad��PC��չʾͼƬʱ�����ڷֱ��ʽϴ��һ�������Wi-Fi���������磬����ֱ����ʾ��ͼ���û�������ͼʱ������ԭͼ��
*/
// Struct ImageElem JsonKey
static const char* kTIMImageElemOrigPath        = "image_elem_orig_path";        // string, ��д(����), ����ͼƬ��·��
static const char* kTIMImageElemLevel           = "image_elem_level";            // uint[TIMImageLevel](), ��д(����), ����ͼƬ����������
static const char* kTIMImageElemFormat          = "image_elem_format";           // int,    ��д(����), ����ͼƬ��ʽ
static const char* kTIMImageElemOrigId          = "image_elem_orig_id";          // string, ֻ��,       ԭͼ��uuid
static const char* kTIMImageElemOrigPicHeight   = "image_elem_orig_pic_height";  // int,    ֻ��,       ԭͼ��ͼƬ�߶�
static const char* kTIMImageElemOrigPicWidth    = "image_elem_orig_pic_width";   // int,    ֻ��,       ԭͼ��ͼƬ�߶�
static const char* kTIMImageElemOrigPicSize     = "image_elem_orig_pic_size";    // int,    ֻ��,       ԭͼ��ͼƬ�߶�
static const char* kTIMImageElemThumbId         = "image_elem_thumb_id";         // string, ֻ��,       ����ͼuuid
static const char* kTIMImageElemThumbPicHeight  = "image_elem_thumb_pic_height"; // int,    ֻ��,       ����ͼ��ͼƬ�߶�
static const char* kTIMImageElemThumbPicWidth   = "image_elem_thumb_pic_width";  // int,    ֻ��,       ����ͼ��ͼƬ�߶�
static const char* kTIMImageElemThumbPicSize    = "image_elem_thumb_pic_size";   // int,    ֻ��,       ����ͼ��ͼƬ�߶�
static const char* kTIMImageElemLargeId         = "image_elem_large_id";         // string, ֻ��,       ��ͼƬuuid
static const char* kTIMImageElemLargePicHeight  = "image_elem_large_pic_height"; // int,    ֻ��,       ��ͼƬ��ͼƬ�߶�
static const char* kTIMImageElemLargePicWidth   = "image_elem_large_pic_width";  // int,    ֻ��,       ��ͼƬ��ͼƬ�߶�
static const char* kTIMImageElemLargePicSize    = "image_elem_large_pic_size";   // int,    ֻ��,       ��ͼƬ��ͼƬ�߶�
static const char* kTIMImageElemOrigUrl         = "image_elem_orig_url";         // string, ֻ��,       ԭͼURL
static const char* kTIMImageElemThumbUrl        = "image_elem_thumb_url";        // string, ֻ��,       ����ͼURL
static const char* kTIMImageElemLargeUrl        = "image_elem_large_url";        // string, ֻ��,       ��ͼƬURL
static const char* kTIMImageElemTaskId          = "image_elem_task_id";          // int,    ֻ��,       ����ID
// EndStruct

/**
* @brief ����Ԫ��
*
* @note
* > �����Ƿ��Ѿ����ţ���ʹ�� ��Ϣ�Զ����ֶ� ʵ�֣��綨��һ���ֶ�ֵ0��ʾδ���ţ�1��ʾ���ţ����û��������ź�����ø��ֶε�ֵΪ1
* > һ����Ϣֻ�����һ������Ԫ�أ���Ӷ������Ԫ��ʱ��������Ϣ����ʧ�ܡ�
*/
// Struct SoundElem JsonKey
static const char* kTIMSoundElemFilePath        = "sound_elem_file_path";        // string, ��д(����), �����ļ�·��,��Ҫ�������Լ��ȱ�������Ȼ��ָ��·��
static const char* kTIMSoundElemFileSize        = "sound_elem_file_size";        // int,    ��д(����), ���������ļ���С������Ϊ��λ
static const char* kTIMSoundElemFileTime        = "sound_elem_file_time";        // int,    ��д(����), ����ʱ��
static const char* kTIMSoundElemFileId          = "sound_elem_file_id";          // string, ֻ��,       ���������ļ�ʱ��ID
static const char* kTIMSoundElemBusinessId      = "sound_elem_business_id";      // int,    ֻ��,       ����ʱ�õ���businessID
static const char* kTIMSoundElemDownloadFlag    = "sound_elem_download_flag";    // int,    ֻ��,       �Ƿ���Ҫ�������ص�ַ(0:����ƽ���룬1:��cos���룬2:����Ҫ����,ֱ����url����)
static const char* kTIMSoundElemUrl             = "sound_elem_url";              // string, ֻ��,       ���ص�URL
static const char* kTIMSoundElemTaskId          = "sound_elem_task_id";          // int,    ֻ��,       ����ID
// EndStruct

/**
* @brief �Զ���Ԫ��
*
* @note
* �Զ�����Ϣ��ָ�����õ���Ϣ�����޷������������󣬿����߿����Զ�����Ϣ��ʽ������ȫ���ɿ����߶��壬ImSDKֻ����͸����
*/
// Struct CustomElem JsonKey
static const char* kTIMCustomElemData   = "custom_elem_data";   // string,  ��д, ����,֧�ֶ���������
static const char* kTIMCustomElemDesc   = "custom_elem_desc";   // string,  ��д, �Զ�������
static const char* kTIMCustomElemExt    = "custom_elem_ext";    // string,  ��д, ��̨���Ͷ�Ӧ��ext�ֶ�
static const char* kTIMCustomElemSound  = "custom_elem_sound";  // string,  ��д, �Զ�������,��������Ǹ�˭����
// EndStruct

/**
* @brief �ļ�Ԫ��
*
* @note
* һ����Ϣֻ�����һ���ļ�Ԫ�أ���Ӷ���ļ�ʱ��������Ϣ����ʧ�ܡ�
*/
// Struct FileElem JsonKey
static const char* kTIMFileElemFilePath      = "file_elem_file_path";      // string,   ��д(����), �ļ�����·���������ļ�����
static const char* kTIMFileElemFileName      = "file_elem_file_name";      // string,   ��д(ѡ��), �ļ�������ʾ������
static const char* kTIMFileElemFileSize      = "file_elem_file_size";      // int,      ��д(����),  �ļ���С
static const char* kTIMFileElemFileId        = "file_elem_file_id";        // string,   ֻ��, ������Ƶʱ��uuid
static const char* kTIMFileElemBusinessId    = "file_elem_business_id";    // int,      ֻ��, ����ʱ�õ���businessID
static const char* kTIMFileElemDownloadFlag  = "file_elem_download_flag";  // int,      ֻ��, �ļ�����flag
static const char* kTIMFileElemUrl           = "file_elem_url";            // string,   ֻ��, �ļ����ص�URL
static const char* kTIMFileElemTaskId        = "file_elem_task_id";        // int,      ֻ��, ����ID 
// EndStruct

/**
* @brief ��ƵԪ��
*/
// Struct VideoElem JsonKey
static const char* kTIMVideoElemVideoType          = "video_elem_video_type";           // string, ��д(����), ��Ƶ�ļ����ͣ�������Ϣʱ��������
static const char* kTIMVideoElemVideoSize          = "video_elem_video_size";           // uint,   ��д(����), ��Ƶ�ļ���С
static const char* kTIMVideoElemVideoDuration      = "video_elem_video_duration";       // uint,   ��д(����), ��Ƶʱ����������Ϣʱ��������
static const char* kTIMVideoElemVideoPath          = "video_elem_video_path";           // string, ��д(����), �����ļ�·�� 
static const char* kTIMVideoElemVideoId            = "video_elem_video_id";             // string, ֻ��, ������Ƶʱ��uuid
static const char* kTIMVideoElemBusinessId         = "video_elem_business_id";          // int,    ֻ��, ����ʱ�õ���businessID
static const char* kTIMVideoElemVideoDownloadFlag  = "video_elem_video_download_flag";  // int,    ֻ��, ��Ƶ�ļ�����flag 
static const char* kTIMVideoElemVideoUrl           = "video_elem_video_url";            // string, ֻ��, ��Ƶ�ļ����ص�URL 
static const char* kTIMVideoElemImageType          = "video_elem_image_type";           // string, ��д(����), ��ͼ�ļ����ͣ�������Ϣʱ��������
static const char* kTIMVideoElemImageSize          = "video_elem_image_size";           // uint,   ��д(����), ��ͼ�ļ���С
static const char* kTIMVideoElemImageWidth         = "video_elem_image_width";          // uint,   ��д(����), ��ͼ�߶ȣ�������Ϣʱ��������
static const char* kTIMVideoElemImageHeight        = "video_elem_image_height";         // uint,   ��д(����), ��ͼ��ȣ�������Ϣʱ��������
static const char* kTIMVideoElemImagePath          = "video_elem_image_path";           // string, ��д(����), �����ͼ��·��
static const char* kTIMVideoElemImageId            = "video_elem_image_id";             // string, ֻ��, ������Ƶ��ͼʱ��ID
static const char* kTIMVideoElemImageDownloadFlag  = "video_elem_image_download_flag";  // int,    ֻ��, ��ͼ�ļ�����flag 
static const char* kTIMVideoElemImageUrl           = "video_elem_image_url";            // string, ֻ��, ��ͼ�ļ����ص�URL 
static const char* kTIMVideoElemTaskId             = "video_elem_task_id";              // uint,   ֻ��, ����ID
// EndStruct

/**
* @brief Ⱥ����Ϣ�޸ĵ�����
*/
enum TIMGroupTipGroupChangeFlag {
    kTIMGroupTipChangeFlag_Name = 0xa,   // �޸�Ⱥ������
    kTIMGroupTipChangeFlag_Introduction, // �޸�Ⱥ���
    kTIMGroupTipChangeFlag_Notification, // �޸�Ⱥ����
    kTIMGroupTipChangeFlag_FaceUrl,      // �޸�Ⱥͷ��URL
    kTIMGroupTipChangeFlag_Owner,        // �޸�Ⱥ������
};

/**
* @brief Ⱥ��ϵͳ��Ϣ-Ⱥ����Ϣ�޸�
*/
// Struct GroupTipGroupChangeInfo JsonKey
static const char* kTIMGroupTipGroupChangeInfoFlag        = "group_tips_group_change_info_flag";         // uint [TIMGroupTipGroupChangeFlag](), ֻ��, Ⱥ��Ϣ�޸�Ⱥ��Ϣ��־
static const char* kTIMGroupTipGroupChangeInfoValue       = "group_tips_group_change_info_value";        // string, ֻ��, �޸ĵĺ�ֵ,��ͬ�� info_flag �ֶ�,���в�ͬ�ĺ���
// EndStruct

/**
* @brief Ⱥ��ϵͳ��Ϣ-Ⱥ���Ա����
*/
// Struct GroupTipMemberChangeInfo JsonKey
static const char* kTIMGroupTipMemberChangeInfoIdentifier  = "group_tips_member_change_info_identifier";     // string, ֻ��, Ⱥ���ԱID
static const char* kTIMGroupTipMemberChangeInfoShutupTime  = "group_tips_member_change_info_shutupTime";     // uint,   ֻ��, ����ʱ��
// EndStruct

/**
* @brief �û���������
*/
// Struct UserProfile JsonKey
static const char* kTIMUserProfileIdentifier    = "user_profile_identifier";      // string, ֻ��, �û�ID
static const char* kTIMUserProfileNickName      = "user_profile_nick_name";       // string, ֻ��, �û����ǳ�
static const char* kTIMUserProfileFaceURL       = "user_profile_face_url";        // string, ֻ��, �û�ͷ��URL
static const char* kTIMUserProfileSelfSignature = "user_profile_self_signature";  // string, ֻ��, �û�����ǩ��
static const char* kTIMUserProfileRemark        = "user_profile_remark";          // string, ֻ��, �û���ע
// EndStruct

/**
* @brief Ⱥ��ϵͳ��Ϣ����
*/
enum TIMGroupTipType {
    kTIMGroupTip_None,              // ��Ч��Ⱥ��ʾ
    kTIMGroupTip_Invite,            // ���������ʾ
    kTIMGroupTip_Quit,              // ��Ⱥ��ʾ
    kTIMGroupTip_Kick,              // ������ʾ
    kTIMGroupTip_SetAdmin,          // ���ù���Ա��ʾ
    kTIMGroupTip_CancelAdmin,       // ȡ������Ա��ʾ
    kTIMGroupTip_GroupInfoChange,   // Ⱥ��Ϣ�޸���ʾ
    kTIMGroupTip_MemberInfoChange,  // Ⱥ��Ա��Ϣ�޸���ʾ
};

/**
* @brief Ⱥ��ϵͳ��ϢԪ��(�������Ⱥ��Ա)
*/
// Struct GroupTipsElem JsonKey
static const char* kTIMGroupTipsElemTipType                     = "group_tips_elem_tip_type";                       // uint [TIMGroupTipType](), ֻ��, Ⱥ��Ϣ����
static const char* kTIMGroupTipsElemOpUser                      = "group_tips_elem_op_user";                        // string,   ֻ��, ������ID
static const char* kTIMGroupTipsElemGroupName                   = "group_tips_elem_group_name";                     // string,   ֻ��, Ⱥ������
static const char* kTIMGroupTipsElemGroupId                     = "group_tips_elem_group_id";                       // string,   ֻ��, Ⱥ��ID
static const char* kTIMGroupTipsElemTime                        = "group_tips_elem_time";                           // uint,     ֻ��, Ⱥ��Ϣʱ��
static const char* kTIMGroupTipsElemUserArray                   = "group_tips_elem_user_array";                     // array string, ֻ��, ���������ʺ��б�
static const char* kTIMGroupTipsElemGroupChangeInfoArray        = "group_tips_elem_group_change_info_array";        // array [GroupTipGroupChangeInfo](),  ֻ��, Ⱥ���ϱ����Ϣ�б�,���� tips_type ֵΪ kTIMGroupTip_GroupInfoChange ʱ��Ч
static const char* kTIMGroupTipsElemMemberChangeInfoArray       = "group_tips_elem_member_change_info_array";       // array [GroupTipMemberChangeInfo](), ֻ��, Ⱥ��Ա�����Ϣ�б�,���� tips_type ֵΪ kTIMGroupTip_MemberInfoChange ʱ��Ч
static const char* kTIMGroupTipsElemOpUserInfo                  = "group_tips_elem_op_user_info";                   // object [UserProfile](),              ֻ��, �����߸�������
static const char* kTIMGroupTipsElemOpGroupMemberInfo           = "group_tips_elem_op_group_memberinfo";            // object [GroupMemberInfo](),          ֻ��, Ⱥ��Ա��Ϣ
static const char* kTIMGroupTipsElemChangedUserInfoArray        = "group_tips_elem_changed_user_info_array";        // array [UserProfile](),               ֻ��, ���������б�����
static const char* kTIMGroupTipsElemChangedGroupMemberInfoArray = "group_tips_elem_changed_group_memberinfo_array"; // array [GroupMemberInfo](),       ֻ��, Ⱥ��Ա��Ϣ�б�
static const char* kTIMGroupTipsElemMemberNum                   = "group_tips_elem_member_num";                     // uint,   ֻ��, ��ǰȺ��Ա��,ֻ�е��¼���Ϣ����Ϊ kTIMGroupTip_Invite �� kTIMGroupTip_Quit �� kTIMGroupTip_Kick ʱ��Ч
static const char* kTIMGroupTipsElemPlatform                    = "group_tips_elem_platform";                       // string, ֻ��, ������ƽ̨��Ϣ
// EndStruct

/**
* @brief Ⱥ��ϵͳ֪ͨ����
*/
enum TIMGroupReportType {
    kTIMGroupReport_None,         // δ֪����
    kTIMGroupReport_AddRequest,   // �����Ⱥ(ֻ�й���Ա����յ�)
    kTIMGroupReport_AddAccept,    // �����Ⱥ��ͬ��(ֻ���������Լ����յ�)
    kTIMGroupReport_AddRefuse,    // �����Ⱥ���ܾ�(ֻ���������Լ����յ�)
    kTIMGroupReport_BeKicked,     // ������Ա�߳�Ⱥ(ֻ�б����߽��յ�)
    kTIMGroupReport_Delete,       // Ⱥ����ɢ(ȫԱ����)
    kTIMGroupReport_Create,       // ����Ⱥ(�����߽���, ��չʾ)
    kTIMGroupReport_Invite,       // �����Ⱥ(�������߽���)
    kTIMGroupReport_Quit,         // ������Ⱥ(�����˳��߽���, ��չʾ)
    kTIMGroupReport_GrantAdmin,   // ���ù���Ա(�������߽���)
    kTIMGroupReport_CancelAdmin,  // ȡ������Ա(��ȡ���߽���)
    kTIMGroupReport_RevokeAdmin,  // Ⱥ�ѱ�����(ȫԱ����, ��չʾ)
    kTIMGroupReport_InviteReq,    // �����Ⱥ(ֻ�б������߻���յ�)
    kTIMGroupReport_InviteAccept, // �����Ⱥ��ͬ��(ֻ�з��������߻���յ�)
    kTIMGroupReport_InviteRefuse, // �����Ⱥ���ܾ�(ֻ�з��������߻���յ�)
    kTIMGroupReport_ReadedSync,   // �Ѷ��ϱ����ն�ͬ��֪ͨ(ֻ���ϱ����Լ��յ�)
    kTIMGroupReport_UserDefine,   // �û��Զ���֪ͨ(Ĭ��ȫԱ����)
};

/**
* @brief Ⱥ��ϵͳ֪ͨԪ��(��Ը���)
*/
// Struct GroupReportElem JsonKey
static const char* kTIMGroupReportElemReportType        = "group_report_elem_report_type";          // uint [TIMGroupReportType](), ֻ��, ����
static const char* kTIMGroupReportElemGroupId           = "group_report_elem_group_id";             // string, ֻ��, Ⱥ��ID
static const char* kTIMGroupReportElemGroupName         = "group_report_elem_group_name";           // string, ֻ��, Ⱥ������
static const char* kTIMGroupReportElemOpUser            = "group_report_elem_op_user";              // string, ֻ��, ������ID
static const char* kTIMGroupReportElemMsg               = "group_report_elem_msg";                  // string, ֻ��, ��������
static const char* kTIMGroupReportElemUserData          = "group_report_elem_user_data";            // string, ֻ��, ����������Զ�������
static const char* kTIMGroupReportElemOpUserInfo        = "group_report_elem_op_user_info";         // object [UserProfile](), ֻ��, �����߸�������
static const char* kTIMGroupReportElemOpGroupMemberInfo = "group_report_elem_op_group_memberinfo";  // object [GroupMemberInfo](), ֻ��,������Ⱥ������
static const char* kTIMGroupReportElemPlatform          = "group_report_elem_platform";             // string, ֻ��, ������ƽ̨��Ϣ
// EndStruct

/**
* @brief ��ϢȺ���ӿڵĲ���
*/
// Struct MsgBatchSendParam JsonKey
static const char* kTIMMsgBatchSendParamIdentifierArray = "msg_batch_send_param_identifier_array"; // array string,       ֻд(����), Ⱥ����ID�б�
static const char* kTIMMsgBatchSendParamMsg             = "msg_batch_send_param_msg";              // object [Message](), ֻд(����), Ⱥ������Ϣ
// EndStruct

/**
* @brief ��ϢȺ���ӿڵķ���
*/
// Struct MsgBatchSendResult JsonKey
static const char* kTIMMsgBatchSendResultIdentifier = "msg_batch_send_result_identifier";  // string, ֻ��, Ⱥ���ĵ���ID
static const char* kTIMMsgBatchSendResultCode       = "msg_batch_send_result_code";        // int [������](https://cloud.tencent.com/document/product/269/1671), ֻ��, ��Ϣ���ͽ��
static const char* kTIMMsgBatchSendResultDesc       = "msg_batch_send_result_desc";        // string, ֻ��, ��Ϣ���͵�����
static const char* kTIMMsgBatchSendResultMsg        = "msg_batch_send_result_msg";         // object [Message](), ֻ��, ���͵���Ϣ
// EndStruct

/**
* @brief ��Ϣ��λ��
*/
// Struct MsgLocator JsonKey
static const char* kTIMMsgLocatorConvId    = "message_locator_conv_id";    // bool,   ��д,       Ҫ���ҵ���Ϣ�Ƿ��Ǳ����ء�true�����صģ�false�ǳ��صġ�Ĭ��ֵΪfalse
static const char* kTIMMsgLocatorConvType  = "message_locator_conv_type";  // bool,   ��д,       Ҫ���ҵ���Ϣ�Ƿ��Ǳ����ء�true�����صģ�false�ǳ��صġ�Ĭ��ֵΪfalse
static const char* kTIMMsgLocatorIsRevoked = "message_locator_is_revoked"; // bool,   ��д(����), Ҫ���ҵ���Ϣ�Ƿ��Ǳ����ء�true�����صģ�false�ǳ��صġ�Ĭ��ֵΪfalse
static const char* kTIMMsgLocatorTime      = "message_locator_time";       // uint64, ��д(����), Ҫ���ҵ���Ϣ��ʱ���
static const char* kTIMMsgLocatorSeq       = "message_locator_seq";        // uint64, ��д(����), Ҫ���ҵ���Ϣ�����к�
static const char* kTIMMsgLocatorIsSelf    = "message_locator_is_self";    // bool,   ��д(����), Ҫ���ҵ���Ϣ�ķ������Ƿ����Լ���true���������Լ���false�����߲����Լ���Ĭ��ֵΪfalse
static const char* kTIMMsgLocatorRand      = "message_locator_rand";       // uint64, ��д(����), Ҫ���ҵ���Ϣ�����
// EndStruct


/**
* @brief ��Ϣ��ȡ�ӿڵĲ���
*/
// Struct MsgGetMsgListParam JsonKey
static const char* kTIMMsgGetMsgListParamLastMsg   = "msg_getmsglist_param_last_msg";   // object [Message](), ֻд(ѡ��), ָ������Ϣ��������Ϊnull
static const char* kTIMMsgGetMsgListParamCount     = "msg_getmsglist_param_count";      // uint,               ֻд(ѡ��), ��ָ����Ϣ�������Ϣ��
static const char* kTIMMsgGetMsgListParamIsRamble  = "msg_getmsglist_param_is_remble";  // bool,               ֻд(ѡ��), �Ƿ�������Ϣ
static const char* kTIMMsgGetMsgListParamIsForward = "msg_getmsglist_param_is_forward"; // bool,               ֻд(ѡ��), �Ƿ���ǰ����
// EndStruct



/**
* @brief ��Ϣɾ���ӿڵĲ���
*/
// Struct MsgDeleteParam JsonKey
static const char* kTIMMsgDeleteParamMsg       = "msg_delete_param_msg";        // object [Message](), ֻд(ѡ��), ָ���ڻỰ��Ҫɾ������Ϣ
static const char* kTIMMsgDeleteParamIsRamble  = "msg_delete_param_is_remble";  // bool, ֻд(ѡ��), �Ƿ�ɾ������/����������Ϣ��trueɾ��������Ϣ��falseɾ��������Ϣ��Ĭ��ֵfalse
// EndStruct

/**
* @brief UUID����
*/
enum TIMDownloadType {
    kTIMDownload_VideoThumb = 0, // ��Ƶ����ͼ
    kTIMDownload_File,           // �ļ�
    kTIMDownload_Video,          // ��Ƶ
    kTIMDownload_Sound,          // ����
};

/**
* @brief ����Ԫ�ؽӿڵĲ���
*/
// Struct DownloadElemParam JsonKey
static const char* kTIMMsgDownloadElemParamFlag       = "msg_download_elem_param_flag";         // uint,   ֻд, ����ϢԪ������ȡ����,Ԫ�ص���������
static const char* kTIMMsgDownloadElemParamType       = "msg_download_elem_param_type";         // uint [TIMDownladType](), ֻд, ����ϢԪ������ȡ����,Ԫ�ص�����
static const char* kTIMMsgDownloadElemParamId         = "msg_download_elem_param_id";           // string, ֻд, ����ϢԪ������ȡ����,Ԫ�ص�ID
static const char* kTIMMsgDownloadElemParamBusinessId = "msg_download_elem_param_business_id";  // uint,   ֻд, ����ϢԪ������ȡ����,Ԫ�ص�BusinessID
static const char* kTIMMsgDownloadElemParamUrl        = "msg_download_elem_param_url";          // string, ֻд, ����ϢԪ������ȡ����,Ԫ��URL
// EndStruct

/**
* @brief ����Ԫ�ؽӿڵķ���
*/
// Struct MsgDownloadElemResult JsonKey
static const char* kTIMMsgDownloadElemResultCurrentSize = "msg_download_elem_result_current_size";       // uint, ֻ��, ��ǰ�����صĴ�С
static const char* kTIMMsgDownloadElemResultTotalSize   = "msg_download_elem_result_total_size";         // uint, ֻ��, ��Ҫ���ص��ļ��ܴ�С
// EndStruct

/// @}


/// @name �Ự�ؼ�����
/// @brief �Ự��غ궨�壬�Լ���ؽṹ��Ա��ȡJson Key����
/// @{
/**
* @brief �ݸ���Ϣ
*/
// Struct Draft JsonKey
static const char* kTIMDraftMsg              = "draft_msg";         // object [Message](), ֻ��, �ݸ��ڵ���Ϣ
static const char* kTIMDraftUserDefine       = "draft_user_define"; // string, ֻ��, �û��Զ�������
static const char* kTIMDraftEditTime         = "draft_edit_time";   // uint, ֻ��, �ݸ����±༭ʱ��
// EndStruct

/**
* @brief �ݸ���Ϣ
*/
// Struct ConvInfo JsonKey
static const char* kTIMConvId           = "conv_id";             // string, ֻ��, �ỰID
static const char* kTIMConvType         = "conv_type";           // uint [TIMConvType](), ֻ��, �Ự����
static const char* kTIMConvOwner        = "conv_owner";          // string, ֻ��, �Ự������
static const char* kTIMConvUnReadNum    = "conv_unread_num";     // uint64, ֻ��, �Ựδ������
static const char* kTIMConvActiveTime   = "conv_active_time";    // uint64, ֻ��, �Ự�ļ���ʱ��
static const char* kTIMConvIsHasLastMsg = "conv_is_has_lastmsg"; // bool, ֻ��, �Ự�Ƿ������һ����Ϣ
static const char* kTIMConvLastMsg      = "conv_last_msg";       // object [Message](), ֻ��, �Ự���һ����Ϣ
static const char* kTIMConvIsHasDraft   = "conv_is_has_draft";   // bool, ֻ��, �Ự�ݸ�
static const char* kTIMConvDraft        = "conv_draft";          // object [Draft](), ֻ��(ѡ��), �Ự�ݸ�
// EndStruct
/// @}

/// @name Ⱥ��ؼ�����
/// @brief Ⱥ����غ궨�壬�Լ���ؽṹ��Ա��ȡJson Key����
/// @{
/**
* @brief Ⱥ���Ⱥѡ��
*/
enum TIMGroupAddOption {
    kTIMGroupAddOpt_Forbid = 0,  // ��ֹ��Ⱥ
    kTIMGroupAddOpt_Auth = 1,    // ��Ҫ����Ա����
    kTIMGroupAddOpt_Any = 2,     // �κ��˶����Լ�Ⱥ
};

/**
* @brief Ⱥ������
*/
enum TIMGroupType {
    kTIMGroup_Public,     // ����Ⱥ
    kTIMGroup_Private,    // ˽��Ⱥ
    kTIMGroup_ChatRoom,   // ������
    kTIMGroup_BChatRoom,  // ���߳�Ա�㲥��Ⱥ
    kTIMGroup_AVChatRoom, // ����ֱ��������
};

/**
* @brief Ⱥ���Ա��ɫ����
*/
enum TIMGroupMemberRole {
    kTIMMemberRole_Normal,     // Ⱥ��Ա
    kTIMMemberRole_Admin,      // ����Ա
    kTIMMemberRole_SuperAdmin, // ��������Ա
};

/**
* @brief Ⱥ���Ա��Ϣ
*/
// Struct GroupMemberInfo JsonKey
static const char* kTIMGroupMemberInfoIdentifier = "group_member_info_identifier";   // string, ��д(����), Ⱥ���ԱID
static const char* kTIMGroupMemberInfoJoinTime   = "group_member_info_join_time";    // uint,  ֻ��, Ⱥ���Ա����ʱ��
static const char* kTIMGroupMemberInfoMemberRole = "group_member_info_member_role";  // uint [TIMGroupMemberRole](), ��д(ѡ��), Ⱥ���Ա��ɫ
static const char* kTIMGroupMemberInfoMsgFlag    = "group_member_info_msg_flag";     // uint,  ֻ��, ��Ա������Ϣ��ѡ��
static const char* kTIMGroupMemberInfoMsgSeq     = "group_member_info_msg_seq";      // uint,  ֻ��, 
static const char* kTIMGroupMemberInfoShutupTime = "group_member_info_shutup_time";  // uint,  ֻ��, ��Ա����ʱ��
static const char* kTIMGroupMemberInfoNameCard   = "group_member_info_name_card";    // string, ֻ��, ��ԱȺ��Ƭ
static const char* kTIMGroupMemberInfoCustomInfo = "group_member_info_custom_info";  // object key string value string, ֻ��, ��ο�[�Զ����ֶ�](https://cloud.tencent.com/document/product/269/1502#.E8.87.AA.E5.AE.9A.E4.B9.89.E5.AD.97.E6.AE.B5)
// EndStruct

/**
* @brief ����Ⱥ��ӿڵĲ���
*/
// Struct CreateGroupParam JsonKey
static const char* kTIMCreateGroupParamGroupName        = "create_group_param_group_name";          //string, ֻд(����), Ⱥ������
static const char* kTIMCreateGroupParamGroupId          = "create_group_param_group_id";            //string, ֻд(ѡ��), Ⱥ��ID,����ʱ�����ɹ��ص��᷵��һ����̨�����ȺID
static const char* kTIMCreateGroupParamGroupType        = "create_group_param_group_type";          //uint[TIMGroupType](), ֻд(ѡ��), Ⱥ������,Ĭ��ΪPublic
static const char* kTIMCreateGroupParamGroupMemberArray = "create_group_param_group_member_array";  //array [GroupMemberInfo](), ֻд(ѡ��), Ⱥ���ʼ��Ա����
static const char* kTIMCreateGroupParamNotification     = "create_group_param_notification";        //string, ֻд(ѡ��), Ⱥ�鹫��,
static const char* kTIMCreateGroupParamIntroduction     = "create_group_param_introduction";        //string, ֻд(ѡ��), Ⱥ����,
static const char* kTIMCreateGroupParamFaceUrl          = "create_group_param_face_url";            //string, ֻд(ѡ��), Ⱥ��ͷ��URL
static const char* kTIMCreateGroupParamAddOption        = "create_group_param_add_option";          //uint [TIMGroupAddOption](),   ֻд(ѡ��), ��Ⱥѡ�Ĭ��ΪAny
static const char* kTIMCreateGroupParamMaxMemberCount   = "create_group_param_max_member_num";      //uint,   ֻд(ѡ��), Ⱥ������Ա��
static const char* kTIMCreateGroupParamCustomInfo       = "create_group_param_custom_info";         //object key string value string, ֻ��(ѡ��), ��ο�[�Զ����ֶ�](https://cloud.tencent.com/document/product/269/1502#.E8.87.AA.E5.AE.9A.E4.B9.89.E5.AD.97.E6.AE.B5)
// EndStruct

/**
* @brief ����Ⱥ��ӿڵķ���
*/
// Struct CreateGroupResult JsonKey
static const char* kTIMCreateGroupResultGroupId         = "create_group_result_groupid"; // string, ֻ��, ������ȺID
// EndStruct

/**
* @brief �����Ա�ӿڵĲ���
*/
// Struct GroupInviteMemberParam JsonKey
static const char* kTIMGroupInviteMemberParamGroupId         = "group_invite_member_param_group_id";         // string, ֻд(����), Ⱥ��ID
static const char* kTIMGroupInviteMemberParamIdentifierArray = "group_invite_member_param_identifier_array"; // array string, ֻд(����), ���������Ⱥ���û�ID����
static const char* kTIMGroupInviteMemberParamUserData        = "group_invite_member_param_user_data";        // string, ֻд(ѡ��), �����Զ�������
// EndStruct


/**
* @brief Ⱥ�������Ϣ
*/
enum HandleGroupMemberResult {
    kTIMGroupMember_HandledErr, // ʧ��
    kTIMGroupMember_HandledSuc, // �ɹ�
    kTIMGroupMember_Included,   // ����Ⱥ��Ա
    kTIMGroupMember_Invited,    // �ѷ�������
};


/**
* @brief �����Ա�ӿڵķ���
*/
// Struct GroupInviteMemberResult JsonKey
static const char* kTIMGroupInviteMemberResultIdentifier = "group_invite_member_result_identifier"; // string, ֻ��, ���������Ⱥ����û�ID
static const char* kTIMGroupInviteMemberResultResult     = "group_invite_member_result_result";     // uint [HandleGroupMemberResult](), ֻ��, ������
// EndStruct

/**
* @brief ɾ����Ա�ӿڵĲ���
*/
// Struct GroupDeleteMemberParam JsonKey
static const char* kTIMGroupDeleteMemberParamGroupId         = "group_delete_member_param_group_id";          // string, ֻд(����), Ⱥ��ID
static const char* kTIMGroupDeleteMemberParamIdentifierArray = "group_delete_member_param_identifier_array";  // array string, ֻд(����), ��ɾ��Ⱥ���Ա����
static const char* kTIMGroupDeleteMemberParamUserData        = "group_delete_member_param_user_data";         // string, ֻд(ѡ��), �����Զ�������
// EndStruct

/**
* @brief ɾ����Ա�ӿڵķ���
*/
// Struct GroupDeleteMemberResult JsonKey
static const char* kTIMGroupDeleteMemberResultIdentifier  = "group_delete_member_result_identifier"; // string, ֻ��, ɾ���ĳ�ԱID
static const char* kTIMGroupDeleteMemberResultResult      = "group_delete_member_result_result";     // uint [HandleGroupMemberResult](), ֻ��, ɾ�����
// EndStruct


/**
* @brief Ⱥ����Ϣ����ѡ��
*/    
enum TIMGroupReceiveMessageOpt {
    kTIMRecvGroupMsgOpt_ReceiveAndNotify,  // ����Ⱥ��Ϣ ����ʾ
    kTIMRecvGroupMsgOpt_NotReceive,        // ������Ⱥ��Ϣ, �������������ת��
    kTIMRecvGroupMsgOpt_ReceiveNotNotify,  // ����Ⱥ��Ϣ,����ʾ
};

/**
* @brief Ⱥ���ڱ��˵���Ϣ
*/
// Struct GroupSelfInfo JsonKey
static const char* kTIMGroupSelfInfoJoinTime   = "group_self_info_join_time";   // uint, ֻ��, ����Ⱥ��ʱ��
static const char* kTIMGroupSelfInfoRole       = "group_self_info_role";        // uint, ֻ��, �û���Ⱥ���еĽ�ɫ
static const char* kTIMGroupSelfInfoUnReadNum  = "group_self_info_unread_num";  // uint, ֻ��, ��Ϣδ������
static const char* kTIMGroupSelfInfoMsgFlag    = "group_self_info_msg_flag";    // uint [TIMGroupReceiveMessageOpt](), ֻ��, Ⱥ��Ϣ����ѡ��
// EndStruct

/**
* @brief ��ȡ�Ѽ���Ⱥ���б�ӿڵķ���(Ⱥ�������Ϣ)
*/
// Struct GroupBaseInfo JsonKey
static const char* kTIMGroupBaseInfoGroupId      = "group_base_info_group_id";       // string, ֻ��, Ⱥ��ID
static const char* kTIMGroupBaseInfoGroupName    = "group_base_info_group_name";     // string, ֻ��, Ⱥ������
static const char* kTIMGroupBaseInfoGroupType    = "group_base_info_group_type";     // string [TIMGroupType](), ֻ��, Ⱥ������
static const char* kTIMGroupBaseInfoFaceUrl      = "group_base_info_face_url";       // string, ֻ��, Ⱥ��ͷ��URL
static const char* kTIMGroupBaseInfoInfoSeq      = "group_base_info_info_seq";       // uint,   ֻ��, 
static const char* kTIMGroupBaseInfoLastestSeq   = "group_base_info_lastest_seq";    // uint,   ֻ��, 
static const char* kTIMGroupBaseInfoReadedSeq    = "group_base_info_readed_seq";     // uint,   ֻ��, 
static const char* kTIMGroupBaseInfoMsgFlag      = "group_base_info_msg_flag";       // uint,   ֻ��, 
static const char* kTIMGroupBaseInfoIsShutupAll  = "group_base_info_is_shutup_all";   // bool,   ֻ��, ��ǰȺ���Ƿ�������ȫԱ����
static const char* kTIMGroupBaseInfoSelfInfo     = "group_base_info_self_info";      // object [GroupSelfInfo](), ֻ��, �û�����Ⱥ�ĸ�����Ϣ
// EndStruct

/**
* @brief Ⱥ����ϸ��Ϣ
*/
// Struct GroupDetailInfo JsonKey
static const char* kTIMGroupDetialInfoGroupId          = "group_detial_info_group_id";           // string, ֻ��, Ⱥ��ID
static const char* kTIMGroupDetialInfoGroupType        = "group_detial_info_group_type";         // uint [TIMGroupType](), ֻ��, Ⱥ������
static const char* kTIMGroupDetialInfoGroupName        = "group_detial_info_group_name";         // string, ֻ��, Ⱥ������
static const char* kTIMGroupDetialInfoNotification     = "group_detial_info_notification";       // string, ֻ��, Ⱥ�鹫��
static const char* kTIMGroupDetialInfoIntroduction     = "group_detial_info_introduction";       // string, ֻ��, Ⱥ����
static const char* kTIMGroupDetialInfoFaceUrl          = "group_detial_info_face_url";           // string, ֻ��, Ⱥ��ͷ��URL
static const char* kTIMGroupDetialInfoCreateTime       = "group_detial_info_create_time";        // uint,   ֻ��, Ⱥ�鴴��ʱ��
static const char* kTIMGroupDetialInfoInfoSeq          = "group_detial_info_info_seq";           // uint,   ֻ��, 
static const char* kTIMGroupDetialInfoLastInfoTime     = "group_detial_info_last_info_time";     // uint,   ֻ��, Ⱥ����Ϣ����޸�ʱ��
static const char* kTIMGroupDetialInfoNextMsgSeq       = "group_detial_info_next_msg_seq";       // uint,   ֻ��,
static const char* kTIMGroupDetialInfoLastMsgTime      = "group_detial_info_last_msg_time";      // uint,   ֻ��, ����Ⱥ����Ϣʱ��
static const char* kTIMGroupDetialInfoMemberNum        = "group_detial_info_member_num";         // uint,   ֻ��, Ⱥ�鵱ǰ��Ա����
static const char* kTIMGroupDetialInfoMaxMemberNum     = "group_detial_info_max_member_num";     // uint,   ֻ��, Ⱥ������Ա����
static const char* kTIMGroupDetialInfoAddOption        = "group_detial_info_add_option";         // uint [TIMGroupAddOption](), ֻ��, Ⱥ���Ⱥѡ��
static const char* kTIMGroupDetialInfoOnlineMemberNum  = "group_detial_info_online_member_num";  // uint,   ֻ��, Ⱥ�����߳�Ա����
static const char* kTIMGroupDetialInfoVisible          = "group_detial_info_visible";            // uint,   ֻ��, Ⱥ���Ա�Ƿ����ɼ�
static const char* kTIMGroupDetialInfoSearchable       = "group_detial_info_searchable";         // uint,   ֻ��, Ⱥ���Ƿ��ܱ�����
static const char* kTIMGroupDetialInfoIsShutupAll      = "group_detial_info_is_shutup_all";      // bool,   ֻ��, Ⱥ���Ƿ�������ȫԱ����
static const char* kTIMGroupDetialInfoOwnerIdentifier  = "group_detial_info_owener_identifier";  // string, ֻ��, Ⱥ��������ID
static const char* kTIMGroupDetialInfoCustomInfo       = "group_detial_info_custom_info";        // object key string value string, ֻ��, ��ο�[�Զ����ֶ�](https://cloud.tencent.com/document/product/269/1502#.E8.87.AA.E5.AE.9A.E4.B9.89.E5.AD.97.E6.AE.B5)
// EndStruct

/**
* @brief ��ȡȺ����Ϣ�б�ӿڵķ���
*/
// Struct GetGroupInfoResult JsonKey
static const char* kTIMGetGroupInfoResultCode  = "get_groups_info_result_code";    // int [������](https://cloud.tencent.com/document/product/269/1671),   ֻ��, ��ȡȺ����ϸ��Ϣ�Ľ��
static const char* kTIMGetGroupInfoResultDesc  = "get_groups_info_result_desc";    // string, ֻ��,��ȡȺ����ϸʧ�ܵ�������Ϣ
static const char* kTIMGetGroupInfoResultInfo  = "get_groups_info_result_info";    // json object [GroupDetailInfo](), ֻ��, Ⱥ����ϸ��Ϣ
// EndStruct

/**
* @brief ����(�޸�)Ⱥ����Ϣ������
*/
enum TIMGroupModifyInfoFlag {
    kTIMGroupModifyInfoFlag_None         = 0x00,
    kTIMGroupModifyInfoFlag_Name         = 0x01,       // �޸�Ⱥ������,      
    kTIMGroupModifyInfoFlag_Notification = 0x01 << 1,  // �޸�Ⱥ����,        
    kTIMGroupModifyInfoFlag_Introduction = 0x01 << 2,  // �޸�Ⱥ���         
    kTIMGroupModifyInfoFlag_FaceUrl      = 0x01 << 3,  // �޸�Ⱥͷ��URL      
    kTIMGroupModifyInfoFlag_AddOption    = 0x01 << 4,  // �޸�Ⱥ�����ѡ��,  
    kTIMGroupModifyInfoFlag_MaxMmeberNum = 0x01 << 5,  // �޸�Ⱥ����Ա��,  
    kTIMGroupModifyInfoFlag_Visible      = 0x01 << 6,  // �޸�Ⱥ�Ƿ�ɼ�,    
    kTIMGroupModifyInfoFlag_Searchable   = 0x01 << 7,  // �޸�Ⱥ�Ƿ�����,  
    kTIMGroupModifyInfoFlag_ShutupAll    = 0x01 << 8,  // �޸�Ⱥ�Ƿ�ȫ�����,
    kTIMGroupModifyInfoFlag_Owner        = 0x01 << 31, // �޸�Ⱥ��
};

/**
* @brief ����Ⱥ��Ϣ�ӿڵĲ���
*/
// Struct GroupModifyInfoParam JsonKey
static const char* kTIMGroupModifyInfoParamGroupId           = "group_modify_info_param_group_id";        // string, ֻд(����), Ⱥ��ID
static const char* kTIMGroupModifyInfoParamModifyFlag        = "group_modify_info_param_modify_flag";     // uint [TIMGroupSetInfoFlag](),  ֻд(����), �޸ı�ʶ,�����ö��ֵ��λ��
static const char* kTIMGroupModifyInfoParamGroupName         = "group_modify_info_param_group_name";      // string, ֻд(ѡ��), �޸�Ⱥ������,       �� modify_flag ���� kTIMGroupModifyInfoFlag_Name ʱ����,�������������
static const char* kTIMGroupModifyInfoParamNotification      = "group_modify_info_param_notification";    // string, ֻд(ѡ��), �޸�Ⱥ����,         �� modify_flag ���� kTIMGroupModifyInfoFlag_Notification ʱ����,�������������
static const char* kTIMGroupModifyInfoParamIntroduction      = "group_modify_info_param_introduction";    // string, ֻд(ѡ��), �޸�Ⱥ���,         �� modify_flag ���� kTIMGroupModifyInfoFlag_Introduction ʱ����,�������������  
static const char* kTIMGroupModifyInfoParamFaceUrl           = "group_modify_info_param_face_url";        // string, ֻд(ѡ��), �޸�Ⱥͷ��URL,      �� modify_flag ���� kTIMGroupModifyInfoFlag_FaceUrl ʱ����,�������������
static const char* kTIMGroupModifyInfoParamAddOption         = "group_modify_info_param_add_option";      // uint,  ֻд(ѡ��), �޸�Ⱥ�����ѡ��,    �� modify_flag ���� kTIMGroupModifyInfoFlag_AddOption ʱ����,�������������
static const char* kTIMGroupModifyInfoParamMaxMemberNum      = "group_modify_info_param_max_member_num";  // uint,  ֻд(ѡ��), �޸�Ⱥ����Ա��,    �� modify_flag ���� kTIMGroupModifyInfoFlag_MaxMmeberNum ʱ����,�������������
static const char* kTIMGroupModifyInfoParamVisible           = "group_modify_info_param_visible";         // uint,  ֻд(ѡ��), �޸�Ⱥ�Ƿ�ɼ�,      �� modify_flag ���� kTIMGroupModifyInfoFlag_Visible ʱ����,�������������
static const char* kTIMGroupModifyInfoParamSearchAble        = "group_modify_info_param_searchable";      // uint,  ֻд(ѡ��), �޸�Ⱥ�Ƿ�����,    �� modify_flag ���� kTIMGroupModifyInfoFlag_Searchable ʱ����,�������������
static const char* kTIMGroupModifyInfoParamIsShutupAll       = "group_modify_info_param_is_shutup_all";   // bool,   ֻд(ѡ��), �޸�Ⱥ�Ƿ�ȫ�����, �� modify_flag ���� kTIMGroupModifyInfoFlag_ShutupAll ʱ����,�������������
static const char* kTIMGroupModifyInfoParamOwner             = "group_modify_info_param_owner";           // string, ֻд(ѡ��), �޸�Ⱥ��������,     �� modify_flag ���� kTIMGroupModifyInfoFlag_Owner ʱ����,��������������ʱ modify_flag ���ܰ�������ֵ�����޸�Ⱥ��ʱ��ͬʱ�޸�������Ϣ��������
static const char* kTIMGroupModifyInfoParamCustomInfo        = "group_modify_info_param_custom_info";     // object key string value string, ֻд(ѡ��), ��ο�[�Զ����ֶ�](https://cloud.tencent.com/document/product/269/1502#.E8.87.AA.E5.AE.9A.E4.B9.89.E5.AD.97.E6.AE.B5)
// EndStruct

/**
* @brief ��ȡȺ��Ա�б�ӿڵĲ���
*/
// Struct GroupGetMemberInfoListParam JsonKey
static const char* kTIMGroupGetMemberInfoListParamGroupId         = "group_get_members_info_list_param_group_id";          // string,       ֻд(����), Ⱥ��ID
static const char* kTIMGroupGetMemberInfoListParamIdentifierArray = "group_get_members_info_list_param_identifier_array";  // array string, ֻд(ѡ��), Ⱥ��ԱID�б�
static const char* kTIMGroupGetMemberInfoListParamOption          = "group_get_members_info_list_param_option";            // object [GroupMemberGetInfoOption](), ֻд(ѡ��), ��ȡȺ��Ա��Ϣ��ѡ��
static const char* kTIMGroupGetMemberInfoListParamNextSeq         = "group_get_members_info_list_param_next_seq";          // uint64, ֻд(ѡ��), ��ҳ��ȡ��־,��һ����ȡ��0,�ص��ɹ������Ϊ��,��Ҫ��ҳ,�����ٴ���ȡ,ֱ��Ϊ0
// EndStruct

/**
* @brief ��ȡȺ��Ա�б�ӿڵķ���
*/
// Struct GroupGetMemberInfoListResult JsonKey
static const char* kTIMGroupGetMemberInfoListResultNexSeq     = "group_get_memeber_info_list_result_next_seq";   // uint64, ֻ��, ��һ����ȡ�ı�־,server����0��ʾû�и��������,�������´λ�ȡ����ʱ���������־
static const char* kTIMGroupGetMemberInfoListResultInfoArray  = "group_get_memeber_info_list_result_info_array"; // array [GroupMemberInfo](), ֻ��, ��Ա��Ϣ�б�
// EndStruct


/**
* @brief ����(�޸�)Ⱥ��Ա��Ϣ������
*/
enum TIMGroupMemberModifyInfoFlag {
    kTIMGroupMemberModifyFlag_None       = 0x00,      // 
    kTIMGroupMemberModifyFlag_MsgFlag    = 0x01,      // �޸���Ϣ����ѡ��
    kTIMGroupMemberModifyFlag_MemberRole = 0x01 << 1, // �޸ĳ�Ա��ɫ
    kTIMGroupMemberModifyFlag_ShutupTime = 0x01 << 2, // �޸Ľ���ʱ��
    kTIMGroupMemberModifyFlag_NameCard   = 0x01 << 3, // �޸�Ⱥ��Ƭ
};


/**
* @brief ����Ⱥ��Ա��Ϣ�ӿڵĲ���
*/
// Struct GroupModifyMemberInfoParam JsonKey
static const char* kTIMGroupModifyMemberInfoParamGroupId     = "group_modify_member_info_group_id";       // string, ֻд(����), Ⱥ��ID
static const char* kTIMGroupModifyMemberInfoParamIdentifier  = "group_modify_member_info_identifier";     // string, ֻд(����), ��������Ϣ�ĳ�ԱID
static const char* kTIMGroupModifyMemberInfoParamModifyFlag  = "group_modify_member_info_modify_flag";    // uint [TIMGroupMemberModifyInfoFlag](), ֻд(����), �޸�����,�����ö��ֵ��λ��
static const char* kTIMGroupModifyMemberInfoParamMsgFlag     = "group_modify_member_info_msg_flag";       // uint,   ֻд(ѡ��), �޸���Ϣ����ѡ��,                  �� modify_flag ���� kTIMGroupMemberModifyFlag_MsgFlag ʱ����,�������������
static const char* kTIMGroupModifyMemberInfoParamMemberRole  = "group_modify_member_info_member_role";    // uint [TIMGroupMemberRole](), ֻд(ѡ��), �޸ĳ�Ա��ɫ, �� modify_flag ���� kTIMGroupMemberModifyFlag_MemberRole ʱ����,�������������
static const char* kTIMGroupModifyMemberInfoParamShutupTime  = "group_modify_member_info_shutup_time";    // uint,   ֻд(ѡ��), �޸Ľ���ʱ��,                      �� modify_flag ���� kTIMGroupMemberModifyFlag_ShutupTime ʱ����,�������������
static const char* kTIMGroupModifyMemberInfoParamNameCard    = "group_modify_member_info_name_card";      // string, ֻд(ѡ��), �޸�Ⱥ��Ƭ,                        �� modify_flag ���� kTIMGroupMemberModifyFlag_NameCard ʱ����,�������������
static const char* kTIMGroupModifyMemberInfoParamCustomInfo  = "group_modify_member_info_custom_info";    // object key string value string, ֻд(ѡ��), ��ο�[�Զ����ֶ�](https://cloud.tencent.com/document/product/269/1502#.E8.87.AA.E5.AE.9A.E4.B9.89.E5.AD.97.E6.AE.B5)
// EndStruct

/**
* @brief ��ȡȺδ����Ϣ�б�Ĳ���
*/
// Struct GroupPendencyOption JsonKey
static const char* kTIMGroupPendencyOptionStartTime     = "group_pendency_option_start_time";       // uint64, ֻд(����), ������ȡʱ���,��һ��������0,��߸���server���ص�[GroupPendencyResult]()��kTIMGroupPendencyResultNextStartTimeָ����ʱ���������д
static const char* kTIMGroupPendencyOptionMaxLimited    = "group_pendency_option_max_limited";      // uint,   ֻд(ѡ��), ��ȡ�Ľ�������,server�ɸ�����Ҫ���ػ�����,������Ϊ������ı�־
// EndStruct


/**
* @brief δ����������
*/
enum TIMGroupPendencyType {
    kTIMGroupPendency_RequestJoin = 0,  // �����Ⱥ
    kTIMGroupPendency_InviteJoin = 1,   // �����Ⱥ
    kTIMGroupPendency_ReqAndInvite = 2, // ����������
};

/**
* @brief Ⱥδ������״̬
*/
enum TIMGroupPendencyHandle {
    kTIMGroupPendency_NotHandle = 0,      // δ����
    kTIMGroupPendency_OtherHandle = 1,    // ���˴���
    kTIMGroupPendency_OperatorHandle = 2, // ����������
};

/**
* @brief Ⱥδ�������������
*/
enum TIMGroupPendencyHandleResult {
    kTIMGroupPendency_Refuse = 0,  // �ܾ�
    kTIMGroupPendency_Accept = 1,  // ͬ��
};

/**
* @brief Ⱥδ����Ϣ����
*/
// Struct GroupPendency JsonKey
static const char* kTIMGroupPendencyGroupId             = "group_pendency_group_id";                //string,  ��д, Ⱥ��ID
static const char* kTIMGroupPendencyFromIdentifier      = "group_pendency_form_identifier";         //string,  ��д, �����ߵ�ID,���磺�����Ⱥ:������,�����Ⱥ:�����ˡ�
static const char* kTIMGroupPendencyToIdentifier        = "group_pendency_to_identifier";           //string,  ��д, �о��ߵ�ID,�����Ⱥ:"",�����Ⱥ:�������ˡ�
static const char* kTIMGroupPendencyAddTime             = "group_pendency_add_time";                //uint64,  ֻ��, δ����Ϣ���ʱ��
static const char* kTIMGroupPendencyPendencyType        = "group_pendency_pendency_type";           //uint [TIMGroupPendencyType](),  ֻ��, δ����������
static const char* kTIMGroupPendencyHandled             = "group_pendency_handled";                 //uint [TIMGroupPendencyHandle](),ֻ��, Ⱥδ������״̬
static const char* kTIMGroupPendencyHandleResult        = "group_pendency_handle_result";           //uint [TIMGroupPendencyHandleResult](), ֻ��, Ⱥδ�������������
static const char* kTIMGroupPendencyApplyInviteMsg      = "group_pendency_apply_invite_msg";        //string, ֻ��, ��������븽����Ϣ
static const char* kTIMGroupPendencyFromUserDefinedData = "group_pendency_form_user_defined_data";  //string, ֻ��, ������������Զ����ֶ�
static const char* kTIMGroupPendencyApprovalMsg         = "group_pendency_approval_msg";            //string, ֻ��, ������Ϣ��ͬ���ܾ���Ϣ
static const char* kTIMGroupPendencyToUserDefinedData   = "group_pendency_to_user_defined_data";    //string, ֻ��, �������Զ����ֶ�
// EndStruct

/**
* @brief ��ȡȺδ����Ϣ�б�ķ���
*/
// Struct GroupPendencyResult JsonKey
static const char* kTIMGroupPendencyResultNextStartTime = "group_pendency_result_next_start_time";  // uint64, ֻ��, ��һ����ȡ����ʼʱ��,server����0��ʾû�и��������,�������´λ�ȡ����ʱ�����ʱ�����Ϊ��ʼʱ���
static const char* kTIMGroupPendencyResultReadTimeSeq   = "group_pendency_result_read_time_seq";    // uint64, ֻ��, �Ѷ��ϱ���ʱ���
static const char* kTIMGroupPendencyResultUnReadNum     = "group_pendency_result_unread_num";       // uint,   ֻ��, δ�������δ���� ?
static const char* kTIMGroupPendencyResultPendencyArray = "group_pendency_result_pendency_array";   // array [GroupPendency](), ֻ��, Ⱥδ����Ϣ�б�
// EndStruct

/**
* @brief ����Ⱥδ����Ϣ�ӿڵĲ���
*/
// Struct GroupHandlePendencyParam JsonKey
static const char* kTIMGroupHandlePendencyParamIsAccept   = "group_handle_pendency_param_is_accept";  // bool,   ֻд(ѡ��), true��ʾ���ܣ�false��ʾ�ܾ���Ĭ��Ϊfalse
static const char* kTIMGroupHandlePendencyParamHandleMsg  = "group_handle_pendency_param_handle_msg"; // string, ֻд(ѡ��), ͬ���ܾ���Ϣ,Ĭ��Ϊ���ַ���
static const char* kTIMGroupHandlePendencyParamPendency   = "group_handle_pendency_param_pendency";   // object [GroupPendency](), ֻд(����), δ����Ϣ����
// EndStruct

/// @}

#endif //SDK_TIM_CLOUD_DEF_HEADER_
