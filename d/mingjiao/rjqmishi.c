//RJQMISHI.C

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�����ң�ʯ��֮��Ƕ����յ�͵ƣ�����������ʯ
�ҵذ��þ������ͣ�������һ�޴���¯���ƺ�Ҳ��ذ���Ϊ
һ�塣¯�л������ܣ����׳��졣����׳ʿ���ڴ���ʲô��
�������ϵĴ��������Ǵ����ﴫ���ġ�ʯ�ҽ�������һ��С
����(men).
LONG );
	set("exits", ([
		"south" : __DIR__"rjqjiguan",
		"down"  : __DIR__"rjqmenlou1",
	]));
	set("no_clean_up", 0);
//	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
