#ifndef SDK_CLOUD_TIM_HEADER_
#define SDK_CLOUD_TIM_HEADER_
#include "TIMCloudDef.h"
#include "TIMCloudCallback.h"

#ifdef __cplusplus
extern"C"
{
#endif

/// @overview TIMCloud
/// @overbrief ��Ѷ��ʱͨ��IM�Ŀ�ƽ̨C�ӿ�(API)
/*
* @brief ����ƽ̨����������
* > Windowsƽ̨[ImSDK](https://github.com/tencentyun/TIMSDK/tree/master/cross-platform/Windows),Windows���ٿ�ʼ[����ImSDK](https://cloud.tencent.com/document/product/269/33489)��[һ������ͨDemo](https://cloud.tencent.com/document/product/269/36838).֧��32λ/64λϵͳ��
* > iOSƽ̨[ImSDK](https://github.com/tencentyun/TIMSDK/tree/master/cross-platform/iOS).
* > Macƽ̨[ImSDK](https://github.com/tencentyun/TIMSDK/tree/master/cross-platform/Mac).
* > Androidƽ̨[ImSDK](https://github.com/tencentyun/TIMSDK/tree/master/cross-platform/Android).
*
* @brief ���ڻص���˵��
* > �ص������֣�һ����ָ���ýӿڵ��첽���أ�����һ��ָ��̨���͵�֪ͨ���ص���ImSDK�ڲ����߼��̴߳����������ýӿڵ��߳̿��ܲ���ͬһ�߳�
* > ��Windowsƽ̨���������[TIMInit]()�ӿڽ��г�ʼ��ImSDK֮ǰ���Ѵ�����UI����Ϣѭ�����ҵ���[TIMInit]()�ӿڵ��߳�Ϊ��UI�̣߳���ImSDK�ڲ��Ὣ�ص��׵���UI�̵߳���
*
* @brief ע��
* > ����ӿڵĲ����ַ����������ģ���ʹ��UTF-8����
*/

/////////////////////////////////////////////////////////////////////////////////
//
//  ע��SDK�ص�
//
/////////////////////////////////////////////////////////////////////////////////
/// @name �¼��ص��ӿ�
/// @{
/**
* @brief ���ӽ�������Ϣ�ص�
* @param cb ����Ϣ�ص���������ο�[TIMRecvNewMsgCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* 
* @note 
* ����û��ǵ�¼״̬��ImSDK�յ�����Ϣ��ͨ���˽ӿ����õĻص��׳���������Ҫע�⣬�׳�����Ϣ��һ����δ������Ϣ��
* ֻ�Ǳ�������û�й�����Ϣ������������һ���ն��Ѷ�����ȡ�����ϵ����Ϣʱ���Ի�ȡ�Ự���һ����Ϣ���������û�У���ͨ���˷����׳�����
* ���û���¼֮��ImSDK����ȡ������Ϣ��Ϊ�˲�©����Ϣ֪ͨ����Ҫ�ڵ�¼֮ǰע������Ϣ֪ͨ��
*/
TIM_DECL void TIMAddRecvNewMsgCallback(TIMRecvNewMsgCallback cb, const void* user_data);

/**
* @brief ɾ����������Ϣ�ص�
* @param cb ����Ϣ�ص���������ο�[TIMRecvNewMsgCallback](TIMCloudCallback.h)
*
* @note
* ����cb��Ҫ��[TIMAddRecvNewMsgCallback]()�����cbһ�£�����ɾ���ص�ʧ��
*/
TIM_DECL void TIMRemoveRecvNewMsgCallback(TIMRecvNewMsgCallback cb);

/**
* @brief ������Ϣ�Ѷ���ִ�ص�
* @param cb ��Ϣ�Ѷ���ִ�ص�����ο�[TIMMsgReadedReceiptCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* 
* @note 
* ���ͷ�������Ϣ�����շ����ýӿ�[TIMMsgReportReaded]()�ϱ�����Ϣ�Ѷ������ͷ�ImSDK��ͨ���˽ӿ����õĻص��׳���
*/
TIM_DECL void TIMSetMsgReadedReceiptCallback(TIMMsgReadedReceiptCallback cb, const void* user_data);

/**
* @brief ���ý��յ���Ϣ�����ػص�
* @param cb ��Ϣ����֪ͨ�ص�,��ο�[TIMMsgRevokeCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* 
* @note 
* ���ͷ�������Ϣ�����շ��յ���Ϣ����ʱ���ͷ����ýӿ�[TIMMsgRevoke]()���ظ���Ϣ�����շ���ImSDK��ͨ���˽ӿ����õĻص��׳���
*/
TIM_DECL void TIMSetMsgRevokeCallback(TIMMsgRevokeCallback cb, const void* user_data);

/**
* @brief ������Ϣ��Ԫ������ļ��ϴ����Ȼص�
* @param cb �ļ��ϴ����Ȼص�����ο�[TIMMsgElemUploadProgressCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* 
* @note
* ������ϢԪ���ϴ����Ȼص�������Ϣ�ڰ���ͼƬ���������ļ�����ƵԪ��ʱ��ImSDK���ϴ���Щ�ļ����������˽ӿ����õĻص����û����Ը��ݻص���֪�ϴ��Ľ���
*/
TIM_DECL void TIMSetMsgElemUploadProgressCallback(TIMMsgElemUploadProgressCallback cb, const void* user_data);

/**
* @brief ����Ⱥ��ϵͳ��Ϣ�ص�
* @param cb Ⱥ��Ϣ�ص�����ο�[TIMGroupTipsEventCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* 
* @note 
* Ⱥ��ϵͳ��Ϣ�¼����� ����Ⱥ���˳�Ⱥ���߳�Ⱥ�����ù���Ա��ȡ������Ա��Ⱥ���ϱ����Ⱥ��Ա���ϱ��������Ϣ���������Ⱥ���Ա�·���
*/
TIM_DECL void TIMSetGroupTipsEventCallback(TIMGroupTipsEventCallback cb, const void* user_data);

/**
* @brief ���ûỰ�¼��ص�
* @param cb �Ự�¼��ص�����ο�[TIMConvEventCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
*
* @note
* > �Ự�¼�������
* >> �Ự����
* >> �Ựɾ��
* >> �Ự���¡�
* > �κβ���һ���»Ự�Ĳ������ᴥ���Ự�����¼���������ýӿ�[TIMConvCreate]()�����Ự�����յ�δ֪�Ự�ĵ�һ����Ϣ�ȡ�
* �κ����лỰ�仯�Ĳ������ᴥ���Ự�����¼��������յ��Ự����Ϣ����Ϣ���أ��Ѷ��ϱ��ȡ�
* ���ýӿ�[TIMConvDelete]()ɾ���Ự�ɹ�ʱ�ᴥ���Ựɾ���¼���
*/
TIM_DECL void TIMSetConvEventCallback(TIMConvEventCallback cb, const void* user_data);

/**
* @brief ������������״̬�����ص�
* @param cb �����¼��ص�����ο�[TIMNetworkStatusListenerCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* 
* @note
* > �����ýӿ� [TIMInit]() ʱ��ImSDK��ȥ�����ƺ�̨���˽ӿ����õĻص����ڼ����������ӵ�״̬��
* > ��������״̬�����ĸ����������ӡ�����ʧ�ܡ����ӳɹ��������ӡ�����������¼�����ʾ�û���������״̬����ָ��ImSDK�Ƿ��뼴ʱͨ��IM��Server����״̬��
* > ��ѡ���ã����Ҫ�û���֪�Ƿ��Ѿ����ӷ���������Ҫ���ô˻ص�������֪ͨ�����߸�ͨѶ��̨���ӵ����ӺͶϿ��¼������⣬����Ͽ����磬������ָ�����Զ��������Զ���ȡ��Ϣ֪ͨ�û����û������������״̬������֪֮ͨ��
* > ֻҪ�û����ڵ�¼״̬��ImSDK�ڲ�����ж����������û�������ġ�
*/
TIM_DECL void TIMSetNetworkStatusListenerCallback(TIMNetworkStatusListenerCallback cb, const void* user_data);

/**
* @brief ���ñ�������֪ͨ�ص�
* @param cb �����߻ص�����ο�[TIMKickedOfflineCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* 
* @note
* > �û�����������ն˵�¼���ᱻ�����ߣ���ʱ���յ��û��������ߵ�֪ͨ��������������������������ʾ�û����в������˳��������ٴΰѶԷ������ߣ���
* > �û����������״̬�±��ߣ��´ε�¼����ʧ�ܣ����Ը��û�һ���ǳ�ǿ�����ѣ���¼������ERR_IMSDK_KICKED_BY_OTHERS��6208����������Ҳ����ѡ�������δ����ٴε�¼���ɡ�
* > �û���������µĻ��������
* +  �û����豸1��¼����������״̬�£����û������豸2��¼����ʱ�û������豸1��ǿ�����ߣ��յ� TIMKickedOfflineCallback �ص���
*    �û����豸1���յ��ص�����ʾ�û����ɼ�������login���ߣ�ǿ���豸2���ߡ���������������»��߹��̡�
* > �û�����״̬����:
* +  �û����豸1��¼��û�н���logout����½����˳������û����豸2��¼����ʱ�����û������ߣ��޷���֪���¼���
*    Ϊ����ʽ�����û��������޸�֪�Ļ��ߣ��û����豸1���µ�¼ʱ���᷵�أ�ERR_IMSDK_KICKED_BY_OTHERS��6208�������룬����֮ǰ���ߣ��Ƿ���Ҫ�ѶԷ������ߡ�
*    �����Ҫ�����ٴε���loginǿ�����ߣ��豸2�ĵ�¼��ʵ�������յ� TIMKickedOfflineCallback �ص���
*/
TIM_DECL void TIMSetKickedOfflineCallback(TIMKickedOfflineCallback cb, const void* user_data);

/**
* @brief ����Ʊ�ݹ��ڻص�
* @param cb Ʊ�ݹ��ڻص�����ο�[TIMUserSigExpiredCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
*
* @note
* �û�Ʊ�ݣ����ܻ���ڹ��ڵ����������û�Ʊ�ݹ��ڣ��˽ӿ����õĻص�����á�
* [TIMLogin]()Ҳ���᷵��70001�����롣�����߿ɸ��ݴ��������Ʊ�ݹ��ڻص�����Ʊ�ݸ���
*/
TIM_DECL void TIMSetUserSigExpiredCallback(TIMUserSigExpiredCallback cb, const void* user_data);

/**
* @brief ������Ӻ��ѵĻص�
* @param cb ��Ӻ��ѻص�����ο�[TIMOnAddFriendCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
*
* @note
* �˻ص�Ϊ�˶��ն�ͬ��������A�豸��B�豸����¼��ͬһ�˺ŵ�ImSDK��A�豸����˺��ѣ�B�豸ImSDK���յ���Ӻ��ѵ����ͣ�ImSDKͨ���˻ص���֪�����ߡ�
*/
TIM_DECL void TIMSetOnAddFriendCallback(TIMOnAddFriendCallback cb, const void* user_data);

/**
* @brief ����ɾ�����ѵĻص�
* @param cb ɾ�����ѻص�����ο�[TIMOnDeleteFriendCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
*
* @note
* �˻ص�Ϊ�˶��ն�ͬ��������A�豸��B�豸����¼��ͬһ�˺ŵ�ImSDK��A�豸ɾ���˺��ѣ�B�豸ImSDK���յ�ɾ�����ѵ����ͣ�ImSDKͨ���˻ص���֪�����ߡ�
*/
TIM_DECL void TIMSetOnDeleteFriendCallback(TIMOnDeleteFriendCallback cb, const void* user_data);

/**
* @brief ���ø��º������ϵĻص�
* @param cb ���º������ϻص�����ο�[TIMUpdateFriendProfileCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
*
* @note
* �˻ص�Ϊ�˶��ն�ͬ��������A�豸��B�豸����¼��ͬһ�˺ŵ�ImSDK��A�豸�����˺������ϣ�B�豸ImSDK���յ������º������ϵ����ͣ�ImSDKͨ���˻ص���֪�����ߡ�
*/
TIM_DECL void TIMSetUpdateFriendProfileCallback(TIMUpdateFriendProfileCallback cb, const void* user_data);

/**
* @brief ���ú����������Ļص�
* @param cb �����������ص�����ο�[TIMFriendAddRequestCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
*
* @note
* ��ǰ�����û�������Ӻ�����Ҫȷ��ʱ��������û�����ӵ�ǰ�����û�Ϊ���ѣ����յ������������Ļص���ImSDKͨ���˻ص���֪�����ߡ�������ն˵���ͬһ�˺ţ�ÿ���ն˶����յ�����ص���
*/
TIM_DECL void TIMSetFriendAddRequestCallback(TIMFriendAddRequestCallback cb, const void* user_data);

/**
* @brief ������־�ص�
* @param cb ��־�ص�����ο�[TIMLogCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
*
* @note
* ������־�����Ļص�֮��ImSDK�ڲ�����־��ش����˽ӿ����õĻص���
* �����߿���ͨ���ӿ�[TIMSetConfig]()������Щ��־�������־�ش����ص�������
*/
TIM_DECL void TIMSetLogCallback(TIMLogCallback cb, const void* user_data);

/**
* @brief ������Ϣ���ƶ˱��޸ĺ�ش���������Ϣ����֪ͨ�ص�
* @param cb ��Ϣ���»ص�����ο�[TIMMsgUpdateCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* 
* @note 
* > �������͵���Ϣ�ڷ���˱��޸ĺ�ImSDK��ͨ���ûص�֪ͨ���� 
* > �����������Լ��ķ��������������м�ʱͨ��IM��Ϣ [��������Ϣ֮ǰ�ص�](https://cloud.tencent.com/document/product/269/1632)
* > ���óɹ�֮�󣬼�ʱͨ��IM�������Ὣ�����û����͵�ÿ����Ϣ��ͬ����֪ͨ������ҵ���������
* > ����ҵ����������ԶԸ�����Ϣ�����޸ģ�����������дʣ���������ķ���������Ϣ�������޸ģ�ImSDK�ͻ�ͨ���˻ص�֪ͨ����
*/
TIM_DECL void TIMSetMsgUpdateCallback(TIMMsgUpdateCallback cb, const void* user_data);
/// @}


/////////////////////////////////////////////////////////////////////////////////
//
//                       ImSDK��ʼ��
//
/////////////////////////////////////////////////////////////////////////////////
/// @name ImSDK��ʼ����ؽӿ�
/// @{
/**
* @brief ImSDK��ʼ��
*
* @param sdk_app_id ���������SDKAppid
* @param json_sdk_config ImSDK����ѡ��Json�ַ���,������ο�[SdkConfig](TIMCloudDef.h)
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
* 
* @example
* Json::Value json_value_init;
* json_value_init[kTIMSdkConfigLogFilePath] = "D:\\";
* json_value_init[kTIMSdkConfigConfigFilePath] = "D:\\";
* 
* uint64_t sdk_app_id = 1234567890;
* if (TIM_SUCC != TIMInit(sdk_app_id, json_value_init.toStyledString().c_str())) {
*     // TIMInit �ӿڵ��ô���ImSDK��ʼ��ʧ��   
* }
* 
* // json_value_init.toStyledString() �õ� json_sdk_config JSON �ַ�������
* {
*    "sdk_config_config_file_path" : "D:\\",
*    "sdk_config_log_file_path" : "D:\\"
* }
* 
* @note 
* > ��ʹ��ImSDK��һ������֮ǰ����Ҫ�ȳ�ʼ��ImSDK
* > json_sdk_config ����Ϊ NULL ���ַ���ָ�����""���ַ������ڴ������SdkConfig��ΪĬ��ֵ��
* > json_sdk_config �����ÿ��Json key����ѡ��ģ�������ο�[SdkConfig](TIMCloudDef.h)
* 
*/
TIM_DECL int TIMInit(uint64_t sdk_app_id, const char* json_sdk_config);

/**
* @brief  ImSDKж��
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
* 
* @example
* if (TIM_SUCC != TIMUninit()) {
*     // ImSDKж��ʧ��  
* }
* @note
* ж��DLL���˳�����ǰ��˽ӿ�ж��ImSDK������ImSDK�����Դ
*
*/
TIM_DECL int TIMUninit(void);

/**
* @brief  ��ȡImSDK�汾��
* @return const char* ����ImSDK�İ汾��
*/
TIM_DECL const char* const TIMGetSDKVersion(void);

/**
* @brief  ���ö�����û�����
* @param json_config ����ѡ��
* @param cb ������������֮���������õĻص����˻ص�cb��Ϊ�գ���ʾ����ȡ����������Ϣ���ص���������Ͳ���������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_user_config;
* json_user_config[kTIMUserConfigIsReadReceipt] = true;  // �����Ѷ���ִ
* Json::Value json_config;
* json_config[kTIMSetConfigUserConfig] = json_user_config;
*
* if (TIM_SUCC != TIMSetConfig(json_config.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*     // �ص��ڲ�
* }, this)) {
*     //TIMSetConfig�ӿڵ���ʧ��
* } 
*
* // json_config.toStyledString().c_str() �õ� json_config JSON �ַ�������
* {
*    "set_config_user_config" : {
*       "user_config_is_read_receipt" : true
*    }
* }
*
* @example ����Http����
* Json::Value json_http_proxy;
* json_http_proxy[kTIMHttpProxyInfoIp] = "http://http-proxy.xxxxx.com";
* json_http_proxy[kTIMHttpProxyInfoPort] = 8888;
* Json::Value json_config;
* json_config[kTIMSetConfigHttpProxyInfo] = json_http_proxy;
*
* if (TIM_SUCC != TIMSetConfig(json_config.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*     // �ص��ڲ�
* }, this)) {
*     // TIMSetConfig�ӿڵ���ʧ��
* }
*
* @example ȡ��Http����
* Json::Value json_http_proxy;
* json_http_proxy[kTIMHttpProxyInfoIp] = "";
* json_http_proxy[kTIMHttpProxyInfoPort] = 0;
* Json::Value json_config;
* json_config[kTIMSetConfigHttpProxyInfo] = json_http_proxy;
*
* if (TIM_SUCC != TIMSetConfig(json_config.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*     // �ص��ڲ�
* }, this)) {
*     // TIMSetConfig�ӿڵ���ʧ��
* }
*
* @example ����socks5����
* Json::Value json_socks5_value;
* json_socks5_value[kTIMSocks5ProxyInfoIp] = "111.222.333.444";
* json_socks5_value[kTIMSocks5ProxyInfoPort] = 8888;
* json_socks5_value[kTIMSocks5ProxyInfoUserName] = "";
* json_socks5_value[kTIMSocks5ProxyInfoPassword] = "";
* Json::Value json_config;
* json_config[kTIMSetConfigSocks5ProxyInfo] = json_socks5_value;
*
* if (TIM_SUCC != TIMSetConfig(json_config.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*     // �ص��ڲ�
* }, this)) {
*     //TIMSetConfig�ӿڵ���ʧ��
* }
*
* @example ȡ��socks5����
* Json::Value json_socks5_value;
* json_socks5_value[kTIMSocks5ProxyInfoIp] = "";
* json_socks5_value[kTIMSocks5ProxyInfoPort] = 0;
* json_socks5_value[kTIMSocks5ProxyInfoUserName] = "";
* json_socks5_value[kTIMSocks5ProxyInfoPassword] = "";
* Json::Value json_config;
* json_config[kTIMSetConfigSocks5ProxyInfo] = json_socks5_value;
*
* if (TIM_SUCC != TIMSetConfig(json_config.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*     // �ص��ڲ�
* }, this)) {
*     //TIMSetConfig�ӿڵ���ʧ��
* }
* 
* @note
* json_config ������ NULL ���ַ���ָ�����""���ַ�������ʱ���ص�cb��Ϊ�գ���ͨ���ص�cb�����ص�ǰ���е�������Ϣ��
* Ŀǰ֧�����õ�������http�����IP�Ͷ˿ڡ�socks5�����IP�Ͷ˿ڡ������־�ļ��𡢻�ȡȺ��Ϣ/Ⱥ��Ա��Ϣ��Ĭ��ѡ��Ƿ������Ϣ�Ѷ���ִ�¼��ȡ�
* http�����IP�Ͷ˿ڡ�socks5�����IP�Ͷ˿ڽ������[TIMInit]()֮ǰ���á�
* ÿ�����ÿ��Ե������ã�Ҳ����һ������,������ο� [SetConfig](TIMCloudDef.h)��
*/
TIM_DECL int TIMSetConfig(const char* json_config, TIMCommCallback cb, const void* user_data);
/// @}


/////////////////////////////////////////////////////////////////////////////////
//
//                       ��¼/�ǳ�
//
/////////////////////////////////////////////////////////////////////////////////
/// @name ��¼�ǳ���ؽӿ�
/// @{
/**
* @brief ��¼
*
* @param user_id �û���indentifier
* @param user_sig �û���sig
* @param cb ��¼�ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @note 
* �û���¼��Ѷ��̨����������������շ���Ϣ����¼��Ҫ�û��ṩidentifier��userSig����Ϣ�����庬����ο�[��¼��Ȩ](https://cloud.tencent.com/document/product/269/31999)
*/
TIM_DECL int TIMLogin(const char* user_id, const char* user_sig, TIMCommCallback cb, const void* user_data);

/**
* @brief  �ǳ�
*
* @param cb �ǳ��ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @note
* ���û������ǳ�����Ҫ�����û����л�������Ҫ���õǳ�����
*/
TIM_DECL int TIMLogout(TIMCommCallback cb, const void* user_data);
/// @}


/////////////////////////////////////////////////////////////////////////////////
//
//                       �Ự��ؽӿ�
//
/////////////////////////////////////////////////////////////////////////////////
/// @name �Ự��ؽӿ�
/*
* @brief
* ImSDK�лỰ��Conversation����Ϊ����
* > C2C�Ự����ʾ��������Լ���Է������ĶԻ�����ȡ��Ϣ�ͷ�����Ϣ����ͨ���Ự���
* > Ⱥ�Ự����ʾȺ������£�Ⱥ�ڳ�Ա��ɵĻỰ��Ⱥ�Ự�ڷ�����ϢȺ��Ա���ɽ��յ���
*/
/// @{
/**
* @brief �����Ự
*
* @param conv_id   �Ự��ID
* @param conv_type �Ự���ͣ���ο�[TIMConvType](TIMCloudDef.h)
* @param cb �����Ự�Ļص����ص���������Ͳ���������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example ��ȡ�Է�identifierΪWindows-02�ĵ��ĻỰʾ��
* const void* user_data = nullptr; // �ص������ش�
* const char* userid = "Windows-02";
* int ret = TIMConvCreate(userid, kTIMConv_C2C, [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*     if (ERR_SUCC != code) {
*         return;
*     }
*     // �ص����ػỰ�ľ�����Ϣ
* }, user_data);
* if (ret != TIM_SUCC) {
*     // ���� TIMConvCreate �ӿ�ʧ��
* }
* 
* @example ��ȡȺ��IDΪWindows-Group-01��Ⱥ�ĻỰʾ��
* const void* user_data = nullptr; // �ص������ش�
* const char* userid = "Windows-Group-01";
* int ret = TIMConvCreate(userid, kTIMConv_Group, [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*     if (ERR_SUCC != code) {
*         return;
*     }
*     // �ص����ػỰ�ľ�����Ϣ
* }, user_data);
* if (ret != TIM_SUCC) {
*     // ���� TIMConvCreate �ӿ�ʧ��
* }
* 
* @note
* > �Ự��ָ����һ���˻���һ��Ⱥ��ĶԻ���ͨ���뵥���˻�Ⱥ��֮��Ự�շ���Ϣ
* > �˽ӿڴ������߻�ȡ�Ự��Ϣ����Ҫָ���Ự���ͣ�Ⱥ����ߵ��ģ����Լ��Ự�Է���־���Է��ʺŻ���Ⱥ�ţ����Ự��Ϣͨ��cb�ش���
*/
TIM_DECL int TIMConvCreate(const char* conv_id, enum TIMConvType conv_type, TIMCommCallback cb, const void* user_data); 

/**
* @brief ɾ���Ự
*
* @param conv_id   �Ự��ID
* @param conv_type �Ự���ͣ���ο�[TIMConvType](TIMCloudDef.h)
* @param cb ɾ���Ự�ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @note
* �˽ӿ�����ɾ���Ự��ɾ���Ự�Ƿ�ɹ�ͨ���ص����ء�
*/
TIM_DECL int TIMConvDelete(const char* conv_id, enum TIMConvType conv_type, TIMCommCallback cb, const void* user_data);

/**
* @brief ��ȡ���ػ���ĻỰ�б�
* 
* @param cb ��ȡ�Ự�����б�Ļص����ص���������Ͳ���������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
* 
*/
TIM_DECL int TIMConvGetConvList(TIMCommCallback cb, const void* user_data);

/**
* @brief ����ָ���Ự�Ĳݸ�
*
* @param conv_id   �Ự��ID
* @param conv_type �Ự���ͣ���ο�[TIMConvType](TIMCloudDef.h)
* @param json_draft_param �����õĲݸ�Json�ַ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
* 
* @example
* Json::Value json_value_text;  // ������Ϣ
* json_value_text[kTIMElemType] = kTIMElem_Text;
* json_value_text[kTIMTextElemContent] = "this draft";
* Json::Value json_value_msg;
* json_value_msg[kTIMMsgElemArray].append(json_value_text);
* 
* Json::Value json_value_draft; // ����ݸ�
* json_value_draft[kTIMDraftEditTime] = time(NULL);
* json_value_draft[kTIMDraftUserDefine] = "this is userdefine";
* json_value_draft[kTIMDraftMsg] = json_value_msg;
* 
* if (TIM_SUCC != TIMConvSetDraft(userid.c_str(), TIMConvType::kTIMConv_C2C, json_value_draft.toStyledString().c_str())) {
*     // TIMConvSetDraft �ӿڵ���ʧ��
* } 
*
* // json_value_draft.toStyledString().c_str() �õ� json_draft_param JSON �ַ�������
* {
*    "draft_edit_time" : 1551271429,
*    "draft_msg" : {
*       "message_elem_array" : [
*          {
*             "elem_type" : 0,
*             "text_elem_content" : "this draft"
*          }
*       ]
*    },
*    "draft_user_define" : "this is userdefine"
* }
*
* @note
* �Ự�ݸ�һ�����ڱ����û���ǰ�����δ���͵���Ϣ��
*/
TIM_DECL int TIMConvSetDraft(const char* conv_id, enum TIMConvType conv_type, const char* json_draft_param);

/**
* @brief ɾ��ָ���Ự�Ĳݸ�
*
* @param conv_id   �Ự��ID
* @param conv_type �Ự���ͣ���ο�[TIMConvType](TIMCloudDef.h)
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
*/
TIM_DECL int TIMConvCancelDraft(const char* conv_id, enum TIMConvType conv_type);
/// @}

/////////////////////////////////////////////////////////////////////////////////
//
//                       ��Ϣ��ؽӿ�
//
/////////////////////////////////////////////////////////////////////////////////
/// @name ��Ϣ��ؽӿ�
/// @brief ��Ϣ������ο� [������Ϣ](https://cloud.tencent.com/document/product/269/3662)��[Ⱥ����Ϣ](https://cloud.tencent.com/document/product/269/3663)��[��Ϣ��ʽ����](https://cloud.tencent.com/document/product/269/2720)
/// @{
/**
* @brief ��������Ϣ
*
* @param conv_id   �Ự��ID
* @param conv_type �Ự���ͣ���ο�[TIMConvType](TIMCloudDef.h)
* @param json_msg_param  ��Ϣjson�ַ���
* @param cb ��������Ϣ�ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example 
* Json::Value json_value_text;
* json_value_text[kTIMElemType] = kTIMElem_Text;
* json_value_text[kTIMTextElemContent] = "send text";
* Json::Value json_value_msg;
* json_value_msg[kTIMMsgElemArray].append(json_value_text);
* json_value_msg[kTIMMsgSender] = login_id;
* json_value_msg[kTIMMsgClientTime] = time(NULL);
* json_value_msg[kTIMMsgServerTime] = time(NULL);
*
* int ret = TIMMsgSendNewMsg(conv_id.c_str(), kTIMConv_C2C, json_value_msg.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*     if (ERR_SUCC != code) {
*         // ��Ϣ����ʧ��
*         return;
*     }
*     // ��Ϣ���ͳɹ�
* }, this);
*
* // json_value_msg.toStyledString().c_str() �õ� json_msg_param JSON �ַ�������
* {
*    "message_client_time" : 1551446728,
*    "message_elem_array" : [
*       {
*          "elem_type" : 0,
*          "text_elem_content" : "send text"
*       }
*    ],
*    "message_sender" : "user1",
*    "message_server_time" : 1551446728
* }
* @note
* >  ��������Ϣ��������Ϣ��Ⱥ��Ϣ�ķ��;����ô˽ӿڡ�
* >> ���͵�����Ϣʱ conv_id Ϊ�Է���identifier�� conv_type Ϊ kTIMConv_C2C 
* >> ����Ⱥ����Ϣʱ conv_id ΪȺID�� conv_type Ϊ kTIMConv_Group ��
* >  ������Ϣʱ���ܷ��� kTIMElem_GroupTips �� kTIMElem_GroupReport ��������Ϊ��̨�·������ڸ���(֪ͨ)Ⱥ����Ϣ�����Եķ�����Ϣ��Ԫ��
* >>   �ı���ϢԪ�أ���ο� [TextElem](TIMCloudDef.h)
* >>   ������ϢԪ�أ���ο� [FaceElem](TIMCloudDef.h)
* >>   λ����ϢԪ�أ���ο� [LocationElem](TIMCloudDef.h)
* >>   ͼƬ��ϢԪ�أ���ο� [ImageElem](TIMCloudDef.h)
* >>   ������ϢԪ�أ���ο� [SoundElem](TIMCloudDef.h)
* >>   �Զ�����ϢԪ�أ���ο� [CustomElem](TIMCloudDef.h)
* >>   �ļ���ϢԪ�أ���ο� [FileElem](TIMCloudDef.h)
* >>   ��Ƶ��ϢԪ�أ���ο� [VideoElem](TIMCloudDef.h)
*/
TIM_DECL int TIMMsgSendNewMsg(const char* conv_id, enum TIMConvType conv_type, const char* json_msg_param, TIMCommCallback cb, const void* user_data);

/**
* @brief ��Ϣ�ϱ��Ѷ�
*
* @param conv_id   �Ự��ID
* @param conv_type �Ự���ͣ���ο�[TIMConvType](TIMCloudDef.h)
* @param json_msg_param  ��Ϣjson�ַ���
* @param cb ��Ϣ�ϱ��Ѷ��ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @note
* json_msg_param ������ NULL ���ַ���ָ�����""���ַ�������ʱ�ԻỰ��ǰ������Ϣ��ʱ���������Ự����������Ϣ����ǰʱ��Ϊ�Ѷ�ʱ����ϱ�.��Ҫָ����Ϣʱ�����Ը�ָ����Ϣ��ʱ���Ϊ�Ѷ�ʱ����ϱ�������ý�������Ϣ��ȡ����Ϣ�����������ϢJson��������Ϣ��λ�����ҵ�����ϢJson�������ظ�������ϢJson��
*/
TIM_DECL int TIMMsgReportReaded(const char* conv_id, enum TIMConvType conv_type, const char* json_msg_param, TIMCommCallback cb, const void* user_data);

/**
* @brief ��Ϣ����
*
* @param conv_id   �Ự��ID
* @param conv_type �Ự���ͣ���ο�[TIMConvType](TIMCloudDef.h)
* @param json_msg_param  ��Ϣjson�ַ���
* @param cb ��Ϣ���سɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_value_text;
* json_value_text[kTIMElemType] = kTIMElem_Text;
* json_value_text[kTIMTextElemContent] = "send text";
* Json::Value json_value_msg;
* json_value_msg[kTIMMsgElemArray].append(json_value_text);
*
* int ret = TIMMsgSendNewMsg("test_win_03", kTIMConv_C2C, json_value_msg.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*     if (ERR_SUCC != code) {
*         // ��Ϣ����ʧ��
*         return;
*     }
*     // ��Ϣ���ͳɹ� json_param ���ط��ͺ����Ϣjson�ַ���
*     TIMMsgRevoke("test_win_03", kTIMConv_C2C, json_param, [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*         if (ERR_SUCC != code) {
*             // ��Ϣ����ʧ��
*             return;
*         }
*         // ��Ϣ���سɹ�
*
*     }, user_data);
* }, this);
*
* @note
* ��Ϣ���ء�ʹ�ñ������ϢJson��������Ϣ��λ�����ҵ�����ϢJson�������ظ�������ϢJson.
*/
TIM_DECL int TIMMsgRevoke(const char* conv_id, enum TIMConvType conv_type, const char* json_msg_param, TIMCommCallback cb, const void* user_data);

/**
* @brief ������Ϣ��λ��׼����ָ���Ự����Ϣ
*
* @param conv_id   �Ự��ID
* @param conv_type �Ự���ͣ���ο�[TIMConvType](TIMCloudDef.h)
* @param json_msg_Locator_array  ��Ϣ��λ������
* @param cb ������Ϣ��λ��׼����ָ���Ự����Ϣ�ɹ����Ļص����ص���������Ͳ���������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
* @example
* Json::Value json_msg_locator;                      //һ����Ϣ��Ӧһ����Ϣ��λ��(��׼��λ)
* json_msg_locator[kTIMMsgLocatorIsRevoked] = false; //��Ϣ�Ƿ񱻳���
* json_msg_locator[kTIMMsgLocatorTime] = 123;        //������Ϣ��ʱ��
* json_msg_locator[kTIMMsgLocatorSeq] = 1;           
* json_msg_locator[kTIMMsgLocatorIsSelf] = false;    
* json_msg_locator[kTIMMsgLocatorRand] = 12345678;   
* 
* Json::Value json_msg_locators;
* json_msg_locators.append(json_msg_locator);
* TIMMsgFindByMsgLocatorList("user2", kTIMConv_C2C, json_msg_locators.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*     
* }, nullptr);
* 
* // json_msg_locators.toStyledString().c_str() �ĵ� json_msg_Locator_array JSON �ַ�������
* [
*    {
*       "message_locator_is_revoked" : false,
*       "message_locator_is_self" : false,
*       "message_locator_rand" : 12345678,
*       "message_locator_seq" : 1,
*       "message_locator_time" : 123
*    }
* ]
* 
* @note
* > �˽ӿڸ�����Ϣ��λ����׼����ָ���Ự����Ϣ���ù���һ��������Ϣ����ʱ����ָ����Ϣ��
* > һ����Ϣ��λ����Ӧһ����Ϣ
*/
TIM_DECL int TIMMsgFindByMsgLocatorList(const char* conv_id, enum TIMConvType conv_type, const char* json_msg_Locator_array, TIMCommCallback cb, const void* user_data);

/**
* @brief ������Ϣ�б�ָ���Ự
*
* @param conv_id   �Ự��ID
* @param conv_type �Ự���ͣ���ο�[TIMConvType](TIMCloudDef.h)
* @param json_msg_array  ��Ϣ����
* @param cb ������Ϣ�б�ָ���Ự�ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_value_elem; //������Ϣ�ı�Ԫ��
* json_value_elem[kTIMElemType] = TIMElemType::kTIMElem_Text;
* json_value_elem[kTIMTextElemContent] = "this is import msg";
* 
* Json::Value json_value_msg; //������Ϣ
* json_value_msg[kTIMMsgSender] = login_id;
* json_value_msg[kTIMMsgClientTime] = time(NULL);
* json_value_msg[kTIMMsgServerTime] = time(NULL);
* json_value_msg[kTIMMsgElemArray].append(json_value_elem);
*
* Json::Value json_value_msgs;  //��Ϣ����
* json_value_msgs.append(json_value_msg);
*
* TIMMsgImportMsgList("user2", kTIMConv_C2C, json_value_msgs.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*     
* }, nullptr);
*
* // json_value_msgs.toStyledString().c_str() �õ�json_msg_array JSON �ַ�������
* [
*    {
*       "message_client_time" : 1551446728,
*       "message_elem_array" : [
*          {
*             "elem_type" : 0,
*             "text_elem_content" : "this is import msg"
*          }
*       ],
*       "message_sender" : "user1",
*       "message_server_time" : 1551446728
*    }
* ]
* 
* @note
* ����������Ϣ�������Լ�������Ϣȥ���롣Ҳ���Խ�֮ǰҪ�������Ϣ����Json���棬Ȼ�����ʱ��ֱ�ӵ��ýӿڣ����⹹����Ϣ����
*/
TIM_DECL int TIMMsgImportMsgList(const char* conv_id, enum TIMConvType conv_type, const char* json_msg_array, TIMCommCallback cb, const void* user_data);

/**
* @brief �����Զ�����Ϣ
*
* @param conv_id   �Ự��ID
* @param conv_type �Ự���ͣ���ο�[TIMConvType](TIMCloudDef.h)
* @param json_msg_param  ��Ϣjson�ַ���
* @param cb �����Զ�����Ϣ�ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
* 
* @note
* ��Ϣ����ӿڣ�һ�����Լ�����һ����ϢJson�ַ�����Ȼ�󱣴浽ָ���Ự
*/
TIM_DECL int TIMMsgSaveMsg(const char* conv_id, enum TIMConvType conv_type, const char* json_msg_param, TIMCommCallback cb, const void* user_data);

/**
* @brief ��ȡָ���Ự����Ϣ�б�
*
* @param conv_id   �Ự��ID
* @param conv_type �Ự���ͣ���ο�[TIMConvType](TIMCloudDef.h)
* @param json_get_msg_param ��Ϣ��ȡ����
* @param cb ��ȡָ���Ự����Ϣ�б�ɹ����Ļص����ص���������Ͳ���������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example ��ȡC2C�Ự Windows-02 ��Ϣ�б�
* Json::Value json_msg(Json::objectValue); // ����Message
* Json::Value json_get_msg_param;
* json_get_msg_param[kTIMMsgGetMsgListParamLastMsg] = json_msg;
* json_get_msg_param[kTIMMsgGetMsgListParamIsRamble] = false;
* json_get_msg_param[kTIMMsgGetMsgListParamIsForward] = true;
* json_get_msg_param[kTIMMsgGetMsgListParamCount] = 100;
*
* int ret = TIMMsgGetMsgList("Windows-02", kTIMConv_C2C, json_get_msg_param.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
* }, this);
* 
* // json_get_msg_param.toStyledString().c_str() �õ� json_get_msg_param JSON �ַ�������
* {
*    "msg_getmsglist_param_count" : 100,
*    "msg_getmsglist_param_is_forward" : true,
*    "msg_getmsglist_param_is_remble" : false,
*    "msg_getmsglist_param_last_msg" : {}
* }
*   
* @note
* �� kTIMMsgGetMsgListParamLastMsg ָ������Ϣ��ʼ��ȡ������Ϣ�б�kTIMMsgGetMsgListParamCount ΪҪ��ȡ����Ϣ��Ŀ��kTIMMsgGetMsgListParamLastMsg ���Բ�ָ������ָ��ʱ��ʾ�ԻỰ���µ���ϢΪ LastMsg��
* ��ָ�� kTIMMsgGetMsgListParamIsRamble Ϊtrue�򱾵���Ϣ��ȡ����ָ����Ŀʱ����ȥ��ȡ�ƶ�������Ϣ��
* kTIMMsgGetMsgListParamIsForward Ϊtrueʱ��ʾ��ȡ�� kTIMMsgGetMsgListParamLastMsg �µ���Ϣ��Ϊfalseʱ��ʾ��ȡ�� kTIMMsgGetMsgListParamLastMsg �ϵ���Ϣ
*/
TIM_DECL int TIMMsgGetMsgList(const char* conv_id, enum TIMConvType conv_type, const char* json_get_msg_param, TIMCommCallback cb, const void* user_data);

/**
* @brief ɾ��ָ���Ự����Ϣ
*
* @param conv_id   �Ự��ID
* @param conv_type �Ự���ͣ���ο�[TIMConvType](TIMCloudDef.h)
* @param json_msgdel_param ��Ϣ��ȡ����
* @param cb ɾ��ָ���Ự����Ϣ�ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
* 
* @example 
* Json::Value json_value_msg(Json::objectValue);
* Json::Value json_value_msgdelete;
* json_value_msgdelete[kTIMMsgDeleteParamIsRamble] = false;
* json_value_msgdelete[kTIMMsgDeleteParamMsg] = json_value_msg;
* TIMMsgDelete("user2", kTIMConv_C2C, json_value_msgdelete.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
* 
* }, nullptr);
* 
* // json_value_msgdelete.toStyledString().c_str() �õ� json_msgdel_param JSON �ַ�������
* {
*   "msg_delete_param_is_remble" : false,
*   "msg_delete_param_msg" : {}
* }
*
* @note 
* > ������ kTIMMsgDeleteParamMsg ʱ���ڻỰ��ɾ��ָ��������Ϣ
* > ��δ���� kTIMMsgDeleteParamMsg ʱ�� kTIMMsgDeleteParamIsRamble Ϊfalse��ʾɾ���Ự���б�����Ϣ��true ��ʾɾ���Ự����������Ϣ(ɾ��������Ϣ��ʱ��֧��)
* > һ��ֱ��ʹ�ñ������ϢJson������ͨ����Ϣ��λ�����ҵõ���Json������ɾ����ʱ������ϢJson
*/
TIM_DECL int TIMMsgDelete(const char* conv_id, enum TIMConvType conv_type, const char* json_msgdel_param, TIMCommCallback cb, const void* user_data);

/**
* @brief ������Ϣ��Ԫ�ص�ָ���ļ�·��(ͼƬ����Ƶ����Ƶ���ļ�)
*
* @param json_download_elem_param  ���صĲ���Json�ַ���
* @param path �����ļ�����·��
* @param cb ���سɹ����Ļص��Լ����ؽ��Ȼص����ص���������Ͳ���������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value download_param;
* download_param[kTIMMsgDownloadElemParamFlag] = flag;
* download_param[kTIMMsgDownloadElemParamType] = type;
* download_param[kTIMMsgDownloadElemParamId] = id;
* download_param[kTIMMsgDownloadElemParamBusinessId] = business_id;
* download_param[kTIMMsgDownloadElemParamUrl] = url;
*
* TIMMsgDownloadElemToPath(download_param.toStyledString().c_str(), (path_ + "\\" + name).c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*
* }, this);
* 
* @note
* �˽ӿ�����������Ϣ��ͼƬ���ļ�����������Ƶ��Ԫ�ء����صĲ��� kTIMMsgDownloadElemParamFlag��kTIMMsgDownloadElemParamId��kTIMMsgDownloadElemParamBusinessId��kTIMMsgDownloadElemParamUrl ������
* ����ӦԪ�����ҵ������� kTIMMsgDownloadElemParamType Ϊ�����ļ����� [TIMDownloadType](TIMCloudDef.h)
*/
TIM_DECL int TIMMsgDownloadElemToPath(const char* json_download_elem_param, const char* path, TIMCommCallback cb, const void* user_data);

/**
* @brief Ⱥ����Ϣ
*
* @param json_batch_send_param  Ⱥ����Ϣjson�ַ���
* @param cb Ⱥ����Ϣ�ɹ����Ļص����ص���������Ͳ���������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example 
* //������Ϣ�ı�Ԫ��
* Json::Value json_value_elem;
* json_value_elem[kTIMElemType] = TIMElemType::kTIMElem_Text;
* json_value_elem[kTIMTextElemContent] = "this is batch send msg";
* //������Ϣ
* Json::Value json_value_msg;
* json_value_msg[kTIMMsgSender] = login_id;
* json_value_msg[kTIMMsgClientTime] = time(NULL);
* json_value_msg[kTIMMsgServerTime] = time(NULL);
* json_value_msg[kTIMMsgElemArray].append(json_value_elem);
*
* // ������������ID�����б�
* Json::Value json_value_ids(Json::arrayValue);
* json_value_ids.append("user2");
* json_value_ids.append("user3");
* // �����������ͽӿڲ���
* Json::Value json_value_batchsend;
* json_value_batchsend[kTIMMsgBatchSendParamIdentifierArray] = json_value_ids;
* json_value_batchsend[kTIMMsgBatchSendParamMsg] = json_value_msg;
* int ret = TIMMsgBatchSend(json_value_batchsend.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
* }, nullptr);
* 
* // json_value_batchsend.toStyledString().c_str() �õ� json_batch_send_param JSON �ַ�������
* {
*    "msg_batch_send_param_identifier_array" : [ "user2", "user3" ],
*    "msg_batch_send_param_msg" : {
*       "message_client_time" : 1551340614,
*       "message_elem_array" : [
*          {
*             "elem_type" : 0,
*             "text_elem_content" : "this is batch send msg"
*          }
*       ],
*       "message_sender" : "user1",
*       "message_server_time" : 1551340614
*    }
* }
*
* @note
* ����������Ϣ�Ľӿڣ�ÿ��identifier���ͳɹ����ͨ���ص�cb���ء�
*/
TIM_DECL int TIMMsgBatchSend(const char* json_batch_send_param, TIMCommCallback cb, const void* user_data);
/// @}


/////////////////////////////////////////////////////////////////////////////////
//
//                       Ⱥ����ؽӿ�
//
/////////////////////////////////////////////////////////////////////////////////
/// @name Ⱥ����ؽӿ�
/// @brief Ⱥ����ؽ�����ο� [Ⱥ��ϵͳ](https://cloud.tencent.com/document/product/269/1502)��[Ⱥ�����](https://cloud.tencent.com/document/product/269/3661)�� [Ⱥ���Զ����ֶ�](https://cloud.tencent.com/document/product/269/1502#.E8.87.AA.E5.AE.9A.E4.B9.89.E5.AD.97.E6.AE.B5)
/// @{
/**
* @brief ����Ⱥ��
*
* @param json_group_create_param ����Ⱥ��Ĳ���Json�ַ���
* @param cb ����Ⱥ��ɹ����Ļص����ص���������Ͳ���������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
*
* Json::Value json_group_member_array(Json::arrayValue);
*
* Json::Value json_value_param;
* json_value_param[kTIMCreateGroupParamGroupId] = "first group id";
* json_value_param[kTIMCreateGroupParamGroupType] = kTIMGroup_Public;
* json_value_param[kTIMCreateGroupParamGroupName] = "first group name";
* json_value_param[kTIMCreateGroupParamGroupMemberArray] = json_group_member_array;
* 
* json_value_param[kTIMCreateGroupParamNotification] = "group notification";
* json_value_param[kTIMCreateGroupParamIntroduction] = "group introduction";
* json_value_param[kTIMCreateGroupParamFaceUrl] = "group face url";
* json_value_param[kTIMCreateGroupParamMaxMemberCount] = 2000;
* json_value_param[kTIMCreateGroupParamAddOption] = kTIMGroupAddOpt_Any;
*
* const void* user_data = nullptr; // �ص������ش�
* int ret = TIMGroupCreate(json_value_param.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
*    if (ERR_SUCC != code) { 
*         // ����Ⱥ��ʧ��
*         return;
*     }
*     
*     // ����Ⱥ��ɹ� ����Json��ȡ�������GroupID
* }, user_data);
* if (TIM_SUCC != ret) {
*     // TIMGroupCreate �ӿڵ���ʧ��
* }
*
* // json_value_param.toStyledString().c_str() �õ� json_group_create_param JSON �ַ�������
* {
*    "create_group_param_add_option" : 2,
*    "create_group_param_face_url" : "group face url",
*    "create_group_param_group_id" : "first group id",
*    "create_group_param_group_member_array" : [],
*    "create_group_param_group_name" : "first group name",
*    "create_group_param_group_type" : 0,
*    "create_group_param_introduction" : "group introduction",
*    "create_group_param_max_member_num" : 2000,
*    "create_group_param_notification" : "group notification"
* }
*
* @note
* > ����Ⱥ��ʱ����ָ��ȺID����δָ��ʱIMͨѶ�Ʒ�����������һ��Ψһ��ID���Ա����������Ⱥ��IDͨ������Ⱥ��ʱ����Ļص�����
* > ����Ⱥ������Json Key������ο�[CreateGroupParam](TIMCloudDef.h)
*/
TIM_DECL int TIMGroupCreate(const char* json_group_create_param, TIMCommCallback cb, const void* user_data);

/**
* @brief ɾ��(��ɢ)Ⱥ��
*
* @param group_id Ҫɾ����Ⱥ��ID
* @param cb ɾ��Ⱥ��ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @note
* > Ȩ��˵����
* >>   ����˽��Ⱥ���κ��˶��޷���ɢȺ�顣
* >>   ���ڹ���Ⱥ�������Һ�ֱ����Ⱥ��Ⱥ�����Խ�ɢȺ�顣
* > ɾ��ָ��Ⱥ��group_id�Ľӿڣ�ɾ���ɹ����ɸ��ݻص�cb�Ĳ����жϡ�
*/
TIM_DECL int TIMGroupDelete(const char* group_id, TIMCommCallback cb, const void* user_data);

/**
* @brief �������Ⱥ��
*
* @param group_id Ҫ�����Ⱥ��ID
* @param hello_msg �������ɣ�ѡ�
* @param cb �������Ⱥ��ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @note
* > Ȩ��˵����
* >> ˽��Ⱥ�������û�����������Ⱥ��
* >> ����Ⱥ�������ҿ�������������롣
* +  ���Ⱥ������Ϊ��Ҫ��ˣ���������Ա��Ⱥ�����ܵ�������Ⱥϵͳ��Ϣ����Ҫ�ȴ�����Ա����Ⱥ����ˣ����Ⱥ������Ϊ�κ��˿ɼ��룬��ֱ����Ⱥ�ɹ���
*    ֱ����Ⱥ�����������Ⱥ�顣
* > �������ָ��Ⱥ��group_id�Ľӿڣ��������Ĳ����ɹ����ɸ��ݻص�cb�Ĳ����жϡ�
*/
TIM_DECL int TIMGroupJoin(const char* group_id, const char* hello_msg, TIMCommCallback cb, const void* user_data);

/**
* @brief �˳�Ⱥ��
*
* @param group_id Ҫ�˳���Ⱥ��ID
* @param cb �˳�Ⱥ��ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @note
* > Ȩ��˵����
* >>   ����˽��Ⱥ��ȫԱ���˳�Ⱥ�顣
* >>   ���ڹ���Ⱥ�������Һ�ֱ����Ⱥ��Ⱥ�������˳���
* > �˳�ָ��Ⱥ��group_id�Ľӿڣ��˳��ɹ����ɸ��ݻص�cb�Ĳ����жϡ�
*/
TIM_DECL int TIMGroupQuit(const char* group_id, TIMCommCallback cb, const void* user_data);

/**
* @brief �������Ⱥ��
*
* @param json_group_invite_param �������Ⱥ���Json�ַ���
* @param cb �������Ⱥ��ɹ����Ļص����ص���������Ͳ���������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_value_invite;
* json_value_invite[kTIMGroupInviteMemberParamGroupId] = groupid;
* json_value_invite[kTIMGroupInviteMemberParamUserData] = "userdata";
* json_value_invite[kTIMGroupInviteMemberParamIdentifierArray].append("user1");
* json_value_invite[kTIMGroupInviteMemberParamIdentifierArray].append("user2");
*
* const void* user_data = nullptr; // �ص������ش�;
* int ret = TIMGroupInviteMember(json_value_invite.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
*     if (ERR_SUCC != code) { 
*         // �����Ա�б�ʧ��
*         return;
*     }
*     // �����Ա�б�ɹ�������JSON��ȡÿ����Ա������
* }, user_data);
* if (TIM_SUCC != ret) {
*     // TIMGroupInviteMember �ӿڵ���ʧ��
* }
* 
* // json_value_invite.toStyledString().c_str() �õ� json_group_invite_param JSON �ַ�������
* {
*    "group_invite_member_param_group_id" : "first group id",
*    "group_invite_member_param_identifier_array" : [ "user1", "user2" ],
*    "group_invite_member_param_user_data" : "userdata"
* }
* @note
* > Ȩ��˵��:
* >>   ֻ��˽��Ⱥ�������û���Ⱥ
* >>   ����Ⱥ�������������û���Ⱥ
* >>   ��Ҫ�û�ͬ�⣻ֱ����Ⱥ���������û���Ⱥ��
* > �˽ӿ�֧�����������Ա����Ⱥ��,Json Key������ο�[GroupInviteMemberParam](TIMCloudDef.h)
*/
TIM_DECL int TIMGroupInviteMember(const char* json_group_invite_param, TIMCommCallback cb, const void* user_data);

/**
* @brief ɾ��Ⱥ���Ա
*
* @param json_group_delete_param ɾ��Ⱥ���Ա��Json�ַ���
* @param cb ɾ��Ⱥ���Ա�ɹ����Ļص����ص���������Ͳ���������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_value_delete;
* json_value_delete[kTIMGroupDeleteMemberParamGroupId] = groupid;
* json_value_delete[kTIMGroupDeleteMemberParamUserData] = "reason";
* json_value_delete[kTIMGroupDeleteMemberParamIdentifierArray].append("user1");
* json_value_delete[kTIMGroupDeleteMemberParamIdentifierArray].append("user2");
*
* int ret = TIMGroupDeleteMember(json_value_delete.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
*       
* }, this));
* 
* // json_value_delete.toStyledString().c_str() �õ� json_group_delete_param JSON �ַ�������
* {
*   "group_delete_member_param_group_id" : "third group id",
*   "group_delete_member_param_identifier_array" : [ "user2", "user3" ],
*   "group_delete_member_param_user_data" : "reason"
* }
* 
* @note
* > Ȩ��˵����
* >>   ����˽��Ⱥ��ֻ�д����߿�ɾ��Ⱥ���Ա��
* >>   ���ڹ���Ⱥ�������ң�ֻ�й���Ա��Ⱥ���������ˡ�
* >>   ����ֱ����Ⱥ���������ˡ�
* > �˽ӿ�֧������ɾ��Ⱥ��Ա,Json Key������ο�[GroupDeleteMemberParam](TIMCloudDef.h)
*/
TIM_DECL int TIMGroupDeleteMember(const char* json_group_delete_param, TIMCommCallback cb, const void* user_data);

/**
* @brief ��ȡ�Ѽ���Ⱥ���б�
*
* @param cb ��ȡ�Ѽ���Ⱥ���б�ɹ����Ļص����ص���������Ͳ���������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @note
* > Ȩ��˵����
* >>   �˽ӿڿ��Ի�ȡ�Լ��������Ⱥ�б�
* >>   �˽ӿ�ֻ�ܻ�ü���Ĳ���ֱ������б�
* > �˽ӿ����ڻ�ȡ��ǰ�û��Ѽ����Ⱥ���б�����Ⱥ��Ļ�����Ϣ�����巵�ص�Ⱥ�������Ϣ�ֶβο�[GroupBaseInfo](TIMCloudDef.h)
*/
TIM_DECL int TIMGroupGetJoinedGroupList(TIMCommCallback cb, const void* user_data);

/**
* @brief ��ȡȺ����Ϣ�б�
*
* @param json_group_getinfo_param ��ȡȺ����Ϣ�б������Json�ַ���
* @param cb ��ȡȺ����Ϣ�б�ɹ����Ļص����ص���������Ͳ���������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value groupids;
* groupids.append("third group id");
* groupids.append("second group id");
* groupids.append("first group id");
* int ret = TIMGroupGetGroupInfoList(groupids.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*
* }, this);
*
* // groupids.toStyledString().c_str() �õ�json_group_getinfo_param����
* [ "third group id", "second group id", "first group id" ]
*
* @note
* �˽ӿ����ڻ�ȡָ��ȺID�б��Ⱥ��ϸ��Ϣ�����巵�ص�Ⱥ����ϸ��Ϣ�ֶβο�[GroupDetailInfo](TIMCloudDef.h)
*/
TIM_DECL int TIMGroupGetGroupInfoList(const char* json_group_getinfo_param, TIMCommCallback cb, const void* user_data);

/**
* @brief �޸�Ⱥ��Ϣ
*
* @param json_group_modifyinfo_param ����Ⱥ��Ϣ������Json�ַ���Json�ַ���
* @param cb ����Ⱥ��Ϣ�ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example ����Ⱥ������
* Json::Value json_value_modifygroupinfo;
* json_value_modifygroupinfo[kTIMGroupModifyInfoParamGroupId] = "first group id";
* json_value_modifygroupinfo[kTIMGroupModifyInfoParamModifyFlag] = kTIMGroupModifyInfoFlag_Owner;
* json_value_modifygroupinfo[kTIMGroupModifyInfoParamOwner] = "user2";
* 
* int ret = TIMGroupModifyGroupInfo(json_value_modifygroupinfo.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*
* }, nullptr);
*
* // json_value_modifygroupinfo.toStyledString().c_str() �õ�json_group_modifyinfo_param JSON �ַ�������
* {
*   "group_modify_info_param_group_id" : "first group id",
*   "group_modify_info_param_modify_flag" : -2147483648,
*   "group_modify_info_param_owner" : "user2"
* }
*
* @example ����Ⱥ���ƺ�Ⱥ֪ͨ
* Json::Value json_value_modifygroupinfo;
* json_value_modifygroupinfo[kTIMGroupModifyInfoParamGroupId] = "first group id";
* json_value_modifygroupinfo[kTIMGroupModifyInfoParamModifyFlag] = kTIMGroupModifyInfoFlag_Name | kTIMGroupModifyInfoFlag_Notification;
* json_value_modifygroupinfo[kTIMGroupModifyInfoParamGroupName] = "first group name to other name";
* json_value_modifygroupinfo[kTIMGroupModifyInfoParamNotification] = "first group notification";
* 
* int ret = TIMGroupModifyGroupInfo(json_value_modifygroupinfo.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*
* }, nullptr);
* 
* // json_value_modifygroupinfo.toStyledString().c_str() �õ�json_group_modifyinfo_param JSON �ַ�������
* {
*    "group_modify_info_param_group_id" : "first group id",
*    "group_modify_info_param_group_name" : "first group name to other name",
*    "group_modify_info_param_modify_flag" : 3,
*    "group_modify_info_param_notification" : "first group notification"
* }
*
* @note
* > �޸�Ⱥ����Ⱥת�ã���Ȩ��˵����
* >>   ֻ��Ⱥ������Ȩ�޽���Ⱥת�ò�����
* >>   ֱ����Ⱥ���ܽ���Ⱥת�ò�����
* > �޸�Ⱥ������Ϣ��Ȩ��˵��:
* >>   ���ڹ���Ⱥ�������Һ�ֱ����Ⱥ��ֻ��Ⱥ�����߹���Ա�����޸�Ⱥ��顣
* >>   ����˽��Ⱥ���κ��˿��޸�Ⱥ��顣
* > kTIMGroupModifyInfoParamModifyFlag ���԰�λ�����ö��ֵ����ͬ��flag���ò�ͬ�ļ�,������ο�[GroupModifyInfoParam](TIMCloudDef.h)
*/
TIM_DECL int TIMGroupModifyGroupInfo(const char* json_group_modifyinfo_param, TIMCommCallback cb, const void* user_data);

/**
* @brief ��ȡȺ��Ա��Ϣ�б�
*
* @param json_group_getmeminfos_param ��ȡȺ��Ա��Ϣ�б������Json�ַ���
* @param cb ��ȡȺ��Ա��Ϣ�б�ɹ����Ļص����ص���������Ͳ���������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value identifiers(Json::arrayValue); 
* ...
* Json::Value customs(Json::arrayValue);
* ...
* Json::Value option;
* option[kTIMGroupMemberGetInfoOptionInfoFlag] = kTIMGroupMemberInfoFlag_None;
* option[kTIMGroupMemberGetInfoOptionRoleFlag] = kTIMGroupMemberRoleFlag_All;
* option[kTIMGroupMemberGetInfoOptionCustomArray] = customs;
* Json::Value getmeminfo_opt;
* getmeminfo_opt[kTIMGroupGetMemberInfoListParamGroupId] = groupid;
* getmeminfo_opt[kTIMGroupGetMemberInfoListParamIdentifierArray] = identifiers;
* getmeminfo_opt[kTIMGroupGetMemberInfoListParamOption] = option;
* getmeminfo_opt[kTIMGroupGetMemberInfoListParamNextSeq] = 0;
* 
* int ret = TIMGroupGetMemberInfoList(getmeminfo_opt.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
* 
* }, this);
*
* // getmeminfo_opt.toStyledString().c_str() �õ�json_group_getmeminfos_param JSON �ַ�������
* {
*    "group_get_members_info_list_param_group_id" : "first group id",
*    "group_get_members_info_list_param_identifier_array" : [],
*    "group_get_members_info_list_param_next_seq" : 0,
*    "group_get_members_info_list_param_option" : {
*       "group_member_get_info_option_custom_array" : [],
*       "group_member_get_info_option_info_flag" : 0,
*       "group_member_get_info_option_role_flag" : 0
*    }
* }
*
* @note
* > Ȩ��˵����
* >>   �κ�Ⱥ�����Ͷ����Ի�ȡ��Ա�б�
* >>   ֱ����Ⱥֻ����ȡ���ֳ�Ա�б�����Ⱥ��������Ա�Ͳ��ֳ�Ա��
* > ���ݲ�ͬ��ѡ���ȡȺ��Ա��Ϣ�б���Ա��Ϣ�ĸ����ֶκ�����ο�[GroupMemberInfo](TIMCloudDef.h)
*/
TIM_DECL int TIMGroupGetMemberInfoList(const char* json_group_getmeminfos_param, TIMCommCallback cb, const void* user_data);

/**
* @brief �޸�Ⱥ��Ա��Ϣ
*
* @param json_group_modifymeminfo_param ����Ⱥ��Ϣ������Json�ַ���
* @param cb ����Ⱥ��Ա��Ϣ�ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_value_setgroupmeminfo;
* json_value_setgroupmeminfo[kTIMGroupModifyMemberInfoParamGroupId] = "third group id";
* json_value_setgroupmeminfo[kTIMGroupModifyMemberInfoParamIdentifier] = "user2";
* json_value_setgroupmeminfo[kTIMGroupModifyMemberInfoParamModifyFlag] = kTIMGroupMemberModifyFlag_MemberRole | kTIMGroupMemberModifyFlag_NameCard;
* json_value_setgroupmeminfo[kTIMGroupModifyMemberInfoParamMemberRole] = kTIMMemberRole_Admin;
* json_value_setgroupmeminfo[kTIMGroupModifyMemberInfoParamNameCard] = "change name card";
*
* int ret = TIMGroupModifyMemberInfo(json_value_setgroupmeminfo.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*   
* }, nullptr);
* 
* // json_value_modifygroupmeminfo.toStyledString().c_str() �õ�json_group_modifymeminfo_param JSON �ַ�������
* {
*    "group_modify_member_info_group_id" : "third group id",
*    "group_modify_member_info_identifier" : "user2",
*    "group_modify_member_info_member_role" : 1,
*    "group_modify_member_info_modify_flag" : 10,
*    "group_modify_member_info_name_card" : "change name card"
* }
* 
* @note
* > Ȩ��˵����
* >> ֻ��Ⱥ�����߹���Ա���Խ��ж�Ⱥ��Ա����ݽ����޸ġ�
* >> ֱ����Ⱥ��֧���޸��û�Ⱥ����ݡ�
* >> ֻ��Ⱥ�����߹���Ա���Խ��ж�Ⱥ��Ա���н��ԡ� 
* > kTIMGroupModifyMemberInfoParamModifyFlag ���԰�λ�����ö��ֵ����ͬ��flag���ò�ͬ�ļ�����ο�[GroupModifyMemberInfoParam](TIMCloudDef.h)
*/
TIM_DECL int TIMGroupModifyMemberInfo(const char* json_group_modifymeminfo_param, TIMCommCallback cb, const void* user_data);

/**
* @brief ��ȡȺδ����Ϣ�б�
*        Ⱥδ����Ϣ��ָ��û�д���Ĳ��������磬�����Ⱥ���������Ⱥ������û�б�������֮ΪȺδ����Ϣ
*
* @param json_group_getpendence_list_param ����Ⱥδ����Ϣ������Json�ַ���
* @param cb ��ȡȺδ����Ϣ�б�ɹ����Ļص����ص���������Ͳ���������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value get_pendency_option;
* get_pendency_option[kTIMGroupPendencyOptionStartTime] = 0;
* get_pendency_option[kTIMGroupPendencyOptionMaxLimited] = 0;
* int ret = TIMGroupGetPendencyList(get_pendency_option.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*     if (ERR_SUCC != code) { 
*         // ��ȡȺδ����Ϣʧ��
*         return;
*     }
* }, nullptr);
* 
* // get_pendency_option.toStyledString().c_str() �õ�json_group_getpendence_list_param JSON �ַ�������
* {
*    "group_pendency_option_max_limited" : 0,
*    "group_pendency_option_start_time" : 0
* }
*
* @note 
* > �˴���Ⱥδ����Ϣ��ָ������Ҫ������Ⱥ��صĲ��������磺��Ⱥ��������������Ⱥ�������ȵȡ��������ͨ�����߾ܾ��󣬸�����ϢҲ��ͨ���˽ӿ����أ����ص���Ϣ�����Ѿ���־��
* > UserA�������ȺGroupA����Ⱥ����Ա�ɻ�ȡ��δ�������Ϣ��UserA��Ϊû������Ȩ�ޣ�����Ҫ��ȡ��δ����Ϣ��
* > ���AdminA��UserA��ȥGroupA����UserA������ȡ��δ�������Ϣ����Ϊ��δ����Ϣ��UserA����
* > Ȩ��˵����
* >> ֻ����������Ȩ����ȡ���δ����Ϣ��
* > kTIMGroupPendencyOptionStartTime ������ȡʱ���,��һ��������0,��߸���server���ص� [GroupPendencyResult](TIMCloudDef.h) �� kTIMGroupPendencyResultNextStartTime ָ����ʱ���������д��
* > kTIMGroupPendencyOptionMaxLimited ��ȡ�Ľ�������,server�ɸ�����Ҫ���ػ�����,������Ϊ������ı�־
*/
TIM_DECL int TIMGroupGetPendencyList(const char* json_group_getpendence_list_param, TIMCommCallback cb, const void* user_data);

/**
* @brief �ϱ�Ⱥδ����Ϣ�Ѷ�
*
* @param time_stamp �Ѷ�ʱ���(��λ��)����[GroupPendency](TIMCloudDef.h)�� kTIMGroupPendencyAddTime ָ����ʱ��Ƚ�
* @param cb �ϱ�Ⱥδ����Ϣ�Ѷ��ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @note
* ʱ���time_stamp��ǰ��Ⱥδ�����󶼽���Ϊ�Ѷ����ϱ��Ѷ�����Ȼ������ȡ����Щδ����Ϣ������ͨ�����Ѷ�ʱ�����ж��ж�δ����Ϣ�Ƿ��Ѷ���
*/
TIM_DECL int TIMGroupReportPendencyReaded(uint64_t time_stamp, TIMCommCallback cb, const void* user_data);

/**
* @brief ����Ⱥδ����Ϣ
*
* @param json_group_handle_pendency_param ����Ⱥδ����Ϣ������Json�ַ���
* @param cb ����Ⱥδ����Ϣ�ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example 
* Json::Value pendency; //���� GroupPendency
* ...
* Json::Value handle_pendency;
* handle_pendency[kTIMGroupHandlePendencyParamIsAccept] = true;
* handle_pendency[kTIMGroupHandlePendencyParamHandleMsg] = "I accept this pendency";
* handle_pendency[kTIMGroupHandlePendencyParamPendency] = pendency;
* int ret = TIMGroupHandlePendency(handle_pendency.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_param, const void* user_data) {
*     if (ERR_SUCC != code) {
*         // �ϱ�Ⱥδ����Ϣ�Ѷ�ʧ��
*         return;
*     }
* }, nullptr);
*
* // handle_pendency.toStyledString().c_str() �õ�json_group_handle_pendency_param JSON �ַ�������
* {
*    "group_handle_pendency_param_handle_msg" : "I accept this pendency",
*    "group_handle_pendency_param_is_accept" : true,
*    "group_handle_pendency_param_pendency" : {
*       "group_pendency_add_time" : 1551414487947,
*       "group_pendency_apply_invite_msg" : "Want Join Group, Thank you",
*       "group_pendency_approval_msg" : "",
*       "group_pendency_form_identifier" : "user2",
*       "group_pendency_form_user_defined_data" : "",
*       "group_pendency_group_id" : "four group id",
*       "group_pendency_handle_result" : 0,
*       "group_pendency_handled" : 0,
*       "group_pendency_pendency_type" : 0,
*       "group_pendency_to_identifier" : "user1",
*       "group_pendency_to_user_defined_data" : ""
*    }
* }
* 
* @note 
* > ����Ⱥ��δ����Ϣ��ImSDK�����˴���ӿڡ������˿���ѡ��Ե�����Ϣ����ͬ����߾ܾ����Ѵ���ɹ�����δ����Ϣ�����ٴδ���
* > ����δ����Ϣʱ��Ҫ��һ��δ����Ϣ[GroupPendency](TIMCloudDef.h)�������ڽӿ�[TIMGroupGetPendencyList]()���ص�δ����Ϣ�б�δ����Ϣ����������
*   �ڴ���δ����Ϣ��ʱ��[GroupPendency](TIMCloudDef.h)����� kTIMGroupHandlePendencyParamPendency ��
*/
TIM_DECL int TIMGroupHandlePendency(const char* json_group_handle_pendency_param, TIMCommCallback cb, const void* user_data);
/// @}

/////////////////////////////////////////////////////////////////////////////////
//
//                      �û�������ؽӿ�
//
/////////////////////////////////////////////////////////////////////////////////
/// @name �û�������ؽӿ�
/// @brief �û����Ͻ�����ο� [����ϵͳ���](https://cloud.tencent.com/document/product/269/1500#.E8.B5.84.E6.96.99.E7.B3.BB.E7.BB.9F.E7.AE.80.E4.BB.8B)
/// @{
/**
* @brief ��ȡָ���û��б�ĸ�������
*
* @param json_get_user_profile_list_param ��ȡָ���û��б���û����Ͻӿڲ�����Json�ַ���
* @param cb ��ȡָ���û��б���û����ϳɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_get_user_profile_list_param;
* json_get_user_profile_list_param[kTIMFriendShipGetProfileListParamForceUpdate] = false;
* json_get_user_profile_list_param[kTIMFriendShipGetProfileListParamIdentifierArray].append("user1");
* json_get_user_profile_list_param[kTIMFriendShipGetProfileListParamIdentifierArray].append("user2");
* 
* int ret = TIMProfileGetUserProfileList(json_get_user_profile_list_param.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
*     if (ERR_SUCC != code) {
*         // ��ȡ�����б�ʧ��
*         return;
*     }
* }, nullptr);
* 
* @note
* ����ͨ�������ȡ�κ��˵ĸ������ϣ������Լ��ĸ������ϡ�����ȡ�ĸ������ϲ����Լ�������ʱ����ȡ�ĸ������ϼӺ���ѡ��ֵΪ kTIMProfileAddPermission_Unknown ���޷���ȡ�����Լ��ļӺ���Ȩ����Ϣ��Ĭ�Ϸ���δ֪��
*/
TIM_DECL int TIMProfileGetUserProfileList(const char* json_get_user_profile_list_param, TIMCommCallback cb, const void* user_data);

/**
* @brief �޸��Լ��ĸ�������
*
* @param json_modify_self_user_profile_param �޸��Լ������Ͻӿڲ�����Json�ַ���
* @param cb �޸��Լ������ϳɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value modify_item;
* modify_item[kTIMUserProfileItemNickName] = "change my nick name"; // �޸��ǳ�
* modify_item[kTIMUserProfileItemGender] = kTIMGenderType_Female;  // �޸��Ա�
* modify_item[kTIMUserProfileItemAddPermission] = kTIMProfileAddPermission_NeedConfirm;  // �޸���Ӻ���Ȩ��
*
* Json::Value json_user_profile_item_custom;
* json_user_profile_item_custom[kTIMUserProfileCustemStringInfoKey] = "Str";  // �޸ĸ��������Զ����ֶ� "Str" ��ֵ
* json_user_profile_item_custom[kTIMUserProfileCustemStringInfoValue] = "my define data";
* modify_item[kTIMUserProfileItemCustomStringArray].append(json_user_profile_item_custom);
* int ret = TIMProfileModifySelfUserProfile(modify_item.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
*     if (ERR_SUCC != code) {
*         // �޸��Լ��ĸ�������ʧ��
*         return;
*     }
* }, nullptr);
*
* @note
* �޸ĺ������ϣ�Ŀǰ֧���޸ĵ��ֶ���ο�[UserProfileItem](TIMCloudDef.h)��һ�οɸ��¶���ֶΡ��޸��Զ����ֶ�ʱ�����keyֵ������� Tag_Profile_Custom_ ǰ׺��Ҳ���Բ���� Tag_Profile_Custom_ ǰ׺���������ʱ��SDK�ڲ����Զ���Ӹ�ǰ׺��
*/
TIM_DECL int TIMProfileModifySelfUserProfile(const char* json_modify_self_user_profile_param, TIMCommCallback cb, const void* user_data);
/// @}

/////////////////////////////////////////////////////////////////////////////////
//
//                      ��ϵ����ؽӿ�
//
/////////////////////////////////////////////////////////////////////////////////
/// @name ��ϵ����ؽӿ�
/// @brief ��ϵ��������ο� [��ϵ��ϵͳ���](https://cloud.tencent.com/document/product/269/1501#.E5.85.B3.E7.B3.BB.E9.93.BE.E7.B3.BB.E7.BB.9F.E7.AE.80.E4.BB.8B)
/// @{
/**
* @brief ��ȡ�����б�
*
* @param cb ��ȡ�����б�ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @note
* �˽ӿ�ͨ���ص��������к�������[FriendProfile](TIMCloudDef.h).
*/
TIM_DECL int TIMFriendshipGetFriendProfileList(TIMCommCallback cb, const void* user_data);

/**
* @brief ��Ӻ���
*
* @param json_add_friend_param ��Ӻ��ѽӿڲ�����Json�ַ���
* @param cb ��Ӻ��ѳɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_add_friend_param;
* json_add_friend_param[kTIMFriendshipAddFriendParamIdentifier] = "user4";
* json_add_friend_param[kTIMFriendshipAddFriendParamFriendType] = FriendTypeBoth;
* json_add_friend_param[kTIMFriendshipAddFriendParamAddSource] = "Windows";
* json_add_friend_param[kTIMFriendshipAddFriendParamAddWording] = "I am Iron Man";
* int ret = TIMFriendshipAddFriend(json_add_friend_param.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
*     if (ERR_SUCC != code) {
*         // ��Ӻ���ʧ��
*         return;
*     }
* }, nullptr);
*
* @note
* ���ѹ�ϵ�е����˫�����֮�֡�������ο�[��Ӻ���](https://cloud.tencent.com/document/product/269/1501#.E6.B7.BB.E5.8A.A0.E5.A5.BD.E5.8F.8B).
*/
TIM_DECL int TIMFriendshipAddFriend(const char* json_add_friend_param, TIMCommCallback cb, const void* user_data);

/**
* @brief �����������
*
* @param json_handle_friend_add_param �����������ӿڲ�����Json�ַ���
* @param cb �����������ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_handle_friend_add_param;
* json_handle_friend_add_param[kTIMFriendResponeIdentifier] = "user1";
* json_handle_friend_add_param[kTIMFriendResponeAction] = ResponseActionAgreeAndAdd;
* json_handle_friend_add_param[kTIMFriendResponeRemark] = "I am Captain China";
* json_handle_friend_add_param[kTIMFriendResponeGroupName] = "schoolmate";
* int ret = TIMFriendshipHandleFriendAddRequest(json_handle_friend_add_param.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
*
* }, nullptr);
*
* @note
* ���Լ��ĸ������ϵļӺ���Ȩ�� kTIMUserProfileAddPermission ����Ϊ kTIMProfileAddPermission_NeedConfirm ʱ����������Լ�Ϊ����ʱ���յ�һ���Ӻ��ѵ����󣬿�ͨ���˽ӿڴ���Ӻ��ѵ�����
*/
TIM_DECL int TIMFriendshipHandleFriendAddRequest(const char* json_handle_friend_add_param, TIMCommCallback cb, const void* user_data);

/**
* @brief ���º�������(��ע��)
*
* @param json_modify_friend_info_param ���º������Ͻӿڲ�����Json�ַ���
* @param cb ���º������ϳɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_modify_friend_profile_item;
* json_modify_friend_profile_item[kTIMFriendProfileItemRemark] = "xxxx yyyy";  // �޸ı�ע
* json_modify_friend_profile_item[kTIMFriendProfileItemGroupNameArray].append("group1"); // �޸ĺ������ڷ���
* json_modify_friend_profile_item[kTIMFriendProfileItemGroupNameArray].append("group2");
*
* Json::Value json_modify_friend_profilie_custom;
* json_modify_friend_profilie_custom[kTIMFriendProfileCustemStringInfoKey] = "Str";
* json_modify_friend_profilie_custom[kTIMFriendProfileCustemStringInfoValue] = "this is changed value";
* json_modify_friend_profile_item[kTIMFriendProfileItemCustomStringArray].append(json_modify_friend_profilie_custom); // �޸ĺ��������Զ����ֶ� "Str" ��ֵ

* Json::Value json_modify_friend_info_param;
* json_modify_friend_info_param[kTIMFriendshipModifyFriendProfileParamIdentifier] = "user4";
* json_modify_friend_info_param[kTIMFriendshipModifyFriendProfileParamItem] = json_modify_friend_profile_item;
* int ret = TIMFriendshipModifyFriendProfile(json_modify_friend_info_param.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
* 
* }, nullptr);
*
* @note
* �޸ĺ������ϣ�Ŀǰ֧���޸ĵ��ֶ���ο�[FriendProfileItem](TIMCloudDef.h)��һ�ο��޸Ķ���ֶΡ��޸��Զ����ֶ�ʱ�����keyֵ������� Tag_SNS_Custom_ ǰ׺��Ҳ���Բ���� Tag_SNS_Custom_ ǰ׺���������ʱ��SDK�ڲ����Զ���Ӹ�ǰ׺��
*/
TIM_DECL int TIMFriendshipModifyFriendProfile(const char* json_modify_friend_info_param, TIMCommCallback cb, const void* user_data);

/**
* @brief ɾ������
*
* @param json_delete_friend_param ɾ�����ѽӿڲ�����Json�ַ���
* @param cb ɾ�����ѳɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_delete_friend_param;
* json_delete_friend_param[kTIMFriendshipDeleteFriendParamIdentifierArray].append("user4");
* json_delete_friend_param[kTIMFriendshipDeleteFriendParamFriendType] = FriendTypeSignle;
* int ret = TIMFriendshipDeleteFriend(json_delete_friend_param.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
*     if (ERR_SUCC != code) {
*         // ɾ������ʧ��
*         return;
*     }
* }, nullptr);
*
* @note
* ɾ������Ҳ��ɾ��������ѻ���˫�����֮�֣�[ɾ������](https://cloud.tencent.com/document/product/269/1501#.E5.88.A0.E9.99.A4.E5.A5.BD.E5.8F.8B).
*/
TIM_DECL int TIMFriendshipDeleteFriend(const char* json_delete_friend_param, TIMCommCallback cb, const void* user_data);


/**
* @brief ����������(����Ļ���˫���)
*
* @param json_check_friend_list_param �����ѽӿڲ�����Json�ַ���
* @param cb �����ѳɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_check_friend_list_param;
* json_check_friend_list_param[kTIMFriendshipCheckFriendTypeParamCheckType] = FriendTypeBoth;
* json_check_friend_list_param[kTIMFriendshipCheckFriendTypeParamIdentifierArray].append("user4");
* int ret = TIMFriendshipCheckFriendType(json_check_friend_list_param.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
*
* }, nullptr);
*
* @note
* �����߿���ͨ���˽ӿڼ������� identifier �б����ǰ�˻��ĺ��ѹ�ϵ��[������](https://cloud.tencent.com/document/product/269/1501#.E6.A0.A1.E9.AA.8C.E5.A5.BD.E5.8F.8B)��
*/
TIM_DECL int TIMFriendshipCheckFriendType(const char* json_check_friend_list_param, TIMCommCallback cb, const void* user_data);

/**
* @brief �������ѷ���
*
* @param json_create_friend_group_param �������ѷ���ӿڲ�����Json�ַ���
* @param cb �������ѷ���ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_create_friend_group_param;
* json_create_friend_group_param[kTIMFriendshipCreateFriendGroupParamNameArray].append("Group123");
* json_create_friend_group_param[kTIMFriendshipCreateFriendGroupParamIdentifierArray].append("user4");
* json_create_friend_group_param[kTIMFriendshipCreateFriendGroupParamIdentifierArray].append("user10");
* int ret = TIMFriendshipCreateFriendGroup(json_create_friend_group_param.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
*     
* }, nullptr);
*
* @note
* ���ܴ����Ѵ��ڵķ��顣
*/
TIM_DECL int TIMFriendshipCreateFriendGroup(const char* json_create_friend_group_param, TIMCommCallback cb, const void* user_data);

/**
* @brief ��ȡָ�����ѷ���ķ�����Ϣ
*
* @param json_get_friend_group_list_param ��ȡ���ѷ�����Ϣ�ӿڲ�����Json�ַ���
* @param cb ��ȡ���ѷ�����Ϣ�ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_get_friend_group_list_param;
* json_get_friend_group_list_param.append("Group123");
* int ret = TIMFriendshipGetFriendGroupList(json_get_friend_group_list_param.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
*     
* }, nullptr);
*
*/
TIM_DECL int TIMFriendshipGetFriendGroupList(const char* json_get_friend_group_list_param, TIMCommCallback cb, const void* user_data);


/**
* @brief �޸ĺ��ѷ���
*
* @param json_modify_friend_group_param �޸ĺ��ѷ���ӿڲ�����Json�ַ���
* @param cb �޸ĺ��ѷ���ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_modify_friend_group_param;
* json_modify_friend_group_param[kTIMFriendshipModifyFriendGroupParamName] = "Group123";
* json_modify_friend_group_param[kTIMFriendshipModifyFriendGroupParamNewName] = "GroupNewName";
* json_modify_friend_group_param[kTIMFriendshipModifyFriendGroupParamDeleteIdentifierArray].append("user4");
* json_modify_friend_group_param[kTIMFriendshipModifyFriendGroupParamAddIdentifierArray].append("user9");
* json_modify_friend_group_param[kTIMFriendshipModifyFriendGroupParamAddIdentifierArray].append("user5");
* int ret = TIMFriendshipModifyFriendGroup(json_modify_friend_group_param.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
*     
* }, nullptr);
*
*/
TIM_DECL int TIMFriendshipModifyFriendGroup(const char* json_modify_friend_group_param, TIMCommCallback cb, const void* user_data);

/**
* @brief ɾ�����ѷ���
*
* @param json_delete_friend_group_param ɾ�����ѷ���ӿڲ�����Json�ַ���
* @param cb ɾ�����ѷ���ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_delete_friend_group_param;
* json_delete_friend_group_param.append("GroupNewName");
* int ret = TIMFriendshipDeleteFriendGroup(json_delete_friend_group_param.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
*     
* }, nullptr);
*
*/
TIM_DECL int TIMFriendshipDeleteFriendGroup(const char* json_delete_friend_group_param, TIMCommCallback cb, const void* user_data);

/**
* @brief ���ָ���û���������
*
* @param json_add_to_blacklist_param ���ָ���û����������ӿڲ�����Json�ַ���
* @param cb ���ָ���û����������ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_add_to_blacklist_param;
* json_add_to_blacklist_param.append("user5");
* json_add_to_blacklist_param.append("user10");
* int ret = TIMFriendshipAddToBlackList(json_add_to_blacklist_param.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
*     
* }, nullptr);
*
*/
TIM_DECL int TIMFriendshipAddToBlackList(const char* json_add_to_blacklist_param, TIMCommCallback cb, const void* user_data);


/**
* @brief ��ȡ�������б�
*
* @param cb ��ȡ�������б�ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
*/
TIM_DECL int TIMFriendshipGetBlackList(TIMCommCallback cb, const void* user_data);

/**
* @brief �Ӻ�������ɾ��ָ���û��б�
*
* @param json_delete_from_blacklist_param �Ӻ�������ɾ��ָ���û��ӿڲ�����Json�ַ���
* @param cb �Ӻ�������ɾ��ָ���û��ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_delete_from_blacklist_param;
* json_delete_from_blacklist_param.append("user5");
* json_delete_from_blacklist_param.append("user10");
* int ret = TIMFriendshipDeleteFromBlackList(json_delete_from_blacklist_param.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
*     
* }, nullptr);
*
*/
TIM_DECL int TIMFriendshipDeleteFromBlackList(const char* json_delete_from_blacklist_param, TIMCommCallback cb, const void* user_data);


/**
* @brief ��ȡ�����������δ����Ϣ�б�
*
* @param json_get_pendency_list_param ��ȡδ���б�ӿڲ�����Json�ַ���
* @param cb ��ȡδ���б�ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_get_pendency_list_param;
* json_get_pendency_list_param[kTIMFriendshipGetPendencyListParamType] = FriendPendencyTypeBoth;
* json_get_pendency_list_param[kTIMFriendshipGetPendencyListParamStartSeq] = 0;
* int ret = TIMFriendshipGetPendencyList(json_get_pendency_list_param.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
*     
* }, nullptr);
*
* @note
* �����������δ����Ϣ��ָ�����������δ����Ĳ��������磬��������ӶԷ�Ϊ���ѣ��Է���û�д�������������ӿ�����Ϊ���ѣ������߻�û�д�����֮Ϊ�����������δ����Ϣ
*/
TIM_DECL int TIMFriendshipGetPendencyList(const char* json_get_pendency_list_param, TIMCommCallback cb, const void* user_data);

/**
* @brief ɾ��ָ�������������δ����Ϣ
*
* @param json_delete_pendency_param ɾ��ָ��δ����Ϣ�ӿڲ�����Json�ַ���
* @param cb ɾ��ָ��δ����Ϣ�ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
* @example
* Json::Value json_delete_pendency_param;
* json_delete_pendency_param[kTIMFriendshipDeletePendencyParamType] = FriendPendencyTypeComeIn;
* json_delete_pendency_param[kTIMFriendshipDeletePendencyParamIdentifierArray].append("user1");
* int ret = TIMFriendshipDeletePendency(json_delete_pendency_param.toStyledString().c_str(), [](int32_t code, const char* desc, const char* json_params, const void* user_data) {
*     
* }, nullptr);
*
*/
TIM_DECL int TIMFriendshipDeletePendency(const char* json_delete_pendency_param, TIMCommCallback cb, const void* user_data);

/**
* @brief �ϱ������������δ����Ϣ�Ѷ�
*
* @param time_stamp �ϱ�δ����Ϣ�Ѷ�ʱ���
* @param cb �ϱ�δ����Ϣ�Ѷ��û��ɹ����Ļص����ص�����������ο� [TIMCommCallback](TIMCloudCallback.h)
* @param user_data �û��Զ������ݣ�ImSDKֻ���𴫻ظ��ص�����cb�������κδ���
* @return int ����TIM_SUCC��ʾ�ӿڵ��óɹ����ӿ�ֻ�з���TIM_SUCC���ص�cb�Żᱻ���ã�������ֵ��ʾ�ӿڵ���ʧ�ܡ�ÿ������ֵ�Ķ�����ο� [TIMResult](TIMCloudDef.h)
*
*/
TIM_DECL int TIMFriendshipReportPendencyReaded(uint64_t time_stamp, TIMCommCallback cb, const void* user_data);
/// @}

#ifdef __cplusplus
};
#endif //__cplusplus

#endif //SDK_CLOUD_TIM_HEADER_
