//jmqmen.c

inherit ROOM;

void create()
{
	set("short", "��ľ�����");
	set("long", @LONG
���������̾�ľ��Ĵ��ţ�ׯ�Ϲ��ӣ���ǰ�Բ�����������
���졣���̵Ĵ��ų����ţ��ƺ��������к����������������ȥ��
ֻ��һƬ�Դ�����֡�
LONG );
	set("exits", ([
		"enter"  : __DIR__"jmqshulin1",
		"west"   : __DIR__"tojmq3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
