// Room: /d/xiangyang/eastroad2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���ڴ��");
	set("long", @LONG
����һ����ʯ�̾͵Ĵ�֡�������һ�¸��ź�ɫ�����ߵ�
��ǽ�������������سǴ�����ĸ�ۡ��Ժ����������������
��Ϊʮ��������Ϊ�����������ֿ��ɹž������Զ�����������
��࣬ǰ���������������ﲻ����������һ��ʮ�ֵֽ���ֻ
�������������ǳ����֣�����������ʯ�̵Ľֵ���
LONG );
        set("outdoors", "xiangyang");

	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"zhonglie",
		"south" : __DIR__"eastroad1",
		"north" : __DIR__"jiekou2",
	]));
	setup();
	replace_program(ROOM);
}

