// tynroad.c ��԰С·
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
��ǰ��Ȼ���ʣ������ɵ�������԰�ߵ�С·�ϡ�·����Ӣ�ͷף�һ��������
�֣�ʢ���ŷۺ���һ�������һƬ���������ߡ������Կ����۷䡸���ˡ����ڻ�
����Ϸ���æ����ͣ�������Գ���ߴզ����������䵱ɽ�ţ�����������ɽ
�Ļ���·��
LONG );
	set("outdoors", "wudang");
	set("exits", ([
		"south" : __DIR__"tyroad8",
	]));
	set("objects", ([
		__DIR__"npc/"+npcs[i] : 1
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
