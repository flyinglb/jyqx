// Room: /lingzhou/baxian.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "���ɵ���");
	set("long", @LONG
�����ǰ��ɵ��ۣ����а��ɵ�����Ź��ϡ�������������Ȱ�
�ɵ������㰸���������ơ���ǽ���ż���̫ʦ�Σ����Ϸ��ż������š�
�������������ȣ������Ƕ���� �ϱ��Ǻ�Ժ,����Щ�������ϻ�����
�ǵ�ʿ����Ϣ�ĵط�����Ժ����һ�ھ�����������ȥ�е�������
LONG );
	set("exits", ([
		"west" : __DIR__"xiaolu2",
	]));
	set("objects", ([
		__DIR__"npc/laodaoshi" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

