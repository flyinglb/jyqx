// Room: /city/zuixianlou3.c
// YZC 1995/12/04

inherit ROOM;
inherit F_DEALER;

void create()
{
        set("short", "����¥��¥");
        set("long", @LONG
��������¥��һ�����;��������ޱȣ��Ͷ�¥������ǡ�ɷ��ȣ���ֱ���㲻��
���š�����ԭ���ɾ����������Ҳ����̣��һ����Ϳ����ˮ�ʵ����أ�������ƨ��
�����ݶ��ǡ����ϻ��в�����Ѫ����
LONG );
        set("objects", ([
                __DIR__"npc/tao1" : 1,
                __DIR__"npc/tao2" : 1,
                __DIR__"npc/tao3" : 1,
                __DIR__"npc/tao4" : 1,
                __DIR__"npc/tao5" : 1,
                __DIR__"npc/tao6" : 1,
        ]));
        set("exits", ([
                "down" : __DIR__"zuixianlou2",
        ]));
//	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}
