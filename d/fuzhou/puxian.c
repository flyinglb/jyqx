// Room: /d/fuzhou/puxian.c
// Date: May 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "����ƽԭ");
	set("long", @LONG
����������ƽԭ�ϡ�����������ģ����̳��ܣ�������
�Ǹ��ݸ����ˡ����Ͼͽ������ϡ�
LONG );
	set("exits", ([
		"north" : __DIR__"zhongzhou",
                "south" : "/d/quanzhou/beimen",
	]));
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

