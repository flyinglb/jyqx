inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ���ӻ��̣�����С�������һ�أ�����һЩ�ճ���Ʒ�����ƹ�
�����������һֻ�����ϣ��к��Ź������ˡ���˵˽������Ҳ��һЩ����
�Ķ�����̯������һ������(zhaopai)��
LONG );
	set("item_desc", ([
		"zhaopai": "���� \"list\" �г������\"buy\" ���ϰ幺�\n",
	]));
	set("exits", ([
		"east" : __DIR__"xidan",
	]));
	set("objects", ([
		__DIR__"npc/hu": 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

