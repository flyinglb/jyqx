// /guanwai/tuyaoguan.c

inherit ROOM;

void create()
{
	set("short", "��Ҥ��");
	set("long", @LONG
һ�������С����һ��֬�ۻ���Ŵ����ζ���˱Ƕ�����������Ǻ��
һ����ͷ�����ڵ��źܶ�����͵��������ı��յ�ͨ�졣�ܶഩ�����õĺ�
�ӣ�һ��§�Ź��һ�����žƺ������ڸ�̸���ۡ�һ�����ֵ���ѻһ����
���ſ��ˣ�һ������ߴٵ�����İ鵱�͹����ǡ�
LONG );
	set("exits", ([
		"north" : __DIR__"dongcheng",
	]));
	set("objects", ([
		__DIR__"npc/jiaowenqi" : 1,
	]));
//	set("no_clean_up", 0);
//	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}

