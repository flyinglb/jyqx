// room: /d/xingxiu/tianroad5.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "��ɽɽ·");
        set("long", @LONG
��������ɽ��´��ɽ���ɽ�ϴ����������ɪɪ������·����һƬ��Ҷ�֡�
������ȥ������ңң�ɼ����ϱ��и��������ɽ��(cave)��
LONG );
        set("exits", ([
            "westup" : __DIR__"tianroad6",
            "eastdown" : __DIR__"tianroad4",
            "enter" : __DIR__"cave",
	    "north" : "/d/npc/m_weapon/liandaoshi",
        ]));
        set("objects", ([
               __DIR__"npc/caiyaoren" : 1, 
        ]));
        set("item_desc", ([
              "cave" : "�������ɽ����Ʈ��һ�����磬�ŵ���ֱ����¡�\n"
        ]) );
//        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
        replace_program(ROOM);
}

