// Room: /guiyun/yixing.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������������������ն�����ɽ��ˮ֮����ӳ��һ�Ѷ���ɰ������
����һ����ɫ�����У���Զ������̫���ߡ��Ϸ����Ǻ��ݸ��ˡ�
LONG );
        set("outdoors", "guiyun");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"tiandi",
		"south"     : __DIR__"nanxun",
		"northwest" : "/d/wudang/wdroad2",
	]));
	setup();
	replace_program(ROOM);
}
