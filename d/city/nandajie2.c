// Room: /city/nandajie2.c
// YZC 1995/12/04 
// CLEANSWORD 1996/2/2

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
������һ�������Ľֵ��ϣ����ϱ���ͷ���졣�ϱ����ϳ��ţ�����ͨ����
���ģ�������һ�ҹ˿��ڶ�Ĳ�ݣ����̾�����ʿ��������̸��˵�ء�����һ
�������¥������������Ц���Ǿ�����������������Ժ��
LONG );
        set("outdoors", "city");
//	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"lichunyuan",
		"south" : __DIR__"nanmen",
		"west"  : __DIR__"chaguan",
		"north" : __DIR__"nandajie1",
	]));
        set("objects", ([
                CLASS_D("shaolin") + "/tuoboseng" : 1,
//
        ]));
	setup();
}

/*
int valid_leave(object me, string dir)
{
	if (dir == "east" && (int)me->query("age") < 18 && !wizardp(me))
		return notify_fail("С���Ѳ�Ҫ�����ֵط�ȥ����\n");
	return 1;
}
*/
