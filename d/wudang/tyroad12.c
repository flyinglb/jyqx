// tyroad12.c ��԰С·
// by Marz 

inherit ROOM;

string* npcs = ({
	"little_monkey",
	"monkey",
	"little_monkey",
	"little_bee",
	"bee",
	"little_bee",
});

void create()
{
	int i = random(sizeof(npcs));
	    
	set("short", "��԰С·");
	set("long", @LONG
��ǰ��Ȼ���ʣ������ɵ�������԰�ߵ�С·�ϡ�·����Ӣ�ͷף���������
���֣�ʢ���ŷۺ���һ�������һƬ���������ߡ������Կ��۷䡸���ˡ�����
������Ϸ���æ����ͣ�������Գ���ߴզ����
LONG );
	set("outdoors", "wudang");
	set("exits", ([
		"west" : __DIR__"tyroad11",
		"east" : __DIR__"tyroad13",
	]));
	set("objects", ([
		__DIR__"npc/"+npcs[i] : 1
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
