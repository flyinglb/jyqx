// damen.c
// by shilling 97.2

inherit ROOM;

void create()
{
        set("short", "ʯ�Ҵ���");
        set("long", @LONG
�����Ҷ���ͻȻ֮�䣬������һ���������Բ�ԭ���Ǹ��Ż����Ż�
�ĺ�������һ��ͭ�����ɵĴ��ţ�ʮ�ֳ��ء���ʹ�Ǳ����ܺõ��ˣ�����Ҳ
������Ϊ������
LONG );
	set("exits", ([
		"north" : __DIR__"shidong",
		"south" : __DIR__"yandong",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
