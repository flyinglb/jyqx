// tyroad8.c ��԰С·
// by Marz 

inherit ROOM;

void create()
{
	set("short", "��԰С·");
	set("long", @LONG
��ǰ��Ȼ���ʣ������ɵ�������԰�ߵ�С·�ϡ������������֣�����ʢ��
�ŷۺ���һ�������һƬ���������ߡ���ʱ���۷䡸���ˡ��طɹ�����ʧ����
�����У���ֻ���������ϻ���׷���ţ�ߴߴ�������������ӡ������䵱ɽ�ţ�
�����������͵�ɽ·��ͨ��ɽ����
LONG );
	set("outdoors", "wudang");
	set("exits", ([
		"westup" : __DIR__"tyroad7",
		"east" : __DIR__"tyroad9",
		"north" : __DIR__"tynroad",
		"south" : __DIR__"tysroad",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
