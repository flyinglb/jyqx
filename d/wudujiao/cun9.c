// Room: /u/star/cun8.c
// star 1998/12/04 ��������Ȩ���У����������޸Ĵ���


inherit ROOM;

void create()
{
        set("short", "ɽ·");
	set("long", @LONG
��������һ����ʯ�̳ɵ�ɽ·�ϣ�·���Ӳݴ�����һƬ��������������
�͵�������ɽ�ˡ�
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
        "west" : __DIR__"cun8",
//        "east" : "/d/heimuya/zhaoze/xiaodou",
        "east" : "/d/dali/gaolishan2",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

