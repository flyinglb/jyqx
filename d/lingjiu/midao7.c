
inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
���������ţ�ͻȻ��������ʧ�˷����������ߵ�ʱ��ȴ�������Ѳ�
�������ĵ�·�ˣ��㲻������һ���顣ͻȻ���ڻ�Ƶĵƹ��£���Լ��
�����ߵĺ�����ǽ���Ͽ���һЩ���ι�״�ķ���(fuhao)��
LONG );
	set("exits", ([
		"south" : __DIR__"midao13",
		"north" : __DIR__"midao8",
		"east" : __DIR__"midao13",
		"west" : __DIR__"midao14",
	]));
	set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}
