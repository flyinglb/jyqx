// tyroad10.c ��԰С·
// by Marz 

inherit ROOM;

void create()
{
	set("short", "��԰С·");
	set("long", @LONG
��ǰ��Ȼ���ʣ������ɵ�������԰�ߵ�С·�ϡ������������֣�����ʢ��
�ŷۺ���һ�������һƬ���������ߡ���ʱ���۷䡸���ˡ��طɹ�����ʧ����
�����У���ֻ���������ϻ���׷���ţ�ߴߴ�������������ӡ��ϱ�������ͨ��
������԰����ڡ�
LONG );
	set("outdoors", "wudang");
	set("exits", ([
		"east" : __DIR__"tyroad11",
		"west" : __DIR__"tyroad9",
		"north" : __DIR__"tygate1",
		"south" : __DIR__"tygate2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
