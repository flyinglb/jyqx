// Room: /d/fuzhou/fzroad3.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "����ŵ�");
	set("long", @LONG
�Թ������޳�;����������ȫ��������������������������
��ͨ���ŵ��ųơ���ǧ�˰ٿ�����������ߣ���ʯ���ͣ�����ͷ
����̡��µ����ף�������ƽ�����ˡ�
LONG );
	set("exits", ([
		"northdown" : __DIR__"fzroad2",
		"southdown" : __DIR__"yanping",
	]));
        set("objects", ([
		"/d/taishan/npc/tiao-fu" : 2,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

