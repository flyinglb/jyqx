// nroad3.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","��ѩɽ��´");
        set("long",@LONG
����ɽ�Ʊȴ�ѩɽ�����Ի���Ҳ����ʮ�ֵ��Ϻ���ɽ�����Գ���
��ϡϡ������һЩҰ�ݡ����º����˼���ֻ�м�ֻͺӥ�ڸߴ�������
������ããѩɽ��
LONG );
        set("exits",([
                "south"     : __DIR__"nroad4",
                "eastdown"  : __DIR__"nroad2",
        ]));
        set("objects",([
                __DIR__"npc/lutianshu" : 1,
                __DIR__"npc/shuidai"   : 1,
                __DIR__"npc/eagle"     : 2,
        ]));
        set("outdoors", "xueshan");
        setup();
        replace_program(ROOM);
}

