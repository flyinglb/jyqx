// nroad5.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","ɽ·");
        set("long",@LONG
����һ����᫵�ɽ·����ӵ�������Ͳ�������ȥ�ˡ�ɽ·�����Ӳݴ�
����·��ʼԽ��Խ���ߡ�
LONG );
        set("exits",([
                "northdown" : __DIR__"nroad6",
                "southup"   : __DIR__"nroad1",
                "westup"    : "/d/npc/m_weapon/lianchuishi",
        ]));
        set("objects",([
                __DIR__"npc/eagle" : 2,
        ]));
        set("outdoors", "xueshan");
        setup();
        replace_program(ROOM);
}

