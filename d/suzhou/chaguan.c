// Room: /d/suzhou/chaguan.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű�����һ��
�ſ��������˿��ˣ������̸Ц����ͷ�Ӷ�������������һ���ź��ſ���
�ǣ���̨������һλ�ϰ�����ڵ������̡�
LONG );
	set("resource/water", 1);
//	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : __DIR__"nandajie1",
	]));
	set("objects", ([
		__DIR__"npc/lady2" : 1,
	]));
	setup();
	replace_program(ROOM);
}

