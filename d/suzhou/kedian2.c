// Room: /d/suzhou/kedian2.c
// Date: May,31 1998 Java

inherit ROOM;

void create()
{
	set("short", "�͵��¥");
	set("long", @LONG
�������ڿ͵��¥�������ϣ����������ӿͷ��ﲻʱ�غ�
���Ĵ�����һ��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ���������
��¥�µ��ƹ񴦸���Ǯ������˯����
LONG );
	set("exits", ([
		"down"  : __DIR__"kedian",
		"enter" : __DIR__"kedian3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

