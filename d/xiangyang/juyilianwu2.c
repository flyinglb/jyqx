// Room: /d/xiangyang/juyilianwu2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǿ���������������ĵط����м���������ר������
�����䣬�м����ֱֳ������ڻ�����С����鶯�����紩��
����һ�㣬�㲻���������ۣ�����������ڵ��ϵ������Ͽ���
������
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east" : __DIR__"juyiyuan",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 3,
	]));
	setup();
	replace_program(ROOM);
}

