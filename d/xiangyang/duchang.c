// Room: /d/xiangyang/duchang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ĳ�");
	set("long", @LONG
���ﱾ���������Ķĳ������Ǵ�ս��ǰ��Ϊ���ؾ�����
��ҡ�����Ͱܻ�����������������ر��˶ĳ����ſ���ȸ�Ĵ�
Ժ����������ʱ�Ĺ�ģ�������ưܵĶľߣ�Ҳ��֪��������
����˵ʲô��
LONG );
	set("no_clean_up", 0);

	set("exits", ([
		"east" : __DIR__"southjie2",
	]));
	setup();
	replace_program(ROOM);
}
