// Room: /d/suzhou/road5.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������
������ҴҶ���������������ݳ��ˡ����ϱ�ԶԶ��ȥ������
�������׷���׺����������������̫���ˡ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"nanmen",
//              "southwest" : "/d/yanziwu/hupan",
                "southwest" : "/d/murong/hubian",
	]));
	setup();
	replace_program(ROOM);
}

