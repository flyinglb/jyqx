// Room: /d/xiangyang/mujiang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ľ����");
	set("long", @LONG
����һ�Ҽ�ª��ľ���̣�һ������ľ�������ڵ��϶�������
ֵ��������ľ����Ҳֻ������Щ��ǹ����ʲô�������Һ��ڡ�
���Ϻ�ǽ�����ҵضѷ���һЩľ����ľ����ľ��ʲô�ģ�����
��������ӣ�����һ���ľ�����ߡ�
LONG );
	set("exits", ([
		"north" : __DIR__"eastjie3",
	]));
	set("objects", ([
		__DIR__"npc/mujiang" : 1,
	]));
	setup();
	replace_program(ROOM);
}

