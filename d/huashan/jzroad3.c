// Room: /d/huashan/jzroad3.c

inherit ROOM;
void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
����������ɽ�š�������գ�ɽ��ѹ������ߵĺ�ϼӳ͸������
ɽ�֣���Х�Ĵ�ɽ��θ���ͣ���㲻����Щ���⡣����һ����ɽС
·��
LONG );
	set("exits", ([
		"west"   : __DIR__"jzroad2",
		"eastup" : __DIR__"jzroad4",
	]));
	set("outdoors", "huashan");
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


