//tan1.c

inherit ROOM;

void create()
{
	set("short", "�����Ϻ� ");
	set("long",
	     "�����Ǽ����Ϻ�ˮ�� �����ܵ����Ƚ���������������ͷ����̶ˮ��Ͷ��������\n"
	     "�Ե�ʮ���������������һƬҲ��֪��Щʲô���㲻�ɶ��Լ�˵......\n"

	);
	set("exits", ([
		"up" : "/d/quanzhou/nanhu",
		"down" : __DIR__"tan2",
	]));
	setup();
	replace_program(ROOM);
}
