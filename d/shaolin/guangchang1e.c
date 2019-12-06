// Room: /d/shaolin/guangchang1e.c
// Date: CSWORD 96/02/28

inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
������������ǰ�Ĺ㳡�������㳡�ɴ�����ʯ�̳ɣ���Ϊ
ƽ̹�����������Զ������Щ���𡣴Դ�С�ݴ�ʯ��ķ�϶�г�
�˳������㳡��Χ�������ܵ������֣��Ľ��ϸ����˼���ʯ����
�ּ�����Ϊģ�����������˿�ľ��(mupai)����ǰ����������վ��
����ɮ�ˡ�
LONG );
	set("exits", ([
		"east" : __DIR__"shulin1",
		"southdown" : __DIR__"shijie11",
		"west" : __DIR__"guangchang1",
	]));
	set("item_desc",([
		"mupai"	:   "�����»������֣�Υ��������ɱ���⣡\n",
	]));
	set("outdoors", "shaolin");
	set("objects",([
		CLASS_D("shaolin") + "/qing-wu" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) 
	&& dir == "east" 
	&& me->query_skill("dodge",1) <= 20 
	&& (present("qingwu biqiu", environment(me))))

	return notify_fail("������סȰ��: �����Ǳ��»������֣������н��޳���\n"
		    + RANK_D->query_respect(me) + "�Ṧ���ѣ�����ȿ���ľ�ƣ���Ҫ����ȥ��\n");

	return ::valid_leave(me, dir);
}

