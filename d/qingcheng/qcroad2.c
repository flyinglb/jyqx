// Room: /qingcheng/qcroad2.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "����С��");
	set("long", @LONG
����������С���ϡ���߲�Զ��������ˮ�죬ԭ�����������
��֪�������ߡ����ӷ�����ʹẽ�֮ˮ��ע������ССϪ���У���
���������ˮ������ȳ����⸻�ĵĳɶ�ƽԭ��
LONG );
        set("outdoors","qingcheng");
	set("exits", ([
		"north" : __DIR__"qcroad3",
		"east"  : __DIR__"qcroad1",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

