// Room: /d/xiakedao/xkroad4.c
// Modified by Java on Feb.14.1998
inherit ROOM;

void create()
{
	set("short", "�Ϻ����");
	set("long", @LONG
�����Ϻ��ذ���ƫƧС�壬ϡϡ����ļ����˼ҡ��յ������ż�
��������������ǲ��κ����Ϻ��ˡ������ߺ����и���ۡ�����
��С���ɳ̲ɹ������
LONG );
        set("outdoors", "xiakedao");
	set("exits", ([
		"north"   : __DIR__"xkroad3",
		"east"    : __DIR__"xkroad5",
		"west"    : __DIR__"haigang",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

