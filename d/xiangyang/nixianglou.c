// Room: /d/xiangyang/nixianglou.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
��������û�в�֪��������¥���ġ����ǿ�սʱ�ڣ�����
����ȴ�࣬����̸��Ҳ�������ⷴ����¡��¥�²��ü��ף���
�Ͷ��ǴҴҵ����ˣ������ӡ����ȡ��׾ƾ͸�·ȥ�ˡ�¥��
����������ս�ڼ䣬���н�Լ������ӻ�����ûɶ���⣬ֻ��
���ˡ�
LONG );
	set("exits", ([
		"west" : __DIR__"southjie2",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
	setup();
	replace_program(ROOM);
}

