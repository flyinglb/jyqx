
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
		"north" : __DIR__"andao5",
		"south" : __DIR__"andao8",		
		"west"  : __DIR__"andao4",
		"east"  : __DIR__"andao7",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

