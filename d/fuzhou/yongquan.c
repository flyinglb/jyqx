// Room: /d/fuzhou/yongquan.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "ӿȪ��");
	set("long", @LONG
ӿȪ��Ϊ���е�һ���֡�������ΰ�����ư��磬���վ�
�ɣ��ھ�һʱ���¶�ʤ����Դ��������ͱڣ�������ɣ�
�������죬�������ţ�����ǧ�ر��֣������䡢������ī��
�±������壬Զ�������̲��������������������ƽԭһ��
��԰��⾡���۵ס�
LONG );
	set("exits", ([
                "south"    : __DIR__"gushan",
	]));
	set("objects", ([
                "/d/hangzhou/npc/seng" : 1,
	]));
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

