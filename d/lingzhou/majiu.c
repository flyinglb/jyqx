//Room: majiu.c ���
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","���");
	set("long",@LONG
���ǳ������ϵ���ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ�
����ֻҪס�꣬����Ǿͻ����ǣ����Ǻ����տ���������ι�����㣬
��ϴˢ�ø�Ǭ������һֱ�ź򵽿��������·������жѷ������Ѳ��ϣ�
������һ����ۡ���������µ���ľ���϶���һ����ľ��(paizi)��
LONG);
	set("outdoors", "lingzhou");
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_clean_up", 0);
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		__DIR__"npc/mafu": 1,
	]));
	set("item_desc", ([
	"paizi": @TEXT
������ֻҪ�����һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ���ǳ�:  rideyd

TEXT]));
	set("exits",([ /* sizeof() == 1 */
	    "west"      : __DIR__"chema",
	]));
	setup();
	replace_program(ROOM);
}
