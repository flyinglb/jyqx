//room: tuyuan.c
inherit ROOM;

void create()
{
	set("short","��Է");
	set("long", @LONG
���Ǹ��������Է����ֻ����þ����ض����̲ݵ��ϳԲݡ�
�����Ǻ��ţ����Ϸ�����԰�����洫���������޵ĺ��У�����
��һ����԰��
LONG );
	set("exits",([
		"north" : __DIR__"houmen",
		"east"  : __DIR__"sheyuan",
		"west"  : __DIR__"shoushe",
		"southwest" : __DIR__"zhuyuan",
	]));
	set("outdoors", "baituo");
	set("objects",([
		__DIR__"npc/baitu" : 2,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	me = this_player();
	myfam = (mapping)me->query("family");
	if ((!myfam || (myfam["family_name"] != "����ɽ��")) && (dir == "west"))
		return notify_fail("�㲻�ǰ���ɽ���ӣ����ܽ����ᡣ\n");
	if ((!myfam || (myfam["family_name"] != "����ɽ��")) && (dir == "east"))
		return notify_fail("�㲻�ǰ���ɽ���ӣ����ܽ���԰��\n");
	else  return 1;
}
