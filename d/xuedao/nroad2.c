// nroad2.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","ɽ·");
        set("long",@LONG
������һɽ·�ϣ�������һ����Сɽ����ң�������Ϸ���ѩɽ
�ı�´��ɽǰ����ԼԼ������һ����Ժ��
LONG );
        set("exits",([
                "westup"    : __DIR__"nroad3",
                "eastdown"  : __DIR__"nroad1",
        ]));
        set("objects",([
                "/d/wudang/npc/guest" : 1,
        ]));
        set("outdoors", "xueshan");
        setup();
        replace_program(ROOM);
}

