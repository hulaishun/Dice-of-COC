#pragma once

#include "cqdefine.h"
//#include "CQLogger.h"
//#include "CQEVE_ALL.h"

#include <string>
#include <map>
#include <vector>

class Unpack;
namespace CQ {
	//����������־ 
	int addLog(int Priority, const char *Type, const char *Content);

	//���ͺ�����Ϣ
	//Auth=106 ʧ�ܷ��ظ�ֵ,�ɹ�������ϢID 
	int sendPrivateMsg(long long QQ, const char *msg);
	//���ͺ�����Ϣ
	//Auth=106 ʧ�ܷ��ظ�ֵ,�ɹ�������ϢID 
	int sendPrivateMsg(long long QQ, std::string&msg);

	//����Ⱥ��Ϣ 
	//Auth=101 ʧ�ܷ��ظ�ֵ,�ɹ�������ϢID
	int sendGroupMsg(long long GroupID, const char *msg);
	//����Ⱥ��Ϣ 
	//Auth=101 ʧ�ܷ��ظ�ֵ,�ɹ�������ϢID
	int sendGroupMsg(long long GroupID, std::string&msg);


	//������������Ϣ 
	//Auth=103 ʧ�ܷ��ظ�ֵ,�ɹ�������ϢID
	int sendDiscussMsg(long long DiscussGroupID, const char *msg);
	//������������Ϣ 
	//Auth=103 ʧ�ܷ��ظ�ֵ,�ɹ�������ϢID
	int sendDiscussMsg(long long DiscussGroupID, std::string&msg);

	//������ Auth=110
	int sendLike(long long QQID, int times);

	//ȡCookies (���ã��˽ӿ���Ҫ�ϸ���Ȩ) 
	//Auth=20 ����,�˽ӿ���Ҫ�ϸ���Ȩ 
	const char *getCookies();

	//�������� 
	const char *getRecord(
		const char *file, // �յ���Ϣ�е������ļ��� (file) 
		const char *outformat // Ӧ������ĸ�ʽ mp3,amr,wma,m4a,spx,ogg,wav,flac
	);
	//�������� 
	std::string getRecord(
		std::string&file, // �յ���Ϣ�е������ļ��� (file) 
		std::string outformat // Ӧ������ĸ�ʽ mp3,amr,wma,m4a,spx,ogg,wav,flac
	);

	//ȡCsrfToken (���ã��˽ӿ���Ҫ�ϸ���Ȩ) 
	//Auth=20 ��QQ��ҳ�õ���bkn/g_tk�� ����,�˽ӿ���Ҫ�ϸ���Ȩ 
	int getCsrfToken();

	//ȡӦ��Ŀ¼ 
	//���ص�·��ĩβ��"\" 
	const char *getAppDirectory();

	//ȡ��¼QQ 
	//ȡ��¼QQ 
	long long getLoginQQ();

	//ȡ��¼�ǳ� 
	const char *getLoginNick();

	//��ȺԱ�Ƴ� Auth=120 
	int setGroupKick(
		long long GroupID, long long QQID,
		CQBOOL Refuse_Request_Forever = false // ���Ϊ�棬�򡰲��ٽ��մ��˼�Ⱥ���롱�������� 
	);

	//��ȺԱ���� Auth=121 
	int setGroupBan(
		long long GroupID, long long QQID,
		long long BanTime = 60 // ���Ե�ʱ�䣬��λΪ�롣���Ҫ�����������д0 
	);

	//��Ⱥ����Ա Auth=122 
	int setGroupAdmin(
		long long GroupID, long long QQID,
		CQBOOL Administrator = true // ��/���ù���Ա ��/ȡ������Ա 
	);

	//��Ⱥ��Աר��ͷ�� Auth=128 ��Ⱥ��Ȩ�� 
	int setGroupSpecialTitle(
		long long GroupID, long long QQID,
		const char *Rank, // ���Ҫɾ����������� 
		long long = -1 // ר��ͷ����Ч�ڣ���λΪ�롣���������Ч��������д-1
	);
	//��Ⱥ��Աר��ͷ�� Auth=128 ��Ⱥ��Ȩ�� 
	int setGroupSpecialTitle(
		long long GroupID, long long QQID,
		std::string&Rank, // ���Ҫɾ����������� 
		long long ExpireTime = -1 // ר��ͷ����Ч�ڣ���λΪ�롣���������Ч��������д-1
	);

