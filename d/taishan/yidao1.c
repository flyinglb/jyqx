// Room: /d/shaolin/yidao1.c
// Date: YZC 96/01/19

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ�
���̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·���������ϵ���
�������ž�װ���¼��������еĻ���������ŵ�������������Щ
Щϰ��Ľ����ˡ���·��������������������֡�
LONG );
	set("exits", ([
		"west" : __DIR__"yidao",
		"northeast" : __DIR__"yidao2",
                "southeast" : "/d/quanzhou/qzroad1",
	]));
	set("objects",([
		__DIR__"npc/tangzi" : 2,
                "/d/quanzhou/npc/hai" : 1,
                "/d/city/npc/xiaoguiz" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

