// Room: /qingcheng/qcroad2.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
��������ʯ����ϡ�ԶԶ����ϸϸ��ˮ�����ڸ���·��������
�ֵķ����С��������Կ���һ����ɽ�ˣ��ԲԴ�䣬��һ�����崿
���ı���
LONG );
        set("outdoors","qingcheng");
	set("exits", ([
		"south"  : __DIR__"qcroad2",
		"north"  : __DIR__"xiaoqiao",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

