//ROOM: /d/yanziwu/huizhen.c

inherit ROOM;

void create()
{
        set("short", "����԰");
        set("long",@LONG
���������������Ļ�԰����ֲ���ϵ��滨��ݣ�����Ũ����һȺ
�ʵ��ڻ������ѷ��裬�㲻�ɵĳ��ˣ��е��ֶ�������
LONG );
        set("outdoors", "yanziwu");
        set("exits", ([
            "west"  : __DIR__"changlang",
        ]));
        set("objects",([
            __DIR__"npc/hudie" : 3,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
