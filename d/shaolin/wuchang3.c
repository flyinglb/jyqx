// Room: /d/shaolin/wuchang3.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡�
��ǧ��Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����䳡�м�
�����Ų���ľ�˺ͲݰС����߽��ϻ���������ɳ�ӣ�ʮ����ɮ��
������ϰ���ա������������һ����ɮ����
LONG
	);

	set("exits", ([
		"south" : __DIR__"fzlou",
		"east" : __DIR__"hsyuan1",
		"west" : __DIR__"hsyuan4",
		"north" : __DIR__"guangchang5",
		"northup" : __DIR__"dmyuan",
	]));

	set("outdoors", "shaolin");

	set("objects",([
		CLASS_D("shaolin") + "/dao-cheng" : 1,
                __DIR__"npc/mu-ren" : 4
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if( !me->query("luohan_winner") && !wizardp(me))
	{
		if (dir == "northup")
		{
			return notify_fail("�㼶�𲻹������ܽ����ĦԺ��\n");
		}
	}
	return ::valid_leave(me, dir);
}

