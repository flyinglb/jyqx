//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɽ��");
	set("long", @LONG
����һƬ��ɽ���������Ͽ��ѳ���ũ��������ɵ�����ʮ�꾭Ӫ���ڼ�
ʮĶ��ɽ����Ҳ���ݹ�ģ�������д��󡢸����������Լ�ʮ�����߲�����ֲ��
�ۼ���
LONG );
	set("exits", ([
		"southup"  : __DIR__"bainiu",
		"east" :  __DIR__"shantian2",
		"west" :  __DIR__"shantian3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}
//���������ص��Ӹ��������ִ�еص�
