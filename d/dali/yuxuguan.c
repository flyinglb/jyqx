//Room: /d/dali/yuxuguan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�����");
	set("long",@LONG
�������ʮ����죬���й����Ź��ϡ�������������õȰ��ɵ�
����������ƣ������ϰ���Щ��ҡ����з��˼������š��Ա�һ��
С����������Σ�������ɢ����Ϣ����ͽ�ĵط���
LONG);
	set("objects", ([
	   CLASS_D("dali")+"/daobaifeng": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"yuxuguanqian",
	]));
	setup();
	replace_program(ROOM);
}

