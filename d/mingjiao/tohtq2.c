//TOHTQ2.C

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ������ͨ��ɽ·��·�ߵ������ܼ����������㣬�ݴ�
�����ǵ��ص�׺��һЩ��ɫҰ�������н��ͣ����߲�ľïʢ����
�����£���ɫ������
LONG );
	set("exits", ([
		"southwest" :__DIR__"tohtq1",
		"northdown" :__DIR__"tohtq3",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