	//��ȫȺ���� Auth=123 
	int setGroupWholeBan(
		long long GroupID,
		CQBOOL WholeBan = true // ��/���� ��/�ر� 
	);

	//������ȺԱ���� Auth=124 
	int setGroupAnonymousBan(
		long long GroupID,
		const char *Anonymous, // Ⱥ��Ϣ�¼��յ��ġ����������� 
		long long BanTime = 60 // ���Ե�ʱ�䣬��λΪ�롣��֧�ֽ�� 
	);

	//��Ⱥ�������� Auth=125 
	int setGroupAnonymous(long long GroupID, CQBOOL �������� = true);

	//��Ⱥ��Ա��Ƭ Auth=126 
	int setGroupCard(long long GroupID, long long QQID, const char *NewGroupNickname);

	//��Ⱥ��Ա��Ƭ Auth=126 
	int setGroupCard(long long GroupID, long long QQID, std::string NewGroupNickname);

	//��Ⱥ�˳� Auth=127 ����,�˽ӿ���Ҫ�ϸ���Ȩ 
	int setGroupLeave(
		long long GroupID,
		CQBOOL Dismiss = false // ��/��ɢ��Ⱥ (Ⱥ��) ��/�˳���Ⱥ (������Ⱥ��Ա) 
	);

	//���������˳� Auth=140 
	int setDiscussLeave(
		long long DiscussGroupID
	);

	//�ú����������� Auth=150 
	int setFriendAddRequest(
		const char *ResponseFlag, // �����¼��յ��ġ�������ʶ������ 
		int ResponseType, // #����_ͨ�� �� #����_�ܾ� 
		const char *Remark // ���Ӻ�ĺ��ѱ�ע 
	);

	//��Ⱥ�������� Auth=151 
	int setGroupAddRequest(
		const char *ResponseFlag, // �����¼��յ��ġ�������ʶ������ 
		int RequestType, // ���������¼������������� #����_Ⱥ���� �� #����_Ⱥ���� 
		int ResponseType, // #����_ͨ�� �� #����_�ܾ� 
		const char *Reason // �������ɣ��� #����_Ⱥ���� �� #����_�ܾ� ʱ����
	);

	//������������ʾ,��ʱ��֪����ʲô�õ�
	int setFatal(const char *ErrMsg);


	class GroupMemberInfo;
	//ȡȺ��Ա��Ϣ (֧�ֻ���) Auth=130 
	GroupMemberInfo getGroupMemberInfo(long long GroupID, long long QQID, CQBOOL DisableCache = false);

	class StrangerInfo;
	//ȡİ������Ϣ (֧�ֻ���) Auth=131 
	StrangerInfo getStrangerInfo(long long QQID, CQBOOL DisableCache = false);

	//ȡȺ��Ա�б� Auth=160  
	std::vector<GroupMemberInfo> getGroupMemberList(long long GroupID);

	//ȡȺ�б� Auth=161  
	std::map<long long, std::string> getGroupList();

	//������Ϣ Auth=180
	int deleteMsg(long long MsgId);

	const char * getlasterrmsg();

	// Ⱥ��Ա��Ϣ
	class GroupMemberInfo
	{
		void Void();
		void setdata(Unpack&pack);
	public:
		long long GroupID;
		long long QQID;
		std::string Nickname;
		std::string GroupNickname;
		int Gender; // 0/���� 1/Ů��
		int Age;
		std::string Region;
		int AddtoGroupTime;
		int LastMsgTime;
		std::string GradeName;
		int permissions; //1/��Ա 2/����Ա 3/Ⱥ��
		std::string UniqueRank;
		int UniqueRankExpireTime; // -1 ����������
		CQBOOL BadRecordMember;
		CQBOOL AbleToModifyGroupNick;

		GroupMemberInfo(Unpack& msg);
		GroupMemberInfo(const char* msg);//��API����
		GroupMemberInfo(std::vector<unsigned char> msg);//��Unpack����
		GroupMemberInfo() = default;

		std::string tostring() const;
	};

	// İ������Ϣ
	class StrangerInfo
	{
	public:
		long long QQID;
		std::string nick;//�ǳ�
		int sex;//0/���� 1/Ů�� 255/δ֪
		int age;//����

		StrangerInfo(const char* msg);
		StrangerInfo() = default;

		std::string tostring() const;
	};
}