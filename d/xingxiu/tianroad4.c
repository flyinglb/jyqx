// room: /d/xingxiu/tianroad4.c
// Jay 3/18/96

inherit ROOM;

void init();
int do_jump(string arg);

void create()
{
        set("short", "��ɽɽ·");
        set("long", @LONG
��������ɽ��´��ɽ���ɽ�ϴ����������ɪɪ������·����һƬ��Ҷ
�֡�ʯ����ʢ����һ���׵���ɽѩ����һ����ҩ�����ڲ�ҩ������һ����
��(valley)��ס����ɽ��·��
LONG );
        set("exits", ([
            "westup" : __DIR__"tianroad5"
        ]));
        set("objects", ([
                __DIR__"npc/caiyaoren"  : 1,
                __DIR__"npc/obj/xuelian" : 1
        ]));

        set("item_desc", ([
        "valley" : "������ɶ��������Ϊ��ߵ��Ƹߣ�Ӧ�ò�����(jump)��ȥ��\n"
        ]) );
//        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="valley" ) {
               message("vision", me->name() + 
                          "һ������˫�������������\n",
               environment(me), ({me}) );
               me->move("/d/xingxiu/tianroad3");
               message("vision", me->name() + 
                          "�����������������\n",
               environment(me), ({me}) );
               return 1;
       }
}
