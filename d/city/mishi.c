// Room: /d/snow/herbshop1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��������������ң��ӵ��Ϻ��Ļҳ����ó������������
�˳��룬�����ߵĵ��Ϸ���һ�����ͣ�����һ����������ǽ�ϣ���֪��
��������ʲ���ˣ������ǽ(wall)���ú�ɼľ���ģ�����������Ļ���
ǽ�������Ե���Щ��Ѱ����
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"chuchang",
	]));

	set("objects", ([
		CLASS_D("gaibang") + "/hong" : 1,
	]));
	setup();
	replace_program(ROOM);
}
