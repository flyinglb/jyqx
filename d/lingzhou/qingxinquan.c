// Room: /lingzhou/qingxinquan.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����Ȫ");
	set("long", @LONG
����ɽ�е�һ����Ȫ��λ���ֳ������ɽ���ϣ���Χ�Ǵ��̵�������
������ɽȪˮ��Ȫ�ۻ�����ӿ�����۳�һ��С̶��С̶ˮ���������ɽ
�£��Ա�һ��С·ͨ��ɽ�¡�
LONG );
	set("exits", ([
		"southeast" : __DIR__"kongdi",
		"northdown" : __DIR__"wangling",
	]));
	set("resource/water", 1);
	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

