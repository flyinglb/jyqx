// shishi1.c
// by shilling 97.2

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ��ʯͷ���ɵķ��䣬��Ϊ�þ�û����������ɢ����һЩ�����ŵ�
��ζ�������е������Կ�����˿�ͳ漣��
LONG );
	set("exits", ([
		"east" : __DIR__"shiji1",
	]));
	set("objects",([
		__DIR__"obj/putuan" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
