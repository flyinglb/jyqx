// Room: /city2/qianzhuang.c

inherit ROOM;

void create()
{
	set("short", "Ǯׯ");
	set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ
�����е���Ʊ�����ǳ��ã�ͨ��ȫ�����������ߵ�������κ�һ����
ׯ�ֵ궼���������ȡ��ǽ�Ϲ���һ������(paizi)��
LONG );
	set("item_desc", ([
        "paizi" : "\n��ׯ����Ϣ�����ٰٷ�֮һ��\n
      ��Ǯ        deposit����cun\n
      ȡǮ        withdraw����qu\n
      Ǯ�Ҷһ�    convert����duihuan\n
      ����        check����chazhang\n",
	]));
	set("exits", ([
		"west" : __DIR__"wangfu1",
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_beg", 1);
	set("objects", ([
		__DIR__"npc/qianlaob" : 1
	]));

	setup();
	replace_program(ROOM);
}

