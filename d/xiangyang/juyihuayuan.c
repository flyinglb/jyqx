// Room: /d/xiangyang/juyihuayuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
���Ǿ���ݵĴ�԰��԰�����Ÿ��ָ����Ļ��ݣ���紵
���������ŵ��ɹɻ��㡣԰�ڶ����������һ���᷿��������
һ����ˮ��ˮ�ϼ������ȣ�ֱͨ����֡������ǹ��ڳ�������
�Ϸ�����һ����Ʒ����
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east"      : __DIR__"juyifemale",
		"west"      : __DIR__"juyimale",
		"south"     : __DIR__"juyichufang",
		"north"     : __DIR__"juyilang",
		"southeast" : __DIR__"juyiwupin",
	]));
	set("objects", ([
		__DIR__"npc/guofu" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (me->query("gender") != "����" && dir == "west") 
		return notify_fail("��Ů�б��뵽����ס��\n");

	if (me->query("gender") != "Ů��" && dir == "east") 
		return notify_fail("��Ů�б��뵽����ס��\n");

	return ::valid_leave(me, dir);
}
