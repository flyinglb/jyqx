// midao2.c
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
		"south" : __DIR__"midao1",
		"north" : __DIR__"midao3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
