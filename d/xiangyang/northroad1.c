// Room: /d/xiangyang/northroad1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���ڴ��");
	set("long", @LONG
����һ������ʯ�̾͵Ĵ����ֻ��������һ������ܴ��
�ӻ��̣���˵����������ණ�����򶫾��Ƕ��ֽֿڣ�����
Ҳ��һ����ֿڣ�����󿴵�һ�����ͨ�����档������һ��
�ϸǺ�ɫ�����ߵĸ�ǽ����������������ʹ���ĵ°��Ÿ�����
���¿��䡢�˳ƹ����������ĸ�ۡ��
LONG );
        set("outdoors", "xiangyang");

	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"jiekou1",
		"east"  : __DIR__"dingzi",
		"north" : __DIR__"xinluofang",
	]));
	setup();
	replace_program(ROOM);
}

