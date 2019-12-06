// Room: /d/shaolin/guangchang4.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǻ��ǰ�ľ��������㳡��ש�̵أ���Ϊ����Ĳ�̤����
͹��ƽ��ǰ��������¸�ǽ���������㳡�����м䣬�γ�һ��խ
խ�ĳ����Ρ����߿�����С�ţ�һ������������Ʈ�˹���������
�Ǹ����ţ���λɮ���ڴ˰��ء�
LONG );
	set("exits", ([
		"south" : __DIR__"guangchang3",
		"northup" : __DIR__"houdian",
	]));
	set("outdoors", "shaolin");
//	set("no_clean_up", 0);
	set("objects",([
		CLASS_D("shaolin") + "/hui-kong" : 1,
		__DIR__"npc/seng-bing3" : 2,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "������") && dir == "northup" &&
		objectp(present("hui kong", environment(me))))
			return notify_fail("�ۿպȵ����㲻�����ֳ��ҵ��ӣ����ý����\n");
	return ::valid_leave(me, dir);
}

