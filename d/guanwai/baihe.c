// /guanwai/baihe.c

inherit ROOM;

void create()
{
	set("short", "�׺�");
	set("long", @LONG
�����ǳ���ɽ�µ�һ��С�壬ֻ���ģ�����ª��Сľ�ݡ����ﲢû��
�̶��ľ���ľ�ݶ��ǽ�ɽ�ɲεĲο����ǣ�Ϊ�����ڽ�ɽǰ��������ú�
����Ϣһ�¡��������Ρ�������ĳ��״�ɽ��
LONG );
	set("exits", ([
		"west"  : __DIR__"caoguduo",
		"east"  : __DIR__"milin1",
		"north" : __DIR__"xiaowu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
