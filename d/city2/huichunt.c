// Room: /city2/huichuntang.c

inherit ROOM;

void create()
{
	set("short", "�ش���ҩ��");
	set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵ�
���ٸ�С������ɢ�������ġ�һλ�����ڹ�̨��վ�š���̨������һ
�ŷ��ƵĹ��(guanggao)����̨����������һ������(neishi)��
LONG );
	set("item_desc", ([
		"guanggao" : "�����������ҩƷ��
��ҩ��\t��ʮ������
������ҩ���ϰ����顣\n",
	]));
	set("objects", ([
		"/d/city2/npc/huoji2" : 1,
		"/d/city2/npc/xutianch" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"xichang1",
                "west" : __DIR__"neishi",   
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

