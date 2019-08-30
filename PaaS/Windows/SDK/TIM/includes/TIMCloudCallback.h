#ifndef SDK_CLOUD_TIM_CALLBACK_HEADER_
#define SDK_CLOUD_TIM_CALLBACK_HEADER_
#include "TIMCloudDef.h"

#ifdef __cplusplus
extern"C"
{
#endif

/////////////////////////////////////////////////////////////////////////////////
//
//                       ImSDK�¼��ص�
//
/////////////////////////////////////////////////////////////////////////////////
/// @name ImSDK�¼��ص�
/// @{
/**
* @brief ����Ϣ�ص�
*
* @param json_msg_array ����Ϣ����
* @param user_data ImSDK����͸�����û��Զ������ݣ�δ���κδ���
* 
* @note
* �˻ص����Ի�ȡ�½��յ���Ϣ���顣ע�� ��Ϣ�ڵ�Ԫ��Ҳ��һ�����顣ÿ��Ԫ�صĶ����� elem_type �ֶξ���
*
*/
typedef void (*TIMRecvNewMsgCallback)(const char* json_msg_array, const void* user_data);
/***
*
* @example ��Ϣ�������ʾ��
* Json::Value json_value_msgs; // ������Ϣ
* Json::Reader reader;
* if (!reader.parse(json_msg_array, json_value_msgs)) {
*     printf("reader parse failure!%s", reader.getFormattedErrorMessages().c_str());
*     return;
* }
* for (Json::ArrayIndex i = 0; i < json_value_msgs.size(); i++) {  // ����Message
*     Json::Value& json_value_msg = json_value_msgs[i];
*     Json::Value& elems = json_value_msg[kTIMMsgElemArray];
*     for (Json::ArrayIndex m = 0; m < elems.size(); m++) {   // ����Elem
*         Json::Value& elem = elems[i];
*
*         uint32_t elem_type = elem[kTIMElemType].asUInt();
*         if (elem_type == TIMElemType::kTIMElem_Text) {  // �ı�
*             
*         } else if (elem_type == TIMElemType::kTIMElem_Sound) {  // ����
*             
*         } else if (elem_type == TIMElemType::kTIMElem_File) {  // �ļ�
*             
*         } else if (elem_type == TIMElemType::kTIMElem_Image) { // ͼƬ
*             
*         } else if (elem_type == TIMElemType::kTIMElem_Custom) { // �Զ���Ԫ��
*             
*         } else if (elem_type == TIMElemType::kTIMElem_GroupTips) { // Ⱥ��ϵͳ��Ϣ
*             
*         } else if (elem_type == TIMElemType::kTIMElem_Face) { // ����
*             
*         } else if (elem_type == TIMElemType::kTIMElem_Location) { // λ��
*             
*         } else if (elem_type == TIMElemType::kTIMElem_GroupReport) { // Ⱥ��ϵͳ֪ͨ
*             
*         } else if (elem_type == TIMElemType::kTIMElem_Video) { // ��Ƶ
*             
*         }
*     }
* }
* 
* @example ����һ���ı���Ϣ��Jsonʾ����Json Key��ο�[Message](TIMCloudDef.h)��[TextElem](TIMCloudDef.h)
* [
*    {
*       "message_client_time" : 1551080111,
*       "message_conv_id" : "user2",
*       "message_conv_type" : 1,
*       "message_elem_array" : [
*          {
*             "elem_type" : 0,
*             "text_elem_content" : "123213213"
*          }
*       ],
*       "message_is_from_self" : true,
*       "message_is_read" : true,
*       "message_rand" : 2130485001,
*       "message_sender" : "user1",
*       "message_seq" : 1,
*       "message_server_time" : 1551080111,
*       "message_status" : 2
*    }
* ]
*
* @example ����һ��Ⱥ֪ͨ��Ϣ��Jsonʾ����Json Key��ο�[Message](TIMCloudDef.h)��[GroupReportElem](TIMCloudDef.h)
* [
*    {
*       "message_client_time" : 1551344977,
*       "message_conv_id" : "",
*       "message_conv_type" : 3,
*       "message_elem_array" : [
*          {
*             "elem_type" : 9,
*             "group_report_elem_group_id" : "first group id",
*             "group_report_elem_group_name" : "first group name",
*             "group_report_elem_msg" : "",
*             "group_report_elem_op_group_memberinfo" : {
*                "group_member_info_custom_info" : {},
*                "group_member_info_identifier" : "user1",
*                "group_member_info_join_time" : 0,
*                "group_member_info_member_role" : 0,
*                "group_member_info_msg_flag" : 0,
*                "group_member_info_msg_seq" : 0,
*                "group_member_info_name_card" : "",
*                "group_member_info_shutup_time" : 0
*             },
*             "group_report_elem_op_user" : "",
*             "group_report_elem_platform" : "Windows",
*             "group_report_elem_report_type" : 6,
*             "group_report_elem_user_data" : ""
*          }
*       ],
*       "message_is_from_self" : false,
*       "message_is_read" : true,
*       "message_rand" : 2207687390,
*       "message_sender" : "@TIM#SYSTEM",
*       "message_seq" : 1,
*       "message_server_time" : 1551344977,
*       "message_status" : 2
*    }
* ]
* 
* @example ����һ��Ⱥ��ʾ��Ϣ��Jsonʾ����Json Key��ο�[Message](TIMCloudDef.h)��[GroupTipsElem](TIMCloudDef.h)
* [
*    {
*       "message_client_time" : 1551412814,
*       "message_conv_id" : "first group id",
*       "message_conv_type" : 2,
*       "message_elem_array" : [
*          {
*             "elem_type" : 6,
*             "group_tips_elem_changed_group_memberinfo_array" : [],
*             "group_tips_elem_group_change_info_array" : [
*                {
*                   "group_tips_group_change_info_flag" : 10,
*                   "group_tips_group_change_info_value" : "first group name to other name"
*                }
*             ],
*             "group_tips_elem_group_id" : "first group id",
*             "group_tips_elem_group_name" : "first group name to other name",
*             "group_tips_elem_member_change_info_array" : [],
*             "group_tips_elem_member_num" : 0,
*             "group_tips_elem_op_group_memberinfo" : {
*                "group_member_info_custom_info" : {},
*                "group_member_info_identifier" : "user1",
*                "group_member_info_join_time" : 0,
*                "group_member_info_member_role" : 0,
*                "group_member_info_msg_flag" : 0,
*                "group_member_info_msg_seq" : 0,
*                "group_member_info_name_card" : "",
*                "group_member_info_shutup_time" : 0
*             },
*             "group_tips_elem_op_user" : "user1",
*             "group_tips_elem_platform" : "Windows",
*             "group_tips_elem_time" : 0,
*             "group_tips_elem_tip_type" : 6,
*             "group_tips_elem_user_array" : []
*          }
*       ],
*       "message_is_from_self" : false,
*       "message_is_read" : true,
*       "message_rand" : 1,
*       "message_sender" : "@TIM#SYSTEM",
*       "message_seq" : 1,
*       "message_server_time" : 1551412814,
*       "message_status" : 2
*    },
* ]
**/


/**
* @brief ��Ϣ�Ѷ���ִ�ص�
*
* @param json_msg_readed_receipt_array ��Ϣ�Ѷ���ִ����
* @param user_data ImSDK����͸�����û��Զ������ݣ�δ���κδ���
*
* @example
* void MsgReadedReceiptCallback(const char* json_msg_readed_receipt_array, const void* user_data) {
*     Json::Value json_value_receipts;
*     Json::Reader reader;
*     if (!reader.parse(json_msg_readed_receipt_array, json_value_receipts)) {
*         // Json ����ʧ��
*         return;
*     }
*     
*     for (Json::ArrayIndex i = 0; i < json_value_receipts.size(); i++) {
*         Json::Value& json_value_receipt = json_value_receipts[i];
*     
*         std::string convid = json_value_receipt[kTIMMsgReceiptConvId].asString();
*         uint32_t conv_type = json_value_receipt[kTIMMsgReceiptConvType].asUInt();
*         uint64_t timestamp = json_value_receipt[kTIMMsgReceiptTimeStamp].asUInt64();
*     
*         // ��Ϣ�Ѷ��߼�
*     }
* }
*/
typedef void (*TIMMsgReadedReceiptCallback)(const char* json_msg_readed_receipt_array, const void* user_data);

/**
* @brief ���յ���Ϣ�����ػص�
*
* @param json_msg_locator_array ��Ϣ��λ������
* @param user_data ImSDK����͸�����û��Զ������ݣ�δ���κδ���
* 
* @example
* void MsgRevokeCallback(const char* json_msg_locator_array, const void* user_data) {
*     Json::Value json_value_locators;
*     Json::Reader reader;
*     if (!reader.parse(json_msg_locator_array, json_value_locators)) {
*         // Json ����ʧ��
*         return;
*     }
*     for (Json::ArrayIndex i = 0; i < json_value_locators.size(); i++) {
*         Json::Value& json_value_locator = json_value_locators[i];
*     
*         std::string convid = json_value_locator[kTIMMsgLocatorConvId].asString();
*         uint32_t conv_type = json_value_locator[kTIMMsgLocatorConvType].asUInt();
*         bool isrevoke      = json_value_locator[kTIMMsgLocatorIsRevoked].asBool();
*         uint64_t time      = json_value_locator[kTIMMsgLocatorTime].asUInt64();
*         uint64_t seq       = json_value_locator[kTIMMsgLocatorSeq].asUInt64();
*         uint64_t rand      = json_value_locator[kTIMMsgLocatorRand].asUInt64();
*         bool isself        = json_value_locator[kTIMMsgLocatorIsSelf].asBool();
*     
*         // ��Ϣ�����߼�
*     }
* }
* 
*/
typedef void (*TIMMsgRevokeCallback)(const char* json_msg_locator_array, const void* user_data);

/**
* @brief ��Ϣ��Ԫ������ļ��ϴ����Ȼص�
*
* @param json_msg ����Ϣ
* @param index �ϴ� Elem Ԫ���� json_msg ��Ϣ���±�
* @param cur_size �ϴ���ǰ��С
* @param total_size �ϴ��ܴ�С
* @param user_data ImSDK����͸�����û��Զ������ݣ�δ���κδ���
*
* @example
* void MsgElemUploadProgressCallback(const char* json_msg, uint32_t index, uint32_t cur_size, uint32_t total_size, const void* user_data) {
*     Json::Value json_value_msg;
*     Json::Reader reader;
*     if (!reader.parse(json_msg, json_value_msg)) {
*         // Json ����ʧ��
*         return;
*     }
*     Json::Value& elems = json_value_msg[kTIMMsgElemArray];
*     if (index >= elems.size()) {
*         // index ������ϢԪ�ظ�����Χ
*         return;
*     }
*     uint32_t elem_type = elems[index][kTIMElemType].asUInt();
*     if (kTIMElem_File ==  elem_type) {
* 
*     }
*     else if (kTIMElem_Sound == elem_type) {
* 
*     }
*     else if (kTIMElem_Video == elem_type) {
*
*     }
*     else if (kTIMElem_Image == elem_type) {
*
*     }
*     else {
*         // ��������Ԫ�ز������ϴ�Ҫ��
*     }
* }
*/
typedef void (*TIMMsgElemUploadProgressCallback)(const char* json_msg, uint32_t index, uint32_t cur_size, uint32_t total_size, const void* user_data);



/**
* @brief Ⱥ�¼��ص�
*
* @param json_group_tip_array Ⱥ��ʾ�б�
* @param user_data ImSDK����͸�����û��Զ������ݣ�δ���κδ���
*/
typedef void (*TIMGroupTipsEventCallback)(const char* json_group_tip_array, const void* user_data);

/**
* @brief �Ự�¼��ص�
*
* @param conv_event �Ự�¼����ͣ���ο�[TIMConvEvent](TIMCloudDef.h)
* @param json_conv_array �Ự��Ϣ�б�
* @param user_data ImSDK����͸�����û��Զ������ݣ�δ���κδ���
*
* @example �Ự�¼��ص����ݽ���
* void ConvEventCallback(TIMConvEvent conv_event, const char* json_conv_array, const void* user_data) {
*     Json::Reader reader;
*     Json::Value json_value;
*     if (!reader.parse(json_conv_array, json_value)) {
*         // Json ����ʧ��
*         return;
*     }
*     for (Json::ArrayIndex i = 0; i < json_value.size(); i++) { // �����Ự���
*         Json::Value& convinfo = json_value[i];
*         // ���ֻỰ�¼�����
*         if (conv_event == kTIMConvEvent_Add) {
*
*         }
*         else if (conv_event == kTIMConvEvent_Del) {
*
*         }
*         else if (conv_event == kTIMConvEvent_Update) {
*
*         }
*     }
* }
*/
typedef void (*TIMConvEventCallback)(enum TIMConvEvent conv_event, const char* json_conv_array, const void* user_data);

/**
* @brief ����״̬�ص�
*
* @param status ����״̬����ο�[TIMNetworkStatus](TIMCloudDef.h)
* @param code ֵΪERR_SUCC��ʾ�ɹ�������ֵ��ʾʧ�ܡ�������ο� [������](https://cloud.tencent.com/document/product/269/1671)
* @param desc ���������ַ���
* @param user_data ImSDK����͸�����û��Զ������ݣ�δ���κδ���
*/
typedef void (*TIMNetworkStatusListenerCallback)(enum TIMNetworkStatus status, int32_t code, const char* desc, const void* user_data);
/***
*
* @example ��֪����״̬�Ļص�����
* void NetworkStatusListenerCallback(TIMNetworkStatus status, int32_t code, const char* desc, const void* user_data) {
*     switch(status) {
*     case kTIMConnected: {
*         printf("OnConnected ! user_data:0x%08x", user_data);
*         break;
*     }
*     case kTIMDisconnected:{
*         printf("OnDisconnected ! user_data:0x%08x", user_data);
*         break;
*     }
*     case kTIMConnecting:{
*         printf("OnConnecting ! user_data:0x%08x", user_data);
*         break;
*     }
*     case kTIMConnectFailed:{
*         printf("ConnectFailed code:%u desc:%s ! user_data:0x%08x", code, desc, user_data);
*         break;
*     }
*     }
* }
**/

/**
* @brief �������߻ص�
*
* @param user_data ImSDK����͸�����û��Զ������ݣ�δ���κδ���
*/
typedef void (*TIMKickedOfflineCallback)(const void* user_data);

/**
* @brief �û�Ʊ�ݹ��ڻص�
*
* @param user_data ImSDK����͸�����û��Զ������ݣ�δ���κδ���
*/
typedef void (*TIMUserSigExpiredCallback)(const void* user_data);

/**
* @brief ��־�ص�
*
* @param level ��־����,��ο�[TIMLogLevel](TIMCloudDef.h)
* @param log �����ַ���
* @param user_data ImSDK����͸�����û��Զ������ݣ�δ���κδ���
*/
typedef void (*TIMLogCallback)(enum TIMLogLevel level, const char* log, const void* user_data);

/**
* @brief ��Ϣ���»ص�
*
* @param json_msg_array ���µ���Ϣ����
* @param user_data ImSDK����͸�����û��Զ������ݣ�δ���κδ���
*
* @note
* ��ο� [TIMRecvNewMsgCallback]()
*/
typedef void (*TIMMsgUpdateCallback)(const char* json_msg_array, const void* user_data);
/// @}


/////////////////////////////////////////////////////////////////////////////////
//
//                       ImSDK�ӿڻص�
//
/////////////////////////////////////////////////////////////////////////////////
/// @name ImSDK�ӿڻص�
/// @{
/**
* @brief �ӿڻص�����
*
* @param code ֵΪERR_SUCC��ʾ�ɹ�������ֵ��ʾʧ�ܡ�������ο� [������](https://cloud.tencent.com/document/product/269/1671)
* @param desc ���������ַ���
* @param json_params Json�ַ�������ͬ�Ľӿڣ�Json�ַ�����һ��
* @param user_data ImSDK����͸�����û��Զ������ݣ�δ���κδ���
*
* @note
* ���лص������ж�code�Ƿ����ERR_SUC����������˵���ӿڵ���ʧ���ˣ�����ԭ����Կ�code��ֵ�Լ�desc������������ο�[������](https://cloud.tencent.com/document/product/269/1671)
*/
typedef void (*TIMCommCallback)(int32_t code, const char* desc, const char* json_params, const void* user_data);
/***
* 
* @example �ӿ�[TIMSetConfig](TIMCloud.h)�Ļص�TIMCommCallback����json_params��Json��Json Key��ο�[SetConfig](TIMCloudDef.h)��
* {
*    "set_config_callback_log_level" : 2,
*    "set_config_is_log_output_console" : true,
*    "set_config_log_level" : 2,
*    "set_config_proxy_info" : {
*       "proxy_info_ip" : "",
*       "proxy_info_port" : 0
*    },
*    "set_config_user_config" : {
*       "user_config_group_getinfo_option" : {
*          "get_info_option_custom_array" : [],
*          "get_info_option_info_flag" : 0xffffffff,
*          "get_info_option_role_flag" : 0
*       },
*       "user_config_group_member_getinfo_option" : {
*          "get_info_option_custom_array" : [],
*          "get_info_option_info_flag" : 0xffffffff,
*          "get_info_option_role_flag" : 0
*       },
*       "user_config_is_ingore_grouptips_unread" : false,
*       "user_config_is_read_receipt" : false,
*       "user_config_is_sync_report" : false
*    }
* }
*
* @example �ӿ�[TIMConvCreate](TIMCloud.h)�Ļص�TIMCommCallback����json_params��Json��Json Key��ο�[ConvInfo](TIMCloudDef.h)��
* {
*    "conv_active_time" : 1551269275,
*    "conv_id" : "user2",
*    "conv_is_has_draft" : false,
*    "conv_is_has_lastmsg" : true,
*    "conv_last_msg" : {
*       "message_client_time" : 1551101578,
*       "message_conv_id" : "user2",
*       "message_conv_type" : 1,
*       "message_elem_array" : [
*          {
*             "elem_type" : 0,
*             "text_elem_content" : "12"
*          }
*       ],
*       "message_is_from_self" : false,
*       "message_is_read" : true,
*       "message_rand" : 3726251374,
*       "message_sender" : "user2",
*       "message_seq" : 56858,
*       "message_server_time" : 1551101578,
*       "message_status" : 2
*    },
*    "conv_owner" : "",
*    "conv_type" : 1,
*    "conv_unread_num" : 1
* }
* 
* @example �ӿ�[TIMConvGetConvList](TIMCloud.h)�Ļص�TIMCommCallback����json_params��Json��Json Key��ο�[ConvInfo](TIMCloudDef.h)��
* [
*    {
*       "conv_active_time" : 1551269275,
*       "conv_id" : "user2",
*       "conv_is_has_draft" : false,
*       "conv_is_has_lastmsg" : true,
*       "conv_last_msg" : {
*          "message_client_time" : 1551235066,
*          "message_conv_id" : "user2",
*          "message_conv_type" : 1,
*          "message_elem_array" : [
*             {
*                "elem_type" : 0,
*                "text_elem_content" : "ccccccccccccccccc"
*             }
*          ],
*          "message_is_from_self" : true,
*          "message_is_read" : true,
*          "message_rand" : 1073033786,
*          "message_sender" : "user1",
*          "message_seq" : 16373,
*          "message_server_time" : 1551235067,
*          "message_status" : 2
*       },
*       "conv_owner" : "",
*       "conv_type" : 1,
*       "conv_unread_num" : 0
*    }
* ]
* @example �ӿ�[TIMMsgSendNewMsg](TIMCloud.h)�Ļص�TIMCommCallback����json_params��Json��Json Key��ο�[Message](TIMCloudDef.h)��
* {
*    "message_client_time" : 1558598732,
*    "message_conv_id" : "asd12341",
*    "message_conv_type" : 1,
*    "message_custom_int" : 0,
*    "message_custom_str" : "",
*    "message_elem_array" : [
*       {
*          "elem_type" : 0,
*          "text_elem_content" : "test"
*       }
*    ],
*    "message_is_from_self" : true,
*    "message_is_online_msg" : false,
*    "message_is_peer_read" : false,
*    "message_is_read" : true,
*    "message_priority" : 1,
*    "message_rand" : 1340036983,
*    "message_sender" : "test_win_01",
*    "message_seq" : 20447,
*    "message_server_time" : 1558598733,
*    "message_status" : 2
* }
*
* @example �ӿ�[TIMMsgFindByMsgLocatorList](TIMCloud.h)�Ļص�TIMCommCallback����json_params��Json��Json Key��ο�[Message](TIMCloudDef.h)��
* [
*    {
*       "message_client_time" : 1551080111,
*       "message_conv_id" : "user2",
*       "message_conv_type" : 1,
*       "message_elem_array" : [
*          {
*             "elem_type" : 0,
*             "text_elem_content" : "123213213"
*          }
*       ],
*       "message_is_from_self" : true,
*       "message_is_read" : true,
*       "message_rand" : 2130485001,
*       "message_sender" : "user1",
*       "message_seq" : 1,
*       "message_server_time" : 1551080111,
*       "message_status" : 2
*    },
*    ...
* ]
* 
* @example �ӿ�[TIMMsgGetMsgList](TIMCloud.h)�Ļص�TIMCommCallback����json_params��Json��Json Key��ο�[Message](TIMCloudDef.h)��
* [
*    {
*       "message_client_time" : 1551080111,
*       "message_conv_id" : "user2",
*       "message_conv_type" : 1,
*       "message_elem_array" : [
*          {
*             "elem_type" : 0,
*             "text_elem_content" : "123213213"
*          }
*       ],
*       "message_is_from_self" : true,
*       "message_is_read" : true,
*       "message_rand" : 2130485001,
*       "message_sender" : "user1",
*       "message_seq" : 1,
*       "message_server_time" : 1551080111,
*       "message_status" : 2
*    },
*    ...
* ]
*
* @example �ӿ�[TIMMsgDownloadElemToPath](TIMCloud.h)�Ļص�TIMCommCallback����json_params��Json��Json Key��ο�[MsgDownloadElemResult](TIMCloudDef.h)��
* {
*   "msg_download_elem_result_current_size" : 10,
*   "msg_download_elem_result_total_size" : 100
* }
* 
* @example �ӿ�[TIMMsgBatchSend](TIMCloud.h)�Ļص�TIMCommCallback����json_params��Json��Json Key��ο�[MsgBatchSendResult](TIMCloudDef.h)��
* [
*    {
*       "msg_batch_send_result_code" : 0,
*       "msg_batch_send_result_desc" : "",
*       "msg_batch_send_result_identifier" : "test_win_05",
*       "msg_batch_send_result_msg" : {
*          "message_client_time" : 1558598923,
*          "message_conv_id" : "test_win_05",
*          "message_conv_type" : 1,
*          "message_custom_int" : 0,
*          "message_custom_str" : "",
*          "message_elem_array" : [
*             {
*                "elem_type" : 0,
*                "text_elem_content" : "this is batch send msgs"
*             }
*          ],
*          "message_is_from_self" : true,
*          "message_is_online_msg" : false,
*          "message_is_peer_read" : false,
*          "message_is_read" : true,
*          "message_priority" : 1,
*          "message_rand" : 673379256,
*          "message_sender" : "test_win_01",
*          "message_seq" : 10274,
*          "message_server_time" : 1558598924,
*          "message_status" : 2
*       }
*    },
*    {
*       "msg_batch_send_result_code" : 0,
*       "msg_batch_send_result_desc" : "",
*       "msg_batch_send_result_identifier" : "test_win_02",
*       "msg_batch_send_result_msg" : {
*          "message_client_time" : 1558598923,
*          "message_conv_id" : "test_win_02",
*          "message_conv_type" : 1,
*          "message_custom_int" : 0,
*          "message_custom_str" : "",
*          "message_elem_array" : [
*             {
*                "elem_type" : 0,
*                "text_elem_content" : "this is batch send msgs"
*             }
*          ],
*          "message_is_from_self" : true,
*          "message_is_online_msg" : false,
*          "message_is_peer_read" : false,
*          "message_is_read" : true,
*          "message_priority" : 1,
*          "message_rand" : 673460408,
*          "message_sender" : "test_win_01",
*          "message_seq" : 10276,
*          "message_server_time" : 1558598924,
*          "message_status" : 2
*       }
*    }
* ]
*
* @example �ӿ�[TIMGroupCreate](TIMCloud.h)�Ļص�TIMCommCallback����json_params��Json��Json Key��ο�[CreateGroupResult](TIMCloudDef.h)��
* {
*    "create_group_result_groupid" : "first group id"
* }
* 
*
* @example �ӿ�[TIMGroupInviteMember](TIMCloud.h)�Ļص�TIMCommCallback����json_params��Json��Json Key��ο�[GroupInviteMemberResult](TIMCloudDef.h)
* [
*    {
*       "group_invite_member_result_identifier" : "user2",
*       "group_invite_member_result_result" : 1
*    },
*    {
*       "group_invite_member_result_identifier" : "user3",
*       "group_invite_member_result_result" : 1
*    }
* ]
* 
* @example �ӿ�[TIMGroupDeleteMember](TIMCloud.h)�Ļص�TIMCommCallback����json_params��Json��Json Key��ο�[GroupDeleteMemberResult](TIMCloudDef.h)
* [
*    {
*       "group_delete_member_result_identifier" : "user2",
*       "group_delete_member_result_result" : 1
*    },
*    {
*       "group_delete_member_result_identifier" : "user3",
*       "group_delete_member_result_result" : 1
*    }
* ]
* 
* @example �ӿ�[TIMGroupGetJoinedGroupList](TIMCloud.h)�Ļص�TIMCommCallback����json_params��Json��Json Key��ο�[GroupBaseInfo](TIMCloudDef.h)
* [
*    {
*       "group_base_info_face_url" : "group face url",
*       "group_base_info_group_id" : "first group id",
*       "group_base_info_group_name" : "first group name",
*       "group_base_info_group_type" : "Public",
*       "group_base_info_info_seq" : 7,
*       "group_base_info_is_shutup_all" : false,
*       "group_base_info_lastest_seq" : 0,
*       "group_base_info_msg_flag" : 0,
*       "group_base_info_readed_seq" : 0,
*       "group_base_info_self_info" : {
*          "group_self_info_join_time" : 1551344977,
*          "group_self_info_msg_flag" : 0,
*          "group_self_info_role" : 400,
*          "group_self_info_unread_num" : 0
*       }
*    }
* ]
*
* @example �ӿ�[TIMGroupGetGroupInfoList](TIMCloud.h)�Ļص�TIMCommCallback����json_params��Json��Json Key��ο�[GetGroupInfoResult](TIMCloudDef.h)
* [
*    {
*       "get_groups_info_result_code" : 0,
*       "get_groups_info_result_desc" : "",
*       "get_groups_info_result_info" : {
*          "group_detial_info_add_option" : 2,
*          "group_detial_info_create_time" : 1551344977,
*          "group_detial_info_custom_info" : {},
*          "group_detial_info_face_url" : "group face url",
*          "group_detial_info_group_id" : "first group id",
*          "group_detial_info_group_name" : "first group name",
*          "group_detial_info_group_type" : "Public",
*          "group_detial_info_info_seq" : 7,
*          "group_detial_info_introduction" : "group introduction",
*          "group_detial_info_is_shutup_all" : false,
*          "group_detial_info_last_info_time" : 1551344977,
*          "group_detial_info_last_msg_time" : 0,
*          "group_detial_info_max_member_num" : 2000,
*          "group_detial_info_member_num" : 1,
*          "group_detial_info_next_msg_seq" : 0,
*          "group_detial_info_notification" : "group notification",
*          "group_detial_info_online_member_num" : 0,
*          "group_detial_info_owener_identifier" : "user1",
*          "group_detial_info_searchable" : 2,
*          "group_detial_info_visible" : 2
*       }
*    }
* ]
*
* @example �ӿ�[TIMGroupGetMemberInfoList](TIMCloud.h)�Ļص�TIMCommCallback����json_params��Json��Json Key��ο�[GroupGetMemberInfoListResult](TIMCloudDef.h)
* {
*    "group_get_memeber_info_list_result_info_array" : [
*       {
*          "group_member_info_custom_info" : {},
*          "group_member_info_identifier" : "user1",
*          "group_member_info_join_time" : 1551344977,
*          "group_member_info_member_role" : 400,
*          "group_member_info_msg_flag" : 0,
*          "group_member_info_msg_seq" : 0,
*          "group_member_info_name_card" : "",
*          "group_member_info_shutup_time" : 0
*       }
*    ],
*    "group_get_memeber_info_list_result_next_seq" : 0
* }
* 
* @example �ӿ�[TIMGroupGetPendencyList](TIMCloud.h)�Ļص�TIMCommCallback����json_params��Json��Json Key��ο�[GroupPendencyResult](TIMCloudDef.h) 
* {
*    "group_pendency_result_next_start_time" : 0,
*    "group_pendency_result_pendency_array" : [
*       {
*          "group_pendency_add_time" : 1551414487947,
*          "group_pendency_apply_invite_msg" : "Want Join Group, Thank you",
*          "group_pendency_approval_msg" : "",
*          "group_pendency_form_identifier" : "user2",
*          "group_pendency_form_user_defined_data" : "",
*          "group_pendency_group_id" : "four group id",
*          "group_pendency_handle_result" : 0,
*          "group_pendency_handled" : 0,
*          "group_pendency_pendency_type" : 0,
*          "group_pendency_to_identifier" : "user1",
*          "group_pendency_to_user_defined_data" : ""
*       }
*    ],
*    "group_pendency_result_read_time_seq" : 0,
*    "group_pendency_result_unread_num" : 1
* }
*
* @note ���½ӿڵĻص�TIMCommCallback����json_params��Ϊ���ַ���""
* > [TIMLogin](TIMCloud.h) 
* > [TIMLogout](TIMCloud.h)
* > [TIMMsgSaveMsg](TIMCloud.h)
* > [TIMMsgReportReaded](TIMCloud.h)
* > [TIMMsgRevoke](TIMCloud.h)
* > [TIMMsgImportMsgList](TIMCloud.h)
* > [TIMMsgDelete](TIMCloud.h)
* > [TIMConvDelete](TIMCloud.h)
* > [TIMGroupDelete](TIMCloud.h)
* > [TIMGroupJoin](TIMCloud.h)
* > [TIMGroupQuit](TIMCloud.h)
* > [TIMGroupModifyGroupInfo](TIMCloud.h)
* > [TIMGroupModifyMemberInfo](TIMCloud.h)
* > [TIMGroupReportPendencyReaded](TIMCloud.h)
* > [TIMGroupHandlePendency](TIMCloud.h)
*
**/
/// @}


#ifdef __cplusplus
};
#endif //__cplusplus

#endif //SDK_CLOUD_TIM_CALLBACK_HEADER_
