//LHQPAIFANG.C

inherit ROOM;

void create()
{
//    set("short", "��ʯ��");
    set("short", "�һ����Ʒ�");
	set("long", @LONG
����������ɽ��´��һƬ�����أ�����ɽ�»�������ľ���죬����
·�е���һ������Ʒ��������Ʒ�����һƬ��ש���ߣ���������
���죬·������վ�����Ž��ڣ�����ɽ���к����������ڣ������
Ұ��ʵ���ǽ�����һ��������û�е�׳�۾����ɴ��򶫱���ת��
��·ֱͨ����죻�ɴ����������У���Ϊ��ľ�졣��������Ƕ���
֮�ƣ��Թ���������Χ��
LONG );
	set("exits", ([
		"northeast" : __DIR__"torjq1",
		"northwest" :__DIR__"tojmq1",
		"northup"   : __DIR__"lhqmen",
		"southdown" : __DIR__"shanlu4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
