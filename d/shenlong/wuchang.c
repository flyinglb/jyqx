// wuchang.c
inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
����һ���������䳡���м�����ִ�̽���������Ů������������
�Ա�վ�ż���,������Ů,��������ʮ����,�ϵ���������ʮ��,����
ȴ��������.������һ������.
LONG );
	set("exits", ([
		"north" : __DIR__"zoulang",
	]));
	set("objects", ([
                "/d/shaolin/npc/mu-ren": 5,
	]));
        setup();
	replace_program(ROOM);
}

