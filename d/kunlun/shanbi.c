//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɽ��");
	set("long", @LONG
һ�������޷��ʵǵı�ѩɽ·ͨ�������������������һ��Ҳ������
û�п��ܵ��ˡ�����ֵ��������ѩ���ǵĽ�����ֱ��ɽ���Ͼ�Ȼ����һЩϸ
С�Ĳݱ�ֲ���Ҳ��֪����Щ��֪���Ĳ�������û�б���֥���м�ֵ�Ķ���
�ˡ�
LONG );
	set("exits", ([
		"westdown" : __DIR__"baixiang",
	]));
	set("objects", ([
		__DIR__"obj/lingzhi" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}
