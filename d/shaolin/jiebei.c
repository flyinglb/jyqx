// Room: /d/shaolin/jiebei.c
// Date: YZC 96/01/19

inherit ROOM;

string look_jiebei();

void create()
{
	set("short", "�籮");
	set("long", @LONG
�籮����δ���Ӻõ�����(jiebei)��
LONG
	);

	set("exits", ([
		"east" : __DIR__"shulin14",
		"northup" : __DIR__"qyping",
	]));

	set("outdoors", "shaolin");
	set("item_desc",([
		"stone"		:	(: look_jiebei :),
	]));
	setup();
}


string look_jiebei()
{
	return "�ɴ���ǰ��ͨ��ɽ������·��δ�޺á�\n��ʱ������������\n";
}

