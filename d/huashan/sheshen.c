// sheshenya.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һ�μ�խ���յ�ɽ�£�����������ƣ�����Ԩ���޵ס��粻С��
��һʧ�����ȥ��ֻ������ͷ���Ҳ����������и�Сɽ��(dong)��
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "eastdown" : __DIR__"canglong",
            "west"     : "/d/xiaoyao/pubu",
        ]));
        set("item_desc", ([
            "dong" : "����������ʯ�ڵ�С�����ں����Ĳ�֪�ж��\n",
        ]));
//      set("objects",(
//              __DIR__"npc/referee" : 1,
//      ]))
//        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
}


void init()
{
        object me = this_player();
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
        if (me->query_temp("xunshan")) me->set_temp("xunshan/sheshen", 1);
        return;
}

int do_enter(string arg)
{
        object me;
        mapping fam;

        me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="dong" )
        {
           if( (fam = me->query("family")) && fam["family_name"] == "ؤ��")
           {
               message("vision",
                        me->name() + "����ؤ�����ǹ���һ�������������˽�ȥ��",
                        environment(me), ({me}) );
               me->move("/d/gaibang/underhs");
               message("vision",
                        me->name() + "�Ӷ������˽�����\n",
                        environment(me), ({me}) );
                        return 1;
           }
           else  return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
       }
}
