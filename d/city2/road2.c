
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�
���̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·���������ϵ��˸�
�����ž�װ���¼��������еĻ���������ŵ�������������ЩЩϰ
��Ľ����ˡ���·��������������������֡�
LONG );
	set("exits", ([
		"northwest" : __DIR__"road1",
		"southeast" : __DIR__"road3",
	]));
	set("objects",([
		"/d/taishan/npc/tangzi" : 2,
	]));
	set("outdoors", "city2");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}



