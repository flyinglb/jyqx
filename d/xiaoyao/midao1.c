// midao1.c
// by shilling 97.2

inherit ROOM;

void create()
{
	set("short", "����ͨ��");
	set("long", @LONG
����һ���ֳ��ֺڵ�����ͨ������Լ���Ըо��������Ǳ������Ӳ��ʯ
�ڣ���ʲô�˿��������ֻ���Կ�������ǰ����
LONG );
	set("exits", ([
		"out" : __DIR__"shishi3",
		"north" : __DIR__"midao2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
