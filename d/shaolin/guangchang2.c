// Room: /d/shaolin/guangchang2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
�����������������ƽ�е���ʯ̨������ǰ����һ�����
����̨���Ͽ̵��������ڷ�����޺��Լ���ǧ٤����������
��ƽ̨�����з�Ҳ�и�����ߵĴ���¯����¯ǰ����̨�ϣ�����
���գ�����Ʈ�ƣ���λ������Դ����ߵ�ݡ����Ҹ�ͨ��һ��
СԺ����������������ʡ���ǰ�����Ǵ��۱��
LONG );
	set("exits", ([
		"south" : __DIR__"twdian",
		"north" : __DIR__"guangchang3",
		"northup" : __DIR__"dxbdian",
		"east" : __DIR__"zhonglou",
		"west" : __DIR__"gulou",
	]));
	set("outdoors", "shaolin");
	set("objects",([
		__DIR__"npc/xiang-ke" : 1,
		__DIR__"npc/seng-bing3" : 2,
		CLASS_D("shaolin") + "/qing-shan" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

