//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
�����Ǻ�̫��ͷ��˰���浵����ң�����Ҳ�ڷ��˲����ʻ��������Ժͺ�
��԰�е��ʻ����ͬ�����������ԭ���Լ�����ĵ�����ջ�����ҩ��ˮ��
֮�ࡣ���ŷ���վ�ڴ�ǰ������԰�е������ʻ�������
LONG );
	set("exits", ([
		"south" :  __DIR__"houhuayuan",
	]));
	set("objects", ([
		__DIR__"npc/binv" : 2,
		__DIR__"npc/banshuxian" :1,
	]));
	setup();
	replace_program(ROOM);
}
