//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","������");
	set("long", @LONG
���еĹ����Ѿ����ᵽ���پ��ˣ�����������λ�����Ų����������ɣ���
Ȼ��ôֻ��������ȴ�������ס����������ٰ���Ҳ�����˳����������Ϸ���һ
�����ס�
LONG );
	set("exits", ([
		"west"  : __DIR__"sanshengju",
	]));
	set("objects", ([
		__DIR__"obj/qinpu" : 1,
	]));
	setup();
	replace_program(ROOM);
}
