// Room: /d/fuzhou/fzroad1.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "إ����");
	set("long", @LONG
إ���̸߾���ϼ���ϣ�����Ⱥɽ���࣬������ڣ�ʮ��ˬ����
�����Ǹ���С��С���䣬��Ȼ���������Ŀ��̷��࣬����Ҳֻ��
һ��СС�͵ꡣ
LONG );
	set("exits", ([
		"north"     : __DIR__"fzroad1",
		"southdown" : __DIR__"fzroad2",
		"west"      : __DIR__"kedian",
	]));
        set("objects", ([
		"/d/huashan/npc/haoke" : 2,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

