// Room: /d/suzhou/wanjing.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��ɽׯ");
	set("long", @LONG
�ڻ���ɽ���������ɽׯ����һ���ϴ���辰԰������
��Ϊ���غ����ϡ���Բ�أ�������������꣬����Ϊ���辰֮
�����������辰Ϊ������ϼε������ʯ�辰����һ���İٶ���
��ȸ÷��׮�辰�������辰�������е���Ʒ��Բ�ھ�ɫ������
�ĸ�԰����Ȥ��
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"eastup" : __DIR__"shijianshi",
		"east"   : __DIR__"toumenshan",
		"westup" : __DIR__"hanhanquan",
	]));
        set("objects", ([
		"/d/taishan/npc/dao-ke" : 1,
	]));
	setup();
	replace_program(ROOM);
}

