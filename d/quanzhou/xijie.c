// Room: /d/quanzhou/xijie.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������Ȫ�ݵ�����֣�������һ���ưܵ�լ�ӡ�������һ���ӻ��̣�
ר��Ů�˼��õĶ��������˲����Խ�ȥ��
LONG );

	set("exits", ([
                "east" : __DIR__"zhongxin",
                "north" : __DIR__"laozhai",
                "west" : __DIR__"zahuopu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "west" && ((string)me->query("gender") =="����") && !wizardp(me))
                return notify_fail("�������ү�Ƕ�ȥ�Ǹ����\n");
        return 1;
}


