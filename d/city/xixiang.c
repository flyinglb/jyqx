// Room: /city/xixiang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���ǲ���С��Ĺ뷿��һ���������������һ����齷���ǽ�ǣ�����ϸɴ��
С����������ϣ��������һ��˼��ģ����������ͻȻ�������������ˡ�
LONG );
	set("exits", ([
		"east" : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/yingying" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

