// Room: /guiyun/huayuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
����һ�����͵Ľ���԰�֣���ģ�䲻�󣬹����ȴ��Ϊ���£�
��ص��꽨԰֮�˺ܷ���һ��������԰�л���Ϯ�ˣ�ݺ�����裬��
����磬�̲�������ֻ����Ƭ�̱��������崺�磬����������
LONG );
        set("outdoors", "guiyun");
//	set("no_clean_up", 0);

	set("exits", ([
		"north" : __DIR__"chufang",
		"south" : __DIR__"huating",
		"east"  : __DIR__"liangong",
	]));
	set("objects", ([
		__DIR__"npc/xiaoju" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "�һ���") && (dir == "east") ) 
		return notify_fail("����ׯ������ͣ��㲻���������ߣ�\n");

	return ::valid_leave(me, dir);
}
