
inherit ROOM;

void create()
{
	set("short", "��ػᰵ��");
	set("long", @LONG
�ص���һƬ��ڣ������ķ���������˷���������ʲôҲ����
����ֻ���ڵص���Ϲ����ײ�������ƺ�����ԼԼ����˵������ֻһ
�����û���ˡ���ʹ����ҡ��ҡͷ���ܻ����⵽���ǲ��ǻþ�����
�����Ѿ���·�ˡ�
LONG );
	set("exits", ([
		"south" : __FILE__,
		"north" : __DIR__"andao5",
		"west" : __FILE__,
		"east" : __DIR__"andao6",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

